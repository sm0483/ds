#include <iostream>
using namespace std;
int main(){
	char arr[30];
	int i,n;
	cin>>n;
	int flag=0;

	cin>>arr;

	for (i=0;i<n;i++){
		flag++;


		if (arr[i]!=arr[n-1-i]){
			cout<<"not palindrome"<<endl;
			break;




		}
		else if (arr[i]==arr[n-i-1]){

			continue;

		}

	}

if (flag==n){
cout<<"yes"<<endl;


}
return 0;

	}
