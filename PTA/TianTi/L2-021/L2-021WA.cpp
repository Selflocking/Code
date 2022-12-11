#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

struct peo {
    string name;
    set<int> s;
    double ave;
};

bool cmp(peo a, peo b) {
    if (a.s.size() != b.s.size())
        return a.s.size() > b.s.size();
    else
        return a.ave < b.ave;
}
vector<peo> v;
int main() {
    int n;
    cin >> n;
    v.resize(n + 1);
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> v[i].name >> k;
        v[i].ave = 0;
        while (k--) {
            int t;
            cin >> t;
            v[i].ave += !v[i].s.insert(t).second;
        }
        v[i].ave = (v[i].ave + v[i].s.size()) / v[i].s.size();
    }
    sort(v.begin(), v.end(), cmp);

    cout << v[0].name;
    if (v.size() >= 3) {
        cout << " " << v[1].name << " " << v[2].name;
    } else if (v.size() == 2) {
        cout << " " << v[1].name << " -";
    } else {
        cout << " - -";
    }
    return 0;
}