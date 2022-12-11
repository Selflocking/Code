#include <cstring>
#include <iostream>
#include<cstdio>
using namespace std;

char num[55];

int main() {
    //倍数要用double.....
    double B = 1;
    cin>>num;
    int len = strlen(num);

    double count = 0;
    for (int i = 0; i < len; ++i) {
        if (num[i] == '2') count++;
    }
    if ((num[len - 1] - '0') % 2 == 0) B *= 2;
    if (num[0] == '-') {
        len -= 1;
        B *= 1.5;
    }
    // print '%' need use %%
    printf("%.2lf%%", count /len * B * 100 );
    return 0;
}