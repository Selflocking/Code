# [2023牛客寒假算法基础集训营3](https://ac.nowcoder.com/acm/contest/46811)

## A 不断减损的时间

容易得知，令正数越小，负数越大，最后的和越小。

所以令正偶数尽量小即可。

```cpp
#include <bits/stdc++.h>

using namespace std;
constexpr int mxN = 1e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        long long t;
        cin >> t;
        if (t > 0 && t % 2 == 0) {
            while (t % 2 == 0) {
                t /= 2;
            }
        }
        sum += t;
    }
    cout << sum << "\n";
    return 0;
}

```

## B 勉强拼凑的记忆

## C 忽远忽近的距离

遍历每一个位置上可能出现的数，如果找到合适的就输出。

本来以为过不了，交了发现还是挺快的(18 ms)，应该是数据比较水。

```cpp
#include <bits/stdc++.h>

using namespace std;
constexpr int mxN = 1e5 + 5;

bool st[mxN];
int ans[mxN];
int n;

void dfs(int x) {
    if (x == n + 1) {
        for (int i = 1; i <= n; ++i) {
            cout << ans[i] << " \n"[i == n];
        }
        exit(0);
    }

    if (x - 2 > 0 && !st[x - 2]) {
        ans[x] = x - 2;
        st[x - 2] = 1;
        dfs(x + 1);
        st[x - 2] = 0;
    }
    if (x - 3 > 0 && !st[x - 3]) {
        ans[x] = x - 3;
        st[x - 3] = 1;
        dfs(x + 1);
        st[x - 3] = 0;
    }
    if (x + 2 <= n && !st[x + 2]) {
        ans[x] = x + 2;
        st[x + 2] = 1;
        dfs(x + 1);
        st[x + 2] = 0;
    }
    if (x + 3 <= n && !st[x + 3]) {
        ans[x] = x + 3;
        st[x + 3] = 1;
        dfs(x + 1);
        st[x + 3] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    if (n < 4) {
        cout << -1 << "\n";
        return 0;
    }

    dfs(1);

    cout << -1 << "\n";
    return 0;
}

```

## D 宿命之间的对决

偶数可以变为奇数，也可变为偶数，而奇数只可以变为奇数。

最优策略下，拿到偶数的人只需要保持下一个数是奇数，拿到奇数的人必输。

```cpp
#include <bits/stdc++.h>

using namespace std;
constexpr int mxN = 1e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;
    if (n % 2 == 0) {
        cout << "kou\n";
    } else {
        cout << "yukari\n";
    }
    return 0;
}

```

## E 公平守望的灯塔

假设 M 为斜边上的中点，C 为直角顶点

设向量 AM = (delta x, delta y)

则易知 MC = (delta y, - delta x)

AC = (delta x + delta y, delta y - delta x)

故点 C = (Xa + delta x + delta y, Ya + delta y - delta x)

为了避免处理浮点数，将所有点的坐标放大1倍。

```cpp
#include <bits/stdc++.h>

using namespace std;
constexpr int mxN = 1e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b, c, d;
    cin >> a >> b >> c >> d;

    // M 为斜边上的中点，C为直角顶点
    // AM = (delta x, delta y)
    // MC = (delta y, - delta x)
    // AC = (delta x + delta y, delta y - delta x)

    long long dx = c - a;
    long long dy = d - b;

    long long cx = 2 * a + dx + dy;
    long long cy = 2 * b + dy - dx;

    if (cx % 2 == 1 || cy % 2 == 1) {
        cout << "No Answer!\n";
    } else {
        cout << cx / 2 << " " << cy / 2 << "\n";
    }
    return 0;
}

```

## F 迎接终结的寂灭

```php
42
```

## G 严肃古板的秩序

## H 穿越万年的轮回

## I 灵魂碎片的收集

## J 无法磨灭的悔恨

## K 永恒守候的爱恋
