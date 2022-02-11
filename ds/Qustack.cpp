#include<iostream>
#include<stack>
using namespace std;

class queue{
	int val;
	stack<int>st;
	stack<int>st1;
	public:

	queue(){
		val=0;
	}

	void push(int x){
		st.push(x);
	}

	void pop(){
		if(st.empty() and st1.empty()){
			cout<<"stack is empty"<<endl;
			return;
		}
		if(st1.empty()){
			while(not(st.empty())){
				st1.push(st.top());
				st.pop();

			}
		}
		cout<<st1.top()<<endl;
		st1.pop();


	}








};


int main(){
	queue qu;
	qu.push(1);
	qu.push(2);
	qu.push(3);
	qu.pop();
	qu.push(4);
	qu.pop();
	qu.pop();
	qu.pop();
	qu.push(5);
	qu.push(6);
	qu.pop();



	return 0;

}
