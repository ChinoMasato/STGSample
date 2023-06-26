//�~�\���̂𑀍삷��֐����������t�@�C��
#include "en.h"
#include <math.h>

int playerimg;//�v���C���[�摜

//�~�̓����蔻��֐�
bool isHit(En en1, En en2)
{
	//��̉~�̓����蔻��
	double dx = en1.x - en2.x;//���̋���
	double dy = en1.y - en2.y;//�c�̋���
	double r2 = en1.r + en2.r;//���a�̍��Z

	if (dx * dx + dy * dy < r2 * r2)
	{
		//�������Ă���
		return true;
	}
	return false;
}

//�i�s�����̉E���Ƀ^�[�Q�b�g�����邩���肷��֐�
bool isRight(En shot, En target)
{
	double dy = target.y - shot.y;
	double dx = target.x - shot.x;
	double cross = shot.vx * dy - shot.vy * dx;

	return cross > 0;
}

//En�̈ړ��������w��p�x����]������֐�
void RotVec(En& shot, double r)
{
	double rot = r * (3.1415926539 / 180.0f);

	double rx = cos(rot) * shot.vx - sin(rot) * shot.vy;
	double ry = sin(rot) * shot.vx + cos(rot) * shot.vy;

	shot.vx = rx;
	shot.vy = ry;
}

