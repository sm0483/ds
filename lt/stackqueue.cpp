#include<iostream>
#include<stack>
using namespace std;

class queue{

	int front;
	int back;
	stack<int>st;
	

	public: 
	queue(){
		front=-1;
		back=-1;

	}

	void enqueue(int val){
		st.push(val);

	}

	void peek(){
		cout<<st.pop()<<endl;

	}








};

int main(){

	queue q;
	q.enqueue(2);
	q.peek();

	return 0;
}
