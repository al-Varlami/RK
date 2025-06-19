#include <gtest/gtest.h>
#include "Behavioral/Observer/ConcreteObserverA.h"
#include "Behavioral/Observer/ConcreteObserverB.h"
#include "Behavioral/Observer/ConcreteSubject.h"

TEST(ObserverTest, ObserverANotification) {
    ConcreteSubject subject;
    ConcreteObserverA observer(0);
    
    subject.add(&observer);
    subject.setState(5);
    subject.notify();
    
    EXPECT_EQ(observer.getState(), 5);
}

TEST(ObserverTest, ObserverBNotification) {
    ConcreteSubject subject;
    ConcreteObserverB observer(0);
    
    subject.add(&observer);
    subject.setState(10);
    subject.notify();
    
    EXPECT_EQ(observer.getState(), 10);
}

TEST(ObserverTest, MultipleObservers) {
    ConcreteSubject subject;
    ConcreteObserverA obsA(0);
    ConcreteObserverB obsB(0);
    
    subject.add(&obsA);
    subject.add(&obsB);
    subject.setState(15);
    subject.notify();
    
    EXPECT_EQ(obsA.getState(), 15);
    EXPECT_EQ(obsB.getState(), 15);
}