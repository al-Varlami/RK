# Тестируем Observer
add_executable(observer_tests
    test_observer.cpp
)

target_link_libraries(observer_tests
    PRIVATE
    observer_lib
    gtest_main
)

enable_testing()
add_test(NAME ObserverTests COMMAND observer_tests)