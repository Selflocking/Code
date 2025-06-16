#include<bits/stdc++.h>

using namespace std;
#define ll long long
ll t,n,m,k;
struct node{
	ll a,b,ans;
}c[500005];
ll d[500005];
bool cmp(node a,node b){
	return a.a<b.a;
}

int main(){
	cin>>t>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>c[i].a>>c[i].b;
	}
	sort(c+1,c+m+1,cmp);
	for(int i=1;i<=m;i++){
		d[c[i].a]+=c[i].b;
	}
	for(int i=1;i<=500005;i++){
		d[i]+=d[i-1];
		if(d[i-1]>0){
			d[i]-=k;
		}
		if(d[i]<0){
			d[i]=0;
		}
	}
	if(d[t]!=n){
		//cout<<d[t]<<endl;
		cout<<"Wrong Record";
	}
	else{
		long long anst=1e18+1,anstt=anst+k;
		for(int i=1;i<=m;i++){
			if(c[i].a<t){
				continue;
			}
			long long qwq=(d[c[i].a]+1)/k;
			if((d[c[i].a]+1)%k!=0)
				qwq+=1;
			if(qwq<=anstt){
				anst=c[i].a;
				anstt=qwq;	
				//cout<<c[i].a<<" "<<d[c[i].a]<<" "<<anst<<" "<<anstt<<endl;
			}
		}
		cout<<anst<<" "<<anstt;
	}
	return 0;
} 
