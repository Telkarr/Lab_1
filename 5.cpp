#include <iostream>
#include <list>
#include <string>
#include <vector>

constexpr size_t P = 300007;  // Размер таблицы. Ближайшее простое > 3*100000
constexpr size_t A = 31;  // Простое и не меньше размера алфавита

size_t hash_str(const std::string &value) {
  size_t h = 0;
  for (char ch : value) {
    h = (h * A + ch) % P;
  }
  return h;
}

class HashMap {
  std::vector<std::list<std::pair<std::string, std::string>>> map;

 public:
  HashMap() : map(P) {}

  void put(const std::string &key, const std::string &value) {
    size_t h = hash_str(key);
    for (auto &i : map[h]) {
      if (i.first == key) {
        i.second = value;
        return;
      }
    }
    map[h].emplace_back(std::make_pair(key, value));
  };
  [[nodiscard]] std::string get(const std::string &key) {
    auto i = hash_str(key);
    auto bucket = map.at(i);
    for (auto &pair : bucket) {
      if (pair.first == key) {
        return pair.second;
      }
    }
    return "null";
  };
  void erase(const std::string &key) {
    auto h = hash_str(key);
    auto &bucket = map.at(h);
    for (auto i = bucket.begin(); i != bucket.end(); i++) {
      if (i->first == key) {
        bucket.erase(i);
        return;
      }
    }
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  HashMap map;

  std::string cmd;
  while (std::cin >> cmd) {
    if (cmd == "put") {
      std::string x;
      std::string y;
      std::cin >> x >> y;
      map.put(x, y);
    } else if (cmd == "get") {
      std::string x;
      std::cin >> x;
      std::cout << map.get(x) << "\n";
    } else if (cmd == "delete") {
      std::string x;
      std::cin >> x;
      map.erase(x);
    } else {
      std::cout << "Unknown command " << cmd;
      return -1;
    }
  }

  return 0;
}