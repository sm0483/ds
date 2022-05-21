#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>answer;
        stack<TreeNode*>st;
        st.push(root);

        while(!st.empty()){
            TreeNode* curr=st.top();
            st.pop();
            if(curr->right) st.push(curr->right);
            if(curr->left) st.push(curr->left);
            answer.push_back(curr->val);

        }

        return answer;
        
        
    }
};

