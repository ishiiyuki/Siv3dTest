#include "GameMain.h"


GameMain::GameMain()
{
	// 背景のいろ
	Scene::SetBackground(ColorF(0.1, 0.2, 0.7));

	font = Font(30);


    //

}

void GameMain::GameUpdate()
{

    const double deltaTime = Scene::DeltaTime();
    enemySpawnTimer += deltaTime;
    //プレイヤーのショットタイム周り
    playerShotTimer = Min(playerShotTimer + deltaTime, playerShotCoolTime);
    enemyShotTimer += deltaTime;

    // 敵の発生
    while (enemySpawnTimer > enemySpawnTime)
    {
        enemySpawnTimer -= enemySpawnTime;
        enemySpawnTime = Max(enemySpawnTime * 0.95, 0.3);
        gameEnemys << GenerateEnemy();
    }





    //敵の移動と描画
    for (auto& enemy : gameEnemys)
    {
        enemy.Update(deltaTime);
        enemy.Draw();
    }


}


Enemy GameMain::GenerateEnemy()
{
    Enemy set;
    return set;
}
