#include <iostream>

using namespace std;

int main() {
  uint32_t n;
  cin >> n;
  if (n == 1) {
    cout << "1";
  } else if (n == 2 || n == 3) {
    cout << "NO SOLUTION";
  } else {
    cout << "2";

    for (int i = 4; i <= n; i += 2)
      cout << " " << i;

    for (int i = 1; i <= n; i += 2)
      cout << " " << i;
  }

  cout << "\n";
  return 0;
}
