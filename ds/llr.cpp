#include <iostream>
using namespace std;

class node{
	public:

		int data;
		node* next;


		node(int value){

			data=value;
			next=NULL;
		}
};








void insertail(node* &head,int value){

	node* n=new node(value);

	if (head==NULL){

		head=n;
		return;
	}
	node* temp=head;
	while(temp->next!=NULL){

		temp=temp->next;
	}

	temp->next=n;


}

/*void OddAEven(node* head){

	node* oddptr=head;
	node* eveptr=head->next;
	node* temp=head->next;

		while( eveptr->next->next!=NULL && oddptr->next!=NULL ){
		oddptr->next=oddptr->next->next;
		eveptr->next=eveptr->next->next;


		oddptr=oddptr->next;
		eveptr=eveptr->next;


	}


	eveptr->next=NULL;
	oddptr->next=temp;



*/






void OddAEven(node* head){

	node* odd=head;
	node* even=head->next;
	node* temp=even;


	while(odd->next!=NULL && even->next!=NULL){
	
	odd->next=even->next;
	odd=odd->next;
	even->next=odd->next;
	even=even->next;
	}











}
void inserthead(node*& head,int value){

	node*n=new node(value);
	n->next=head;
	head=n;


}

void print(node* head){

	node* temp=head;

	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp=temp->next;

	}
	cout<<endl;


}

void search(node *head,int key){
	node* temp=head;

	while(temp!=NULL){

		if(temp->data==key){
			cout<<"foud"<<endl;

		}
		temp=temp->next;


	}

}

node* reverse(node* head){

	node* preptr=NULL;
	node* curptr=head;
	node*nexptr;


	while(curptr!=NULL){
		nexptr=curptr->next;
		curptr->next=preptr;

		preptr=curptr;
		curptr=nexptr;
	

	}

	return preptr;

	

}






int main(){

	node* head=NULL;
	insertail(head,1);
	insertail(head,2);
	insertail(head,3);
	insertail(head,4);
	insertail(head,5);

        //insertail(head,6);
	//	print(head);
	//inserthead(head,6);
	//print(head);
	//search(head,4);
	print(head);
	//node* newhead=reverse(head);
	//print(newhead);
	OddAEven(head);
	print(head);




	return 0;
}
