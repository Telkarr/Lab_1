#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

int closestNumber(const std::vector<int> &arr, int target) {
  int left = 0;
  int right = arr.size() - 1;

  while (left <= right) {
    int mid = left + (right - left) / 2;

    if (arr[mid] == target) {
      return arr[mid];
    } else if (arr[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  if (right < 0) {
    return arr[left];
  } else if (left >= arr.size()) {
    return arr[right];
  } else {
    if (std::abs(target - arr[left]) < std::abs(target - arr[right])) {
      return arr[left];
    } else {
      return arr[right];
    }
  }
}

int main() {
  int n, m;
  std::cin >> n;
  std::vector<int> array(n);

  for (int i = 0; i < n; ++i) {
    std::cin >> array[i];
  }

  std::cin >> m;
  std::vector<int> queries(m);

  for (int i = 0; i < m; ++i) {
    std::cin >> queries[i];
  }

  std::sort(array.begin(), array.end());

  for (int i = 0; i < m; ++i) {
    int closest = closestNumber(array, queries[i]);
    std::cout << closest << " ";
  }

  return 0;
}
