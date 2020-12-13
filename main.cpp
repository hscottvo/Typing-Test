#include <ncurses.h>
#include <iostream>

#include "Composite/header/init.hpp"

int main() {
    Initializer* main = new Initializer();
    main->run();

    return 0;
}