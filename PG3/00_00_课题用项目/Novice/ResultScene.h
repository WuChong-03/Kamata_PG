#pragma once

#include "IScene.h"

class ResultScene : public IScene {
public:
	explicit ResultScene(int score);
	void Initialize() override;
	void Update(const char* keys, const char* preKeys) override;
	void Draw() override;
	SceneType GetNextScene() const override;

private:
	SceneType nextScene_ = SceneType::kNone;
	int score_ = 0;
	int backgroundHandle_ = -1;
};
