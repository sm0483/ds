#include <iostream>
using namespace std;
int main(){
int n,k,in;
int flag=0;
cin>>n>>k;

for (int i=0;i<n;i++){
cin>>in;
if (in%k==0){
flag+=1;}
}

cout<<flag<<endl;

return 0;
}
