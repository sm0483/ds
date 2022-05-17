#include<iostream>
#include<algorithm>
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
    ListNode(int _val){
        val=_val;
        next=NULL;
    }

};
void getList(ListNode* &head,int val){
   ListNode* n=new ListNode(val);
   if(head==NULL){
	  head=n;
	  return;
   }

   ListNode* temp=head;
   while(temp->next!=NULL){
	  temp=temp->next;

   }
   temp->next=n;

}

void print(ListNode* head){
   ListNode* temp=head;
   while(temp!=NULL){
	  cout<<temp->val<<"->";
	  temp=temp->next;

   }
   cout<<endl;
}

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* curr=head;
        ListNode * next=head->next;

        while(curr->next->next && next->next->next){
           swap(curr->val,next->val);
           curr=curr->next->next;
           next=next->next->next;
        }
        if(curr->next && next){
            swap(curr->val, next->val);
        }
        return head;
        
    }
};

int main(){
    ListNode* head=NULL;
    getList(head,1);
    getList(head,2);
    getList(head,3);
    getList(head,4);
    getList(head,1);
    print(head);
    Solution *s=new Solution();
    ListNode* newHead=s->swapPairs(head);
    print(newHead);

}
