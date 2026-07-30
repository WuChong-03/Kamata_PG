#pragma once

#include <memory>

#include "IScene.h"

class SceneManager {
public:
	SceneManager();
	void Update(const char* keys, const char* preKeys);
	void Draw();

private:
	void ChangeScene(SceneType type);

	std::unique_ptr<IScene> scene_;
	int lastScore_ = 0;
};
