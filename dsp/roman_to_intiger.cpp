#include<iostream>
using namespace std;
class Solution{
	int res;
	public:

	Solution(){
		res=0;


	}



	int val(char e){
		if(e=='I'){return 1;}
		if(e=='V'){return 5;}
		if(e=='X'){return 10;}
		if(e=='L'){return 50;}
		if(e=='C'){return 100;}
		if(e=='D'){return 500;}
		if(e=='M'){return 1000;}
		return 0;

	}







	int romanToInt(string s){
		res=val(s[s.length()-1]);
		for(int i=s.length()-2;i>=0;i--){
			if(val(s[i])<val(s[1+i])){
				res=res-val(s[i]);
	
			}
			else{
				res=res+val(s[i]);

			}


		}
		return res;
	}
};

int main(){
	Solution s;
	cout<<s.romanToInt("MCMXCIV")<<endl;

	return 0;

}
