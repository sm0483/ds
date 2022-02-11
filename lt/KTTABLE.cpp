#include <iostream>
using namespace std;
int main(){
	int t,p=0,i;
	cin>>t;
	while (t--){
		int e,num=0;
		cin>>e;
		int arrf[e];
		int arrl[e];
		for (i=0;i<e;i++){
			cin>>arrf[i];
		}
		for (i=0;i<e;i++){
			cin>>arrl[i];
		}
		for (i=0;i<e;i++){
			if (i==0){
				p=arrf[i];
			}
			else if (i>0){
				p=arrf[i]-arrf[i-1];
			}
			if (p>=arrl[i]){
				num++;
			}
		}
		cout<<num<<endl;

	}
	return 0;
}
