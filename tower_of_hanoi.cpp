#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<pair<int, int>> solve(int k, int src, int aux, int dest) {
  if (!k)
    return {};

  vector<pair<int, int>> ans_moves = solve(k - 1, src, dest, aux);
  ans_moves.emplace_back(src, dest);
  vector<pair<int, int>> rec_moves = solve(k - 1, aux, src, dest);
  ans_moves.insert(end(ans_moves), begin(rec_moves), end(rec_moves));
  return ans_moves;
}

int main() {
  int k;
  cin >> k;
  vector<pair<int, int>> moves = solve(k, 1, 2, 3);
  cout << moves.size() << "\n";
  for (auto& m: moves)
    cout << m.first << " " << m.second << "\n";

  return 0;
}
