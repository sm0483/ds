

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL)return true;
        if(p==NULL && q!=NULL)return false;
        if(q==NULL && p!=NULL)return false;
        if(p->val!=q->val) return false;


        bool isSameLeft=isSameTree(p->left,q->left);
        bool isSameRight=isSameTree(p->right,q->right);

        if(!isSameLeft || !isSameRight) return false;
        return true;
        
    }
};

