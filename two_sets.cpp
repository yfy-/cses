#include <iostream>
#include <vector>

using namespace std;

int main() {
  uint32_t n;
  cin >> n;
  uint64_t sum = n * (n + 1) / 2;
  if (sum % 2) {
    cout << "NO\n";
    return 0;
  }

  cout << "YES\n";
  vector<uint32_t> set1;
  uint64_t set1_sum = 0;
  vector<uint32_t> set2;
  uint64_t set2_sum = 0;
  for (uint32_t i = n; i >= 1; --i) {
    if (set1_sum <= set2_sum) {
      set1_sum += i;
      set1.push_back(i);
    } else {
      set2_sum += i;
      set2.push_back(i);
    }
  }

  cout << set1.size() << "\n" << set1[0];
  for (int i = 1; i < set1.size(); ++i) {
    cout << " " << set1[i];
  }

  cout << "\n" << set2.size() << "\n" << set2[0];
  for (int i = 1; i < set2.size(); ++i) {
    cout << " " << set2[i];
  }

  cout << "\n";
  return 0;
}
