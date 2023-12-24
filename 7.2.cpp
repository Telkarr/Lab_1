#include <iostream>
#include <vector>

std::vector<int> longest_increasing_subseq(const std::vector<int>& seq) {
  std::vector<int> lis(seq.size(), 1); 
  std::vector<int> prev(seq.size(), -1); 

  for (size_t i = 0; i < seq.size(); ++i) {
    for (size_t j = 0; j < i; ++j) {
      if (seq[j] < seq[i] && lis[i] < lis[j] + 1) {
        lis[i] = lis[j] + 1;
        prev[i] = j;
      }
    }
  }

  int max_len = 0;
  size_t max_idx = 0;
  for (size_t i = 0; i < lis.size(); ++i) {
    if (lis[i] > max_len) {
      max_len = lis[i];
      max_idx = i;
    }
  }

  std::vector<int> result;
  while (max_idx != -1) {
    result.insert(result.begin(), seq[max_idx]);
    max_idx = prev[max_idx];
  }

  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::size_t n;
  std::cin >> n;
  std::vector<int> seq(n);

  for (auto& el : seq) {
    std::cin >> el;
  }

  auto longest_seq = longest_increasing_subseq(seq);

  std::cout << longest_seq.size() << "\n";
  for (auto el : longest_seq) {
    std::cout << el << " ";
  }

  return 0;
}