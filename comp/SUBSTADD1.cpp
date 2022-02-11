#include<iostream>
using namespace std;

int main(){
        int t,arr[1000],n,x,y,ls[1000],out[2000];
        cin>>t;
        while(t--){
                cin>>n>>x>>y;
                for(int i=0;i<n;i++){
                        cin>>arr[i];
                }
                for(int k=0;k<n;k++){
                        cin>>ls[k];

                }
                for(int j=0;j<n;j++){
			out[j]=arr[j]+x;
			int w=arr[j]+y;
			arr[j]=w;
                }

		for(int i=n-1;i<2*n;i++){
			out[i]=arr[i];
		}
		int count=0;
		for(int a=0;a<2*2*n;a++){
			count++;
			cout<<out[a]<<" ";
			/*bool key=false;
			for(int b=0;b<2*n;b++){
				if(ls[a]==out[b]){
					key=true;
				}
			}
			if(!key){
				cout<<"no"<<endl;
				break;
			}
			*/

		}
		if(count==n){
			cout<<"yes"<<endl;


		}


        }

        return 0;
}

