#include<iostream>
using namespace std;



struct ListNode{
    int val;
    ListNode* next;

    ListNode(){
        val=0;
        next=NULL;

    }

    ListNode(int _val){
        val=_val;
        next=NULL;

    }

    ListNode(int _val,ListNode* _next){
        val=_val;
        next=_next;

    }



};


//for creating and testing linkedlist


void addNode(ListNode* &node,int val){
    ListNode *n=new ListNode(val);
    if(node==NULL){
        node=n;
        return;

    }
    ListNode* temp=node;
    while(temp->next!=NULL){
        temp=temp->next;

    }
    temp->next=n;


}



void print(ListNode* head){
    while(head!=NULL){
        cout<<head->val<<endl;
        head=head->next;

    }

}

class Solution {
    public:
        ListNode* middleNode(ListNode* head) {
            ListNode* slow=head;
            ListNode* fast=head;

            while(fast!=NULL && fast->next!=NULL){
                fast=fast->next->next;
                slow=slow->next;

            }

            return slow;

        }
};



int main(){
    ListNode* head=NULL;
    addNode(head,1);
    addNode(head,2);
    addNode(head,3);
    addNode(head,4);
//    addNode(head,5);
    Solution s;
    ListNode* newHead=s.middleNode(head);
    print(newHead);


    return 0;
}
