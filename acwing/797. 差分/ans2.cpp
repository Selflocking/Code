#include <iostream>

using namespace std;

const int mxN = 1e5 + 5;

int a[mxN];
int b[mxN];
int n;
int m;

void insert(int i, int j, int c) {
    b[i] += c;
    b[j + 1] -= c;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    // for (int i = 1; i <= n; ++i) {
    //     b[i] = a[i] - a[i - 1];
    // }

    // 构造差分数组也可以这样。
    /*
        想法是假设a数组全是0,则容易知道差分数组b也全是0;
        为了构造出a：比如a[1],相当于在1～1加上a[1],2~2全部加上a[2];
        故可以直接用insert();
    */
    for (int i = 1; i <= n; ++i) {
        insert(i, i, a[i]);
    }

    while (m--) {
        int l, r, c;
        cin >> l >> r >> c;
        insert(l, r, c);
    }

    for (int i = 1; i <= n; ++i) {
        b[i] += b[i - 1]; // 原地前缀和。
        cout << b[i] << " \n"[i == n];
    }

    return 0;
}