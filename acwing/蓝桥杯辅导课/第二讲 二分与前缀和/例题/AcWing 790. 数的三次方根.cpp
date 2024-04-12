#include <iostream>

int main(){
    double n = 0;
    std::cin>>n;
    double l = -10000;
    double r = 10000;
    while(r-l>=1e-8){
        double m = (l + r)/2;
        if(m*m*m>=n){
            r = m;
        }else {
            l = m;
        }
    }
    printf("%.6f\n",l);
    return 0;
}