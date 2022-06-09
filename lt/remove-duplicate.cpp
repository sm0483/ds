#include<iostream>
#include<vector>
using namespace std;



class Solution {
public:
     int reSolution(vector<int>nums,int point){
        if(nums.size()==point) return 0;
        int answer=reSolution(nums,point+1);
        if(nums[point]!=nums[point+1]) return answer+1;
        else return answer;

    }
    int removeDuplicates(vector<int>& nums) {
        return reSolution(nums,1);
        
    }
};

//Input: nums = [0,0,1,1,1,2,2,3,3,4]
int main(){
    Solution * s=new Solution();
    //vector<int>answer={0,0,1,1,1,2,2,3,3,4};
    vector<int>answer={1,1,2};
    int value=s->removeDuplicates(answer);
    cout<<value<<endl;
    return 0;
}
