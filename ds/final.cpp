#include<iostream>
#include<unordered_map>
using namespace std;

class Node{
    public :
        int key;
        int value;
        Node* right;
        Node* left;
        Node(int ikey,int ivalue){
            key=ikey;
            value=ivalue;

        }

};

class doublelist{
    int size;
    public:
    Node* head=new Node(0,0);
    unordered_map<int,Node*>hmap;
    doublelist(int isize){
        size=isize;
    }
    //insert
    Node* Insert(int key,int value){
        Node* temp=head;
        Node* n=new Node(key,value);
        n->right=temp->right;
        n->left=temp;
        if(temp->right!=NULL){
            temp->right->left=n;

        }
        temp->right=n;
        return n;

    }
    //insert tested ok

    Node * Insert(int key,int value,int pos){
        if(pos==1){
            Node* n=Insert(key,value);
            return n;

        }
        Node* temp=head;
        Node* n=new Node(key,value);
        int count =1;
        while(temp->right!=NULL && count!=pos){
            temp=temp->right;
            count++;

        }

        n->left=temp;
        n->right=temp->right;
        temp->right=n;
        return n;

    }
    int del(){
        int delkey=0;
        Node* temp=head;
        while(temp->right->right!=NULL){
            temp=temp->right;

        }
        Node* todelete=temp->right;
        delkey=temp->right->key;
        delete(todelete);
        temp->right=NULL;
        return delkey;

    }

    int del(int pos){
        int hsize=hmap.size();
        //work when size of linkedlist 1 and del only that element or size of map
        //for error checking: cout<<"hsize: "<<hsize<<endl;
        if(pos==hsize || (hsize==1 && pos==1)){
            return del();

        }
        Node* temp=head;
        int count=0;
        while(temp->right!=NULL && count!=pos){
            count++;
            temp=temp->right;
        }
        Node* todelete=temp;
        temp->left->right=temp->right;
        temp->right->left=temp->left;
        delete(todelete);
        return -1;


    }
    int tr(int key,int &value){
        Node* temp=head;
        int count=0;
        while(temp->right!=NULL && temp->key!=key){
            count++;
            temp=temp->right;
        }
        value=temp->value;
        return count;


    }

    void print(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<"key: "<<temp->key<<":value:"<<temp->value<<endl;
            temp=temp->right;

        }

    }


};

class LRUCache : public doublelist{
    public:
        int size=0;
        LRUCache(int isize):doublelist(isize){
            size =isize;
        }

        void put(int key,int value){
            if(hmap.count(key)){
                int kvalue=0;
                int pos=tr(key,kvalue);
                //for error handaling: cout<<"%"<<pos<<endl;
                del(pos);
                hmap.erase(key);

            }
            int mapsize=hmap.size();
            Node* node=NULL;
            if(mapsize!=size){
                node=Insert(key,value,1);
                hmap[key]=node;

            }
            else{
                int delkey=del(mapsize);
                hmap.erase(delkey);
                node=Insert(key,value,1);
                hmap[key]=node;

            }

        }

        int get(int key){
            if(!hmap.count(key)){
                return -1;

            }
            int value=0;
            int pos=tr(key,value);
            if(pos!=1){
                del(pos);
                Insert(key,value,1);

            }
            return value;

        }



};


int main(){

    LRUCache s(3);
    cout<<s.get(1)<<endl;
    s.put(1,10);
    s.put(2,20);
    s.put(3,30);
    s.put(4,40);
    s.print();
    cout<<endl;
    s.get(2);
 cout<<s.get(2)<<endl;
 cout<<s.get(1)<<endl;
 s.print();
    return 0;
}
/*
   int main(){
   doublelist s(2);
   s.Insert(1,1,1);
   s.print();
//s.del(1);
cout<<endl;
s.Insert(2,2,1);
//s.print();

cout<<endl;
s.Insert(3,2,1);
s.print();
cout<<endl;
//s.Insert(3,3,3);
//s.del(3);
s.print();
cout<<endl;
return 0;
}
*/
