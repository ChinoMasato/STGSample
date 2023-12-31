//敵の弾を操作する関数を書いたファイル
#include "en.h"
#include "DxLib.h"
#include "enemyshot.h"
#include "player.h"
#include "game.h"

En enemyshot[EnemyShotNum];//弾
//弾の初期化
void initEnemyShot()
{
	for (int i = 0; i < EnemyShotNum; i++) {
		enemyshot[i].r = 5;
		enemyshot[i].color = GetColor(0,255, 0);
		enemyshot[i].fill = true;
		enemyshot[i].enable = false;
	}
}
//弾の更新
void updateEnemyShot()
{
	//弾が有効なときに弾を動かす
	for (int i = 0; i < EnemyShotNum; i++)
	{
		if (enemyshot[i].enable == true) {
			//弾の種類に応じて動き方を変える
			if (enemyshot[i].type == ENEMY4) {
				enemyshot[i].vx = enemyshot[i].vx + enemyshot[i].vvx;
				enemyshot[i].vy = enemyshot[i].vy + enemyshot[i].vvy;
			}
			//誘導弾
			if (enemyshot[i].type == ENEMY5) {
				if (isRight(enemyshot[i], player))
				{
					RotVec(enemyshot[i], 1);//右に1度回転
				}
				else {
					RotVec(enemyshot[i], -1);//左に1度回転
				}
			}
			enemyshot[i].x = enemyshot[i].x + enemyshot[i].vx;
			enemyshot[i].y = enemyshot[i].y + enemyshot[i].vy;
			if (enemyshot[i].x >= 800 ||
				enemyshot[i].x < 0 ||
				enemyshot[i].y >= 600 ||
				enemyshot[i].y < 0) 
			{
				enemyshot[i].enable = false;
			}
			if (isHit(player, enemyshot[i]))
			{
				//当たっている
				player.color = enemyshot[i].color;
				gameOverFlag = true;//ゲームオーバーフラグを立てる
				enemyshot[i].enable = false;
			}
		}
	}
}
//弾の描画
void drawEnemyShot()
{
	for (int i = 0; i < EnemyShotNum; i++) {
		if (enemyshot[i].enable == true)
		{
			DrawCircle(enemyshot[i].x, enemyshot[i].y, enemyshot[i].r, enemyshot[i].color, enemyshot[i].fill);
		}
	}
}

