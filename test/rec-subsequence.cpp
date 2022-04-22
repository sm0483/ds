#include<iostream>
#include<vector>
using namespace std;




class Test{
    public:
        void printSubsequence(int arr[],int idx,vector<int>ds){
            if(idx>2) {
                for(auto i:ds){
                    cout<<i<<"-";
                }
                cout<<endl;
                return;
            }

            printSubsequence(arr,idx+1,ds);
            ds.push_back(arr[idx]);
            printSubsequence(arr,idx+1,ds);
        }

        void printSubsequence(vector<int> arr,int idx,vector<int>ds){
            for(idx>=arr.size()){
                for(auto i:ds){
                    cout<<i<<"-";
                    return;
                }
                ds.push_back(arr[idx]);
                printSubsequence(arr,idx+1,ds);
                ds.pop_back();
                printSubsequence(arr,idx+1,ds);


            }
        }

};


int main(){

    Test *obj=new Test();
    int arr[]={1,2,3};
    vector<int>v={};
    obj->printSubsequence(arr,0,v);
    obj->printSubsequence();




}
