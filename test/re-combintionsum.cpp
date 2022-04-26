#include<iostream>
#include<vector>
using namespace std;


class Test{
    public:
        void getCombination(vector<int>inputArr,vector<int>ds,int idx,int target){
            int size=inputArr.size();
            if(idx>=size){
                if(target==0){
                    for(auto i: ds){
                        cout<<i<<" ";
                    }
                    cout<<endl;
                }
                return;
            }


            if(target>=inputArr[idx]){
                ds.push_back(inputArr[idx]);
                getCombination(inputArr,ds,idx,target-inputArr[idx]);
                ds.pop_back();
            }
            getCombination(inputArr,ds,idx+1,target);
        }

        void getCombination(vector<int>inputArr,int target){
            vector<int>ds;
            getCombination(inputArr,ds,0,target);
        }
};
int main(){
    vector<int> arr={1,2,3};
    vector<int>ds={};
    Test *obj=new Test();
    //obj->getCombination(arr,ds,0,5);
    obj->getCombination(arr,5);

    return 0;
}
