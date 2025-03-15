# 笔试

## 3

如果 a 是 b 的倍数，则 f(a,b)=1,否则 f(a,b)=0;

给你四个整数 l1,r1,l2,r2，求

$$
\sum_{i=l1}^{r1}\sum_{j=l2}^{r2}f(i,j)
$$

其中：

$$
1<= l1 <=r1 <=1e6 \\
1<= l2 <=r2 <=1e9
$$

想法错了，一直是正着求的，会超时，最多 25%。尝试使用 hashmap 记录结果，推导后面的结果，可是不行。

```cpp
// 暴力版本
int main() {
    int l1, r1, l2, r2;
    scanf("%d %d %d %d", &l1, &r1, &l2, &r2);
    int ans = 0;
    for (int i = l1; i <= r1; i++) {
        if (i < l2) {
            continue;
        }
        int up = min(i, r2);
        for (int j = l2; j <= up; ++j) {
            ans += (i % j == 0);
        }
    }
    cout << ans << "\n";
    return 0;
}
```

做完后就问了 ai,发现要反着求，具体来说，看[l1,r1]中有多少个数是[l2,r2]中数字的倍数。上面那个是求[l2,r2]中有多少个数是[l1,r1]中数字的因数。

具体来说：

求解`3 4 1 2`, 1 的倍数有 3,4;2 的倍数有 4。

在[1,4]中，1 的倍数有 $\lfloor {4/1} \rfloor = 4$ 个

在[1,3)中， 1 的倍数有$\lfloor \frac{3-1}{1} \rfloor = 2$ 个

故，在[3,4]中，1 的倍数有 2 个。同理，2 的倍数有 2 - 1 = 1 个。

这样就能求解了。

```cpp
int main() {
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    long long ans = 0;
    for (int i = l2; i <= min(r1, r2); ++i) {
        ans += r1 / i - (l1 - 1) / i;
    }
    cout << ans << "\n";
    return 0;
}
```

这样看还挺简单的。
