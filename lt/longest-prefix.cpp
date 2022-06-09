#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string answer="";
        string a=strs[0];
        string b=strs[strs.size()-1];
        for(int i=0;i< b.size(); i++){
            if(a[i]==b[i]) answer+=b[i];
            else return answer;
        }

        return answer;

    }
};
