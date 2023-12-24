#include <iostream>
#include <vector>
using namespace std;

//объединение
void merge(vector<int> &arr, vector<int> &buffer, size_t begin, size_t mid, size_t end) {
    size_t left = begin;
    size_t right = mid + 1;
    size_t temp = begin;

    // Слияние двух подмассивов во временный буфер
    while (left <= mid && right <= end) {
        if (arr[left] <= arr[right]) {
            buffer[temp++] = arr[left++];
        } else {
            buffer[temp++] = arr[right++];
        }
    }

    // Копирование оставшихся элементов из левого массива
    while (left <= mid) {
        buffer[temp++] = arr[left++];
    }

    // Копирование из правого
    while (right <= end) {
        buffer[temp++] = arr[right++];
    }

    // Копирование объединённых элементов из буфера обратно в исходный массив
    for (size_t i = begin; i <= end; i++) {
        arr[i] = buffer[i];
    }
}


void merge_sort(vector<int> &arr, vector<int> &buffer, size_t begin, size_t end) {
    if (begin >= end) {
        return;
    }

    size_t mid = (begin + end) / 2;
    merge_sort(arr, buffer, begin, mid);
    merge_sort(arr, buffer, mid + 1, end);

    merge(arr, buffer, begin, mid, end);
}

//интерфейс
void run_merge_sort(vector<int> &arr) {
    vector<int> buffer(arr.size());
    merge_sort(arr, buffer, 0, arr.size() - 1);
}

int main() {

  vector<int> arr;
  arr={1,2,5,1,1,2,6,8,9,3};
  size_t n=10; cout<< n <<"\n";

  for (auto i : arr) {
    cout << i << " ";
  }
  cout<<"\n";
  
  run_merge_sort(arr);

  for (auto i : arr) {
    cout << i << " ";
  }

  return 0;
}



