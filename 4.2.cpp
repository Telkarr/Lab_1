#include <iostream>
#include <string>
#include <vector>

struct Data {
  size_t idx;
  int value;
};

class PriorityQueue {
  std::vector<Data> queue;

  void print() const {
    std::cout << "[";
    for (auto &el : queue) {
      std::cout << el.value << " ";
    }
    std::cout << "]\n";
  }

 public:
  void enqueue(const Data &data) {
    queue.push_back(data);
    auto i = queue.size() - 1;
    while ((i > 0) && (queue[i].value > queue[(i - 1) / 2].value)) {
      std::swap(queue[i], queue[(i - 1) / 2]);
      i = (i - 1) / 2;
    }
  };
  void dequeue_max() {
    std::swap(queue[0], queue[queue.size() - 1]);
    queue.pop_back();
    size_t i = 0;
    while ((i < queue.size() - 1) &&
           (queue[i].value < queue[(2 * i + 1)].value)) {
      std::swap(queue[i], queue[2 * i + 1]);
      i = 2 * i + 1;
    }
  };
  void increase(const Data &data) {
    size_t point = 0;
    if (queue.size() != 0) {
      while (point <= queue.size()) {
        if (queue[point].idx == data.idx) {
          queue[point].value = queue[point].value + data.value;
          break;
        } else {
          point++;
        }
      }
    }
  };
  [[nodiscard]] const Data &max() const { return queue[0]; };
  [[nodiscard]] bool empty() const { return queue.size() == 0; };
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  PriorityQueue queue;

  size_t op_idx = 0;
  std::string cmd;
  while (std::cin >> cmd) {
    if (cmd == "enqueue") {
      op_idx++;
      Data data{op_idx, 0};
      std::cin >> data.value;
      queue.enqueue(data);
    } else if (cmd == "dequeue_max") {
      if (queue.empty()) {
        std::cout << "*\n";
      } else {
        auto &d = queue.max();
        std::cout << d.idx << " " << d.value << "\n";
        queue.dequeue_max();
      }
    } else if (cmd == "inc") {
      Data d{0, 0};
      std::cin >> d.idx >> d.value;
      queue.increase(d);
    } else {
      std::cout << "Unknown command " << cmd;
      return -1;
    }
  }

  return 0;
}