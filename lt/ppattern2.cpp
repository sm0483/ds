#include <iostream>

using namespace std;

int main(){
	int n;
	cin>>n;

	for (int i=1;i<=n;i++){
		for (int p=1;p<=2*(n-i+1);p++){
		
		cout<<" ";
		}




		for (int k=i;k>=1;k--){

			cout<<k;
			cout<<" ";
		}

		for (int j=1;j<i;j++){

			cout<<j+1;
			cout<<" ";


		}
		cout<<endl;




	}




	return 0;
}
