#include<iostream>
using namespace std;

int main(){
	int t,len;
	cin>>t;
	while(t--){
		cin>>len;
		int count=97;
		for(int i=0;i<len;i++){
			if(count>=122){
				count=97;

			}
			cout<<char(count++);

		}
		cout<<endl;



	}

return 0;

}
