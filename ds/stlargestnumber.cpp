#include<bits/stdc++.h>
using namespace std;

class Solution {
   public:
	  stack<int>st;
	  vector<int> nextGreaterElements(vector<int>& nums) {
		 vector<int>ans(nums.size());
		 int n=nums.size();
		 int k=0;
		 for(int i=2*n-1;i>=0;i--){

			if(i>=n){
			   k=i%n;
			}
			else{
			   k=i;
			
			}

			while(!st.empty() && st.top()<=nums[k])
			   st.pop();

			if(st.empty()){
			   st.push(nums[k]);
			   ans[k]=-1;

			}
			else{
			   ans[k]=st.top();
			   st.push(nums[k]);

			}
		 }
		 reverse(ans.begin(),ans.end());
		 return ans;

	  }
};

int main(){
   Solution obj;
   vector<int>nums={1,2,1};
   vector<int>ans=obj.nextGreaterElements(nums);
   for(auto i: ans){
	  cout<<i<<endl;
   
   }


}


