#include<iostream>
#include<math.h>
#include<vector>
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
//max balancedtree
int balance(Node* root){
   if(root==NULL){
	  return 0;
   }
   return max(balance(root->left),balance(root->right))+1;

}

bool balancetree(Node* root){
   if(root==NULL){
	  return true;
   }

   int lhight=balance(root->left);
   int lright=balance(root->right);
   if(abs(lhight-lright)>1){
	  return false;
   }
   balancetree(root->left);
   balancetree(root->right);
}
int balatree(Node *root){
   if(root==NULL){
	  return 0;
   
   }

   int leftcount=balatree(root->left);
   int rcount=balatree(root->right);
   if(abs(leftcount-rcount)>1){
	  return -1;   
   }
   return max(leftcount,rcount)+1;

}

int main(){
   int pre[]={1,2,4,5,3,6,7};
   int ino[]={4,2,5,1,6,3,7};
   Node* root=buildtree(pre,ino,0,6);
   //inorderbuild(root);
   //int h=maxdept(root);
   //cout<<h<<endl;
   /*
   Node* root=new Node(1);
   root->left=new Node(5);
   root->right=new Node(2);
   root->right->right=new Node(3);
   root->right->right->right=new Node(4);
   //cout<<balancetree(root)<<endl;
   */
   cout<<balatree(root)<<endl;

   return 0;
}
