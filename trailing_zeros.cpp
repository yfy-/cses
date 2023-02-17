#include <iostream>

using namespace std;

int main() {
  uint32_t n;
  cin >> n;
  uint64_t count_div5 = 0;
  for (uint32_t i = 5; i <= n; i *= 5)
    count_div5 += n / i;

  cout << count_div5 << "\n";
  return 0;
}
