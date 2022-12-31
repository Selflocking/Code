#include <cstring>
#include <iostream>
using namespace std;

char Left[3][7];   //记录左边
char Right[3][7];  //记录右边
char Result[3][5]; //记录结果

bool isFake(char ch, bool light);

int main() {
    int T;
    cin >> T;
    while (T--) {
        //数组初始化
        memset(Left, 0, sizeof Left);
        memset(Right, 0, sizeof Right);
        memset(Result, 0, sizeof Result);
        for (int i = 0; i < 3; ++i)
            cin >> Left[i] >> Right[i] >> Result[i];
        for (char ch = 'A'; ch <= 'L'; ++ch) {
            if (isFake(ch, 1)) { //先假设ch为轻球，如果没问题就输出并break；
                cout << ch << " is the counterfeit coin and it is light. \n";
                break;
            } else if (isFake(ch, 0)) { //假设ch为重球
                cout << ch << " is the counterfeit coin and it is heavy. \n";
                break;
            }
        }
    }
    return 0;
}

bool isFake(char ch, bool light) {
    //想方设法排除不满足条件的假设，剩下的就是真的假设。
    int mark = 0; //用于标记该球是否在三次称量中出现
    for (int i = 0; i < 3; ++i) {
        int lite_mark = 0; //用于标记该球是否在此次称量中出现
        //遍历左边
        for (int pl = 0; pl < strlen(Left[i]); ++pl) {
            if (Left[i][pl] == ch) {
                mark = 1;
                lite_mark = 1;
                //三目运算符，灵光一现想到的
                //如果假设球是轻的，现在在遍历左边，就看结果是不是down，不是的话就return
                // false
                if ((light == 1) ? (Result[i][0] != 'd')
                                 : (Result[i][0] != 'u'))
                    return false;
            }
        }
        for (int pr = 0; pr < strlen(Right[i]); ++pr) {
            if (Right[i][pr] == ch) {
                mark = 1;
                lite_mark = 1;
                if ((light == 1) ? (Result[i][0] != 'u')
                                 : (Result[i][0] != 'd'))
                    return false;
            }
        }
        //如果该球没在此次称量中出现，且结果不是even，则假设错误。
        if (lite_mark == 0 && Result[i][0] != 'e')
            return false;
    }
    //如果该球没有在称量中出现过，就返回false，否则就是真的
    if (mark)
        return true;
    else
        return false;
}