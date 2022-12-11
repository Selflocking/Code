#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int h;
    double w;
    int N;
    cin>>N;
    while(N--){
        cin>>h>>w;
        double W = (h-100)*1.8;
        if(abs(w-W)<0.1*W){
            cout<<"You are wan mei!"<<endl;
        }else{
            if(w>W){
                cout<<"You are tai pang le!"<<endl;
            }else{
                cout<<"You are tai shou le!"<<endl;
            }
        }
    }

    return 0;

}