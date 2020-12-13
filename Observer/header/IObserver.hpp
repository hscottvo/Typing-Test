#ifndef __IOBSERVER_HPP__
#define __IOBSERVER_HPP__

#include <string>

class IObserver {
 public:
  virtual ~IObserver(){};
/*update
  virtual void Update(const std::string &message_from_subject) = 0;*/
};

#endif
