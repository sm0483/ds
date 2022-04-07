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
    cout<<cycleNode<<endl;
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
        ListNode* detectCycle(ListNode *head) {
            if(head==NULL || head->next==NULL) return NULL;
            ListNode* slow=head;
            ListNode* fast=head;

            while(fast->next!=NULL && fast->next->next!=NULL){
                slow=slow->next;
                fast=fast->next->next;

                if(slow==fast){
                    fast=head;

                while(slow!=fast){
                    slow=slow->next;
                    fast=fast->next;

                }

                return fast;

                }

            }

            return NULL;
        }
};







int main(){
    ListNode *head=NULL;
    addNode(head,1);
    addNode(head,2);
    addNode(head,3);
    addNode(head,4);
    createCycle(head,2);
    Solution s;
    cout<<s.detectCycle(head)<<endl;

    //print(head);


    return 0;
}
