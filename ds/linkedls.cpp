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

node* inhead(node* &head,int val){

	node* n=new node(val);
	node* temp=head;
	head=n;
	head->next=temp;


	return head;

}




void intail(node* &head,int val){
	node*n=new node(val);


	if(head==NULL){

		head=inhead(head,val);
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

	cout<<"NULL"<<endl;



}

void del(node* &head,int pos){

	if(pos==1){
		node* todelete;
		if(head==NULL){cout<<"ll empty"<<endl;}
		else if(head->next==NULL){delete head;head=NULL;}
		else {
			todelete=head;
			head=head->next;
			delete todelete;

		}
		return;
	}


	int count=0;
	node* temp=head;

	while(temp!=NULL){
		count++;
		if(count==(pos-1)){
			break;
		}
		temp=temp->next;
	}
	node* todelete=temp->next;

	if(temp->next->next==NULL){
		temp->next=NULL;
		delete todelete;
		return;

	}
	temp->next=todelete->next;
	delete todelete;


}
//creating cycle in ll
void ccycle(node* head,int pos){

	node* temp=head;
	node* end=NULL;
	int count=0;
	while(temp->next!=NULL){
		count++;

		if(count==pos){
			end=temp;
		}

		temp=temp->next;
	}

	temp->next=end;


}
//detect cycle
bool dcycle(node* head){

	node* slow=head;
	node* fast=head;
	while(fast!=NULL && fast->next!=NULL){

		slow=slow->next;
		fast=fast->next->next;

		if(slow==fast){

			return true;
		}
	}

	return false;



}
//del cycle
void delcycle(node* head){
	node* slow=head;
	node* fast=head;
	while(fast!=NULL && fast->next!=NULL){

		slow=slow->next;
		fast=fast->next->next;

		if(slow==fast){
			break;
		}
	}


	fast=head;

	while(fast->next!=slow->next){

		fast=fast->next;
		slow=slow->next;
	
	}

	slow->next=NULL;




}




int main(){

	node* head=NULL;

	intail(head,1);
	intail(head,2);
	intail(head,3);
	intail(head,4);
	intail(head,5);
	intail(head,6);
	//del(head,2);
	ccycle(head,3);
	//display(head);
	cout<<dcycle(head)<<endl;
	delcycle(head);
	display(head);
	cout<<dcycle(head)<<endl;
	return 0;

}
