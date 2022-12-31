#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int mx1 = 0, mx2 = 0;
        int n;
        cin >> n;
        while (n--) {
            int temp;
            cin >> temp;
            if (mx1 < temp)
                swap(mx1, temp);
            if (mx2 < temp)
                swap(mx2, temp);
        }

        if (mx1 - mx2 > 1)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}