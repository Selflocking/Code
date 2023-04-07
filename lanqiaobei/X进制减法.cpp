#include<bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

int A[100005];
int B[100005];
int times[100005];
int main(){
	int n = 0;
	cin>>n;
	
	int ma,mb;
	cin>>ma;
	for(int i = 1;i<=ma;++i){
		cin>>A[i];
	}
	cin>>mb;
	for(int i = 1;i<=mb;++i){
		cin>>B[ma-mb+i];
	}
	for(int i = 1;i<=ma;++i){
		times[i] = max(max(A[i],B[i])+1,2);
		A[i] = A[i] - B[i];
	}
	long long res = A[1];
	for(int i = 2;i<=ma;++i){
		res *= times[i];
		res = (res+A[i])%MOD;
	}
	cout<<res<<"\n";
	return 0;
}

