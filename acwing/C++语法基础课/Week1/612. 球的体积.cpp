#include <iostream>

using namespace std;

const double PI = 3.14159;

int main() {
    int r = 0;
    cin >> r;
    double res = 4 / 3.0 * PI * r * r * r;
    printf("VOLUME = %.3f\n", res);
    return 0;
}
