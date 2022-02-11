#include <iostream>
using namespace std;
#define n 5

class stack{

	int top;
	int* arr;

	public:

	stack(){

		arr=new int[n];
		top=-1;
	}

	void push(int val){

		if(top==n-1){
			cout<<"stack overflow"<<endl;
			return;
		}


		top++;
		arr[top]=val;



	}

	void pop(){
		if(top==-1){
			cout<<"stack underflow"<<endl;
			return;

		}

		cout<<arr[top]<<endl;
		top--;

	}

	int Top(){

		if(top==-1){return -1}

	}

	void empty(){

		return top==-1



	}


};


int main(){

	stack a;
	a.push(5);
	a.push(4);
	a.push(3);
	a.push(2);
	a.push(1);
	for(int i=0;i<n;i++){
		a.pop();
	}








	return 0;

}
