#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
   public:
	  int data;
	  Node *left;
	  Node *right;
	  Node(int val){
		 data=val;
		 left=NULL;
		 right=NULL;

	  }

};
int search(int ino[],int curr,int start,int end){
   for(int i=start;i<=end;i++)
	  if(curr==ino[i]){return i;}
   return -1;

}
Node* buildtree(int pre[],int inorder[],int start,int end){
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
   int pos=search(inorder,curr,start,end);
   node->left=buildtree(pre,inorder,start,pos-1);
   node->right=buildtree(pre,inorder,pos+1,end);
   return node;

}
void print(Node* root){
   if(root==NULL){return;}
   cout<<root->data<<" ";
   print(root->left);
   print(root->right);


}

//leveltraversel
void traversel(Node* root,vector<int>&ds){
   queue<Node*>q;
   q.push(root);
   while(!q.empty()){
	  int size=q.size();
	  for(int i=0;i<size;i++){
		 Node *node=q.front();
		 q.pop();
		 if(node->left){
			q.push(node->left);
		 }
		 if(node->right){
			q.push(node->right);
		 }
		 ds.push_back(node->data);

	  }



   }



}

int main(){
   int pre[]={1,2,4,5,3,6,7};
   int ino[]={4,2,5,1,6,3,7};
   Node* root=buildtree(pre,ino,0,6);
   //print(root);
   vector<int>ds;
   traversel(root,ds);
   for(auto i: ds){
	  cout<<i<<" ";

   }
   cout<<endl;
   return 0;
}
