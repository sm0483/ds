#include <iostream>
#include <stack>
#include<algorithm>
using namespace std;


int pres(char s){


	if(s=='^'){

		return 4;

	}

	if(s=='/' || s=='*' ){

		return 3;
	}

	if(s=='+' || s=='-' ){
		return 2;
	}

	return -1;

}

string ipre(string s){

	stack<char> st;
	reverse(s.begin(),s.end());

	cout<<s<<endl;
	string word=" ";

	for(int i=0;i<s.length();i++){

		if(s[i]>='a' && s[i]<='z'){
			word+=s[i];
		}
		else if(s[i]==')'){
			st.push(s[i]);

		}

		else if(s[i]=='('){

			while(!st.empty() && st.top()!='('){
				word+=st.top();
				st.pop();

			}

			if(!st.empty()){
				st.pop();
			}

		}

		else{

			while(!st.empty() && pres(st.top())>pres(s[i])){
				word+=st.top();
				st.pop();

			}
			st.push(s[i]);

		}	

	}

	while(!st.empty()){
		word+=st.top();
		st.pop();

	}














	reverse(word.begin(),word.end());
	return word;
}



string  ip(string s){

	stack <char> st;
	string word=" ";

	for(int i=0;i<s.length();i++){

		if((s[i]>='a' && s[i]<='z')){
			word+=s[i];
		}

		else if(s[i]=='('){

			st.push(s[i]);

		}
		else if(s[i]==')'){
			while(!st.empty() && st.top()!='('){
				word+=st.top();
				st.pop();
			}



			if(!st.empty()){
				st.pop();
			}

		}

		else {
			while(!st.empty() && pres(s[i])<pres(st.top())){
				word+=st.top();
				st.pop();
			}
			st.push(s[i]);
		}

	}

	while(!st.empty()){
		word+=st.top();
		st.pop();


	}





	return word;
}


int main(){
	string s="((a+b)*(b+c))";
	cout<<ip(s)<<endl;
	cout<<ipre(s)<<endl;




	return 0;
}
