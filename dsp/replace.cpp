#include<iostream>
using namespace std;

void replace(string s){
	string sub;

	if(s.length()==0){
		return;

	}

	if(s[0]=='p' && s[1]=='i'){
		cout<<3.14;
		sub=s.substr(2,s.length());
	}
	else{
		cout<<s[0];
		sub=s.substr(1,s.length());

	}

	replace(sub);





}


int main(){
	replace("aapibbpi");


	return 0;
}
