#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool checkPresence(vector<int>input,int start,int point){
        for(int i=start;i<point;i++){
            if(input[i]==input[point]) return true;

        }
        return false;

    }
    void getCombination(vector<int>input,vector<vector<int>>&output,vector<int>ds,int idx,int target){
        if(target==0){
            output.push_back(ds);
        }

        for(int i=idx;i<input.size();i++){
            if(!checkPresence(input,idx,i)){
                if(input[i]>target)break;
                ds.push_back(input[i]);
                getCombination(input,output,ds,i+1,target-input[i]);
                ds.pop_back();
            }

        }



    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>output;
        vector<int>ds={};
        sort(candidates.begin(),candidates.end());
        getCombination(candidates,output,ds,0,target);
        return output; 
    }
};

int main(){
    Solution s;
    int target=8;
    vector<int>input={10,1,2,7,6,1,5};
    vector<vector<int>>output=s.combinationSum2(input,target);
    for(auto i :output){
        for(auto j : i){
            cout<<j<<"-";

        }
        cout<<endl;
    }
    return 0;

}
