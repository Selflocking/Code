#include <iostream>
#include <map>
#include <set>
using namespace std;

set<string> S;
map<string, int> M;
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string t;
        cin >> t;
        S.insert(t);
    }
    int m;
    cin >> m;
    double sum = 0;
    for (int i = 0; i < m; ++i) {
        string t;
        int zan;
        cin >> t >> zan;
        sum += zan;
        M.insert({t, zan});
    }
    double avr = sum / m;
    int flag = 1;
    for (auto i : M) {
        if (i.second > avr && S.find(i.first) == S.end()) {
            flag = 0;
            cout << i.first << "\n";
        }
    }
    if (flag)
        cout << "Bing Mei You";
    return 0;
}