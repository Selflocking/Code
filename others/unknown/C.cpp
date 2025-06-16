#include<bits/stdc++.h>
 
using namespace std;
 
double R,E;
double ans=(double)0x7fffffff,r,rmax,rmin=1000000000;
int n;
int main(){
	scanf("%d%lf%lf",&n,&R,&E);
	for(int i=1;i<=n;i++)
	{
		scanf("%lf",&r);
	}
	if(E>3.1415926)E=2*3.1415926-E;
	ans=min(2.0*R,E*R);
	printf("%.6f",ans);
	return 0;
} 
