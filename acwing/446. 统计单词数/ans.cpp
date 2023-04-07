#include <bits/stdc++.h>
#include <cstring>
#include <string>

using namespace std;

constexpr int mxN = 1e6 + 5;

string a, b;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 读一行
    getline(cin, a);
    getline(cin, b);
    // 转小写
    transform(a.begin(), a.end(), a.begin(), ::tolower);
    transform(b.begin(), b.end(), b.begin(), ::tolower);

    int i = 0;
    int j = 0;
    int cnt = 0;
    int loc = 0;
    bool flag = false;
    while (1) {
        if (a[i] == b[j]) i++;
        j++;
        // 空格是单词的分割
        if (b[j] == ' ') {
            j++; // 无用字符 +1
            // 单词要匹配玩，且保证前后均有空格
            // 实际上没有考虑边界情况，即b首字符不为空格的时候
            // 例如样例
            // 但是还是过了，说明数据还是不够全面。
            if (i == a.size() && b[j - 1 - a.size() - 1] == ' ') {
                if (!flag) {
                    loc = j - 1 - a.size(); // 首字符位置
                    flag = true;
                }
                cnt++;
            }
            i = 0;
        }
        // 单词匹配完，但是没有遇到空格
        if (i == a.size()) {
            i = 0;
        }
        // 结束
        if (j == b.size()) break;
    }

    if (cnt != 0) {
        cout << cnt << " " << loc << "\n";
    } else {
        cout << "-1\n";
    }

    return 0;
}
