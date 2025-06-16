#include<bits/stdc++.h>

using namespace std;
struct node
{
	long long t,x;
}y[500005];
bool cmp(node a,node b)
{
	return a.t<b.t;
}
long long T,n,m,k,nowt,cnt,flag,ans1,ans2=1e18+1;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>T>>n;
	cin>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>y[i].t>>y[i].x;
	}
	sort(y+1,y+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(T<=y[i].t&&T>y[i-1].t)
		{
			long long temp=cnt;
			temp-=(T-y[i-1].t)*k;
			if(T==y[i].t)temp+=y[i].x;
			if(temp<0)temp=0;
			if(temp==n)flag=1;
		}
		cnt-=(y[i].t-y[i-1].t)*k;
		if(cnt<0)cnt=0;
		cnt+=y[i].x;
		if(flag)
		{
			long long temp;
			temp=(cnt+1)/k;
			if((cnt+1)%k!=0)temp++;
			if(temp<=ans2)
			{
				ans1=y[i].t;
				ans2=temp;
			}
		}
	}
	if(flag)
	{
		cout<<ans1<<" "<<ans2;
	}
	else cout<<"Wrong Record";
	return 0;
} 
