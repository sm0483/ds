#include<iostream>
using namespace std;

class Node{
   public:
	  int data;
	  Node *link;

	  Node(int val){
		 data=val;
		 link=NULL;


	  }
};

void blinklist(Node* &head,int val){
   Node* n=new Node(val);
   if(head==NULL){
	  head=n;
	  return;
   }

   Node* temp=head;
   while(temp->link!=NULL){
	  temp=temp->link;

   }
   temp->link=n;

}

void print(Node* head){
   Node* temp=head;
   while(temp!=NULL){
	  cout<<temp->data<<"->";
	  temp=temp->link;

   }
   cout<<endl;
}




int main(){
   Node* head=NULL;
   blinklist(head,1);
   blinklist(head,2);
   blinklist(head,3);
   blinklist(head,4);
   print(head);



   return 0;
}
