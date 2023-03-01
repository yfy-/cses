#include <iostream>
#include <vector>

using namespace std;

vector<string> gray_code(int n) {
  if (n == 1)
    return {"0", "1"};

  vector<string> sub_gray_code = gray_code(n - 1);
  size_t sub_size = sub_gray_code.size();
  sub_gray_code.resize(sub_size * 2);
  for (size_t i = 0; i < sub_size; ++i) {
    sub_gray_code[sub_size + i] = sub_gray_code[sub_size - i - 1];
    sub_gray_code[sub_size + i] += '1';
    sub_gray_code[sub_size - i - 1] += '0';
  }

  return sub_gray_code;
}


int main() {
  int n;
  cin >> n;
  for (auto &gc : gray_code(n))
    cout << gc << "\n";

  return 0;
}
