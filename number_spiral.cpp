#include <iostream>

using namespace std;

uint64_t solve(uint64_t row, uint64_t col) {
  int64_t step_dir = 1;
  uint64_t start = 0;
  uint64_t step;
  if (row >= col) {
    step = col;
    start = row * row;
    if (row % 2 == 0)
      step_dir = -1;
    else
      start -= 2 * row - 2;
  } else {
    step = row;
    start = col * col;
    if (col % 2 == 0)
      start -= 2 * col - 2;
    else
      step_dir = -1;
  }

  return start + (step - 1) * step_dir;
}

int main() {
  uint32_t t;
  cin >> t;
  while (t--) {
    uint64_t row, col;
    cin >> row >> col;
    cout << solve(row, col) << "\n";
  }
  return 0;
}
