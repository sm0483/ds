#include<iostream>
#include<stack>
using namespace std;

class Solution{
	stack<char>st;

	public:
	bool isValid(string s){
		for(int i=0;i<s.length();i++){

			if(s[i]==')' && st.top()=='('){
				st.pop();

			}
			else if(s[i]==']' && st.top()=='['){
				st.pop();

			}

			else if(s[i]=='}' && st.top()=='{'){
				st.pop();

			}
			else {
				st.push(s[i]);


			}

		}

		if(!st.empty()){return false;}
		return true;







	}



};



int main(){
	Solution s;
	cout<<s.isValid("{()}")<<endl;




	return 0;


}
