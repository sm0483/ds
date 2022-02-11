#include <iostream>
using namespace std;
//selection sort//
int main(){

       int arr[20];
       int len;

       cin>>len;
       for(int i=0;i<len;i++){
       
       cin>>arr[i];
       } 


       for (int k=0;k<len;k++){
       
       for (int j=k+1;j<len-1;j++){
       
       if (arr[k]>arr[j]){
       int temp=arr[k];
       arr[k]=arr[j];
       arr[j]=temp;

       }
       
       
       }
       
       
       
       }


for (int i=0;i<len;i++){
cout<<arr[i]<<"";
}
       return 0;
 
 
 
 
 
 
 
 
 
 
       }
