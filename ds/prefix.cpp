#include<iostream>
#include<math.h>
#include <stack>
using namespace std;

int prefix(string s){

	stack<int>st;


	for(int i=s.length()-1;i>=0;i--){

		if(s[i]>='0' && s[i]<='9'){

			st.push(s[i]-'0');

		}
		else{
			int op2=st.top();
			st.pop();
			int op1=st.top();
			st.pop();

			switch(s[i]){
				case '+':
					st.push(op2+op1);
					break;

			}








		}




	}

	return st.top();




}
int main(){

	string s="+43";
	cout<<prefix(s)<<endl;
	return 0;




}



