#ifndef __I_OBSERVER_HPP__
#define __I_OBSERVER_HPP__

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <list>
#include <string>
#include "i_subject.hpp"
#include "observer_obs.hpp"
#include "subject_obs.hpp"

using namespace std;

class IObserver {
 public:
  virtual ~IObserver();
  virtual void Update(const string &message_from_subject);
};

#endif
