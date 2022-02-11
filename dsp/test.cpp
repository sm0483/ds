#include<iostream>
using namespace std;


void fun(int arr[],int n){

	int *p=&arr[n-1];
//	cout<<*p<<endl;
//	cout<<*arr<<endl;
	cout<<arr[n-1]<<endl;
	if(*arr==*p){
		return;
	}
	cout<<*arr<<endl;

	fun(arr+1,n-1);
}


int main(){
	int arr[]={1,2,3};
	//	cout<<arr<<endl;
	//	cout<<arr+1<<endl;
	fun(arr,3);

	return 0;
}
