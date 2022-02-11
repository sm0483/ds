#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* left;
		Node* right;
		Node(int val){
			data=val;
			left=NULL;
			right=NULL;

		}
};

//height
int height(Node* root){
	if(root==NULL){return 0;}
	int rh=height(root->right)+1;
	int lf=height(root->left)+1;
	return max(lf,rh);

}

int CountNodes(Node* node){
	if(node==NULL){return 0;}
	//return CountNodes(node->left)+CountNodes(node->right)+1;
	return CountNodes(node->right)+CountNodes(node->left)+1;
}

int search(int ino[],int start,int end,int curr){
	for(int i=start;i<=end;i++){
		if(ino[i]==curr){return i;}
	}

	return -1;
}
void printpre(Node *node){
	if(node==NULL){return;}
	cout<<node->data<<" ";
	printpre(node->left);
	printpre(node->right);

}
int  sum(Node* node){
	if(node ==NULL){
		return 0;
	}
	return sum(node->right)+sum(node->left)+node->data;

}

Node * buildtree(int pre[],int ino[],int start,int end){
	if(start>end){
		return NULL;
	}
	static int idx=0;
	int curr=pre[idx];
	idx++;
	Node *node=new Node(curr);
	if(start==end){
		return node;
	}
	int pos=search(ino,start,end,curr);
	node->left=buildtree(pre,ino,start,pos-1);
	node->right=buildtree(pre,ino,pos+1,end);

	return node;
}
int main(){
	int pre[]={1,2,4,5,3,6,7};
	int ino[]={4,2,5,1,6,3,7};
	Node*root=buildtree(pre,ino,0,6);
	printpre(root);
	cout<<endl;
	cout<<CountNodes(root)<<endl;
	cout<<sum(root)<<endl;
	cout<<height(root)<<endl;

	return 0;
}


