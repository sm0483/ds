#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int t,i,p,count;
	char alp[26] ={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	cin>>t;

	while (t--){

		count=0;

		string s;
		cin>>s;

		sort(s.begin(),s.end());
		for(i=0;i<26;i++){
			for (p=0;p<s.length();p++){
				if (alp[i]==s[p]){

					count+=(i+1)*(p+1);


				}

			}

		}

		cout<<count<<endl;


	}




	return 0;
}
