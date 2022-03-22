#include<iostream>
#include<unordered_map>
using namespace std;

class LRUCache {
    public:
        class Node{
            public:
                int key;
                int value;
                Node* left;
                Node* right;
                //constrctor for node class
                Node(int _key,int _value){
                    key=_key;
                    value=_value;
                }

        };
        int size=0;
        unordered_map<int,Node*>hmap;
        Node* head=new Node(-1,-1);
        Node* tail=new Node(-1,-1);
        //constructor for main class
        LRUCache(int _size){
            size=_size;
            head->right=tail;
            tail->left=head;
        }

        void doubleDel(Node* delNode){
            Node *preNode=delNode->left;
            Node *nextNode=delNode->right;
            preNode->right=nextNode;
            nextNode->left=preNode;
            //delete(delNode);

        }
        void addNode(Node* newNode){
            Node *temp=head->right;
            newNode->right=temp;
            newNode->left=head;
            head->right=newNode;
            temp->left=newNode;
        }

        int get(int key) {
            if(hmap.count(key)){
                Node* getNode=hmap[key];
                hmap.erase(key);
                int res=getNode->value;
                doubleDel(getNode);
                addNode(getNode);
                hmap[key]=head->right;
                return res;
            }
            return -1;

        }

        void put(int key, int value) {
            Node *newNode=NULL;
            if(hmap.count(key)){
                Node* getNode=hmap[key];
                doubleDel(getNode);
                hmap.erase(key);
            }
            int mapsize=hmap.size();
            //cout<<"sizeofmap: "<<mapsize<<endl;

            if(mapsize==size){
                int delkey=tail->left->key;
                doubleDel(tail->left);
                hmap.erase(delkey);
            }
            newNode=new Node(key,value);
            addNode(newNode);
            hmap[key]=head->right;

        }

        //for testing print
/*		
        void print(){
            Node* temp=head;
            while(temp!=NULL){
                cout<<temp->key<<endl;
                temp=temp->right;
            }

        }
*/	
};






int main(){
    LRUCache *s=new LRUCache(2);
    s->put(1,1);
    s->put(2,2);
    s->get(1);
    s->put(3,3);
    cout<<"get(2)"<<s->get(2)<<endl;
//    s->print();
    /*
    s->put(4,4);
   cout<<"value: "<<s->get(1)<<endl;
   cout<<"lastprint"<<endl;
    s->print();
*/
    return 0;
}

