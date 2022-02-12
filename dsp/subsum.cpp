#include<iostream>
#include<vector>
using namespace std;
int sumation(vector<int> arr){
   int s=0;

   for(int i=0;i<arr.size();i++){
	  s+=arr[i];
   }
   return s;

}

void fun(vector<int>arr,vector<int>ans,int sum){
   int val=arr[0];

   if(arr.size()==0){
	  if(sumation(ans)==sum){
		 for(auto i: ans){
			cout<<i<<" ";

		 }
		 cout<<endl;
		 cout<<sum<<endl;
	  }
	  return;
   }
   vector<int>newarr(arr.begin()+1,arr.end());
   //fun(newarr,ans.push_back(val),sum);
   fun(newarr,ans,sum);
   fun(newarr,ans.push_back(val),sum);



}





int main(){
   fun({1,2,1},{},2);



   return 0;
}
