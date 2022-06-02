#include<iostream>
#include<vector>
using namespace std;


struct Node{
    int val;
    Node* left;
    Node* right;

    Node(int _val){
        val=_val;
        left=NULL;
        right=NULL;
    }

};


class Solution{

    bool isLeaf(Node* node){
        if(node->left==NULL || node->right==NULL) return true;
        return false;

    }
    void leftTraversal(Node* root,vector<int>&result){
        Node* curr=root->left;

        while(curr){
            if(!isLeaf(curr)) result.push_back(curr->val);
            if(curr->left) curr=curr->left;
            else curr=curr->right;
        }

    }


    void rightTraversal(Node* root,vector<int>&result){
        Node* curr=root->right;
        vector<int>tmp;
        while(curr){
            if(!isLeaf(curr))tmp.push_back(curr->val);
            if(curr->right) curr=curr->right;
            else curr=curr->left;
        }

        for(int i=tmp.size()-1;i>=0 ;i-- ){
            result.push_back(tmp[i]);
        }
    }

    void leafTraversal(Node* root,vector<int>&result){
        if(root==NULL) return;
        result.push_back(root->val);
        leafTraversal(root->left);
        leafTraversal(root->right);
    }

    vector<int>boundaryTraversal(Node* root){
        if(root==NULL) return {};
        vector<int>result;
        leftTraversal(root,result);
        rightTraversal(root,result);
        leafTraversal(root,result);

        return result;
        
        
    }

};


int main(){

    return 0;
}

