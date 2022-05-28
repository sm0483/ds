#include<iostream>
using namespace std;



class Solution {
    public:
        int height(TreeNode* root){
            if(root==NULL) return 0;

            int leftH=height(root->left);
            int rightH=height(root->right);

            return max(leftH,rightH)+1;
        }
        void reSolution(TreeNode *root,int &diameter){
            if(root==NULL) return;

            int leftH=height(root->left);
            int rightH=height(root->right);
            int currentValue=leftH+rightH;

            if(diameter<currentValue){
                diameter=currentValue;
            }
            reSolution(root->left,diameter);
            reSolution(root->right,diameter);


        }
        int diameterOfBinaryTree(TreeNode* root) {
            int diameter=-1;
            reSolution(root,diameter);
            return diameter;

        }
};

