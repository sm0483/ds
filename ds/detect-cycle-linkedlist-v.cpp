#include<iostream>
#include<vector>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;

    ListNode(int _val){
        val=_val;
        next=NULL;

    }


};


void addNode(ListNode* &node,int val){
    ListNode* n=new ListNode(val);
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


void createCycle(ListNode* head,int pos){
    ListNode* temp=head;
    int count=1;
    ListNode* cycleNode;
    while(temp->next!=NULL){
        if(count==pos){
            cycleNode=temp;

        }

        temp=temp->next;
        count++;

    }
    temp->next=cycleNode;

}

void print(ListNode* node){
    ListNode* temp=node;
    while(temp!=NULL){
        cout<<temp->val<<"->";
        temp=temp->next;

    }



}



class Solution {
    public:
        bool hasCycle(ListNode *head) {
            if(head==NULL || head->next==NULL) return false;
            ListNode* slow=head;
            ListNode* fast=head;

            while(fast->next!=NULL && fast->next->next!=NULL){
                slow=slow->next;
                fast=fast->next->next;

                if(slow==fast)return true;

            }

            return false;
        }
};




int main(){
    ListNode *head=NULL;
    addNode(head,1);
    addNode(head,2);
    //    addNode(head,3);
    //  addNode(head,4);
    createCycle(head,1);
    Solution s;
    cout<<s.hasCycle(head)<<endl;

    //print(head);


    return 0;
}
