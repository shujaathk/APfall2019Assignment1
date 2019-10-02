#include <iostream>
#include <fstream>

using namespace std;

char encrypt_decrypt(char c){   //Function performs both encryption and decryption
    if(c<65||c>122||(c>90&&c<97))  //Do nothing for non-alphabetic characters
        return c;
    else if(c<97)
        return 'A'-c +'Z';  //Encrypting/Decrypting Capital letter
    else return 'a'-c +'z';   //Encrypting/Decrypting Small letter
}

int main() {
    int op;
    char c;
    ifstream infile;
    cout<<"1. Encrypt\n2. Decrypt\nSelect Option: ";
    cin>>op;
    cout<<endl;

    if(op==1) {
        infile.open("original1.txt");
        cout<<"Encrypted Text:"<<endl;
    }
    else{
        infile.open("encrypted1.txt");
        cout<<"Decrypted Text:"<<endl;
    }

    while (infile.get(c)) {          // reading file character by character
        cout << encrypt_decrypt(c);
    }

    infile.close();
    return 0;
}