# [2023牛客寒假算法基础集训营5](https://ac.nowcoder.com/acm/contest/46813)

## A 小沙の好客

先将输入排序，接着用前缀和存储多个商品价值和。

通过二分查找找到对应的区间，输出即可。

```cpp
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int mxN = 1e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    vector<ll> sum(n + 1);

    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + a[i];
    }

    while (q--) {
        int k, x;
        cin >> k >> x;

        int t = upper_bound(a.begin(), a.end(), x) - a.begin() - 1;

        cout << sum[t] - sum[max(0, t - k)] << "\n";
    }
    return 0;
}

```

## B 小沙の博弈

可怜的沙沙，他永远也不会获胜。

```cpp
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int mxN = 1e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    if (n % 2 == 0) {
        cout << "win-win!\n";
    } else {
        cout << "Yaya-win!\n";
    }
    return 0;
}

```

## C 小沙の不懂

## D 小沙の赌气

## E 小沙の印章

## F 小沙の串串

## G 小沙の编码

## H 小沙の店铺

模拟

```cpp
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int mxN = 1e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll x, y, k, n, t;
    cin >> x >> y >> k >> n >> t;
    ll sum = 0;
    ll bak = n;
    ll v = 0;
    while (n != 0 && sum < t) {
        sum += x * n;
        x += (n + v) / k * y;
        v = (n + v) % k;
        n--;
    }

    if (sum < t)
        cout << -1 << "\n";
    else
        cout << bak - n << "\n";

    return 0;
}

```

## I 小沙の金银阁

## J 小沙の最短路

## K 小沙の抱团 easy

容易得知，当n<=2时不用再发指令，而当n>2时，要求一半多一点的人成团删掉的人最多，例如有6个人，要求6/2+1=4人成团，有5人时，要求5/2+1=3人成团。

```cpp
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int mxN = 1e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    ll cnt = 0;
    while (n > 2) {
        n = n / 2 + 1;
        cnt++;
    }
    cout << cnt << "\n";
    return 0;
}

```

## L 小沙の抱团 hard

f[i]表示剩余i个人花费的代价，初始值为1e18。

最后从f[2]~f[n]，第一个小于1e18的即为答案。

```cpp
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int mxN = 1e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<pair<ll, ll>> cmd(m);
    for (auto &[a, b] : cmd) {
        cin >> a >> b;
    }

    if (n <= 2) {
        cout << 0 << "\n";
        return 0;
    }

    vector<ll> f(n + 1, 1e18);
    f[n] = 0;
    for (int i = n; i >= 2; --i) {
        for (auto &[a, b] : cmd) {
            if (b >= i)
                continue;
            ll t = i / b * b;
            f[t] = min(f[t], f[i] + a);
        }
    }

    ll ans = 1e18;
    for (int i = 2; i <= n; ++i) {
        if (f[i] < ans) {
            ans = f[i];
            break;
        }
    }

    cout << ans << "\n";
    return 0;
}

```
