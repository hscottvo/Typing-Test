#include "../header/Word.hpp"

void Word::set_word(std::string input) {
    word = input;
}

void Word::set_reference(std::string input) {
    reference = input;
}

bool Word::check() {
    return word == reference;
}

unsigned Word::len() {
    return reference.size();
}

void Word::display(bool curr, unsigned row, unsigned col) {
    move(row, col);
    for(int i = 0; i < this->len(); ++i) {
        if (curr) {
            if (i == 0) {
                attron(A_STANDOUT);
            }
            else {
                attroff(A_STANDOUT);
            } 
        }
        addch(reference.data()[i]);
    }
    
    // const char* first_char = new char(reference.data()[0]);
    // const char* rest = &reference.data()[1];
    // if(curr) attron(A_STANDOUT);
    // mvaddstr(row, col, first_char);
    // if(curr) attroff(A_STANDOUT);
    // addstr(rest);
    // attroff(A_STANDOUT);
}
