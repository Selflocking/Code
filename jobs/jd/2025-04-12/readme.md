## 京东笔试

### 第一题 SQL

给你一张读者表，一张借阅表，让你输出 2024 年借阅次数超过 3 次的读者姓名和借阅次数，按照借阅次数降序排序。

用 left join + group by + having + order by 就行。

因为没怎么用过 having, 只知道 group by 后可以接条件，但是忘记 having 怎么写了，最后用子查询过了。

### 第二题

给你 n 个数组，每个数组的大小为 m。

规定数组的价值为数组中的最小数

你可以将两个数组合并，合并方式为$c_i = a_i + b_i$。

但是你只有一次合并机会。

请问最终这些数组的价值最大值为多少。

```txt
3 4
1 2 3 4
2 3 4 5
3 4 5 6
```

```
3
```

#### 答案

想了很久，不知道该怎么做，最后时间不够了就开始写暴力做法，竟然过了。

```cpp
#include <iostream>
#include <vector>

using namespace std;

int n, m;

int merge(vector<int> &a, vector<int> &b) {
    int res = 1e9 + 10;
    for (int i = 0; i < m; ++i) {
        res = min(res, max(a[i], b[i]));
    }
    return res;
}

int main() {
    cin >> n >> m;
    vector<vector<int>> arr(n);
    for (int i = 0; i < n; ++i) {
        arr[i].resize(m);
        for (int j = 0; j < m; ++j) {
            cin >> arr[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            ans = max(ans, merge(arr[i], arr[j]));
        }
    }
    cout << ans << "\n";
    return 0;
}

```

### 第三题

给你一个货架，我们使用数组表示，使用数字表示货物的价值。现在将货架分为两部分，你可以在这两部分中交换物品。问是否可以是这两部分价值相等。

#### 输入格式

首先一个 t,代表测试用例的数量

接着一个数字 m（1~1e5）, 代表货物的数量

接着 m 个数字，代表货物价值，1~1e6。

例如:

```txt
2
5
6 3 3 5 7
5
4 1 1 1 2
```

#### 输出格式

输出"YES" or "NO", 每行一个。

例如上面样例：

```txt
YES
NO
```

#### 答案

我没做出来，只过了 18%的数据。

简单来说就是看数组的某个子集的和是否可以做到 sum/2。

二进制枚举可能是一种办法，因为每个数字要么被选，要么不被选，但是数据范围太大了，肯定超时。

#### 原题

问了 deepseek, leetcode 有类似的题目：

[leetcode 416. 分割等和子集](https://leetcode.cn/problems/partition-equal-subset-sum/description/)
