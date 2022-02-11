#include <iostream>
using namespace std;

void print(int n);
void asc(int n);
int main(){


	int n;
	cin>>n;
	print(n);
	asc(n);
	return 1;


}

void asc(int n){

	if(n==0){
	return ;
	}
	cout<<n<<endl;
	asc(n-1);

}

void print(int n){

	if (n==0){
		cout<<"*"<<endl;
		return;
	
	}
	print(n-1);
	cout<<n<<endl;
	





}
