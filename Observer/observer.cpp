#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <list>
#include <string>
#include "i_subject.hpp"
#include "i_observer.hpp"
#include "observer_obs.hpp"
#include "subject_obs.hpp"

using namespace std;
//iobs
 virtual ~IObserver(){};
 virtual void IObserver::Update(const string &message_from_subject) = 0;
//isub
 virtual ~ISubject(){};
 virtual void ISubject:: Attach(IObserver *observer) = 0;
 virtual void ISubject::Detach(IObserver *observer) = 0;
 virtual void ISubject::Notify() = 0;
//sub
 virtual ~Subject() {
    cout << "Goodbye, I was the Subject.\n";
  }

 void Subject::Attach(IObserver *observer) override {
    list_observer_.push_back(observer);
  }
 void Subject::Detach(IObserver *observer) override {
    list_observer_.remove(observer);
  }
 void Subject::Notify() override {
    list<IObserver *>::iterator iterator = list_observer_.begin();
    HowManyObserver();
    while (iterator != list_observer_.end()) {
      (*iterator)->Update(message_);
      ++iterator;
    }
  }
 void Subject::CreateMessage(string message = "Empty") {
    this->message_ = message;
    Notify();
  }
 void Subject::HowManyObserver() {
    std::cout << "There are " << list_observer_.size() << " registered users.\n";
  }

//obs
 Observer::Observer(Subject &subject) : subject_(subject) {
    this->subject_.Attach(this);
    cout << "Hello, User \"" << ++Observer::static_number_ << "\".\n";
    this->number_ = Observer::static_number_;
  }
 virtual ~Observer() {
    cout << "Goodbye, User \"" << this->number_ << "\".\n";
  }

 void Observer::Update(const std::string &message_from_subject) override {
    message_from_subject_ = message_from_subject;
    PrintInfo();
  }
 void Observer::RemoveMeFromTheList() {
    subject_.Detach(this);
    cout << "User \"" << number_ << "\" has unregistered.\n";
  }
 void Observer::PrintInfo() {
    cout << "User \"" << this->number_ << "\": you have a new message --> " << this->message_from_subject_ << "\n";
  }
//obs
//int Observer::static_number_ = 0;
int static_number_=0;
void ClientCode() {
  Subject *subject = new Subject;
  Observer *observer1 = new Observer(*subject);
  Observer *observer2 = new Observer(*subject);
  Observer *observer3 = new Observer(*subject);
  Observer *observer4;
  Observer *observer5;

  subject->CreateMessage("Leaderboard has updated.");
  observer3->RemoveMeFromTheList();

  subject->CreateMessage("A new test has been added to your count.");
  observer4 = new Observer(*subject);

  observer2->RemoveMeFromTheList();
  observer5 = new Observer(*subject);

  observer4->RemoveMeFromTheList();
  observer1->RemoveMeFromTheList();

  delete observer2;
  delete observer1;
  delete subject;
}

int main() {
  ClientCode();
  return 0;
}

