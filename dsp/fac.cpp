#include<iostream>
using namespace std;


int fac(int n){
	if(n==0){
		return 1;

	}

	return n*fac(n-1);


}



int main(){

	cout<<fac(4)<<endl;


	return 0;
}
