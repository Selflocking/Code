#include <cstring>
#include <iostream>
using namespace std;

int book[10];         //标记此数出现过没有
int arr[11], len = 0; // arr,len为长度
int idx[11];          // index
int main() {
    string s;
    cin >> s;
    //初始化
    memset(book, 0, sizeof book);
    //标记出现过的数
    for (int i = 0; i < 11; ++i) {
        book[s[i] - '0'] = 1;
    }
    //倒序放到arr里
    for (int i = 9; i >= 0; --i) {
        if (book[i]) {
            arr[len++] = i;
        }
    }
    //输出arr,先输出一个,以后的输出','+数字
    cout << "int[] arr = new int[]{";
    cout << arr[0];
    for (int i = 1; i < len; ++i) {
        cout << ',' << arr[i];
    }
    cout << "};\n";

    //遍历arr制造index
    for (int i = 0; i < 11; ++i) {
        for (int j = 0; j < len; ++j) {
            if (arr[j] == s[i] - '0') {
                idx[i] = j;
                break;
            }
        }
    }

    //输出index
    cout << "int[] index = new int[]{";
    cout << idx[0];
    for (int i = 1; i < 11; ++i) {
        cout << "," << idx[i];
    }
    cout << "};";
    return 0;
}