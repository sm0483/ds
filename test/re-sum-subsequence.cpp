#include<iostream>
#include<vector>
using namespace std;

class Test{
    public:
        void printSumSeq(vector<int> arr,vector<int>ds,int idx,int sum,int target){
            if(idx>=arr.size()){
                if(sum==target){
                    for(auto i: ds){
                        cout<<i<<"-";

                    }
                    cout<<endl;
                }
                return;
            }

            sum=sum+arr[idx];
            ds.push_back(arr[idx]);
            printSumSeq(arr,ds,idx+1,sum,target);
            ds.pop_back();
            sum=sum-arr[idx];
            printSumSeq(arr,ds,idx+1,sum,target);

        }

        void printSum(vector<int> arr,vector<int>ds,int idx,int sum,int target){
            if(sum==target){
                for(auto i:ds){
                    cout<<i<<"-";
                }
                cout<<endl;
            }
            return;


            printSum(arr,ds,idx+1,sum,target);
            ds.push_back(arr[idx]);
            sum+=arr[idx];
            printSum(arr,ds,idx+1,sum,target);
        }

        bool isExist(vector<int> arr,vector<int>ds ,int idx,int sum,int target){
            if(idx>=arr.size()){
            if(sum==target){
                for(auto i:ds){
                    cout<<i<<"-";
                }
                cout<<endl;
                return true;
            }
            return false;
            }

            if(isExist(arr,ds,idx+1,sum,target)){
                return true;
            }
            else
            {
                return false;
            }
            ds.push_back(arr[idx]);
            if(isExist(arr,ds,idx+1,sum+arr[idx],target))
            {
                return true;
            }
            else
            {
                return false;
            }

        }
};

int main(){
    vector<int> arr={1,2,3};
    vector<int>ds;
    Test *obj=new Test();
  //  obj->printSum(arr,ds,0,0,6);
//    obj->printSumSeq(arr,ds,0,0,6);
    cout<<obj->isExist(arr,ds,0,0,6);
    return 0;
}
