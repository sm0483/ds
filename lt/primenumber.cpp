#include <iostream>
#include <cmath>
using namespace  std;

bool Isprime(int num)
{
	for (int k=2;k<=sqrt(num);k++)
	{
		if (num%k==0){return false;}

	}
	return true;
}




int main()
{
	int a,b;
	cin>>a>>b;


	for (int i=a;i<b;i++)
	{
                         
		if (Isprime(i)){cout<<i<<endl;}

	
	}


return 0;
}
