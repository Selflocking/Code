#include <cstring>
#include <iostream>

using namespace std;

int main() {
    int n;
    char ch;
    string s;
    cin >> n >> ch;
    //好像是因为末尾空格,getchar()一下
    getchar();

    getline(cin,s);
    if (s.length() <= n) {
        for (int i = 0; i < n - s.length(); ++i) {
            cout << ch;
        }
        cout << s;
    } else {
        for (int i = s.length() - n; i < s.length(); ++i) {
            cout << s[i];
        }
    }

    return 0;
    
}