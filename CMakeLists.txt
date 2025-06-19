cmake_minimum_required(VERSION 3.14)
project(RK_Behavioral_Patterns)

set(CMAKE_CXX_STANDARD 17)

# Подключаем Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

# Подключаем подпроекты
add_subdirectory(Behavioral/Observer)
add_subdirectory(tests)