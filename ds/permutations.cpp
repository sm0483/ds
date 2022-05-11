#include<iostream>
#include<vector>
using namespace std;


class Solution {
    public:
        bool checkPresence(vector<int>ds,int value){
            for(int i=0;i<ds.size();i++){
                if(ds[i]==value) return true;
            }

            return false;

        }
        void getPermute(vector<vector<int>>&output,vector<int>input,vector<int>ds,int idx){
            if(ds.size()==input.size()){
                output.push_back(ds);
                return;
            }
            for(int i=0;i<input.size();i++){
                if(!checkPresence(ds,input[i])){
                    ds.push_back(input[i]);
                    getPermute(output,input,ds,i+1);
                    ds.pop_back();
                }

            }

        }
        vector<vector<int>> permute(vector<int>& nums){
            vector<vector<int>>output;
            getPermute(output,nums,{},0);
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
