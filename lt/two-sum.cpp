#include<iostream>
#include<vector>
#include <unordered_map>
using namespace std;


class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            vector<int>answer;
            unordered_map<int,int>map;
            for(int i=0;i<nums.size();i++){
                int numberToFind=target-nums[i];
                map[numberToFind]=i;
            }

            for(int i=0;i<nums.size();i++){
                if(map.count(nums[i])){
                    if(map[nums[i]]!=i){
                        return {i,map[nums[i]]};
                    }
                }
            }
            return {-1,-1};
        }
};


int main(){

    return 0;
}
