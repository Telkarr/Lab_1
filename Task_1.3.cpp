#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool hasDuplicates(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int n = arr.size();

    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            return true;
        }
    }
    return false;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    vector<int> arr = { 4,2,7,4,9,1,5 };
    int n = arr.size();

    cout << "Массив: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) {
            cout << ",";
        }
    }
    cout << endl;

    if (hasDuplicates(arr)) {
        for (int i = 1; i < n; i++) {
            if (arr[i] == arr[i - 1]) {
                cout << "Дубликат числа " << arr[i] << endl;
            }
        }
    }
    else {
        cout << "Нет дубликатов" << endl;
    }

    return 0;
}
