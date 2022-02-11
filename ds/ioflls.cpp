#include<iostream>
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


void intail(node* &head,int val){
	node* n=new node(val);
	if(head==NULL){head=n;return;}

	node* temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}

	temp->next=n;
}


void display(node* head){

	while(head!=NULL){
		cout<<head->data<<"->";

		head=head->next;

	}
	cout<<"NULL"<<endl;



}


node* point(node* head,int pos){
	node* temp=head;
	int count=0;

	while(temp!=NULL){
		if(count==pos-1){

			return temp;
		}
		count++;
		temp=temp->next;
	}

	return NULL;

}


void clink(node* head,node* pos){

	node* temp=head;
	while(temp->next!=NULL){

		temp=temp->next;

	}

	temp->next=pos;



}

int len(node* head){
	node* temp=head;
	int count=0;
	while(temp!=NULL){

		temp=temp->next;
		count++;

	}
	return count;
}
bool checkforj(node* p1,node* p2){

	do{
		p1=p1->next;
		p2=p2->next;
	}
	while(p1->next!=p2->next);

	if(p1==p2){return true;}

	return false;
}

int main(){


	node* head1=NULL;
	intail(head1,1);
	intail(head1,2);
	intail(head1,3);
	intail(head1,4);
	node* p=point(head1,2);

	node* head2=NULL;
	intail(head2,9);
	intail(head2,8);
	intail(head2,7);
	//display(head2);
	clink(head2,p);
	display(head1);
	display(head2);
	cout<<len(head1)<<endl;
	cout<<len(head2)<<endl;
	int lofl=0;
	node*p1=NULL;
	if(len(head1)>len(head2)){
		lofl=len(head1)-len(head2);
		p1=point(head1,lofl+1);
		cout<<checkforj(p1,head2)<<endl;
	}
	else {
		lofl=len(head2)-len(head1);
		p1=point(head2,lofl+1);
		cout<<checkforj(p1,head1)<<endl;
	}
	cout<<p1->data<<endl;




	return 0;

}

