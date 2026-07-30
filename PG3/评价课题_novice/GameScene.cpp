#include "GameScene.h"

#include <Novice.h>

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>

void GameScene::Initialize() {
	static bool randomInitialized = false;
	if (!randomInitialized) {
		std::srand(static_cast<unsigned int>(std::time(nullptr)));
		randomInitialized = true;
	}

	nextScene_ = SceneType::kNone;
	playerPosition_ = { 640.0f, 650.0f };
	bullets_.clear();
	enemies_.clear();
	shotCoolTime_ = 0;
	time_ = 30 * 60;
	score_ = 0;

	backgroundHandle_ = Novice::LoadTexture("./Resources/bg.png");
	playerHandle_ = Novice::LoadTexture("./Resources/player.png");
	enemyHandle_ = Novice::LoadTexture("./Resources/enemy_t1.png");
	bulletHandle_ = Novice::LoadTexture("./Resources/bullet.png");

	// 複数の敵を時間差で画面上から出現させる
	for (int i = 0; i < 6; i++) {
		Enemy enemy = {};
		ResetEnemy(enemy, -60.0f - static_cast<float>(i * 110));
		enemies_.push_back(enemy);
	}
}

void GameScene::ResetEnemy(Enemy& enemy, float startY) {
	enemy.position.x = 16.0f + static_cast<float>(std::rand() % (1280 - 32));
	enemy.position.y = startY;
	enemy.speed = 2.0f + static_cast<float>(std::rand() % 4);
	enemy.radius = 16.0f;
}

void GameScene::Update(const char* keys, const char* preKeys) {
	(void)preKeys;
	const float playerSpeed = 6.0f;

	if (keys[DIK_A]) { playerPosition_.x -= playerSpeed; }
	if (keys[DIK_D]) { playerPosition_.x += playerSpeed; }
	if (keys[DIK_W]) { playerPosition_.y -= playerSpeed; }
	if (keys[DIK_S]) { playerPosition_.y += playerSpeed; }

	if (playerPosition_.x < 24.0f) { playerPosition_.x = 24.0f; }
	if (playerPosition_.x > 1256.0f) { playerPosition_.x = 1256.0f; }
	if (playerPosition_.y < 24.0f) { playerPosition_.y = 24.0f; }
	if (playerPosition_.y > 696.0f) { playerPosition_.y = 696.0f; }

	if (shotCoolTime_ > 0) {
		shotCoolTime_--;
	}

	// 加点要素：std::vectorで複数の弾を管理
	if (keys[DIK_SPACE] && shotCoolTime_ == 0) {
		bullets_.push_back({ { playerPosition_.x, playerPosition_.y - 30.0f }, 10.0f, 6.0f });
		shotCoolTime_ = 10;
	}

	for (Bullet& bullet : bullets_) {
		bullet.position.y -= bullet.speed;
	}

	// 敵は上から下へ移動し、画面外に出たら上から再出現する
	for (Enemy& enemy : enemies_) {
		enemy.position.y += enemy.speed;
		if (enemy.position.y - enemy.radius > 720.0f) {
			ResetEnemy(enemy, -enemy.radius);
		}
	}

	for (Bullet& bullet : bullets_) {
		for (Enemy& enemy : enemies_) {
			float dx = bullet.position.x - enemy.position.x;
			float dy = bullet.position.y - enemy.position.y;
			float distance = std::sqrt(dx * dx + dy * dy);
			if (distance <= bullet.radius + enemy.radius) {
				score_ += 100;
				bullet.position.y = -100.0f;
				ResetEnemy(enemy, -enemy.radius);
				break;
			}
		}
	}

	bullets_.erase(
		std::remove_if(
			bullets_.begin(), bullets_.end(),
			[](const Bullet& bullet) { return bullet.position.y < -bullet.radius; }),
		bullets_.end());

	time_--;
	if (time_ <= 0) {
		nextScene_ = SceneType::kResult;
	}
}

void GameScene::Draw() {
	Novice::DrawSprite(0, 0, backgroundHandle_, 1.0f, 1.0f, 0.0f, WHITE);

	for (const Enemy& enemy : enemies_) {
		Novice::DrawSprite(
			static_cast<int>(enemy.position.x - 16.0f),
			static_cast<int>(enemy.position.y - 16.0f),
			enemyHandle_, 1.0f, 1.0f, 0.0f, WHITE);
	}

	for (const Bullet& bullet : bullets_) {
		Novice::DrawSprite(
			static_cast<int>(bullet.position.x - 6.0f),
			static_cast<int>(bullet.position.y - 6.0f),
			bulletHandle_, 1.0f, 1.0f, 0.0f, WHITE);
	}

	Novice::DrawSprite(
		static_cast<int>(playerPosition_.x - 24.0f),
		static_cast<int>(playerPosition_.y - 24.0f),
		playerHandle_, 1.0f, 1.0f, 0.0f, WHITE);

	Novice::DrawBox(10, 10, 270, 90, 0.0f, 0x102010AA, kFillModeSolid);
	Novice::ScreenPrintf(20, 20, "Score: %d", score_);
	Novice::ScreenPrintf(20, 45, "Time: %d", time_ / 60);
	Novice::ScreenPrintf(20, 70, "WASD: Move  SPACE: Shoot");
}

SceneType GameScene::GetNextScene() const {
	return nextScene_;
}

int GameScene::GetScore() const {
	return score_;
}
