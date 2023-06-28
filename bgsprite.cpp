#include "DxLib.h"
#include "bgsprite.h"
int bgimg0;//”wŒiŽè‘O‰æ‘œ
int bgimg1;//”wŒi‰æ‘œ
int bgimg2;//”wŒi‰æ‘œ2
double scrollX1 = 0.0;
double scrollX2 = 800.0;
double scrollX3 = 0.0;
double scrollX4 = 800.0;
void initBg() 
{
	bgimg0 = LoadGraph("BG0.png");
	bgimg1 = LoadGraph("BG1.png");
	bgimg2 = LoadGraph("BG2.png");

}
double scroll(double x,double speed)
{
	x = x - speed;
	if (x <= -800.0)//‰æ‘œ1–‡•ª¶‚ÉƒYƒŒ‚½‚ç
	{
		//‰æ‘œ2–‡•ª‰E‚É–ß‚·
		x = x + 1600.0;
	}
	return x;
}
void updateBg()
{
	//ƒXƒNƒ[ƒ‹
	scrollX1  = scroll(scrollX1,  0.2);
	scrollX2  = scroll(scrollX2, 0.2);

	scrollX3 = scroll(scrollX3, 1.0);
	scrollX4 = scroll(scrollX4, 1.0);
}
void drawBg()
{
	DrawGraph(scrollX1, 0, bgimg1, true);
	DrawGraph(scrollX2, 0, bgimg2, true);

	DrawGraph(scrollX3, 0, bgimg0, true);
	DrawGraph(scrollX4, 0, bgimg0, true);
}