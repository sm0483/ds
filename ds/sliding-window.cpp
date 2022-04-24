#include<iostream>
#include<vector>
#include<limits.h>
#include<unistd.h>
using namespace std;


class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            static vector<int>v={};
            int static start=0;
            int static end=k;
            //test
            //            cout<<"start"<<start<<endl;
            //          cout<<"end"<<end<<endl;

            int size=nums.size();
            if(size==1 || k==1) return nums;
//            cout<<size<<endl;
            if(size<end){
                return {};
            }

            int current_max=INT_MIN;
            for(int i=start ;i<end ;i++){
                if(current_max<nums[i]) current_max=nums[i];
            }
            v.push_back(current_max);
            start=start+1;
            end=end+1;
            //         sleep(1);
            maxSlidingWindow(nums,k);
            return v;

        }
};




int main(){
    vector<int>nums={1,3,-1,-3,5,3,6,7};
    Solution *s=new Solution();
    vector<int>k=s->maxSlidingWindow(nums,3);
    for(auto i:k){
        cout<<i<<"-";

    }
    cout<<endl;

    return 0;
}
