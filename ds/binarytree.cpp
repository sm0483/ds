#include<iostream>
using namespace std;

class node{
	public:
	int data;
	node* left;
	node* right;




	node(int val){
		data=val;
		right=NULL;
		left=NULL;
	}


};





int main(){

	node* root =new node(1);
	node* l=new node(2);
	node* r=new node(3);

	root->right=r;
	root->left=l;

	cout<<root->right->data<<endl;
	cout<<root->left->data<<endl;









}
