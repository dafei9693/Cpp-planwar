#pragma once

#include <graphics.h>
#include <windows.h>
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)


IMAGE GetMasked(IMAGE image,int width,int height) {
	IMAGE masked(width,height);
	DWORD* pmemimage = GetImageBuffer(&image);
	DWORD* pmemmasked = GetImageBuffer(&masked);
	COLORREF maskbk = pmemimage[0];
	for (int i = 0; i < width * height; i++)
	{
		if (pmemimage[i] <= 0x555555 && pmemimage[i] >= 0)
		{
			pmemmasked[i] = WHITE;
		}
		else
			pmemmasked[i] = BLACK;
	}
	return masked;
}


class Hero {
private:
	double x;
	double y;
	double speed;
	double blood;
	int weapon;
	IMAGE image;
	IMAGE masked_img;
	int pic_width;
	int pic_height;
public:
	Hero(int X,int Y) {
		x = X;
		y = Y;
		pic_width = 100;
		pic_height = 122;
		speed = 10;
		blood = 100;
		weapon = 1;
		loadimage(&image, "E:/source/image/hero2.png");
		masked_img = GetMasked(image,pic_width,pic_height);
	}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	int getWidth() {
		return pic_width;
	}
	int getHeight() {
		return pic_height;
	}
	IMAGE getImage() {
		return image;
	}
	IMAGE getMasked() {
		return masked_img;
	}
	void Move(){
		if (KEY_DOWN('W'))
			this->y = this->y - speed *0.7 ;
		if (KEY_DOWN('S'))
			this->y = this->y + speed *0.7;
		if (KEY_DOWN('A'))
			this->x = this->x - speed *0.7;
		if (KEY_DOWN('D'))
			this->x = this->x + speed *0.7;
		if (x - pic_width/2 < 0)
			x = pic_width/2;
		if (x + pic_width/2 > 480)
			x = 480 - pic_width/2;
		if (y - pic_height/2 < 0)
			y = pic_height/2;
		if (y + pic_height/2 >= 760)
			y = 760 - pic_height;
	}
	int getWeapon() {
		return weapon;
	}
	void change_weapon() {
		weapon = 2;
	}
	void Destroy() {
		IMAGE image1;
		IMAGE masked1;
		int width1, height1;
		width1 = 98;
		height1 = 124;
		loadimage(&image1, "E:/source/image/hero_blowup_n1.png");
		masked1 = GetMasked(image1,width1,height1);
		putimage(x-width1/2,y, &masked1, SRCAND);
		putimage(x - width1 / 2,y, &image1, SRCPAINT);
		Sleep(200);
		width1 = 98;
		height1 = 124;
		loadimage(&image1, "E:/source/image/hero_blowup_n2.png");
		masked1 = GetMasked(image1,width1, height1);
		putimage(x - width1 / 2, y, &masked1, SRCAND);
		putimage(x - width1 / 2, y, &image1, SRCPAINT);
		Sleep(200);
		width1 = 98;
		height1 = 124;
		loadimage(&image1, "E:/source/image/hero_blowup_n3.png");
		masked1 = GetMasked(image1, width1, height1);
		putimage(x - width1 / 2, y, &masked1, SRCAND);
		putimage(x - width1 / 2, y, &image1, SRCPAINT);
		Sleep(200);
		width1 = 66;
		height1 = 78;
		loadimage(&image1, "E:/source/image/hero_blowup_n4.png");
		masked1 = GetMasked(image1,width1, height1);
		putimage(x - width1 / 2, y, &masked1, SRCAND);
		putimage(x - width1 / 2, y, &image1, SRCPAINT);
		Sleep(200);
	}
};

class Bullet_left {
private:
	double x;
	double y;
	double speed;
	double damage;
	IMAGE image;
	IMAGE masked_img;
	int pic_width;
	int pic_height;
	int statu;
public:
	Bullet_left() {
		statu = 0;
	}
	Bullet_left(Hero hero) {
		statu = 1;
		x = hero.getX()-36;
		y = hero.getY();
		speed = 25;  //40pix/s
		if (hero.getWeapon() == 1) {
			loadimage(&image, "E:/source/image/bullet1.png");
			damage = 30;
		}
		else {
			loadimage(&image, "E:/source/image/bullet2.png");
			damage = 50;
		}
		pic_width = 9;
		pic_height = 21;
		masked_img = GetMasked(image, pic_width, pic_height);
	}
	void switch_statu() {
		statu = 0;
	}
	int getDamage() {
		return damage;
	}
	int getWidth() {
		return pic_width;
	}
	int getHeight() {
		return pic_height;
	}
	int getStatu() {
		return statu;
	}
	IMAGE getImage() {
		return image;
	}
	IMAGE getMasked() {
		return masked_img;
	}
	int getY() {
		return y;
	}
	int getX() {
		return x;
	}
	void move() {
		y = y - speed;
	}
};

class Bullet_right {
private:
	double x;
	double y;
	double speed;
	double damage;
	IMAGE image;
	IMAGE masked_img;
	int pic_width;
	int pic_height;
	int statu;
public:
	Bullet_right() {
		statu = 0;
	}
	Bullet_right(Hero hero) {
		statu = 1;
		x = hero.getX() + 28;
		y = hero.getY();
		speed = 25;  //40pix/s
		damage = 30;
		if (hero.getWeapon() == 1) {
			loadimage(&image, "E:/source/image/bullet1.png");
			damage = 30;
		}
		else {
			loadimage(&image, "E:/source/image/bullet2.png");
			damage = 50;
		}
		pic_width = 9;
		pic_height = 21;
		masked_img = GetMasked(image, pic_width, pic_height);
	}
	void switch_statu() {
		statu = 0;
	}
	int getWidth() {
		return pic_width;
	}
	int getHeight() {
		return pic_height;
	}
	bool deal_damage() {
	}
	int getStatu() {
		return statu;
	}
	IMAGE getImage() {
		return image;
	}
	IMAGE getMasked() {
		return masked_img;
	}
	int getY() {
		return y;
	}
	int getX() {
		return x;
	}
	void move() {
		y = y - speed ;
	}
	int getDamage() {
		return damage;
	}
};
   
class Enemy {
private:
	double x;
	double y;
	int blood;
	int type;
	IMAGE image;
	IMAGE masked;
	double speed;
	int pic_width;
	int pic_height;
	int statu;
public:
	Enemy() {
		statu = 0;
	}
	Enemy(int random) {
		statu = 1;
		if (random < 60) {
			type = 0;
			pic_width = 51;
			pic_height = 39;
			loadimage(&image, "E:/source/image/enemy0.png");
			masked = GetMasked(image, pic_width, pic_height);
			speed = (rand() % (10 - 5)) + 5;
			blood = 30;
			x = rand() % 480;
			y = 0 - pic_height;
		}
		if (random >= 60 && random < 90) {
			type = 1;
			pic_width = 69;
			pic_height = 89;
			loadimage(&image, "E:/source/image/enemy1.png");
			masked = GetMasked(image, pic_width, pic_height);
			speed = (rand() % (5 - 2)) + 2;
			blood = 90;
			x = rand() % 480;
			y = 0 - pic_height;
		}
		if (random >= 90) {
			type = 2;
			pic_width = 165;
			pic_height = 246;
			loadimage(&image, "E:/source/image/enemy2.png");
			masked = GetMasked(image, pic_width, pic_height);
			speed = (rand() % (3 - 1)) + 1;
			blood = 150;
			x = rand() % 480;
			y = 0 - pic_height;
		}
	}
	void RecDamage(int damage) {
		blood -= damage;
	}
	int getBlood() {
		return blood;
	}
	void move() {
		y += speed;
	}
	int getStatu() {
		return statu;
	}
	IMAGE getImage() {
		return image;
	}
	IMAGE getMasked() {
		return masked;
	}
	int getY() {
		return y;
	}
	int getX() {
		return x;
	};
	void switch_statu() {
		statu = 0;
	}
	int getHeight() {
		return pic_height;
	}
	int getWidth() {
		return pic_width;
	}
	void Blood_decrease(int n) {
		blood -= n;
	}
};

Bullet_left leftBullet[99];
Bullet_right rightBullet[99];
Enemy enemy[99];

void Shoot(Bullet_left* left, Bullet_right* right, Hero* hero) {
	static int x = 0;
	x++;
	if (x % 11 == 0) {
		for (int i = 0; i < 99; i++) {
			if (left[i].getStatu() == 0) {
				left[i] = Bullet_left(hero[0]);
				break;
			}
		}
		for (int i = 0; i < 99; i++) {
			if (right[i].getStatu() == 0) {
				right[i] = Bullet_right(hero[0]);
				break;
			}
		}
		x = 0;
	}
}

void CreateEnemy(Enemy* enemy) {
	for (int i = 0; i < 99; i++) {
		if (enemy[i].getStatu() == 0) {
			int random = rand() % 100;
			enemy[i] = Enemy(random);
			break;
		}
	}
}

bool if_overlap(int x1,int y1,int x2,int y2,int width1,int height1,int width2,int height2) {
	//if (rc1.x + rc1.width > rc2.x &&rc2.x + rc2.width > rc1.x &&rc1.y + rc1.height > rc2.y &&rc2.y + rc2.height > rc1.y)
	if (x1 + width1 > x2 && x2 + width2 > x1 && y1 + height1 > y2 && y2 + height2 > y1)
		return true;
	else
		return false;
}

bool if_fail(Hero* hero,Enemy* enemy) {
	for (int i = 0; i < 99; i++) {
		if (if_overlap(hero->getX() - hero->getWidth() / 2, hero->getY() - hero->getHeight() / 2, enemy[i].getX() - enemy[i].getWidth() / 2, enemy[i].getY() - enemy[i].getHeight() / 2, hero->getWidth(), hero->getHeight(), enemy[i].getWidth(), enemy[i].getHeight())) {
			hero->Destroy();
			return 1;
		}
		return 0;
	}
			
}

void Hit(Enemy* enemy, Bullet_left* left, Bullet_right* right) {
	for (int i = 0; i < 99; i++) {
		if (left[i].getStatu() == 1) {
			for (int j = 0; j < 99; j++) {
				//int A[4] = {left[i].getX()-left[i].getWidth()/2,left[i].getY()+left[i].getHeight()/2,left[i].getX() + left[i].getWidth() / 2,left[i].getY() - left[i].getHeight() / 2 };
				//int B[4] = { enemy[i].getX() - enemy[i].getWidth() / 2,enemy[i].getY() + enemy[i].getHeight() / 2,enemy[i].getX() + enemy[i].getWidth() / 2,enemy[i].getY() - enemy[i].getHeight() / 2 };
				if (if_overlap(left[i].getX() - left[i].getWidth() / 2, left[i].getY() - left[i].getHeight() / 2, enemy[j].getX() - enemy[j].getWidth() / 2, enemy[j].getY() - enemy[j].getHeight() / 2, left[i].getWidth(), left[i].getHeight(), enemy[j].getWidth(), enemy[j].getHeight())) {
					left[i].switch_statu();
					enemy[j].Blood_decrease(left[i].getDamage());
					if (enemy[j].getBlood() <= 0)
						enemy[j].switch_statu();
				}
			}
		}
		if (right[i].getStatu() == 1) {
			for (int j = 0; j < 99; j++) {
				//int A[4] = { right[i].getX() - right[i].getWidth() / 2,right[i].getY() + right[i].getHeight() / 2,right[i].getX() + right[i].getWidth() / 2,right[i].getY() - right[i].getHeight() / 2 };
				//int B[4] = { enemy[i].getX() - enemy[i].getWidth() / 2,enemy[i].getY() + enemy[i].getHeight() / 2,enemy[i].getX() + enemy[i].getWidth() / 2,enemy[i].getY() - enemy[i].getHeight() / 2 };
				if (if_overlap(right[i].getX() - right[i].getWidth() / 2, right[i].getY() - right[i].getHeight() / 2, enemy[j].getX() - enemy[j].getWidth() / 2, enemy[j].getY() - enemy[j].getHeight() / 2, left[i].getWidth(), left[i].getHeight(), enemy[j].getWidth(), enemy[j].getHeight())) {
					right[i].switch_statu();
					enemy[j].Blood_decrease(left[i].getDamage());
					if (enemy[j].getBlood() <= 0)
						enemy[j].switch_statu();
				}
			}
		}
	}
}

void Demo(Bullet_left* left, Bullet_right* right, Hero* hero,Enemy* enemy) {
	if (_kbhit())
		hero->Move();
	for (int i = 0; i < 99; i++) {
		if (left[i].getStatu() == 1)
			left[i].move();
		if (right[i].getStatu() == 1)
			right[i].move();
		if (left[i].getY() <= 0) {
			left[i].switch_statu();
		}
		if (right[i].getY() <= 0) {
			right[i].switch_statu();
		}
	}
	int x = rand() % 100;
	if (x>=95)
		CreateEnemy(enemy);
	for (int i = 0; i < 99; i++) {
		if (enemy[i].getStatu() == 1) {
			enemy[i].move();
			if (enemy[i].getY() - enemy[i].getHeight()/2 >= 760)
				enemy[i].switch_statu();
		}
	}
	if (if_fail(hero, enemy))
		exit(0);
	Hit(enemy, left, right);
}


