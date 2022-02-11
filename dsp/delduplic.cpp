#include<iostream>
using namespace std;

string deldup(string s){
	if(s.length()==0){return "";}
	char ch=s[0];
	string ans=deldup(s.substr(1));
	if(ch==ans[0]){return ans;}
	return ch+ans;

}


void del(string s){
	if(s.length()==0){return;}

	char ch=s[0];
	bool key=true;
	for(int i=1;i<s.length();i++){
		if(ch==s[i]){
			key=false;
			break;
		}
	}
	if(key){cout<<ch;}

	del(s.substr(1));



}

int main(){
	string s="aababdbccd";
	//cout<<deldup(s)<<endl;
	del(s);

}
