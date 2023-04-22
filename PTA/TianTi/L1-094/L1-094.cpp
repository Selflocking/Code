#include <bits/stdc++.h>

using namespace std;

/*
考试的时候在这道题上花了太多的时间。导致后面都没怎么看。
题目也有点没说清楚。
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int T;
    cin >> T;
    while (T--) {
        int a, b;
        cin >> a >> b;

        string c, d;
        cin >> c >> d;

        string x = s.substr(a - 1, b - a + 1);
        // 考试的时候以为 substr 是截取从 [a,b) 的字符串，写完一交错了才知道
        // 果然没有智能提示，没有文档就不好写了。
        s.erase(a - 1, b - a + 1);
        /*
        考试的时候不知道有 erase , 所以是手动拼接：
        string tt = s.substr(0, a - 1);
        tt += s.substr(b);
        s = tt;
        这些下标想了好久。
        */
        auto it = s.find(c + d);
        /*
        题目说：
        对于上面操作后的结果（cde），给定插入位置前为 bf，插入位置后为 g，则插入后变为 abfcdeg

        我最开始以为是先找到 bf 的位置，再找到 g 的位置，然后不管这两者之间有多长，让中间变成 cde.
        de了半天才知道是说 df 要和 g 紧挨在一起，即要找到 bfg 的位置，然后在 bf 和 g 之间插入。
        这道题 debug 又特别花时间，所以浪费了很多时间
        */
        if (it == string::npos) {
            // 用 devc++ 写的时候也不知道find找不到返回什么。所以开始写的是：
            // if (it >= s.size()) {
            s += x;
            continue;
        }
        it += c.size() - 1;
        s.insert(it + 1, x);
        /*
        考试的时候这样写的：
        string tt = s.substr(0, it + 1);
        tt += x;
        tt += s.substr(it + 1);
        s = tt;
        */
    }

    cout << s << "\n";
    return 0;
}
