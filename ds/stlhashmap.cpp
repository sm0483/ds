#include<iostream>
#include<map>
using namespace std;

int main(){
	map<int ,int>hmap;
	hmap.insert(1,40);
	hmap.insert(2,34);

	for(int itr=hmap.begin(); itr!=hmap.end();i++){
		cout<<itr->first;


	}



}


