#include <iostream>
#include <vector>

using namespace std;

int main() {
  string word;
  cin >> word;
  vector<uint32_t> char_counts(26);
  for (auto c: word)
    ++char_counts[c - 'A'];

  bool odd_used = false;
  bool can_palindrome = true;
  size_t n = word.size();
  string palindrome(n, 'X');
  uint32_t palin_beg = 0;
  for (int i = 0; i < 26; ++i) {
    if (char_counts[i] % 2) {
      if (odd_used) {
        can_palindrome = false;
        break;
      } else {
        palindrome[n / 2] = i + 'A';
        odd_used = true;
      }
    }

    for (int j = 0; j < char_counts[i] / 2; ++j) {
      palindrome[palin_beg] = i + 'A';
      palindrome[n - palin_beg - 1] = i + 'A';
      ++palin_beg;
    }
  }

  cout << (can_palindrome ? palindrome : "NO SOLUTION") << "\n";
  return 0;
}
