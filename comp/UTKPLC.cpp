#include <iostream>
using namespace std;

int main()
{
	int n;
	char a,b,c;
	char x,y;
	cin>>n;

	while (n--)
	{
		cin>>a>>b>>c;
		cin>>x>>y;


		if (a==x || a==y)
		{
			cout<<a<<endl;
		}
		else if (b==x || b==y)
		{
			cout<<b<<endl;

		}

		else if (c==x || c==y)
		{
			cout<<c<<endl;


		}

	}
	return 0;



}
