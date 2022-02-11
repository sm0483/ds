#include <iostream>
using namespace std;



int fib(int n)

{

	int t1=0;
	int t2=1;
	cout<<t1<<endl;
	cout<<t2<<endl;
	n=n-2;

        while (n--)
	{
		int temp=t1;
		t1=t2;
		t2=temp+t1;
		cout<<t2<<endl;
	

	}



}

int main()
{


	int n;
	cout<<"number of elements: "<<endl;
	cin>>n;

	fib(n);





return 0;
}
