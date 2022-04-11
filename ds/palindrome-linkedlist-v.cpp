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
        bool isPalindrome(ListNode* head){
            ListNode* slow=head;
            ListNode* fast=head;
            ListNode* temp=head;
            //find middle
            while(fast->next!=NULL && fast->next->next!=NULL){
                slow=slow->next;
                fast=fast->next->next;

            }
            //reverse from middle

            ListNode* first=slow->next;
            ListNode* second=NULL;
            ListNode* third=NULL;

            while(first!=NULL){
                second=first;
                first=first->next;
                second->next=third;
                third=second;
            }

            slow->next=second;

            while(second!=NULL){
                if(second->val!=temp->val) return false;
                second=second->next;
                temp=temp->next;

            }

            return true;



        }
};




int main(){
    ListNode *head=NULL;
    addNode(head,1);
    addNode(head,2);
    addNode(head,3);
    addNode(head,4);
    addNode(head,5);
    addNode(head,6);
    print(head);
    Solution *s=new Solution();
    bool newHead=s->isPalindrome(head);
    cout<<endl;
    //print(newHead);
    cout<<newHead<<endl;
    return 0;


}
