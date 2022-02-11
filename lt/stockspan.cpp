#include<iostream>
#include<stack>
#include<vector>
using namespace std;


int main(){
	stack<pair<int ,int >>st;
	int arr[7]={100,80,60,70,60,75,85};

	for(int i=0;i<arr.size;i++){
		if(i==0 || st.top().first>arr[i]){
			st.push({arr[i],1});
		}
		else {
			while(st.top().first>arr[i]){
				int temp=st.top().second+1;
				cout<<st.top().first<<":"<<st.top().second<<endl;
				st.pop();
				st.push({arr[i],temp});
			}

		}


	}




	return 0;
}
