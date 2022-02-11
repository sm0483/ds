#include<iostream>
#include<string>
using namespace std;


class Solution{
	string subst;
	public:

	Solution(){
		subst="";
	}

	string largestOddNumber(string num){

		for(int i=num.length()-1;i>=0;i--){
			if((num[i]-'0')%2==1){
				return num.substr(0,i+1); 

			}

		}

		return subst;




	}


};

int main(){
	Solution s;
	cout<<s.largestOddNumber("7542351161");

	return 0;
}
