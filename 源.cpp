#include <graphics.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "Class.h"
#include "Draw.h"
#include "run.h"

int main() {
	srand((unsigned int)time(0));
	initgraph(480, 760);
	RunMain();
	_getch();
	closegraph();
}