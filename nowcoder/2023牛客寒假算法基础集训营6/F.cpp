#include <bits/stdc++.h>
#include <queue>

using namespace std;
using ll = long long;
constexpr int mxN = 1e5 + 5;

int f(int x) { return __builtin_popcount(x); }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    priority_queue<int> heap;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        heap.push(t);
    }

    int cnt = 0;
    vector<int> ans(5 * n);

    while (heap.top() != 1) {
        int t = f(heap.top());
        heap.pop();
        heap.push(t);
        cnt++;
        ans[cnt] = heap.top();
    }

    while (q--) {
        int a;
        cin >> a;
        if (a >= cnt) {
            cout << 1 << "\n";
        } else {
            cout << ans[a] << "\n";
        }
    }

    return 0;
}
