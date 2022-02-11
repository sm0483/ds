#include<iostream>
#include<stack>
using namespace std;

int main(){
	int s;
	cin>>s;
	while(s--){
		string num;
		string out="";
		cin>>num;
		for (int i=num.length()-1;i>=0;i--){
			out+=num[i];
		}
		cout<<stoi(out)<<endl;


	}

	return 0;
}
