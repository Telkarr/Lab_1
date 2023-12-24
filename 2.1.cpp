#include <iostream>
#include <vector>
using namespace std;

void insertions_sort(vector<int> &arr) {
  for (size_t i = 1; i < arr.size(); ++i) {
    
    int current = arr[i];
    int j = i;
    
    while (arr[j - 1] > current) {
        arr[j] = arr[j - 1];
        j--;
        }
    
    arr[j] = current;
  }
}

int main() {

    vector<int> arr;
    
    arr={1,2,5,1,1,2,6,8,9,3};
    
    cout << arr.size()<<"\n";
    for (auto i : arr) {
        cout << i << " ";
    }
    cout << "\n";
    
    insertions_sort(arr);
    
    for (auto i : arr) {
        cout << i << " ";
    }
    
    return 0;
}




