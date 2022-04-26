#include<iostream>
#include<vector>
#include<unistd.h>
using namespace std;




class Solution {
    public:
        void combinationSum(vector<int>&candidates,vector<vector<int>>&ans,vector<int>ds,int idx,int target){
            int size=candidates.size();
            if(idx>=size){
                if(target==0){
                    ans.push_back(ds);
                }
                return;
            }

            if(candidates[idx]<=target){
                ds.push_back(candidates[idx]);
                combinationSum(candidates,ans,ds,idx,target-candidates[idx]);
                ds.pop_back();
            }
            combinationSum(candidates,ans,ds,idx+1,target);

        }
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            vector<vector<int>>ans;
            vector<int>ds;
            combinationSum(candidates,ans,ds,0,target);
            return ans;

        }
};


int main(){

    vector<int>v={2,3,6,7};
    Solution *obj=new Solution();
    vector<vector<int>>ans=obj->combinationSum(v,7);
    for(auto i:ans){
        for(auto k:i){
            cout<<k<<"-";

        }
        cout<<endl;
    }
    return 0;
}
