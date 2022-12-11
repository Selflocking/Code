#include<iostream>

using namespace std;

int main(){
    int a;
    cin>>a;
    if(a%2==0&&a<=12&&a>4)  cout<<1;
    else    cout<<0;
    cout<<" ";
    if(a%2==0||(a<=12&&a>4))    cout<<1;
    else    cout<<0;
    cout<<" ";
    if((a%2==0&&(a>12||a<=4))||(a%2==1&&(a<=12&&a>4)))    cout<<1;
    else    cout<<0;
    cout<<" ";
    if(a%2==1&&(a>12||a<=4))    cout<<1;
    else    cout<<0;

    return 0;
}