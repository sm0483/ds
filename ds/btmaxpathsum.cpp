#include<iostream>
#include<math.h>
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
   for(int i=start;i<=end;i++){
	  if(curr==ino[i]){
		 return i;
	  }
   }

   return -1;
}


Node* buildtree(int pre[],int ino[],int start,int end){
   static int idx=0;
   if(start>end){
	  return NULL;
   }
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

int maxsumpath(Node* root,int &sum){
   if(root==NULL){
	  return 0;
   }
   int lsum=maxsumpath(root->left,sum);
   int rsum=maxsumpath(root->right,sum);

   sum=max(sum,lsum+rsum+root->data);
   return root->data+max(lsum,rsum);


}



int main(){
   int pre[]={1,2,4,5,3,6,7};
   int ino[]={4,2,5,1,6,3,7};
   Node *root=buildtree(pre,ino,0,6);
   //preprint(root);
   int sum=0;
   maxsumpath(root,sum);
   cout<<sum<<endl;
   return 0;
}
