#include<iostream>
#include<map>
#include<unistd.h>
using namespace std;



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int _val){
        val=_val;
        next=NULL;

    }

};

ListNode* addNode(ListNode* &head ,int val){
    ListNode* n=new ListNode(val);
    if(head==NULL){
        head=n;
        return head;
    }

    ListNode* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;

    }
    temp->next=n;
    return n;
}

void joinNode(ListNode* toJoin,ListNode *pos){
    toJoin->next=pos;


}

void print(ListNode* head){
    while(head!=NULL){
        cout<<head->val<<"->";
        head=head->next;
        sleep(.9);
    }
    cout<<"end";

}

//first way long
class Solution {
    public:
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
            ListNode* tempA=headA;
            ListNode* tempB=headB;

            while(tempA!=NULL && tempB!=NULL){
                tempA=tempA->next;
                tempB=tempB->next;

            }

            if(tempA!=NULL) tempB=headA;
            else tempA=headB;

            while(tempB!=NULL && tempA!=NULL){
                tempA=tempA->next;
                tempB=tempB->next;
            }


            if(tempA!=NULL) tempB=headA;
            else tempA=headB;


            while(tempA!=tempB){
                tempA=tempA->next;
                tempB=tempB->next;

            }

            return tempA;



        }
};

int main(){
    ListNode* headA=NULL;
    ListNode* headB=NULL;

    addNode(headA,1);
    addNode(headA,2);
    ListNode *pos=addNode(headA,3);
    addNode(headA,4);

    addNode(headB,6);
    addNode(headB,7);
    addNode(headB,2);
    ListNode* toJoin=addNode(headB,8);
    joinNode(toJoin,pos);
//    print(headA);
//    cout<<endl;
  //  cout<<"-----------------"<<endl;
    //print(headB);
    //cout<<"-----------------"<<endl;
    //cout<<endl;




    Solution *s=new Solution();
    ListNode* newHead=s->getIntersectionNode(headA,headB);
//    print(newHead);
    cout<<newHead->val<<endl;

        return 0;
}
