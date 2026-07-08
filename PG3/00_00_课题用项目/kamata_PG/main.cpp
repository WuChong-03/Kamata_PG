#include "Enemy.h"
#include <stdio.h>

int main(void) {
	Enemy enemy;
	int frame = 1;

	while (!enemy.IsFinished()) {
		printf("---- %dフレーム目 ----\n", frame);
		enemy.Update();
		frame++;
	}

	return 0;
}
