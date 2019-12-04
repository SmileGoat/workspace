// Copyright 2019 PEACH LAB. All Rights Reserved.
// Author: goat.zhou@foxmail.com

#ifndef SNAKE_SNAKEcONTROLLER_H_
#define SNAKE_SNAKEcONTROLLER_H_

#include "snake/snake_interface.h"
#include "base/basic_types.h"
#include "base/compat.h"

namespace goat {

class SnakeController {
 public:
  SnakeController(SnakeInterface* snake); 
  void Init();
  void ProduceApple(int32* y_apple, int32* x_apple) const;
	void Running();
  int32 WaitToStop();

 private:
  void GetCommandFromKeyboardThreadInternalFunc(); 
	static void* GetCommandFromKeyboardThreadFunc(void* instance); 

	Direction direction_;
  SnakeInterface* snake_;
	bool snake_is_alive_;
	pthread_t thread_id_;
	DISALLOW_COPY_AND_ASSIGN(SnakeController);
};

}

#endif  // SNAKE_SNAKEcONTROLLER_H_
