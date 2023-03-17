#include <iostream>
#include <vector>

using namespace std;

vector<string> solve(vector<int>& char_counts, int pos, int size) {
  vector<string> ans;
  for (int i = 0; i < 26; ++i) {
    if (char_counts[i] > 0) {
      if (pos == size - 1) {
        string ans(size, 'X');
        ans[pos] = i + 'a';
        return {ans};
      }

      --char_counts[i];
      vector<string> sub_ans = solve(char_counts, pos + 1, size);
      ++char_counts[i];
      for (auto& sa: sub_ans)
        sa[pos] = i + 'a';

      ans.insert(end(ans), begin(sub_ans), end(sub_ans));
    }
  }

  return ans;
}

int main() {
  string input;
  cin >> input;
  int n = input.size();
  vector<int> char_counts(26);
  for (auto& c: input)
    ++char_counts[c - 'a'];


  vector<string> ans = solve(char_counts, 0, n);
  cout << ans.size() << "\n";
  for (auto& a: ans)
    cout << a << "\n";

  return 0;
}
