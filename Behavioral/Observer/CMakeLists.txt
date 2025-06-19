# Указываем минимальную версию CMake
cmake_minimum_required(VERSION 3.10)

# Настройка проекта
project(ObserverPattern)

# Устанавливаем стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Указываем, где искать заголовочные файлы
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Собираем библиотеку из компонентов Observer
add_library(observer_lib
    ConcreteObserverA.cpp
    ConcreteObserverB.cpp
    ConcreteSubject.cpp
)

# Дополнительные настройки для библиотеки
target_include_directories(observer_lib
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Собираем демо-программу
add_executable(observer_demo main.cpp)

# Связываем демо-программу с библиотекой
target_link_libraries(observer_demo 
    PRIVATE 
    observer_lib
)

# Если есть тесты, добавляем их
if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/tests)
    enable_testing()
    
    # Подключаем GoogleTest
    find_package(GTest REQUIRED)
    include_directories(${GTEST_INCLUDE_DIRS})
    
    # Создаем исполняемый файл для тестов
    add_executable(observer_tests
        tests/test_observer.cpp
    )
    
    # Связываем тесты с библиотеками
    target_link_libraries(observer_tests
        PRIVATE
        observer_lib
        ${GTEST_LIBRARIES}
        pthread
    )
    
    # Добавляем тест в CTest
    add_test(
        NAME ObserverTests
        COMMAND observer_tests
    )
endif()