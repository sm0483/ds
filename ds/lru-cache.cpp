#include<iostream>
#include<unordered_map>
using namespace std;

class LRUCache {
    public:
        class Node{
            public:
                int key;
                int val;
                Node* next;
                Node* pre;

                Node(){
                    val=0;
                    key=0;
                    next=NULL;
                    pre=NULL;
                }

                Node(int _key,int _val){
                    key=_key;
                    val=_val;
                    next=NULL;
                    pre=NULL;
                }

        };
        int capacity=0;
        unordered_map<int,Node*>m;  
        Node* head=NULL;
        Node* tail=NULL;
        LRUCache(int capacity) {
            this->capacity=capacity;
            this->head=new Node();
            this->tail=new Node();
            head->next=tail;
            tail->pre=head;
        }


        void toDelNode(Node* delNode){
            Node* tailSide=delNode->next;
            Node* headSide=delNode->pre;
            headSide->next=tailSide;
            tailSide->pre=headSide;
            delete(delNode);
        }

        void addNode(Node* newNode){
            Node* tailSide=head->next;
            head->next=newNode;
            newNode->pre=head;
                newNode->next=tailSide;
                tailSide->pre=newNode;
        }

        int get(int key) {
            if(m.count(key)!=0){
                Node* toReturn=m[key];
                int toReturnVal=toReturn->val;
                toDelNode(toReturn);
                Node * newNode=new Node(key,toReturnVal);
                addNode(newNode);
                return toReturnVal;
            }
            return -1;
        }

        void put(int key, int value) {
            if(m.count(key)!=0){
                Node* xisNode=m[key];
                toDelNode(xisNode);
                m.erase(key);
            }
            int size=m.size();
            if(size>=capacity){
                Node* delNode=tail->pre;
                m.erase(delNode->key);
                toDelNode(delNode);

            }
            //insert new one
            Node* newNode=new Node(key,value);
            m[key]=newNode;
            addNode(newNode);
        }

        void print(){
            if(head==NULL) return;
            Node* temp=head;

            while(temp!=NULL){
                cout<<temp->key<<":"<<temp->val<<"->";
                temp=temp->next;
            }
            cout<<"end"<<endl;

        }
};

int main(){
    LRUCache *obj=new LRUCache(2);
    obj->put(2,1);
    obj->put(1,1);
    cout<<obj->get(2)<<endl;
    obj->put(4,1);
    cout<<obj->get(1)<<endl;
    cout<<obj->get(2)<<endl;
    obj->print();
    cout<<obj->get(3)<<endl;
    obj->print();
    return 0;



}
