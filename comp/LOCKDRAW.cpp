#include<iostream>
using namespace std;


int main(){
	int t;
	int a,b,c;
	cin>>t;
	while(t--){
		int max=0;
		cin>>a>>b>>c;
		if(a>=b && a>=c){
			max=a;
			if(max==b+c){
				cout<<"yes"<<endl;
			}
			else{
				cout<<"no"<<endl;
			}

		}
		else if(b>=c && b>=a){
			max=b;
			if(max==a+c){
				cout<<"yes"<<endl;
			}
			else{cout<<"no"<<endl;}

		}
		else if(c>=b && c>=a){
			max=c;
			if(max==a+b){
				cout<<"yes"<<endl;
			}
			else{cout<<"no"<<endl;}



		}
	}



	return 0;
}
