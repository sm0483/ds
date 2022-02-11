#include<iostream>
using namespace std;



int dec(int n){
	if(n==0){
		return 0;

	}

	cout<<n<<endl;
	return dec(n-1);


}

void inc(int n){
	if(n==0){
		return;

	}

	inc(n-1);
	cout<<n<<endl;

}

int main(){
//	dec(5);
	inc(5);
	return 0;


}
