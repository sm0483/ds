#include<iostream>
#include<stack>
#include<vector>
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

class trversel{
   public:
	  vector<int>ds;
	  bool leafnode(Node* root){
		 if(root->right==NULL && root->right==NULL){
			return true;

		 }
		 return false;

	  }

	  void leftside(Node* root){
		 Node* curr=root->left;
		 ds.push_back(root->data);
		 while(curr){
			if(!leafnode(curr)){
			   ds.push_back(curr->data);
			}
			if(curr->left){
			   curr=curr->left;

			}
			else{
			   curr=curr->right;
			}
		 
		 }

	  }

	  void rightside(Node* root){
		 Node* curr=root->right;
		 stack<int>st;
		 while(curr){
			if(!leafnode(curr)){
			   st.push(curr->data);
			   
			}
			if(curr->right){
			   curr=curr->right;
			
			}
			else{
			   curr=curr->left;
			
			}
		 
		 }

		 while(!st.empty()){
			ds.push_back(st.top());
			st.pop();
		 }
	  
	  }

	  void leafside(Node* root){
		 if(leafnode(root)){
			ds.push_back(root->data);
			return;
		 
		 }
		 if(root->left)leafside(root->left);
		 if(root->right)leafside(root->right);

	  
	  }

	  vector<int> answer(){
		 return ds;
	  
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


int main(){
   int pre[]={1,2,4,5,3,6,7};
   int ino[]={4,2,5,1,6,3,7};
   Node* root=build(pre,ino,0,6);
   //print(root);
   trversel obj;
   obj.leftside(root);
   obj.leafside(root);
   obj.rightside(root);
   vector<int>ds=obj.answer();
   for(auto i :ds){
	  cout<<i<<" ";
   
   }
   cout<<endl;









   return 0;
}
