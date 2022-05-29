class Solution {
public:
    int reSolution(TreeNode* root,int &maxHeight){
        if(root==NULL) return 0;
        int leftH=reSolution(root->left,maxHeight)+1;
        int rightH=reSolution(root->right,maxHeight)+1;

        maxHeight=max(maxHeight,leftH+rightH);

        return max(leftH,rightH);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxHeight=0;
        reSolution(root,maxHeight);
        return maxLeft+maxRight;
    }
};
