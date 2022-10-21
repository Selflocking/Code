#include <iostream>
using namespace std;
using ll = long long;
const int mxL = 1e5 + 5;
const ll mxN = 1e14 + 5;

int l, k;
int logs[mxL];

ll sum(ll x) {
  ll res = 0;
  ll temp = 0;
  for (int i = 0; i < l; ++i) {
    temp += logs[i];
    if (temp >= x) {
      res++;
      temp = 0;
    }
    if (temp < 0)
      temp = 0;
  }
  return res;
}

// n越大，k越小。找到n的范围。

int main() {
  cin >> l >> k;
  for (int i = 0; i < l; ++i) {
    cin >> logs[i];
  }
  //先求最小值
  ll lo = 0, hi = mxN;
  while (hi - lo > 1) {
    ll mid = lo + (hi - lo) / 2;
    const ll s = sum(mid);
    if (k < s) {
      lo = mid;
    } else if (k > s) {
      hi = mid;
    } else {
      hi = mid;
    }
  }
  if (sum(hi) != k) {
    cout << -1;
    return 0;
  } else {
    cout << hi << " ";
  }
  //再求最大值
  lo = 0, hi = mxN;
  while (hi - lo > 1) {
    ll mid = lo + (hi - lo) / 2;
    const ll s = sum(mid);
    if (k < s) {
      lo = mid;
    } else if (k > s) {
      hi = mid;
    } else {
      lo = mid;
    }
  }
  cout << lo;
  return 0;
}