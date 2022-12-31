#include "cstring"
#include "iostream"
#include "memory"

/**
2
0 1 1 0 1 0
1 0 0 1 1 1
0 0 1 0 0 1
1 0 0 1 0 1
0 1 1 1 0 0
0 0 1 0 1 0
1 0 1 0 1 1
0 0 1 0 1 1
1 0 1 1 0 0
0 1 0 1 0 0
Sample Output
PUZZLE #1
1 0 1 0 0 1
1 1 0 1 0 1
0 0 1 0 1 1
1 0 0 1 0 0
0 1 0 0 0 0
PUZZLE #2
1 0 0 1 1 1
1 1 0 0 0 0
0 0 0 1 0 0
1 1 0 1 0 1
1 0 1 1 0 1
 */
using namespace std;
char oriLights[5];
char lights[5];
char result[5];

int getBit(char c, int i) { return (c >> i) & 1; }

void setBit(char &c, int i, int v) {
    if (v)
        c |= (1 << i);
    else
        c &= ~(1 << i);
}

void filpBit(char &c, int i) { c ^= (1 << i); }

void outPutResult(int t, char result[]) {
    // cout << "PUZZLE #" << t << endl;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 6; ++j) {
            cout << getBit(result[i], j);
            if (j < 5)
                cout << " ";
        }
        cout << endl;
    }
}

int main() {
    int T = 1;
    // cin >> T;
    for (int t = 1; t <= T; ++t) {
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 6; ++j) {
                int s;
                cin >> s;
                setBit(oriLights[i], j, s);
            }
        }
        for (int n = 0; n < 64; ++n) {
            int switches = n;
            memcpy(lights, oriLights, sizeof(oriLights));
            for (int i = 0; i < 5; ++i) {
                result[i] = switches;
                for (int j = 0; j < 6; ++j) {
                    if (getBit(switches, j)) {
                        if (j > 0)
                            filpBit(lights[i], j - 1);
                        filpBit(lights[i], j);
                        if (j < 5)
                            filpBit(lights[i], j + 1);
                    }
                }
                if (i < 4)
                    lights[i + 1] ^= switches;
                switches = lights[i];
            }
            if (lights[4] == 0) {
                outPutResult(t, result);
                break;
            }
        }
    }
}