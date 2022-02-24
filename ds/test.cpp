#include <iostream>
#include<queue>
#include<vector>
using namespace std;



int main(){
	queue<int>q;
	vector<int>v;

	q.push(1);
	q.push(2);
	q.push(3);
	q.pop();
	v[0]=2;
	cout<<v[0]<<endl;

//	cout<<"front"<<q.front()<<endl;
//	cout<<q.back()<<endl;


	return 0;
}


