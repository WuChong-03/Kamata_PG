#include "ResultScene.h"

#include <Novice.h>

ResultScene::ResultScene(int score) : score_(score) {}

void ResultScene::Initialize() {
	nextScene_ = SceneType::kNone;
	backgroundHandle_ = Novice::LoadTexture("./Resources/bg.png");
}

void ResultScene::Update(const char* keys, const char* preKeys) {
	if (keys[DIK_RETURN] && !preKeys[DIK_RETURN]) {
		nextScene_ = SceneType::kTitle;
	}
}

void ResultScene::Draw() {
	Novice::DrawSprite(0, 0, backgroundHandle_, 1.0f, 1.0f, 0.0f, WHITE);
	Novice::DrawBox(450, 220, 380, 250, 0.0f, 0x102010CC, kFillModeSolid);
	Novice::ScreenPrintf(570, 260, "RESULT");
	Novice::ScreenPrintf(560, 330, "Score: %d", score_);
	Novice::ScreenPrintf(500, 410, "Press ENTER to TITLE");
}

SceneType ResultScene::GetNextScene() const {
	return nextScene_;
}
