#include <iostream>

using namespace std;

const double PI = 3.14159;

int main() {
    double a, b, c;
    cin >> a >> b >> c;
    printf("TRIANGULO: %.3f\n", a * c / 2);
    printf("CIRCULO: %.3f\n", PI * c * c);
    printf("TRAPEZIO: %.3f\n", (a + b) * c / 2);
    printf("QUADRADO: %.3f\n", b * b);
    printf("RETANGULO: %.3f\n", a * b);
    return 0;
}
