#include "Scene/Scenemanager.h"


int main() {
	env;

	Scenemanager Scenemanager_;

	Scenemanager_.Setup();

	while (env.isOpen()) {
		env.begin();
		
		Scenemanager_.Shift();

		Scenemanager_.Draw();
		Scenemanager_.Update();


		env.end();
  }
}
