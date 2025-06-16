#include<bits/stdc++.h>
using namespace std;
long long n,k,cnt;
struct node
{
	long long val,pos;
}a[1000005];
queue<node>q;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].val;
		a[i].pos=i;
		q.push(a[i]);
	}
	node temp,nex;
	temp=q.front();
	q.pop();
	nex=q.front();
	while(cnt<=k)
	{
		if(temp.val>=nex.val)
		{
			cnt++;
			q.pop();
			q.push(nex);
			nex=q.front();
		}
		else
		{
			cnt=1;
			q.push(temp);
			temp=q.front();
			q.pop();
			nex=q.front();
		}
	}
	cout<<temp.pos;
	return 0;
	
}
/*int n,k;
struct node{
	int a,id;
};
queue<node>q;
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int tmp;
		cin>>tmp;
		q.push(node{tmp,i});
	}
	long long now=0,nowid=0;
	while(now<k){
		node ied=q.front();
		q.pop();
		while(ied.a>=q.front().a){
			node tmp=q.front();
			q.pop();
			q.push(tmp);
			now++;
			if(now>=k)break;
		}
		if(now>=k){
			nowid=ied.id;
			break;
		}
		if(ied.a<q.front().a){
			now=0;
			q.push(ied);
		}
	}
	cout<<nowid;
}*/
