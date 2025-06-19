# Подключаем GoogleTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(observer_tests
    test_observer.cpp
)

# Связываем с нашей библиотекой и GTest
target_link_libraries(observer_tests
    PRIVATE
    observer_lib
    ${GTEST_LIBRARIES}
    pthread
)

enable_testing()
add_test(NAME ObserverTests COMMAND observer_tests)