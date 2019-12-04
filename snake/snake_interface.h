// Copyright 2019 PEACH LAB. All Rights Reserved.
// Author: goat.zhou@foxmail.com

#ifndef SNAKE_SNAKE_INTERFACE_H_
#define SNAKE_SNAKE_INTERFACE_H_

enum Direction {
  Down = 0,
  Up = 1,
  Left = 2,
  Right = 3,
};

class SnakeInterface {
 public:
  virtual ~SnakeInterface() {}
  virtual void SnakeInit(int head_y, int head_x) = 0;
  virtual void SnakeMove(Direction direction) = 0;
  virtual bool SnakeEatApple(int y_apple_postion,
                             int x_apple_position,
                             Direction direction) = 0;
  virtual void SnakeShow() const = 0;
};

#endif  // SNAKE_SNAKE_INTERFACE_H_
