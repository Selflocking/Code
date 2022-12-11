#include <bits/stdc++.h>
using namespace std;

void fun(char ch) {
    switch (ch) {
        case '-':
            cout << "fu";
            break;
        case '1':
            cout << "yi";
            break;
        case '2':
            cout << "er";
            break;
        case '3':
            cout << "san";
            break;
        case '4':
            cout << "si";
            break;
        case '5':
            cout << "wu";
            break;
        case '6':
            cout << "liu";
            break;
        case '7':
            cout << "qi";
            break;
        case '8':
            cout << "ba";
            break;
        case '9':
            cout << "jiu";
            break;
        case '0':
            cout << "ling";
            break;
    }
}

int main() {
    char s[20];
    cin >> s;
    int len = strlen(s);
    for (int i = 0; i < len - 1; ++i) {
        fun(s[i]);
        cout << " ";
    }
    fun(s[len - 1]);
    return 0;
}