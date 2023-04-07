#include<bits/stdc++.h>

using namespace std;

// 0 0 0

// 1 1 1
// 0 1 1

// 1 2 2
// 1 0 2

// 2 1 3
// 2 1 0

// 3 2 1
// 3 0 1

// 4 1 2
// 0 1 2

// 1 2 3
// 1 0 3

// 2 1 4
// 2 1 0

// 3 2 1
// 3 0 1


int a[10005];

int main(){
	int n = 0;
	cin>>n;
	for(int i = 0;i<n;++i){
		int x = (n-i-1)*2;
		int y = i*2;
		a[i] = max(x,y);
	}
	
	for(int i = 0;i<n;++i){
		cout<<a[i]<<"\n";
	}
	return 0;
}
