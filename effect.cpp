#include "effect.h"
#include "DxLib.h"
Effect effe[EffectNum];//�G�t�F�N�g�p�̕ϐ�
int img[10];//�ő�P�O�R�}�@�摜

void initEffect()
{
	//�摜�̓ǂݍ���
	LoadDivGraph("effect.png", 5, 5, 1, 120, 120, img);
}
void updateEffect()
{
	for (int i = 0; i < EffectNum; i++) {
		if (effe[i].enable == true)
		{
			//�A�j���[�V������i�߂�
			effe[i].animeNo = effe[i].animeNo + 0.1;
			//5�R�}�ڂɂȂ�����I��
			if ((int)(effe[i].animeNo) > 4) {
				effe[i].enable = false;
			}
		}
	}
}
void drawEffect()
{
	for (int i = 0; i < EffectNum; i++) {
		if (effe[i].enable == true)
		{
			int no = effe[i].animeNo;//�`�悷�ׂ��R�}
			DrawGraph(effe[i].x, effe[i].y, img[no],true);
		}
	}
}