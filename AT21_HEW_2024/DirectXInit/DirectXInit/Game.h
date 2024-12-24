#pragma once
#include "Object.h"
#include "input.h"

#define image		(4)

enum SceneName {
	TITLE,
	STAGE_1,
	RESULT
};

class Game
{
private:
	Object background;//プレイヤーオブジェクト
	Object titlesanta;//タイトル
	Object title;//タイトル

	Object santa;//サンタオブジェクト
	Object mounten[image];//ゲーム画面の背景にある山
	Object tree[image];//ゲーム画面の背景にある木
	Object ground[image];//地面
	Object star;//星
	Object sky;//空


	int changescene = TITLE;//シーン

	Input input; //入力

public:
	void Init(HWND hWnd);//初期化
	void Update(void);//更新
	void Draw();//描画
	void Uninit();//終了


};

