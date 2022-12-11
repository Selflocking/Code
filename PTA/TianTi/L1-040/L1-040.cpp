#include <cstdio>
#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    while(n--){
        char ch;
        cin>>ch;
        double h;
        cin>>h;
        ch=='F'?printf("%.2lf\n",1.09*h):printf("%.2lf\n",h/1.09);
    }
    return 0;
}