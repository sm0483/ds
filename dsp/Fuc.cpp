#include<iostream>
#include<algorithm>
using namespace std;

class Solution{
	public:
		int key=0;
		int j=0;
		int i=0;

		int firstUniqChar(string s){
			for(i=0;i<s.length()-1;i++){
				int count=i+1;
				for(j=i+1;j<s.length();j++){
					if(s[i]!=s[j]){
						count++;
					}

				}
				if(count==j){return i;
				}

			}
			return -1;





		}

};
int main(){
	Solution s;
	cout<<s.firstUniqChar("abc")<<endl;

	return 0;


}
