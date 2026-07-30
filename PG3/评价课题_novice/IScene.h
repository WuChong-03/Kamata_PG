#pragma once

enum class SceneType {
	kTitle,
	kGame,
	kResult,
	kNone,
};

// すべてのシーンが継承するインターフェース
class IScene {
public:
	virtual ~IScene() = default;
	virtual void Initialize() = 0;
	virtual void Update(const char* keys, const char* preKeys) = 0;
	virtual void Draw() = 0;
	virtual SceneType GetNextScene() const = 0;
	virtual int GetScore() const { return 0; }
};
