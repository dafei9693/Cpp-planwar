#pragma once
#include "Class.h"



void Draw_hero(Hero* hero) {
	putimage(hero->getX() - hero->getWidth() / 2, hero->getY(), &hero->getMasked(), SRCAND);
	putimage(hero->getX() - hero->getWidth() / 2, hero->getY(), &hero->getImage(), SRCPAINT);
}

void Draw_left_bullet(Bullet_left* left) {
	for (int i = 0; i < 99; i++) {
		if (left[i].getStatu() == 1) {
			putimage(left[i].getX(), left[i].getY(), &left[i].getMasked(), SRCAND);
			putimage(left[i].getX(), left[i].getY(), &left[i].getImage(), SRCPAINT);
		}	
	}
}

void Draw_right_bullet(Bullet_right* right) {
	for (int i = 0; i < 99; i++) {
		if (right[i].getStatu() == 1) {
			putimage(right[i].getX(), right[i].getY(), &right[i].getMasked(), SRCAND);
			putimage(right[i].getX(), right[i].getY(), &right[i].getImage(), SRCPAINT);
		}
	}
}

void Draw_Enemy(Enemy* enemy) {
	for (int i = 0; i < 99; i++) {
		if (enemy[i].getStatu() == 1) {
			putimage(enemy[i].getX()-enemy[i].getWidth()/2, enemy[i].getY(), &enemy[i].getMasked(), SRCAND);
			putimage(enemy[i].getX() - enemy[i].getWidth() / 2, enemy[i].getY(), &enemy[i].getImage(), SRCPAINT);
		}
	}
}

void DRAW(Bullet_left* left, Bullet_right* right, Hero* hero,Enemy* enemy) {
	Draw_hero(hero);
	Draw_left_bullet(left);
	Draw_right_bullet(right);
	Draw_Enemy(enemy);
}


