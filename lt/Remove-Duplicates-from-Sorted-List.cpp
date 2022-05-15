#include<iostream>
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
// non recuressive
struct ListNode{
    int val;
    ListNode* next;

    ListNode(int _val){
        val=_val;
        next=NULL;

    }
};
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* temp1=head;
        ListNode* temp2=head->next;
        while(temp2!=NULL){
            if(temp1->val==temp2->val){
                ListNode* toDel=temp2;
                temp1->next=temp2->next;
                temp2=temp2->next;
                delete(toDel);
            }
            else{
                temp1=temp1->next;
                temp2=temp2->next;

            }


        }
        
    }
};


//recuressive
class Solution {
public:
    void getSolution(ListNode* head){
        if(head==NULL || head->next==NULL) return;
        if(head->val==head->next->val){
            ListNode* toDel=head->next;
            head->next=head->next->next;
            delete(toDel);
            getSolution(head);

        }
        else{
            getSolution(head->next);

        }

    }
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* newHead=head;
        getSolution(head);
        return newHead;
        
    }
};
