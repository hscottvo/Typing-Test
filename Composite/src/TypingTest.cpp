#include "../header/TypingTest.hpp"

void TypingTest::run(int max_row, int max_col, Observer* current_user) {

    body->set_max_col(3 * max_col / 4);
    mvaddstr(body->get_row()-1, body->get_col(), "Press ESC to quit test");
    body->display(false, body->get_row(), body->get_col());

    time_t start = start_timer();

    for(unsigned i = body->get_input_size(); i < body->get_ref_size(); ++i) {
        body->add_word(this->get_user_input(max_row, max_col, start));
        if(!running) {
            erase();
            running = true;
            return;
        }
        body->display(false, body->get_row(), body->get_col());
    }
    if(body->get_accuracy() > current_user->get_accuracy()) {
        current_user->set_data(current_user->get_username(), current_user->get_highscore(), body->get_accuracy());
    }
    double wpm = body->get_correct_characters() / 5.0;
    wpm = wpm / (timer / 60.0);
    if(wpm > current_user->get_highscore()) {
        current_user->set_data(current_user->get_username(), wpm, body->get_accuracy());
    }
}

void TypingTest::get_text(int max_row, int max_col) {
    std::vector<std::string> ref = text_gen->generate();
    Passage* a = new Passage(max_row/3, max_col/4, ref);
    body = a;
}

std::string TypingTest::get_user_input(int row, int col, time_t start) {
    int ch;
    std::string ret = "";
    ch = getch();
    for(;;){
        attron(A_STANDOUT);
        mvaddstr(row-1, col/2, ret.c_str());
        attroff(A_STANDOUT);
        update_timer(start);
        display_timer(timer, row, col);
        display_accuracy(col);
        if (ch >= 33 && ch <= 126) {
            ret += static_cast<char>(ch);
        }
        switch(ch) {
            case ' ':
            {   
                move(row-1, 0);
                clrtoeol();
                return ret;
                break;
            }
            case KEY_BACKSPACE:
            {   
                move(row-1, 0);
                clrtoeol();
                if(ret.size() > 0) ret.pop_back();
                break;
            }
            case 27:
            {
                running = false;
                return "";
                break;
            }
        }
        ch = getch();
    }
    attroff(A_STANDOUT);
    return "";
}

time_t TypingTest::start_timer() { 
    time_t timer;
    return time(&timer);

}

void TypingTest::update_timer(time_t start) {
    time_t curr_time;
    time(&curr_time);
    timer = difftime(curr_time, start);
}

void TypingTest::display_timer(int time, int max_row, int max_col) {
    mvaddstr(max_row/4, max_col/2, std::to_string(time).c_str());
}

void TypingTest::display_accuracy(int max_col) {
    std::string accuracy = this->get_accuracy();
    mvaddstr(0, (max_col-accuracy.size())/2+1, this->get_accuracy().c_str());
}

std::string TypingTest::get_accuracy() {
    std::string not_truncated = std::to_string(body->get_accuracy() * 100);

    int dec_index = not_truncated.find(".");

    return not_truncated.substr(0, dec_index + 3) + "%";
    
}

std::string TypingTest::get_wpm() {
    double words = body->get_correct_characters() / 5.0;
    double time = timer;

    std::string ret = std::to_string(words / (timer / 60.0));

    int dec_index = ret.find(".");

    return ret.substr(0,dec_index + 3);
}

void TypingTest::display_results(unsigned row, unsigned col) {
    erase();

    int ch = 0;
    
    for (;;) {
        ch = getch();
        if (ch != -1) { return; }
        std::vector<std::string> msg = {"You have completed your typing test. Here are your results:",
                                        "",
                                        "Accuracy: " + get_accuracy(),
                                        get_wpm() + " WPM",
                                        "",
                                        "Press any key to return to menu"};

        for(unsigned i = 0; i < msg.size(); ++i) {
            mvaddstr(row/3+i, (col-msg.at(i).size())/2, msg.at(i).c_str());
        }
    }
}   

void TypingTest::set_text_gen(TextGenerator* input) {
    if(text_gen != nullptr) {
        delete text_gen;
    }
    text_gen = input;
}