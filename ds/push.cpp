#include<iostream>

void push(int x){
	q2.push(x);

	while(!q1.empty()){
		q2.push(q1.front());
		q2.pop();
	}


	queue<int>temp=q1;
	q1=q2;
	q2=temp;



}
