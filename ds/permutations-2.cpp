#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
    public:
        void getPermute(vector<vector<int>>&output,vector<int>&input,int idx){
            if(idx>=input.size()){
                output.push_back(input);
                return;
            }
            for(int i=idx ; i<input.size();i++){
                swap(input[idx],input[i]);
                getPermute(output,input,idx+1);
                swap(input[idx],input[i]);

            }

        }
        vector<vector<int>> permute(vector<int>& nums){
            vector<vector<int>>output;
            getPermute(output,nums,0);
            return output;
        }
};

int main(){
    Solution *s=new Solution();
    vector<vector<int>>output;
    vector<int>input={1,2,3};
    output=s->permute(input);
    for(auto i:output){
        for(auto j: i){
            cout <<j<<"-";
        }
        cout <<endl;
    }

    return 0;
}
