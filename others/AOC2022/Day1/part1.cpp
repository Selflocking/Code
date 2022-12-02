#include <iostream>
#include <string>

using namespace std;

int main() {
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    int ans = 0;
    int tmp = 0;
    string s;
    while (getline(cin, s)) {
        if (s.size() == 0) {
            ans = max(ans, tmp);
            tmp = 0;
        } else {
            tmp += stoi(s);
        }
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}