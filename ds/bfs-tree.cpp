#include<iostream>
#include<vector>
#include<queue>
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
    vector<int> bfs(TreeNode* root){
        queue<TreeNode*>q;
        q.push(root);
        vector<int>v;

        while(!q.empty()){
            TreeNode*value=q.front();
            if(value->left) q.push(value->left);
            if(value->right)q.push(value->right);
            q.pop();
            cout<<value->val<<endl;
            v.push_back(value->val);
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
    //preTraversal(root);
    Bfs* obj=new Bfs();
    obj->bfs(root);
    return 0;


}



