#include<iostream>
#include<deque>
//#include<functional>
//#include<cctype>
using namespace std;


int main(){
	deque<char>dq;
	string s="Aba";
	cout<<s<<endl;

	for(int i=0;i<s.length();i++){
		if(isalnum(s[i])){
			dq.push_front(tolower(s[i]));
		}
	}


	while(!dq.empty()){
		char right=dq.back();
		char left=dq.front();
		cout<<right<<endl;
		cout<<left<<endl;
		dq.pop_front();
		if(!dq.empty()){
			dq.pop_back();}

		if(right!=left){
			cout<<"not a pal"<<endl;
			return 0;
		}

	}


	cout<<"yep palindrome"<<endl;
	return 0;


}

