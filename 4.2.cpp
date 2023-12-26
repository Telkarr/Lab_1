#include <iostream>
#include <string>
#include <vector>

struct Data {
    size_t idx;
    int value;
};

class PriorityQueue {
    std::vector<Data> queue;

    void heapify_up(size_t idx) {
        while (idx > 0 && queue[idx].value > queue[(idx - 1) / 2].value) {
            std::swap(queue[idx], queue[(idx - 1) / 2]);
            idx = (idx - 1) / 2;
        }
    }

    void heapify_down(size_t idx) {
        size_t left_child = 2 * idx + 1;
        size_t right_child = 2 * idx + 2;
        size_t largest = idx;

        if (left_child < queue.size() && queue[left_child].value > queue[largest].value) {
            largest = left_child;
        }

        if (right_child < queue.size() && queue[right_child].value > queue[largest].value) {
            largest = right_child;
        }

        if (largest != idx) {
            std::swap(queue[idx], queue[largest]);
            heapify_down(largest);
        }
    }

public:
    void enqueue(const Data &data) {
        queue.push_back(data);
        heapify_up(queue.size() - 1);
    }

    void dequeue_max() {
        if (queue.empty()) {
            std::cout << "*\n";
        } else {
            std::cout << queue[0].idx << " " << queue[0].value << "\n";
            std::swap(queue[0], queue[queue.size() - 1]);
            queue.pop_back();
            heapify_down(0);
        }
    }

    void increase(const Data &data) {
        size_t point = 0;
        while (point < queue.size()) {
            if (queue[point].idx == data.idx) {
                queue[point].value += data.value;
                heapify_up(point);
                heapify_down(point);
                break;
            } else {
                point++;
            }
        }
    }

    [[nodiscard]] const Data &max() const { return queue[0]; }
    [[nodiscard]] bool empty() const { return queue.empty(); }
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
            queue.dequeue_max();
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
