#include<bits/stdc++.h>

using namespace std;

long long T,x,t,k,n,d,a[1000005],sleep,cnt;

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>x>>t>>k>>n>>d;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		long long time = 0;
		long long bak = x;
		bool flag = false;
		for(int i = 0,nn = 2*n;nn>0;i = (i+1)%n,nn--){
			if(a[i]<=d){
				x-=1;
			}else{
				x+=1;
			}
			if(x<=k){
				time++;
			}else{
				time = 0;
			}
			if(time==t){
				cout<<"YES"<<endl;
				flag = true;
				break;
			}
		}
		if(flag){
			continue;
		} 
		
		if(x<bak){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
		
		for(int i=0;i<=n;i++){
			a[i]=0;
		}
	}
	return 0;
} 
