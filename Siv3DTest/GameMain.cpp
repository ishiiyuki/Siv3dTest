#include "GameMain.h"


GameMain::GameMain()
{
	// 背景のいろ
	Scene::SetBackground(ColorF(0.1, 0.2, 0.7));

	font = Font(30);
    gameoverfont = Font(60);

    //プレイヤーの生成
    gamePlayer = Player();

}

void GameMain::GameUpdate()
{

    // ゲームオーバー画面
    if (gameover)
    {
        if (KeyA.down())
        {
            effect.clear();
            gamePlayer.pos = Vec2(400, 500);
            gameEnemys.clear();
            gamePlayerBullet.clear();
            gameEnemyBullet.clear();
            enemySpawnTime = initialEnemySpawnTime;
            highScore = Max(highScore, score);
            score = 0;
            gameover = false;
        }
        
        //  文字表示
        gameoverfont(U"Press Key A to continue").drawAt(Scene::Center(), Palette::Black);

        return;
    }

    const double deltaTime = Scene::DeltaTime();
    
    // 敵の発生
    while (enemySpawnTimer > enemySpawnTime)
    {
        enemySpawnTimer -= enemySpawnTime;
        enemySpawnTime = Max(enemySpawnTime * 0.95, 0.3);
        gameEnemys << GenerateEnemy();
    }

    //攻撃のヒット判定
    GameHitCheck(deltaTime);

    //Shot周り
    GameShotUpdate(deltaTime);

    //移動
    GameMoveUpdate(deltaTime);

    //描画のみ
    GameDrow(deltaTime);


}

void GameMain::GameMoveUpdate(const double _time)
{
    //自機の移動と描画
    gamePlayer.Update(_time);

    //敵の移動と描画
    for (auto& enemy : gameEnemys)
    {

        enemy.Update(_time, gameover);
    }
}

void GameMain::GameShotUpdate(const double _time)
{
    //プレイヤーのショットタイム周り
    playerShotTimer = Min(playerShotTimer + _time, playerShotCoolTime);
    playerHomingShotTimer = Min(playerHomingShotTimer + _time, playerHomingShotCoolTime);

    enemyShotTimer += _time;
    enemySpawnTimer += _time;


    // 敵ショットの発射
    if (enemyShotTimer >= enemyShotCoolTime)
    {
        enemyShotTimer -= enemyShotCoolTime;

        for (const auto& enemy : gameEnemys)
        {
            gameEnemyBullet << EnemyBullet(enemy.pos);
        }
    }

    // 敵ショットの移動
    for (auto& enemyBullet : gameEnemyBullet)
    {
        enemyBullet.Update(_time);

    }

    // 画面外の敵ショットの削除
    gameEnemyBullet.remove_if([](const EnemyBullet& e_b) {return e_b.BulletEnd(); });

    //自機ショット
 
    if (playerShotTimer >= playerShotCoolTime)
    {
        playerShotTimer = 0.0;
        gamePlayerBullet << PlayerBullet(gamePlayer.pos.movedBy(0, -50));
    }

    for (auto& playerBullet : gamePlayerBullet)
    {
        playerBullet.Update(_time);
    }

    // 画面外の自機ショットの削除
    gamePlayerBullet.remove_if([](const PlayerBullet& p_b) {return p_b.BulletEnd(); });


    if (playerHomingShotTimer >= playerHomingShotCoolTime)
    {
        
        if (KeyD.down())
        {
            //一番近い距離の敵を探す
            auto _nEnemy = NearEnemy();

            Vec2 setPos = gamePlayer.pos.movedBy(0, +50);
            Vec2 setVec = setPos.movedBy(-300, 300);
            gameHomingBullet << HomingBullet(setPos, setVec, _nEnemy);

            playerHomingShotTimer = 0.0;

        }
    }


    for (auto& phomingBullet : gameHomingBullet)
    {
        phomingBullet.Update(_time);
    }

}

void GameMain::GameDrow(const double _time)
{
    
    // 背景のアニメーション
    for (auto i : step(12))
    {
        const double a = Periodic::Sine0_1(2s, Scene::Time() - (2.0 / 12 * i));
        Rect(0, i * 50, 800, 50).draw(ColorF(1.0, a * 0.2));
    }

    effect.update();
}


void GameMain::GameHitCheck(const double _time)
{

    // 敵 vs 自機ショット
    for (auto itEnemy = gameEnemys.begin(); itEnemy != gameEnemys.end();)
    {
        bool skip = false;
        bool homingSkip = false;

        for (auto itBullet = gamePlayerBullet.begin(); itBullet != gamePlayerBullet.end();)
        {
            if (itEnemy->MyHitCheck(itBullet->GetPos()))
            {
                // 爆発エフェクトを追加
                effect.add([enemy_pos = *itEnemy](double t)
                {
                    double t2 = (1.0 - t);
                    Circle(enemy_pos.pos, 10 + t * 70).drawFrame(20 * t2, AlphaF(t2 * 0.5));
                    return t < 1.0;
                });

                itEnemy = gameEnemys.erase(itEnemy);
                gamePlayerBullet.erase(itBullet);
                ++score;
                skip = true;
                break;

            }

            ++itBullet;
        }

        if (skip)
        {
            continue;
        }

        for (auto itBullet = gameHomingBullet.begin(); itBullet != gameHomingBullet.end();)
        {
            if (itEnemy->MyHitCheck(itBullet->GetPos()))
            {
                // 爆発エフェクトを追加
                effect.add([enemy_pos = *itEnemy](double t)
                {
                    double t2 = (1.0 - t);
                    Circle(enemy_pos.pos, 10 + t * 70).drawFrame(20 * t2, AlphaF(t2 * 0.5));
                    return t < 1.0;
                });

                itEnemy = gameEnemys.erase(itEnemy);
                gameHomingBullet.erase(itBullet);
                ++score;
                homingSkip = true;
                break;

            }

            ++itBullet;
        }

        if (homingSkip)
        {
            continue;
        }

      

        ++itEnemy;
    }

    // 敵ショット vs 自機
    for (auto& enemyBullet : gameEnemyBullet)
    {
        // 敵ショットが playerPos の 20 ピクセル以内に接近したら
        if (gamePlayer.MyHitCheck(enemyBullet.GetPos()))
        {
            // ゲームオーバーにする
            gameover = true;
            break;
        }
    }
}

Enemy GameMain::GenerateEnemy()
{
    Enemy set;
    return set;
}

Enemy GameMain::NearEnemy()
{
    Enemy set;
    double checkDis = 1000;

    for (auto& enemy : gameEnemys)
    {

        auto _dis = dist(gamePlayer.pos, enemy.pos);

        if (_dis < checkDis)
        {
            checkDis = _dis;
            set = enemy;
        }
    }
    return set;
}


double GameMain::dist(Vec2 _SetPos, Vec2 _TargetPos)
{

    return dist(_SetPos.x, _SetPos.y, _TargetPos.x, _TargetPos.y);
}

double GameMain::dist(double x1, double y1, double x2, double y2)
{

    double dx,dy;

    dx = x2 - x1;
    dy = y2 - y1;

    return Math::Sqrt(dx * dx + dy * dy);

}