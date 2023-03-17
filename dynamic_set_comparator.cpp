#include <iostream>
#include <set>

enum class Direction { ASC, DESC };

class VariableComparator {
public:
  explicit VariableComparator(Direction &direction)
      : direction_(direction) {}
  bool operator()(const int &lhs, const int &rhs) {
    if (direction_ == Direction::ASC) {
      return lhs < rhs;
    } else if (direction_ == Direction::DESC) {
      return rhs < lhs;
    }
  }
private:
  Direction &direction_;
};

int main() {
  Direction dir = Direction::DESC;
  VariableComparator cmp(dir);
  std::set<int, VariableComparator> closure(cmp);
  closure.insert(2);
  closure.insert(1);
  closure.insert(3);
  dir = Direction::ASC;
  closure.insert(7);
  closure.insert(5);
  closure.insert(6);

  for (const auto &val : closure) {
    std::cout << val << ' ';
  }
  std::cout << '\n';
}

// Result: 3 2 1 5 6 7


