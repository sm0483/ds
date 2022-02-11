#include <iostream>
using namespace std;

bool check(char pre,char cur){
	if(((pre=='d' || pre=='f') && (cur== 'd' || cur=='f') )||  ((pre=='j' || pre=='k') && (cur=='j' || cur=='k'))){
		return true;

	}
	return false;

}



int fun(string s){
	int ans=0;
	for(int i=0;i<s.length();i++){
		if(i==0){
			ans+=2;

		}

		else if(check(s[i-1],s[i])){
			ans+=4;
		}
		else{
			ans+=2;

		}


	}

	return ans;
}


int main(){
	int p=0,t=0;
	string s="";
	cin>>t;
	while(t--){
		cin>>p;
		string arr[100];
		int count=0;
		int result=0;
		while(p--){
			bool flag=false;
			cin>>s;

			for(int i=0;i<count;i++){
				if(s==arr[i]){
					flag=true;

				}

			}
			arr[count]=s;
			count++;
			if(flag){
				result=result+(fun(s)/2);

			}
			else{
				result+=fun(s);
			}

		}

		cout<<result<<endl;

	}

	return 0;
}
