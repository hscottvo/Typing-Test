#ifndef __OBSERVER_HPP__
#define __OBSERVER_HPP__

#include "IObserver.hpp"
#include "ISubject.hpp"
#include "Subject.hpp"

class Subject;

class Observer : public IObserver {
    private: 
        Subject* subject;
        int id_number;
		//message
		//std::string message_from_subject_;
    public: 
        Observer(Subject* subject, std::string username, int id);
        void remove();
		//update
  		//virtual void Update(const std::string &message_from_subject);
		//void PrintInfo();

        std::string get_username();
		int get_id();
        double get_highscore();
        double get_accuracy();

        void set_data(std::string input_user, double score, double acc);
};

#endif
