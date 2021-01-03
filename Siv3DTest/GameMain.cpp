#include "GameMain.h"


GameMain::GameMain()
{
	// 背景のいろ
	Scene::SetBackground(ColorF(0.1, 0.2, 0.7));

	font = Font(30);

    //プレイヤーの生成
    gamePlayer = Player();

}

void GameMain::GameUpdate()
{

    const double deltaTime = Scene::DeltaTime();
    //プレイヤーのショットタイム周り
    playerShotTimer = Min(playerShotTimer + deltaTime, playerShotCoolTime);

    enemyShotTimer += deltaTime;
    enemySpawnTimer += deltaTime;

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
        enemyBullet.Update(deltaTime);

    }
    // 画面外の敵ショットの削除
    gameEnemyBullet.remove_if([](const EnemyBullet& e_b){return e_b.BulletEnd(); });

    //自機ショット
            // 自機ショットの発射
    if (playerShotTimer >= playerShotCoolTime)
    {
        playerShotTimer = 0.0;
        gamePlayerBullet << PlayerBullet(gamePlayer.pos.movedBy(0, -50));
    }

    for (auto& playerBullet : gamePlayerBullet)
    {
        playerBullet.Update(deltaTime);
    }

    // 画面外の自機ショットの削除
    gamePlayerBullet.remove_if([](const PlayerBullet& p_b) {return p_b.BulletEnd(); });



    // 敵の発生
    while (enemySpawnTimer > enemySpawnTime)
    {
        enemySpawnTimer -= enemySpawnTime;
        enemySpawnTime = Max(enemySpawnTime * 0.95, 0.3);
        gameEnemys << GenerateEnemy();
    }

    //自機の移動と描画
    gamePlayer.Update(deltaTime);

    //敵の移動と描画
    for (auto& enemy : gameEnemys)
    {
        enemy.Update(deltaTime,gameover);
       
    }



}


Enemy GameMain::GenerateEnemy()
{
    Enemy set;
    return set;
}
