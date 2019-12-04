// Copyright 2019 PEACH LAB. All Rights Reserved.
// Author: goat.zhou@foxmail.com

#include "snake/snake_controller.h"

#include <curses.h>
#include <stdlib.h>
#include <unistd.h>

namespace goat {

SnakeController::SnakeController(SnakeInterface* snake) {
  snake_is_alive_ = true;
  snake_ = snake;
}

void SnakeController::Init() {
  initscr();
  cbreak();
  nonl();
  noecho();
  intrflush(stdscr, FALSE);
  keypad(stdscr, TRUE);
  box(stdscr, ACS_VLINE, ACS_HLINE);
  curs_set(0);
  snake_->SnakeInit(LINES/2,  COLS/2);
}

void SnakeController::Running() {
  int32 y_apple, x_apple;
  ProduceApple(&y_apple, &x_apple);
  pthread_create(&thread_id_, NULL,
                 this->GetCommandFromKeyboardThreadFunc, this);

  while (snake_is_alive_) {
    clear();
    box(stdscr, ACS_VLINE, ACS_HLINE);
    mvaddch(y_apple, x_apple, '$');
    snake_->SnakeMove(direction_);
    snake_->SnakeShow();
    if (snake_->SnakeEatApple(y_apple, x_apple, direction_)) {
      ProduceApple(&y_apple, &x_apple);
    }
    sleep(1);
    refresh();
  }
}

int32 SnakeController::WaitToStop() {
//  int32 score = snake_->GetScore();
  sleep(4);
  pthread_join(thread_id_, NULL);
  endwin();
  return 0;
}

void SnakeController::ProduceApple(int* apple_y, int* apple_x) const {
    *apple_y = rand() % LINES;
    *apple_x = rand() % COLS;
}

void* SnakeController::GetCommandFromKeyboardThreadFunc(void* instance) {
  SnakeController* controller = reinterpret_cast<SnakeController*> (instance);
  controller->GetCommandFromKeyboardThreadInternalFunc();
  return NULL;
}

void SnakeController::GetCommandFromKeyboardThreadInternalFunc() {
  while (snake_is_alive_) {
    int key = getch();
    switch (key) {
      case KEY_DOWN: direction_ = Down; break;
      case KEY_UP: direction_ = Up; break;
      case KEY_LEFT: direction_ = Left; break;
      case KEY_RIGHT: direction_ = Right; break;
      default: snake_is_alive_ = false;
    }
  }
}

}  // namespace goat
