#include <iostream>

using namespace std;

char id[18];
int quan[18] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
char M[12] = "10X98765432";

int main() {
    int N;
    cin >> N;
    int count = 0;
    while (N--) {
        bool flag = 0;
        cin >> id;
        for (int i = 0; i < 17; ++i) {
            if (!isdigit(id[i])) {
                flag = 1;
                count++;
                cout << id << endl;
                break;
            }
        }
        if (flag) continue;

        int S = 0;
        for (int i = 0; i < 17; ++i) {
            S += (id[i] - '0') * quan[i];
        }
        if (M[S % 11] != id[17]) {
            count++;
            cout << id << endl;
        }
    }
    if (count == 0) cout << "All passed";
    return 0;
}