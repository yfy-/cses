#include <iostream>
#include <map>
#include <vector>

using namespace std;

std::int64_t pow_int(int base, int exp) {
  std::int64_t res = 1;
  for (int i = 0; i < exp; ++i)
    res *= base;

  return res;
}

int main() {
  map<std::int64_t, int> digits;
  int d = 1;
  std::int64_t sum = 9 * pow_int(10, d - 1) * d;
  std::int64_t limit = pow_int(10, 18);
  while (sum <= limit) {
    digits[sum] = d;
    ++d;
    sum += 9 * pow_int(10, d - 1) * d;
  }
  digits[limit] = d;

  int num_q;
  cin >> num_q;
  vector<int64_t> queries(num_q);
  for (int i = 0; i < num_q; ++i)
    cin >> queries[i];

  auto beg = begin(digits);
  for (int64_t q : queries) {
    auto found = digits.lower_bound(q);
    int digit = found->second;
    std::int64_t offset = 1;
    if (found != beg)
      offset = prev(found)->first + 1;

    int64_t num_offset = (q - offset) / digit;
    int64_t num_digit = pow_int(10, digit - 1);
    int64_t found_num = num_digit + num_offset;
    int64_t digit_offset = digit - ((q - offset) % digit) - 1;
    int64_t digit_divisor = pow_int(10, digit_offset + 1);
    cout << (found_num % digit_divisor) / (digit_divisor / 10) << "\n";
  }

  return 0;
}
