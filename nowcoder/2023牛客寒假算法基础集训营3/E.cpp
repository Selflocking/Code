#include <bits/stdc++.h>

using namespace std;
constexpr int mxN = 1e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b, c, d;
    cin >> a >> b >> c >> d;

    // M 为斜边上的中点，C为直角顶点
    // AM = (delta x, delta y)
    // MC = (delta y, - delta x)
    // AC = (delta x + delta y, delta y - delta x)

    long long dx = c - a;
    long long dy = d - b;

    long long cx = 2 * a + dx + dy;
    long long cy = 2 * b + dy - dx;

    if (cx % 2 == 1 || cy % 2 == 1) {
        cout << "No Answer!\n";
    } else {
        cout << cx / 2 << " " << cy / 2 << "\n";
    }
    return 0;
}
