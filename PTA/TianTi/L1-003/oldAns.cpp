#include <cstring>
#include <iostream>
using namespace std;

int count[10];
char ori[1005];

int main() {
    scanf("%s", ori);

    for (auto i : count) count[i] = 0;

    for (int i = 0; i < strlen(ori); ++i) count[ori[i]-48]++;

    for (int i = 0; i < 10; ++i) {
        if (count[i] != 0) cout << i << ":" << count[i] << endl;
    }

    return 0;
}
