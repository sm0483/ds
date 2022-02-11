#include<iostream>
#include<string>
using namespace std;


class Solution{
	string sleft;
	string sright;
	int score;

	public:
	Solution(){
		sleft="";
		sright="";
		score=0;
	}

	int zerocheck(string s){
		int count=0;
		for(int i=0;i<s.length();i++){
			if(s[i]=='0'){
				count++;

			}

		}
		return count;

	}
	int onecheck(string s){
		int count=0;
		for(int i=0;i<s.length();i++){
			if(s[i]=='1'){
				count++;

			}

		}
		return count;
	}


	int maxScore(string s){
		for(int i=0;i<s.length()-1;i++){
			sleft=s.substr(0,i+1);
			sright=s.substr(i+1,s.length());
			int temp=zerocheck(sleft)+onecheck(sright);
			cout<<temp<<endl;


			if(temp>score){
				score=temp;
			}


		}

		return score;


	}

};

int main(){
	Solution s;
	cout<<s.maxScore("011101")<<endl;



	return 0;
}

