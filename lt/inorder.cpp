#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void reSolution(TreeNode* root,vector<int>&answer){
        if(root==NULL) return;
        reSolution(root->left);
        answer.push_back(root->val);
        reSolution(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>answer;
        reSolution(root,answer);
        return answer;
        
        
    }
};
