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

        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            vector<int>v;
            ListNode* firstHead=list1;
            ListNode* secondHead=list2;
            ListNode* newHead=NULL;

            while(firstHead!=NULL){
                v.push_back(firstHead->val);
                firstHead=firstHead->next;
            }

            while(secondHead!=NULL){
                v.push_back(secondHead->val);
                secondHead=secondHead->next;


            }

            sort(v.begin(),v.end());
            for(int i=0;i<v.size();i++){
                addNode(newHead,v[i]);

            }


            return newHead;




        }
};


int main(){
    ListNode* head=NULL;
    ListNode* head2=NULL;
    /*
    addNode(head,1);
    addNode(head,2);
    addNode(head,3);
    addNode(head,4);

    addNode(head2,3);
    addNode(head2,4);
    addNode(head2,6);
*/
    //    addNode(head,5);
    Solution s;
    ListNode* newHead=s.mergeTwoLists(head,head2);
    print(newHead);


    return 0;
}


