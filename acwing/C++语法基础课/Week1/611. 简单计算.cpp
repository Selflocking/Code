#include <iostream>

using namespace std;

int main() {
    int a1, b1;
    double c1;
    int a2, b2;
    double c2;
    cin >> a1 >> b1 >> c1;
    cin >> a2 >> b2 >> c2;
    double res = b1 * c1 + b2 * c2;
    printf("VALOR A PAGAR: R$ %.2f\n", res);

    return 0;
}
