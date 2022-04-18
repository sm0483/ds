#include<iostream>
#include<unistd.h>
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

    ListNode(int x){
        val=x;

    }

    ListNode(int x,ListNode *_next){
        val=x;
        next=_next;
    }


};


void addNode(ListNode* &head,int val){
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

void printNext(ListNode* head){
    while(head!=NULL){
        cout<<head->val<<"->";
        head=head->next;
        sleep(0.5);

    }
    cout<<"end"<<endl;

}
class Solution {
    public:
        ListNode* rotateRight(ListNode* head, int k) {
            if(head==NULL || head->next==NULL) return head;
            ListNode* temp=head;
            ListNode* lastNode=NULL;
            int count=0;
            while(temp!=NULL){
                lastNode=temp;
                temp=temp->next;
                count++;

            }
            lastNode->next=head;
            int val=count-(k%count);
            temp=head;

            while(--val){
                temp=temp->next;
            }


            ListNode* newHead=temp->next;
            temp->next=NULL;

            return newHead;




        }
};



int main(){
    ListNode* head=NULL;
    addNode(head,1);
    addNode(head,2);
    addNode(head,3);
    addNode(head,4);

    printNext(head);
    Solution *s=new Solution();
    ListNode* newHead=s->rotateRight(head,1);
    printNext(newHead);
    return 0;
}
