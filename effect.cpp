#include "effect.h"
#include "DxLib.h"
Effect effe[EffectNum];//エフェクト用の変数
int img[10];//最大１０コマ　画像

void initEffect()
{
	//画像の読み込み
	LoadDivGraph("effect.png", 5, 5, 1, 120, 120, img);
}
void updateEffect()
{
	for (int i = 0; i < EffectNum; i++) {
		if (effe[i].enable == true)
		{
			//アニメーションを進める
			effe[i].animeNo = effe[i].animeNo + 0.1;
			//5コマ目になったら終了
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
			int no = effe[i].animeNo;//描画すべきコマ
			DrawGraph(effe[i].x, effe[i].y, img[no],true);
		}
	}
}