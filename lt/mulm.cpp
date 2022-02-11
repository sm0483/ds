#include <iostream>
using namespace std;

int main(){


	int r1,c1,r2,c2;
	cout<<"r1: c1: r2: c2:";
	cin>>r1>>c1>>r2>>c2;
	int arf[r1][c1],ars[r2][c2],sol[r1][c2];

	//for first matrix input:
	cout<<"first matrix"<<endl;
	for (int i=0;i<r1;i++){

		for (int j=0;j<c1;j++){

			cin>>arf[i][j];


		}
	}

	//second matrix input;
	cout<<"second matrix"<<endl;

	for (int i=0;i<r2;i++){

		for (int j=0;j<c2;j++){

			cin>>ars[i][j];


		}

	}

	//intioating

	for (int i=0;i<r1;i++){

		for (int j=0;j<c2;j++){

			sol[i][j]=0;


		}
	}


	//main algorithm


	for (int i=0;i<r1;i++){
		int sum=0;

		for (int j=0;j<c2;j++){

			for (int k=0;k<r2;k++){

				sol[i][j]+=arf[i][k]*ars[k][j];
			}


		}





	}



	for (int i=0;i<r1;i++){

		for (int j=0;j<c2;j++){

			cout<<sol[i][j]<<" ";


		}

		cout<<endl;
	}




















	return 0;
}
