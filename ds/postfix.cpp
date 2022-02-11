#include<iostream>
#include<stack>
#include<math.h>
using namespace std;

int postfix(string s){

	stack<int> st;
	int op2;
	int op1;

	for(int i=0;i<s.length();i++){
		if(s[i]>='0' && s[i]<'9'){
			st.push(s[i]-'0');
		}
		else{
			op2=st.top();
			st.pop();
			op1=st.top();
			st.pop();


			switch(s[i]){
				case '+':
					st.push(op2+op1);
					break;
				case '-':
					st.push(op2-op1);
					break;
				case '*':
					st.push(op2*op1);
					break;
				case '/':
					st.push(op2/op1);
					break;
				case '^':
					st.push(pow(op2,op1));
					break;

			}


		}

	}
	return st.top();


}


int main(){
	string s="43+";
	cout<<postfix(s)<<endl;;
	return 0;

}
