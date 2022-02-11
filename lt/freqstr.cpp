#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int count;

	string str;

	cin>>str;

	for (int i=0;i<str.length();i++){
		for (int j=i;j<str.length();j++){
			count=0;
			if (str[i]==str[j]){

				count++;

			}



		}

		cout<<str[i]<<" repeats "<< count <<endl;



	}


	return 0;
}
