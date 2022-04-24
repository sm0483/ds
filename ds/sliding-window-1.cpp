#include<iostream>
#include<deque>
#include<vector>
#include<unistd.h>
using namespace std;

class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            deque<int>dq;
            vector<int>ds;

            dq.push_back(nums[0]);
            int numsSize=nums.size();
            for(int i=1;i<numsSize;i++){
                //      cout<<nums[i]<<endl;
                //        cout<<"before check back"<<dq.back()<<endl;

                if(i%k==0 || i>k) ds.push_back(dq.front());
                if(nums[i]>dq.back()){
                    while(nums[i]>dq.back() && !dq.empty()){
                        dq.pop_front();
                    }
                }
                //      sleep(1);

                dq.push_back(nums[i]);
                //                cout<<"start{"<<endl;
                //              for(auto i:dq){
                //                cout<<i<<"***";
                //          }
                //        cout<<"}end"<<endl;
                int dqSize=dq.size();

                //if(i%k==0 || i>k) ds.push_back(dq.front());
                if(dqSize>k) dq.pop_front();

            }

            while(!dq.empty()){
                ds.push_back(dq.front());
                dq.pop_front();

            }


            return ds;

        }


};

int main(){
    vector<int>nums={1};
    Solution *s=new Solution();
    vector<int>k=s->maxSlidingWindow(nums,1);
    for(auto i:k){
        cout<<i<<"*";

    }
    cout<<endl;



    return 0;
}
