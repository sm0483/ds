#include<iostream>
#include<algorithm>
#include<vector>
#include<unistd.h>
using namespace std;

// Definition for a Node.
class Node {
    public:
        int val;
        Node* prev;
        Node* next;
        Node* child;
};


Node* addChildNode(Node* &node , int _val){
    Node *n=new Node();
    n->val=_val;
    n->child=NULL;
    n->next=NULL;

    if(node==NULL){
        node=n;
        return n;

    }

    Node* temp=node;

    while(temp->child!=NULL){
        temp=temp->child;

    }
    temp->child=n;

    return n;

}

Node * addNextNode(Node* &node ,int _val){
    Node* n=new Node();
    n->val=_val;
    n->next=NULL;
    n->child=NULL;

    if(node==NULL){
        node=n;
        return n;
    }

    Node * temp=node;

    while(temp->next!=NULL){
        temp=temp->next;
    }
    n->prev=temp;
    temp->next=n;

    return n;

}

void printChild(Node* node){
    while(node!=NULL){
        cout<<node->val<<"->";
        node=node->child;
        sleep(0.5);
    }
    cout<<"EndChild";

}

void printNext(Node* node){
    while(node!=NULL){
        cout<<node->val<<"->";
        node=node->next;

    }
    cout<<"EndNext";

}

void joinChild(Node* toJoin,Node* host){
    host->child=toJoin;

}

void joinNext(Node* toJoin,Node* host){
    host->next=toJoin;
}



class Solution {
    public:
        Node* merge(Node* a,Node* b){
            //new Head
            Node* head=new Node();
            head->val=0;
            head->next=NULL;
            head->child=NULL;

            Node* temp=head;
            if(b==NULL){
                return a;

            }
            while(a!=NULL && b!=NULL){
                if(a->val > b->val){
                    temp->child=b;
                    b=b->child;

                }
                else{
                    temp->child=a;
                    a=a->child;

                }
                temp=temp->child;
            }

            while(a!=NULL){
                temp->child=a;
                a=a->child;
                temp=temp->child;

            }

            while(b!=NULL){
                temp->child=b;
                b=b->child;
                temp=temp->child;

            }

            return head->child;


        }
        Node* flatten(Node* head){
            if(head==NULL || head->next==NULL) return head;

            if(head->next==NULL){
                return merge(head,head->next);

            }

            Node* k=flatten(head->next);
            return merge(head,k);


        }
};


int main(){
    Node* head=new Node();
    head->val=0;
    head=NULL;
    //first head
    addNextNode(head,1);
    addNextNode(head,2);
    Node *third=addNextNode(head,3);
    addNextNode(head,4);
    addNextNode(head,5);
    addNextNode(head,6);

    //next level

    Node *oneFirst=addChildNode(third,7);
    Node *oneSecond=addNextNode(oneFirst,8);
    addNextNode(oneFirst,9);
    addNextNode(oneFirst,10);
    //second level 

    Node* secondFirst=addChildNode(oneSecond,11);
    addNextNode(secondFirst,12);

    //joinChild

    //joinChild(oneFirst,third);
    //oinChild(secondFirst,oneSecond);

    //printNext(head);
    //printChild(third);
    //printNext(secondFirst);
    // printNext(oneFirst);
    //test


    /*
       Node *testHead1=new Node();
       testHead1=NULL;

       addChildNode(testHead1,1);
       addChildNode(testHead1,2);
       addChildNode(testHead1,3);


       Node* testHead2=new Node();
       testHead2=NULL;
       addChildNode(testHead2,2);
       addChildNode(testHead2,6);
*/
       Solution *s= new Solution();
       Node* testHead=s->flatten(head);
       printChild(testHead);


    return 0;
}
