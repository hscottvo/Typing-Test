#include "../header/Subject.hpp"

void Subject::Attach(IObserver *observer) {
    list_observer_.push_back(observer);
}

void Subject::Detach(IObserver *observer) {
    list_observer_.remove(observer);
}
/*notify
void Subject::Notify() {
    std::list<IObserver *>::iterator iterator = list_observer_.begin();
    HowManyObserver();
    while (iterator != list_observer_.end()) {
      (*iterator)->Update(message_);
      ++iterator;
  }
}
//createmessage
void Subject::CreateMessage(std::string message = "Empty") {
    this->message_ = message;
    Notify();
}
//Howmanyusers
void Subject::HowManyObserver() {
    std::cout << "There are " << list_observer_.size() << " registered users.\n";
}
*/
int Subject::len() {
    return list_observer_.size();
}

void Subject::set_username(std::string input) { 
    username = input; 
}

void Subject::set_id(int input) {
    id = input;
}

void Subject::set_highscore(double input) {
    if(input > highscore) {
        highscore = input;
    }
}

void Subject::set_accuracy(double input) {
    if(input > accuracy) {
        accuracy = input;
    }
}

std::string Subject::get_username() {
    return this->username;
}

int Subject::get_id() {
    return this->id;
}

double Subject::get_highscore() {
    return this->highscore;
}

double Subject::get_accuracy() {
    return this->accuracy;
}

