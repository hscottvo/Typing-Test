#include "../header/init.hpp"

void Initializer::run() {
    initscr();
    int row, col, ch;

    // gets the size of the terminal
    getmaxyx(stdscr, row, col);

    // lets program run without waiting for a character input
    nodelay(stdscr, TRUE);

    // enables numpad
    keypad(stdscr, TRUE);

    // allows program to take in input immediately
    cbreak();

    // starts with program not echoing user input
    noecho();

    show_menu(row, col);

    // menu loop
    for(;;) {
        // get user input
        ch = getch();
        // a += character;
        switch(ch) {
            case 'l':
            {
                data->login(row, col);
                show_menu(row, col);
                break;
            }
            case 'p':
                srand(std::time(NULL));
                test->get_text(row, col);
                erase();
                test->run(row, col, data->get_current_user());
                test->display_results(row, col);
                show_menu(row, col);
                break;
            case 's': 
            {
                show_settings(row, col);
                show_menu(row, col);
                break;
            }
            case 'q':
                move(0, 0);
                endwin();
                return;
        }
    }
}



void Initializer::show_menu(int row, int col) {
    erase();
    if(data->get_curr_user_num() >= 0) {
        mvaddstr(0, 0, "Current user: ");
        addstr(data->get_current_user()->get_username().c_str());
        mvaddstr(1, 0,"Press L to show user list. ");
    } 
    else {
        mvaddstr(0, 0, "Press L to create a new user.");
    }

    char settings_message[] = "Press S for Settings";
    mvprintw(0, col - strlen(settings_message), settings_message);

    std::vector<std::string> welcome;
    welcome.push_back("Welcome to our typing test!");
    welcome.push_back("Press L to login/logout. Press P to play. Press S for settings. Pres Q to quit.");
    welcome.push_back("");
    welcome.push_back("Created by Brian Arciga, Danin Namiranian, and Scott Vo");
    for (unsigned i = 0; i < welcome.size(); ++i) {
        mvprintw(row/3 + i, (col-welcome.at(i).size())/2, welcome.at(i).c_str());
    }
}

void Initializer::show_settings(int row, int col) {
    erase();
    attroff(A_STANDOUT);
    mvaddstr(0, 0, "Press 0 to set the test type to Random Words");
    mvaddstr(1, 0, "Press 1 to set the test type to Random Paragraph");
    mvaddstr(2, 0, "Press 2 to set the test type to Random Quote");
    mvaddstr(3, 0, "Press ESC to exit");


    int ch = getch();

    while(ch < 1) {
        ch = getch();
        switch(ch) {
            case '0': {
                test->set_text_gen(new WordSetGenerator(new Language_English()));
                break;
            }
            case '1': {
                test->set_text_gen(new ParagraphGenerator(new Language_English()));
                break;
            }
            case '2': {
                test->set_text_gen(new QuoteGenerator(new Language_English()));
                break;
            }
            default: {
                continue;
            }
        }
    }
}

