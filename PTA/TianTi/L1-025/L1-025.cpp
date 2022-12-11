#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    //输入
    getline(cin, s);
    //用来标记空格的位置
    int flag;
    //用来标记这两个数是否合法
    bool A = 1, B = 1;
    //遍历查找第一个空格位置
    for (flag = 0; flag < s.length(); ++flag) {
        if (s[flag] == ' ') break;
    }
    //判断前半段是否全为数字
    for (int i = 0; i < flag; ++i) {
        if (!isdigit(s[i])) A = 0;
    }
    //判断后半段是否全为数字
    for (int i = flag + 1; i < s.length(); ++i) {
        if (!isdigit(s[i])) B = 0;
    }

    //用来存储这两个数字
    int AN = 0, BN = 0;
    //文本转数字
    if (A) {
        for (int i = 0; i < flag; ++i) {
            AN *= 10;
            AN += (s[i] - '0');
        }
    }
    if (B) {
        for (int i = flag + 1; i < s.length(); ++i) {
            BN *= 10;
            BN += (s[i] - '0');
        }
    }
    //判断这个数字是否在给定的范围内,开始我觉得可以省略<1;后来想了想<1的正整数不就是0吗;
    if (AN > 1000 || AN < 1) A = 0;
    if (BN > 1000 || BN < 1) B = 0;

    //按照要求输出
    if (A)  cout << AN;
    else    cout << '?';
    cout << " + ";
    if (B)  cout << BN;
    else    cout << '?';
    cout << " = ";
    if (A && B) cout << AN + BN;
    else    cout << '?';

    return 0;
}