#include <iostream>
using namespace std;

int fun(int n)
{
	if (n==0){return 1;}
	int fact=1;
	for (int i=2;i<=n;i++)
	{fact*=i;}
	return fact;



}




int main()
{
	int n,ans;
	cin>>n;



	for (int i=0;i<n;i++)
	{
		for (int j=0;j<=i;j++)
		{
			ans=fun(i)/(fun(i-j)*fun(j));
		        cout<<ans<<" ";


		
		
		}
		cout<<""<<endl;
	
	}



return 0;

}
