#include <iostream>
using namespace std;

int main()
{
	int t,n,x,p,score;
	cin>>t;

	for (int i=0;i<t;i++){

		cin>>n>>x>>p;

		score=3*x-(n-x);



		if (score>=p){
			cout<<"pass"<<endl;


		}
		else{
			cout<<"fail"<<endl;

		}






	}
	return 0;
}
