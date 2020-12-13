#ifndef __ISUBJECT_HPP__
#define __ISUBJECT_HPP__

#include "IObserver.hpp"

class ISubject {
 public:
  virtual ~ISubject(){};
  virtual void Attach(IObserver *observer) = 0;
  virtual void Detach(IObserver *observer) = 0;
  //virtual void Notify() = 0;
};

#endif
