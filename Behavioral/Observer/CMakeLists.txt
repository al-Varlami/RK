cmake_minimum_required(VERSION 3.10)
project(ObserverPattern)

# Библиотека компонентов
add_library(observer_lib
    ConcreteObserverA.cpp
    ConcreteObserverB.cpp
    ConcreteSubject.cpp
)

target_include_directories(observer_lib
    PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}
)

# Демо-программа
add_executable(observer_demo main.cpp)
target_link_libraries(observer_demo PRIVATE observer_lib)

# Тесты (если включены и папка существует)
if(BUILD_TESTING AND EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/../tests)
    add_executable(observer_tests
        ${CMAKE_CURRENT_SOURCE_DIR}/../tests/test_observer.cpp
    )
    
    target_link_libraries(observer_tests
        PRIVATE
        observer_lib
        gtest_main
    )
    
    add_test(NAME ObserverTests COMMAND observer_tests)
endif()