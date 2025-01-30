#pragma once
#include "Object.h"
#include "input.h"
#include "Texture.h"
#include "Item.h"
#include "Sound.h"

#define image		(10)

enum SceneName {
	TITLE,
	STAGE1_LOADING,
	STAGE2_LOADING,
	BOSS_LOADING,
	STAGESELECT,
	STAGE_1,
	STAGE_2,
	BOSS,
	RESULT
};

class Game
{
private:
	Object background;//プレイヤーオブジェクト
	Object titlesanta;//タイトル
	Object title;//タイトル

	Object Stage1_Loading;


	Object santa_Nor[8];  // サンタオブジェクト 通常袋
	Object santa_Huro[8]; // サンタオブジェクト 風呂敷
	Object santa_Kin[7];  // サンタオブジェクト 巾着袋

	Object star;//星
	Object sky;//空
	Object mounten[image];//ゲーム画面の背景にある山

	Object itemUi[9]; // アイテム入手時のUI

	Object use_rock[3];     // 投げ物
	Object use_snowball[3]; // 投げ物
	Object use_turara[3];   // 投げ物


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

	Object Returntogame;//ゲームに戻る

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
	Object Snowball_Stage2[image];



	//リザルト関連
	Object Result;//リザルト背景
	Object Number[2];//数字
	Object ResultStar[5];//星
	Object GrayStar[5];//透明な星
	Object Result_Bigpresent;//大プレ
	Object Result_present;//プレぜんと

	//UI関連
	Object Time;//制限時間
	Object ItemStock;//持っている岩、雪玉
	Object Number_UI[3];//数字　1:スコア　2:時間
	Object UseBag;//現在の袋
	Object ScoreCounter;

	//ゲームオーバー画面
	Object Gameover;//背景
	Object GoodMorning;//おはよう
	Object Retry;//リトライ
	Object TitleBack;//タイトルに戻る
	Object Cursor;
	//ステージセレクト
	Object StegeSelect;//ステージセレクト
	Object SantaCursor;//サンタカーソル
	Object PressBbotton;//A押してね
	Object pause;//ポーズ画面オブジェクト


	Object rule;//操作方法
	//Object pause;//ポーズ画面オブジェクト

	bool gameoverFg = false;//ポーズフラグ
	bool pauseFg = false;//ポーズフラグ

	bool changeRight = true;//キャラの
	bool changeLeft = true;//


	int changescene = TITLE;//シーン

	int presentcount=0;//何個プレゼントとったか

	int score = 0;//スコア



	int time = 150;
	int cleartime = 0;

	bool HitFg = false;

	bool ResettingFg = false;

	int hitcooltime=0;//敵と当たった時の無敵時間

	//セクレト画面での移動フラグ
	bool Select_MoverightFg = false;
	bool Select_MoveleftFg = false;

	bool CursorFg = false;

	//動きが止まってるか
	bool StopCheck =true;

	//フレームカウント
	int framcount = 0;
	int framcount2 = 0;
	int framcount3 = 0;
	int framcount4 = 0;
	int framcount5 = 0;
	//敵の移動フラグ
	bool moveFg1 = false;
	bool moveFg2= false;
	bool moveFg3 = false;
	bool moveFg4 = false;
	bool moveFg5 = false;

	
	float speed = 0;

	Input input; //入力

	int select = 1;

	
	Item* item; //メンバ変数
	Sound sound;


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

	// この世界には二つの物がある。石か石以外か。 0:初期値　1:石　2:雪玉
	int itemID_1 = 0;
	int itemID_2 = 0;
	int itemID_3 = 0;

	// アイテム使用時の動き
	bool itemMove1 = false;
	bool itemMove2 = false;
	bool itemMove3 = false;

	// アイテム使用中の座標の管理
	bool itemMove1_M = false;
	bool itemMove2_M = false;
	bool itemMove3_M = false;

	// 次のアイテムが出るまで使えません
	int changeItem = 0;

	// サンタの向き
	int direction = 0; // 0:右　1:左

	// サンタの画像
	int santaImage = 0;

	// 袋の力
	int bugPower = 0; // 0:無し　1:威力弱　2:威力中　3:威力強(最大威力)

	// 固有能力変数
	bool sp_ani = false; 

	bool changeRight_SP_1 = true;//キャラの
	bool changeLeft_SP_1 = true;//
	bool changeRight_SP = true;//キャラの
	bool changeLeft_SP = true;//

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

