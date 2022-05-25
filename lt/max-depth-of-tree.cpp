#include<iostream>
using namespace std;


class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;

        int depthLeft=maxDepth(root->left)+1;
        int depthRight=maxDepth(root->right)+1;

        return max(depthLeft,depthRight);
        
    }
};
