# [2023牛客寒假算法基础集训营1](https://ac.nowcoder.com/acm/contest/46800)

## A. World Final? World Cup! (I)

> 其判断胜负的规则为得分多者获胜，而若在罚完某一球后（无论是哪队罚的），当前双方比分已经使得无论之后的罚球结果如何都不会影响比赛的结果，则此时比赛结束。

题读了半天。

使用两个变量记录A, B两方的得分。若第`i`次罚球后一方分数高于另一方现在得分和假设往后几次罚球均获胜的得分，`i`即为答案。

```cpp
#include <bits/stdc++.h>

using namespace std;

constexpr int mxN = 1e5 + 5;

void solve() {
    string s;
    cin >> s;
    int ans = -1;
    int A = 0;
    int B = 0;
    for (int i = 0; i < 10; ++i) {
        if (i % 2 == 0) {
            if (s[i] == '1') {
                A++;
            }
        } else {
            if (s[i] == '1') {
                B++;
            }
        }
        if (A > B + (5 - (i + 1) / 2)) {
            ans = i + 1;
            break;
        }
        if (A + (5 - (i + 2) / 2) < B) {
            ans = i + 1;
            break;
        }
    }
    cout << ans << "\n";
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

## B. World Final? World Cup! (II)

## C. 现在是，学术时间 (I)

每个教授只有一篇论文

当一位教授拥有一篇引用量大于0的论文时，H指数为1, 当一位教授拥有两篇论文且两篇论文的引用量均超过2时H为2。

由此可见，一位教授拿一篇论文即是H指数最大的情况。

统计论文引用量大于0的论文个数即可

```cpp
#include <bits/stdc++.h>

using namespace std;

constexpr int mxN = 1e5 + 5;

void solve() {
    int n;
    cin >> n;
    vector<int> papers(n);
    for (int i = 0; i < n; ++i) {
        cin >> papers[i];
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (papers[i] >= 1) {
            ans++;
        }
    }
    cout << ans << "\n";
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

## D. 现在是，学术时间 (II)

~~显然~~，另一个顶点取矩形的四个定点时IOU最大。

~~显然~~，另一个定点离P点越远越好。

故先算出了最长的长和宽

```cpp
int a = max(abs(xx - x), abs(xx - 0));
int b = max(abs(yy - y), abs(yy - 0));
```

求得总面积后，再算出重合部分的长和宽

```cpp
int c = min(a, x);
int d = min(b, y);
```

答案：

```cpp
#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

constexpr int mxN = 1e5 + 5;

void solve() {
    int x, y, xx, yy;
    cin >> x >> y >> xx >> yy;
    int a = max(abs(xx - x), abs(xx - 0));
    int b = max(abs(yy - y), abs(yy - 0));
    int c = min(a, x);
    int d = min(b, y);
    int s = a * b + x * y;
    double ans = double(c * d) / (s - c * d);
    cout << ans << "\n";
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

## E. 鸡算几何

## F. 鸡玩炸蛋人

## G. 鸡格线

暴力的很好写，但是会超时，原因在于 `round(10*sqrt(x))` 会逐渐趋近于某个常数（0, 99, 100）。

可以使用`set`保存所有未收敛的数的下标，只对这些数进行操作。

```cpp
#include <bits/stdc++.h>
#include <cmath>

using namespace std;
constexpr int mxN = 1e5 + 5;

inline int fun(int x) {
    //
    return round(10 * sqrt(x));
}

int n, m;
set<int> locs;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    vector<int> nums(n + 1);
    long long sum = 0;

    for (int i = 1; i <= n; ++i) {
        cin >> nums[i];
        sum += nums[i];
        if (fun(nums[i]) != nums[i]) {
            locs.insert(i);
        }
    }

    while (m--) {
        int op;
        cin >> op;
        if (op == 2) {
            cout << sum << "\n";
        } else {
            int l, r, k;
            cin >> l >> r >> k;
            auto it = locs.lower_bound(l);
            auto ed = locs.upper_bound(r);

            while (!locs.empty() && it != ed) {
                sum -= nums[*it];
                bool flag = 0;
                for (int i = 0; i < k; ++i) {
                    int t = fun(nums[*it]);
                    if (nums[*it] == t) {
                        flag = 1;
                        break;
                    } else {
                        nums[*it] = t;
                    }
                }
                sum += nums[*it];
                int t = *it;
                it++;
                if (flag)
                    locs.erase(t);
            }
        }
    }
    return 0;
}

```

## H. 本题主要考察了DFS

题目好像是在诱导人，不需要用DFS。

如果一个拼图的上面凹下去了，那必有对应的另一个拼图下面是凸的。

故统计上下左右各自的凹凸情况。

如果上面凹的个数小于下面凸的个数。最后一块一定是下面凸。

这样就能过了，不过有点不严谨，因为例如上面凸的等于下面凹的，则最后那一块有可能是上面平下面平，也有可能是上面凹下面凸。

但是因为制作成本为 `10-x+y`。并不影响得分，所以也能过。


```cpp
#include <bits/stdc++.h>

using namespace std;

constexpr int mxN = 1e5 + 5;
// 上、右、下、左
void solve() {
    int n;
    cin >> n;
    vector<string> pts(n * n);
    for (int i = 0; i < n * n - 1; ++i) {
        cin >> pts[i];
    }
    int ao[4] = {0, 0, 0, 0};
    int tu[4] = {0, 0, 0, 0};
    for (int i = 0; i < n * n - 1; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (pts[i][j] == '1') {
                ao[j]++;
            } else if (pts[i][j] == '2') {
                tu[j]++;
            }
        }
    }
    int x = 0;
    int y = 0;
    for (int i = 0; i < 4; ++i) {
        // ao[i]
        if (ao[i] > tu[(i + 2) % 4]) {
            y++;
        } else if (ao[i] < tu[(i + 2) % 4]) {
            x++;
        }
    }
    cout << 10 - x + y << "\n";
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

想麻烦了，正确做法应该是：

```cpp
void solve() {
    int n;
    std::cin >> n;
     
    int sum = 0;
    for (int i = 0; i < n * n - 1; i++) {
        std::string s;
        std::cin >> s;
        sum += 10;
        for (auto c : s) {
            if (c == '1') sum--;
            if (c == '2') sum++;
        }
    }
     
    int total = n * n * 10;
    std::cout << total - sum << "\n";
}
```



## I. 本题也主要考察了DFS

## J. 本题竟也主要考察了DFS

## K. 本题主要考察了dp

对于样例10 4

一定是 100 100 100 1

假设最优的结构是100 100 100 100

如果1比较多，则为100 100 100 100 ...111111

故按照这样构造即可。

```cpp
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
constexpr int mxN = 1e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> s(n);
    fill(s.begin(), s.end(), 0);
    for (int i = 0; i < n; i += 3) {
        if (m > 0) {
            s[i] = 1;
            m--;
        }
    }

    for (int i = n - 1; i >= 0; --i) {
        if (s[i])
            continue;
        if (m > 0) {
            s[i] = 1;
            m--;
        } else {
            break;
        }
    }
    int ans = 0;
    for (int i = 0; i < n - 2; ++i) {
        int cnt = 0;
        if (s[i])
            cnt++;
        if (s[i + 1])
            cnt++;
        if (s[i + 2])
            cnt++;
        if (cnt >= 2)
            ans++;
    }
    cout << ans << "\n";
    return 0;
}

```

## L. 本题主要考察了运气

最优猜测：先猜团体，再猜个人。

猜团体：

一次猜对的概率：0.2,

两次：0.2

三次：0.2

四次：0.4，因为如果第四次直接猜中0.2, 如果第四次没猜中，则剩下一个肯定是，概率为0.2, 故总概率为0.4

猜个人：

一次猜对：0.25

两次猜对：0.25

三次猜对：0.5

故：

| 2      | 3      | 4      | 5      | 6      | 7      |
|:------:|:------:|:------:|:------:|:------:|:------:|
|  0.05  |   0.1  |   0.2  |  0.25  |   0.2  |   0.2  |

期望`E=2*0.05+3*0.1+4*0.2+5*0.25+6*0.2+7*0.2`

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    double E = 2 * 0.05 + 3 * 0.1 + 4 * 0.2 + 5 * 0.25 + 6 * 0.2 + 7 * 0.2;
    
    double mi = 999;
    int ans = 1;
    for (int i = 1; i <= 100; ++i) {
        double t = fabs(3.45 + 0.05 * i - E);
        if (mi > t) {
            mi = t;
            ans = i;
        }
    }

    cout << ans << "\n";
    return 0;
}

```

## M. 本题主要考察了找规律

题目是专门来迷惑人的。

使用复杂度为O(N^3)的dp即可。

`f[i][j]`表示在考虑有i人，j个仙贝的情况下的最优好感度。

使用 for (int k = 1; k <= j; ++k) 遍历。

```cpp
f[i][j] = max(f[i][j], f[i - 1][j - k] + 1.0 * k / j);
```

当前最优解可能不变，也可能为少1个好友，总仙贝数少k的情况下的最大亲密度加上当前给出k个仙贝获得的亲密度（k/j）。

最后输出`f[n][m]`即可。

```cpp
#include <bits/stdc++.h>
#include <cstdio>

using namespace std;
constexpr int mxN = 5e2 + 5;

double f[mxN][mxN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            for (int k = 1; k <= j; ++k) {
                f[i][j] = max(f[i][j], f[i - 1][j - k] + 1.0 * k / j);
            }
        }
    }

    printf("%.9f\n", f[n][m]);
    return 0;
}

```

要多输出几位小数，直接用cout只能过90%的数据。
