#include<iostream>
#define n 5
using namespace std;


class deque{
	int *arr;
	int front;
	int back;
	public:

	deque(){
		arr=new int[5];
		front=-1;
		back=n;
		int size();
	}


	void push_front(int x){
		if(size()==n){
			cout<<"dque is full"<<endl;
			return ;
		}
		front++;
		arr[front]=x;

	}
	void push_back(int x){
		if(size()==n){
			cout<<"dque is full"<<endl;
			return;
		}
		back--;
		arr[back]=x;

	}
	void dback(){
		cout<<arr[back]<<endl;

	}
	void dfront(){
		cout<<arr[front]<<endl;

	}

	void pop_front(){
		front--;

	}
	void pop_back(){
		back++;

	}

	int size(){
		return back-front+1;

	}






};


int main(){
	deque dq;
	dq.push_front(1);
	dq.push_front(2);
	dq.push_front(3);
	dq.push_front(4);
	dq.dfront();
	dq.pop_front();
//	dq.dback();
	dq.dfront();
return 0;

}

