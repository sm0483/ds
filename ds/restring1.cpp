#include<iostream>
#include<stack>
using namespace std;
#define n 5

void Rstring(string s){

	stack<string> st;
	string word=" ";

	for(int i=0;i<=s.length();i++){

		if(s[i]==' ' || i==s.length()){
			st.push(word);
			word=" ";

		}

		else {

			word+=s[i];
		}



	}


	for(int i=0;i<s.length();i++){

		cout<<st.top()<<" "<<endl;
		if(i==s.length()-1){
			return;

		}

		st.pop();

	}








}



int main(){

	string s="Hellow how are you";
	Rstring(s);



	return 0;
}
