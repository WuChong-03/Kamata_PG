#include <Novice.h>

#include <cstring>

#include "SceneManager.h"

const char kWindowTitle[] = "GC2C_02_ゴチュウ";
const int kWindowWidth = 1280;
const int kWindowHeight = 720;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Novice::Initialize(kWindowTitle, kWindowWidth, kWindowHeight);

	char keys[256] = { 0 };
	char preKeys[256] = { 0 };
	SceneManager sceneManager;

	while (Novice::ProcessMessage() == 0) {
		Novice::BeginFrame();

		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		sceneManager.Update(keys, preKeys);
		sceneManager.Draw();

		Novice::EndFrame();

		if (!preKeys[DIK_ESCAPE] && keys[DIK_ESCAPE]) {
			break;
		}
	}

	Novice::Finalize();
	return 0;
}
