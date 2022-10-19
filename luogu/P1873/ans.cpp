// https://www.luogu.com.cn/problem/P1873
#include <iostream>
using namespace std;
const int mxN = 1e6 + 5;

int n, m;
int trees[mxN];

bool check(int x) {
  long long sum = 0;
  for (int i = 0; i < n; ++i) {
    if (trees[i] > x) {
      sum += trees[i] - x;
    }
  }
  return sum >= m;
}

int solve() {
  int l = 0;
  int r = 1e9;
  int mid;
  while (l<=r) {
    mid = l + (r - l) / 2;
    if(check(mid)){
        l = mid + 1;
    }else{
        r = mid - 1;
    }
  }
  return r;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> trees[i];
  }
  cout << solve();
  return 0;
}