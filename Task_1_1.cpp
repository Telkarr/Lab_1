#include <iostream>
#include <stack>

using namespace std;

bool isValidBrackets(string& str)
{
    stack<char> stk;
    for (char bracket : str) {
        if (bracket == '(' || bracket == '[' || bracket == '{') {
            stk.push(bracket);
        }
        else if (bracket == ')' || bracket == ']' || bracket == '}') {
            if (stk.empty()) {
                return false; // нет открывающей скобки
            }

            char balance_bracket = stk.top();
            stk.pop(); // удаляет верхний элемент из стека (т.к. сопоставлен открывающей скобке)

            if ((bracket == ')' && balance_bracket != '(') ||
                (bracket == ']' && balance_bracket != '[') ||
                (bracket == '}' && balance_bracket != '{')) {
                return false;
            }
        }
    }
    return stk.empty();
}

int main() {
    setlocale(LC_ALL, "Russian");
    string arr = "(){}";

    if (isValidBrackets(arr)) {
        cout << "Скобки сбалансированы." << endl;
    }
    else {
        cout << "Скобки не сбалансированы." << endl;
    }
    return 0;
}
