#include "cstring"
#include <cstring>
#include <iostream>

using namespace std;
const int N = 1005;
int book[N];
int Time[N];

int main() {
  int n;
  cin >> n;
  while (n--) {
    double cnt = 0;
    double sum = 0;
    int id;
    char s;
    int h, m;

    memset(Time, 0, sizeof Time);
    memset(book, 0, sizeof book);

    while (1) {
      scanf("%d %c %d:%d", &id, &s, &h, &m);

      if (id == 0) {
        if (cnt == 0)
          cout << 0 << " " << 0 << "\n";
        else
          cout << cnt << " " << (int)(sum / cnt + 0.5) << "\n";
        break;
      }

      if (s == 'S') {
        book[id] = 1;
        Time[id] = 60 * h + m;
      } else {
        if (book[id] != 0) {
          book[id] = 0;
          sum += 60 * h + m - Time[id];
          cnt++;
        } else {
          continue;
        }
      }
      
    }
  }
  return 0;
}