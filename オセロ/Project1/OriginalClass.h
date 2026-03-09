#pragma once
#include <iostream>
#include "WindowData.h"

template<typename T> // どんな型にも対応できる万能型
class List
{
public:
	List() = default;
	explicit List(size_t num) {
		if (num > 0) {
			data = new T[num];
			capacity = num;
		}
		length = num;
	}
	~List() { delete[] data; };

private:
	T* data = nullptr; // 動的配列のポインタ
	size_t capacity = 0; // 格納できる要素数
	size_t length = 0; // 格納している要素数
	void Resize(size_t _capacity) { // 領域の再確保
		if (_capacity < length) {
			throw std::length_error("Resize smaller than current length");
		}

		T* new_data = new T[_capacity];
		if (data) {
			std::copy(data, data + length, new_data);
			delete[] data;
		}
		data = new_data;
		capacity = _capacity;
	};
public:
	void Add(const T& value) { // 要素の追加
		if (length == capacity) {
			Resize(capacity == 0 ? 1 : capacity * 2);
		}
		data[length++] = value;
	}
	void RemoveAt(size_t index) { // 指定箇所の要素の削除
		if (index >= length) return;
		for (size_t i = index; i < length - 1; i++) { data[i] = data[i + 1]; }
		length--;
	}
	void Remove(const T& value) { // 指定箇所の要素の削除
		int num = -1;
		for (int i = 0; i < length; i++) {
			if (value == data[i]) {
				num = i;
				break;
			}
		}
		if (num == -1) return;
		for (size_t i = num; i < length - 1; i++) { data[i] = data[i + 1]; }
		length--;
	}
	size_t Count() const {
		return length;
	}
	T& operator[](size_t index) {
		return data[index];
	}
	const T& operator[](size_t index) const {
		return data[index];
	}

	List& operator=(const List& other) { // コピー代入演算子
		if (this != &other) {
			delete[] data;
			capacity = other.capacity;
			length = other.length;
			if (capacity > 0) {
				data = new T[capacity];
				std::copy(other.data, other.data + length, data);
			}
			else {
				data = nullptr;
			}
		}
		return *this;
	}

	// ムーブコンストラクタ
	List(List&& other) noexcept
		: data(other.data), capacity(other.capacity), length(other.length) {
		other.data = nullptr;
		other.capacity = 0;
		other.length = 0;
	}

	// ムーブ代入演算子
	List& operator=(List&& other) noexcept {
		if (this != &other) {
			delete[] data;
			data = other.data;
			capacity = other.capacity;
			length = other.length;

			other.data = nullptr;
			other.capacity = 0;
			other.length = 0;
		}
		return *this;
	}
};

/// <summary>
/// ベクトル変数 2D
/// </summary>
class Vector2
{
public:
	Vector2(int X = 0, int Y = 0);
	~Vector2();
private:
	
public:
	float x, y;
	float Magnitude();
public:
	static Vector2 zero();
	static Vector2 Up();
	static Vector2 Down();
	static Vector2 Left();
	static Vector2 Right();
	Vector2 operator+(const Vector2& vec) const { // +
		return Vector2(x + vec.x, y + vec.y);
	}
	Vector2 operator-(const Vector2& vec) const { // -
		return Vector2(x - vec.x, y - vec.y);
	}
	Vector2 operator*(const float scalar) const { // スカラー乗算
		return Vector2(x * scalar, y * scalar);
	}
	bool operator==(const Vector2& vec) const { // 等価比較
		if (x == vec.x && y == vec.y) return true;
		return false;
	}
	bool operator!=(const Vector2& vec) const { // 非等価比較
		if (x == vec.x && y == vec.y) return false;
		return true;
	}
};

/// <summary>
/// 重力関係 2D
/// </summary>
class RigidBody2D
{
public:
	RigidBody2D();
	~RigidBody2D();

private:
	int mass; // 質量
	Vector2 force; // 力の量と方向
	int underLine; // 仮の地面
	float gravity; // 重力
	float airDensity; // 空気密度 (空気抵抗の強さに影響)
	float drag; // 抗力係数
	Vector2 startVec;
public:
	/// <summary>
	/// 初期化
	/// </summary>
	/// <param name="Mass">質量</param><param name="Force">力の方向と量</param>
	/// <param name="UnderLine">最低ライン</param><param name="Gravity">重力(9.8f)</param>
	void Initialize(int Mass, Vector2 Force, int UnderLine, float Gravity = 9.8f, float AirDensity = 1.225f, float Drag = 0.47);
	/// <summary>
	/// 自由落下
	/// </summary>
	/// <param name="pos">セットしたオブジェクトのポジション</param>
	void FreeFall(Vector2* pos); // 自由落下
	/// <summary>
	/// 力を加える
	/// </summary>
	/// <param name="Force">加えたい力の方向と量</param>
	void AddForce(Vector2 Force);
	/// <summary>
	/// 力の設定
	/// </summary>
	/// <param name="Vel">設定したい力の方向と量</param>
	void SetVelocity(Vector2 Vel);
};

/// <summary>
/// カラー変数
/// </summary>
class Color
{
public:
	Color(int r,int g,int b);
	~Color();
private:

public:
	int color;
public:
	static int Black();
	static int White();
	static int Red();
	static int Green();
	static int Blue();
	static int Orange();
	static int Yellow();
	static int Pink();
	static int Purple();
	static int Violet();
	static int Cyan();
	static int Lightblue();
	static int Lightgreen();
	static int Gray();
};

/// <summary>
/// フォント変数
/// </summary>
class Font
{
public:
	Font();
	~Font();
private:
	int fnt_Original;
public:
	static int* GetFontGosic();
	static int* GetFontMintyo();
	static void SetFont(char FntName, int Size, int Thick);
	static int* GetFont();
};

/// <summary>
/// フレームレート管理
/// </summary>
class Fps
{
public:
	Fps();
	~Fps();
private:
	int startTime;
	int count;
	float fps;
	int FPS;
public:
	void SetFPS(int _FPS);
	/// <summary>
	/// 処理を開始する時間を取得
	/// </summary>
	void Update();
	/// <summary>
	/// 指定したFPSになるように待つ
	/// </summary>
	void Wait();
	/// <summary>
	/// FPSを左上に表示する
	/// </summary>
	void DrawFps();
};

/// <summary>
/// テキスト
/// </summary>
class Text
{
public:
	Text();
	~Text();
	enum PosType {
		Left = 0, Center, Right
	};
private:
	std::string text;
	int size;
	int underSpace;
	int color;
	Vector2 pos;
	PosType posType;
public:
	/// <summary>
	/// 初期化
	/// </summary>
	/// <param name="_text">文字列</param>
	/// <param name="_pos">ポジション</param>
	/// <param name="_posType">ポジションを基準にどこに描画するか</param>
	/// <param name="_size">サイズ</param>
	/// <param name="_underSpace">文字下の空白</param>
	/// <param name="_color">色</param>
	void Initialize(std::string _text, Vector2 _pos, PosType _posType = Left, int _size = 40, int _underSpace = 10, int _color = Color::Black());
	void Disp();
	/// <summary>
	/// テキスト描画処理
	/// </summary>
	/// <param name="_text">文字列</param>
	/// <param name="_pos">ポジション</param>
	/// <param name="_posType">ポジションを基準にどこに描画するか</param>
	/// <param name="_size">文字サイズ</param>
	/// <param name="underSpace">文字下の空白</param>
	/// <param name="_color">色</param>
	static void DispText(std::string _text, Vector2 _pos, PosType _posType = Left, int _size = 40, int underSpace = 10, int _color = Color::Black());
};

/// <summary>
/// ボタン
/// </summary>
class Btn
{
public:
	Btn();
	~Btn();

private:
	int width;
	int height;
	int size;
	Vector2 pos;
	int color;
	int highlightColor;
	Text text;
public:
	/// <summary>
	/// 初期化
	/// </summary>
	/// <param name="Width">横幅</param>
	/// <param name="Height">縦幅</param>
	/// <param name="Pos">ポジション</param>
	void Initialize(int Width, int Height, int Size, Vector2 Pos, Vector2 ShiftTextPos, int Color, std::string _text, int HighlightColor = -1);
	/// <summary>
	/// ボタンの表示
	/// </summary>
	void Disp();
	/// <summary>
	/// 当たり判定
	/// </summary>
	/// <param name="mousePos">クリック時のポジション</param>
	bool OnCollition(Vector2 mousePos);
};