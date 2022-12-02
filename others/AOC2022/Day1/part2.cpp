#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> ans;

int main() {
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    // int ans = 0;
    int tmp = 0;
    string s;
    while (getline(cin, s)) {
        if (s.size() == 0) {
            // ans = max(ans, tmp);
            ans.emplace_back(tmp);
            tmp = 0;
        } else {
            tmp += stoi(s);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans[ans.size() - 1] + ans[ans.size() - 2] + ans[ans.size() - 3]
         << endl;
    // cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}