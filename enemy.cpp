//敵を操作する関数を書いたファイル
#include "en.h"
#include "DxLib.h"
#include <math.h>
#include "shot.h"
#include "enemyshot.h"
#include "enemy.h"
#include "player.h"
#include "effect.h"
#include "game.h"
extern bool gameOverFlag;//ゲームオーバー判定
En enemy[EnemyNum];//敵

int explodese;//爆発SE
//敵の初期化
void initEnemy()
{
	explodese = LoadSoundMem("maou_se_battle_explosion06.mp3");
	//1体目の敵
	enemy[0].x = 900;
	enemy[0].y = 200;
	enemy[0].r = 30;
	enemy[0].color = GetColor(255, 0, 0);
	enemy[0].fill = true;
	enemy[0].enable = true;
	enemy[0].vx = -2.0;
	enemy[0].vy = 0.0;
	enemy[0].type = ENEMY1;
	enemy[0].pattern[200] = { 0,2 };
	enemy[0].pattern[300] = { -1,1 };
	enemy[0].pattern[400] = { -2,0 };
	enemy[0].pattern[600] = { 0,-2 };

	//2体目の敵
	enemy[1].x = 1500;
	enemy[1].y = 400;
	enemy[1].r = 30;
	enemy[1].color = GetColor(255, 0, 0);
	enemy[1].fill = true;
	enemy[1].enable = true;
	enemy[1].vx = -2.0;
	enemy[1].vy = 0.0;
	enemy[1].type = ENEMY4;

	//3体目の敵
	enemy[2].x = 2000;
	enemy[2].y = 200;
	enemy[2].r = 30;
	enemy[2].color = GetColor(255, 0, 0);
	enemy[2].fill = true;
	enemy[2].enable = true;
	enemy[2].vx = -2.0;
	enemy[2].vy = 0.0;
	enemy[2].type = ENEMY3;

	//2体目の敵
	enemy[3].x = 2500;
	enemy[3].y = 400;
	enemy[3].r = 30;
	enemy[3].color = GetColor(255, 0, 0);
	enemy[3].fill = true;
	enemy[3].enable = true;
	enemy[3].vx = -2.0;
	enemy[3].vy = 0.0;
	enemy[3].type = ENEMY4;

	//3体目の敵
	enemy[4].x = 3000;
	enemy[4].y = 200;
	enemy[4].r = 30;
	enemy[4].color = GetColor(255, 0, 0);
	enemy[4].fill = true;
	enemy[4].enable = true;
	enemy[4].vx = -2.0;
	enemy[4].vy = 0.0;
	enemy[4].type = ENEMY4;

	//2体目の敵
	enemy[5].x = 3500;
	enemy[5].y = 400;
	enemy[5].r = 30;
	enemy[5].color = GetColor(255, 0, 0);
	enemy[5].fill = true;
	enemy[5].enable = true;
	enemy[5].vx = -2.0;
	enemy[5].vy = 0.0;
	enemy[5].type = ENEMY4;

	//3体目の敵
	enemy[6].x = 4000;
	enemy[6].y = 200;
	enemy[6].r = 30;
	enemy[6].color = GetColor(255, 0, 0);
	enemy[6].fill = true;
	enemy[6].enable = true;
	enemy[6].vx = -2.0;
	enemy[6].vy = 0.0;
	enemy[6].type = ENEMY4;

	//2体目の敵
	enemy[7].x = 4500;
	enemy[7].y = 400;
	enemy[7].r = 30;
	enemy[7].color = GetColor(255, 0, 0);
	enemy[7].fill = true;
	enemy[7].enable = true;
	enemy[7].vx = -2.0;
	enemy[7].vy = 0.0;
	enemy[7].type = ENEMY4;

	//3体目の敵
	enemy[8].x = 5000;
	enemy[8].y = 200;
	enemy[8].r = 30;
	enemy[8].color = GetColor(255, 0, 0);
	enemy[8].fill = true;
	enemy[8].enable = true;
	enemy[8].vx = -2.0;
	enemy[8].vy = 0.0;
	enemy[8].type = ENEMY4;

	//2体目の敵
	enemy[9].x = 5500;
	enemy[9].y = 400;
	enemy[9].r = 30;
	enemy[9].color = GetColor(255, 0, 0);
	enemy[9].fill = true;
	enemy[9].enable = true;
	enemy[9].vx = -2.0;
	enemy[9].vy = 0.0;
	enemy[9].type = ENEMY5;
}
//真っすぐ弾を撃つ
void straightShot(int rad,En ene,int shifty)
{
	//弾が無効なときのみ初期値をセットし有効にする
	for (int j = 0; j < EnemyShotNum; j++)
	{
		//撃てる弾をみつける
		if (enemyshot[j].enable == false) {
			//弾を撃つ
			enemyshot[j].x = ene.x;
			enemyshot[j].y = ene.y + shifty;
			double PI = 3.14159265358979323846264338;
			double minrad = PI / 180.0;//1度のラジアン
			double speed = 3.0;//速度
			enemyshot[j].vx = speed * cos(minrad * rad);
			enemyshot[j].vy = speed * sin(minrad * rad);
			enemyshot[j].enable = true;
			enemyshot[j].type = ene.type;
			enemyshot[j].vvx = -enemyshot[j].vx * 0.002;
			enemyshot[j].vvy = -enemyshot[j].vy * 0.002;
			break;
		}
	}
}

//狙って撃つ
void aimShot(En ene)
{
	//弾を撃てる状態
//弾が無効なときのみ初期値をセットし有効にする
	for (int j = 0; j < EnemyShotNum; j++)
	{
		//撃てる弾をみつける
		if (enemyshot[j].enable == false) {
			//弾を撃つ
			enemyshot[j].x = ene.x;
			enemyshot[j].y = ene.y;

			double speed = 3.0;//速度
			double dx = player.x - ene.x;//プレイヤーと敵のx方向の距離
			double dy = player.y - ene.y;//プレイヤーと敵のy方向の距離
			double d = sqrt(dx * dx + dy * dy);//敵とプレイヤーとの距離
			enemyshot[j].vx = speed * (dx / d);//xの移動量
			enemyshot[j].vy = speed * (dy / d);//yの移動量
			enemyshot[j].enable = true;
			enemyshot[j].type = ene.type;
			enemyshot[j].vvx = enemyshot[j].vx * 0.01;
			enemyshot[j].vvy = enemyshot[j].vy * 0.01;
			break;
		}
	}
}
//爆発発生関数
void explosion(En ene)
{
	for (int i = 0; i < EffectNum; i++)
	{
		if (effe[i].enable == false)
		{
			effe[i].enable = true;
			effe[i].x = ene.x - 60;
			effe[i].y = ene.y - 60;
			effe[i].animeNo = 0;
			break;
		}
	}
}
//敵の更新
void updateEnemy()
{
	for (int i = 0; i < EnemyNum; i++) {
		if (enemy[i].enable == true) {
			//敵を自動で動かす
			if (enemy[i].pattern.find(enemy[i].counter)!= enemy[i].pattern.end()) 
			{
				enemy[i].vx = enemy[i].pattern[enemy[i].counter].vx;
				enemy[i].vy = enemy[i].pattern[enemy[i].counter].vy;
			}
			enemy[i].counter++;
			enemy[i].x = enemy[i].x + enemy[i].vx;
			enemy[i].y = enemy[i].y + enemy[i].vy;

			//弾を発射する
			if (canEnemyShot(enemy[i]))
			{
				//三本ショット
				if (enemy[i].type == ENEMY1) {
					straightShot(175, enemy[i],0);
					straightShot(180, enemy[i],0);
					straightShot(185, enemy[i],0);
				}
				if (enemy[i].type == ENEMY2) {
					straightShot(180, enemy[i],-10);
					straightShot(180, enemy[i], 10);
				}
				if (enemy[i].type == ENEMY3) {
					aimShot(enemy[i]);
				}
				if (enemy[i].type == ENEMY4) {
					straightShot(180, enemy[i], 0);
				}
				if (enemy[i].type == ENEMY5) {
					straightShot(180, enemy[i], -10);
					straightShot(180, enemy[i], 10);
				}
				enemy[i].cooltime = 30;
			}
		
			if (isHit(player, enemy[i]))
			{
				//当たっている
				player.color = enemy[i].color;
				gameOverFlag = true;//ゲームオーバーフラグを立てる
			}

			for (int j = 0; j < ShotNum; j++) {
				//敵と弾との当たり判定
				if (shot[j].enable == true) {
					if (isHit(shot[j], enemy[i]))
					{
						//当たっている
						enemy[i].enable = false;//敵を無効
						shot[j].enable = false;//弾を無効
						PlaySoundMem(explodese, DX_PLAYTYPE_BACK);

						explosion(enemy[i]);//爆発
						if (gameOverFlag == false) {
							score++;//１フレームごとに１点加算
						}
						break;
					}
				}
			}
			//銃を冷やす処理
			if (enemy[i].cooltime > 0) {
				enemy[i].cooltime--;
			}
		}
	}
}

//敵の描画
void drawEnemy()
{
	for (int i = 0; i < EnemyNum; i++) {
		if (enemy[i].enable == true) {
			DrawCircle(enemy[i].x, enemy[i].y, enemy[i].r, enemy[i].color, enemy[i].fill);
		}
	}
}
//弾が撃てるか確認する関数
bool canEnemyShot(En enemy)
{
	//銃が冷えている
	if (enemy.cooltime <= 0) {
		if(enemy.x >=0 &&
			enemy.x < 800 &&
			enemy.y>0 &&
			enemy.y < 600)
		{
			//画面の中にいる
			return true;
		}
	}

	return false;
}