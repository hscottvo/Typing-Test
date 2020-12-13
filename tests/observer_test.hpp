#ifndef __OBSERVER_TEST_HPP__
#define __OBSERVER_TEST_HPP__

#include "gtest/gtest.h"
#include "../Observer/header/IObserver.hpp"
#include "../Observer/header/Observer.hpp"
#include "../Observer/header/ISubject.hpp"
#include "../Observer/header/Subject.hpp"

TEST(IObserver, AddUser) {
	Subject *subject = new Subject();
	Observer* obs = new Observer (subject, "Brian", 3);
    
    EXPECT_EQ(obs->get_username(), "Brian");
	EXPECT_EQ(obs->get_id(), 3);
}

TEST(Observer, AddUser2) {
    Subject *subject = new Subject();
    Observer* obs = new Observer (subject, "Scott", 1);

    EXPECT_EQ(obs->get_username(), "Scott");
    EXPECT_EQ(obs->get_id(), 1);
}

TEST(Observer, AddUser3) {
    Subject *subject = new Subject();
    Observer* obs = new Observer (subject, "Danin", 2);

    EXPECT_EQ(obs->get_username(), "Danin");
    EXPECT_EQ(obs->get_id(), 2);
}

TEST(Observer, AddUser4) {
    Subject *subject = new Subject();
    Observer* obs = new Observer (subject, " ", 123);

    EXPECT_EQ(obs->get_username(), " ");
    EXPECT_EQ(obs->get_id(), 123 );
}
/*
TEST(Observer, RemoveUser1) {
    Subject *subject = new Subject();
    Observer* obs = new Observer (subject, "Daniel", 123);

    EXPECT_EQ(obs->Detach(*obs), " ");
}
*/
#endif
