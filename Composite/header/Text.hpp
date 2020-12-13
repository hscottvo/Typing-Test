#ifndef __TEXT_HPP__
#define __TEXT_HPP__


#include <string>
#include "ncurses.h"

class Text {
    private:
        unsigned row;
        unsigned col;
    public: 
    Text() : row(0), col(0) {} 
    Text(unsigned row, unsigned col) : row(row), col(col) {}

    void set_pos(unsigned row, unsigned col) { this->row = row, this->col = col;}

    unsigned get_row() { return row; }
    unsigned get_col() { return col; }

    virtual unsigned len() = 0;

    virtual bool check() = 0;

    virtual void display(bool curr, unsigned row, unsigned col) = 0;
};

#endif
