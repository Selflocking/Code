#include <cmath>
#include <iostream>

using namespace std;

/*
1 2 3 0
4 5 6 1
7 8 9 2
*/

// 0 1 2

bool map[4][4];

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                map[i][j] = false;
            }
        }
        int tmp = s[0] - '0' - 1;
        map[tmp / 3][tmp % 3] = true;
        bool flag = true;
        for (int i = 1; i < s.size(); ++i) {
            int last = s[i - 1] - '0' - 1;
            int tmp = s[i] - '0' - 1;

            if (map[tmp / 3][tmp % 3]) {
                flag = false;
                break;
            } else {
                map[tmp / 3][tmp % 3] = true;
            }
            if ((tmp / 3 - last / 3 > 1 || tmp / 3 - last / 3 < -1) &&
                tmp % 3 == last % 3) {
                if (map[(tmp / 3 + last / 3) / 2][tmp % 3] == false) {
                    flag = false;
                    break;
                }
            }
            // cout<<tmp/3-last/3<<" "<<tmp % 3   - last % 3  <<"\n";
            if ((tmp / 3 - last / 3 > 1 || tmp / 3 - last / 3 < -1) &&
                (tmp % 3 - last % 3 > 1 || tmp % 3 - last % 3 < -1)) {
                if (map[1][1] == false) {
                    flag = false;
                    break;
                }
            }
            if ((tmp / 3 == last / 3) &&
                (tmp % 3 - last % 3 > 1 || tmp % 3 - last % 3 < -1)) {
                if (map[tmp / 3][(tmp % 3 + last % 3) / 2] == false) {
                    flag = false;
                    break;
                }
            }
        }
        if (flag) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}