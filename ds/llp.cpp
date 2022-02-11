#include <iostream>
using namespace std;


class node{
	public:


		int data;
		node *next;







};

void print(node *n){

	while (n!=NULL){

		cout<<n->data<<" ";
		n=n->next;
	}


}




int main(){


	node *head;
	node *first;
	node *second;

	head=new node();
	first=new node();
	second=new node();


	head->data=2;
	head->next=first;
	first->data=3;
	first->next=second;
	second->data=5;
	second->next=NULL;


	print(head);






	return 0;

}
