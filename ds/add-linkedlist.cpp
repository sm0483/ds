#include<iostream>
#include<vector>
#include<algorithm>
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
        void addNode(ListNode* &node,int val){
            ListNode* n=new ListNode(val);
            if(node==NULL){
                node=n;
                return;

            }

            node->next=n;
        }

        bool check(int &val){
            if(val>9){
                val=val-10;
                return true;
            }
            return false;

        }
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode* head=new ListNode();
            ListNode* temp=head;
            bool next=false;
            int value=0;

            while(l1!=NULL && l2!=NULL){
                value=l1->val+l2->val;
                l1=l1->next;
                l2=l2->next;
                if(next)value=value+1;
                if(check(value)){
                    addNode(temp,value);
                    next=true;

                }
                else{
                    addNode(temp,value);
                    next=false;

                }

                temp=temp->next;

            }

            while(l1!=NULL){
                value=l1->val;
                l1=l1->next;
                if(next)value=value+1;
                if(check(value)){
                    addNode(temp,value);
                    next=true;

                }
                else{
                    addNode(temp,value);
                    next=false;

                }

                temp=temp->next;



            }

            while(l2!=NULL){
                value=l2->val;
                l2=l2->next;
                if(next)value=value+1;
                if(check(value)){
                    addNode(temp,value);
                    next=true;

                }
                else{
                    addNode(temp,value);
                    next=false;

                }

                temp=temp->next;


            }

            return head->next;


        }
};





int main(){
    ListNode* head=NULL;
    ListNode* head2=NULL;
    addNode(head,5);
    addNode(head,6);
    addNode(head,7);
    addNode(head,3);
    addNode(head2,6);

    addNode(head2,3);
    addNode(head2,1);
    //addNode(head2,1);
/*
    addNode(head2,1);
    addNode(head2,1);

    addNode(head2,1);
    addNode(head2,1);
    addNode(head2,1);
    //addNode(head,5);
    */
    Solution s;
    ListNode* newHead=s.addTwoNumbers(head,head2);
    print(newHead);


    return 0;
}


