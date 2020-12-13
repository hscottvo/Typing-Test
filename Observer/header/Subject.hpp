#ifndef __SUBJECT_HPP__
#define __SUBJECT_HPP__

#include "ISubject.hpp"
#include "IObserver.hpp"
#include "Observer.hpp"
#include <string>
#include <list>

class Subject : public ISubject {
    private: 
        std::list<IObserver *> list_observer_;
        std::string message_;
        std::string username;
		int id;
        double highscore;
        double accuracy;
    public: 
        virtual void Attach(IObserver *observer);
        virtual void Detach(IObserver *observer);
		//virtual void Notify();
		/*
		virtual void CreateMessage(std::string message = "Empty");
		virtual void HowManyObserver();
		*/
        int len();
        void set_username(std::string input);
		void set_id(int input);
        void set_highscore(double input);
        void set_accuracy(double input);

        std::string get_username();
		int get_id();
        double get_highscore();
        double get_accuracy();
};

#endif

