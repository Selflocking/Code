#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    int h, m;
    scanf("%d:%d", &h, &m);
    if (h < 12 || h == 12 && m == 0)
        printf("Only %02d:%02d.  Too early to Dang.", h, m);
    else {
        h -= 12;
        if (m) h++;
        for (int i = 0; i < h; ++i) {
            cout << "Dang";
        }
    }
    return 0;
}
