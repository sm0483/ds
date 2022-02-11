#include<iostream>
using namespace std;

//program

int main(){
//	string s="0011001110110001111";
	string s="11001";
	int input=2;
	int ans=0;
	for(int i=0;i<s.length();i++){
		int k=0;
		int count=0;
		for(int j=i;j<s.length();j++){
			if(s[j]=='0'){
				k++;
			}
			if(k>input){
				break;
			}
			count++;

		}
//		cout<<count<<endl;
		ans=max(count,ans);
	}
	cout<<ans<<endl;
	return 0;
}
