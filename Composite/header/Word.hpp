#ifndef __WORD_HPP__
#define __WORD_HPP__

#include <string>
#include "ncurses.h"
#include "Text.hpp"
#include <cstring>

class Text;

class Word : public Text {
    private: 
        std::string word;
        std::string reference;
    public: 
        Word() : Text() {};Word(unsigned row, unsigned col) : Text(row, col), word(""), reference(""){}
        Word(std::string input) : Text(), word(""), reference(input) {}
        Word(std::string input, std::string reference) : Text(), word(input), reference(reference) {}
        
        
        void set_word(std::string input);

        void set_reference(std::string input); 

        virtual bool check();

        virtual unsigned len();

        virtual void display(bool curr, unsigned row, unsigned col);
};

#endif
