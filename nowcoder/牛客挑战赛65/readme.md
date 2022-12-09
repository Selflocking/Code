# [牛客挑战赛65](https://ac.nowcoder.com/acm/contest/48458)

## [A 233的字符串](https://ac.nowcoder.com/acm/contest/48458/A)

只做出来A题🥲。

找规律
abc             0       0
abcabc          1       1
abcabcabc       4       1 + 2 + 1
abcabcabcabc    10      4 + 3 + 2 + 1

比如看abcabcabcabc，这样看：abc abcabcabc。首先后半段是4,加上前半段后需要加上3+2+1。
此时规律已经很明显。

即假设S[i]为前i个正整数的和，给一个正整数n,求前n个S[i]的和, 1<=i<=n。

C++写了好几次，不是超时就是超范围。问了别人才找到通项：https://oeis.org/A000292。
即(n-1)\*n\*(n+1)/6

就这样用python还写错几次，因为之前没怎么用过python

第一次是这样写的：
```python
n = int(input());
print(((n-1)*n*(n+1)/6)%1000000007)
```
运行发现输出会带.0。问了下同学说可以之间使用int()先转换成整数再输出。

看着没什么问题，但是报答案错误，一度以为自己想错了。

后来将除改成整除才过。仔细想想应该是超过python的浮点数精度了。

```python
n = int(input());
print(((n-1)*n*(n+1)//6)%1000000007)
```