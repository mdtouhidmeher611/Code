#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node* next;
};


void insertAtBegining(Node*& head, int newData){
	Node* newNode = new Node();
	newNode->data = newData;
	newNode -> next = head ;
	head = newNode;
}


void insertAtEnd(Node*& head, int newData){
	Node* newNode = new Node();
	newNode->data = newData;
	newNode->next = nullptr;

	if(head == nullptr){
		head = newNode;
		return;
	}

	Node* temp = head ;
	while ( temp->next != nullptr){
		temp= temp->next;
	}
	temp->next = newNode;
}

void insertAfter(Node* head , int prevdata , int newData){
	Node* newNode = new Node();
	newNode->data = newData;

	Node* temp = head;
	while (temp->data != prevdata){
		temp= temp->next;
		if (temp->next == nullptr){
			cout<<"data not found" ;
			return;
		}
	}

	newNode->next = temp->next;
	temp->next= newNode;
}

void printlist(Node* head){
	Node* temp = head;
	while(temp!= nullptr){
		cout << temp->data << " -> ";
		temp= temp->next;
	}
	cout<< "NULL"<<endl;
}

int main(){
	Node* head  = nullptr ;
    
    insertAtBegining(head,10);
    insertAtBegining(head,20);
    insertAtBegining(head,30);
    cout<< "initail list : ";
    printlist(head);

    insertAtEnd(head, 40);
    insertAtEnd(head, 50);

    cout << "new list : ";
    printlist(head);
    insertAfter(head, 20 , 25);
    cout<<" after inserting 25 :";
    printlist(head);
    return 0;
}