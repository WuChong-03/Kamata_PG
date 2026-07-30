#pragma once

#include "IScene.h"

class TitleScene : public IScene {
public:
	void Initialize() override;
	void Update(const char* keys, const char* preKeys) override;
	void Draw() override;
	SceneType GetNextScene() const override;

private:
	SceneType nextScene_ = SceneType::kNone;
	int backgroundHandle_ = -1;
};
