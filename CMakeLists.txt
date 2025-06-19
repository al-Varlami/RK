cmake_minimum_required(VERSION 3.14)
project(RK_Behavioral_Patterns)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Настройка Google Test
option(BUILD_TESTING "Build tests" ON)

if(BUILD_TESTING)
    include(FetchContent)
    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.11.0
    )
    FetchContent_MakeAvailable(googletest)
endif()

# Подключаем компоненты
add_subdirectory(Behavioral/Observer)