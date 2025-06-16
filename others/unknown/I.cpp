#include<bits/stdc++.h>

using namespace std;

long long T,st,x,t,k,n,d,cnt,a[1000005],flag,tot,flag2;


int main(){
	scanf("%lld",&T);
	while(T--)
	{
		flag=0;cnt=0;tot=0;flag2=0;
		scanf("%lld%lld%lld%lld%lld",&x,&t,&k,&n,&d);
		st=x;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			a[i+n]=a[i];
			if(a[i]<=d)tot--;
			else tot++;
			if(tot>0)flag2=1;
			
		}
		for(int i=1;i<=2*n;i++)
		{
			if(a[i]<=d)
			{
				x--;
			}
			else x++;
			if(x<=k)
			{
				cnt++;
			}
			else cnt=0;
			if(cnt>=t)
			{
				flag=1;
				break;
			}
		}
		if(tot==0&&st==k&&flag2==0)flag=1;
		if(x<st)flag=1;
		if(flag==1)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
} 
