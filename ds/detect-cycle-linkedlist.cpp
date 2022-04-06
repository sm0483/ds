#include<iostream>
#include<vector>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;

    ListNode(int _val){
        val=_val;
        next=NULL;

    }


};


void addNode(ListNode* &node,int val){
    ListNode* n=new ListNode(val);
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


void createCycle(ListNode* head,int pos){
    ListNode* temp=head;
    int count=1;
    ListNode* cycleNode;
    while(temp->next!=NULL){
        if(count==pos){
            cycleNode=temp;

        }

        temp=temp->next;
        count++;

    }
    temp->next=cycleNode;

}

void print(ListNode* node){
    ListNode* temp=node;
    while(temp!=NULL){
        cout<<temp->val<<"->";
        temp=temp->next;

    }



}



class Solution {
    public:
        bool hasCycle(ListNode *head) {
            vector<ListNode*>arr;
            int count=0;

            for(ListNode* temp=head;temp!=NULL; temp=temp->next){
                for(auto i: arr){
                    if(i==temp)return true;
                }
                
                arr.push_back(temp);

            }
            return false;

        }
};




int main(){
    ListNode *head=NULL;
    addNode(head,1);
    addNode(head,2);
    addNode(head,3);
    addNode(head,4);
           createCycle(head,2);
    Solution s;
    cout<<s.hasCycle(head)<<endl;

    //print(head);


    return 0;
}
