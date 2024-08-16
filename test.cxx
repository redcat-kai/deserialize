#include <iostream>
#include <array>

constexpr int mult(int a, int b, int limit) { 
  int ret = 0;

  for (int i=0; i<limit; i++) {
    ret += a*b;
  }

  return ret;
}

int main() {
  constexpr int SIZE = mult(2, 3, 10);

  std::array<int, SIZE> arr;
  std::cout <<  arr.size() << "\n";
}
