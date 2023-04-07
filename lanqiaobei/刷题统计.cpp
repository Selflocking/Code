#include<bits/stdc++.h>

using namespace std;

int main(){
	long long a,b,n;
	cin>>a>>b>>n;
	
	long long all = a*5 + b*2;
	
	long long week = n/all;
	long long res = week * 7;
	
	n = n%all;
	while(n>0){
		if(res%7<4){
			n-=a;
		}else{
			n-=b;
		}
		res++;
	}
	cout<<res<<"\n";
	return 0;
}

