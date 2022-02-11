#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int a,b,n,mx,mn,k=1;
	int x;
	cin>>x;
	for (int l=0;l<x;l++)
	{
	cin>>a>>b>>n;
	for (int i=0;i<n;i++)
	{
		k+=1;
		if (k%2==0)
		{
			a*=2;
		}
		else
		{
			b*=2;
		}
	
	}
	mx=max(a,b);
	mn=min(a,b);

	cout<<mx/mn<<endl;
	}

	return 0;

} 
