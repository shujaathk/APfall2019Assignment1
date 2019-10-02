//
// Created by usama on 9/21/19.
//

#include <iostream>
#include <fstream>

using namespace std;

int length(const char* word){   //Function to get length of word
    int i =0;
    while (word[i]!='\0')
        i++;
    return  i;
}

bool isEqual(const char* word, const char* word1, int len){  //Function to compare equality of two words
    int i =0;
    while(word[i]!='\0'||word1[i]!='\0') {
        if (word[i] != word1[i])
            return false;
        i++;
    }

    return i == len;
}

void insert(char* top10[10],int (&top10_count)[10],char* word,int pos){   //Function inserts word at specified pos. And pushes the existing word further down the array.
    char* temp = top10[pos];
    int temp_count = top10_count[pos];
    top10[pos] = word;
    top10_count[pos] = 0;

    for(int i=pos+1;i<10;i++){
        if(top10[i] == nullptr) {   //If array is empty insert and break
            top10[i] = temp;
            break;
        }
        else if(length(temp) > length(top10[i])){   //Else keep swapping till end of array is reached. The smaller word will be discarded.
            swap(temp,top10[i]);
            swap(temp_count,top10_count[i]);
        }
    }
}

void top10_unique(char* top10[10],int (&top10_count)[10],ifstream &infile){  //Function to return top 10 unique words and their count.
    char *word = new char;
    // extracting words from the file
    while (infile >> word)   //Reading file word by word
    {
        int count = length(word);
        for(int i = 0;i<10;i++) {     //Loop to get the right place by length to insert word
            if (top10[i] == nullptr) {
                top10[i] = word;
                break;
            }

            if (length(word) > length(top10[i])) {
                insert(top10, top10_count, word, i);
                break;
            }

            else if(length(word) == length(top10[i]) && isEqual(word, top10[i], count)) {   //If word appears again increment count
                top10_count[i]++;
                break;
            }
        }
        word = new char;
    }
}

int main() {
    ifstream infile("original1.txt");

    char *top10[10] = {nullptr};
    int top10_count[10] = {0};

    top10_unique(top10,top10_count,infile);

    cout<<"Top 10 unique words and their count:"<<endl;
    for(int i=0;i<10 && top10[i]!= nullptr;i++)
        cout<<top10[i]<<"  "<<top10_count[i]<<endl;
}