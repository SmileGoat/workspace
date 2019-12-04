// Copyright 2019 PEACH LAB. All Rights Reserved.
// Author: goat.zhou@foxmail.com

#include "snake/array_snake.h"

#include <curses.h>

namespace goat {

void ArraySnake::JudgeDirection(Direction direction,
                                int* y_add, int* x_add) {
  *x_add = 0;
  *y_add = 0;
  switch (direction) {
    case Down: *y_add = 1; break;
    case Up: *y_add = -1; break;
    case Left: *x_add = -1; break;
    case Right: *x_add = 1; break;
  }
}

void ArraySnake::SnakeInit(int head_y, int head_x) {
  y_snake_body_.push_back(head_y);
  x_snake_body_.push_back(head_x);
}

void ArraySnake::SnakeMove(Direction direction) {
  int x_add = 0, y_add = 0;
  JudgeDirection(direction, &y_add, &x_add);
  int new_head = (head_ + y_snake_body_.size() - 1) % y_snake_body_.size();
  y_snake_body_[new_head] = y_snake_body_[head_] + y_add;
  x_snake_body_[new_head] = x_snake_body_[head_] + x_add;
  head_ = new_head;
}

bool ArraySnake::SnakeEatApple(int y_apple_position,
                               int x_apple_position, Direction direction) {
  if (y_apple_position != y_snake_body_[head_]
          || x_apple_position != x_snake_body_[head_] ) return false;
  y_snake_body_.push_back(0);
  x_snake_body_.push_back(0);
  for (size_t idx = y_snake_body_.size() - 1; idx > head_; --idx) {
    y_snake_body_[idx] = y_snake_body_[idx - 1];
    x_snake_body_[idx] = x_snake_body_[idx - 1];
  }
  int x_add = 0, y_add = 0;
  JudgeDirection(direction, &y_add, &x_add);
  x_snake_body_[head_] += x_add;
  y_snake_body_[head_] += y_add;
  return true;
}

void ArraySnake::SnakeShow() const {
  for (size_t idx = 0; idx < y_snake_body_.size(); ++idx) {
    mvaddch(y_snake_body_[idx], x_snake_body_[idx], '*');
  }
}

}  // namespace goat
