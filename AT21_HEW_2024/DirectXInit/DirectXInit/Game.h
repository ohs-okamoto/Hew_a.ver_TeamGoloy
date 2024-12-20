#pragma once
#include "Object.h"
#include "input.h"
class Game
{
private:
	Object player;//プレイヤーオブジェクト
	Object background;//プレイヤーオブジェクト
	Input input; //入力

public:
	void Init(HWND hWnd);//初期化
	void Update(void);//更新
	void Draw();//描画
	void Uninit();//終了


};

