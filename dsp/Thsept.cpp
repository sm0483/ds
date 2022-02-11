#include<iostream>
#include<string>
using namespace std;


int main(){
	string s="1789";
	int point=0;

	for(int i=s.length()-1;i>0;i--){
		point++;
		if(point%3==0 && s.length()>3){
			cout<<point<<endl;
			cout<<i<<endl;
			s.insert(i,".");

		}

	}
	cout<<s<<endl;


}
