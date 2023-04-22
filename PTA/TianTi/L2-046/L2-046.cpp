#include <bits/stdc++.h>

using namespace std;

constexpr int mxN = 5e3 + 5;

/*
考场上的时候读错题了。

则寻找剩余空位数大于等于 n 的编号最小的赛场，将队员安排进去；

我以为这个编号最小是说的例如：
1号考场，2号考场，，，，
找一个编号最小且满足的考场。。。。。。
怪不得，de了半天还是觉得没错
*/

int idx = -1;
int rem[mxN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, c;
    cin >> n >> c;
    multiset<int> schools;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        string name;
        int num;
        cin >> name >> num;
        cout << name << " " << ceil(1.0 * num / c) << "\n";
        ans += num / c;
        if (num % c != 0) schools.insert(num % c);
    }
    auto it = schools.rbegin();
    while (it != schools.rend()) {
        int bst = 1e9;
        int loc = -1;
        for (int i = 0; i <= idx; ++i) {
            if (rem[i] >= *it && rem[i] < bst) {
                bst = rem[i];
                loc = i;
            }
        }
        if (loc != -1) {
            rem[loc] -= *it;
        } else {
            idx++;
            rem[idx] = c - *it;
            ans++;
        }
        it++;
    }
    cout << ans << "\n";
    return 0;
}
