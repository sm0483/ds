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
        ListNode* removeNthFromEnd(ListNode* head, int n) {

            ListNode* start=new ListNode();
            start->next=head;

            ListNode* slow=start;
            ListNode* fast=start;
    

            for (int i=1;i<=n;++i){
                slow=slow->next;

            }

            //cout<<"count"<<count<<"key"<<start->val<<endl;

            while(slow->next!=NULL){
                slow=slow->next;
                fast=fast->next;

            }

            ListNode* toDel=fast->next;
            fast->next=fast->next->next;
            delete(toDel);

            return start->next;




        }
};


int main(){
    ListNode* head=NULL;
    addNode(head,1);
    addNode(head,2);
    addNode(head,3);
    addNode(head,4);
    addNode(head,5);

    Solution s;
    ListNode* newHead=s.removeNthFromEnd(head,5);
    print(newHead);




    return 0;
}
