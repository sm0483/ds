#include<iostream>
using namespace std;



class Node{
	public:
		int data;
		Node* right;
		Node* left;
		Node(int val){
			right=NULL;
			left=NULL;
			data=val;
		}
};

int search(int inorder[],int start,int end,int curr){
	for(int i=start;i<=end;i++){
		if(inorder[i]==curr){
			return i;

		}
	}
	return -1;
}

Node* buildtree(int postorder[],int inorder[],int start,int end){
	if(start>end){
		return NULL;

	}
	static int idx=end-1;
	int curr=postorder[idx];
	idx--;
	Node* node=new Node(curr);
	if(start==end){
		return node;
	}
	int pos=search(inorder,start,end,curr);
	node->right=buildtree(postorder,inorder,pos+1,end);
	node->left=buildtree(postorder,inorder,start,pos-1);
	return node;
}

void printpost(Node *node){
	if(node==NULL){
		return ;
	}
	printpost(node->left);
	printpost(node->right);
	cout<<node->data<<" ";
}

int main(){
	int pos[]={4,5,2,6,7,3,1};
	int ino[]={4,2,5,1,6,3,7};
	Node *node=buildtree(pos,ino,0,7);
	printpost(node);

	return 0;
}
