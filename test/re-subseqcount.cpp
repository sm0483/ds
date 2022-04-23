#include<iostream>
#include<vector>
using namespace std;

class Count{
    public:
        int getCountSameSum(vector<int>values,int idx,int sum,int target){
            if(sum>target) return 0;

            if(idx>=values.size()){
                if(sum==target){
                    return 1;

                }
                return 0;
            }


            int sideCount=getCountSameSum(values,idx+1,sum,target);
            int oppositeSideCount=getCountSameSum(values,idx+1,sum+values[idx],target);
            return oppositeSideCount+sideCount;
        }
};


int main(){
    Count *obj=new Count();
    vector<int>values={1,2,1};
    int count=obj->getCountSameSum(values,0,0,3);
    cout<<count<<endl;


}
