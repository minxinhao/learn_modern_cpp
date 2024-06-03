#include <algorithm>
#include <charconv>
#include <format>
#include <numeric>
#include <ranges>
#include <string>
#include <string_view>

#include "dbg.h"

int persistence(long long n) {
  // Write a function, persistence, that takes in a positive parameter num and
  // returns its multiplicative persistence, which is the number of times you
  // must multiply the digits in num until you reach a single digit.
  int count = 0;
  std::cout << (std::format("persistence {}", n)) << std::endl;
  while (n >= 10) {
    auto str = std::to_string(n);
    n = std::accumulate(str.begin(), str.end(), 1LL,
                        [](long long a, char c) { return a * (c - '0'); });
    std::copy(str.begin(), str.end(),
              std::ostream_iterator<char>(std::cout, " "));
    std::cout << "----->\t" << n << std::endl;
    ++count;
  }
  return count;
}

int main() {
  // 39 --> 3 (because 3*9 = 27, 2*7 = 14, 1*4 = 4 and 4 has only one digit,
  // there are 3 multiplications)
  std::cout << "res" << persistence(39) << std::endl;
  // 999 --> 4 (because 9*9*9 = 729, 7*2*9 = 126, 1*2*6 = 12, and finally 1*2 =
  // 2, there are 4 multiplications)
  std::cout << "res" << persistence(999) << std::endl;

  // 4 --> 0 (because 4 is already a one-digit
  // number, there is no multiplication)
  std::cout << "res" << persistence(4) << std::endl;
  std::cout << "res" << persistence(25) << std::endl;
  std::cout << "res" << persistence(444) << std::endl;
}