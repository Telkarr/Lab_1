#include <iostream>
#include <vector>

void start(const std::vector<int> &field, std::size_t n, std::size_t m) {
  std::vector<std::vector<int>> dp(n, std::vector<int>(m, 0));

  dp[0][0] = field[0];
  for (std::size_t i = 1; i < n; i++) {
    dp[i][0] = dp[i - 1][0] + field[i * m];
  }
  for (std::size_t j = 1; j < m; j++) {
    dp[0][j] = dp[0][j - 1] + field[j];
  }

  for (std::size_t i = 1; i < n; i++) {
    for (std::size_t j = 1; j < m; j++) {
      if (dp[i - 1][j] > dp[i][j - 1]) {
        dp[i][j] = dp[i - 1][j] + field[i * m + j];
      } else {
        dp[i][j] = dp[i][j - 1] + field[i * m + j];
      }
    }
  }

  std::cout << "Max coins: " << dp[n - 1][m - 1] << "\n";

  std::size_t i = n - 1, j = m - 1;
  std::string result_path = "";
  while (i > 0 || j > 0) {
    if (i > 0 && dp[i][j] - field[i * m + j] == dp[i - 1][j]) {
      result_path = 'D' + result_path;
      i--;
    } else {
      result_path = 'R' + result_path;
      j--;
    }
  }

  std::cout << "Path: " << result_path << "\n";
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::size_t n, m;
  std::cin >> n >> m;

  std::vector<int> field(n * m);
  for (std::size_t i = 0; i < n; i++) {
    for (std::size_t j = 0; j < m; j++) {
      std::cin >> field.at(i * m + j);
    }
  }

  start(field, n, m);

  return 0;
}
