#include <iostream>

using namespace std;

string s;
int loc;
int loc2;
bool checkUserName() {
    for (int i = 0; i < (int)s.size(); ++i) {
        if (s[i] == '@') {
            loc = i;
            break;
        }
        // 大小写字母，数字或者下划线组成
        if (!((s[i] <= 'z' && s[i] >= 'a') || (s[i] <= 'Z' && s[i] >= 'A') ||
              s[i] == '_' || (s[i] >= '0' && s[i] <= '9'))) {
            return false;
        }
    }
    if (loc == 0 || loc > 16) {
        return false;
    } //必须有@，必须有username， 必须长度小于等于16,大于等于1
    return true;
}
bool checkHostName() {
    int dot = 0;
    for (int i = loc + 1; i < (int)s.size(); ++i) {
        if (s[i] == '/') {
            loc2 = i;
            break;
        }
        if (s[i] == '.') {
            if (dot == 0) {
                if (i - loc - 1 > 16)
                    return false; //每个单词长度不能超过16
                if (i - loc == 1)
                    return false; //不能 ..
            } else {
                if (i - dot - 1 > 16)
                    return false; //每个单词长度不能超过16
                if (i - dot == 1)
                    return false; //不能 ..
            }
            dot = i;
            continue;
        }
        if (!((s[i] <= 'z' && s[i] >= 'a') || (s[i] <= 'Z' && s[i] >= 'A') ||
              s[i] == '_' || (s[i] >= '0' && s[i] <= '9'))) {
            return false;
        }
    }
    // if (dot == 0) return false;  //必须有点
    if ((int)s.size() - dot == 1)
        return false; //点不能在末尾
    if (loc2 - dot == 1)
        return false; //点不能在 / 前
    //如果没有resource,要保证总长度不能超过32, 同时不能是类似与 a@ 这样的字符串
    if (loc2 == 0 && (int)s.size() - loc - 1 > 32 || (int)s.size() - loc == 1)
        return false;
    else if (loc2 - loc - 1 > 32) // / 和 @ 之间不能超过32个字符
        return false;
    return true;
}
bool checkResource() {
    if (loc2 == 0)
        return true; //如果没有 / 证明没有resource.
    // cout<<(int)s.size() - 1 - loc2;
    if (loc2 == s.size() - 1)
        return false; //如果以 / 结尾
    if ((int)s.size() - 1 - loc2 > 16)
        return false; //如果超过 16

    for (int i = loc2 + 1; i < (int)s.size(); ++i) {
        if (!((s[i] <= 'z' && s[i] >= 'a') || (s[i] <= 'Z' && s[i] >= 'A') ||
              s[i] == '_' || (s[i] >= '0' && s[i] <= '9'))) {
            return false;
        }
    }

    return true;
}

int main() {
    cin >> s;

    if (!checkUserName()) {
        cout << "NO";
        return 0;
    }
    if (!checkHostName()) {
        cout << "NO";
        return 0;
    }
    if (!checkResource()) {
        cout << "NO";
        return 0;
    }
    cout << "YES";
    return 0;
}
