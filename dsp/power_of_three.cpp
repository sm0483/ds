#include<iostream>
using namespace std;

bool power(float n){
	if(n/3.0==1 || n==1){
		return true;
	}
	else if(n/3.0<1){
		return false;

	}



	return power(n/3.0);

}


int main(){
	cout<<power(27)<<endl;
	cout<<power(9)<<endl;
	cout<<power(5)<<endl;
	cout<<power(16)<<endl;




	return 0;
}
