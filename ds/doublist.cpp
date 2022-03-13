#include <iostream>
#include<unordered_map>
using namespace std;

class Node{
    public:
        int key;
        int value;
        Node* right;
        Node* left;
        Node(int lkey,int lvalue){
            key=lkey;
            value=lvalue;
            right=NULL;
            left=NULL;

        }

};

class doublelist{
    public:
        Node* head;
        doublelist(Node *&lhead){
            head=lhead;
        }

        Node* Insert(int key,int value){
            Node *temp=head;
            Node* n=new Node(key,value);
            n->right=temp->right;
            n->left=temp;
            if(temp->right!=NULL){
                temp->right->left=n;
            }
            temp->right=n;
            return n;

        }


        Node* Insert(int key,int value,int pos){
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
            int delkey;
            Node* temp=head;
            // cout<<"del**"<<endl;
            while(temp->right->right!=NULL){
                temp=temp->right;
                //   cout<<"testin for last :"<<temp->key<<endl;

            }
            //cout<<"del*"<<endl;
            Node* todelete =temp->right;
            delkey=temp->right->key;
            delete(todelete);
            temp->right=NULL;
            return delkey;


        }



        void print(){
            Node* temp=head;
            while(temp!=NULL){
                cout<<temp->key<<endl;
                temp=temp->right;
            }

        }


};

class Solution : public doublelist{

    unordered_map<int,Node*>map;
    public:

    Solution(Node* lhead):doublelist(lhead){

    }

    void push(int key,int val,int size){

        if(map.size()!=size){
            Node *node=Insert(key,val);
            map[key]=node;
            //              cout<<"map size: "<<map.size()<<endl;


        }
        else if(map.size()==size){
            //cout<<"**"<<endl;
            int delkey=del();
            //cout<<"*"<<endl;
            map.erase(delkey);
            Node *node=Insert(key,val);
            map[key]=node;

        }

    }


};
int main(){
    Node *head=new Node(0,0);
    Solution s(head);
    s.push(1,1,3);
    s.push(2,2,3);
    s.push(3,3,3);
    s.print();
    s.push(4,4,3);
    s.push(5,5,3);
    s.print();


}

/*
   int main(){
   Node* head=new Node(0,0);
   doublelist dl(head);
   dl.Insert(1,1);
   dl.Insert(2,2);
   dl.Insert(3,3);
   dl.Insert(4,4,2);
   dl.print();


   }

*/

