#include <iostream>
using namespace std;
int main(){

	int t,i;
	cin>>t;
	while (t--){

		int n;
		cin>>n;
		int arr[n];
		int flag=0,flag1=0;
		for (i=0;i<n;i++){
			cin>>arr[i];
		}




		if (arr[0]!=1 || n%2!=1 || arr[1]-arr[0]!=1 || arr[n-1]!=1 ){

			cout<<"no"<<endl;
			flag=1;

		}

		else if (flag==0){

			for (i=0; i<n;i++){

				if (arr[i]!=arr[n-1-i]){cout<<"no"<<endl;flag1=1;break;}

				if (i<(n-1)/2){
					if (arr[i+1]-arr[i]!=1){cout<<"no"<<endl; flag1=1; break;}


				}

				else if (i>=(n-1)/2 && i!=n-1 ){
					if (arr[i+1]-arr[i]!=-1){cout<<"no"<<endl; flag1=1;break;}
				}


			}

			if (flag1==0){cout<<"yes"<<endl;}

		}

	}

	return 0;
}


