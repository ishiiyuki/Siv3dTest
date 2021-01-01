#pragma once
//#include<initializer_list>
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

	
	// 自機ショットのクールタイム（秒）
	double playerShotCoolTime = 0.1;
	// 自機ショットのクールタイムタイマー
	double playerShotTimer = 0.0;

	// 敵ショットのクールタイム（秒）
	double enemyShotCoolTime = 0.90;
	// 敵ショットのクールタイムタイマー
	double enemyShotTimer = 0.0;


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


	//敵のランダム配置
	Enemy GenerateEnemy();


};

