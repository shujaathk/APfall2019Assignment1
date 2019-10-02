//
// Created by usama on 9/21/19.
//

#include <iostream>

////Assumption: Linked List is Sorted.

using namespace std;

struct Node{
    int data;
    Node* next;
}*head;

void insert(int data){      //Function to Insert value at head
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

void display(){       //Function to display linked list
    Node* curr = head;
    while (curr!=nullptr) {
        cout << curr->data<<" ";
        curr=curr->next;
    }
    cout<<endl;
}

void sorted_insert(int data){   //Function to insert value in a sorted linked list
    Node* prev = nullptr;
    Node* curr = head;
    while (curr!= nullptr){  //Loop over list to find node to insert before
        if(data<curr->data)
            break;
        else{
            prev=curr;
            curr=curr->next;
        }
    }
    if(head!= nullptr&&prev!= nullptr){   //Insert before the node
        Node* temp = new Node;
        *temp = {data,curr};
        prev->next = temp;
    } else insert(data);
}

void sorted_delete(int data){    //Function to delete value in a sorted linked list
    Node* prev = nullptr;
    Node* curr = head;
    while (curr!= nullptr){       //Loop to find the node
        if(data==curr->data)
            break;
        else{
            prev=curr;
            curr=curr->next;
        }
    }
    if(prev!= nullptr&&curr!= nullptr){   //Delete the Node
        prev->next = curr->next;
        delete(curr);
    } else if(curr==head){
        head=head->next;
        delete(curr);
    } else cout<<"Value not found!!"<<endl;
}



int main(){
    int val;
    insert(9);
    insert(8);
    insert(6);
    insert(4);
    insert(3);
    insert(2);
    cout<<"Current Linked List:"<<endl;
    display();

    cout<<"1. Insert\n2. Delete\nSelect Option: ";
    cin>>val;
    if(val==1) {
        cout << "Enter Value to insert: ";
        cin >> val;
        sorted_insert(val);
    } else{
        cout << "Enter Value to delete: ";
        cin >> val;
        sorted_delete(val);
    }
    cout<<"Linked List After:"<<endl;
    display();
    return 0;
}