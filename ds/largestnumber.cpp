#include<iostream>
#include<vector>
#include<stack>
#include<bits/stdc++.h>
using namespace std;
/*
   vector<int> prob(vector<int>v){
   stack<int>st;
   vector<int>ans;
   for(int i=v.size()-1;i>=0;i--){
   if(st.empty()){
   ans.push_back(-1);
   st.push(v[i]);
   }
   else if(v[i]<st.top()){
   ans.push_back(st.top());
   st.push(v[i]);

   }
   else{
   while(st.top()<v[i]){
   st.pop();
   }
   ans.push_back(st.top());
   st.push(v[i]);

   }

   }
   return ans;


   }

*/


class Solution{
   public:
	  vector<int> nextGreaterElements(vector<int>& nums) {
		 stack<int>st;
		 vector<int>ans;
		 for(int i=nums.size()-1;i>=0;i--){
			if(st.empty()){
			   st.push(nums[i]);
			   ans.push_back(-1);

			}
			else if(nums[i]<st.top()){
			   //arr[k]=st.top();
			   ans.push_back(st.top());
			   st.push(nums[i]);
			}
			else{
			   while(st.top()<nums[i] && st.empty()){
				  st.pop();

			   }
			   //arr[k]=st.top();
			   if(!st.empty()){
				  ans.push_back(st.top());
			   }
			   else{
				  ans.push_back(-1);
			   
			   }
			   st.push(nums[i]);

			}

		 }
		 reverse(ans.begin(),ans.end());
		 return ans;


	  }
};

int main(){
   vector<int>v={1,2,1};
   Solution s;
   vector<int>ans=s.nextGreaterElements(v);
   for(auto i:ans){
	  cout<<i<<endl;

   }

   return 0;
}
