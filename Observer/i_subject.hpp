#ifndef __I_SUBJECT_HPP__
#define __I_SUBJECT_HPP__

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <list>
#include <string>
#include "i_observer.hpp"
#include "observer_obs.hpp"
#include "subject_obs.hpp"

using namespace std;

class ISubject {
 public:
  virtual ~ISubject(){};
  virtual void Attach(IObserver *observer) = 0;
  virtual void Detach(IObserver *observer) = 0;
  virtual void Notify() = 0;
};

#endif
