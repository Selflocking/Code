#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

constexpr int mxN = 1e3 + 5;

int n, v;
int V[mxN], W[mxN];
int f[mxN];

int main() {
    cin >> n >> v;
    for (int i = 1; i <= n; ++i) {
        cin >> V[i] >> W[i];
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = v; j >= V[i]; --j) {
            f[j] = max(f[j], f[j - V[i]] + W[i]);
        }
    }

    /*
    为什么for (int j = v; j >= V[i]; --j)：
    因为我们的f[i][j]只需要关注f[i-i]层
    可以将二维压缩成一维，即将：
    # # # # # # # #
    # # # # # # # #
    # # $ # # $ # #
    # # # # # $ # #
    变为：
    # # # # # $ # #
    这个 $ 代表我们当前考虑的状态。看二维图，例如我们计算f[4][6]需要考虑f[3][6]和f[3][3].
    由于我们关注的是f[i][j-V[i]]，即前面的状态，如果我们从前往后遍历，就会将旧的状态（即上一层）覆盖掉。
    故需从后往前遍历
    */

    cout << f[v];
    return 0;
}
