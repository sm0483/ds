#include<iostream>
using namespace std;



class node{
	public:
		node*left;
		node*right;
		int data;

		node(int val){
			left=NULL;
			right=NULL;
			data=val;
		}

};
void preorder(node* root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);

}


void inorder(node * root){
	if(root==NULL){
	return;
	}
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
void postorder(node* root){
	if(root==NULL){
		return;
	}
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";

}

int main(){

	node*root=new node(1);
	//left branch
	root->left=new node(2);
	root->left->left=new node(4);
	root->left->right=new node(5);
	//right branch
	root->right=new node(3);
	root->right->left=new node(6);
	root->right->right=new node(7);

	preorder(root);
	cout<<endl;
	inorder(root);
	cout<<endl;
	postorder(root);
	cout<<endl;

	return 0;
}
