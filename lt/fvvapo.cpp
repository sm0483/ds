#include <iostream>
using namespace std;
int main(){
	string arr[]={"--X","X++","X++"};
	int sum=0;


	for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
	
	if (arr[i]=="++X" || arr[i]=="X++"){
	sum+=1;

	}
	else{
	sum-=1;}
	
	
	}
	cout<<sum<<endl;


	return 0;







}
