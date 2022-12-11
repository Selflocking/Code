#include <iostream>
#include <vector>
using namespace std;
const int N = 1e5 + 10;
bool vis[N];
vector<int> q;
int main() {
    int cnt = 0;
    int n;
    cin >> n;
    q.resize(n + 1);
    for (int i = 1; i <= n; ++i) cin >> q[i];
    int i;
    for (i = 1; i <= n; ++i) {
        int mi = 1e5 + 10;
        for (int j = i; j <= n; ++j) {
            if (vis[j] == 0 && q[j] < mi) {
                vis[j] = 1;
                mi = q[j];
                cnt++;
            }
        }
        if (cnt == n) break;
    }
    cout << i;
    return 0;
}