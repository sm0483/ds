#include<iostream>
#include<unordered_map>
using namespace std;

//class Node
class Node{
    public:
        int key;
        int value;
        Node *left;
        Node *right;

        Node(int ikey,int ivalue){
            key=ikey;
            value=ivalue;
            left=NULL;
            right=NULL;
        }

};
//insert at any pos
Node* inode(Node *head,int key,int val,int pos){
    Node *temp=head;
    int count=0;
    count++;
    while(temp->right!=NULL && count!=pos){
        temp=temp->right;
    }

    Node *n=new Node(key,val);
    n->left=temp;
    n->right=temp->right;
    temp->right=n;
    return n;

}
//travesal

int tr(Node* head,int key,int &value){
    Node* temp=head;
    int count=0;
    while(temp->right!=NULL && temp->key!=key){
        count++;
        temp=temp->right;
    }
    value=temp->value;
    return count;
}


//delete right most side
int del(Node* head){
    int delkey;
    Node* temp=head;
   // cout<<"del**"<<endl;
    while(temp->right!=NULL){
        temp=temp->right;
     //   cout<<"testin for last :"<<temp->key<<endl;

    }
    //cout<<"del*"<<endl;
    Node* todelete=temp;
    temp->left->right=NULL;
    delkey=temp->key;
    delete(todelete);
    return delkey;

}
//to delete from any side of dll
int delpos(Node* head,int pos){
    int key=0;
    Node* temp=head;
    int count=0;
    while(temp->right!=NULL && count!=pos){
        count++;
        temp=temp->right;

    }
    temp->left->right=temp->right;
    temp->right->left=temp->left;
    delete(temp);
    return key;



}
//to print
void print(Node* head){
    while(head!=NULL){
        cout<<head->key<<" "<<head->value<<endl;
        head=head->right;

    }

}
//main

class solution{
    public:
        unordered_map<int,Node*>map;
        Node* head=new Node(0,0);
        void push(int key,int val,int size){
            if(map.size()!=size){
                Node *node=inode(head,key,val,1);
                map[key]=node;
                //              cout<<"map size: "<<map.size()<<endl;


            }
            else if(map.size()==size){
                //cout<<"**"<<endl;
                int delkey=del(head);
                //cout<<"*"<<endl;
                map.erase(delkey);
                Node *node=inode(head,key,val,1);
                map[key]=node;

            }

        }

        int get(int key){
            if(!map.count(key)){
                return -1;


            }
            else {
                int value;
                int pos=tr(head,key,value);
                int p=delpos(head,pos);
                Node* node=inode(head,key,value,0);
                return value;

            }

        }

        void print(){
            Node* temp=head;
            while(temp!=NULL){
                cout<<temp->key<<" : "<<temp->value<<endl;
                temp=temp->right;


            }

        }

};
/*
int main(){
    solution s;
    s.push(1,1,3);
    s.push(2,3,3);
    s.push(3,4,3);
    s.print();
    s.push(4,5,3);
    cout<<endl;
    s.print();

       int get=s.get(2);
       cout<<get<<endl;
    return 0;
}
*/


int main(){
    Node* head=new Node(0,0);
    inode(head,1,2,1);
    inode(head,2,3,1);
    inode(head,3,5,1);
    inode(head,5,6,1);
    print(head);
    del(head);
    cout<<endl;
    print(head);



}

