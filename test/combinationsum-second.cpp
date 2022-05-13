#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Test{
    public:
        void combinationSum(int input[],vector<int>ds,int idx,int target){
            if(idx==5){
                if(target==0){
                    for(auto i:ds){
                        cout<<i<<"-";
                    }
                    cout<<endl;
                }
                return;
            }

            if(target>=input[idx]){
                ds.push_back(input[idx]);
                combinationSum(input,ds,idx+1,target-input[idx]);
                ds.pop_back();
            }
            combinationSum(input,ds,idx+1,target);

        }

        bool checkPresence(int pos,vector<int>input){
            for(int i=0;i<pos;i++){
                if(input[i]==input[pos]) return false;
            }
            return true;

        }

        void combinationSum(vector<int>input,vector<int>ds,int idx,int target){
            if(idx==input.size()){
                if(target==0){
                    for(auto i:ds){
                        cout<<i<<"-";
                    }
                    cout<<endl;
                }
                return;
            }

            for(int i=idx;i<input.size();i++){
                if(target>=input[i] && checkPresence(i,input)){
                    ds.push_back(input[i]);
                    combinationSum(input,ds,i+1,target-input[i]);
                    ds.pop_back();
                }
            }


        }
};

class MoreTest{
    public:
        bool checkPresence(int start,int pos,vector<int>input){
            for(int i=start;i<pos;i++){
                if(input[i]==input[pos]) return false;
            }
            return true;
        }

        void combinationSum(vector<int>input,vector<int>ds,int idx,int target){
            if(idx==input.size()-1){
            if(target==0){
                for(auto i:ds){
                    cout<<i<<"-";

                }
                cout<<endl;

            }
            return;
            }

            for(int i=idx;i<input.size();i++){
                if(checkPresence(idx,i,input)){
                    if(input[i]>target) break;
                    ds.push_back(input[i]);
                    combinationSum(input,ds,i+1,target-input[i]);
                    ds.pop_back();
                }
            }
        }

};


int main(){
    //[10,1,2,7,6,1,5], target = 8
    Test t;
    vector<int>input={10,1,2,7,6,1,5};
    sort(input.begin(),input.end());
    /*for(auto i:input){
        cout<<i<<" ";

    }
    //cout<<endl;
    vector<int>ds={};
    //t.combinationSum(input,ds,0,8);
    */
    MoreTest mt;
    //vector<int>arr={1,1,2};
    vector<int>ds={};
    mt.combinationSum(input,ds,0,8);

}
