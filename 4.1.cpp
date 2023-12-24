#include <climits>
#include <iostream>

struct Node {
  int data;
  Node* next;

  explicit Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
 private:
  Node* head;

 public:
  LinkedList() : head(nullptr) {}

  void insert(int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
  }

  void remove() {
    if (head) {
      Node* temp = head;
      head = head->next;
      delete temp;
    }
  }

  [[nodiscard]] int top() {
    if (head) {
      return head->data;
    }
    return INT_MIN;
  }

  [[nodiscard]] int getMin() {
    if (!head) {
      return INT_MIN;
    }

    int minVal = head->data;
    Node* current = head->next;

    while (current) {
      if (current->data < minVal) {
        minVal = current->data;
      }
      current = current->next;
    }
    return minVal;
  }
};

class StackMin {
 private:
  LinkedList list;

 public:
  void push(const int value) { list.insert(value); }

  void pop() { list.remove(); }

  [[nodiscard]] int top() { return list.top(); }

  [[nodiscard]] int min() { return list.getMin(); }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  StackMin stack;

  std::string cmd;
  while (std::cin >> cmd) {
    if (cmd == "push") {
      int value;
      std::cin >> value;
      stack.push(value);
    } else if (cmd == "top") {
      std::cout << stack.top() << "\n";
      std::cout.flush();
    } else if (cmd == "min") {
      std::cout << stack.min() << "\n";
      std::cout.flush();
    } else if (cmd == "pop") {
      stack.pop();
    } else {
      std::cout << "неизвестная: " << cmd;
      std::cout.flush();
      return -1;
    }
  }

  return 0;
}
