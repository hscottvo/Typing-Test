#include "../header/Passage.hpp"
#include <iostream>

Passage::Passage(unsigned row, unsigned col, std::vector<std::string> input) 
 : Text(row, col) {
    for (unsigned i = 0; i < input.size(); ++i) {
        Word* new_word = new Word();
        new_word->set_reference(input.at(i));

        text.push_back(new_word);
    }
}

unsigned Passage::len() {
    unsigned x = 0;
    for (unsigned i = 0; i < text.size(); ++i) {
        x += text.at(i)->len();
    }
    return x;
}

unsigned Passage::get_correct_characters() {
    unsigned x = 0;

    for(int i = 0; i < text.size(); ++i) {
        if (text.at(i)->check()) {
            x += text.at(i)->len(); 
        }
    }
    return x;
}

void Passage::add_word(std::string input) {
    text.at(curr_word)->set_word(input);
    curr_word++;
}

bool Passage::check() {
    for (unsigned i = 0; i < text.size(); ++i) {
        if (!text.at(i)->check()) {
            return false;
        }
    }
    return true;
}

void Passage::display(bool curr, unsigned row, unsigned col) {
    unsigned curr_row = row + 1;
    unsigned curr_col = col;
    unsigned i = 0;
    for(; i < text.size(); ++i) {
        if(curr_col + text.at(i)->len() > max_col) {
            curr_col = col;
            curr_row += 1;
        }
        if(i < curr_word && !text.at(i)->check()) attron(A_STANDOUT);
        text.at(i)->display(i == curr_word, curr_row, curr_col);
        attroff(A_STANDOUT);
        
        // if(i < curr_word && !text.at(i)->check()) {
        //     attron(A_STANDOUT);
        //     text.at(i)->display(curr_row, curr_col); 
        //     attroff(A_STANDOUT);
        // }
        // else if (i >= curr_word) text.at(i)->display(curr_row, curr_col);
        addstr(" ");
        curr_col += text.at(i)->len() + 1;
    }

}

double Passage::get_accuracy() {
    if(this->len() == 0) { return 0; } 
    return this->get_correct_characters() / static_cast<double>(this->len());
}