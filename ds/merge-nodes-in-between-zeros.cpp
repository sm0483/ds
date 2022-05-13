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
    public:
        ListNode* mergeNodes(ListNode* head) {
            ListNode* temp=head;
            ListNode* newHead=NULL;
            int track=0;
            while(temp!=NULL){
                if(!temp->val){
                    getList(newHead,track);
                    track=0;
                }
                track+=temp->val;
                temp=temp->next;
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
    createNode(head,0);
    createNode(head,3);
    createNode(head,1);
    createNode(head,0);
    createNode(head,4);
    createNode(head,5);
    createNode(head,2);
    createNode(head,0);
    Solution * s=new Solution();
    ListNode* newHead=s->mergeNodes(head);
    print(newHead);

}
