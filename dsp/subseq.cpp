#include<iostream>
using namespace std;


void fun(string s,string ans){
   if(s.length()==0){
	  cout<<ans<<endl;
	  return;
   }

   string sub=s.substr(1);
   fun(sub,ans+s[0]);
   fun(sub,ans);


}



int main(){
   fun("abc"," ");


   return 0;
}
