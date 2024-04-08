#include <stdio.h>

// 忙等待锁，也称自旋锁

typedef struct lock_t {
    int flag;
}lock_t;

// 查看旧值，并设置新值
int TestAndSet(int *ptr,int new){
    int old = *ptr;
    *ptr = new;
    return old;
}

void lock(lock_t *l){
    // flag 为 0 才能正常执行，否则一直自旋
    while(TestAndSet(&l->flag,1)==1);
}

void unlock(lock_t *l){
    l->flag = 0;
}

void thread1(){
    lock_t l;
    // 尝试上锁，当flag为0时才能拿到锁，将flag设置为1
    lock(&l);

    // do something

    // 解锁
    unlock();
}

void thread2(){
    lock_t l;
    lock(&l);

    // do something

    unlock();
}

int main(){

}
