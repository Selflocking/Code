#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  while (n--) {
    int a, b;
    cin >> a >> b;
    if (a == 0 && b != 0) {
      cout << 1 << "\n";
    }else{
        cout<<a+2*b+1<<"\n";
    }
  }
  return 0;
}