#include <iostream>
#include <cstring>

void fill(int& dest, const char* src) {
  dest = std::stoi(src);
}
void fill(double& dest, const char* src) {
  dest = std::stod(src);
}
void fill(bool& dest, const char* src) {
  std::string str = src;
  if (str == "true") {
    dest = true;
  } 
  else if (str == "false") {
    dest = false;
  } else {
    throw std::invalid_argument("error, not a boolean value");
  }
}
void fill(std::string& dest, const char* src) {
  dest = src;
}

template <class ... Args>
void fill_struct(const char** values, Args&& ... args) {
  int i {};
  ([&] {
     fill(args, values[i]);
     i++;
   }(), ...);
}

const char* arr[] = {
  "100",
  "12.23",
  "Kai",
  "true",
};

struct Data {
  int id;
  double balance;
  std::string name;
  bool active_status;

  void deserialize(const char** values) {
    fill_struct(values, id, balance, name, active_status);
  }
};

int main() {
  Data d {};

  d.deserialize(arr);

  std::cout << d.id << ", " << d.balance << ", " << d.name << ", " 
            << d.active_status << "\n";
}
