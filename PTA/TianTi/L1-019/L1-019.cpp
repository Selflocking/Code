#include <iostream>

using namespace std;

int main() {
    int A, AJ = 0, B, BJ = 0;
    cin>>A>>B;
    int N;
    cin >> N;
    int a, b, c, d;
    while (N--) {
        cin >> a >> b >> c >> d;
        
        if (b == (a + c) && d != b) AJ++;
        if (d == (a + c) && b != d) BJ++;

        if (AJ > A) {
            cout << "A" << endl << BJ;
            break;
        }
        if (BJ > B) {
            cout << "B" << endl << AJ;
            break;
        }
    }

    return 0;
}