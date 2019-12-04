# Copyright 2019 PEACH LAB. All Rights Reserved.
# Author: goat.zhou@foxmail.com

package(default_visibility = ['//visibility:public'])

cc_library(
  name = "array_snake", 
	srcs = ["array_snake.cc"],
	hdrs = [
	    "array_snake.h",
	    "snake_interface.h"
	],
	deps = [
	    "//base:compat",
	],
)

cc_library(
  name = "snake_controller",
	srcs = ["snake_controller.cc"],
	hdrs = [
	    "snake_controller.h",
	  	"snake_interface.h"
	],
	deps = [
	    "//base:compat",
	],
	linkopts = ["-lpthread"],
)

cc_binary(
  name = "snake_main",
	srcs = ["snake_main.cc"],
	deps = [
	    ":snake_controller",
	    ":array_snake",
	],
	linkopts = ["-lcurses"],
)
