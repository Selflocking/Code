# 双指针

题目要求连续不重复最长区间长度。

例如

```text
1 2 2 3 5
```

答案应该是3；

原理是维护两个指针：l,r;
初始位置都是0,右指针先移动，同时需要有一个记录是否重复的东西，数组也行，map也行。
当遇到重复的数字时，让左指针向右移动，直到不再有重复的数字时;

同时，右指针每移动一次，都要计算一次最大长度。

