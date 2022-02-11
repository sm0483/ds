#include<iostream>
using namespace std;


int main(){
	int n,a;
	int t;
	cin>>t;
	while(t--){
		cin>>n>>a;
		int x=n-a;
		if(x>a){
			cout<<a<<endl;

		}
		else{
			cout<<x<<endl;

		}

	}


	return 0;
}
