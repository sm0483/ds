#include <iostream>

using namespace std;

int main(){

	int n,lastdigit;
	cin>>n;

	bool flag=true;

	while(flag){

		lastdigit=n%10;
		n=n/10;


		cout<<lastdigit;

		if (n<9){
			cout<<n;	
			break;

		}






	}

	return 0;




}

