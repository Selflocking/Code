#include <iostream>
using namespace std;

// 注意:是四舍五入取整.
int main() {
    int n;
    char ch;
    cin >> n >> ch;
    int ban;
    if (1.0 * n / 2 - n / 2 < 0.5)
        ban = n / 2;
    else
        ban = n / 2 + 1;
    for (int i = 0; i < ban; i++) {
        for (int j = 0; j < n; ++j) cout << ch;
        cout << endl;
    }
    return 0;
}