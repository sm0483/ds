#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node*left;
		Node*right;

		Node(int val){
			data=val;
			left=NULL;
			right=NULL;
		}

};


void inorderbuild(Node *root){
	if(root==NULL){
		return;
	}
	inorderbuild(root->left);
	cout<<root->data<<" ";
	inorderbuild(root->right);
}

int search(int inorder[],int start,int end,int curr){
	for(int i=start;i<=end;i++){
		if(inorder[i]==curr){
			return i;
		}
	}
	return -1;
}


Node* buildtree(int preorder[],int inorder[],int start,int end){
	static int idx=0;
	if(start>end){
		return NULL;

	}
	int curr=preorder[idx];
	idx++;
	Node*node =new Node(curr);
	if(start==end){
		return node;

	}
	int pos=search(inorder,start,end,curr);
	node->left=buildtree(preorder,inorder,start,pos-1);
	node->right=buildtree(preorder,inorder,pos+1,end);
	return node;

}
//inorder

void inorder(Node* root,vector<int>&ds){
   stack<int>st;
   st.push(root->data);
   while(!st.empty()){
	  if()
   
   
   }
    



}


int main(){
	int pre[]={1,2,4,5,3,6,7};
	int ino[]={4,2,5,1,6,3,7};
	Node* root=buildtree(pre,ino,0,6);
	//inorderbuild(root);
	

	return 0;
}
