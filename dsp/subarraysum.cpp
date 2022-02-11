#include<iostream>
#include<vector>
using namespace std;

int main(){

	int arr[]={1,2,,0,5,6,7};
	vector<int>v;
	int sum=0;

	for(int i=0;i<7;i++){
		sum+=arr[i];
		v.push_back(sum);
	}
	int count=0;
	int large;

	for(int i=0;i<6;i++){
		count++;
		large=v[i];
		if(v[6]<v[i]){
			break;

		}

	}
	if(count==6){
		cout<<v[6]<<endl;


	}



	return 0;
}
