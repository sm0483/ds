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
        ListNode* mergeTwoLists(ListNode *l1,ListNode *l2){
            if(l1->val >l2->val)swap(l1,l2);
            ListNode* res=l1;

            while(l1!=NULL && l2!=NULL){
                ListNode* temp=NULL;
                while(l1!=NULL && l1->val <=l2->val){
                    temp=l1;
                    l1=l1->next;

                }
                temp->next=l2;
                swap(l1,l2);

            }

            

            return res;




        } 
};


int main(){
	ListNode* head=NULL;
	ListNode* head2=NULL;

	addNode(head,1);
	addNode(head,2);
	addNode(head,3);
	addNode(head,6);


	addNode(head2,1);
	addNode(head2,3);
	addNode(head2,4);
	addNode(head2,6);
	//    addNode(head,5);
	Solution s;
	ListNode* newHead=s.mergeTwoLists(head,head2);
	print(newHead);


	return 0;
}


