#include <iostream>
#include <map>
using namespace std;
const int N = 1e5 + 5;
int arr[N];
multimap<int, int> m;
int mem[N];
int fun(int x) {
    if (mem[arr[x]] != 0) return mem[x] = 1 + mem[arr[x]];
    if (arr[x] == -1) return 1;
    return mem[x] = 1 + fun(arr[x]);
}
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> arr[i];

    for (int i = 1; i <= n; ++i) {
        int cnt = fun(i);
        m.insert({cnt, i});
    }
    int flag = m.rbegin()->first;
    cout << flag << "\n";
    auto it = m.begin();
    while (it->first != flag) { ++it; }
    cout << it->second;
    while (++it != m.end()) { cout << " " << it->second; }
    return 0;
}