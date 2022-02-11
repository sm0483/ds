#include<iostream>
using namespace std;
#define n 100


class stack{
	string* arr;
	int top;

	public:

	stack(){

		arr=new string[n];
		top=-1;


	}

	void push(string val){
		if(top==n-1){cout<<"stack overflow "<<endl;return;}
		top++;
		arr[top]=val;

	}

	void pop(){

		if(top==-1){cout<<"stack underflow"<<endl;return;}
		top--;



	}

	string Top(){

		if(top==-1){return "No";}

		return arr[top];




	}

	bool empty(){

		return top==-1;

	}




};

int main(){

	string s="hello how are you";



	stack st;
	string word=" ";
	cout<<s.length()<<endl;

	for(int i=0;i<=s.length();i++){
		if(s[i]==' ' || i==s.length()){
			st.push(word);
			word=" ";
		}

		else {
			word+=s[i];
		}

	}



	for(int i=0;i<4;i++){
		cout<<st.Top()<<endl;
		st.pop();

	}


	return 0;
}



