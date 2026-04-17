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


void print(Node* head){
	if(head==nullptr){
		cout<<"List is empty"<<endl;
		return;
	}
	cout<< " Main list :  ";
	Node* temp=head;
	while(temp!=nullptr){
		cout <<temp->data<< "  --> ";
		temp=temp->next;
	}
	cout<<"NULL"<<endl;

}

void print2(Node* head, int n){
	Node* temp= head;
	int total = n;
	int i=1;
	cout << "\n 1st half of the list: { ";
	while(i<=((total/2) + 1 )){
		cout<< temp->data << "  ";
		temp=temp->next;
		i++;
	}
	cout << "}"; 
	cout << " \n2nd half of the list : { ";
	while(temp!=nullptr){
		cout << temp->data <<"  ";
		temp=temp->next;
	}
	cout<<"}";
}

int main(){
	Node* head=nullptr;
	int n1;
	cout<<"Enter the number of total elements in List : ";
	cin >> n1 ;
	int n= n1;
	cout<< "Enter the elements : ";
	while(n1--){
		int data;
		cin >> data;
		insert(head,data);
	}
	
	print(head);
	print2(head, n);
	return 0;
}