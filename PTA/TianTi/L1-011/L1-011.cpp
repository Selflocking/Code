#include <cstring>
#include <iostream>
#include <string>
using namespace std;
constexpr int mxN = 10005;

char A[mxN];
char B[mxN];

int main() {
    // freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
    cin.getline(A, mxN);
    cin.getline(B, mxN);
    int len = strlen(A);

    for (char *pb = B; *pb; pb++) {
        for (char *pa = A; pa != &A[len]; pa++) {
            if (*pa == *pb) *pa = 0;
        }
    }
    for (int i = 0; i < len; ++i) {
        // cout << A[i];
        //加上if(A[i])才正确,奇了怪了
        if (A[i]) cout << A[i];
    }
    return 0;
}