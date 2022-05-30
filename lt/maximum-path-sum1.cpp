class Solution {
public:

    int getRe(TreeNode* root,int &answer){
        if(root==NULL) return 0;
       
        int leftSum=max(0,getRe(root->left,answer)); //to avoid negative root just ignore it by returning 0
        int rightSum=max(0,getRe(root->right,answer));
        int temp=leftSum+rightSum+root->val;
        answer=max(temp,answer);

        return max(leftSum,rightSum)+root->val;

    }
    int maxPathSum(TreeNode* root) {
        int answer=INT_MIN;
        getRe(root,answer);
        return answer;
        
    }
};
