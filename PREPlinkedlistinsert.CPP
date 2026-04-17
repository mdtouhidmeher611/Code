#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node* next;
};

void insertfirst(Node* &head, int data){
	Node* newNode= new Node();
	newNode->data= data;
	newNode->next=head;
	head=newNode;
}

void insertlast(Node* &head,int data){
	Node* newNode= new Node();
	newNode->data = data;
	newNode->next = nullptr;

	if(head == nullptr){
		head=newNode;
		return;
	}

	Node* temp= head;
	while(temp->next!=nullptr){
		temp=temp->next;
	}
	temp->next= newNode;

}

void insertafter(Node* head , int value , int data){
	Node* temp= head;
	count=1;
	while(temp!=nullptr && count <= value){
		temp=temp->next;
	}

	Node* newNode = newNode();
	newNode->data= data;
	newNode->next=temp->next;
	temp->next = newNode;
}

void deletefirst(Node*& head){
	if(head==nullptr){
		cout<<"list is empty\n";
		return;
	}
	Node* temp=head;
	head= head->next;
	cout<<"deleted "<<temp->data<<endl;
	delete temp;

}

void deletelast(Node*& head){
		if(head==nullptr){
		cout<<"list is empty\n";
		return;
	}
	Node* temp  =head;
 	
 	if(head->next==nullptr){
 		cout<<"deleted"<<head->data<<endl;
 		delete head;
 		head = nullptr;
 		return;
 	}


	while(temp->next->next!=nullptr){
		temp=temp->next;
	}

	cout<<"deleted"<<temp->next->data<<endl;
	delete temp->next;
	temp->=nullptr;


}

void deletecertain(Node*head , int n ){

	if(head==nullptr){
		cout<<"list is empty\n";
		return;
	}
	Node* temp  =head;
 	int count=1
 	if(head->next==nullptr && count == n){
 		cout<<"deleted"<<head->data<<endl;
 		delete head;
 		head = nullptr;
 		return;
 	}
 	while(count!=n && temp->next !=nullptr){
 		temp=temp->next ;
 		count=count+1;
 	}
 	if(cout == n-1){
 		Node* tobedeleted = temp->next;
 		cout<<"deleted "<<tobedeleted->data <<endl;
 		temp->next=temp->next->next;
 		delete tobedeleted;
 		return;
 	}
 	else{
 		cout<<"node doesn't exist"<<endl;
 	}
 }