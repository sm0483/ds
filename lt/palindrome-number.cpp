#include<iostream>
using namespace std;


class Solution {
public:
    bool isPalindrome(int x) {
        string value=to_string(x);

        for(int i=0;i<value.size()/2;i++){
            if(value[i]!=value[value.size()-1-i]){
                return false;
            }
        }

        return true;
    }
};
