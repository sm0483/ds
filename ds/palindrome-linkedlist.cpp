#include<iostream>
#include<vector>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


struct ListNode{
    int val;
    ListNode *next;
    ListNode(){
        val=0;
        next=NULL;

    }

    ListNode(int _val){
        val=_val;
        next=NULL;

    }

    ListNode(int _val,ListNode *_next){
        val=_val;
        next=_next;
    }


};
ListNode* addNode(ListNode* &head ,int val){
    ListNode* n=new ListNode(val);
    if(head==NULL){
        head=n;
        return head;
    }

    ListNode* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;

    }
    temp->next=n;
    return n;
}

void print(ListNode* head){
    while(head!=NULL){
        cout<<head->val<<"->";
        head=head->next;

    }
    cout<<"end";


}

class Solution {
    public:
        vector<int>v;
        bool isPalindrome(ListNode* head){
            ListNode *current=head;
            ListNode *second=NULL;
            ListNode *first=NULL;

            while(current!=NULL){
                v.push_back(current->val);
                current=current->next;

            }

            current=head;

            while(current!=NULL){
                second=current;
                current=current->next;
                second->next=first;
                first=second;
            }

            ListNode* temp=second;
            int i=0;
            while(temp!=NULL){
                if(temp->val!=v[i])return false;
                temp=temp->next;
                i++;
            }

            return true;

        }
};




int main(){
    ListNode *head=NULL;
    addNode(head,1);
//    addNode(head,1);
//    addNode(head,3);
  //      addNode(head,4);
    print(head);
    Solution *s=new Solution();
    bool newHead=s->isPalindrome(head);
    cout<<endl;
    cout<<newHead<<endl;
    return 0;


}
