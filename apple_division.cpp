#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int64_t solve(int64_t diff, int idx, vector<int>& weights,
              vector<unordered_map<int64_t, int64_t>>& dp) {
  if (idx == weights.size())
    return diff < 0 ? diff * -1 : diff;

  if (dp[idx].find(diff) != dp[idx].end()) {
    return dp[idx][diff];
  }

  int64_t sol = min(solve(diff + weights[idx], idx + 1, weights, dp),
                    solve(diff - weights[idx], idx + 1, weights, dp));
  dp[idx][diff] = sol;
  return sol;
}

int main() {
  int n;
  cin >> n;
  vector<int> weights(n);
  for (int i = 0; i < n; ++i)
    cin >> weights[i];

  vector<unordered_map<int64_t, int64_t>> dp(n);
  cout << solve(0, 0, weights, dp) << "\n";
  return 0;

}
