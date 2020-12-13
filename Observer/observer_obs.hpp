#ifndef __OBSERVER_OBS_HPP__
#define __OBSERVER_OBS_HPP__

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <list>
#include <string>
#include "i_subject.hpp"
#include "i_observer.hpp"
#include "subject_obs.hpp"

using namespace std;

class Observer : public IObserver {
 public:
  Observer(Subject &subject) : subject_(subject);
  virtual ~Observer();
  void Update(const std::string &message_from_subject) override;
  void RemoveMeFromTheList();
  void PrintInfo();

 private:
  string message_from_subject_;
  Subject &subject_;
  static int static_number_;
  int number_;
};

int Observer::static_number_ = 0;

#endif
