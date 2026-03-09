#include "SceneManager.h"

SceneManager::SceneManager()
{
	sceneState = 0;
	for (int i = 0; i < MAXSCENE; i++) scene[i] = nullptr;
}

SceneManager::~SceneManager()
{
}

/*** ‰Šú‰» ***/
void SceneManager::Initialize(SceneState State) {
	sceneState = State; // ƒV[ƒ“‚Ìİ’è
	scene[TITLE] = &title;
	scene[INGAME] = &inGame;
	for (int i = 0; i < MAXSCENE; i++) scene[i]->Initialize();
}

/*** ƒQ[ƒ€“àˆ— ***/
int SceneManager::Process() {
	int flag = 1;
	int _sceneState = scene[sceneState]->Process(&flag);
	if (_sceneState != sceneState) scene[_sceneState]->Initialize();
	sceneState = _sceneState;
	return flag;
}

/*** •`‰æ ***/
void SceneManager::Disp() {
	scene[sceneState]->Disp();
}