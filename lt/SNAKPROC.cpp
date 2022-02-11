#include <iostream>
#include <algorithm>
using namespace std;
int main(){

	int i,t;
	cin>>t;
	while (t--){
		int i=0,flag=0;
		int size;
		cin>>size;

		string s;
		cin>>s;
		s.erase(remove(s.begin(),s.end(),'.'),s.end());


		for (i=0;i<s.length();i++){

			if (i%2==0){

				if (s[i]!='H'){
					flag=1;
					break;
				}
			}
			else if (i%2==1){
				if( s[i]!='T'){
					flag=1;
					break;
				}
			}
		}


		if(flag || s[0]=='T' || s[i-1]=='H'){cout<<"Invalid"<<endl;}
		else {cout<<"Valid"<<endl;}




	}

	return 0;
}


