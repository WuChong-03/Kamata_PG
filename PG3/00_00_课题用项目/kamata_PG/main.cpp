#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

typedef void (*ResultCallback)(int dice, int userAnswer);

void ShowResult(int dice, int userAnswer) {
	int diceAnswer = dice % 2;

	printf("\nサイコロの出目は%dです。\n", dice);

	if (diceAnswer == userAnswer) {
		printf("正解\n");
	}
	else {
		printf("不正解\n");
	}
}

void WaitResult(ResultCallback callback, int dice, int userAnswer) {
	printf("結果を確認しています...\n");
	Sleep(3000);
	callback(dice, userAnswer);
}

int main(void) {
	int dice = 0;
	int userAnswer = 0;
	ResultCallback callback = ShowResult;

	srand((unsigned int)time(NULL));
	dice = rand() % 6 + 1;

	printf("サイコロの出目が半(奇数)か丁(偶数)かを当ててください。\n");
	printf("半(奇数)なら1、丁(偶数)なら0を入力してください: ");
	if (scanf("%d", &userAnswer) != 1) {
		printf("数字を入力してください。\n");
		return 0;
	}

	if (userAnswer != 0 && userAnswer != 1) {
		printf("0か1を入力してください。\n");
		return 0;
	}

	WaitResult(callback, dice, userAnswer);

	return 0;
}
