#include <iostream>

using namespace std;

int main() {
  uint64_t n;
  cin >> n;
  uint64_t n_sum = n * (n + 1) / 2;
  uint64_t act_sum = 0;
  uint32_t x;
  for (int i = 0; i < n - 1; ++i) {
    cin >> x;
    act_sum += x;
  }

  cout << n_sum - act_sum << "\n";
  return 0;
}
