#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

constexpr int mxN = 1e5 + 5;

int fa[mxN];

int find(int x) {
    if (x == fa[x])
        return x;
    else
        return fa[x] = find(fa[x]);
}

void megra(int a, int b) {
    fa[find(a)] = find(b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i <= mxN - 1; ++i) {
        fa[i] = i;
    }

    int n, m;
    cin >> n >> m;
    while (m--) {
        char ch;
        int a, b;
        cin >> ch >> a >> b;
        if (ch == 'M') {
            megra(a, b);
        } else {
            if (find(a) != find(b)) {
                cout << "No\n";
            } else {
                cout << "Yes\n";
            }
        }
    }

    return 0;
}
