#include "../header/Observer.hpp"

Observer::Observer(Subject* subject, std::string username, int id) : subject(subject), id_number(id) {
  subject->set_username(username);
  subject->set_id(id);
}
/*
void Observer::Update(const std::string &message_from_subject) {
    message_from_subject_ = message_from_subject;
    PrintInfo();
}
void PrintInfo() {
    cout << "User: \"" << this->username << "\": you have a new message --> " << this->message_from_subject_ << "\n";
}
*/
std::string Observer::get_username() {
  return subject->get_username();
}
int Observer::get_id() {
  return subject->get_id();
}
double Observer::get_highscore() {
  return subject->get_highscore();
}
double Observer::get_accuracy() {
  return subject->get_accuracy();
}
void Observer::set_data(std::string input_user, double score, double acc) {
    subject->set_username(input_user);
    subject->set_highscore(score);
    subject->set_accuracy(acc);
}

