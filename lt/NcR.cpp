#include <iostream>
using namespace std;

int fun(int n)
{
	int fact=1;

	for (int i=2;i<=n;i++)
	{
		fact=fact*i;
	
	}
	return fact;


}





int main()
{
	int n,r,ans;
	cout<<"n,r: ";
       	cin>>n>>r;
        cout<<fun(n)<<endl;
	ans=fun(n)/(fun(n-r)*fun(r));
	cout<<ans<<endl;
	return 0;


	





}
