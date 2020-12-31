#pragma once
#include<initializer_list>

# include <Siv3D.hpp> // OpenSiv3D v0.4.3

class GameMain
{
private:
	


public:

	// 大きさ 60 のフォントを用意
	Font font;

	// 猫のテクスチャを用意
	Texture cat;
	// 猫の座標
	Vec2 catPos;

	GameMain();

	~GameMain()
	{

	}



	void GameUpdate();

	


};

