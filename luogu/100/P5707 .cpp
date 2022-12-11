#include<iostream>

using namespace std;

int main(){
    int s,v;
    cin>>s>>v;
    int time = s%v?s/v+1:s/v;
    int h = 7,m = 50;
    h-=time/60;
    m-=time%60;
    if(m<0) m+=60,h--;
    if(h<0) h+=24;

    printf("%02d:%02d",h,m);
    return 0;

}