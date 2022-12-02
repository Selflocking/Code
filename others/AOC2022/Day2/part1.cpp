#include <iostream>

using namespace std;

// A石头 B布 C剪刀
// X石头 Y布 Z剪刀
// 石头 1 分，布 2 分，剪刀 3 分
// 输了 0 分，平局 3 分，赢了 6 分

int score = 0;
int main() {
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    char a, b;
    while (cin >> a >> b) {
        if (a == 'A') {
            if (b == 'X') {
                score += 1 + 3;
            } else if (b == 'Y') {
                score += 2 + 6;
            } else {
                score += 3 + 0;
            }
        } else if (a == 'B') {
            if (b == 'X') {
                score += 1 + 0;
            } else if (b == 'Y') {
                score += 2 + 3;
            } else {
                score += 3 + 6;
            }
        } else {
            if (b == 'X') {
                score += 1 + 6;
            } else if (b == 'Y') {
                score += 2 + 0;
            } else {
                score += 3 + 3;
            }
        }
    }

    cout << score << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}