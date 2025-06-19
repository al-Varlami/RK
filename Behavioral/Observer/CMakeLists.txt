# Собираем библиотеку из компонентов Observer
add_library(observer_lib
    ConcreteObserverA.cpp
    ConcreteObserverB.cpp
    ConcreteSubject.cpp
)

# Собираем демо-программу
add_executable(observer_demo main.cpp)
target_link_libraries(observer_demo PRIVATE observer_lib)