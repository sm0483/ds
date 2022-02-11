#include<iostream>
using namespace std;


//int last(int arr[],int key,int point,int n)


int check(int arr[],int key,int point,int n){

	if(point==n){
		return -1;

	}

	if(arr[point]==key){
		return point;

	}
	else{
		check(arr,key,point+1,n-1);


	}


}




int main(){
	int box[]={1,2,3,2,5,6,7,2,7};
	int temp=check(box,2,1,9);
	cout<<check(box,2,1,9)<<endl;

	cout<<check(box,2,temp+1,9)<<endl;

	return 0;
}
