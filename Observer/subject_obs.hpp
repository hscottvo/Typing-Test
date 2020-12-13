#ifndef __SUBJECT_OBS_HPP__
#define __SUBJECT_OBS_HPP__

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <list>
#include <string>
#include "i_subject.hpp"
#include "i_observer.hpp"
#include "observer_obs.hpp"

using namespace std;

class Subject : public ISubject {
 public:
  virtual ~Subject();

  void Attach(IObserver *observer);
  void Detach(IObserver *observer);
  void Notify();

  void CreateMessage(string message = "Empty");
  void HowManyObserver();

 private:
  list<IObserver *> list_observer_;
  string message_;
};

#endif
