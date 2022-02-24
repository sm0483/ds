#include<iostream>
#include<vector>
#include<queue>

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

bool order(int k){
   if(k%2==0){
	  return true;
   
   }
   return false;


}

void zig_zag(Node* node,vector<vector<int>>&ds){
   queue<Node*>q;
   q.push(node);
   int count=0;
   while(!q.empty()){
	  int size=q.size();
	  int pos=0;
	  vector<int>v(size);
	  for(int i=0;i<size;i++){
		 Node*root=q.front();
		 q.pop();
		 if(order(count)){
			pos=size-1-i;
		 }
		 else{
			pos=i;
		
		 }
		 v[pos]=root->data;
		 if(root->left){
			q.push(root->left);
		 
		 }
		 if(root->right){
			q.push(root->right);
		 }

	  }
	  ds.push_back(v);
	  count++;
   }
}


int main(){
   int pre[]={1,2,4,5,3,6,7};
   int ino[]={4,2,5,1,6,3,7};
   Node* root=buildtree(pre,ino,0,6);
   //inorderbuild(root);
   vector<vector<int>>ds;
   zig_zag(root,ds);
   for(auto i:ds){
	  for(auto k: i){
		 cout<<k<<" ";
	  
	  }
	  cout<<endl;
   
   }

   return 0;
}
