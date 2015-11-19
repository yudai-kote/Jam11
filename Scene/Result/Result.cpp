#include "Result.h"

Result::Result(){

    Setup();

}


void Result::Setup()
{
   /* win = Texture("res/");
    loos = Texture("res/");
*/
    loosse = Media("res/Media/BGM/Result/lost.wav");
    winse = Media("res/Media/BGM/4Result/win.wav");
}

void Result::Update(){

}

void Result::Draw(){
    if (iswin)
    {

        drawFillBox(-WIDTH / 2, -HEIGHT / 2, WIDTH, HEIGHT, Color::red);
        //drawTextureBox(-WIDTH / 2, -HEIGHT / 2, WIDTH, HEIGHT, 0, 0, , , win);
        if (!winse.isPlaying()){
            winse.play();
        }
    }
    else
    {
        drawFillBox(-WIDTH / 2, -HEIGHT / 2, WIDTH, HEIGHT, Color::green);
        //drawTextureBox(-WIDTH / 2, -HEIGHT / 2, WIDTH, HEIGHT, 0, 0, , , loos);

        if (!loosse.isPlaying()){
            loosse.play();
        }
    }
}


Scenename Result::Shift(){
	if (env.isPushKey(GLFW_KEY_ENTER)){
		return Scenename::TITLE;
	}
    return Scenename::RESULT;
}

void Result::SetWin(bool _win){
    iswin = _win;
}