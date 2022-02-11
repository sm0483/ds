#include<iostream>
#include<stack>
using namespace std;


int main(){
	stack<char>st;
	string s;
	s="((a+b)*(a*b))";

	for(int i=0;i<s.length();i++){
		if(s[i]=='(' or s[i]=='+' or s[i]=='-' or s[i]=='/' or s[i]=='*'){
			st.push(s[i]);
		}
		else if(s[i]==')'){
			if(st.top()=='('){
				cout<<"yep there is free ()"<<endl;
				break;
			}
			else{
				while(st.top()!='('){
					st.pop();
				}
				st.pop();
			}

		}
	}

	if(st.empty()){
		cout<<"NO "<<endl;
	}



	return 0;

}
