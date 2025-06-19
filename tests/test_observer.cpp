#include <gtest/gtest.h>
#include "ConcreteObserverA.h"
#include "ConcreteObserverB.h"
#include "ConcreteSubject.h"

class ObserverTest : public ::testing::Test {
protected:
    void SetUp() override {
        subject = new ConcreteSubject();
        observerA = new ConcreteObserverA(0);
        observerB = new ConcreteObserverB(0);
    }

    void TearDown() override {
        delete subject;
        delete observerA;
        delete observerB;
    }

    ConcreteSubject* subject;
    ConcreteObserverA* observerA;
    ConcreteObserverB* observerB;
};

TEST_F(ObserverTest, InitialState) {
    EXPECT_EQ(observerA->getState(), 0);
    EXPECT_EQ(observerB->getState(), 0);
}

TEST_F(ObserverTest, SingleObserverNotification) {
    subject->add(observerA);
    subject->setState(5);
    subject->notify();
    
    EXPECT_EQ(observerA->getState(), 5);
    EXPECT_EQ(observerB->getState(), 0); // Не должен измениться
}

TEST_F(ObserverTest, MultipleObserversNotification) {
    subject->add(observerA);
    subject->add(observerB);
    subject->setState(10);
    subject->notify();
    
    EXPECT_EQ(observerA->getState(), 10);
    EXPECT_EQ(observerB->getState(), 10);
}

TEST_F(ObserverTest, StateChangeWithoutNotification) {
    subject->add(observerA);
    subject->setState(15);
    // Не вызываем notify()
    
    EXPECT_EQ(observerA->getState(), 0); // Не должен измениться
}