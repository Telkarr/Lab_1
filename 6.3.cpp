#include <iostream>
#include <cmath>

using namespace std;

double equation(double x, double a) {
    return x * x - x + sqrt(x) - a;
}

double find_x(double a) {
    double left = 0;
    double right = a;

    double precision = 1e-6;
    while (right - left > precision) {
        double mid = (left + right) / 2;
        if (equation(mid, a) > 0) {
            right = mid;
        } else {
            left = mid;
        }
    }
    return left;
}

int main() {
    double a;
    cin >> a;

    if (a < 0) {
        cout << "Уравнение не имеет решения в области действительных чисел." << endl;
    } else {
        double result = find_x(a);
        cout << fixed << result << endl;
    }

    return 0;
}
