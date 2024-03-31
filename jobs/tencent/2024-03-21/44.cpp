#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

constexpr int mxN = 405;
vector<int> arr(mxN);
vector<vector<int>> ress(mxN);

int n, kk;
void init() {
    for (auto &v : ress) {
        v.resize(mxN);
    }
    for (int i = 0; i < n; ++i) {
        int curr = 0;
        int j = i;
        while (j != n) {
            curr ^= arr[j];
            ress[i][j] = curr;
            j++;
        }
    }
}

int main() {
    cin >> n >> kk;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    init();

    return 0;
}
