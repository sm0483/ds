#include<iostream>
using namespace std;


struct TreeNode{
    int val;
    TreeNode* right;
    TreeNode* left;

    TreeNode(int _val){
        val=_val;
        right=NULL;
        left=NULL;
    }



};

class Solution {
public:
    int count(TreeNode * root){
        if(root==NULL) return 0;

        int lh=count(root->left);
        if(lh==-1) return -1;
        int rh=count(root->right);
        if(rh==-1) return -1;
        if(abs(lh-rh)>1) return -1;
        return max(lh,rh)+1;
    }
    bool isBalanced(TreeNode* root) {
        int answer=count(root);
        if(answer!=-1) return true;
        return false;
    }
};
