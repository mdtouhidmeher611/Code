#include<bits/stdc++.h>
using namespace std;


struct Node{
	int data;
	Node* next;
};


void insert(Node* &head, int newData){

	Node* newNode = new Node();
	newNode->data = newData;
	newNode->next = nullptr;

	if(head==nullptr){
		head=newNode;
		return;
	}
	Node* temp=head;
	while(temp->next!=nullptr){
		temp=temp->next;
	}
	temp->next= newNode;
}

void merge(Node* head1 , Node* head2){

	if(head1==nullptr){
		head1=head2;
		return;
	}

	Node* temp=head1;
	while(temp->next!= nullptr){
		temp = temp->next;
	}
	temp->next=head2;
}

void print(Node* head){
	if(head==nullptr){
		cout<<"List is empty"<<endl;
		return;
	}

	Node* temp=head;
	while(temp!=nullptr){
		cout <<temp->data<< "  --> ";
		temp=temp->next;
	}
	cout<<"NULL"<<endl;

}

int main(){
	Node* head1=nullptr;
	Node* head2 = nullptr;
	int n1;
	cout<<"Enter the number of total elements in List1 : ";
	cin >> n1 ;
	cout<< "Enter the elements : ";
	while(n1--){
		int data;
		cin >> data;
		insert(head1,data);
	}

	int n2;
	cout<<"Enter the number of total elements in List2 : ";
	cin >> n2 ;
	cout<< "Enter the elements : ";
	while(n2--){
		int data;
		cin >> data;
		insert(head2,data);
	}
	cout<< "List1 :" ;
	print(head1);
	cout<< "List2 :" ;
	print(head2);
	
	merge(head1, head2);
	 cout<<"Merged list : ";
	print(head1);

	return 0;
}