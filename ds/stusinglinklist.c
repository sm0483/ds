#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int val;
	struct Node *next;

}Node;



void push(Node* head,int _val){
	//create new node;
	Node *rest=head->next;
	Node* new=((Node*)malloc(sizeof(Node)));
	new->val=_val;
	new->next=rest;

	head->next=new;

}

void display(Node* head){

	Node *temp=head;

	while(temp!=NULL){
		printf("%d->",temp->val);
		temp=temp->next;
	}


}

void pop(Node* head){
	Node* rest=NULL;
	if(head->next!=NULL)rest=head->next->next;
	Node* todel=head->next;
	free(todel);
	head->next=rest;


}




int main(){
	//create head;
	Node* head=NULL;
	head=((Node*)malloc(sizeof(Node)));
	head->val=0;
	push(head,1);
	push(head,3);
	push(head,4);
	display(head);
	pop(head);
	pop(head);
	pop(head);
	display(head);
	return 0;

}
