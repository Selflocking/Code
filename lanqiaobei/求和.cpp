#include<bits/stdc++.h>

using namespace std;

const int mxN = 2e5+10;
long long a[mxN];
long long s[mxN];

int main(){
	int n = 0;
	cin>>n;
	for(int i = 1;i<=n;++i){
		cin>>a[i];
		s[i] = s[i-1] + a[i];
	}
	long long res = 0;
	for(int i = 1;i<=n;++i){
		res+=a[i]*(s[n]-s[i]);
	}
	cout<<res<<"\n";
	return 0;
}

