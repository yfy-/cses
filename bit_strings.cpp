#include <cmath>
#include <iostream>

using namespace std;

constexpr uint32_t kBase = 1e9 + 7;

uint32_t num_bits(uint32_t n) {
  if (n <= 32)
    return static_cast<uint64_t>(pow(2, n)) % kBase;

  uint32_t rec_small = n / 2;
  uint32_t rec_big = n - rec_small;
  return (static_cast<uint64_t>(num_bits(rec_small)) * num_bits(rec_big)) %
         kBase;
}

int main() {
  uint32_t n;
  cin >> n;
  cout << num_bits(n) << "\n";
  return 0;
}
