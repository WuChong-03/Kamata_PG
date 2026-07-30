#include "TitleScene.h"

#include <Novice.h>

void TitleScene::Initialize() {
	nextScene_ = SceneType::kNone;
	backgroundHandle_ = Novice::LoadTexture("./Resources/bg.png");
}

void TitleScene::Update(const char* keys, const char* preKeys) {
	if (keys[DIK_RETURN] && !preKeys[DIK_RETURN]) {
		nextScene_ = SceneType::kGame;
	}
}

void TitleScene::Draw() {
	Novice::DrawSprite(0, 0, backgroundHandle_, 1.0f, 1.0f, 0.0f, WHITE);
	Novice::DrawBox(420, 210, 440, 270, 0.0f, 0x102010CC, kFillModeSolid);
	Novice::ScreenPrintf(500, 250, "ABYSS STRIKE");
	Novice::ScreenPrintf(515, 350, "Press ENTER");
	Novice::ScreenPrintf(460, 430, "Move: WASD   Shoot: SPACE");
}

SceneType TitleScene::GetNextScene() const {
	return nextScene_;
}
