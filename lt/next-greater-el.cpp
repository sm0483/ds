#include<iostream>
#include<vector>
using namespace std;

//brute force
class Solution {
    public:
        vector<int> nextGreaterElements(vector<int>& nums) {
            bool flag=false;
            vector<int>answer;
            for(int i=0;i<nums.size();i++){
                flag=false;
                for(int j=i+1;j<nums.size();j++){
                    if(nums[j]>nums[i]){
                        answer.push_back(nums[j]);
                        flag=true;
                        break;
                    }
                }
                if(!flag){
                    for(int j=0;j<nums.size();j++){
                        if(nums[j]>nums[i]){
                            answer.push_back(nums[j]);
                            break;
                        }

                        if(j==nums.size()-1)answer.push_back(-1);

                    }
                }
            }
            return answer;
        }
};

int main(){
    Solution *s=new Solution();
    vector<int>q={1,2,1}
    vector<int>answer=s->nextGreaterElements();
    for(auto i: answer){
        cout<<i<<endl;
    }

}
