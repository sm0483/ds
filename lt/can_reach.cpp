#include <iostream>
using namespace std;
int main(){

int arr[3],n;


for (int i=0;i<3;i++)
   {
           cin>>n;
           arr[i]=n;
   }

if(arr[0]%arr[2]==0 && arr[1]%arr[2]==0){
	cout<<"yes"<<endl;
}
else{
cout<<"no"<<endl;}







return 0;































}
