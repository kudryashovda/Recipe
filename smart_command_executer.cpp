// Based on
// Abstraction the true superpower of C++ - Guy Davidson - Meeting C++ 2022
// https://www.youtube.com/watch?v=68Y8MKvnFzs

#include <map>
#include <sstream>
#include <iostream>

std::string MATRIX("0 20 30 40 50 60");

using std::literals::string_literals::operator""s;

class Command;

auto options_table = std::map<std::string, Command *>{};

class Command {
public:
  explicit Command(std::string const &id) { options_table.emplace(id, this); }
  virtual ~Command() = default;
  virtual void execute(std::istream &options) = 0;
};

class GetMatrix : public Command {
public:
  GetMatrix() : Command("GETMATRIX"s) {}
  ~GetMatrix() override = default;
  void execute(std::istream &options) override{
    std::string dummy_line;
    getline(options, dummy_line);
    std::cout << MATRIX << '\n';
  }
};
GetMatrix get_matrix;

class SetMatrix : public Command {
public:
  SetMatrix() : Command("SETMATRIX"s) {}
  ~SetMatrix() override = default;
  void execute(std::istream &options) override{
      options.get(); // skip space
      std::getline(options, MATRIX);
  }
};
SetMatrix set_matrix;

void OnDataReceived(std::istream &options) {
  while (options.good()) {
    auto key = std::string{};
    options >> key;
    auto fn = options_table.find(key);
    if (fn != options_table.end()) {
      (*(fn->second)).execute(options);
    }
  }
}

int main() {
  std::stringstream ss;

  ss << "GETMATRIX "s << '\n';
  ss << "SETMATRIX 90 80 70 60 50 40 30"s << '\n';
  ss << "GETMATRIX"s << '\n';

  OnDataReceived(ss);
}
