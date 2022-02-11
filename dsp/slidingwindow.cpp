#include<iostream>
using namespace std;


void max(int arr[],int n){

	int *p=&arr[n-2];
	if(p==arr){
		return;
	}
	int k=-1;
	for(int i=0;i<3;i++){
		if(k<arr[i]){
			k=arr[i];

		}
	}
	cout<<k<<endl;
	max(arr+1,n-1);


}

int main(){
	int arr[]={1,3,2,1,4,5};
	max(arr,6);
	return 0;



}
