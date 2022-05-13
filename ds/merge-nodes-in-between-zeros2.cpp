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
    ListNode* next;

    ListNode(){
        val=0;
        next=NULL;

    }

    ListNode(int _val){
        val=_val;
        next=NULL;

    }

};


class Solution {
    private:
        ListNode* changeNode(ListNode* node,int track){
            node->val=track;
            node->next=NULL;
            return node;
        }
    public:
        ListNode* mergeNodes(ListNode* head) {
            ListNode* temp=head->next;
            ListNode* newHead=new ListNode();
            ListNode* newTemp=newHead;
            int track=0;
            while(temp->next!=NULL){
                track+=temp->val;
                ListNode* point=temp->next;
                if(!temp->next->val){
                    newTemp->next=changeNode(temp,track);
                    newTemp=newTemp->next;
                    track=0;
                }
                temp=point;
            }

            return newHead->next;

        }

};


void createNode(ListNode* &head,int val){
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
    while(head!=NULL){
        cout<<head->val<<"-";
        head=head->next;

    }
    cout<<endl;

}
int main(){
    ListNode* head=NULL;
    //0,1,0,3,0,2,2,0
    createNode(head,0);
    createNode(head,1);
    createNode(head,0);
    createNode(head,3);
    createNode(head,0);
    createNode(head,2);
    createNode(head,2);
    createNode(head,0);
    Solution * s=new Solution();
    ListNode* newHead=s->mergeNodes(head);
    print(newHead);

}
