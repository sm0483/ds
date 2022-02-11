#include <iostream>
using namespace std;


class node{
	public:
		int data;
		node* next;

		node(int val){
			data=val;
			next=NULL;

		}
};

void inhead(node* &head,int val){

	node* n=new node(val);
	node* temp=head;
	while(temp->next!=head){
		temp=temp->next;
	}
	temp->next=n;
	n->next=head;
	head=n;





}



void intail(node* &head,int val){

	node* n=new node(val);

	if(head==NULL){

		head=n;
		head->next=n;
		return;


	

	}


	node* temp=head;

	while(temp->next!=head){

		temp=temp->next;

	}
	temp->next=n;
	n->next=head;

}


void display(node* head){

	node* temp=head;

	do{
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	while(temp->next!=NULL);
	cout<<endl;



}

int main(){

	node* head=NULL;
	intail(head,1);
	intail(head,2);
	intail(head,3);
	//inhead(head,6);
	display(head);
	cout<<head->data<<endl;


	return 0;
}
