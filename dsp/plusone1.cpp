#include<iostream>
#include<string>
#include<vector>
#include<math.h>
using namespace std;

class Solution {
   public:
      vector<int> plusOne(vector<int>& digits) {
         vector<int>output;
         double val=0;
         int size=digits.size();
         for(int i=0;i<size;i++){
            val=val+digits[i]*pow(10,size-i-1);

         }
         val=val+1;
         string ans=to_string(val);
         for(int i=0;i<ans.size();i++){
            int k=ans[i]-'0';
            output.push_back(k);

         }
         return output;

      }
};

int main(){
   Solution s;
   vector<int>ans={1,2,3};
   vector<int>out=s.plusOne(ans);
   for(auto i:out){
      cout<<i<<endl;


   }





   return 0;
}
