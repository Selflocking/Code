#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int y, m, d;
    scanf("%d-%d-%d", &m, &d, &y);
    printf("%d-%02d-%02d", y, m, d);
    return 0;
}