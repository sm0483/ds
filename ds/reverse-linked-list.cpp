#include<iostream>
#include<stack>
using namespace std;

struct ListNode{
    public:
        int val;
        ListNode* next;
        ListNode(int _val){
            val=_val;
            next=NULL;

        }

};


class Solution {
    public:
        ListNode* reverseList(ListNode* head) {
            ListNode* temp3=NULL;
            /*

            do{
                temp2->next=temp3;
                temp3=temp2;
                temp2=temp1;
                temp1=temp1->next;
            }while(temp1!=NULL);

*/
            while(head!=NULL){
                temp2=temp1;
                temp1=temp1->next;
                temp2->next=temp3;
                temp3=temp2;


            }

            return temp3;
        }
};


class Solution1 {
    public:

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
        ListNode* reverseList(ListNode* head){
            stack<int>st;
            ListNode* temp=head;
            ListNode* newHead=NULL;

            while(temp!=NULL){
                st.push(temp->val);
                temp=temp->next;

            }

            while(!st.empty()){
                int tempVal=st.top();
                addNode(newHead,tempVal);
                st.pop();

            }

            return newHead;


        }
};

int main(){
    ListNode* head=new ListNode(1);
    Solution1 p;
    p.addNode(head,2);
    p.addNode(head,3);
    p.addNode(head,4);
    Solution s;
    ListNode* c=s.reverseList(head);
    while(c!=NULL){
        cout<<c->val<<endl;
        c=c->next;

    }
return 0;
}



