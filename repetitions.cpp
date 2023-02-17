#include <iostream>

using namespace std;

int main() {
  string dna;
  cin >> dna;
  int max_repeat = 0;
  int curr_repeat = 1;
  char rep_char = dna[0];
  for (int i = 1; i < dna.size(); ++i) {
    if (dna[i] == rep_char) {
      ++curr_repeat;
    } else {
      max_repeat = max(max_repeat, curr_repeat);
      curr_repeat = 1;
      rep_char = dna[i];
    }
  }

  max_repeat = max(max_repeat, curr_repeat);
  cout << max_repeat << "\n";
  return 0;
}
