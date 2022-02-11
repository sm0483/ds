#include <iostream>
#include<math.h>
using namespace std;

int main(){

	int arr[4];
	int t;
	cin>>t;

	while(t--){
	
	for(int i=0;i<4;i++){
	
	cin>>arr[i];
	
	
	}

	if(pow(arr[0],2)/pow(arr[2],3)==pow(arr[1],2)/pow(arr[3],3))
		cout<<"YES"<<endl;

	else
		cout<<"NO"<<endl;
	
	}

	return 0;
}
