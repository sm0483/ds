#include<iostream>
#include<unordered_map>
using namespace std;

class Node{
    public:

        int val;
        Node* next;
        Node* random;

        Node(int _val){
            val=_val;
            next=NULL;
            random=NULL;

        }


};


class Solution{
    public:
        Node* copyRandomList(Node* head){
            if(head==NULL) return head;
            Node *newHead=NULL;
            Node* currentHead=head;

            while(currentHead!=NULL){
                Node* rest=currentHead->next;
                Node* newNode=new Node(currentHead->val);
                currentHead->next=newNode;
                newNode->next=rest;
                currentHead=rest;
            }

            currentHead=head;
            newHead=currentHead->next;

            while(currentHead!=NULL){
                Node * temp=currentHead;
                if(temp->random!=NULL)temp->next->random=temp->random->next;
                currentHead=currentHead->next->next;
            }

            currentHead=head;

            while(currentHead!=NULL){
                //assing two variables
                Node* ptr1=currentHead;
                Node* ptr2=currentHead->next->next;

                //detaching newcopy
                if(ptr2!=NULL)ptr1->next->next=ptr2->next;
                //ptr1->next->random=ptr1->random->next; //this line should be done in different loop
                ptr1->next=ptr2;

                //traversal
                currentHead=currentHead->next;
            }

            return newHead;

        }


};


Node* addNode(Node* &head ,int val){
    Node* n=new Node(val);
    if(head==NULL){
        head=n;
        return head;
    }

    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;

    }
    temp->next=n;
    return n;
}

void addRandom(Node* host , Node* attach){
    host->random=attach;
}

void print(Node* head){
    while(head!=NULL){
        cout<<head->val<<"--";
        if(head->random!=NULL){
            cout<<head->random->val;
        }
        else{
            cout<<"NULL";

        }
        cout<<"->";
        head=head->next;

    }
    cout<<"end"<<endl;

}

//for indiviual chain test

void printHeadChain(Node* node){
    while(node!=NULL){
        cout<<node->val<<"-";
        node=node->next;

    }
    cout<<endl;


}

int main(){
    Node* head=NULL;
    Node* one=addNode(head,7);
    Node* two=addNode(head,13);
    Node* three=addNode(head,11);
    Node* four=addNode(head,10);
    Node* five=addNode(head,1);
    //random connection
    addRandom(two,one);
    addRandom(one,NULL);
    addRandom(three,five);
    addRandom(four,three);
    addRandom(five,one);

    printHeadChain(head);
    print(head);

    cout<<"______________________________________________"<<endl;


    Solution *obj=new Solution();
    Node *newHead=obj->copyRandomList(head);
    printHeadChain(newHead);
    printHeadChain(head);
    print(newHead);




}
