#include <iostream>
using namespace std;
#define n 5


class queue{
	int front;
	int back;
	int *arr;

	public:
	queue(){
		arr=new int[n];
		front=-1;
		back=-1;
	}


	void enqueue(int val){

		if(back==n-1){
			cout<<"queue overflow"<<endl;
			return;
		}
		front=0;
		back++;
		arr[back]=val;


	}

	void dequeue(){
		if(back==front && back==-1){
			cout<<"queue underflow"<<endl;
			return;
		}

		front++;
	}

	void peek(){
		cout<<arr[front]<<endl;

	}
	bool empty(){
		if(back==front && back==-1){
			cout<<"queue underflow"<<endl;
			return true;
		}
		return false;

	}



};






int main(){

	queue q;
	q.enqueue(1);
	q.enqueue(2);
	q.peek();
	q.dequeue();
	q.peek();
	q.dequeue();
	q.peek();


	return 0;
}
