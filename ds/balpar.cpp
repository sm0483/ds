#include <iostream>
#include<stack>
using namespace std;


bool chec(string s){

	stack<char>st;

	for(int i=0;i<s.length();i++){
		if(s[i]=='(' || s[i]=='{' || s[i]=='[' ){
			st.push(s[i]);
		}


		else{
			if(s[i]==')'){
				if(st.top()!='('){
					return false;
				}
			}


			else if(s[i]=='}'){
				if(st.top()!='{'){
					return false;
				}
			}

			else if(s[i]==']'){
				if(st.top()!='['){
					return false;
				}
			}

			st.pop();


		}
		if(!st.empty()){
			return false;

		}



	}

	return true;
}






int main(){
	string s="{([])}";

	cout<<chec(s)<<endl;



	return 0;
}
