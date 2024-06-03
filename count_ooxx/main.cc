#include <algorithm>
#include <charconv>
#include <format>
#include <ranges>
#include <string>
#include <string_view>

#include "dbg.h"

bool XO(const std::string& str) {
  // your code here
  auto lower =
      str | std::views::transform([](char c) { return std::tolower(c); });
  return std::ranges::count(lower, 'o') == std::ranges::count(lower, 'x');
}

int main() {
  dbg(XO("ooxx"));
  // XO("ooxx") => true
  dbg(XO("xooxx"));
  // XO("xooxx") => false
  dbg(XO("ooxXm"));
  // XO("ooxXm") => true
  dbg(XO("zpzpzpp"));
  // XO("zpzpzpp") => true // when no 'x' and 'o' is present should return true
  dbg(XO("zzoo"));
  // XO("zzoo") => false
}