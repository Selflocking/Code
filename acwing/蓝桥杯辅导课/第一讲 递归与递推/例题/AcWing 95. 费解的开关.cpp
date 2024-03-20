#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int n;
char arr[6][6];  // 输入的内容
char oprt[6][6]; // 每次操作的内容
int dx[5] = {-1, 0, 1, 0, 0};
int dy[5] = {0, 1, 0, -1, 0};

void turn(int x, int y) {
    for (int i = 0; i < 5; ++i) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx < 0 || xx >= 5 || yy < 0 || yy >= 5) continue;

        if (oprt[xx][yy] == '1')
            oprt[xx][yy] = '0';
        else
            oprt[xx][yy] = '1';
    }
}

bool is_all_on() {
    for (int i = 0; i < 5; ++i) {
        if (oprt[4][i] == '0') {
            return false;
        }
    }
    return true;
}

void solve() {
    int ans = 7;
    int step = 0;
    // 枚举第一行可行的所有操作
    // 更改完第一行后，第二行的操作必须将第一行的0更改为1,故第二行操作确定
    // 故确定下第一行操作后，接下来的操作也就确定了。
    // 找出可行的并且步数最小的即可。
    for (int op = 0; op < 32; ++op) {
        memcpy(oprt, arr, sizeof(arr));
        step = 0;
        for (int i = 0; i < 5; ++i) {
            if (op >> i & 1) {
                turn(0, i);
                step++;
            }
        }

        for (int i = 1; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                if (oprt[i - 1][j] == '0') {
                    turn(i, j);
                    step++;
                }
            }
        }

        // cout<<oprt[4]<<"\n";
        if (is_all_on()) {
            ans = min(ans, step);
        }
    }
    if (ans > 6)
        cout << -1 << endl;
    else
        cout << ans << endl;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin >> arr[j];
        }
        solve();
    }
    return 0;
}