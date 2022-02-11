#include<iostream>
using namespace std;


string mv(string s){
	if(s.length()==0){return "";}


	char ch=s[0];
	string ans=mv(s.substr(1));
	if(ch=='x'){return ans+ch;}
	else{return ch+ans;}



}



int main(){
	string s="axxbax";
cout<<	mv(s);


	return 0;
}
