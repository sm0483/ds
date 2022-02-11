#include<iostream>
#include <queue>
using namespace std;

class stack{
	queue<int>q1,q2;
	int N;
	public:

	stack(){
		N=0;
	}



	void push(int x){
		N=q1.size();
		q2.push(x);

		while(!q1.empty()){
			q2.push(q1.front());
			q1.pop();

		}
		queue<int>temp=q2;
		q2=q1;
		q1=temp;



	}

	void pop(){
		q1.pop();
	}

	void top(){
		cout<<q1.front()<<endl;

	}


};

int main(){
	stack st;

	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.pop();
	st.top();
	return 0;



}
