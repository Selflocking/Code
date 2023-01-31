# [2023牛客寒假算法基础集训营4](https://ac.nowcoder.com/acm/contest/46812)

## A 清楚姐姐学信息论

因为一共有x ✖️ y张号码牌，在表示x进制的时候，一共可以表示y位，故表达效率为pow(x,y)。

x进制的信息效率：pow(x,y); y进制的信息表达效率：pow(y,x)。

```cpp
#include <bits/stdc++.h>

using namespace std;
constexpr int mxN = 1e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> a >> b;

    if (a == b) {
        cout << a << "\n";
    } else {
        if (pow(a, b) > pow(b, a)) {
            cout << a << "\n";
        } else if (pow(a, b) < pow(b, a)) {
            cout << b << "\n";
        } else {
            cout << min(a, b) << "\n";
        }
    }
    return 0;
}

```

## B 清楚姐姐学构造

考虑a[0]与a[n-1]对m同余，b[0]与-b[n-1]对m同余，同时c[0]与a[0]+b[0]同余，c[n-1]与a[n-1]+b[n-1]同余。

因为最后的输出的每个数最好是在[0,m)范围内，故可以得知 a[0] = a[n-1], b[0] + b[n-1] = m。

c[0] = (a[0]+b[0])%m; c[n-1] = (a[n-1]+b[n-1])%m。 

故(c[0]+c[n-1])%m = (a[0]+a[n-1]+b[0]+b[n-1])%m = (2 * a[0])%m

故可以简单理解为c[0]+c[n-1] = 2 * a[0]或者2*a[0]-m

要保证a[0]是个整数，如果不是输出No。

按照这个规则构造出a,b数组的前半部分，后半部分按照要求补齐。

这个校验其实是非必需的:

```cpp
    for (int i = 1; i <= n; ++i) {
        if (mod(a[i] + b[i]) != c[i]) {
            cout << "No\n";
            return 0;
        }
    }
```

最终答案：

```cpp
#include <bits/stdc++.h>
#include <cmath>
#include <cstdlib>
#include <sys/types.h>

using namespace std;
constexpr int mxN = 1e5 + 5;

long long a[mxN];
long long b[mxN];
long long c[mxN];
long long n, m;

long long mod(long long a) {
    a %= m;
    if (a < 0)
        a += m;
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }

    if (n % 2 != 0) {
        a[n / 2 + 1] = c[n / 2 + 1];
        b[n / 2 + 1] = 0;
    }

    for (int i = 1; i <= n / 2; ++i) {
        long long tmp = c[i] + c[n - i + 1];
        if (tmp % 2 == 0)
            a[i] = tmp / 2;
        else if (m % 2 == 1)
            a[i] = (tmp + m) / 2;
        else {
            cout << "No\n";
            return 0;
        }

        a[i] = mod(a[i]);
        b[i] = mod(c[i] - a[i]);
    }

    for (int i = n / 2 + 1; i <= n; ++i) {
        a[i] = a[n - i + 1];
        b[i] = mod(-b[n - i + 1]);
    }

    for (int i = 1; i <= n; ++i) {
        if (mod(a[i] + b[i]) != c[i]) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    for (int i = 1; i <= n; ++i) {
        cout << a[i] << " \n"[i == n];
    }
    for (int i = 1; i <= n; ++i) {
        cout << b[i] << " \n"[i == n];
    }
    return 0;
}

```

## C 清楚姐姐学01背包(Easy Version)

算一下强制选某个物品和强制不选某个物品的最大价值

结果是强制不选某物品的最大价值-强制选某物品的最大价值+1。如果小于等于0就代表已经是必选蝴蝶结。

```cpp
#include <algorithm>
#include <bits/stdc++.h>
#include <cstring>

using namespace std;
using ll = long long;
constexpr int mxN = 5e3 + 5;

ll w[mxN];
ll v[mxN];
ll f[mxN];
ll xuan[mxN];
ll buxuan[mxN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        cin >> w[i] >> v[i];
    }

    for (int x = 1; x <= n; ++x) {
        for (int i = 1; i <= n; ++i) {
            if (i == x)
                continue;
            for (int j = m; j >= w[i]; --j) {
                f[j] = max(f[j], f[j - w[i]] + v[i]);
            }
        }
        buxuan[x] = f[m];
        memset(f, 0, sizeof f);
    }
    for (int x = 1; x <= n; ++x) {
        for (int i = 1; i <= n; ++i) {
            if (i == x)
                continue;
            for (int j = m - w[x]; j >= w[i]; --j) {
                f[j] = max(f[j], f[j - w[i]] + v[i]);
            }
        }
        xuan[x] = f[m - w[x]] + v[x];
        memset(f, 0, sizeof f);
    }

    for (int i = 1; i <= n; ++i) {
        cout << max(0LL, buxuan[i] - xuan[i] + 1LL) << "\n";
    }
    return 0;
}

```

## D 清楚姐姐学01背包(Hard Version)

## E 清楚姐姐打怪升级

按照顺序轮流考虑每只怪兽:

如果怪兽血量小于攻击力，消耗一个时间间隔t.

如果怪兽的恢复速度*时间间隔大于或者等于攻击力，输出-1.

接着计算一下将怪物从满血打到可以一击必杀所需要的时间，再加上一个时间间隔。

最后输出即可。

```cpp
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    long long t;
    long long atk;
    cin >> n >> t >> atk;

    vector<pair<long long, long long>> monster(n);

    for (int i = 0; i < n; ++i) {
        long long a, b;
        cin >> a >> b;
        monster[i] = {a, b};
    }
    long long ans = 0;

    for (int i = 0; i < n; ++i) {
        if (monster[i].first <= atk) {
            ans += t;
            continue;
        }
        if (monster[i].second * t >= atk) {
            cout << -1 << "\n";
            return 0;
        }

        ans += ceil(1.0 * (monster[i].first - atk) /
                    (atk - monster[i].second * t)) *
               t;
        ans += t;
    }

    cout << ans - (t - 1) << "\n";
    return 0;
}

```

## F 清楚姐姐学树状数组

## G 清楚姐姐逛街(Easy Version)

## H 清楚姐姐逛街(Hard Version)

## I 清楚姐姐采蘑菇

## J 清楚姐姐学排序

## K 清楚姐姐玩翻翻乐

## L 清楚姐姐的三角形I

首先将每条边*2，避免处理浮点数。

容易得知：

```cpp
lc = (va + vb - vc) / 2;
la = vb - lc;
lb = va - lc;
```

最后看一下是不是两边之和大于第三边，是不是合法边。

```cpp
#include <bits/stdc++.h>

using namespace std;

constexpr int mxN = 1e5 + 5;

void solve() {
    long long va, vb, vc;
    cin >> va >> vb >> vc;
    va *= 2;
    vb *= 2;
    vc *= 2;

    long long lc = (va + vb - vc) / 2;
    long long la = vb - lc;
    long long lb = va - lc;

    if (la + lc <= lb || la + lb <= lc || lc + lb <= la) {
        cout << "No\n";
        return;
    }

    if (la % 2 != 0 || lb % 2 != 0 || lc % 2 != 0) {
        cout << "No\n";
        return;
    }

    cout << "Yes\n";
    cout << la / 2 << " " << lb / 2 << " " << lc / 2 << "\n";
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

## M 清楚姐姐的三角形II

输出 1 1 2 1 1 2 1 1 2.......即可

```cpp
#include <bits/stdc++.h>

using namespace std;
constexpr int mxN = 1e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // 1 1 2 1 1 2 1 1 2
    for (int i = 1; i <= n; ++i) {
        if (i % 3 == 0) {
            cout << "2 ";
        } else {
            cout << "1 ";
        }
    }
    cout << "\n";

    return 0;
}

```
