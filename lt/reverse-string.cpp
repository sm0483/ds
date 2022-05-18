#include<iostream>
#include<vector>
using namespace std;


class Solution {
    public:

        void recSolution(vector<char> &s,int start,int end){
            if(start>=end) return;
            swap(s[start],s[end]);
            recSolution(s,start+1,end-1);

        }

        void reverseString(vector<char>& s){
            recSolution(s,0,s.size()-1);


        }
};
