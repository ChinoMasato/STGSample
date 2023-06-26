#pragma once
#include <map>
extern int playerimg;
enum EnemyType
{
	ENEMY1,//�G�^�C�v�P
	ENEMY2,//�G�^�C�v�Q
	ENEMY3,//�G�^�C�v�R
	ENEMY4,//�G�^�C�v�S
	ENEMY5 //�G�^�C�v�T
};
struct MovePattern
{
	double vx;
	double vy;
};
//�~�̍\����
struct En
{
	EnemyType type;//�G�̎��
	double x;//X���W
	double y;//Y���W
	double r;//���a
	int color;//�~�̐F
	bool fill;//�h��Ԃ����ۂ�
	double vx;//���̈ړ���
	double vy;//�c�̈ړ���
	double vvx;//���̈ړ��ʂ̑���
	double vvy;//�c�̈ړ��ʂ̑���
	bool enable;//�L���t���O�i�����Ă邩�A����ł邩�j
	int cooltime;//�A�˂ł��Ȃ��悤�ɂ���^�C�}�[
	int counter;
	int spawnTiming;//�o���^�C�~���O
	std::map<int,MovePattern> pattern;
	int imgSizeX = 0;
	int imgSizeY = 0;
};

bool isHit(En en1, En en2);//�����蔻��֐�

bool isRight(En shot, En target);//�i�s�����̉E�ɂ��邩
void RotVec(En& shot, double r);