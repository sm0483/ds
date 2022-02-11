#include <iostream>
using namespace std;

int main(){

	int array[20]={3,2,4};
	int size=4,target,i,j,flag=0;

	cin>>target;



	for (i=0;i<size;i++){

		if (flag==-1){
		break;
		
		
		}

		for (j=1;j<size-1;j++){
			int k=array[j]+array[i];


			if (k==target){
				flag=-1;
				cout <<i<<","<<j<<endl;
				break;

			}






		}

	}


	return 0;






}
