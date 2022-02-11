#include<iostream>
using namespace std;



void subst(string s, string ans){
	if(s.length()==0){
		cout<<ans<<endl;
		return;
	}
	char ch=s[0];

	subst(s.substr(1),ans+ch);
	subst(s.substr(1),ans);


}




int main(){
	subst("abc","");

	return 0;
}
