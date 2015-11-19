#pragma once
#include "../../lib/framework.hpp"
#include "../../Share.h"
#include "../../Classbase.h"


class Result : public Classbase{
private:
    bool iswin;
    Texture win;
    Texture loos;
    Media winse;// = Media("res/Media/Result/win.wav");
    Media loosse;// = Media("res/Media/Result/lost.wav");
public:
	Result();

	void Setup();
	void Update();
	void Draw();
	Scenename Shift();

    void SetWin(bool _win);
};