#pragma once
#include <stddef.h>

class Enemy {
public:
	enum class Phase {
		Approach,
		Shot,
		Leave,
		Count,
	};

	using PhaseFunc = void (Enemy::*)();

	Enemy();
	void Update();
	bool IsFinished();

private:
	void Approach();
	void Shot();
	void Leave();
	void ChangePhase(Phase nextPhase);

	static PhaseFunc phaseTable_[static_cast<size_t>(Phase::Count)];

	Phase phase_;
	int phaseTimer_;
	bool isFinished_;
};
