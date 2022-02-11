#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];

		}

		sort(arr,arr+n);
		float sum=0;
		for(int i=0;i<n-1;i++){
			sum+=arr[i];

		}
		float temp=sum/(n-1),temp2=arr[n-1];
		cout<<temp+temp2<<endl;
		




	}
	return 0;


}
