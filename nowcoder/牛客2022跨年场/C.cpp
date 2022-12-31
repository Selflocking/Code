#include <bits/stdc++.h>
#include <shared_mutex>
#include <string>

using namespace std;
constexpr int mxN = 1e5 + 5;
constexpr int MOD = 1e9 + 7;

bool nums[10];
long long sum = 0;
vector<int> arr;
string s;
long long cnt = 0;

void fun(int x, int y) {
    if (x == y) {
        string tmp = s;
        int top = 0;
        for (auto &it : tmp) {
            if (it == '?') {
                it = arr[top] + '0';
                top++;
            }
        }
        long long t = stoll(tmp + tmp);
        sum += t % 7;
        sum %= MOD;
        cnt++;
    } else {
        for (int i = x; i <= y; ++i) {
            swap(arr[i], arr[x]);
            fun(x + 1, y);
            swap(arr[i], arr[x]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s;
    for (auto &it : s) {
        if (it != '?') {
            nums[it - '0'] = 1;
        }
    }
    for (int i = 1; i < 10; ++i) {
        if (nums[i] == 0) {
            arr.push_back(i);
        }
    }
    fun(0, arr.size() - 1);
    if (cnt == 0) {
        long long t = stoll(s+s);
        cout<<t%7<<"\n";
    } else {
        cout << sum / cnt % MOD << "\n";
    }
    return 0;
}
