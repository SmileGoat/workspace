// Copyright 2019 PEACH LAB. All Rights Reserved.
// Author: goat.zhou@foxmail.com

#include "snake/array_snake.h"
#include "snake/snake_controller.h"

int main() {
    unique_ptr<goat::ArraySnake> array_snake(new goat::ArraySnake());
    goat::SnakeController snake_controller(array_snake.get());
    snake_controller.Init();
    snake_controller.Running();
    snake_controller.WaitToStop();
    return 0;
}
