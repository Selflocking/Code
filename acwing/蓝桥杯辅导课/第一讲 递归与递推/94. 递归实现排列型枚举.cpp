#include <iostream>
#include <vector>

using namespace std;

const int mxN = 15;

int n;
vector<int> way(mxN);
vector<bool> state(mxN);

void print() {
    for (int i = 1; i <= n; ++i) {
        cout << way[i] << " ";
    }
    cout << endl;
}

void dfs(int x) {
    if (x > n) {
        print();
    }

    for (int i = 1; i <= n; ++i) {
        if (!state[i]) {
            way[x] = i;
            state[i] = true;
            dfs(x + 1);
            way[x] = 0;
            state[i] = false;
        }
    }
}

int main() {
    cin >> n;
    dfs(1);
    return 0;
}
