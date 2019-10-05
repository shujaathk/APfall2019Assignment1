#include<iostream>
using namespace std;
class Node {
public:
	double	data;	// data
	Node*	next;	// pointer to next
};
class List {
public:
	List(void) { head = NULL; } // constructor
	~List(void);	            // destructor

	bool IsEmpty() { return head == NULL; }
	void SortedInsert(double x);
	int DeleteNode(double x);
	void DisplayList(void);
private:
	Node* head;
};

List::~List(void) {
	Node* currNode = head;
	Node* nextNode = NULL;
	while (currNode != NULL)
	{
		nextNode = currNode->next;
		delete currNode; // destroy the current node
		currNode = nextNode;
	}
}
void List::SortedInsert(double x)
{
	Node* newNode = new Node;
	newNode->data = x;
	newNode->next = NULL;
	if (head == NULL || head->data >= newNode->data)         //if link list is empty or head has same data as the input
	{
		newNode->next = head;
		head = newNode;
		return;
	}
	Node* current = head;                                         	// Locate the node before the point of insertion
	while (current->next != NULL && current->next->data < newNode->data)
		current = current->next;

	newNode->next = current->next;
	current->next = newNode;
}

int List::DeleteNode(double x) {
	Node* prevNode = NULL;
	Node* currNode = head;
	int currIndex = 1;
	while (currNode && currNode->data != x) {
		prevNode = currNode;
		currNode = currNode->next;
		currIndex++;
	}
	if (currNode) {
		if (prevNode) {
			prevNode->next = currNode->next;
			delete currNode;
		}
		else {
			head = currNode->next;
			delete currNode;
		}
		return currIndex;
	}
	return 0;
}
void List::DisplayList()
{
	int num = 0;
	Node* currNode = head;
	while (currNode != NULL){
		cout << currNode->data << endl;
		currNode = currNode->next;
		num++;
	}
	cout << "Number of nodes in the list: " << num << endl;
}
int main(void)
{
	List list;
	list.SortedInsert( 7.0);	// successful
	list.SortedInsert(5.0);	// successful
	list.SortedInsert(6.0);
	list.SortedInsert(1.0);
	list.SortedInsert(10.0);

	// successful
	// print all the elements
	list.DisplayList();
	list.DeleteNode(6.0);
	list.DisplayList();
	return 0;
}
