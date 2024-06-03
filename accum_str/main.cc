#include <charconv>
#include <format>
#include <numeric>
#include <ranges>
#include <string>
#include <string_view>

#include "dbg.h"

std::string accum_opt(const std::string& s) {
  // 对第i个char c,输出一个大C，i个小c
  auto [oss, cnt] = std::accumulate(
      s.begin(), s.end(), std::make_tuple(std::ostringstream{}, 0),
      [](std::tuple<std::ostringstream, int> res, char c) {
        auto& [oss, idx] = res;
        oss <<  static_cast<char>(std::toupper(c));
        oss << std::string(idx, std::tolower(c));
        oss << '-';
        idx++;
        return std::make_tuple(std::move(oss), idx);
      });

  std::string result = oss.str();
  if (!result.empty() && result.back() == '-') {
    result.pop_back();  // 移除最后的多余的 '-'
  }

  return result;
}

std::string accum(const std::string& s) {
  // 对第i个char c,输出一个大C，i个小c
  auto [str, cnt] =
      std::accumulate(s.begin(), s.end(), std::make_tuple(std::string{}, 0),
                      [](std::tuple<std::string, int> res, char c) {
                        auto& [str, idx] = res;
                        str.push_back(std::toupper(c));
                        str.append(idx, std::tolower(c));
                        str.push_back('-');
                        idx++;
                        return std::make_tuple(str, idx);
                      });
  if (!str.empty() && str.back() == '-') {
    str.pop_back();  // 移除最后的多余的 '-'
  }
  return str;
}

int main() {
  // accum("abcd") -> "A-Bb-Ccc-Dddd"
  dbg(accum("abcd"),accum_opt("abcd"));
  // accum("RqaEzty") -> "R-Qq-Aaa-Eeee-Zzzzz-Tttttt-Yyyyyyy"
  dbg(accum("RqaEzty"),accum_opt("RqaEzty"));
  // accum("cwAt") -> "C-Ww-Aaa-Tttt"
  dbg(accum("cwAt"),accum_opt("cwAt"));
  // dotest("ZpglnRxqenU",
  // "Z-Pp-Ggg-Llll-Nnnnn-Rrrrrr-Xxxxxxx-Qqqqqqqq-Eeeeeeeee-Nnnnnnnnnn-Uuuuuuuuuuu");
  dbg(accum("ZpglnRxqenU"),accum_opt("ZpglnRxqenU"));
  // dotest("NyffsGeyylB",
  // "N-Yy-Fff-Ffff-Sssss-Gggggg-Eeeeeee-Yyyyyyyy-Yyyyyyyyy-Llllllllll-Bbbbbbbbbbb");
}