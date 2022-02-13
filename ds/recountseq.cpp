#include<iostream>
using namespace std;

//function
int sum(int arr[],int idx,int current_sum,int target_sum,int n){
   if(idx==n){
	  if(current_sum==target_sum){return 1;}
	  return 0;
   }

   current_sum+=arr[idx];
   int left=sum(arr,idx+1,current_sum,target_sum,n);
   current_sum-=arr[idx];
   int right=sum(arr,idx+1,current_sum,target_sum,n);
   return right+left;



}


int main(){
   int arr[]={1,2,1};
   cout<<sum(arr,0,0,3,3)<<endl;


   return 0;
}
