#pragma once
//#include<initializer_list>
# include <Siv3D.hpp> // OpenSiv3D v0.4.3

#include "Enemy.h"
#include "Player.h"
#include "PlayerBullet.h"
#include "EnemyBullet.h"
#include "HomingBullet.h"

class GameMain
{
private:
	
	// ゲームオーバー判定
	bool gameover = false;

	// 大きさ 60 のフォントを用意
	Font font;
	Font gameoverfont;

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

	Array<HomingBullet> gameHomingBullet;

	//敵
	Array<Enemy> gameEnemys;

	Array<EnemyBullet> gameEnemyBullet;


	// 自機ショットのクールタイム（秒）
	double playerShotCoolTime = 0.5;
	// 自機ショットのクールタイムタイマー
	double playerShotTimer = 0.0;

	// 自機ホーミングショットのクールタイム（秒）
	double playerHomingShotCoolTime = 1.2;
	// 自機ホーミングショットのクールタイムタイマー
	double playerHomingShotTimer = 0.0;

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

	//ゲームのメインループ
	void GameUpdate();
	//ショットの移動関係
	void GameShotUpdate(const double _time);
	//移動関係
	void GameMoveUpdate(const double _time);
	//ゲーム描画処理（背景やエフェクト)
	void GameDrow(const double _time);

	//ショットのヒット判定
	void GameHitCheck(const double _time);

	//敵のランダム配置
	Enemy GenerateEnemy();

	//一番近い敵を取得

	Enemy NearEnemy();

	double dist(Vec2 _SetPos, Vec2 _TargetPos);
	double dist(double x1, double y1, double x2, double y2);


};

