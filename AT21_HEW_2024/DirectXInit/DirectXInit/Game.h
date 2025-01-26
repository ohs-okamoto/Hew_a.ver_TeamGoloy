#pragma once
#include "Object.h"
#include "input.h"
#include "Texture.h"
#include "Item.h"

#define image		(10)

enum SceneName {
	TITLE,
	STAGE1_LOADING,
	STAGE_1,
	STAGE_2,
	RESULT
};

class Game
{
private:
	Object background;//プレイヤーオブジェクト
	Object titlesanta;//タイトル
	Object title;//タイトル

	Object Stage1_Loading;


	Object santa;//サンタオブジェクト
	Object star;//星
	Object sky;//空
	Object mounten[image];//ゲーム画面の背景にある山

	Object itemUi[9]; // アイテム入手時のUI


	Object wood[image];//ゲーム画面の背景にある木
	Object ground[image];//地面
	Object tree;//木
	Object rock[image];//いわ
	Object icicle[image];//木
	Object stairs[image];//階段

	Object snowman[image];//雪だるま
	Object tonakai;//トナカイ
	Object star_monster;//星野　敵
	
	Object present[image];//プレゼント
	Object BigPresent[image];//プレゼント
	Object snowball[image];//雪玉
	Object goal;//ゴール


	//ステージ２関連
	Object Ground_Stge2[image];//ステージ２の床
	Object Tree_Stge2[image];//木
	Object Block_Stge2[image];//ブロック
	Object Icicles_Stge2[image];//つらら
	Object Stairs_Stge2[image];//階段
	Object Present_Stage2[image];//プレゼント
	Object BigPresent_Stage2[image];//プレゼント
	Object Breakrock_Stge2[image];//壊せる岩
	Object Collectrock_Stage2[image];

	//リザルト関連
	Object Result;//リザルト背景
	Object Number[2];//数字
	Object ResultStar[5];//星
	Object GrayStar[5];//透明な星
	Object Result_Bigpresent;//大プレ
	Object Result_present;//プレぜんと

	bool changeRight = true;//キャラの
	bool changeLeft = true;//


	int changescene = TITLE;//シーン

	int presentcount=0;//何個プレゼントとったか

	int score = 0;//スコア

	//フレームカウント
	int framcount = 0;
	int framcount2 = 0;
	//敵の移動フラグ
	bool moveFg1 = false;
	bool moveFg2= false;
	bool moveFg3 = false;
	bool moveFg4 = false;
	bool moveFg5 = false;

	
	float speed = 0;

	Input input; //入力

	

	int itemID;
	Item* item; //メンバ変数

	// アイテムを透明にするかしないかの変数
	int rock_visible1 = 0;
	int rock_visible2 = 0;
	int rock_visible3 = 0;
	int rock_visible4 = 0;
	int rock_visible5 = 0;
	int rock_visible6 = 0;
	int snow_visible1 = 0;
	int snow_visible2 = 0;
	int snow_visible3 = 0;
	int snow_visible4 = 0;
	int snow_visible5 = 0;
	int snow_visible6 = 0;

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

