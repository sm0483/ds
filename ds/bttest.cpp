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


int search(int ino[],int start,int end,int curr){
   for(int i=start;i<end;i++)
	  if(curr==ino[i])
		 return i;
   return -1;
}
Node* buildtree(int pre[],int ino[],int start,int end){
   if(start>end){
	  return NULL;
   }
   static int idx=0;
   int curr=pre[idx];
   idx++;
   Node* node=new Node(curr);
   if(start==end){
	  return node;
   }
   int pos=search(ino,start,end,curr);
   node->left=buildtree(pre,ino,start,pos-1);
   node->right=buildtree(pre,ino,pos+1,end);
   return node;

}
void preprint(Node* root){
   if(root==NULL){
	  return;
   }
   cout<<root->data<<" ";
   preprint(root->left);
   preprint(root->right);
}




int main(){
   int pre[]={1,2,4,5,3,6,7};
   int ino[]={4,2,5,1,6,3,7};
   Node* root=buildtree(pre,ino,0,6);
   preprint(root);




   return 0;
}
