#include "SceneManager.h"

#include "GameScene.h"
#include "ResultScene.h"
#include "TitleScene.h"

SceneManager::SceneManager() {
	ChangeScene(SceneType::kTitle);
}

void SceneManager::Update(const char* keys, const char* preKeys) {
	scene_->Update(keys, preKeys);
	SceneType next = scene_->GetNextScene();

	if (next != SceneType::kNone) {
		if (next == SceneType::kResult) {
			lastScore_ = scene_->GetScore();
		}
		ChangeScene(next);
	}
}

void SceneManager::Draw() {
	scene_->Draw();
}

void SceneManager::ChangeScene(SceneType type) {
	switch (type) {
	case SceneType::kTitle:
		scene_ = std::make_unique<TitleScene>();
		break;
	case SceneType::kGame:
		scene_ = std::make_unique<GameScene>();
		break;
	case SceneType::kResult:
		scene_ = std::make_unique<ResultScene>(lastScore_);
		break;
	case SceneType::kNone:
		return;
	}
	scene_->Initialize();
}
