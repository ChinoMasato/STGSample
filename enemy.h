#pragma once
#include "en.h"
const int EnemyNum = 10;//“G‚Ì”
extern En enemy[EnemyNum];//“G

void initEnemy();//“G‚Ì‰Šú‰»
void updateEnemy();//“G‚ÌXV
void drawEnemy();//“G‚Ì•`‰æ

bool canEnemyShot(En enemy);//’e‚ªŒ‚‚Ä‚é‚©Šm”F

void straightShot(int rad,En ene,int shifty);//^‚Á‚·‚®Œ‚‚Â
void aimShot(En ene);//‘_‚Á‚ÄŒ‚‚Â

void explosion(En ene);//”š”­”­¶ŠÖ”