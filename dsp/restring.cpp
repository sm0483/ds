#include<iostream>
using namespace std;





void print(string s){

	if(s.length()==0){
		return;

	}




	cout<<s[s.length()-1];
	string sub=s.substr(0,s.length()-1);
	print(sub);


}











int main(){


print("binod");




	return 0;

}
