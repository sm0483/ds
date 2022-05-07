#include<iostream>
#include<vector>
using namespace std;


void getSubsetSum(vector<int>input,int sum,int idx){
    if(idx==input.size()){
        cout<<sum<<endl;
        return;
    }
    sum+=input[idx];
    getSubsetSum(input,sum,idx+1);
    sum-=input[idx];
    getSubsetSum(input,sum,idx+1);
    

}


int main(){
    vector<int> arr={1,2};
    getSubsetSum(arr,0,0);


}
