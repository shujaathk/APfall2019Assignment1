//
// Created by usama on 9/20/19.
//

#include <iostream>
#include <fstream>

using namespace std;

////Assumption: File contains only Capital letters separated by single space

//To resolve conflict if number is greater than (X)88 add 23.
int encrypt(char c){
    return c%23+(c/'X'*23);  //Encrypting Capital letter
}

//If number is between 0-18 decryption will be 23*3+c  else it will be 23*2+c
char decrypt(int c){
    return 23*(c>18?2:3)+c; //Decrypting Capital letter
}

int main() {
    int op,d;
    char c;
    ifstream infile;
    ofstream outfile;
    cout << "1. Encrypt\n2. Decrypt\nSelect Option: ";
    cin >> op;
    cout << endl;

    if(op==1) {
        infile.open("original2.txt");
        outfile.open("encrypted2.txt");
        cout<<"Encrypted Text:"<<endl;
        while (infile>>c) {          // reading file character by character
            d = encrypt(c);
            cout << d << " ";
            outfile << d << " ";
        }
    } else{
        infile.open("encrypted2.txt");
        outfile.open("original2.txt");
        cout<<"Decrypted Text:"<<endl;
        while (infile>>d) {          // reading file integer by integer
            d = decrypt(d);
            cout << (char)d << " ";
            outfile << (char)d << " ";
        }
    }

    infile.close();
    outfile.close();

    return 0;
}