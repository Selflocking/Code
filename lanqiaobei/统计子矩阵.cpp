#include<bits/stdc++.h>

using namespace std;

int a[505][505];
long long sum[505][505];
int main(){
	int n,m,k;
	cin>>n>>m>>k;
	for(int i = 1;i<=n;++i){
		for(int j = 1;j<=m;++j){
			cin>>a[i][j];
		}
	}
	for(int i = 1;i<=n;++i){
		for(int j = 1;j<=m;++j){
			sum[i][j] = sum[i-1][j] + a[i][j];
		}
	}
	long long cnt = 0;
	// i上边界，j下边界 
	for(int i = 1;i<=n;++i){
		for(int j = i;j<=n;++j){
			// l,r左右边界 
			long long s = 0;
			for(int l = 1,r = 1;r<=m;r++){
				s+=sum[j][r] - sum[i-1][r];
				while(s>k){
					s-=sum[j][l] - sum[i-1][l];
					l++;
				}
				cnt+=r-l+1;
			}
		}
	}
	cout<<cnt<<"\n";
	
	return 0;
}

