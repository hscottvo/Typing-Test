#include "../header/UserList.hpp"

std::string UserList::truncate(double input) {
    std::string not_truncated = std::to_string(input * 100);

    int dec_index = not_truncated.find(".");

    return not_truncated.substr(0, dec_index + 3);
}

void UserList::login(int row, int col) {
    int ch = -1;
    int i = 0;
    erase(); 
    move(0, 0);
    addstr("Press the number of your user. ");
    if(users.size() <= 10) {
        addstr("Press \"a\" to add a new user. Press ESC to exit.");
    }
    mvaddstr(1, 0, "Username");
    mvaddstr(1, 15, "Best WPM");
    mvaddstr(1, 29, "Best Accuracy");
    mvaddstr(1, 44, "User ID");
    if(!users.empty()){
        for(; i < users.size(); ++i) {
            mvaddstr(i+2, 0, users.at(i)->get_username().c_str());
            mvaddstr(i+2, 15, (truncate(users.at(i)->get_highscore()/100.0)).c_str());
            mvaddstr(i+2, 29, (truncate(users.at(i)->get_accuracy())+"%").c_str());
            mvaddstr(i+2, 44, std::to_string(i).c_str());
        }
    }
    
    if(users.size() <= 10){
        mvaddstr(i+3, 0, "Press \"a\" to add a new user. ");
    }
    while (true) {
        ch = getch();
        switch(ch) {
            case 'a': {
                std::string user = get_user_input(row, col);
                int id = users.size();
                users.push_back(new Observer(new Subject(), user, id));
                current_user = users.size()-1;
                return;
            }
            case '0' ... '9': {
                int user = ch - 48;
                if(user > users.size()-1) {
                    continue;
                }
                else {
                    current_user = user;
                    return;
                }
            }
            case 27 : {
                return;
            }
            default : 
            {
                continue;
            }
        }
    }
    erase();
}

std::string UserList::get_user_input(int row, int col) {
    char* msg = "Type in your name. Max 13 characters. Press space to finish.";
    mvaddstr(row/2-1, (col-strlen(msg))/2, msg);
    int ch;
    std::string ret = "";
    ch = getch();
    for(;;){
        attron(A_STANDOUT);
        mvaddstr(row/2, col/2, ret.c_str());
        attroff(A_STANDOUT);
        if (ch >= 33 && ch <= 126) {
            ret += static_cast<char>(ch);
        }
        switch(ch) {
            case ' ':
            {   
                move(row/2, 0);
                clrtoeol();
                return ret;
            }
            case KEY_BACKSPACE:
            {   
                move(row/2, 0);
                clrtoeol();
                if(ret.size() > 0) ret.pop_back();
            }
        }
        ch = getch();
    }
    attroff(A_STANDOUT);
    return ret;
}