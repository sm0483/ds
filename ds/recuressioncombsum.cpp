#include<iostream>
#include<vector>
using namespace std;


void comb(int arr[],vector<int>&ds,int idx,int n,int target_sum){
   if(idx==n){
	  if(target_sum==0){
		 for(auto i: ds){
			cout<<i<<" ";

		 }
		 cout<<endl;
	  }
	  return;
   }


   if(target_sum>=arr[idx]){
	  ds.push_back(arr[idx]);
	  comb(arr,ds,idx,n,target_sum-arr[idx]);
	  ds.pop_back();


   }
   comb(arr,ds,idx+1,n,target_sum);

}

int main(){

   vector<int>ds={};
   int arr[]={1,2,1};
   comb(arr,ds,0,3,3);

   return 0;
}
