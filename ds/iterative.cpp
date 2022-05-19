#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(){
        val=0;
        left=NULL;
        right=NULL;

    }

    TreeNode(int _val){
        val=_val;
        left=NULL;
        right=NULL;
    }

};


void creatTree(TreeNode* &root){
    TreeNode* lOne=root->left=new TreeNode(2);
    TreeNode* rOne=root->right=new TreeNode(5);

    TreeNode* llTwo=lOne->left=new TreeNode(3);
    TreeNode* lrTwo=lOne->right=new TreeNode(4);

    //TreeNode* rlTwo=rOne->left=new TreeNode()
    TreeNode* rrTwo=rOne->right=new TreeNode(6);


}


class Bfs{
    public:
    vector<int> pre(TreeNode* root){
        stack<TreeNode*>st;
        st.push(root);
        vector<int>v;
        while(!st.empty()){
            TreeNode* curr=st.top();
            st.pop();
            if(curr->right)st.push(curr->right);
            if(curr->left)st.push(curr->left);
            cout<<curr->val<<"-";
            v.push_back(curr->val);
        }
        return v;
    }


};

void preTraversal(TreeNode * root){
    if(root==NULL) return;
    cout<<root->val<<"-";
    preTraversal(root->left);
    preTraversal(root->right);
}



int main(){
    TreeNode* root=new TreeNode(1);
    creatTree(root);
    preTraversal(root);
    cout<<endl;
    Bfs* obj=new Bfs();
    obj->pre(root);
    return 0;


}



