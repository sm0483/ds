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
int height(Node* root){
   if(root==NULL){
	  return 0;

   }
   int lh=height(root->left);
   int rh=height(root->right);
   return max(lh,rh)+1;

}

int diameter(Node * root){
   if(root==NULL){
	  return 0;

   }
   static int dm=0;
   diameter(root->left);
   diameter(root->right);
   int lhight=height(root->left);
   int rhight=height(root->right);
   cout<<dm<<endl;
   dm=max(dm,lhight+rhight);
   return dm;

}
int dimeter(Node* root,int &dmeter){
   if(root==NULL){
	  return 0;
   }
   int lh=dimeter(root->left,dmeter);
   int rh=dimeter(root->right,dmeter);
   dmeter=max(dmeter,lh+rh);

   return max(lh,rh)+1;



}


int main(){
   int pre[]={1,2,4,5,3,6,7};
   int ino[]={4,2,5,1,6,3,7};
   Node* root=buildtree(pre,ino,0,6);
   //inorderbuild(root);
   //cout<<diameter(root)<<" ";
   int dmeter=0;
   dimeter(root,dmeter);
   cout<<dmeter<<endl;
   cout<<endl;

   return 0;
}
