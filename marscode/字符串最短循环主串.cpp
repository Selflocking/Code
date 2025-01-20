#include <iostream>
#include <string>

std::string solution(const std::string &inp) {
    // Edit your code here
    const int n = inp.size();

    int pa = 0;
    int pb = 1;
    while (pb < n - 1) {
        if (inp[pb] == inp[pa]) {
            pa++;
            pb++;
        } else {
            pa = 0;
            pb++;
        }
    }
    if ((pa + 1) % (pb - pa) != 0 || pa == 0) {
        return "";
    } else {
        return inp.substr(0, pb - pa);
    }
}

int main() {
    // Add your test cases here

    std::cout << (solution("abcabcabcabc")) << std::endl;
    return 0;
}
