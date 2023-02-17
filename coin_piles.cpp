#include <iostream>

using namespace std;

bool can_empty(uint32_t a, uint32_t b) {
  return (a + b) % 3 == 0 && min(a, b) * 2 >= max(a, b);
}

int main() {
  uint32_t t;
  cin >> t;
  while (t--) {
    uint32_t a, b;
    cin >> a >> b;
    cout << (can_empty(a, b) ? "YES" : "NO") << "\n";
  }

  return 0;
}
