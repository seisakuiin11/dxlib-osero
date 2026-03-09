#include "Board.h"
#include "DxLib.h"
#include <iostream>
#include <string>

Board::Board()
{
	width = 0;
	height = 0;
	blComa = 0;
	whComa = 0;
	endFlag = false;
	putFlag = false;
	resultFlag = false;
}

Board::~Board()
{
}

/*** 初期化 ***/
void Board::Initialize() {
	pos = Vector2(400,100);
	width = 720;
	height = 720;
	endFlag = false;
	putFlag = false;
	resultFlag = false;
	time = 0;

	int mWidth = width / 8;
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++)
		{
			Vector2 mPos = Vector2(pos.x + (mWidth * x), pos.y + (mWidth * y));
			masu[y][x].Initialize(mPos, mWidth, Empty);
			if ((x == 3 && y == 3) || (x == 4 && y == 4)) masu[y][x].SetComa(White);
			if ((x == 4 && y == 3) || (x == 3 && y == 4)) masu[y][x].SetComa(Black);
		}
	}
}

/*** ゲーム内処理 ***/
int Board::Process(int Player) {
	if (endFlag && !resultFlag) { // ゲームが終了したら
		time++;
		if (time > 50) { // リザルトを表示
			time = 0;
			resultFlag = true;
			return -1; // プレイヤーの表示をやめる
		}
	}
	if (putFlag || endFlag) return Player;
	time++;
	if (time > 60) {
		// パスを表示した後、ターンを変える
		time = 0;
		int player = Player;
		player = player == Black ? White : Black;
		Check(player);
		return player;
	}
	return Player;
}

/*** 描画 ***/
void Board::Disp() {
	if (resultFlag) {
		// 勝者を表示
		SetFontSize(110);
		if(blComa == whComa) DrawString(400, 300,"引き分け", Color::Black());
		else if(blComa > whComa) DrawString(300, 300, "プレイヤー1の勝ち", Color::Black());
		else DrawString(300, 300, "プレイヤー2の勝ち", Color::Black());
		// 駒数を表示
		SetFontSize(60);
		std::string text = "黒：" + std::to_string(blComa);
		DrawString(500, 650, text.c_str(), Color::Black());
		text = "白：" + std::to_string(whComa);
		DrawString(900, 650, text.c_str(), Color::Black());
		return;
	}
	// 盤面を表示
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++)
		{
			masu[y][x].Disp();
		}
	}
	// 駒数を表示
	SetFontSize(45);
	std::string text = "黒：" + std::to_string(blComa);
	DrawString(1130, 600, text.c_str(), Color::Black());
	text = "白：" + std::to_string(whComa);
	DrawString(1130, 650, text.c_str(), Color::Black());

	if (endFlag) { // ゲーム終了
		SetFontSize(180);
		DrawString(570, 360, "終了", Color::Red());
		return;
	}
	if (putFlag) return; // おける場所があるなら戻る
	SetFontSize(150);
	DrawString(600, 360, "パス", Color::Red());
}

bool PutCheck(Box masu[][8], int x, int y, int player, int enemy);
/*** 設置可能マスの確認 ***/
void Board::Check(int Player) {
	int enemy = Player == Black ? White : Black;
	bool _putFlag = putFlag;
	putFlag = false;

	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++)
		{
			bool flag = PutCheck(masu, x, y, Player, enemy);
			masu[y][x].SetIsPut(flag);
			putFlag |= flag;
		}
	}
	// 両者がおけなければ ゲームを終了する
	if (!_putFlag && !putFlag) { endFlag = true; time = 0; }
	Count();

	// おける場所がなければ
	if (!putFlag) time = 0;
}

/*** 相手の駒を挟める場所の検索 → 設置可能マスの検索 ***/
bool PutCheck(Box masu[][8], int x, int y, int player, int enemy) {
	if (masu[y][x].GetComa() != Empty) return false; // すでに駒が置かれているなら
	int cx[8] = { 1,1,0,-1,-1,-1,0,1 };
	int cy[8] = { 0,1,1,1,0,-1,-1,-1 };
	bool flag = false;
	// 周り八マスを検索
	for (int i = 0; i < 8; i++) {
		int count = 0;
		int xx = x;
		int yy = y;
		do {
			// その先を検索
			xx += cx[i];
			yy += cy[i];
			if (xx < 0 || yy < 0 || xx >= 8 || yy >= 8) break; // 盤外なら
			if (masu[yy][xx].GetComa() != enemy) break; // 相手の駒じゃなければ
			// 相手の駒なら検索を続ける
			count++; // 相手の駒数をカウント
		} while (true);

		if (xx < 0 || yy < 0 || xx >= 8 || yy >= 8) continue; // 盤外なら
		if (count == 0) continue; // 挟める相手の駒がないなら

		// 終了地点が自分の駒ならTRUEフラグを返す 空マスなら続行
		flag = masu[yy][xx].GetComa() == player;
		if(flag) break;
	}
	return flag;
}

void SetPut(Box masu[][8], int x, int y, int player);
int Reversi(Box masu[][8], int x, int y, int xx, int yy, int player, int enemy);
/*** 駒の設置 ***/
int Board::Put(int Player, Vector2 cPos) {
	if (!putFlag || endFlag) return Player; // おける場所がなければ戻る
	int player = Player;
	bool flag = false;

	// マスとの当たり判定
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++)
		{
			flag = masu[y][x].Collition(cPos);
			if (flag) {
				SetPut(masu, x, y, player);
				break;
			}
		}
		if (flag) break;
	}

	// 当たっていなければターンを変えない
	if (!flag) return player;
	// 当たっていればターンを変える
	player = player == Black ? White : Black;
	Check(player);
	return player;
}

/*** 駒の設置、ひっくり返し ***/
void SetPut(Box masu[][8], int x, int y, int player) {
	masu[y][x].SetComa(player);

	int cx[8] = { 1,1,0,-1,-1,-1,0,1 };
	int cy[8] = { 0,1,1,1,0,-1,-1,-1 };
	int enemy = player == Black ? White : Black;

	// 挟んだものをひっくり返す
	for (int i = 0; i < 8; i++) {
		Reversi(masu, x+cx[i], y+cy[i], cx[i], cy[i], player, enemy);
	}
}

/*** 間にある駒をひっくり返す ***/
int Reversi(Box masu[][8], int x, int y, int xx, int yy, int player, int enemy) {
	if (x < 0 || y < 0 || x >= 8 || y >= 8) return enemy; // 盤外なら
	// 駒が相手なら次のマスへ
	if (masu[y][x].GetComa() == enemy) {
		int coma = Reversi(masu, x + xx, y + yy, xx, yy, player, enemy);
		masu[y][x].SetComa(coma);
		return coma;
	}
	// 駒が自分ならひっくり返して戻る
	if (masu[y][x].GetComa() == player) {
		masu[y][x].SetComa(player);
		return player;
	}
	// 空白マスならひっくり返さず戻る
	return enemy;
}

/*** 駒数を数える ***/
void Board::Count() {
	blComa = 0;
	whComa = 0;
	int count[3] = { 0,0,0 };

	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			int i = masu[y][x].GetComa();
			count[i]++;
		}
	}

	blComa = count[Black];
	whComa = count[White];

	// ゲーム終了
	if (count[0] == 0 || count[1] == 0 || count[2] == 0) { endFlag = true; time = 0; }
}

bool Board::GetEndFlag() {
	return endFlag;
}