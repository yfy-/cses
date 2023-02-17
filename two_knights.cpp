#include <iostream>

using namespace std;

uint64_t solve(uint32_t k) {
  int64_t ksq = static_cast<int64_t>(k) * k;
  return (ksq * (ksq - 9)) / 2 + 12 * k - 8;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  uint32_t n;
  cin >> n;
  for (uint32_t i = 1; i <= n; ++i)
    cout << solve(i) << "\n";

  return 0;
}
