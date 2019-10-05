#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	int size=100,i=0;
	char* input, *encrypted, *decrypted;
	input = new char[size];
	decrypted = new char[size];
	encrypted = new char[size]; 
	cout << "enter string" << endl;
	cin.get(input, size);
	for (int i = 0; i < size; i++)
	{
		encrypted[i] = input[i];
		if (encrypted[i]>64 && encrypted[i]<91)              //converts A to Z, B to Y and so on
			encrypted[i] = 25 - (encrypted[i] - 65) + 65;
		if (encrypted[i]>96 && encrypted[i]<123)             ////converts a to z, b to y and so on
			encrypted[i] = 25 - (encrypted[i] - 97) + 97;
	}
	fstream myfile1("encrypted.txt", ios::out);
	for (int i = 0; i < size; i++)
	{
		if ((encrypted[i] > 64 && encrypted[i] < 91) || (encrypted[i]>96 && encrypted[i] < 123) || encrypted[i]==32) //writing encrypted with spaces
			myfile1 << encrypted[i];
	}
	for (int i = 0; i < size; i++)
	{
		decrypted[i] = encrypted[i];
		if (decrypted[i]>64 && decrypted[i]<91)
			decrypted[i] = 25 - (decrypted[i] - 65) + 65;
		if (decrypted[i]>96 && decrypted[i]<123)
			decrypted[i] = 25 - (decrypted[i] - 97) + 97;
	}
	fstream myfile2("decrypted.txt", ios::out);
	for (int i = 0; i < size; i++)
	{
		if ((decrypted[i] > 64 && decrypted[i] < 91) || (decrypted[i]>96 && decrypted[i] < 123) || decrypted[i] == 32)  //writing decrypted with spaces
			myfile2 << decrypted[i];
	}
	return 0;
}
