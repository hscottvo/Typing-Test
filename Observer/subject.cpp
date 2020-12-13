#include <iostream>
#include <vector>

using namespace std;

class Subject {
    vector < class Observer * > players;
    int score;
  public:
    void attach(Observer *obs) {
        views.push_back(obs);
    }
    void setVal(int val) {
        value = val;
        notify();
    }
    int getVal() {
        return value;
    }
    void notify();
};

