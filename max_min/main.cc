#include <algorithm>
#include <charconv>
#include <format>
#include <ranges>
#include <string>
#include <string_view>

#include "dbg.h"
std::string highAndLow(const std::string& numbers) {
  // your code here
  auto res = numbers | std::views::split(' ') |
             std::views::transform([](auto&& subrange) {
               std::string_view token(subrange.begin(), subrange.end());
               int32_t res;
               std::from_chars(token.begin(), token.end(), res);
               dbg(subrange,res);
               return res;
             }) |
             std::views::common;
  auto [min, max] = std::ranges::minmax(res);

  return std::format("{} {}", min, max);
}

int main() {
  std::string src = "8 3 -5 42 -1 0 0 -9 4 7 4 -4";
  dbg(highAndLow(src));
}