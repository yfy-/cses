#include <iostream>
#include <vector>

using namespace std;

int main() {
  uint32_t n;
  cin >> n;
  vector<uint32_t> nums(n);
  for (uint32_t i = 0; i < n; ++i)
    cin >> nums[i];

  uint64_t ans = 0;
  for (uint32_t i = 1; i < n; ++i) {
    if (nums[i] < nums[i - 1]) {
      ans += nums[i - 1] - nums[i];
      nums[i] = nums[i - 1];
    }
  }

  cout << ans << "\n";
  return 0;
}
