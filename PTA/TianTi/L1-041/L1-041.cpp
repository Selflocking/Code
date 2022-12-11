#include "iostream"

using namespace std;
int main(){
    int cnt = 0;
    int n;
    while(1){
        cin>>n;
        cnt++;
        if(n==250){
            cout<<cnt;
            return 0;
        }
    }

}