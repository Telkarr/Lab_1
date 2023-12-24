#include <algorithm>
#include <iostream>
#include <vector>

bool canFit(int side, int w, int h, int N) {
  return (side / w) * (side / h) >= N;
}

int findMinSquare(int w, int h, int N) {
  int left = 1;
  int right = std::max(w, h) * N + 1; 
  int result = right;

  while (left < right) { 
    int mid = left + (right - left) / 2;

    if (canFit(mid, w, h, N)) {
      result = mid;
      right = mid;
    } else {
      left = mid + 1;
    }
  }

  return result; 
}

int main() {
  int N, h, w;
  std::cout << "Введите количество дипломов: ";
  std::cin >> N;
  std::cout << "Введите высоту диплома: ";
  std::cin >> h;
  std::cout << "Введите ширину диплома: ";
  std::cin >> w;
  
  int minSquareSide = findMinSquare(w, h, N);
  std::cout << "Минимальная сторона квадратного ящика: " << minSquareSide
            << std::endl;

  return 0;
}
