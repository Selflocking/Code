#include <iostream>

using namespace std;

// A石头 B布 C剪刀
// X输 Y平局 Z赢
// 石头 1 分，布 2 分，剪刀 3 分
// 输了 0 分，平局 3 分，赢了 6 分

int score = 0;
int main() {
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    char a, b;
    while (cin >> a >> b) {
        if (a == 'A') { //石头
            if (b == 'X') {
                score += 0+3;
            } else if (b == 'Y') {
                score += 3+1;
            } else {
                score += 6+2;
            }
        } else if (a == 'B') { //布
            if (b == 'X') {
                score += 0+1;
            } else if (b == 'Y') {
                score += 3+2;
            } else {
                score += 6+3;
            }
        } else { //剪刀
            if (b == 'X') {
                score += 0+2;
            } else if (b == 'Y') {
                score += 3+3;
            } else {
                score += 6+1;
            }
        }
    }

    cout << score << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}