#include <algorithm>
#include <bits/stdc++.h>
#include <cctype>
#include <fstream>
#include <iostream>
#include <unordered_map>

using namespace std;

auto NumToString = unordered_map<int, string>{
    {1, "one"}, {2, "two"},   {3, "three"}, {4, "four"}, {5, "five"},
    {6, "six"}, {7, "seven"}, {8, "eight"}, {9, "nine"}};

class Num {
  public:
    bool used = false;
    string::size_type loc = 0;
    int value = -1;
    bool operator<(const Num &other) const {
        return this->loc < other.loc;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fstream in;
    // in.open("example2.txt");
    in.open("input.txt");
    if (!in.is_open()) {
        exit(-1);
    }

    int ans = 0;
    while (!in.eof()) {
        string s;
        in >> s;
        Num first;
        Num last;
        for (string::size_type i = 0; i < s.size(); ++i) {
            auto &c = s[i];
            if (c >= '0' && c <= '9') {
                Num value{true, i, c - '0'};
                if (!first.used) {
                    first = value;
                }
                last = value;
            }
        }

        for (auto [n, str] : NumToString) {
            auto loc = s.find(str);
            if (loc != string::npos) {
                Num value{true, loc, n};
                if (!first.used) {
                    first = value;
                } else {
                    first = min(first, value);
                }
            }
        }

        reverse(s.begin(), s.end());
        for (auto [n, str] : NumToString) {
            reverse(str.begin(), str.end());
            auto loc = s.find(str);
            if (loc != string::npos) {
                Num value{true, s.size() - loc - str.size(), n};
                if (!last.used) {
                    last = value;
                } else {
                    last = max(last, value);
                }
            }
        }

        if (!first.used || !last.used) {
            cerr << "error";
        }

        auto add = first.value * 10 + last.value;
        ans += add;
    }
    cout << ans << endl;
    return 0;
}
