#include<iostream>
#include<queue>
using namespace std;

class stack{
	int n;
	queue<int>q1,q2;
	public:



	stack(){
		n=0;
	}


	void push(int x){
		q1.push(x);
		n++;
	}

	void pop(){
		int temp=0;
		while(temp!=n-1){
			temp++;
			q2.push(q1.front());
			q1.pop();
		}
		q1.pop();
		queue<int>q=q1;
		q1=q2;
		q2=q;

	}


	void top(){
		cout<<q1.back()<<endl;	

	}

};

int main(){
	stack st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);
	st.top();
	for(int k=0;k<3;k++){
		st.pop();
		st.top();
	}

	return 0;



}
