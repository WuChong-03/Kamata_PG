#include "Enemy.h"
#include <stdio.h>

Enemy::PhaseFunc Enemy::phaseTable_[static_cast<size_t>(Enemy::Phase::Count)] = {
	&Enemy::Approach,
	&Enemy::Shot,
	&Enemy::Leave,
};

Enemy::Enemy() {
	phase_ = Phase::Approach;
	phaseTimer_ = 0;
	isFinished_ = false;
}

void Enemy::Update() {
	if (isFinished_) {
		return;
	}

	(this->*phaseTable_[static_cast<size_t>(phase_)])();
}

bool Enemy::IsFinished() {
	return isFinished_;
}

void Enemy::Approach() {
	printf("敵が接近しています。\n");
	phaseTimer_++;

	if (phaseTimer_ >= 3) {
		printf("接近が完了しました。射撃に移ります。\n");
		ChangePhase(Phase::Shot);
	}
}

void Enemy::Shot() {
	printf("敵が射撃しています。\n");
	phaseTimer_++;

	if (phaseTimer_ >= 2) {
		printf("射撃が完了しました。離脱に移ります。\n");
		ChangePhase(Phase::Leave);
	}
}

void Enemy::Leave() {
	printf("敵が離脱しています。\n");
	phaseTimer_++;

	if (phaseTimer_ >= 3) {
		printf("敵は離脱しました。\n");
		isFinished_ = true;
	}
}

void Enemy::ChangePhase(Phase nextPhase) {
	phase_ = nextPhase;
	phaseTimer_ = 0;
}
