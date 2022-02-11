#include<iostream>
#include<vector>
using namespace std;



class Node{
	public:
		Node* next;
		int data;
		Node(int val){
			data=val;
			next=NULL;
		}
};

void inhead(Node* &head,int val){
	Node*n=new Node(val);
	if(head==NULL){
		head=n;
		return;
	}
	Node*temp=head;
	while(temp->next!=NULL){
		temp=temp->next;

	}
	temp->next=n;
}

void print(Node* head){
	while(head!=NULL){
		cout<<head->data<<endl;
		head=head->next;
	}

}

int solu(Node *head){
	vector<int>v;
	int ans=0;
	while(head!=NULL){
		v.push_back(head->data);
		head=head->next;
	}
	for(int i=0;i<v.size();i++){
		ans=max(v[i]+v[v.size()-i-1],ans);
	}
	return ans;


}



int main(){
	Node* head=NULL;
	inhead(head,1);
	inhead(head,2);
	inhead(head,0);
	inhead(head,4);
	cout<<solu(head)<<endl;
	//print(head);


	return 0;
}
