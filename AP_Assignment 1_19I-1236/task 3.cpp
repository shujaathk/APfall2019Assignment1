//
// Created by usama on 9/21/19.
//


#include <iostream>

using namespace std;

////Assumption: Values do not repeat in Linked List.

struct Node{
    int data;
    Node* next;
}*head;

void insert(int data){  //Function to Insert value at head
    if (head == nullptr) {
        head = new Node;
        *head = {data, nullptr};
    }
    else{
        Node *temp = new Node;
        *temp= {data,head};
        head = temp;
    }
}

void display(){  //Function to display linked list
    Node* curr = head;
    while (curr!=nullptr) {
        cout << curr->data<<" ";
        curr=curr->next;
    }
    cout<<endl;
}

void swap(int val1, int val2){
    Node* curr = head;
    Node* n1 = nullptr;
    Node* n2  = nullptr;
    while (curr!=nullptr){  //Loop to find nodes with val1 and val2 and store them
        if(curr->data == val1)
            n1 = curr;

        else if(curr->data == val2)
            n2 = curr;

        curr = curr->next;
    }
    if(n1!= nullptr && n2!= nullptr) {
        n1->data = val2;
        n2->data = val1;
    } else cout<<"Values not Found!!"<<endl;  //If pointers null Values not found
}

int main(){
    int val1;
    int val2;
    insert(3);
    insert(4);
    insert(8);
    insert(7);
    insert(2);
    insert(9);
    insert(0);
    insert(1);
    insert(5);
    insert(6);
    cout<<"Current Linked List:"<<endl;
    display();
    cout << "Enter Value 1 to swap: ";
    cin >> val1;
    cout << "Enter Value 2 to swap: ";
    cin >> val2;
    swap(val1,val2);
    cout<<"Linked List After:"<<endl;
    display();
    return 0;
}

