#include <cctype>
#include <cstring>
#include <iostream>
using namespace std;

constexpr int mxN = 1005;

char ori[mxN];
char str[mxN];
char *words[mxN];

int main() {
    int n;
    cin >> n;
    getchar();
    while (n--) {
        cin.getline(ori, sizeof ori);

        printf("%s\n", ori);

        int point = 0;
        char *p = &ori[0];
        while (*p != '\0') {
            if (isalnum(*p)) {
                str[point++] = *p;
                // ++point;
            } else if (*p == ' ') {
                while (*(p + 1) == ' ') {
                    ++p;
                }
                if (ispunct(*(p + 1))) {
                    ++p;
                }
                str[point++] = *p;
            } else if (ispunct(*p)) {
                str[point++] = *p;
            }
            ++p;
        }
        str[point + 1] = '\0';
        for (int i = 0; i < strlen(str); ++i) {
            if (isupper(str[i]) && str[i] != 'I') str[i] += 32;
            if (str[i] == '?') str[i] = '!';
        }
        int idx;
        p = strtok(str, " ");
        for (idx = 0; p != NULL; idx++) {
            words[idx] = p;
            p = strtok(NULL, " ");
        }
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
}