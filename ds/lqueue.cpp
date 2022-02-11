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
	if(head==NULL){
		head=n;
		return;

	}

	node* temp=head;

	while(temp->next!=NULL){
		temp=temp->next;

	}
	temp->next=n;

}


void display(node* head){

	node* temp=head;

	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<endl;



}

node* remove(node* &head){
	node*temp=head->next;
	node* todelete=head;
	head=temp;

	delete todelete;

	return head;

}

class queue{
	public:
		int data;
		int front;
		int back;
		node* head;

		queue(){
			front=-1;
			back=-1;
			head=NULL;
		}

		void enqueue(int val){
			inhead(head,val);
			front++;
			back++;


		}

		void dequeue(){
			node* newhead=remove(head);
			head=newhead;
			back--;
		}

		void Top(){
			display(head);

		}




};




int main(){
	node* head=NULL;
	queue qu;
	qu.enqueue(1);
	qu.enqueue(2);
	qu.enqueue(3);
	qu.dequeue();
	qu.dequeue();
	qu.Top();


	return 0;
}
