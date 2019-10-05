#include <iostream> 
using namespace std; 

class Node  // Linked list node class
{ public: 
    int data; 
    Node* next; 
}; 
  
void Swap(Node* head) //Function to swap elements of linked list
{ 
    Node* temp = head; 
} 

void push(Node** head_ref, int new_data) //ftn of adding a node at the begining of the linked list
{ 
    Node* new_node = new Node(); 
    new_node->data = new_data; 
    new_node->next = (*head_ref); 
    (*head_ref) = new_node;  //move the head to point to the new node
} 
  
void showList(Node* node)  //Function to print nodes in linked list
{ 
    while (node != NULL) { 
        cout << node->data << " "; 
        node = node->next; 
    } 
} 

int main() 
{ 
    Node* start = NULL; 
    
    //Entering values in Linked list
    push(&start, 72); 
    push(&start, 37);  
    cout << "Linked list= 72 37 \n"
         << "After Swapping nodes:"; 
    showList(start); 
	 Swap(start); 
    return 0; 
} 
