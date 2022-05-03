#include<iostream>
using namespace std;


void parseDuplicate(string input,string &answer, int idx){
    if(idx==input.size()){
        return;
    }
    bool   flag=true;
    if(answer.size()==0) answer+=input[idx];
    else{
        for(int i=0;i<answer.size();i++){
            if(answer[i]==input[idx]){
                flag=false;
            }
        }
        if(flag) answer+=input[idx];

    }
    parseDuplicate(input,answer,idx+1);


}



int main(){
    string ans=" ";
    parseDuplicate("acaat",ans,0);
    cout<<ans<<endl;



}
