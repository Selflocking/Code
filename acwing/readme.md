# AcWing

## 0x3f3f3f3f
以前学长在教我们的时候说在写 dijkstra 可以这样表示无穷大：

```cpp
constexpr int INF = 0x3f3f3f3f;
```

容易得知 0x3f3f3f3f 的二进制表示为0011 1111 0011 1111 0011 1111 0011 1111。

而 int 的最大值应该为 0x7fffffff，即 0111 1111 1111 1111 1111 1111 1111

为什么不用 0x7fffffff 呢。

学长通常使用 memset 初始化数组，如下：

```cpp
memset(dist, 0x3f3f3f3f, sizeof dist);
```

memset 是按字节初始化内存的，上面的代码等同于：

```cpp
memset(dist, 0x3f, sizeof dist);
```

即取最低的字节初始化内存。这样很容易导致问题，例如：

```cpp
memset(dist, 5, sizeof dist);
```

我们想要的是将每一个元素初始化为5。可得到的结果确实84215045。这是因为5的最低字节为0000 0101, 故将每个数初始化为了 0x05050505。

而对于 0x3f3f3f3f 来说则没有这个问题。同理还有 0x0f0f0f0f, 0x7f7f7f7f等等。

使用 0x3f3f3f3f 还有一个好处就是两个 0x3f3f3f3f 相加不会爆 int。

为了减少错误，推荐使用更好用的 std::fill 和 std::fill_n :

```cpp
    fill(dist, dist + mxN, INF);
    fill_n(dist, mxN, INF);
```
