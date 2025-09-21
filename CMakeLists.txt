
cmake_minimum_required(VERSION 3.20)
project(struct_cast)

set(LIBCXX_INSTALL "/usr/local/clang/21.0.0")

add_executable(p2996 p2996.cpp)

include_directories(
  SYSTEM
  ${LIBCXX_INSTALL}/include/c++/v1
  ${LIBCXX_INSTALL}/include/x86_64-unknown-linux-gnu/c++/v1
)

target_compile_options(
  p2996 PRIVATE
  -nostdinc++
  -nostdlib++
  "$<$<COMPILE_LANGUAGE:CXX>:-isystem${LIBCXX_INSTALL}/include/c++/v1>"
  "$<$<COMPILE_LANGUAGE:CXX>:-isystem${LIBCXX_INSTALL}/include/x86_64-unknown-linux-gnu/c++/v1>"
  -std=c++26
  -Wall 
  -Wextra 
  -Wpedantic 
  -freflection-latest
)

target_link_options(
  p2996 PRIVATE
  -L${LIBCXX_INSTALL}/lib/x86_64-unknown-linux-gnu
  -Wl,-rpath,${LIBCXX_INSTALL}/lib/x86_64-unknown-linux-gnu
  -lc++
)

