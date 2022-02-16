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

int search(int ino[],int curr,int start,int end){
   for(int i=start;i<=end;i++){
	  if(curr==ino[i]){
		 return i;
	  }
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

void print(Node* root){
   if(root==NULL){
	  return;
   }
   cout<<root->data<<" ";
   print(root->left);
   print(root->right);

}
//level order

void level(Node* root){
   queue<int>q;
   q.push(root);
   q.push(NULL);

   while(!q.empty()){
	  Node *node=q.front();
	  q.pop();
	  if(node!=NULL){
		 cout<<node->data<<endl;

	  }
	  while(q.empty()){
		 if(root->left){
			q.push(root->left);
		 }
		 if(root->right){
			q.push(root->right);
		 
		 }

	  }



   }



}



int main(){
   int pre[]={1,2,4,5,3,6,7};
   int ino[]={4,2,5,1,6,3,7};
   Node* root=build(pre,ino,0,6);
   print(root);
   queue<int>q;



   return 0;
}
