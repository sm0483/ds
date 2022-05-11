#include<iostream>
#include<vector>
using namespace std;


//check presence
class Solution {
    public:
        bool checkPresence(vector<int>input,int start,int pos){
            for(int i=start;i<pos;i++){
                if(input[i]==input[pos]) return true;

            }
            return false;
        }

        void subset(vector<vector<int>>&output,vector<int>ds,vector<int>input,int idx){
            output.push_back(ds);
            for(int i=idx;i<input.size();i++){
                if(!checkPresence(input,idx,i)){
                ds.push_back(input[i]);
                subset(output,ds,input,i+1);
                ds.pop_back();
                }
            }

        }
        vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            vector<vector<int>>output;
            subset(output,{},nums,0);
            return output;
        }
};


int main(){
    vector<int>input={1,2,2};
    vector<vector<int>>arr;
    Solution *s=new Solution();
    arr=s->subsetsWithDup(input);
    for(auto i:arr){
        for(auto j: i){
            cout<<j<<"-";
        }
        cout<<endl;
    }

    return 0;
}
