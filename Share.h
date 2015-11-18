#pragma once
#include "lib\framework.hpp"
#include <iostream>
#include <string>
#include <vector>

#define env App::Get()


enum WindowSize{
	WIDTH = 1024,
	HEIGHT = 1024,
};

class App{
public:
	static AppEnv& Get(){
		static AppEnv singleton_env(WIDTH, HEIGHT, false, true);
		return singleton_env;
	}
};


enum class Scenename{
	TITLE,
	STAGESELECT,
	GAMEMAIN,
	RESULT,
};

enum class Ismove{
	STOP,
	MOVE,
};

enum class Direction{
	UP,
	DOWN,
	LEFT,
	RIGHT,

	NONE,
};

enum class Item{
	ROBOT,
	COMIC,


};