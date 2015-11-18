#include "Result.h"

Result::Result(){



}


void Result::Setup(){

}

void Result::Update(){

}

void Result::Draw(){

}


Scenename Result::Shift(){
	if (env.isPushKey(GLFW_KEY_ENTER)){
		return Scenename::STAGESELECT;
	}
}