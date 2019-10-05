#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

void encrypt(char *word)
{
        char *arr=new char[strlen(word)];  //to calculate and return the length of string i ll use strlen function
    int user_input;

    for (int i = 0; i < strlen(word); i++)
    {
        arr[i] = (char )((int)word[i] % 23); 
    }
    cout << "Encrypted String is : ";  //output the encryted value of string
    for (int i = 0; i < strlen(word); i++)
        cout << (int)arr[i];
    cout << endl
         << "Enter 1 for Decrypt again and 0 for Exit : "; //user's choice.
    cin >> user_input;
    
    
    if (user_input)
    {
        cout << "Decrypted String is : ";
        for (int i = 0; i < strlen(word); i++)
        {
            cout << (char)(((int)arr[i]) + (23 * ((int)word[i] / 23))); //formula for decryption
        }
    }
    else
    {
        return;
    }
}

int main()
{
    char word[] = ""; 
    cout << "Enter any string : ";
    gets(word);    //taking value from  user
    encrypt(word);  
	cout<<endl;

	system("pause");
    return 0;
}
