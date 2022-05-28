#include<iostream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode* right;
    TreeNode * left;

    TreeNode(int _val){
        val=_val;
        right=NULL;
        left=NULL;

    }
};


class Solution {
public:

    int count(TreeNode* root){
        if(root==NULL) return 0;

        int lh=count(root->left);
        int rh=count(root->right);


        return max(lh,rh)+1;


    }


    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;

        bool isLeft=isBalanced(root->left);
        bool isRight=isBalanced(root->right);

        int lh=count(root->left);
        int rh=count(root->right);

        if(abs(lh-rh)>1) return false;
        if(isLeft || isRight) return false;
        return true;



    }
};

