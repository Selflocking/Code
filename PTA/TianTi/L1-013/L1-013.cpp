#include<iostream>

using namespace std;

int main(){
    long  S = 0;
    int N;
    cin>>N;
    
    while(N){
        long temp =1;
        for(int i = N;i;i--){
            temp*=i;
        }
        S+=temp;
        N--;
    }
    cout<<S;
    return 0;
}