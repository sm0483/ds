#include<iostream>
using namespace std;

class Solution {
	public:
		ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
			ListNode* temp=list1;
			int count=0;
			while(temp->next!=NULL){
				if(count==a-1){point1=temp;point1->next=list2;}
				if(count==b){point2=temp;}
				temp=temp->next;
			}
			temp->next=point2;

			poin1->next=list2;

			ListNode* temp2=list2;
			while(temp2->next!=NULL){
				temp2=temp2->next;
			}
			temp2->next=point2;
			return list2;

		}
};
