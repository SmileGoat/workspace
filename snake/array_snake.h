// Copyright 2019 PEACH LAB. All Rights Reserved.
// Author: goat.zhou@foxmail.com

#ifndef SNAKE_ARRAY_SNAKE_H_
#define SNAKE_ARRAY_SNAKE_H_

#include "base/basic_types.h"
#include "base/compat.h"
#include "snake/snake_interface.h"

namespace goat {

class ArraySnake : public SnakeInterface {
 public:
  ArraySnake() {}
  virtual ~ArraySnake() {}
  virtual void SnakeInit(int head_y, int head_x);
  virtual void SnakeMove(Direction direction);
  virtual bool SnakeEatApple(int y_apple_position,
                             int x_apple_position,
                             Direction direction);
  virtual void SnakeShow() const;

 private:
  void JudgeDirection(Direction direction, int* y_add, int* x_add);

  Direction direction_;
  size_t head_;
  vector<int> y_snake_body_;
  vector<int> x_snake_body_;

  DISALLOW_COPY_AND_ASSIGN(ArraySnake);
};

}  // namespace goat
#endif  // SNAKE_ARRAY_SNAKE_H_
