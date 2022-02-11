#include <iostream>
#include <algorithm>
using namespace std;
int main(){

	int t,n,tar,out,i;

	cin>>t;

	while (t--){
		n=0;
		out=0;
		cin>>n>>tar;
		int arr[n];
		for (i=0;i<n;i++){

			cin>>arr[i];
		}
		sort(arr,arr+n);
		for (i=0;i<n;i++){
			if (arr[i]>=arr[n-tar]){
				++out;
			}
	

		}


		cout<<out<<endl;


	}

	return 0;

}
