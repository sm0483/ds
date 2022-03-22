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

Node* inhead(Node* head,int key,int val){
    Node* temp=head;
    Node* n=new Node(key,val);
    n->right=temp->right;
    temp->right=n;
    n->left=temp;
    temp->right->left=n;
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

//to delete from any side of dll
int delpos(Node* head,int pos){
    int rekey=0;
    Node* temp=head;
    int count=0;
    while(temp->right!=NULL && count!=pos){
        count++;
        temp=temp->right;

    }
    //cout<<temp->key<<endl;
    Node* todelete=temp;
    cout<<"right and left"<<endl;
    cout<<temp->right->key<<endl;
    cout<<temp->left->key<<endl;
    /*
    temp->right->left=temp->left;
    temp->left->right=temp->right;
    rekey=temp->key;
    delete(todelete);
    */
    return rekey;



}
//to print
void print(Node* head){
    while(head!=NULL){
        cout<<head->key<<"right: value: "<<head->value<<endl;
        cout<<head->left->key<<endl;
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
                //tr working properly
                int pos=tr(head,key,value);
                int p=delpos(head,pos);
                /*
                Node* node=inode(head,key,value,1);
                return value;
            */
                return 0;

            }

        }

        void print(){
            Node* temp=head;
            while(temp!=NULL){
                //errocheck
                cout<<"right:"<<temp->key<<endl;
                temp=temp->right;


            }

        }

};

/*
int main(){
    solution s;
    s.push(1,1,3);
    s.push(2,2,3);
    s.push(3,3,3);
    s.print();
//    s.push(4,4,3);
  //  s.push(5,5,3);
    //cout<<endl;
    //s.print();
    cout<<s.get(1)<<endl;

    //    int get=s.get(2);
    //  cout<<get<<endl;
    return 0;
}

*/

   int main(){
   Node* head=new Node(0,0);
   inhead(head,1,1);
   inhead(head,2,2);
   inhead(head,3,3);
   inhead(head,4,4);
   print(head);
   delpos(head,3);
   cout<<endl;
   print(head);



   }
   
