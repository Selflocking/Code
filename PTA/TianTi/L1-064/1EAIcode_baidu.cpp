#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAXLEN 10001

int main(void) {
    char original[MAXLEN] = {0}, newstr[MAXLEN] = {0};
    int nowpos, newpos;

    while (fgets(original, sizeof(original), stdin)) {
        if (isdigit(original[0])) continue;
        nowpos = newpos = 0;
        // 分隔出独立的单词
        while (original[nowpos] != '\0') {
            char c = original[nowpos++];
            if (isalnum(c)) {
                newstr[newpos++] = c;
            } else if (isspace(c)) {
                newstr[newpos++] = c;
                while (original[nowpos] == ' ') nowpos++;
            } else {
                newstr[newpos++] = ' ';
                newstr[newpos++] = c;
            }
        }
        newstr[newpos - 1] = '\0';
        // 大小写转换 问号变为惊叹号
        for (newpos = 0; newstr[newpos] != '\0'; newpos++)
            if (newstr[newpos] != 'I')
                newstr[newpos] =
                    newstr[newpos] == '?' ? '!' : tolower(newstr[newpos]);

        char *words[MAXLEN] = {NULL};
        char *p = strtok(newstr, " ");
        int idx;
        for (idx = 0; p != NULL; idx++) {
            words[idx] = p;
            p = strtok(NULL, " ");
        }
        printf("%s", original);
        printf("AI:");
        if ((idx > 0 && !isalnum(words[0][0])) || idx == 0) {
            printf(" ");
        }
        for (int i = 0; i < idx; i++) {
            if (!isalnum(words[i][0])) {
                printf("%s", words[i]);
            } else if (i + 1 < idx && strcmp(words[i], "can") == 0 &&
                       strcmp(words[i + 1], "you") == 0) {
                printf(" I can");
                i++;
            } else if (i + 1 < idx && strcmp(words[i], "could") == 0 &&
                       strcmp(words[i + 1], "you") == 0) {
                printf(" I could");
                i++;
            } else if (strcmp(words[i], "I") == 0 ||
                       strcmp(words[i], "me") == 0) {
                printf(" you");
            } else {
                printf(" %s", words[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
