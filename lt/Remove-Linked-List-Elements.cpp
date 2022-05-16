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
    ListNode* removeElements(ListNode* head, int _val) {
        ListNode* temp=head;
        if(head==NULL || head->next==NULL && head->val!=_val) return head;

        while(temp!=NULL && temp->next!=NULL){
            cout<<temp->val<<endl;
            if(temp->next->val==_val){
                ListNode* toDel=temp->next;
                temp->next=temp->next->next;
                delete(toDel);

            }
            else{
                temp=temp->next;
            }
        }
        if(head->val==_val){
            return head->next;
        }
        return head;
    }
};

//Output: [1,2,3,4,5]
//Input: head = [1,2,6,3,4,5,6], val = 6
/*
class Solution {
public:
    void reSolution(ListNode* head ,int _val){
        if(head==NULL) return;
        
        if(head->val==_val){
            ListNode* toDel=head->next;
            head->next=head->next->next;
            delete(toDel);
            reSolution(head,_val);
        }
        else{
            reSolution(head->next,_val);

        }

    }
    ListNode* removeElements(ListNode* head, int _val) {
       ListNode* newHead=head;
       reSolution(head,_val);
       return newHead;
    }
};
*/
int main(){
    ListNode* head=NULL;
    getList(head,6);
    getList(head,6);
    getList(head,5);
    getList(head,6);
//    getList(head,4);
    getList(head,5);
    //getList(head,6);

    print(head);
    Solution* s=new Solution();
    ListNode* newHead=s->removeElements(head,6);
    print(newHead);


}
