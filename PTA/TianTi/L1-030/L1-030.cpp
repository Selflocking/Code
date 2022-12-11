#include<iostream>
using namespace std;
//我写过的最有成就感的程序
//没有用到比较高级的数据结构
int main(){
    int N;
    cin>>N;
    //stu存人名,gender存性别
    string * stu = new string[N];
    int * gender = new int[N];
    //输入
    for(int i = 0;i<N;++i){
        cin>>gender[i]>>stu[i];
    }
    //找对象(划掉
    for(int i = 0;i<N>>1;++i){
        for(int j = N-1;j>=N>>1;--j){
            //因为性别是0或1,所以相加为1即为异性;
            //对于已经使用过的同学就把他的性别改成-1,这样就没法和其他人匹配了
            if(gender[j]+gender[i]==1){
                cout<<stu[i]<<" "<<stu[j]<<endl;
                gender[j] = -1;
                break;
            }
        }
    }
    return 0;
}

