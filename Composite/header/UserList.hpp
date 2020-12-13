#ifndef __USERLIST_HPP__
#define __USERLIST_HPP__

#include "../../Observer/header/Observer.hpp"
#include "../../Observer/header/Subject.hpp"
#include "ncurses.h"
#include <vector>
#include <string>
#include <cstring>

class UserList {
    private:
        std::vector<Observer*> users;

        std::string truncate(double input);

        int current_user = -1;
    public: 
        int get_curr_user_num() { return current_user; }
        int get_num_users() { return users.size(); }
        void login(int row, int col);
        std::string get_user_input(int row, int col);

        Observer* get_current_user() { if(users.size() > 0) return users.at(current_user); else return nullptr;}

};

#endif 