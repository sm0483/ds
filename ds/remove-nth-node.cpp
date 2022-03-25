#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int _val){
        val=_val;
        next=NULL;

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
            ListNode* temp=head;
            ListNode* toAdd=NULL;
            ListNode* toDel=NULL;
            if(head==NULL){
                return NULL;

            }
            int count =0;
            while(temp!=NULL){
                temp=temp->next;
                count++;

            }
//            cout<<count<<endl;
          int pos=count-n;
          if(pos==0){
              toDel=head;
              toAdd=head->next;
              delete(toDel);
              return toAdd;
          }
           count=1;
          temp=head;
          while(temp->next!=NULL && count!=pos){
              temp=temp->next;
              count++;

          }

          toAdd =temp->next->next;
          toDel=temp->next;
          temp->next=toAdd;
          delete(toDel);
          return head;


        }
};


int main(){
    ListNode * head=NULL;
    addNode(head,1);
    addNode(head,2);
    addNode(head,3);
    addNode(head,4);
    addNode(head,5);
    print(head);

    Solution s;
    ListNode* newHead=s.removeNthFromEnd(head,5);
    print(newHead);

    return 0;
}
