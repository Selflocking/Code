#include <iostream>
using namespace std;
int A[1005] = {};
int main() {
  int N;
  cin>>N;
  for (int i = 0; i < N; ++i) {
    int n;
    cin >> n;
    while (n--) {
      int t;
      cin >> t;
      A[t]++;
    }
  }
  int cnt = 0;
  int flag = 1;
  for (int i = 1; i <= 1000; ++i) {
    if (A[i] >= cnt) {
      cnt = A[i];
      flag = i;
    }
  }
  cout << flag << " " << cnt;
  return 0;
}