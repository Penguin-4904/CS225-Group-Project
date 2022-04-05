#include "Stack.h"

Stack::Stack(int rw, int rh) : Board(20, 50), direction{true}, rect_height{rh}, layer{2}, rect_width{rw}, gameOver(false), inFlag(false) {
    objects.push_back(std::make_shared<Rect>(Rect(rect_width, rect_height, (width - rect_width)/2, height - rect_height)));
    objects.push_back(std::make_shared<Rect>(Rect(rect_width, rect_height, 0, height - layer * rect_height)));
    inputThread = std::thread(&Stack::input_thread_fun, this);
    gameThread = std::thread(&Stack::game_thread_fun, this);
}

bool Stack::step() {
    int x_block = objects.back()->posX();
    int x_tower = objects.end()[-2]->posX();
    if (inFlag) {
        inFlag = false;
        rect_width -= abs(x_block - x_tower);
        if (rect_width <= 0) {
            return true;
        }
        objects.pop_back();
        objects.push_back(std::make_shared<Rect>(Rect(rect_width, rect_height, std::max(x_block, x_tower), height - layer * rect_height)));
        layer++;
        objects.push_back(std::make_shared<Rect>(Rect(rect_width, rect_height, 0, height - layer * rect_height)));
    }
    else{
        if (x_block + rect_width >= width) {
            direction = false;
        }
        if (x_block <= 0) {
            direction = true;
        }
        objects.back()->setX(x_block + (direction - .5) * 2);
    }
    return false;
}

void Stack::display() {
    clear();
    if (!gameOver){
        this->print();
        move(0, 0);
        std::string score = "Score: " + std::to_string(layer - 2);
        addstr(score.c_str());
    } else {
        std::string text = "Game Over!";
        move(height/2, (width/2.0 - text.length()/2.0));
        addstr("Game Over!");
        std::string score = "Score: " + std::to_string(layer - 2);
        move(height/2 + 1, (width/2.0 - score.length()/2.0));
        addstr(score.c_str());
        move(0,0);
    }
    refresh();
}

void Stack::game_thread_fun() {
    while (!gameOver) {
        gameOver = this->step();
        this->display();
        std::this_thread::sleep_for(std::chrono::milliseconds(int(100 * exp((2 - layer)/4.0) + 50)));
    }
}

void Stack::input_thread_fun() {
     do {
        std::cin.ignore();
        inFlag = true;
    } while (!gameOver);
}

Stack::~Stack() {
    inputThread.join();
    gameThread.join();

    time_t now = time(0);
    char* date_time = ctime(&now);

    std::string name = "Stack " + std::string(date_time) + ".txt";
    std::ofstream fout(name);
    if (fout.is_open()) {
        std::string score = "Score: " + std::to_string(layer - 2);
        fout << *this << score;
    }
}



