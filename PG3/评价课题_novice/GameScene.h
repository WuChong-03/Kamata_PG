#pragma once

#include <vector>

#include "IScene.h"

struct Vector2 {
	float x;
	float y;
};

struct Bullet {
	Vector2 position;
	float speed;
	float radius;
};

struct Enemy {
	Vector2 position;
	float speed;
	float radius;
};

class GameScene : public IScene {
public:
	void Initialize() override;
	void Update(const char* keys, const char* preKeys) override;
	void Draw() override;
	SceneType GetNextScene() const override;
	int GetScore() const override;

private:
	void ResetEnemy(Enemy& enemy, float startY);

	SceneType nextScene_ = SceneType::kNone;
	Vector2 playerPosition_ = {};
	std::vector<Bullet> bullets_;
	std::vector<Enemy> enemies_;
	int shotCoolTime_ = 0;
	int time_ = 0;
	int score_ = 0;
	int backgroundHandle_ = -1;
	int playerHandle_ = -1;
	int enemyHandle_ = -1;
	int bulletHandle_ = -1;
};
