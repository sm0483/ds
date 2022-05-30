
class Solution {
public:
    int sum(TreeNode* root){
        if(root==NULL) return 0;
        int leftSum=max(0,sum(root->left))+root->val;
        int rightSum=max(0,sum(root->right))+root->val;

        return max(leftSum,rightSum);

    }

    void getRe(TreeNode* root,int &answer){
        if(root==NULL) return;
       
        int leftSum=max(0,sum(root->left));
        int rightSum=max(0,sum(root->right));
        int temp=leftSum+rightSum+root->val;
        answer=max(temp,answer);
        
        getRe(root->left,answer);
        getRe(root->right,answer);
        
        

    }
    int maxPathSum(TreeNode* root) {
        int answer=INT_MIN;
        getRe(root,answer);
        return answer;
        
    }

