#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Student {
    string name;
    int age;
};

bool compare_students_age(const Student &a, const Student &b) {
  return a.age < b.age;
}

bool compare_students_name(const Student &a, const Student &b) {
  return a.name < b.name;
}

void sort_students(std::vector<Student> &arr) {
  sort(arr.begin(), arr.end(), compare_students_age);
  stable_sort(arr.begin(), arr.end(), compare_students_name);
}

int main() {
    vector<Student> arr = { {"A", 21}, {"B", 19} };

    for (auto i : arr) {
        cout << i.name << " " << i.age << "\n";
    }
  
    sort_students(arr);

    for (auto i : arr) {
        cout << i.name << " " << i.age << "\n";
    }

}




