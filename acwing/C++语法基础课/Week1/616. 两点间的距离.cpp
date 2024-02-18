#include <cmath>
#include <iostream>

using namespace std;

int main() {
    double x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    double res = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    printf("%.4f\n", res);
    return 0;
}
