#pragma once
#include "Object.h"
#include "input.h"
#include "Texture.h"

#define image		(10)

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
	Object rock[image];//いわ
	Object icicle[image];//木
	Object stairs[image];//階段

	Object snowman[image];//雪だるま
	Object tonakai;//トナカイ
	Object star_monster;//星野　敵
	
	Object present[image];//プレゼント
	Object goal;//ゴール

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

