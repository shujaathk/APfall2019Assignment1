#include<iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	int row = 70;
	int col = 20;
	char** myArray = new char*[row];
	for (int i = 0; i < row; ++i)
		myArray[i] = new char[col];
	double word[70];
	int num_characters = 0;
	int i = 0,index[10];
	double top[10][2];
	
	fstream myfile("Q1EX.cpp",ios::in);
	if (myfile.is_open())
	{
		while (!myfile.eof()) //end of life
		{
			int j = 0;
			myfile.get(myArray[i][j]);
			while (myArray[i][j] != ' ')                       //saves all words in a 2d array i.e. reads character till space and then starts saving next word
			{

				j++;
				myfile.get(myArray[i][j]);
			}
			i++;
			num_characters++;
		}
		myfile.close();
	}
	for (int i = 0; i < row; i++)
	{
		word[i] = 0;
		for (int j = 0; j < col; j++)
		{
			if (myArray[i][j] < 123 && myArray[i][j]>64)
			{
				word[i] = word[i] + tolower(myArray[i][j]) * (j + 1);             //gives a number unique num to each depending on its position in the word,
			                                                                      //tolower eliminates the difference between upper and lower case words
			}
		}
	}
	for (int j = 0; j < 10; j++)       //finding top 10 words and their occurences
	{
		index[j] = 0;
		top[j][0] = word[0];
		for (int i = 0; i < row; i++)
		{
			if (top[j][0] < word[i])
			{
				top[j][0] = word[i];              //top[j][0] saves the weights of top 10 numbers
				index[j] = i;                    //index array saves the index of the largest number
			}
		}
		top[j][1] = 0;                          // here we find the occurences
		for (int i = 0; i < row; i++)
		{
			if (top[j][0] == word[i]&&word[i]!=0)           //top[j][1] saves the occurences of largest
			{
				word[i] = 0;
				top[j][1]=top[j][1]+1;
			}
		}
		word[index[j]] = 0;                  //largest is turned to 0 so that smaller than the largest element can be found as 2nd largest
	}


	for (int i = 0; i < 10; i++)
	{
		int size = 0;
		for (int j = 0; j < col; j++)
		{
			if (myArray[index[i]][j] < 123 && myArray[index[i]][j]>64)
			{
				cout << myArray[index[i]][j];
				size = j;
			}
		}
		cout <<" ->Length="<< size+1 <<" ->occurences=" << top[i][1] << endl;
	}
	return 0;
}