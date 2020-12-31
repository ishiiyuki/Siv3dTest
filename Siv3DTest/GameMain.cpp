#include "GameMain.h"


GameMain::GameMain()
{
	// 背景のいろ
	Scene::SetBackground(ColorF(0.1, 0.2, 0.7));

	font = Font(60);

	cat = Texture(Emoji(U"🐈"));

	catPos = Vec2(640, 450);

}



void GameMain::GameUpdate()
{






}