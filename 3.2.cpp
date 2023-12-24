#include <iostream>
#include <vector>
using namespace std;

void count_sort(vector<std::string> &arr, size_t digit) {
  const int radix = 256;
  const size_t n = arr.size();
  vector<int> count(radix, 0);
  vector<string> temp(n);

  for (const auto &item : arr) {
    if (digit < item.length()) {
      count[item[digit]]++;
    } else {
      count[0]++;
    }
  }

  for (int i = 1; i < radix; i++) {
    count[i] += count[i - 1];
  }

  for (int i = n - 1; i >= 0; i--) {
    const auto &item = arr[i];
    if (digit < item.length()) {
      temp[--count[item[digit]]] = item;
    } else {
      temp[--count[0]] = item;
    }
  }

  arr = temp;
}

void radix_sort(std::vector<std::string> &arr) {
  size_t max_length = 0;
  for (const auto &item : arr) {
    max_length = std::max(max_length, item.length());
  }

  for (size_t digit = max_length - 1; digit != size_t(-1); digit--) {
    count_sort(arr, digit);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  size_t n;
  cin >> n;

  vector<string> lines(n);
  for (auto &line : lines) {
    cin >> line;
  }

  radix_sort(lines);

  for (const auto &line : lines) {
    cout << line << "\n";
  }

  return 0;
}
