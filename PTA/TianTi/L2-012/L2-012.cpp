#include <iostream>
#include <vector>
using namespace std;

vector<int> q;

void upTree(int i) {
    if (i == 1)
        return;
    while (i != 1) {
        if (q[i] < q[i / 2]) {
            swap(q[i], q[i / 2]);
            i = i / 2;
        } else {
            break;
        }
    }
}

void judge1(int a, int b) {
    int mx, mi;
    for (int i = 1; i <= q.size() - 1; ++i) {
        if (q[i] == a)
            mx = i;
        if (q[i] == b)
            mi = i;
    }
    if (mi > mx)
        swap(mx, mi);
    if (mx - mi == 1 && mx % 2 == 1)
        cout << "T\n";
    else
        cout << "F\n";
}

void judge2(int a, int b) {
    int aa, bb;
    for (int i = 1; i < q.size(); ++i) {
        if (q[i] == a)
            aa = i;
        if (q[i] == b)
            bb = i;
    }
    if (bb / 2 == aa)
        cout << "T\n";
    else
        cout << "F\n";
}

// void judge3(int a,int b){

// }
int main() {
    int n, m;
    cin >> n >> m;
    q.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> q[i];
        upTree(i);
    }

    // for (auto i : q) cout << i << " ";
    // cout<<"\n";
    int a, b;
    char s[10];
    while (m--) {
        scanf("%d %s ", &a, s);
        if (s[2] == 'd') {
            scanf("%d %s %s", &b, s, s);
            judge1(a, b);
        } else {
            scanf("%s %s", s, s);
            if (s[0] == 'r') {
                if (q[1] == a)
                    cout << "T\n";
                else
                    cout << "F\n";
            } else if (s[0] == 'p') {
                scanf("%s %d", s, &b);
                judge2(a, b);
            } else {
                scanf("%s %d", s, &b);
                judge2(b, a);
            }
        }
    }
    return 0;
}