#include<iostream>
#include<vector>
using namespace std;

bool check(vector<int>&track,int val){
   for(int i=0;i<track.size();i++){
	  if(val==track[i]){
		 return false;
	  }

   }

   return true;
}


void sum(int arr[],vector<int>&ds,int size,int idx,int target_sum){

   if(target_sum==0){
	  for(auto i:ds)
		 cout<<i<<"";

   }
   cout<<endl;
   return;





   vector<int>track={};
   for(int i=idx;i<size;i++){
	  if(check(track,arr[i])){
		 ds.push_back(arr[i]);
		 target_sum-=arr[i];
		 sum(arr,ds,size,i,target_sum);
		 ds.pop_back();
		 target_sum+=arr[i];
	  }


   }




}


int main(){
   int arr[]={1,1,1,2,2};
   vector<int>ds={};
   sum(arr,ds,5,0,3);
   return 0;
}
