#include <iostream>
#include <vector>

using namespace std;

int removeElementInplace(vector<int>& arr, int val) {
    int n = arr.size();
    int j = 0;  // Индекс для нового массива

    for (int i = 0; i < n; i++) {
        if (arr[i] != val) {
            arr[j] = arr[i];
            j++;
        }
    }
    return j;
}

int main() {
    setlocale(LC_ALL, "Russian");
    vector<int> arr = { 0,2,6,6,1,0,4,6 };
    int val1 = 6;
    int newSize1 = removeElementInplace(arr, val1);

    cout << "результат: " << newSize1 << ", arr = [";
    for (int i = 0; i < arr.size(); i++) {
        if (i < newSize1) {
            cout << arr[i];
        }
        else {
            cout << "_";
        }

        if (i < arr.size() - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;
    return 0;
}





