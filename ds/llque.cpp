#include <iostream>
using namespace std;

class node{
	public:
		int data;
		node* next;
		node* front;
		node* back;

		node(int val){
			data=val;
			front=NULL;
			back=NULL;
			next=NULL;
		}

};




class queue{
	node*front;
	node*back;

	public:
	queue(){
		front=NULL;
		back=NULL;

	}


	void push(int val){

		node* n=new node(val);
		if(front==NULL && back==NULL){
			front=n;
			back=n;
			return;
		}

		front->next=n;
		front=n;

	}

	void pop(){
		if(back==front && back==NULL){
			cout<<"queue is empty"<<endl;
			return;
		}
		node* todelete=back;
		node* tp=back->next;
		delete todelete;
		back=tp;
	
	
	}


	void display(){
		node *temp=back;
		while(temp!=NULL){
			cout<<temp->data<<"->";
			temp=temp->next;
		
		}
		cout<<endl;
	}

	void Top(){
		cout<<front->data<<endl;
	
	
	}







};


int main(){
	queue qu;
	qu.push(1);
	qu.push(2);
	qu.push(3);
	qu.pop();
	qu.display();
	qu.Top();



	return 0;
}
