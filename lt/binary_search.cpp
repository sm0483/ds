#include <iostream>
using namespace std;

int main()
{
	int arr[20];
	int key,n,first,last,middle;
	cout<<"element number,key,array"<<endl;
	cin>>n;
	cin>>key;

	for (int i=0;i<n;i++)
	{
		cin>>arr[i];
	
	}


	first=0;
	last=n-1;
	middle=(first+last)/2;


	while(last>=first)
	{
		middle=(first+last)/2;
		if(arr[middle]==key)
		{
			cout<<"yep found"<<endl;
			break;
		
		}

		else if(arr[middle]>key)
		{
			last=middle-1;
		
		}
		else if(arr[middle]<key)
		{
			first=middle+1;
		
		}


		

	
	
	
	}


	
        return 0;







}
