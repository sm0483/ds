#include <iostream>
#include <math.h>
using namespace std;

int main(){

	int n;
	int sum=0;
	int temp,lastdigit;

	cin>>n;
	int k=n;

	while (true){



		lastdigit=n%10;
		n=n/10;
		temp=pow(lastdigit,3);

		sum+=temp;


		if (n<9){
			temp=pow(n,3);

			sum+=temp;
			break;

		}
	






	}

	cout<<sum<<endl;

	if (sum==k){
		cout<<"yep"<<endl;}

	else {cout<<"NO"<<endl;}







	return 0;


}
