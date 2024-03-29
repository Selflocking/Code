# 团体程序设计天体赛

## L1-001

直接 cout 即可

## L1-002

先求出第一行需要多少个符号。

如下：

```
k = 17个:
*****
 ***
  *
 ***
*****

k+1:
*****
 ***
  *
  *
 ***
*****

(k+1)/2
*****
 ***
  *
```

容易得知 1 + 3 + 5 + 7 + 9 + ... + 2k-1 = k^2

故最上面一行的长度为：

一半的层数为：

```cpp
int t = sqrt((n+1)/2);
```

最上面一层的长度为：

```cpp
int k = 2 * t - 1;
```

剩余的符号数量为：

```cpp
int ans = n - (t * t * 2 - 1);
```

接着模拟即可

[最终答案](./L1-002/L1-002.cpp)

## L1-003

简单，直接使用string存储数字，遍历每一位，使用map存储结果或者使用一个10位长度的数组也可以

[最终答案](./L1-003/L1-003.cpp)

## L1-004

[最终答案](./L1-004/L1-004.cpp)

## L1-005



## L1-006
## L1-007
## L1-008
## L1-009
## L1-010
## L1-011
## L1-012
## L1-013
## L1-014
## L1-015
## L1-016
## L1-017
## L1-018
## L1-019
## L1-020
## L1-021
## L1-022
## L1-023
## L1-024
## L1-025
## L1-026
## L1-027
## L1-028
## L1-029
## L1-030
## L1-031
## L1-032
## L1-033
## L1-034
## L1-035
## L1-036
## L1-037
## L1-038
## L1-039
## L1-040
