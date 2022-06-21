#include<iostream>
using namespace std;


class Solution {
    public:

        string addElement(string a,string b,string &carry){
            string element="";
            if(a=="1" && b=="1") {
                carry="1";
                element="0";
            }
            else if((a=="1" && b=="0") || (a=="0" && b=="1"))element="1";
            else if(a=="0" && b=="0") element="0";

            return element;
        }


        string addBinary(string a, string b) {
            int lenA=a.size();
            int lenB=b.size();
            int tempA=lenA-1;
            int tempB=lenB-1;
            string carry="";
            string temp="";
            string answer="";


            while(tempA>=0 && tempB>=0){
                string stTempA="";
                stTempA+=a[tempA];
                string stTempB="";
                stTempB+=b[tempB];

                if(carry!=""){
                    temp=addElement(stTempA,stTempB,carry);
                }
                else{
                    temp=addElement(stTempA,stTempB,carry);
                }
                answer+=temp;
                tempA--;
                tempB--;
            }
            if(carry!="")answer+="1";
            return answer;

        }
};


int main(){
    Solution* s=new Solution();
    string a="1101";
    string b="1111";
    string answer=s->addBinary(a,b);
    cout<<answer<<endl;
    return 0;


}
