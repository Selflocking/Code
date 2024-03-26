#include <assert.h>
#include <pipeline.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
    int fd[2];
    // 使用 pipe 创建管道，pipe函数会往fd中放入文件描述符，fd[0] 用于读，fd[1]
    // 用于写
    if (pipe(fd) < 0) {
        printf("failed to create pipe\n");
        exit(-1);
    }

    pid_t pid = fork();
    if (pid < 0) {
        printf("failed to create child process");
        exit(-1);
    } else if (pid == 0) {
        char buf[100];
        strcpy(buf, "Hi, I'm your dad\n");
        const size_t l = strlen(buf);
        write(fd[1], buf, l);
    } else {
        char buf[100];
        read(fd[0], buf, 100);
        printf("parent say: %s\n", buf);
    }
    return 0;
}
