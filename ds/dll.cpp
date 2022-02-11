#include<iostream>
using namespace std;


class node{
	public:
		int data;
		node*next;
		node*previous;

		node(int val){

			data=val;
			next=NULL;
			previous=NULL;
		}	


};

void intail(node* &head,int val){

	node* n=new node(val);


	if(head==NULL){
		head=n;
		return;
	}

	node* temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}

	temp->next=n;
	n->previous=temp;


}

void display(node* &head){

	node* temp=head;

	while(temp!=NULL){

		cout<<temp->data<<"->";
		temp=temp->next;
	}

	cout<<"NULL"<<endl;
	temp=head;


	while(temp!=NULL){

		cout<<temp->*previous<<"->";
		temp=temp->next;

	}
	cout<<"NULL"<<endl;




}




int main(){


	node* head=NULL;
	intail(head,1);
	intail(head,2);
	intail(head,3);
	display(head);



	return 0;


}

