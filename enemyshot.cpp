//�G�̒e�𑀍삷��֐����������t�@�C��
#include "en.h"
#include "DxLib.h"
#include "enemyshot.h"
#include "player.h"
#include "game.h"

En enemyshot[EnemyShotNum];//�e
//�e�̏�����
void initEnemyShot()
{
	for (int i = 0; i < EnemyShotNum; i++) {
		enemyshot[i].r = 5;
		enemyshot[i].color = GetColor(0,255, 0);
		enemyshot[i].fill = true;
		enemyshot[i].enable = false;
	}
}
//�e�̍X�V
void updateEnemyShot()
{
	//�e���L���ȂƂ��ɒe�𓮂���
	for (int i = 0; i < EnemyShotNum; i++)
	{
		if (enemyshot[i].enable == true) {
			//�e�̎�ނɉ����ē�������ς���
			if (enemyshot[i].type == ENEMY4) {
				enemyshot[i].vx = enemyshot[i].vx + enemyshot[i].vvx;
				enemyshot[i].vy = enemyshot[i].vy + enemyshot[i].vvy;
			}
			//�U���e
			if (enemyshot[i].type == ENEMY5) {
				if (isRight(enemyshot[i], player))
				{
					RotVec(enemyshot[i], 1);//�E��1�x��]
				}
				else {
					RotVec(enemyshot[i], -1);//����1�x��]
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
				//�������Ă���
				player.color = enemyshot[i].color;
				gameOverFlag = true;//�Q�[���I�[�o�[�t���O�𗧂Ă�
				enemyshot[i].enable = false;
			}
		}
	}
}
//�e�̕`��
void drawEnemyShot()
{
	for (int i = 0; i < EnemyShotNum; i++) {
		if (enemyshot[i].enable == true)
		{
			DrawCircle(enemyshot[i].x, enemyshot[i].y, enemyshot[i].r, enemyshot[i].color, enemyshot[i].fill);
		}
	}
}

