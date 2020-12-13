#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <list>
#include <string>
#include <vector>
#include "../header/Observer.hpp"
#include "../header/IObserver.hpp"
#include "../header/ISubject.hpp"
#include "../header/Subject.hpp"

using namespace std;

class Subject;
class Observer;

void ClientCode() {
  string response;
  string unregister;
  int userNumber;
  vector<Observer*> list;
  Subject *subject = new Subject();
  list.push_back(new Observer(*subject));
  Observer *observer2 = nullptr;
  while(1){
  cout<< "Do you want to add another user? (y/n)"<<endl;
  cin>>response;
  if (response == "y"){
  list.push_back(new Observer(*subject));
  }
  else if (response == "n"){
  subject->CreateMessage("Leaderboard has updated.");
  break;
  }
  else {
  cout << "invalid" << endl;
  break;
  }
} 
  while(1){
  cout << "Would you like to remove a user? (y/n)" << endl;
  cin>> unregister;
  if (unregister == "y" || unregister == "yes"){
  cout << "which user? (enter user number)" << endl;
  cin>>userNumber;
  }
  if (userNumber == 2){
  list.at(0)->RemoveMeFromTheList();
  delete observer2;
  delete subject;
  break;
  }
  else if (unregister == "n" || unregister == "no"){
  delete subject;
  break;
  }
}
}

int main() {
  ClientCode();
  return 0;
}
