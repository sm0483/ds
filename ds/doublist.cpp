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
        //to insert at head
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

        //to inser at postion
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
        //delete at end

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

        //delete at postion

        void del(int pos){
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


        }


        //travesal

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
                cout<<temp->key<<endl;
                temp=temp->right;
            }

        }


};

class Solution : public doublelist{

    unordered_map<int,Node*>map;
    int size=0;
    public:

    Solution(Node* lhead,int len):doublelist(lhead){
        size=len;

    }

    void push(int key,int val){
        int sizeofmap=map.size();
        if(sizeofmap!=size){
            Node *node=Insert(key,val);
            map[key]=node;
            //              cout<<"map size: "<<map.size()<<endl;


        }
        else if(sizeofmap==size){
            //cout<<"**"<<endl;
            int delkey=del();
            //cout<<"*"<<endl;
            map.erase(delkey);
            Node *node=Insert(key,val);
            map[key]=node;

        }

    }

    int get(int key){
        if(!map.count(key)){
            return -1;


        }
        else {
            int value;
            int pos=tr(key,value);
  //          cout<<"error checking "<<endl;
            if(pos==size){
                del();
            }
            else{
            del(pos);
            }
//            cout<<"error checking"<<endl;
            Insert(key,value);
            return value;


        }

    }





};
int main(){
    Node *head=new Node(0,0);
    Solution s(head,3);
    s.push(1,1);
    s.push(2,2);
    s.push(3,3);
    //s.push(4,4);
    s.print();
    //cout<<"key 2: "<<s.get(2)<<endl;
    cout<<"**"<<endl;
    cout<<s.get(1)<<endl;
    cout<<"----------"<<endl;
    s.print();


}

/*

   int main(){
   Node* head=new Node(0,0);
   doublelist dl(head);
   dl.Insert(1,1);
   dl.Insert(2,2);
   dl.Insert(3,3);
   dl.print();
//dl.Insert(4,4,2);
//dl.del(2);
//    int value;
//  int pos=dl.tr(2,value);
dl.del(3);
//cout<<"2: "<<value<<endl;
//cout<<"________________"<<endl;
dl.print();


}

*/
