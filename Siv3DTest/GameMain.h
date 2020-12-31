#pragma once
#include<initializer_list>

# include <Siv3D.hpp> // OpenSiv3D v0.4.3

#include "Enemy.h"
#include "Player.h"
#include "PlayerBullet.h"
#include "EnemyBullet.h"

class GameMain
{
private:
	
	// ゲームオーバー判定
	bool gameover = false;

	// 大きさ 60 のフォントを用意
	Font font;

	// 猫のテクスチャを用意
	Texture cat;
	// 猫の座標
	Vec2 catPos;

	// 敵の発生間隔の初期値（秒）
	double initialEnemySpawnTime = 2.0;
	// 敵の発生間隔（秒）
	double enemySpawnTime = initialEnemySpawnTime;
	// 敵の発生間隔タイマー
	double enemySpawnTimer = 0.0;

	Effect effect;


	//プレイヤー
	Player gamePlayer;

	Array<PlayerBullet> gamePlayerBullet;

	//敵
	Array<Enemy> gameEnemys;

	Array<EnemyBullet> gameEnemyBullet;




	// ハイスコア
	int32 highScore = 0;
	// 現在のスコア
	int32 score = 0;

public:



	GameMain();

	~GameMain()
	{

	}



	void GameUpdate();

	


};

