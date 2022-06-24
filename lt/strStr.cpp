#include<iostream>
using namespace std;


class Solution {
public:
    int strStr(string haystack, string needle) {
        int sizeHays=haystack.size();
        int sizeNeed=needle.size();

        for(int i=0;i<sizeHays-sizeNeed;i++){
            for(int j=0;j<sizeNeed;j++){
                if(haystack[i+j]!=needle[j]){
                    break;
                }
                if(sizeNeed==j)return i;
            }

        }
        return -1;
        
    }
};
