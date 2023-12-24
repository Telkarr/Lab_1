#include <iostream>
#include <vector>
using namespace std;

void count_sort(std::vector<int> &arr) {
    std::vector<int> count(128, 0);

    for (int num : arr) {
        count[num]++;
    }

    int j = 0;
    for (int i = 0; i < 128; i++) {
        if (count[i] > 0) {
            arr[j++] = i;
        }
    }
}

int main() {
    std::vector<int> arr(128,0); 

    arr={124,68,57,0,93,60,24,71,125,70,87,83,105,34,30,15};

    for (auto i : arr) {
        printf("%4d", i);
    }
    std::cout<<"\n";
    
    count_sort(arr);

    for (auto i : arr) {
        printf("%4d", i);
    }
}


