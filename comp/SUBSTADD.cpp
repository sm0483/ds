#include<iostream>
using namespace std;
bool check(int arr[],int curr,int n){
	for(int i=0;i<n;i++){
		if(arr[i]==curr){
			return true;
		}
	}
	return false;

}

int main(){
	int t,arr[1000],n,x,y,ls[1000];
	cin>>t;
	while(t--){
		cin>>n>>x>>y;
		int count=0;
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		for(int k=0;k<n;k++){
			cin>>ls[k];

		}
		for(int j=0;j<n;j++){
			int val=arr[j]+x;
			int p=arr[j]+y;
			if(check(ls,val,n) || check(ls,p,n)){
				count++;

			}
		}
		if(count==n){
			cout<<"yes"<<endl;

		}
		else{
			cout<<"no"<<endl;
		}

	}

	return 0;
}
