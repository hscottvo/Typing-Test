#ifndef __INIT_HPP__
#define __INIT_HPP__

#include "ncurses.h"
#include "TypingTest.hpp"
#include "../../Observer/header/Observer.hpp"
#include "../../Observer/header/Subject.hpp"
#include "UserList.hpp"
#include <cstring>
#include <string>
#include <vector>
#include <unistd.h>
#include <iostream>
#include <time.h>

class Initializer {
    public: 
        void run();
    private:
        TypingTest* test = new TypingTest();
        UserList* data = new UserList();
        void show_menu(int row, int col);
        void show_settings(int row, int col); 
        
};

#endif