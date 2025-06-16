#include<bits/stdc++.h>

using namespace std;
long long n,m;
const int mxN = 505;
using pll = pair<long,long>
vector<vector<pll>> G(mxN);

int main(){
	cin>n>>m;
	for(int i = 0;i<n;++i){
		int a,b,c;
		cin>>a>>b>>c;
		G[a].push({b,c});
	}
	return 0;
} 
