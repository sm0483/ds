#include<iostream>
using namespace std;

void asci(string s,string ans){
	if(s.length()==0){
		cout<<ans<<endl;
		return ;

	}
	char ch=s[0];
	int val=ch-'a';

	asci(s.substr(1),ans);
	asci(s.substr(1),ans+ch);
	asci(s.substr(1),ans+to_string(val));



}




int main(){
	/*
	int p='a'-'a';
	int k='b'-'a';
	cout<<p<<endl;
	cout<<k<<endl;
	*/
	asci("abc","");

	return 0;
}
