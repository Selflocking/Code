#include "iostream"
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  cout << n;
  cout << '/';
  if (m > 0)
    cout << m;
  else if (m < 0)
    cout << '(' << m << ')';
  else {
    cout << m;
    cout << "=Error";
    return 0;
  }

  cout << '=';
  printf("%.2f", 1.0 * n / m);
  return 0;
}