#include <iostream>

using namespace std;

int main() {
    string name;
    double b, c;
    cin >> name >> b >> c;
    double total = b + c * 0.15;
    printf("TOTAL = R$ %.2f\n", total);
    return 0;
}
