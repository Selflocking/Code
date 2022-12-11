#include <iostream>
#include <set>
#include<string>
using namespace std;
set<string> ugly, book;
// set<int> ugly, book;
int main() {
    int N, M;
    cin >> N;
    while (N--) {
        int n;
        cin >> n;
        // int t;
        string t;
        if (n == 1) {
            cin >> t;
            continue;
        }
        while (n--) {
            cin >> t;
            ugly.insert(t);
        }
    }
    
    cin >> M;
    bool flag = 1;
    while (M--) {
        // int t;
        string t;
        cin >> t;
        if (ugly.find(t) == ugly.end() && book.find(t) == book.end()) {
            if (flag == 0) cout << " ";
            cout << t;
            book.insert(t);
            flag = 0;
        }
    }

    if (flag) cout << "No one is handsome";
    return 0;
}