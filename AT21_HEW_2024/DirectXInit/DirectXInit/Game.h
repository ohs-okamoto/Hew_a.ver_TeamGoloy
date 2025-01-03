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
	Object wood[image];//ゲーム画面の背景にある木
	Object ground[image];//地面
	Object star;//星
	Object sky;//空
	Object tree;//木


	bool changeRight = true;//キャラの
	bool changeLeft = true;//


	int changescene = TITLE;//シーン
	int framcount = 0;
	Input input; //入力

public:
	void Init(HWND hWnd);//初期化
	void Update(void);//更新
	void Draw();//描画
	void Uninit();//終了

	DirectX::XMFLOAT3 GetSantaPos()const; // サンタの位置を取得するメソッド
	const Object& GetSanta() const; // サンタオブジェクトへの参照を取得するメソッド

	DirectX::XMFLOAT3 GetGroundPos(int index)const;
	const Object& GetGround(int index) const; // 地面オブジェクトへの参照を取得する
};

