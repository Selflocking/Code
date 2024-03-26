#include <bits/types/timer_t.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
    // fork 出的子进程会复制父进程的内存空间
    pid_t pid = fork();
    if (pid == 0) {
        printf("im child process\n");
        printf("my pid: %d\n", getpid());
    } else if (pid > 0) {
        printf("im parent process\n");
        printf("my pid: %d\n", getpid());
        printf("child pid: %d\n", pid);
    } else {
        printf("failed to fork\n");
        exit(-1);
    }
    return 0;
}
