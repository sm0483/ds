#include<iostream>
#include<vector>
#include<queue>
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
int search(int ino[],int curr,int start,int end){
   for(int i=start;i<=end;i++){
	  if(curr=ino[i])return i;

   }
   return -1;


}
Node* build(int preorder[],int inorder[],int start ,int end){
   if(start>end){
	  return NULL;
   }

   static int idx=0;
   int curr=preorder[idx];
   idx++;
   Node* root=new Node(curr);
   if(start==end){
	  return root;
   }

   int pos=search(inorder,curr,start,end);
   root->left=build(preorder,inorder,start,pos-1);
   root->right=build(preorder,inorder,pos+1,end);
   return root;
}

void leveltr(Node* root,vector<Node*>&ds){
   queue<Node*>q;
   q.push(root);
   while(!q.empty()){
	  int size=q.size();
	  for(int i=0;i<size;i++){
		 Node* node=q.front();
		 q.pop();
		 if(node->left){q.push(node->left);}
		 if(node->right){q.push(node->right);}
		 ds.push_back(node);

	  }
   }


}


int main(){
   int pre[]={1,2,4,5,3,6,7};
   int ino[]={4,2,5,1,6,3,7};
   Node* root=build(pre,ino,0,6);
   cout<<"level order: ";
   vector<Node*>ds;
   leveltr(root,ds);
   for(auto node:ds){
	  cout<<node->data<<" ";
   }
   cout<<endl;
   return 0;
}

