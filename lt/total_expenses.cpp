#include <iostream>
using namespace std;
int main()
{
	int n,number,price;
	float bill;
	cin>>n;

	while (n--)
	{
		bill=0;
		cin>>number>>price;

		if (number>1000)
		{
			bill=(number*price)-((number*price)*(0.1));

	
		
		
		}
		else 
		{
			bill=(number*price);
		
		
		}
	  
	
	
	cout<<bill<<endl;
	
	}




return 0;

}
