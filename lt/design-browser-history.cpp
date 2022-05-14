#include<iostream>
using namespace std;


class BrowserHistory {
    private:
        class Node{
            public:
                string page;
                Node* next;
                Node* pre;

                Node(){
                    page="null";
                    next=NULL;
                    pre=NULL;
                }
                Node(string _page){
                    page=_page;
                    next=NULL;
                    pre=NULL;
                }
        };
    public:
        Node* head=NULL;
        Node* curr=NULL;
        BrowserHistory(string _homepage) {
            head=new Node(_homepage);
            curr=head;

        }

        void visit(string url) {
            Node* newPage=new Node(url);
            curr->next=newPage;
            newPage->pre=curr;
            curr=newPage;


        }
        string back(int steps) {
            int count =0;
            while(curr->pre!=NULL && count!=steps){
                curr=curr->pre;
                count++;
            }

            return curr->page;
        
        }

        string forward(int steps) {
            int count=0;
            while(curr->next!=NULL && count!=steps){
                curr=curr->next;
                count++;
            }

            return curr->page;
        }

        //for testing

        void printNext(){
            Node* temp=head;

            while(temp!=NULL){
                cout<<temp->page<<"-";
                temp=temp->next;
            }
            cout<<endl;
        }
        void printPre(){
            Node* temp=curr;

            while(temp!=NULL){
                cout<<temp->page<<"-";
                temp=temp->pre;
            }
            cout<<endl;
        }


};

int main(){
  BrowserHistory* obj = new BrowserHistory("h1");
obj->visit("h2");
  obj->visit("h3");
  obj->visit("h4");
  string test=obj->back(1);
  obj->visit("hk");
  cout<<test<<endl;



  obj->printNext();
  obj->printPre();

}
