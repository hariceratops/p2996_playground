#include <meta>
#include <print>

struct S {
  int a;
  int b; 
};

consteval auto member_number(int n) {
  auto ctx = std::meta::access_context::current();
  return std::meta::nonstatic_data_members_of(^^S, ctx)[n];
}

auto main(void) -> int {
  constexpr auto r = ^^int;
  typename[:r:] x = 42;
  std::println("{}", x);
  return 0;
}
