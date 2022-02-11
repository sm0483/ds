#include <iostream>
using namespace std;
int main(){
	int row,col,n;

	cin>>n;




	for (row=1;row<=2*n;row++){
		for (col=1;col<=2*n;col++){



			if  ( row<=n && col<=row || col>=2*n-row){
				cout<<"*";



			}


			else if( row <=n || col>row || col <2*n-row ){


				cout<<"-";



			}




		}
		cout<<endl;




	}

	return 0;
}

