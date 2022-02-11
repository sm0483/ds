#include<iostream>
using namespace std;

int fib(int n){

	if(n==0 || n==1){
		return n;

	}

	cout<<fib(n-1)+fib(n-2)<<endl;
	return fib(n-1)+fib(n-2);


}

int main(){
	fib(3);
	cout<<"________"<<endl;
//	cout<<fib(3)<<endl;

	return 0;
}
