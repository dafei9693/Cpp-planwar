#pragma once
#include <graphics.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

void RunMain() {
	Hero* hero;
	hero = new Hero(240, 620);
	IMAGE background;
	loadimage(&background, "E:/source/image/background.png");
	while (TRUE) {
		Shoot(leftBullet, rightBullet, hero);
		BeginBatchDraw();
		putimage(0, 0, &background);
		DRAW(leftBullet, rightBullet, hero, enemy);
		Demo(leftBullet, rightBullet, hero, enemy);
		EndBatchDraw();
		Sleep(20);
	}
}