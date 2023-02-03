# [2023牛客寒假算法基础集训营6](https://ac.nowcoder.com/acm/contest/46814)

## A 阿宁的签到题

手速题

```cpp
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int mxN = 1e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a;
    cin >> a;

    if (a <= 7) {
        cout << "very easy"
             << "\n";
    } else if (a <= 233) {
        cout << "easy"
             << "\n";
    } else if (a <= 10032) {
        cout << "medium"
             << "\n";
    } else if (a <= 114514) {
        cout << "hard"
             << "\n";
    } else if (a <= 1919810) {
        cout << "very hard"
             << "\n";
    } else {
        cout << "can not imagine"
             << "\n";
    }
    return 0;
}

```

## B 阿宁的倍数	

利用cnt[i]记录因子i出现的次数，利用pre[i]记录前i个中因子a[i]出现的次数。

通过cnt[a[i]] - pre[i]得到后半部分有多少数是a[i]的倍数。

```cpp
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int mxN = 4e5 + 5;

int cnt[mxN];
int pre[mxN];

void work(int x) {
    for (int j = 1; j * j <= x; ++j) {
        if (x % j == 0) {
            cnt[j]++;
            if (j * j != x) {
                cnt[x / j]++;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; ++i) {
        work(a[i]);
        pre[i] = cnt[a[i]];
    }

    while (q--) {
        int op, x;
        cin >> op >> x;
        if (op == 1) {
            a.emplace_back(x);
            work(x);
            pre[a.size() - 1] = cnt[x];
        } else {
            cout << cnt[a[x]] - pre[x] << "\n";
        }
    }

    return 0;
}

```

## C 阿宁的大背包

按照这样的规则填数即可：1 4 5 8 9 10 7 6 3 2

```cpp
#include <algorithm>
#include <bits/stdc++.h>
#include <cstring>
#include <string>

using namespace std;
using ll = long long;
constexpr int mxN = 1e5 + 5;
constexpr int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    // 1 4 5 8 9 10 7 6 3 2
    for (int i = 0; i < n / 2; ++i) {
        if (i % 2 == 0)
            a[i] = i * 2 + 1;
        else
            a[i] = (i + 1) * 2;
    }
    for (int i = 0; i < n / 2; ++i) {
        if (i % 2 == 0) {
            a[n - i - 1] = a[i] + 1;
        } else {
            a[n - i - 1] = a[i] - 1;
        }
    }
    if (n % 2 == 1)
        a[n / 2] = n;

    string ans;
    for (int i = 0; i < n; ++i) {
        ans += to_string(a[i]) + " \n"[i == n - 1];
    }

    while (n > 1) {
        for (int i = 0; i + 1 < n; ++i) {
            a[i] = (a[i] + a[i + 1]) % MOD;
        }
        n--;
    }

    cout << a[0] << "\n";
    cout << ans;
    return 0;
}

```

## D 阿宁的毒瘤题

利用dpq数组分别记录下前i个字符中"","u","ud","udu"的个数。
利用dph数组分别记录下后面前i个字符中"","u","ud","udu"的个数。

删掉某字符后，利用前面得到的结果计算一下总共的udu数量。

找到udu数量最小的对应的位置，更改为'a'。

```cpp
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int mxN = 2e5 + 5;

string ss = " udu";

ll dpq[mxN][4] = {1};
ll dph[mxN][4] = {1};
string s;

void work(ll dp[][4]) {
    for (int i = 0; i < s.size(); ++i) {
        dp[i + 1][0] = 1;
        for (int j = 1; j <= 3; ++j) {
            dp[i + 1][j] = dp[i][j];
            if (s[i] == ss[j])
                dp[i + 1][j] += dp[i][j - 1];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s;
    work(dpq);
    reverse(s.begin(), s.end());
    work(dph);
    reverse(s.begin(), s.end());

    ll mi = 1e18;
    int ans = 0;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        ll cnt = 0;
        cnt += dpq[i][0] * dph[n - i - 1][3];
        cnt += dpq[i][1] * dph[n - i - 1][2];
        cnt += dpq[i][2] * dph[n - i - 1][1];
        cnt += dpq[i][3] * dph[n - i - 1][0];
        if (mi > cnt) {
            mi = cnt;
            ans = i;
        }
    }
    s[ans] = 'a';
    cout << s << "\n";
    return 0;
}

```

## E 阿宁的生成树

## F 阿宁的二进制

使用`__builtin_popcount()`计算二进制中1的个数

使用优先队列保存输入的数，堆顶为最大值

每次取出最大值，操作后放回堆中。记录下每次操作后的最大值，查询时直接输出。

```cpp
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

```

## G 阿宁的整数配对

猜测比较大的两个正数数字相乘，绝对值比较大的两个负数相乘，最后相加得出的结果比较大。

正数，负数，0分开存储。正数比较大的两个相乘，负数绝对值比较大的两个相乘。

此时，正数可能还剩1个，负数也可能还剩1个，0可能也有好几个。

如果剩1个非0数，不需要管

如果剩两个非0数，且有至少1个0，最好的结果是和0相乘得0,不需要管。

如果剩两个非0数，且1个0也没有，就只能这两个非0数相乘。

将所有结果放入一个数组，按照从大到小的顺序排序。

取出前k个即可，若不够k个表面后面的都是0。

```cpp
#include <algorithm>
#include <bits/stdc++.h>
#include <functional>

using namespace std;
using ll = long long;
constexpr int mxN = 1e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> z;
    vector<int> f;
    int zero = 0;

    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        if (t > 0) {
            z.emplace_back(t);
        } else if (t < 0) {
            f.emplace_back(t);
        } else {
            zero++;
        }
    }

    sort(z.begin(), z.end(), greater<int>());
    sort(f.begin(), f.end());

    vector<int> res;

    for (int i = 1; i < z.size(); i += 2) {
        res.emplace_back(z[i] * z[i - 1]);
    }
    for (int i = 1; i < f.size(); i += 2) {
        res.emplace_back(f[i] * f[i - 1]);
    }

    if (z.size() % 2 == 1 && f.size() % 2 == 1 && zero == 0) {
        res.emplace_back(z.back() * f.back());
    }

    sort(res.begin(), res.end(), greater<int>());

    ll ans = 0;
    for (int a : res) {
        ans += a;
        k--;
        if (k == 0)
            break;
    }

    cout << ans << "\n";

    return 0;
}

```

## H 阿宁讨伐虚空

如果n <= l，表示脆皮全部死了。输出0；如果n > r，表示肯定有活着的脆皮，输出1。

如果在(l, r]中间，求一下区间占比即可。

```cpp
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int mxN = 1e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int l, r;
    cin >> n;
    cin >> l >> r;
    if (n <= l) {
        cout << 0 << "\n";
    } else if (n > r) {
        cout << 1 << "\n";
    } else {
        int t = n - 1 - l + 1;
        printf("%.9lf", 1.0 * t / (r - l + 1));
    }
    return 0;
}

```

## I 阿宁前往沙城

## J 阿宁指指点点

## K 阿宁大战小红

## L 阿宁睡大觉

