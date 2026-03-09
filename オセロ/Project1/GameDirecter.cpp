#include "GameDirecter.h"

GameDirecter::GameDirecter()
{
}

GameDirecter::~GameDirecter()
{
}

/*** 初期化 ***/
void GameDirecter::Initialize() {
	board.Initialize();
	player.Initialize();
	board.Check(player.GetTurn());
}

/*** ゲーム内処理 ***/
int GameDirecter::Process(int* flag) {
	int scene = 1;
	// ボード 処理
	int _turn = board.Process(player.GetTurn());
	player.SetTurn(_turn);
	// プレイヤー 処理
	Vector2 vec = player.Process();
	if (vec.x != -1 && vec.y != -1) {
		int turn = board.Put(player.GetTurn(), vec);
		player.SetTurn(turn);
	}

	if (GetKey()->GetInputKeyUp(KEY_INPUT_ESCAPE)) scene = 0;
	if (GetKey()->GetInputKeyUp(KEY_INPUT_SPACE) && board.GetEndFlag()) scene = 0;

	return scene;
}

/*** 描画 ***/
void GameDirecter::Disp() {
	board.Disp();
	player.Disp();
}