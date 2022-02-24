#include<iostream>
#include<vector>
using namespace std;


class Node{
   public:
	  int data;
	  Node* left;
	  Node* right;

	  Node(int val){
		 data=val;
	  }

	  void check(Node* root,vector<int>&ds){
		 if(root==NULL){
			return ;

		 }
		 ds.push_back(root->data);
		 check(root->left,ds);
		 check(root->right,ds);

	  }

	  bool true_false(vector<int>v1,vector<int>v2){
		 if(v1==v2){
			return true;
		 
		 }
		 return false;

	  }

};
int search(int ino[],int start,int end,int curr){
   for(int i=start;i<=end;i++){
	  if(curr==ino[i])
		 return i;
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

int main(){
   int pre[]={1,2,4,5,3,6,7};
   int ino[]={4,2,5,1,6,3,7};
   Node *root1=buildtree(pre,ino,0,6);
   Node *root2=buildtree(pre,ino,0,6);

   Node obj0(1);
   Node obj1(1);
   vector<int>ds0={};
   vector<int>ds1={};

   obj0.check(root1,ds0);
   obj1.check(root2,ds1);
   for(auto i: ds0){
	  cout<<i<<" ";
   
   }
   cout<<endl;
   for(auto i:ds1){
	  cout<<i<<" ";

   }
   cout<<endl;
   if(ds0==ds1){
	  cout<<"they are equal"<<endl;
   
   }
   //cout<<obj1.true_false(ds0,ds1)<<endl;



   return 0;
}
