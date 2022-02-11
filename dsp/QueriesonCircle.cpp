#include<iostream>
#include<vector>
#include<math.h>
using namespace std;


class Solution {
	public:
		vector<vector<int>>arrv;
		vector<vector<int>>arrq;
		Solution(vector<vector<int>>& points, vector<vector<int>>& queries) {
			arrv=points;
			arrq=queries;
		}
		bool equation(int point,int circle){
			return pow(arrq[circle][0]-arrv[point][0],2)+pow(arrq[circle][1]-arrv[point][1],2)<=pow(arrq[circle][2],2);

		}

		vector<int> output(){
			vector<int>v;
			for(int i=0;i<arrq.size();i++){
				int count=0;
				for(int j=0;j<arrv.size();j++){
					if(equation(j,i)){
						count++;
					}

			}
				v.push_back(count);
			}
			return v;

		}
};

int main(){
	vector<vector<int>>arrv;
	vector<vector<int>>arrq;
	arrv.push_back({1,3});
	arrv.push_back({3,3});
	arrv.push_back({5,3});
	arrv.push_back({2,2});

	arrq.push_back({2,3,1});
	arrq.push_back({4,3,1});
	arrq.push_back({1,1,2});

	Solution s(arrv,arrq);
	vector<int>ans;
	ans=s.output();
	for(int i=0;i<3;i++){
		cout<<ans[i]<<endl;
	}





	return 0;
}
