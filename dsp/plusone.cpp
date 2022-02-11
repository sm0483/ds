#include<iostream>
#include<vector>
using namespace std;


class Solution {
	public:
		vector<int> plusOne(vector<int>& digits) {
			int size=digits.size();
			//cout<<size<<endl;
			vector<int>ans;
			for(int i=0;i<size;i++){
				if(i!=size-1){
					ans.push_back(digits[i]);
				}
				else {
					int temp=digits[i]+1;
					if(temp<9){
						ans.push_back(temp);

					}
					else{
						int val=temp/10;
						int val2=temp%10;
						ans.push_back(val);
						ans.push_back(val2);

					}

				}

			}
			return ans;

		}
};

int main(){
	Solution s;
	vector<int>p={9,9};
	vector<int> ans=s.plusOne(p);
	for(auto i: ans){
		cout<<i<<endl;


	}

	return 0;
}


