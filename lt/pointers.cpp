#include <iostream>
using namespace std;

void fun(int *a,int *b){

	cout<<*a+*b<<endl;

}


int main(){

	int a,b,*ptra,*ptrb;

	cin >>a>>b;

	ptra=&a;
	ptrb=&b;


	fun(ptra,ptrb);

	//cout<<ptr<<endl;
	return 0;








}
