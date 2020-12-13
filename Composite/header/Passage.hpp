#ifndef __PASSAGE_HPP__
#define __PASSAGE_HPP__

#include <vector>
#include <string>
#include "ncurses.h"
#include "Text.hpp"
#include "Word.hpp"

class Text;
class Word;

class Passage : public Text {
    private:
        std::vector<Word*> text;
        unsigned row;
        unsigned col;
        unsigned curr_word = 0;
        unsigned max_col = 0;
    public:
        Passage(unsigned row, unsigned col, std::vector<std::string> input);
        
        virtual unsigned len();

        unsigned get_correct_characters();

        virtual bool check();

        void set_max_col(unsigned i) { max_col = i; }

        void add_word(std::string input);

        unsigned get_input_size() { return curr_word; }

        unsigned get_ref_size() {return text.size(); }

        virtual void display(bool curr, unsigned row, unsigned col); 

        double get_accuracy();
};

#endif