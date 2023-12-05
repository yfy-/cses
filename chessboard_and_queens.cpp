#include <cstring>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

char board[8][8];


bool is_attacked(int row, int col) {
  for (int i = 1; i < 8; ++i) {
    int pre_row = row - i;
    int pre_col = col - i;
    int next_col = col + i;
    if (pre_col > -1 && pre_row > -1 && board[pre_row][pre_col] == 'Q')
      return true;

    if (pre_row > -1 && board[pre_row][col] == 'Q')
      return true;

    if (next_col < 8 && pre_row > -1 && board[pre_row][next_col] == 'Q')
      return true;
  }

  return false;
}

int solve(int row) {
  int placed = 0;
  for (int col = 0; col < 8; ++col) {
    if (board[row][col] == '*' || is_attacked(row, col))
      continue;

    if (row == 7) {
      ++placed;
    } else {
      board[row][col] = 'Q';
      placed += solve(row + 1);
      board[row][col] = '.';
    }
  }

  return placed;
}

int main() {
  string line;
  for (int row = 0; row < 8; ++row) {
    cin >> line;
    for (int col = 0; col < 8; ++col) {
      board[row][col] = line[col];
    }
  }

  cout << solve(0) << "\n";
  return 0;
}
