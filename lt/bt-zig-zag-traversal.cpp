#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class TreeNode{
    public:
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int _val){
            val=_val;
            left=NULL;
            right=NULL;
        }

};



class Solution {
    public:
        vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
            if(root==NULL) return {};
            queue<TreeNode*>q;
            q.push(root);
            vector<vector<int>>result;
            int idx;
            bool letToRight=true;
            while(!q.empty()){
                int size=q.size();
                vector<int>tempDs(size);
                if(letToRight) letToRight=false;
                else letToRight=true;

                for(int i=0;i<size;i++){
                    TreeNode* node=q.front();
                    if(node->left) q.push(node->left);
                    if(node->right) q.push(node->right);
                    if(letToRight) idx=size-1-i;
                    else idx=i;

                    tempDs[idx]=node->val;
                    q.pop();
                }
                result.push_back(tempDs);
            }
            return result;
        }

};
