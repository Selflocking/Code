# [2023牛客寒假算法基础集训营2](https://ac.nowcoder.com/acm/contest/46810)

昨天通宵了，做了几个题就不想做了。

## A.Tokitsukaze and a+b=n (easy)

暴力

```cpp
#include <bits/stdc++.h>

using namespace std;

constexpr int mxN = 1e5 + 5;

void solve() {
    int n;
    cin >> n;
    int l1, r1;
    cin >> l1 >> r1;
    int l2, r2;
    cin >> l2 >> r2;

    int cnt = 0;
    for (int i = l1; i <= r1 && i >= l1; ++i) {
        int t = n - i;
        if (t >= l2 && t <= r2)
            cnt++;
    }

    cout << cnt << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

```

## B.Tokitsukaze and a+b=n (medium)

若从[L1, R1]中选一个数a, 那么另一个数b一定属于[n-R1, n-L1]。

故求不同的选法即求[n-R1, n-L1]与区间[L2, R2]交集的大小。分类讨论即可。

```cpp
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

constexpr int mxN = 1e5 + 5;

void solve() {
    int n;
    cin >> n;
    int l1, r1;
    cin >> l1 >> r1;
    int l2, r2;
    cin >> l2 >> r2;

    // [n-r1, n-l1]
    // [l2, r2]

    int cnt = 0;

    if (n - r1 >= l2) {
        if (n - l1 <= r2) {
            cnt = r1 - l1 + 1;
        } else {
            cnt = r2 - n + r1 + 1; //[l2 <= n-r1, r2<n-l1]
        }
    } else {
        if (n - l1 <= r2) {
            cnt = n - l1 - l2 + 1; //[ n-r1<l2, n-l1<=r2]
        } else {
            cnt = r2 - l2 + 1;
        }
    }

    cout << max(0, cnt) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

```

## C.Tokitsukaze and a+b=n (hard)
## D.Tokitsukaze and Energy Tree

能量大的能量球尽量放在远离根节点的地方，对结果的贡献为能量值*到根节点的路径长度。

故求出所有节点的路径长度，对路径长度和能量值排序。两者相乘求和即为结果。

```cpp
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

using namespace std;
constexpr int mxN = 2e5 + 5;

int parent[mxN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 2; i <= n; ++i) {
        int t;
        cin >> t;
        parent[i] = t;
    }

    vector<int> depth(n + 1);
    depth[1] = 1;
    for (int i = 2; i <= n; ++i) {
        int cnt = 2;
        while (parent[i] != 1) {
            if (depth[parent[i]] != 0) {
                cnt = depth[parent[i]] + 1;
                break;
            } else {
                cnt++;
                parent[i] = parent[parent[i]];
            }
        }
        depth[i] = cnt;
    }

    vector<int> value(n);

    for (int i = 0; i < n; ++i) {
        cin >> value[i];
    }

    sort(value.begin(), value.end());
    sort(depth.begin(), depth.end());

    long long res = 0;
    for (int i = n - 1; i >= 0; --i) {
        res += 1LL * value[i] * depth[i + 1];
    }
    cout << res << "\n";
    return 0;
}

```

## E.Tokitsukaze and Function
## F.Tokitsukaze and Gold Coins (easy)
## G.Tokitsukaze and Gold Coins (hard)
## H.Tokitsukaze and K-Sequence

使用map记录每个数出现的次数。

每个数的贡献可以分开计算，对于出现次数小于等与k的数来说，贡献为(出现次数)。对于出现次数大于k的数来说，贡献为k-1。

故统计一下出现次数为1, 2, 3, 4....的个数。再计算一下当出现次数小于k时，每个的贡献。

```cpp
#include <bits/stdc++.h>

using namespace std;

constexpr int mxN = 1e5 + 5;

void solve() {
    int n;
    cin >> n;

    map<int, int> a;

    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        a[t]++;
    }

    vector<int> cnt(n + 1);
    vector<int> sum(n + 1);

    // 统计出现次数的i的个数
    for (auto it : a) {
        cnt[it.second]++;
    }
    // 计算每个的贡献
    for (int i = 1; i <= n; ++i) {
        sum[i] = cnt[i] * i;
    }
    // 前缀和
    for (int i = 1; i <= n; ++i) {
        cnt[i] += cnt[i - 1];
        sum[i] += sum[i - 1];
    }
    // 小于i的部分直接使用之前计算的贡献，大于i的部分为(k-1)*个数
    for (int i = 1; i <= n; ++i) {
        int res = 0;
        res += sum[i];
        res += (i - 1) * (cnt[n] - cnt[i]);
        cout << res << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

```

## I.Tokitsukaze and Musynx
## J.Tokitsukaze and Sum of MxAb

`max(abs(a-b),abs(a+b))` 即 `abs(a)+abs(b)`。

首先先将所有的数改为其绝对值。

考虑a_1与a_1, a_2 ... a_n,进行运算，结果应为a_1+a_1, a_1+a_2....a_1+a_n, 即n*a_1+sum, sum为所有数的和。

故答案应为n* a_1+sum + n* a_2+sum +....+ n* a_n+sum，即2\*n\*sum。

```cpp
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

constexpr int mxN = 1e5 + 5;

void solve() {
    int n;
    cin >> n;
    long long res = 0;
    for (int i = 0; i < n; ++i) {
        int t;
        cin>>t;
        res+=abs(t);
    }
    cout << 2*n*res << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

```

## K.Tokitsukaze and Synthesis and Traits
## L.Tokitsukaze and Three Integers