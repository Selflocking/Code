#include <iostream>
#include <map>
using namespace std;
multimap<int, string> m;
int n, g, k;
int main() {
    cin >> n >> g >> k;
    int sum = 0;

    for (int i = 1; i <= n; ++i) {
        string t;
        int a;
        cin >> t >> a;
        if (a >= g) sum += 50;
        if (a < g && a >= 60) sum += 20;
        m.insert({a, t});
    }
    cout<<sum<<"\n";
    int cnt = 0;
    int rank = 0;
    int temp = 1;
    int flag ;
    auto it = m.rbegin();
    while(cnt<=k&&it!=m.rend()){
        if(it->first==flag){
            temp++;
        }else {
            rank+=temp;
            temp = 1;
        }
        flag = it->first;
        cout<<rank<<" "<<it->second<<" "<<it->first<<"\n";
        it++;
        cnt++;
    }
    return 0;
}