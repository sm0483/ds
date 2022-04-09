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

/*
   class Solution{
   public:
   unordered_map<int,Node*>uMap;
   Node* copyRandomList(Node* head){
   Node* fTemp=head;
   Node* newHead=new Node(0);
   Node* sTemp=newHead;

   while(fTemp!=NULL){
   Node* fNode=NULL;
   Node* sNode=NULL;

//check value in map for next
if(uMap.count(fTemp->val)==0){
fNode=new Node(fTemp->val);
uMap[fTemp->val]=fNode;
}
else{
fNode=uMap[fTemp->val];
//check for random
}
if(fTemp->random!=NULL){
if(uMap.count(fTemp->random->val)==0){
sNode=new Node(fTemp->random->val);
uMap[fTemp->random->val]=sNode;
}
else{
sNode=uMap[fTemp->random->val];
}
}


fNode->random=sNode;
sTemp->next=fNode;
sTemp=sTemp->next;
fTemp=fTemp->next;



}
return newHead->next;

}



};

*/

class Solution{
    public:
        unordered_map<Node*,Node*>uMap;
        Node* copyRandomList(Node* head){
            Node* fTemp=head;

            while(fTemp!=NULL){
                Node* newNode=new Node(fTemp->val);
                uMap[fTemp]=newNode;
                fTemp=fTemp->next;

            }
            fTemp=head;

            while(fTemp!=NULL){
                Node* currentNode=uMap[fTemp];
                currentNode->next=uMap[fTemp->next];
                if(fTemp->random!=NULL){
                    currentNode->random=uMap[fTemp->random];
                }
                else{
                    currentNode->random=NULL;

                }
                fTemp=fTemp->next;


            }
            return uMap[head];

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
        cout<<head->val<<"->";
        head=head->next;

    }
    cout<<"end"<<endl;

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
    print(head);


    Solution *obj=new Solution();
    Node *newHead=obj->copyRandomList(head);
    print(newHead);





}
