#include <iostream>
#include <vector>

using namespace std;

const int mxN = 50;

vector<int> ans(mxN);

void cacl() {
    ans[0] = 0;
    ans[1] = 1;
    for (int i = 2; i < mxN; ++i) {
        ans[i] = ans[i - 1] + ans[i - 2];
    }
}

int main() {
    cacl();

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
