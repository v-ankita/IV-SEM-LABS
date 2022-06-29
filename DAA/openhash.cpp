#include <iostream>
using namespace std;

class Node{
public:
	int data;
	Node* next;
};

class HashTable{
public:
	Node** HT;
	HashTable();
	int hash(int key);
	void Insert(int key);
	int Search(int key);
	
};

HashTable::HashTable() {
	HT = new Node* [10];
	for (int i=0; i<10; i++){
		HT[i] = nullptr;
	}
}

int HashTable::hash(int key) {
	return key % 10;
}

void HashTable::Insert(int key) {
	int hIdx = hash(key);
	Node* t = new Node;
	t->data = key;
	t->next = nullptr;
	// Case: No nodes in the linked list
	if (HT[hIdx] == nullptr){
		HT[hIdx] = t;
	} else {
		Node* p = HT[hIdx];
		Node *q=HT[hIdx];
		// Traverse to find insert position
		while (p && p->data < key){
			q=p;  
			p = p->next; 
		}
		// Case: insert position is first
		if (q == HT[hIdx]){
			t->next = HT[hIdx];
			HT[hIdx] = t;
		} else {
			t->next = q->next;
			q->next = t;
		}
	} 
}

int HashTable::Search(int key) {
	int hIdx = hash(key);
	Node* p = HT[hIdx];
	while (p){
		if (p->data == key){
			return hIdx;
		}
		p = p->next;
	}
	return -1;
}

int main() {
	 int i=0, n=0;

    cout<<"Enter number of elements: ";
    cin>>n;
    int A[n];
    cout<<"Enter elements: ";
    for(i=0;i<n;i++)
    cin>>A[i];
	
	HashTable H;
	for (int i=0; i<n; i++){
		H.Insert(A[i]);
	}
	
	int key;
    cout<<"Enter key to search: ";
    cin>>key;
	int value = H.Search(key);
    if(value==-1)
    cout<<"Unsuccessful search"<<endl;
    else
	cout << "Key: " << key << ", Value: " << value << endl;

	return 0;
}