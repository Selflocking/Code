#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int t;
    int ji = 0,ou = 0;
    while(n--){
        cin>>t;
        if(t%2) ji++;
        else    ou++;
    }
    cout<<ji<<" "<<ou;
    return 0;
}