#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

constexpr int mxN = 1e5 + 5;

int fa[mxN];
int Size[mxN];

int find(int x) {
    if (x == fa[x])
        return x;
    else
        return fa[x] = find(fa[x]);
}

void megra(int a, int b) {
    int x = find(a);
    int y = find(b);
    if (x == y) return;
    fa[x] = y;
    Size[y] += Size[x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
        Size[i] = 1;
    }

    while (m--) {
        string s;
        int a, b;
        cin >> s;

        if (s[0] == 'C') {
            cin >> a >> b;
            megra(a, b);
        } else if (s[1] == '1') {
            cin >> a >> b;
            if (find(a) != find(b)) {
                cout << "No\n";
            } else {
                cout << "Yes\n";
            }
        } else {
            cin >> a;
            cout << Size[find(a)] << "\n";
        }
    }

    return 0;
}
