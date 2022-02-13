#include<iostream>
using namespace std;



void sumof(int arr[],int idx,int n,int current_sum,int final_sum){
   if(idx==n){
	  if(current_sum==final_sum){
		 cout<<current_sum<<endl;
	  }
	  return;

   }
   current_sum+=arr[idx];
   sumof(arr,idx+1,n,current_sum,final_sum);
   current_sum-=arr[idx];
   sumof(arr,idx+1,n,current_sum,final_sum);

}










int main(){
   int arr[]={1,1,3};
   sumof(arr,0,3,0,4);


   return 0;
}
