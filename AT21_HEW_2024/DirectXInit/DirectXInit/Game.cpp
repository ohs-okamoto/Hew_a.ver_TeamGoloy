#include "Game.h"
#include "Texture.h"
#include "Collision.h"
#include "Item.h"
#include <iostream>


using namespace std;

//2024年12/24 横スクロール 作成　畦内
//2024年12/31  ステージ１作成 　畦内



void Game::Init(HWND hWnd)
{
	D3D_Create(hWnd);//Directxを初期化
	sound.Init();//サウンドを初期化
	//====================================================
	//プレイヤー関連
	//====================================================
	
	// 通常袋
	santa_Nor[0].Init(L"asset/Santa_Normal_Move_v2.png", 4, 4);//サンタを初期化
	santa_Nor[0].SetPos(-400.0f, -175.0f, 0.0f);		//位置を設定
	santa_Nor[0].SetSize(150.0f, 120.0f, 0.f);	//大きさを設定
	santa_Nor[0].SetAngle(0.0f);             		//角度を設定
	santa_Nor[0].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //色を設定

	santa_Nor[1].Init(L"asset/Santa_Normal_Pack_Move_v4.png", 4, 4);//サンタを初期化
	santa_Nor[1].SetPos(-400.0f, -175.0f, 0.0f);		//位置を設定
	santa_Nor[1].SetSize(150.0f, 120.0f, 0.f);	//大きさを設定
	santa_Nor[1].SetAngle(0.0f);             		//角度を設定
	santa_Nor[1].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //色を設定

	santa_Nor[2].Init(L"asset/Santa_Normal_Jump_v2.png", 1, 2);//サンタを初期化
	santa_Nor[2].SetPos(-400.0f, -175.0f, 0.0f);		//位置を設定
	santa_Nor[2].SetSize(150.0f, 120.0f, 0.f);	//大きさを設定
	santa_Nor[2].SetAngle(0.0f);             		//角度を設定
	santa_Nor[2].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //色を設定

	santa_Nor[3].Init(L"asset/Santa_Normal_Pack_Jump_v2.png", 1, 2);//サンタを初期化
	santa_Nor[3].SetPos(-400.0f, -175.0f, 0.0f);		//位置を設定
	santa_Nor[3].SetSize(150.0f, 120.0f, 0.f);	//大きさを設定
	santa_Nor[3].SetAngle(0.0f);             		//角度を設定
	santa_Nor[3].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //色を設定

	santa_Nor[4].Init(L"asset/Santa_Normal_In_v2.png", 5, 2);//サンタを初期化
	santa_Nor[4].SetPos(-400.0f, -175.0f, 0.0f);		//位置を設定
	santa_Nor[4].SetSize(150.0f, 120.0f, 0.f);	//大きさを設定
	santa_Nor[4].SetAngle(0.0f);             		//角度を設定
	santa_Nor[4].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //色を設定

	santa_Nor[5].Init(L"asset/Santa_Normal_Out_v2.png", 5, 2);//サンタを初期化
	santa_Nor[5].SetPos(-400.0f, -175.0f, 0.0f);		//位置を設定
	santa_Nor[5].SetSize(150.0f, 120.0f, 0.f);	//大きさを設定
	santa_Nor[5].SetAngle(0.0f);             		//角度を設定
	santa_Nor[5].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //色を設定

	santa_Nor[6].Init(L"asset/Santa_Normal_SP_v2.png", 4, 2);//サンタを初期化
	santa_Nor[6].SetPos(-400.0f, -175.0f, 0.0f);		//位置を設定
	santa_Nor[6].SetSize(150.0f, 120.0f, 0.f);	//大きさを設定
	santa_Nor[6].SetAngle(0.0f);             		//角度を設定
	santa_Nor[6].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //色を設定

	santa_Nor[7].Init(L"asset/Santa_Normal_Pack_SP_v2.png", 5, 2);//サンタを初期化
	santa_Nor[7].SetPos(-400.0f, -175.0f, 0.0f);		//位置を設定
	santa_Nor[7].SetSize(150.0f, 120.0f, 0.f);	//大きさを設定
	santa_Nor[7].SetAngle(0.0f);             		//角度を設定
	santa_Nor[7].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //色を設定

	// 風呂敷
	santa_Huro[0].Init(L"asset/Santa_Huro_Move_v2.png", 4, 4);//サンタを初期化
	santa_Huro[0].SetPos(-400.0f, -175.0f, 0.0f);		//位置を設定
	santa_Huro[0].SetSize(150.0f, 120.0f, 0.f);	//大きさを設定
	santa_Huro[0].SetAngle(0.0f);             		//角度を設定
	santa_Huro[0].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //色を設定

	santa_Huro[1].Init(L"asset/Santa_Huro_Pack_Move_v2.png", 4, 4);//サンタを初期化
	santa_Huro[1].SetPos(-400.0f, -175.0f, 0.0f);		//位置を設定
	santa_Huro[1].SetSize(150.0f, 120.0f, 0.f);	//大きさを設定
	santa_Huro[1].SetAngle(0.0f);             		//角度を設定
	santa_Huro[1].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //色を設定

	santa_Huro[2].Init(L"asset/Santa_Huro_Jump_v2.png", 1, 2);//サンタを初期化
	santa_Huro[2].SetPos(-400.0f, -175.0f, 0.0f);		//位置を設定
	santa_Huro[2].SetSize(150.0f, 120.0f, 0.f);	//大きさを設定
	santa_Huro[2].SetAngle(0.0f);             		//角度を設定
	santa_Huro[2].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //色を設定

	santa_Huro[3].Init(L"asset/Santa_Huro_Pack_Jump_v2.png", 1, 2);//サンタを初期化
	santa_Huro[3].SetPos(-400.0f, -175.0f, 0.0f);		//位置を設定
	santa_Huro[3].SetSize(150.0f, 120.0f, 0.f);	//大きさを設定
	santa_Huro[3].SetAngle(0.0f);             		//角度を設定
	santa_Huro[3].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //色を設定

	santa_Huro[4].Init(L"asset/Santa_Huro_In_v2.png", 5, 2);//サンタを初期化
	santa_Huro[4].SetPos(-400.0f, -175.0f, 0.0f);		//位置を設定
	santa_Huro[4].SetSize(150.0f, 120.0f, 0.f);	//大きさを設定
	santa_Huro[4].SetAngle(0.0f);             		//角度を設定
	santa_Huro[4].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //色を設定

	santa_Huro[5].Init(L"asset/Santa_Huro_Out_v2.png", 5, 2);//サンタを初期化
	santa_Huro[5].SetPos(-400.0f, -175.0f, 0.0f);		//位置を設定
	santa_Huro[5].SetSize(150.0f, 120.0f, 0.f);	//大きさを設定
	santa_Huro[5].SetAngle(0.0f);             		//角度を設定
	santa_Huro[5].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //色を設定

	santa_Huro[6].Init(L"asset/Santa_Huro_SP.png", 5, 2);//サンタを初期化
	santa_Huro[6].SetPos(-400.0f, -175.0f, 0.0f);		//位置を設定
	santa_Huro[6].SetSize(150.0f, 120.0f, 0.f);	//大きさを設定
	santa_Huro[6].SetAngle(0.0f);             		//角度を設定
	santa_Huro[6].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //色を設定

	santa_Huro[7].Init(L"asset/Santa_Huro_Pack_SP.png", 5, 2);//サンタを初期化
	santa_Huro[7].SetPos(-400.0f, -175.0f, 0.0f);		//位置を設定
	santa_Huro[7].SetSize(150.0f, 120.0f, 0.f);	//大きさを設定
	santa_Huro[7].SetAngle(0.0f);             		//角度を設定
	santa_Huro[7].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //色を設定

	// 巾着袋
	santa_Kin[0].Init(L"asset/Santa_Kin_Move_v2.png", 4, 4);//サンタを初期化
	santa_Kin[0].SetPos(-400.0f, -175.0f, 0.0f);		//位置を設定
	santa_Kin[0].SetSize(150.0f, 120.0f, 0.f);	//大きさを設定
	santa_Kin[0].SetAngle(0.0f);             		//角度を設定
	santa_Kin[0].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //色を設定

	santa_Kin[1].Init(L"asset/Santa_Kin_Pack_Move_v2.png", 4, 4);//サンタを初期化
	santa_Kin[1].SetPos(-400.0f, -175.0f, 0.0f);		//位置を設定
	santa_Kin[1].SetSize(150.0f, 120.0f, 0.f);	//大きさを設定
	santa_Kin[1].SetAngle(0.0f);             		//角度を設定
	santa_Kin[1].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //色を設定

	santa_Kin[2].Init(L"asset/Santa_Kin_Jump_v2.png", 1, 2);//サンタを初期化
	santa_Kin[2].SetPos(-400.0f, -175.0f, 0.0f);		//位置を設定
	santa_Kin[2].SetSize(150.0f, 120.0f, 0.f);	//大きさを設定
	santa_Kin[2].SetAngle(0.0f);             		//角度を設定
	santa_Kin[2].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //色を設定

	santa_Kin[3].Init(L"asset/Santa_Kin_Pack_Jump_v2.png", 1, 2);//サンタを初期化
	santa_Kin[3].SetPos(-400.0f, -175.0f, 0.0f);		//位置を設定
	santa_Kin[3].SetSize(150.0f, 120.0f, 0.f);	//大きさを設定
	santa_Kin[3].SetAngle(0.0f);             		//角度を設定
	santa_Kin[3].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //色を設定

	santa_Kin[4].Init(L"asset/Santa_Kin_In_v2.png", 5, 2);//サンタを初期化
	santa_Kin[4].SetPos(-400.0f, -175.0f, 0.0f);		//位置を設定
	santa_Kin[4].SetSize(150.0f, 120.0f, 0.f);	//大きさを設定
	santa_Kin[4].SetAngle(0.0f);             		//角度を設定
	santa_Kin[4].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //色を設定

	santa_Kin[5].Init(L"asset/Santa_Kin_Out_v2.png", 5, 2);//サンタを初期化
	santa_Kin[5].SetPos(-400.0f, -175.0f, 0.0f);		//位置を設定
	santa_Kin[5].SetSize(150.0f, 120.0f, 0.f);	//大きさを設定
	santa_Kin[5].SetAngle(0.0f);             		//角度を設定
	santa_Kin[5].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //色を設定

	santa_Kin[6].Init(L"asset/Santa_Kin_SP.png", 3, 2);//サンタを初期化
	santa_Kin[6].SetPos(-400.0f, -175.0f, 0.0f);		//位置を設定
	santa_Kin[6].SetSize(150.0f, 120.0f, 0.f);	//大きさを設定
	santa_Kin[6].SetAngle(0.0f);             		//角度を設定
	santa_Kin[6].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //色を設定
	
	//====================================================
	//タイトル
	//====================================================
	title.Init(L"asset/Main_Rogo.png", 1, 1);//サンタを初期化
	title.SetPos(250.0f, 150.0f, 0.0f);		//位置を設定
	title.SetSize(500.0f, 400.0f, 0.f);	//大きさを設定
	title.SetAngle(0.0f);             		//角度を設定
	title.SetColor(1.0f, 1.0f, 1.0f, 1.0f); //色を設定

	PressBbotton.Init(L"asset/preb.png", 1, 1);//サンタを初期化
	PressBbotton.SetPos(250.0f, -200.0f, 0.0f);		//位置を設定
	PressBbotton.SetSize(550.0f, 400.0f, 0.f);	//大きさを設定
	PressBbotton.SetAngle(0.0f);             		//角度を設定
	PressBbotton.SetColor(1.0f, 1.0f, 1.0f, 1.0f); //色を設定

	titlesanta.Init(L"asset/Main_Ilust.png", 1, 1);//を初期化
	titlesanta.SetPos(0.0f, 0.0f, 0.0f);         //位置を設定
	titlesanta.SetSize(1280.0f, 720.0f, 0.f);     //大きさ設定
	titlesanta.SetAngle(0.0f);//角度を設定	    

	background.Init(L"asset/background.png", 1, 1);//プレイヤーを初期化
	background.SetPos(0.0f, 0.0f, 0.0f);         //位置を設定
	background.SetSize(1280.0f, 720.0f, 0.f);     //大きさ設定
	background.SetAngle(0.0f);//角度を設定	 

	//====================================================
	// セクレト画面
	//====================================================
	StegeSelect.Init(L"asset/Stageselect.png", 1, 1);//を初期化
	StegeSelect.SetPos(0.0f, 0.0f, 0.0f);         //位置を設定
	StegeSelect.SetSize(1280.0f, 720.0f, 0.f);     //大きさ設定
	StegeSelect.SetAngle(0.0f);//角度を設定	    

	SantaCursor.Init(L"asset/Santa_Normal_Pack_Move_v4.png", 4, 4);//を初期化
	SantaCursor.SetPos(-430.0f, 0.0f, 0.0f);         //位置を設定
	SantaCursor.SetSize(200.0f, 180.0f, 0.f);     //大きさ設定
	SantaCursor.SetAngle(0.0f);//角度を設定	   

	//====================================================
	// UI
	//====================================================

		// いわ bug1
	itemUi[0].Init(L"asset/iwa.png", 1, 1); //いわ
	itemUi[0].SetPos(-440.0f, 260.0f, 0.0f);//位置を特定
	itemUi[0].SetSize(110.0f, 110.0f, 0.0f);//大きさ設定
	itemUi[0].SetAngle(0.0f);//角度設定

	// いわ bug2
	itemUi[1].Init(L"asset/iwa.png", 1, 1); //いわ
	itemUi[1].SetPos(-520.0f, 270.0f, 0.0f);//位置を特定
	itemUi[1].SetSize(90.0f, 90.0f, 0.0f);//大きさ設定
	itemUi[1].SetAngle(0.0f);//角度設定

	// いわ bud3
	itemUi[2].Init(L"asset/iwa.png", 1, 1); //いわ
	itemUi[2].SetPos(-580.0f, 290.0f, 0.0f);//位置を特定
	itemUi[2].SetSize(60.0f, 60.0f, 0.0f);//大きさ設定
	itemUi[2].SetAngle(0.0f);//角度設定

	// 雪玉 bug1
	itemUi[3].Init(L"asset/yukidama.png", 1, 1); //雪玉
	itemUi[3].SetPos(-440.0f, 260.0f, 0.0f);//位置を特定
	itemUi[3].SetSize(100.0f, 100.0f, 0.0f);//大きさ設定
	itemUi[3].SetAngle(0.0f);//角度設定

	// 雪玉 bug2
	itemUi[4].Init(L"asset/yukidama.png", 1, 1); //雪玉
	itemUi[4].SetPos(-520.0f, 270.0f, 0.0f);//位置を特定
	itemUi[4].SetSize(80.0f, 80.0f, 0.0f);//大きさ設定
	itemUi[4].SetAngle(0.0f);//角度設定

	// 雪玉 bug3
	itemUi[5].Init(L"asset/yukidama.png", 1, 1); //雪玉
	itemUi[5].SetPos(-580.0f, 290.0f, 0.0f);//位置を特定
	itemUi[5].SetSize(50.0f, 50.0f, 0.0f);//大きさ設定
	itemUi[5].SetAngle(0.0f);//角度設定

	// つらら bug1
	itemUi[6].Init(L"asset/turara.png", 1, 1); //いわ
	itemUi[6].SetPos(-600.0f, 300.0f, 0.0f);//位置を特定
	itemUi[6].SetSize(90.0f, 90.0f, 0.0f);//大きさ設定
	itemUi[6].SetAngle(0.0f);//角度設定

	// つらら bug2
	itemUi[7].Init(L"asset/turara.png", 1, 1); //いわ
	itemUi[7].SetPos(-600.0f, 220.0f, 0.0f);//位置を特定
	itemUi[7].SetSize(90.0f, 90.0f, 0.0f);//大きさ設定
	itemUi[7].SetAngle(0.0f);//角度設定

	// つらら bug3
	itemUi[8].Init(L"asset/turara.png", 1, 1); //いわ
	itemUi[8].SetPos(-600.0f, 120.0f, 0.0f);//位置を特定
	itemUi[8].SetSize(90.0f, 90.0f, 0.0f);//大きさ設定
	itemUi[8].SetAngle(0.0f);//角度設定

	//====================================================
	//ステージ1
	//====================================================
	Stage1_Loading.Init(L"asset/Stage1.png", 1, 1);//を初期化
	Stage1_Loading.SetPos(0.0f, 0.0f, 0.0f);         //位置を設定
	Stage1_Loading.SetSize(1280.0f, 720.0f, 0.f);     //大きさ設定
	Stage1_Loading.SetAngle(0.0f);//角度を設定	    

	goal.Init(L"asset/house.png", 1, 1);//ゴール
	goal.SetPos(5800.0f, -70.0f, 0.0f);//位置を特定
	goal.SetSize(240.0f, 250.0f, 0.0f);//大きさ設定
	goal.SetAngle(0.0f);//角度設定
	//山
	mounten[1].Init(L"asset/background_stage_1_v03.png", 1, 1);//ゲーム背景
	mounten[1].SetPos(0.0f, 0.0f, 0.0f);//位置を特定
	mounten[1].SetSize(1280.0f, 720.0f, 0.0f);//大きさ設定
	mounten[1].SetAngle(0.0f);//角度設定

	mounten[2].Init(L"asset/background_stage_1_v03.png", 1, 1);//ゲーム背景
	mounten[2].SetPos(1280.0f, 0.0f, 0.0f);//位置を特定
	mounten[2].SetSize(1280.0f, 720.0f, 0.0f);//大きさ設定
	mounten[2].SetAngle(0.0f);//角度設定

	mounten[3].Init(L"asset/background_stage_1_v03.png", 1, 1);//ゲーム背景
	mounten[3].SetPos(2560.0f, 0.0f, 0.0f);//位置を特定
	mounten[3].SetSize(1280.0f, 720.0f, 0.0f);//大きさ設定
	mounten[3].SetAngle(0.0f);//角度設定

	//地面
	ground[1].Init(L"asset/Stage.png", 1, 1);//地面
	ground[1].SetPos(0.0f, -300.0f, 0.0f);//位置を特定
	ground[1].SetSize(1280, 200.0f, 0.0f);//大きさ設定
	ground[1].SetAngle(0.0f);//角度設定

	ground[2].Init(L"asset/Stage.png", 1, 1);//地面
	ground[2].SetPos(1300.0f, -300.0f, 0.0f);//位置を特定
	ground[2].SetSize(700.0f, 200.0f, 0.0f);//大きさ設定
	ground[2].SetAngle(0.0f);//角度設定

	ground[3].Init(L"asset/Stage.png", 1, 1);//地面
	ground[3].SetPos(3100.0f, -300.0f, 0.0f);//位置を特定
	ground[3].SetSize(2500.0f, 200.0f, 0.0f);//大きさ設定
	ground[3].SetAngle(0.0f);//角度設定

	ground[4].Init(L"asset/Stage.png", 1, 1);//地面
	ground[4].SetPos(4500.0f, -450.0f, 0.0f);//位置を特定
	ground[4].SetSize(400.0f, 200.0f, 0.0f);//大きさ設定
	ground[4].SetAngle(0.0f);//角度設定

	ground[5].Init(L"asset/Stage.png", 1, 1);//地面
	ground[5].SetPos(5300.0f, -300.0f, 0.0f);//位置を特定
	ground[5].SetSize(1280.0f, 200.0f, 0.0f);//大きさ設定
	ground[5].SetAngle(0.0f);//角度設定

	//木
	wood[1].Init(L"asset/wood_stage_1.png", 1, 1);//木
	wood[1].SetPos(0.0f, -30.0f, 0.0f);//位置を特定
	wood[1].SetSize(1280.0f, 420.0f, 0.0f);//大きさ設定
	wood[1].SetAngle(0.0f);//角度設定

	wood[2].Init(L"asset/wood_stage_1.png", 1, 1);//木
	wood[2].SetPos(1280.0f, -30.0f, 0.0f);//位置を特定
	wood[2].SetSize(1280.0f, 420.0f, 0.0f);//大きさ設定
	wood[2].SetAngle(0.0f);//角度設定

	wood[3].Init(L"asset/wood_stage_1.png", 1, 1);//木
	wood[3].SetPos(2560.0f, -30.0f, 0.0f);//位置を特定
	wood[3].SetSize(1280.0f, 420.0f, 0.0f);//大きさ設定
	wood[3].SetAngle(0.0f);//角度設定

	tree.Init(L"asset/tree.png", 1, 1);//木
	tree.SetPos(1900.0f, -70.0f, 0.0f);//位置を特定
	tree.SetSize(240.0f, 250.0f, 0.0f);//大きさ設定
	tree.SetAngle(0.0f);//角度設定

	sky.Init(L"asset/sky.png", 1, 1);//ゲーム背景
	sky.SetPos(0.0f, 0.0f, 0.0f);//位置を特定
	sky.SetSize(1280.0f, 720.0f, 0.0f);//大きさ設定
	sky.SetAngle(0.0f);//角度設定

	star.Init(L"asset/star.png", 1, 1);//星
	star.SetPos(0.0f, 0.0f, 0.0f);//位置を特定
	star.SetSize(1280.0f, 720.0f, 0.0f);//大きさ設定
	star.SetAngle(0.0f);//角度設定

	//回収いわ
	rock[1].Init(L"asset/iwa.png", 1, 1);//いわ
	rock[1].SetPos(-250.0f, -175.0f, 0.0f);//位置を特定
	rock[1].SetSize(70.0f, 70.0f, 0.0f);//大きさ設定
	rock[1].SetAngle(0.0f);//角度設定

	rock[2].Init(L"asset/iwa.png", 1, 1);//いわ
	rock[2].SetPos(300.0f, -175.0f, 0.0f);//位置を特定
	rock[2].SetSize(70.0f, 70.0f, 0.0f);//大きさ設定
	rock[2].SetAngle(0.0f);//角度設定

	rock[3].Init(L"asset/iwa.png", 1, 1);//いわあ
	rock[3].SetPos(1100.0f, -175.0f, 0.0f);////位置を特定
	rock[3].SetSize(70.0f, 70.0f, 0.0f);//大きさ設定
	rock[3].SetAngle(0.0f);//角度設定

	rock[4].Init(L"asset/iwa.png", 1, 1);//いわあ
	rock[4].SetPos(5000.0f, -175.0f, 0.0f);////位置を特定
	rock[4].SetSize(70.0f, 70.0f, 0.0f);//大きさ設定
	rock[4].SetAngle(0.0f);//角度設定

	rock[5].Init(L"asset/iwa.png", 1, 1);//いわあ
	rock[5].SetPos(2300.0f, -175.0f, 0.0f);////位置を特定
	rock[5].SetSize(70.0f, 70.0f, 0.0f);//大きさ設定
	rock[5].SetAngle(0.0f);//角度設定

	rock[6].Init(L"asset/iwa.png", 1, 1);//いわあ
	rock[6].SetPos(4400.0f, -300.0f, 0.0f);////位置を特定
	rock[6].SetSize(70.0f, 70.0f, 0.0f);//大きさ設定
	rock[6].SetAngle(0.0f);//角度設定

	//kaidan
	stairs[1].Init(L"asset/block.png", 1, 1);//いわ
	stairs[1].SetPos(540.0f, -165.0f, 0.0f);//位置を特定
	stairs[1].SetSize(200.0f, 70.0f, 0.0f);//大きさ設定
	stairs[1].SetAngle(0.0f);//角度設定

	stairs[2].Init(L"asset/block.png", 1, 1);//いわ
	stairs[2].SetPos(565.0f, -95.0f, 0.0f);//位置を特定
	stairs[2].SetSize(150.0f, 70.0f, 0.0f);//大きさ設定
	stairs[2].SetAngle(0.0f);//角度設定

	stairs[3].Init(L"asset/block.png", 1, 1);//いわあ
	stairs[3].SetPos(600.0f, -25.0f, 0.0f);////位置を特定
	stairs[3].SetSize(75.0f, 70.0f, 0.0f);//大きさ設定
	stairs[3].SetAngle(0.0f);//角度設定

	stairs[4].Init(L"asset/stairs.png", 1, 1);//いわあ
	stairs[4].SetPos(2800.0f, 80.0f, 0.0f);////位置を特定
	stairs[4].SetSize(300.0f, 70.0f, 0.0f);//大きさ設定
	stairs[4].SetAngle(0.0f);//角度設定

	//プレゼント
	present[1].Init(L"asset/present.png", 1, 1);//いわあ
	present[1].SetPos(800.0f, -25.0f, 0.0f);////位置を特定
	present[1].SetSize(75.0f, 70.0f, 0.0f);//大きさ設定
	present[1].SetAngle(0.0f);//角度設定

	present[2].Init(L"asset/present.png", 1, 1);//いわあ
	present[2].SetPos(2800.0f, 160.0f, 0.0f);////位置を特定
	present[2].SetSize(75.0f, 70.0f, 0.0f);//大きさ設定
	present[2].SetAngle(0.0f);//角度設定

	present[3].Init(L"asset/present.png", 1, 1);//いわあ
	present[3].SetPos(4500.0f, -300.0f, 0.0f);////位置を特定
	present[3].SetSize(75.0f, 70.0f, 0.0f);//大きさ設定
	present[3].SetAngle(0.0f);//角度設定

	//雪玉
	snowball[1].Init(L"asset/yukidama.png", 1, 1);//雪
	snowball[1].SetPos(1500.0f, -175.0f, 0.0f);////位置を特定
	snowball[1].SetSize(70.0f, 70.0f, 0.0f);//大きさ設定
	snowball[1].SetAngle(0.0f);//角度設定

	snowball[2].Init(L"asset/yukidama.png", 1, 1);//雪
	snowball[2].SetPos(2900.0f, -175.0f, 0.0f);////位置を特定
	snowball[2].SetSize(70.0f, 70.0f, 0.0f);//大きさ設定
	snowball[2].SetAngle(0.0f);//角度設定

	snowball[3].Init(L"asset/yukidama.png", 1, 1);//雪
	snowball[3].SetPos(4000.0f, -175.0f, 0.0f);////位置を特定
	snowball[3].SetSize(70.0f, 70.0f, 0.0f);//大きさ設定
	snowball[3].SetAngle(0.0f);//角度設定

	//大きいプレゼント
	BigPresent[1].Init(L"asset/boxv2.png", 1, 1);//いわあ
	BigPresent[1].SetPos(5400.0f, -25.0f, 0.0f);////位置を特定
	BigPresent[1].SetSize(105.0f, 100.0f, 0.0f);//大きさ設定
	BigPresent[1].SetAngle(0.0f);//角度設定



	//====================================================
	//ステージ2
	//====================================================

		//地面
	Ground_Stge2[1].Init(L"asset/Stage.png", 1, 1);//地面
	Ground_Stge2[1].SetPos(0.0f, -300.0f, 0.0f);//位置を特定
	Ground_Stge2[1].SetSize(1280, 200.0f, 0.0f);//大きさ設定
	Ground_Stge2[1].SetAngle(0.0f);//角度設定

	Ground_Stge2[2].Init(L"asset/Stage.png", 1, 1);//地面
	Ground_Stge2[2].SetPos(2000.0f, -300.0f, 0.0f);//位置を特定
	Ground_Stge2[2].SetSize(2350.0f, 200.0f, 0.0f);//大きさ設定
	Ground_Stge2[2].SetAngle(0.0f);//角度設定

	Ground_Stge2[3].Init(L"asset/Stage.png", 1, 1);//地面
	Ground_Stge2[3].SetPos(3300.0f, -420.0f, 0.0f);//位置を特定
	Ground_Stge2[3].SetSize(250.0f, 200.0f, 0.0f);//大きさ設定
	Ground_Stge2[3].SetAngle(0.0f);//角度設定

	Ground_Stge2[4].Init(L"asset/Stage.png", 1, 1);//地面
	Ground_Stge2[4].SetPos(3800.0f, -300.0f, 0.0f);//位置を特定
	Ground_Stge2[4].SetSize(800, 200.0f, 0.0f);//大きさ設定
	Ground_Stge2[4].SetAngle(0.0f);//角度設定

	Ground_Stge2[5].Init(L"asset/Stage.png", 1, 1);//地面
	Ground_Stge2[5].SetPos(4450.0f, -420.0f, 0.0f);//位置を特定
	Ground_Stge2[5].SetSize(500, 200.0f, 0.0f);//大きさ設定
	Ground_Stge2[5].SetAngle(0.0f);//角度設定

	Ground_Stge2[6].Init(L"asset/Stage.png", 1, 1);//地面
	Ground_Stge2[6].SetPos(5300.0f, -300.0f, 0.0f);//位置を特定
	Ground_Stge2[6].SetSize(1200.0f, 200.0f, 0.0f);//大きさ設定
	Ground_Stge2[6].SetAngle(0.0f);//角度設定

	Ground_Stge2[7].Init(L"asset/Stage.png", 1, 1);//地面
	Ground_Stge2[7].SetPos(7400.0f, -300.0f, 0.0f);//位置を特定
	Ground_Stge2[7].SetSize(1300.0f, 200.0f, 0.0f);//大きさ設定
	Ground_Stge2[7].SetAngle(0.0f);//角度設定

	//ブロック
	Block_Stge2[1].Init(L"asset/stairs.png", 1, 1);//ブロック
	Block_Stge2[1].SetPos(2000.0f, 200.0f, 0.0f);//位置を特定
	Block_Stge2[1].SetSize(450, 50.0f, 0.0f);//大きさ設定
	Block_Stge2[1].SetAngle(0.0f);//角度設定

	//つらら
	Icicles_Stge2[1].Init(L"asset/turara.png", 1, 1);//つらら
	Icicles_Stge2[1].SetPos(1800.0f, 100.0f, 0.0f);//位置を特定
	Icicles_Stge2[1].SetSize(150, 200.0f, 0.0f);//大きさ設定
	Icicles_Stge2[1].SetAngle(0.0f);//角度設定

	Icicles_Stge2[2].Init(L"asset/turara.png", 1, 1);//つらら
	Icicles_Stge2[2].SetPos(2000.0f, 100.0f, 0.0f);//位置を特定
	Icicles_Stge2[2].SetSize(150, 200.0f, 0.0f);//大きさ設定
	Icicles_Stge2[2].SetAngle(0.0f);//角度設定

	Icicles_Stge2[3].Init(L"asset/turara.png", 1, 1);//つらら
	Icicles_Stge2[3].SetPos(2200.0f, 100.0f, 0.0f);//位置を特定
	Icicles_Stge2[3].SetSize(150, 200.0f, 0.0f);//大きさ設定
	Icicles_Stge2[3].SetAngle(0.0f);//角度設定

	//木
	Tree_Stge2[1].Init(L"asset/tree3.png", 1, 1);//木
	Tree_Stge2[1].SetPos(900.0f, -70.0f, 0.0f);//位置を特定
	Tree_Stge2[1].SetSize(240.0f, 250.0f, 0.0f);//大きさ設定
	Tree_Stge2[1].SetAngle(0.0f);//角度設定

	//kaidan
	Stairs_Stge2[1].Init(L"asset/block2.png", 1, 1);//いわ
	Stairs_Stge2[1].SetPos(5720.0f, -170.0f, 0.0f);//位置を特定
	Stairs_Stge2[1].SetSize(370.0f, 65.0f, 0.0f);//大きさ設定
	Stairs_Stge2[1].SetAngle(0.0f);//角度設定

	Stairs_Stge2[2].Init(L"asset/block2.png", 1, 1);//いわ
	Stairs_Stge2[2].SetPos(5755.0f, -105.0f, 0.0f);//位置を特定
	Stairs_Stge2[2].SetSize(300.0f, 65.0f, 0.0f);//大きさ設定
	Stairs_Stge2[2].SetAngle(0.0f);//角度設定

	Stairs_Stge2[3].Init(L"asset/block2.png", 1, 1);//いわあ
	Stairs_Stge2[3].SetPos(5790.0f, -40.0f, 0.0f);////位置を特定
	Stairs_Stge2[3].SetSize(230.0f, 65.0f, 0.0f);//大きさ設定
	Stairs_Stge2[3].SetAngle(0.0f);//角度設定

	Stairs_Stge2[4].Init(L"asset/block2.png", 1, 1);//いわ
	Stairs_Stge2[4].SetPos(5825.0f, 25.0f, 0.0f);//位置を特定
	Stairs_Stge2[4].SetSize(160.0f, 65.0f, 0.0f);//大きさ設定
	Stairs_Stge2[4].SetAngle(0.0f);//角度設定

	Stairs_Stge2[5].Init(L"asset/block2.png", 1, 1);//いわ
	Stairs_Stge2[5].SetPos(5860.0f, 90.0f, 0.0f);//位置を特定
	Stairs_Stge2[5].SetSize(90.0f, 65.0f, 0.0f);//大きさ設定
	Stairs_Stge2[5].SetAngle(0.0f);//角度設定



	//回収できる岩
	Collectrock_Stage2[1].Init(L"asset/iwa.png", 1, 1);//プレゼント
	Collectrock_Stage2[1].SetPos(-275.0f, -175.0f, 0.0f);//位置を特定
	Collectrock_Stage2[1].SetSize(75.0f, 70.0f, 0.0f);//大きさ設定
	Collectrock_Stage2[1].SetAngle(0.0f);//角度設定

	Collectrock_Stage2[2].Init(L"asset/iwa.png", 1, 1);//プレゼント
	Collectrock_Stage2[2].SetPos(5000.0f, -175.0f, 0.0f);//位置を特定
	Collectrock_Stage2[2].SetSize(75.0f, 70.0f, 0.0f);//大きさ設定
	Collectrock_Stage2[2].SetAngle(0.0f);//角度設定

	Collectrock_Stage2[3].Init(L"asset/iwa.png", 1, 1);//プレゼント
	Collectrock_Stage2[3].SetPos(1400.0f, -175.0f, 0.0f);//位置を特定
	Collectrock_Stage2[3].SetSize(75.0f, 70.0f, 0.0f);//大きさ設定
	Collectrock_Stage2[3].SetAngle(0.0f);//角度設定

	Collectrock_Stage2[4].Init(L"asset/iwa.png", 1, 1);//プレゼント
	Collectrock_Stage2[4].SetPos(2800.0f, -175.0f, 0.0f);//位置を特定
	Collectrock_Stage2[4].SetSize(75.0f, 70.0f, 0.0f);//大きさ設定
	Collectrock_Stage2[4].SetAngle(0.0f);//角度設定

	Collectrock_Stage2[5].Init(L"asset/iwa.png", 1, 1);//プレゼント
	Collectrock_Stage2[5].SetPos(4000.0f, -175.0f, 0.0f);//位置を特定
	Collectrock_Stage2[5].SetSize(75.0f, 70.0f, 0.0f);//大きさ設定
	Collectrock_Stage2[5].SetAngle(0.0f);//角度設定

	Collectrock_Stage2[6].Init(L"asset/iwa.png", 1, 1);//プレゼント
	Collectrock_Stage2[6].SetPos(7500.0f, -175.0f, 0.0f);//位置を特定
	Collectrock_Stage2[6].SetSize(75.0f, 70.0f, 0.0f);//大きさ設定
	Collectrock_Stage2[6].SetAngle(0.0f);//角度設定

	//回収できる雪玉
	Snowball_Stage2[1].Init(L"asset/yukidama.png", 1, 1);//プレゼント
	Snowball_Stage2[1].SetPos(3100.0f, -175.0f, 0.0f);//位置を特定
	Snowball_Stage2[1].SetSize(75.0f, 70.0f, 0.0f);//大きさ設定
	Snowball_Stage2[1].SetAngle(0.0f);//角度設定

	Snowball_Stage2[2].Init(L"asset/yukidama.png", 1, 1);//プレゼント
	Snowball_Stage2[2].SetPos(5500.0f, -175.0f, 0.0f);//位置を特定
	Snowball_Stage2[2].SetSize(75.0f, 70.0f, 0.0f);//大きさ設定
	Snowball_Stage2[2].SetAngle(0.0f);//角度設定

	Snowball_Stage2[3].Init(L"asset/yukidama.png", 1, 1);//プレゼント
	Snowball_Stage2[3].SetPos(7000.0f, -175.0f, 0.0f);//位置を特定
	Snowball_Stage2[3].SetSize(75.0f, 70.0f, 0.0f);//大きさ設定
	Snowball_Stage2[3].SetAngle(0.0f);//角度設定


	//プレゼント
	Present_Stage2[1].Init(L"asset/present.png", 1, 1);//プレゼント
	Present_Stage2[1].SetPos(3300.0f, -265.0f, 0.0f);////位置を特定
	Present_Stage2[1].SetSize(75.0f, 70.0f, 0.0f);//大きさ設定
	Present_Stage2[1].SetAngle(0.0f);//角度設定

	Present_Stage2[2].Init(L"asset/present.png", 1, 1);//プレゼント
	Present_Stage2[2].SetPos(6300.0f, 100.0f, 0.0f);////位置を特定
	Present_Stage2[2].SetSize(75.0f, 70.0f, 0.0f);//大きさ設定
	Present_Stage2[2].SetAngle(0.0f);//角度設定

	Present_Stage2[3].Init(L"asset/present.png", 1, 1);//プレゼント
	Present_Stage2[3].SetPos(2000.0f, 280.0f, 0.0f);////位置を特定
	Present_Stage2[3].SetSize(75.0f, 70.0f, 0.0f);//大きさ設定
	Present_Stage2[3].SetAngle(0.0f);//角度設定

	//プレゼント大
	BigPresent_Stage2[1].Init(L"asset/boxv2.png", 1, 1);//プレゼント
	BigPresent_Stage2[1].SetPos(4450.0f, -250.0f, 0.0f);////位置を特定
	BigPresent_Stage2[1].SetSize(75.0f, 70.0f, 0.0f);//大きさ設定
	BigPresent_Stage2[1].SetAngle(0.0f);//角度設定

	//壊せる岩
	Breakrock_Stge2[1].Init(L"asset/iwa_yuki.png", 1, 1);//プレゼント
	Breakrock_Stge2[1].SetPos(4450.0f, -250.0f, 0.0f);////位置を特定
	Breakrock_Stge2[1].SetSize(350.0f, 300.0f, 0.0f);//大きさ設定
	Breakrock_Stge2[1].SetAngle(0.0f);//角度設定

	//====================================================
	//リザルト
	//====================================================
	Result.Init(L"asset/Result_v2.png", 1, 1);//を初期化
	Result.SetPos(0.0f, 0.0f, 0.0f);         //位置を設定
	Result.SetSize(1280.0f, 720.0f, 0.f);     //大きさ設定
	Result.SetAngle(0.0f);//角度を設定	    
	
	ResultStar[1].Init(L"asset/ResultStar.png", 1, 1);//を初期化
	ResultStar[1].SetPos(-180.0f, 100.0f, 0.0f);         //位置を設定
	ResultStar[1].SetSize(100.0f, 100.0f, 0.f);     //大きさ設定
	ResultStar[1].SetAngle(0.0f);//角度を設定

	ResultStar[2].Init(L"asset/ResultStar.png", 1, 1);//を初期化
	ResultStar[2].SetPos(-80.0f, 100.0f, 0.0f);         //位置を設定
	ResultStar[2].SetSize(100.0f, 100.0f, 0.f);     //大きさ設定
	ResultStar[2].SetAngle(0.0f);//角度を設定

	ResultStar[3].Init(L"asset/ResultStar.png", 1, 1);//を初期化
	ResultStar[3].SetPos(20.0f, 100.0f, 0.0f);         //位置を設定
	ResultStar[3].SetSize(100.0f, 100.0f, 0.f);     //大きさ設定
	ResultStar[3].SetAngle(0.0f);//角度を設定

	ResultStar[4].Init(L"asset/ResultStar.png", 1, 1);//を初期化
	ResultStar[4].SetPos(120.0f, 100.0f, 0.0f);         //位置を設定
	ResultStar[4].SetSize(100.0f, 100.0f, 0.f);     //大きさ設定
	ResultStar[4].SetAngle(0.0f);//角度を設定

	GrayStar[1].Init(L"asset/ResultStar_Null.png", 1, 1);//を初期化
	GrayStar[1].SetPos(-180.0f, 100.0f, 0.0f);         //位置を設定
	GrayStar[1].SetSize(100.0f, 100.0f, 0.f);     //大きさ設定
	GrayStar[1].SetAngle(0.0f);//角度を設定	  

	GrayStar[2].Init(L"asset/ResultStar_Null.png", 1, 1);//を初期化
	GrayStar[2].SetPos(-80.0f, 100.0f, 0.0f);         //位置を設定
	GrayStar[2].SetSize(100.0f, 100.0f, 0.f);     //大きさ設定
	GrayStar[2].SetAngle(0.0f);//角度を設定	  

	GrayStar[3].Init(L"asset/ResultStar_Null.png", 1, 1);//を初期化
	GrayStar[3].SetPos(20.0f, 100.0f, 0.0f);         //位置を設定
	GrayStar[3].SetSize(100.0f, 100.0f, 0.f);     //大きさ設定
	GrayStar[3].SetAngle(0.0f);//角度を設定	  

	GrayStar[4].Init(L"asset/ResultStar_Null.png", 1, 1);//を初期化
	GrayStar[4].SetPos(120.0f, 100.0f, 0.0f);         //位置を設定
	GrayStar[4].SetSize(100.0f, 100.0f, 0.f);     //大きさ設定
	GrayStar[4].SetAngle(0.0f);//角度を設定	  

	Number[1].Init(L"asset/Nunber_Result.png", 11, 1);//を初期化
	Number[1].SetPos(150.0f, 10.0f, 0.0f);         //位置を設定
	Number[1].SetSize(70.0f, 70.0f, 0.f);     //大きさ設定
	Number[1].SetAngle(0.0f);//角度を設定	
	//====================================================
	//UI
	//====================================================
	Time.Init(L"asset/Time_v2.png", 1, 1);//を初期化
	Time.SetPos(0.0f, 300.0f, 0.0f);         //位置を設定
	Time.SetSize(250.0f, 150.0f, 0.f);     //大きさ設定
	Time.SetAngle(0.0f);//角度を設定	

	Number_UI[1].Init(L"asset/Number_v2.png", 10, 1);//スコアを初期化
	Number_UI[1].SetPos(-300.0f, -300.0f, 0.0f);         //位置を設定
	Number_UI[1].SetSize(40.0f, 40.0f, 0.f);     //大きさ設定
	Number_UI[1].SetAngle(0.0f);//角度を設定

	Number_UI[2].Init(L"asset/Number_v2.png", 10, 1);//時間を初期化
	Number_UI[2].SetPos(50.0f, 300.0f, 0.0f);         //位置を設定
	Number_UI[2].SetSize(40.0f, 40.0f, 0.f);     //大きさ設定
	Number_UI[2].SetAngle(0.0f);//角度を設定

	ScoreCounter.Init(L"asset/ScoreCounter_v2.png", 1, 1);//を初期化
	ScoreCounter.SetPos(-550.0f, -300.0f, 0.0f);         //位置を設定
	ScoreCounter.SetSize(80.0f, 80.0f, 0.f);     //大きさ設定
	ScoreCounter.SetAngle(0.0f);//角度を設定	

	ItemStock.Init(L"asset/ItemStock.png", 1, 1);//を初期化
	ItemStock.SetPos(-500.0f, 280.0f, 0.0f);         //位置を設定
	ItemStock.SetSize(230.0f, 130.0f, 0.f);     //大きさ設定
	ItemStock.SetAngle(0.0f);//角度を設定	
	ItemStock.SetColor(1.0f, 1.0f, 1.0f, 1.0f);

	//ゲームに戻る
	Returntogame.Init(L"asset/Returntogame.png", 1, 1);//いわあ
	Returntogame.SetPos(5400.0f, -25.0f, 0.0f);////位置を特定
	Returntogame.SetSize(250.0f, 250.0f, 0.0f);//大きさ設定
	Returntogame.SetAngle(0.0f);//角度設定

	//====================================================
	//投げ物
	//====================================================
	
	//いわ1
	use_rock[0].Init(L"asset/iwa.png", 1, 1);//いわ
	use_rock[0].SetPos(-2500.0f, -175.0f, 0.0f);//位置を特定
	use_rock[0].SetSize(70.0f, 70.0f, 0.0f);//大きさ設定
	use_rock[0].SetAngle(0.0f);//角度設定

	//いわ2
	use_rock[1].Init(L"asset/iwa.png", 1, 1);//いわ
	use_rock[1].SetPos(-2500.0f, -175.0f, 0.0f);//位置を特定
	use_rock[1].SetSize(70.0f, 70.0f, 0.0f);//大きさ設定
	use_rock[1].SetAngle(0.0f);//角度設定

	//いわ3
	use_rock[2].Init(L"asset/iwa.png", 1, 1);//いわ
	use_rock[2].SetPos(-2500.0f, -175.0f, 0.0f);//位置を特定
	use_rock[2].SetSize(70.0f, 70.0f, 0.0f);//大きさ設定
	use_rock[2].SetAngle(0.0f);//角度設定

	//雪玉1
	use_snowball[0].Init(L"asset/yukidama.png", 1, 1);//雪
	use_snowball[0].SetPos(-2500.0f, -175.0f, 0.0f);////位置を特定
	use_snowball[0].SetSize(70.0f, 70.0f, 0.0f);//大きさ設定
	use_snowball[0].SetAngle(0.0f);//角度設定

	//雪玉2
	use_snowball[1].Init(L"asset/yukidama.png", 1, 1);//雪
	use_snowball[1].SetPos(-2500.0f, -175.0f, 0.0f);////位置を特定
	use_snowball[1].SetSize(70.0f, 70.0f, 0.0f);//大きさ設定
	use_snowball[1].SetAngle(0.0f);//角度設定

	//雪玉3
	use_snowball[2].Init(L"asset/yukidama.png", 1, 1);//雪
	use_snowball[2].SetPos(-2500.0f, -175.0f, 0.0f);////位置を特定
	use_snowball[2].SetSize(70.0f, 70.0f, 0.0f);//大きさ設定
	use_snowball[2].SetAngle(0.0f);//角度設定

	//====================================================
	//ゲームオーバー
	//====================================================

	Gameover.Init(L"asset/MorningFilter_v3.png", 1, 1);//を初期化
	Gameover.SetPos(0.0f, 0.0f, 0.0f);         //位置を設定
	Gameover.SetSize(1280.0f, 720.0f, 0.f);     //大きさ設定
	Gameover.SetAngle(0.0f);//角度を設定
	Gameover.SetColor(0.8f, 0.8f, 0.8f, 0.8f); //色を設定

	GoodMorning.Init(L"asset/Gameover.png", 1, 1);//を初期化
	GoodMorning.SetPos(0.0f, 190.0f, 0.0f);         //位置を設定
	GoodMorning.SetSize(650.0f, 400.0f, 0.f);     //大きさ設定
	GoodMorning.SetAngle(0.0f);//角度を設定

	Retry.Init(L"asset/Retry.png", 1, 1);//を初期化
	Retry.SetPos(0.0f, -100.0f, 0.0f);         //位置を設定
	Retry.SetSize(250.0f, 150.0f, 0.f);     //大きさ設定
	Retry.SetAngle(0.0f);//角度を設定

	TitleBack.Init(L"asset/TitleBack.png", 1, 1);//を初期化
	TitleBack.SetPos(0.0f, -200.0f, 0.0f);         //位置を設定
	TitleBack.SetSize(250.0f, 150.0f, 0.f);     //大きさ設定
	TitleBack.SetAngle(0.0f);//角度を設定

	Cursor.Init(L"asset/Cursor.png", 1, 1);//を初期化
	Cursor.SetPos(-150.0f, -100.0f, 0.0f);         //位置を設定
	Cursor.SetSize(100.0f, 100.0f, 0.f);     //大きさ設定
	Cursor.SetAngle(0.0f);//角度を設定

	pause.SetPos(100.0f, 0.0f, 0.0f);//位置を特定
	pause.SetSize(1280.0f, 720.0f, 0.0f);//大きさ設定
	gameoverFg = false;//ポーズフラグ初期化

	rule.Init(L"asset/Setsumei.png", 1, 1);//を初期化
	rule.SetPos(-150.0f, 20.0f, 0.0f);         //位置を設定
	rule.SetSize(1000.0f, 600.0f, 0.f);     //大きさ設定
	rule.SetAngle(0.0f);//角度を設定
	
	//====================================================
	//てき
	//====================================================

	snowman[1].Init(L"asset/Snowman_Move_v3.png", 4, 2);//雪だるまを初期化
	snowman[1].SetPos(30.0f, -160.0f, 0.0f);		//位置を設定
	snowman[1].SetSize(180.0f, 90.0f, 0.f);	//大きさを設定
	snowman[1].SetAngle(0.0f);             		//角度を設定
	snowman[1].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //色を設定

	snowman[2].Init(L"asset/Snowman_Move_v3.png", 4, 2);//雪だるまを初期化
	snowman[2].SetPos(1400.0f, -160.0f, 0.0f);		//位置を設定
	snowman[2].SetSize(180.0f, 90.0f, 0.f);	//大きさを設定
	snowman[2].SetAngle(0.0f);             		//角度を設定
	snowman[2].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //色を設定

	snowman[3].Init(L"asset/Snowman_Move_v3.png", 4, 2);//ゆきを初期化
	snowman[3].SetPos(2000.0f, -160.0f, 0.0f);		//位置を設定
	snowman[3].SetSize(180.0f, 90.0f, 0.f);	//大きさを設定
	snowman[3].SetAngle(0.0f);             		//角度を設定
	snowman[3].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //色を設定


	star_monster.Init(L"asset/Star_Move_v3.png", 6, 2);//ほしを初期化
	star_monster.SetPos(3600.0f, -150.0f, 0.0f);		//位置を設定
	star_monster.SetSize(200.0f, 110.0f, 0.f);	//大きさを設定
	star_monster.SetAngle(0.0f);             		//角度を設定
	star_monster.SetColor(1.0f, 1.0f, 1.0f, 1.0f); //色を設定

	tonakai.Init(L"asset/Tonakai_Move_v3.png", 4, 2);//となかいを初期化
	tonakai.SetPos(4800.0f, -140.0f, 0.0f);		//位置を設定
	tonakai.SetSize(220.0f, 130.0f, 0.f);	//大きさを設定
	tonakai.SetAngle(0.0f);             		//角度を設定
	tonakai.SetColor(1.0f, 1.0f, 1.0f, 1.0f); //色を設定

	//しょきか
	changescene = TITLE;//シーン初期化
	framcount = 0;
	framcount2 = 0;
	score = 0;
	presentcount = 0;
	time = 150;
	cleartime = 0;
	item = new Item(1);
	select=1;
}

void Game::Update(void) {
	input.Update();

	Collision collision; // 宣言
	collision.canMoveRight = true; // フラグを初期化
	collision.canMoveLeft = true; // フラグを初期化

	//Item* item;


	//値更新する処理の後に入力処理を記述すること by岡本

	switch (changescene)
	{
	case TITLE:
	{
		//キー入力で本編
		if (input.GetKeyTrigger(VK_RETURN)||input.GetButtonPress(XINPUT_B))

		{
			changescene = STAGESELECT;
			//changescene = GAMEOVER;
			
		}
	}
	break;
	case STAGESELECT:
	{
		DirectX::XMFLOAT3 pos = SantaCursor.GetPos();


		if (pos.x == -430) { select = 1; }//ステージ１
		if (pos.x == 0)    { select = 2; }//ステージ２
		if (pos.x == 430)  { select = 3; }//ボス

		if (select !=3&&input.GetKeyTrigger(VK_D) || select != 3 && input.GetLeftAnalogStick().x >= 0.5&& Select_MoverightFg == false && Select_MoveleftFg == false)
		{
			Select_MoverightFg = true;
			//がぞうをみぎ向きに変更
			SantaCursor.numU = 0;
			SantaCursor.numV = 0;
			StopCheck = false;
		}
		if (select != 1&&input.GetKeyTrigger(VK_A) || select != 1 && input.GetLeftAnalogStick().x <= -0.5 && Select_MoveleftFg == false && Select_MoverightFg == false)
		{
			Select_MoveleftFg = true;
			//がぞうを左向きに変更
			SantaCursor.numU = 0;
			SantaCursor.numV = 3;

			StopCheck = false;
		}

		if (Select_MoverightFg == true) 
		{
			if(select!=3){ pos.x += 10; }
			framcount++; //フレームカウント
			if (framcount % 5 == 0) //5フレームに一回行われる
			{
				SantaCursor.numU++;
				if (SantaCursor.numU >= 4)
				{
					SantaCursor.numU = 0;
					SantaCursor.numV++;
					if (SantaCursor.numV >= 2)
					{
						SantaCursor.numV = 0;
					}
				}
			}
			if (pos.x == 0){Select_MoverightFg = false; StopCheck = true;}
			if (pos.x == 430) { Select_MoverightFg = false; StopCheck = true;}
		}

		if (Select_MoveleftFg == true)
		{
			if (select != 1) { pos.x -= 10; }
			framcount++; //フレームカウント
			if (framcount % 5 == 0) //5フレームに一回行われる
			{
				SantaCursor.numU++;
				if (SantaCursor.numU >= 4)
				{
					SantaCursor.numU = 0;
					SantaCursor.numV++;
					if (SantaCursor.numV >= 4)
					{
						SantaCursor.numV = 2;
					}
				}
			}
			if (pos.x == 0) { Select_MoveleftFg = false; StopCheck = true;}
			if (pos.x == -430) { Select_MoveleftFg = false; StopCheck = true;}

		}

		//キーボード入力
		
		//キー入力で本編
		if (input.GetKeyTrigger(VK_RETURN) &&select == 1&&StopCheck)
		{
			changescene = STAGE1_LOADING;
		}
		//ステージ２へ	
		if (input.GetKeyTrigger(VK_RETURN) && select ==2 && StopCheck)
		{
			changescene = STAGE_2;
		}
		//ボスへ	
		if (input.GetKeyTrigger(VK_RETURN) && select == 3 && StopCheck)
		{
			changescene = BOSS;
		}

		//コントローラー入力
		if (input.GetButtonTrigger(XINPUT_B) && select == 1 && StopCheck)
		{
			changescene = STAGE1_LOADING;
		}
		//ステージ２へ	
		if (input.GetButtonTrigger(XINPUT_B) && select == 2 && StopCheck)
		{
			changescene = STAGE_2;
		}
		//ボスへ	
		if (input.GetButtonTrigger(XINPUT_B) && select == 3 && StopCheck)
		{
			changescene = BOSS;
		}


		SantaCursor.SetPos(pos.x,pos.y,pos.z);

	}
	break;
	//ステージ選択した後に出るやつ
	case STAGE1_LOADING:
	{
		framcount++;
		if (framcount % 100 == 0) //２秒弱ぐらいでシーン切り替え
		{
			changescene = STAGE_1;
			sound.Play(SOUND_LABEL_BGM000);//BGMを再生
		}
	}
	break;
	case STAGE_1:
	{

		//サンタ
		DirectX::XMFLOAT3 santa_pos = santa_Nor[0].GetPos();
		DirectX::XMFLOAT3 santa_pos1 = santa_Nor[1].GetPos();
		DirectX::XMFLOAT3 santa_pos2 = santa_Nor[2].GetPos();
		DirectX::XMFLOAT3 santa_pos3 = santa_Nor[3].GetPos();
		DirectX::XMFLOAT3 santa_pos4 = santa_Nor[4].GetPos();
		DirectX::XMFLOAT3 santa_pos5 = santa_Nor[5].GetPos();
		DirectX::XMFLOAT3 santa_pos6 = santa_Nor[6].GetPos();
		DirectX::XMFLOAT3 santa_pos7 = santa_Nor[7].GetPos();
		//ゴール
		DirectX::XMFLOAT3 goal_pos = goal.GetPos();
		//山
		DirectX::XMFLOAT3 mounten_pos1 = mounten[1].GetPos();
		DirectX::XMFLOAT3 mounten_pos2 = mounten[2].GetPos();
		DirectX::XMFLOAT3 mounten_pos3 = mounten[3].GetPos();

		//背景の木
		DirectX::XMFLOAT3 wood_pos1 = wood[1].GetPos();
		DirectX::XMFLOAT3 wood_pos2 = wood[2].GetPos();
		DirectX::XMFLOAT3 wood_pos3 = wood[3].GetPos();

		DirectX::XMFLOAT3 tree_pos = tree.GetPos();


		//地面
		DirectX::XMFLOAT3 ground_pos1 = ground[1].GetPos();
		DirectX::XMFLOAT3 ground_pos2 = ground[2].GetPos();
		DirectX::XMFLOAT3 ground_pos3 = ground[3].GetPos();
		DirectX::XMFLOAT3 ground_pos4 = ground[4].GetPos();
		DirectX::XMFLOAT3 ground_pos5 = ground[5].GetPos();

		//いわ
		DirectX::XMFLOAT3 rock_pos1 = rock[1].GetPos();
		DirectX::XMFLOAT3 rock_pos2 = rock[2].GetPos();
		DirectX::XMFLOAT3 rock_pos3 = rock[3].GetPos();
		DirectX::XMFLOAT3 rock_pos4 = rock[4].GetPos();
		DirectX::XMFLOAT3 rock_pos5 = rock[5].GetPos();
		DirectX::XMFLOAT3 rock_pos6 = rock[6].GetPos();

		//雪玉
		DirectX::XMFLOAT3 snowball_pos1 = snowball[1].GetPos();
		DirectX::XMFLOAT3 snowball_pos2 = snowball[2].GetPos();
		DirectX::XMFLOAT3 snowball_pos3 = snowball[3].GetPos();

		//階段
		DirectX::XMFLOAT3 stairs_pos1 = stairs[1].GetPos();
		DirectX::XMFLOAT3 stairs_pos2 = stairs[2].GetPos();
		DirectX::XMFLOAT3 stairs_pos3 = stairs[3].GetPos();
		DirectX::XMFLOAT3 stairs_pos4 = stairs[4].GetPos();

		//敵
		DirectX::XMFLOAT3 snowman_pos1 = snowman[1].GetPos();          //雪の敵
		DirectX::XMFLOAT3 snowman_pos2 = snowman[2].GetPos();		   //雪の敵
		DirectX::XMFLOAT3 snowman_pos3 = snowman[3].GetPos();		   //雪の敵
		DirectX::XMFLOAT3 star_monster_pos = star_monster.GetPos();	   //星の敵
		DirectX::XMFLOAT3 tonakai_pos = tonakai.GetPos();			   //鹿の敵
		//プレゼント
		DirectX::XMFLOAT3 present_pos1 = present[1].GetPos();
		DirectX::XMFLOAT3 present_pos2 = present[2].GetPos();
		DirectX::XMFLOAT3 present_pos3 = present[3].GetPos();
		//プレゼント大
		DirectX::XMFLOAT3 bigpresent_pos1 = BigPresent[1].GetPos();

		//投げ物　いわ
		DirectX::XMFLOAT3 use_rock_pos1 = use_rock[0].GetPos();
		DirectX::XMFLOAT3 use_rock_pos2 = use_rock[1].GetPos();
		DirectX::XMFLOAT3 use_rock_pos3 = use_rock[2].GetPos();

		//投げ物　雪玉
		DirectX::XMFLOAT3 use_snowball_pos1 = use_snowball[0].GetPos();
		DirectX::XMFLOAT3 use_snowball_pos2 = use_snowball[1].GetPos();
		DirectX::XMFLOAT3 use_snowball_pos3 = use_snowball[2].GetPos();

		DirectX::XMFLOAT3 cursor_pos = Cursor.GetPos();

		//item->GetItem_1();

		// 一旦仮で重力的なものをを追加します　ゴロイ
		//santa_pos.y -= 1;
		if (ResettingFg == true)
		{
			
			ResettingFg = false;
		}
		
		

		// サンタが下に落ちた時に初期位置に戻る処理　ゴロイ
		if (santa_pos.y == -250.0f)
		{
			santa_pos.x = -400.0f;
			santa_pos.y = -175.0f;
		}


		framcount2++;
		if (framcount2 % 10 == 0) //１０フレームに一回行われる
		{
			snowman[1].numU++;
			snowman[2].numU++;
			snowman[3].numU++;
			star_monster.numU++;
			tonakai.numU++;
			if (snowman[1].numU >= 4 || snowman[2].numU >= 4 || snowman[3].numU >= 4 || tonakai.numU >= 4)
			{
				snowman[1].numU = 0;
				snowman[2].numU = 0;
				snowman[3].numU = 0;
				star_monster.numU = 0;
				tonakai.numU = 0;


				tonakai.numU = 0;
			}
			if (star_monster.numU >= 6)
			{
				star_monster.numU = 0;
			}


		}

		
		
		//制限時間
		if (framcount2 % 60 == 0&&pauseFg==false)//1秒に一回行われる
		{
			time--;
		}
		if (time <= 0)//タイムオーバーになったら
		{
			gameoverFg = true;
		}
		if (gameoverFg == true)
		{
			if (cursor_pos.y == -100)
			{
				if (input.GetKeyTrigger(VK_S) ||input.GetLeftAnalogStick().y<-0.5)
				{
					cursor_pos.y = -200;
				}

				if (input.GetKeyTrigger(VK_RETURN)||input.GetButtonPress(XINPUT_B))
				{
					changescene = STAGE1_LOADING;//リトライ
					gameoverFg = false;
					//初期化
					time = 150;
					framcount = 0;
					framcount2 = 0;
					score = 0;
					presentcount = 0;
					time = 150;
					cleartime = 0;
					santa_pos.x = -400;

					mounten_pos1.x = 0;
					mounten_pos2.x = 1280;
					mounten_pos3.x = 2560;

					wood_pos1.x = 0;
					wood_pos2.x = 1280;
					wood_pos3.x = 2560;

					rock_pos1.x = -250;
					rock_pos2.x = 300;
					rock_pos3.x = 1100;
					rock_pos4.x = 1100;
					rock_pos5.x = 2300;
					rock_pos6.x = 4400;

					snowball_pos1.x = 1500;
					snowball_pos2.x = 2900;
					snowball_pos3.x = 4000;

					ground_pos1.x = 0;
					ground_pos2.x = 1300;
					ground_pos3.x = 3100;
					ground_pos4.x = 4500;
					ground_pos5.x = 5300;

					stairs_pos1.x = 540;
					stairs_pos2.x = 565;
					stairs_pos3.x = 600;
					stairs_pos4.x = 2800;

					snowman_pos1.x = 30;
					snowman_pos2.x = 1400;
					snowman_pos3.x = 2700;

					bigpresent_pos1.x = 5400;

					star_monster_pos.x = 4800;
					tonakai_pos.x = 3600;

					present_pos1.x = 800;
					present_pos2.x = 2800;
					present_pos3.x = 4500;

					tree_pos.x = 1900;
					goal_pos.x = 5800;

				}
			}

			if (cursor_pos.y == -200)
			{
				if (input.GetKeyTrigger(VK_W)||input.GetLeftAnalogStick().y > 0.5)
				{
					cursor_pos.y = -100;
				}

				if (input.GetKeyTrigger(VK_RETURN) || input.GetButtonPress(XINPUT_B))
				{
					changescene = TITLE;//タイトル
					gameoverFg = false;
					//初期化
					time = 150;
					framcount = 0;
					framcount2 = 0;
					score = 0;
					presentcount = 0;
					time = 150;
					cleartime = 0;
					santa_pos.x = -400;

					mounten_pos1.x = 0;
					mounten_pos2.x = 1280;
					mounten_pos3.x = 2560;

					wood_pos1.x = 0;
					wood_pos2.x = 1280;
					wood_pos3.x = 2560;

					rock_pos1.x = -250;
					rock_pos2.x = 300;
					rock_pos3.x = 1100;
					rock_pos4.x = 1100;
					rock_pos5.x = 2300;
					rock_pos6.x = 4400;

					snowball_pos1.x = 1500;
					snowball_pos2.x = 2900;
					snowball_pos3.x = 4000;

					ground_pos1.x = 0;
					ground_pos2.x = 1300;
					ground_pos3.x = 3100;
					ground_pos4.x = 4500;
					ground_pos5.x = 5300;

					stairs_pos1.x = 540;
					stairs_pos2.x = 565;
					stairs_pos3.x = 600;
					stairs_pos4.x = 2800;

					snowman_pos1.x = 30;
					snowman_pos2.x = 1400;
					snowman_pos3.x = 2700;

					bigpresent_pos1.x = 5400;

					star_monster_pos.x = 4800;
					tonakai_pos.x = 3600;

					present_pos1.x = 800;
					present_pos2.x = 2800;
					present_pos3.x = 4500;

					tree_pos.x = 1900;
					goal_pos.x = 5800;

				}

			}
		}

		//ポーズ画面

		if (input.GetButtonPress(VK_P)||input.GetButtonPress(XINPUT_START)){pauseFg = true;}
		if (pauseFg == true)
		{
			if (input.GetButtonPress(VK_P) || input.GetButtonPress(XINPUT_START))
			{
				//pauseFg = false;
			}
		}



		//-------敵移動--------//
		//雪だるま（１）
		if (moveFg1 == false && pauseFg == false)
		{
			snowman[1].numV = 0;
			snowman_pos1.x -= 1;
			if (snowman_pos1.x < ground_pos1.x - 240)//左はしに行ったら
			{
				moveFg1 = true;
			}
		}

		if (moveFg1 == true && pauseFg == false)
		{

			snowman[1].numV = 1;
			snowman_pos1.x += 1;
			if (snowman_pos1.x > ground_pos1.x + 240)//右端に行ったら
			{
				moveFg1 = false;
			}
		}

		//雪だるま（2）
		if (moveFg2 == false && pauseFg == false)
		{
			snowman[2].numV = 0;
			snowman_pos2.x -= 1;
			if (snowman_pos2.x < ground_pos2.x - 180)//左はしに行ったら
			{
				moveFg2 = true;
			}
		}

		if (moveFg2 == true && pauseFg == false)
		{
			snowman[2].numV = 1;
			snowman_pos2.x += 1;
			if (snowman_pos2.x > ground_pos2.x + 240)//右端に行ったら
			{
				moveFg2 = false;
			}
		}

		//雪だるま（3）
		if (moveFg3 == false && pauseFg == false)
		{
			snowman[3].numV = 0;
			snowman_pos3.x -= 1;
			if (snowman_pos3.x < ground_pos3.x - 700)//左に行ったら
			{
				moveFg3 = true;
			}
		}

		if (moveFg3 == true && pauseFg == false)
		{
			snowman[3].numV = 1;
			snowman_pos3.x += 1;
			if (snowman_pos3.x > ground_pos3.x - 200)//右端に行ったら
			{
				moveFg3 = false;
			}
		}

		//星の敵（１)

		if (moveFg4 == false && pauseFg == false)
		{
			star_monster.numV = 0;
			star_monster_pos.x -= 2;
			if (star_monster_pos.x < ground_pos3.x - 130)//左に行ったら
			{
				moveFg4 = true;
			}
		}

		if (moveFg4 == true && pauseFg == false)
		{
			star_monster.numV = 1;
			star_monster_pos.x += 2;
			if (star_monster_pos.x > ground_pos3.x + 700)//右端に行ったら
			{
				moveFg4 = false;
			}
		}


		//トナカイの敵
		if (moveFg5 == false && pauseFg == false)
		{
			tonakai.numV = 0;
			tonakai_pos.x -= 2;
			if (tonakai_pos.x < ground_pos5.x - 400)//左に行ったら
			{
				moveFg5 = true;
			}
		}

		if (moveFg5 == true && pauseFg == false)
		{
			tonakai.numV = 1;
			tonakai_pos.x += 2;
			if (tonakai_pos.x > ground_pos5.x + 200)//右端に行ったら
			{
				moveFg5 = false;
			}
		}


		hitcooltime++;
		//敵に当たったら約２秒無敵に
		if (hitcooltime % 120 == 0&&HitFg==true)
		{
			HitFg = false;//
		}

		// 雪だるまとの当たり判定追加 
		for (int i = 0; i < image; i++) 
		{	
			if (collision.enemy_santa(snowman[i], santa_Nor[0], 50.0f, 0.0f)&&HitFg==false && pauseFg == false)
			{
				time -= 5;	
				hitcooltime = 0;
				HitFg = true;
			}
		}
		// 星との当たり判定追加 
		if (collision.enemy_santa(star_monster, santa_Nor[0], 50.0f, 0.0f) && HitFg == false && pauseFg == false)
		{
			time -= 5;
			hitcooltime = 0;
			HitFg = true;
		}
		//トナカイ との当たり判定追加 
		if (collision.enemy_santa(tonakai, santa_Nor[0], 50.0f, 0.0f) && HitFg == false && pauseFg == false)
		{
			time -= 5;
			hitcooltime = 0;
			HitFg = true;
		}
	

		if (collision.item_santa(present[1], santa_Nor[0], 100.0f, 0.0f))

		//プレゼントの当たり判定
		if (collision.item_santa(present[1], santa_Nor[0], 100.0f, 0.0f) && pauseFg == false)

		{
			presentcount += 1;
			score += 500;
			present_pos1.y = 100000;
		}

		if (collision.item_santa(present[2], santa_Nor[0], 100.0f, 0.0f))
		{
			presentcount += 1;
			score += 500;
			present_pos2.y = 100000;
		}

		if (collision.item_santa(present[3], santa_Nor[0], 100.0f, 0.0f))
		{
			presentcount += 1;
			score += 500;
			present_pos3.y = 100000;
		}

		if (collision.item_santa(BigPresent[1], santa_Nor[0], 100.0f, 0.0f))
		{
			presentcount += 1;
			score += 1000;
			bigpresent_pos1.y = 100000;
		}

		
		
		// 地面との当たり判定の追加 ゴロイ
		for (int i = 0; i < image; i++) {
			DirectX::XMFLOAT3 ground_pos = GetGroundPos(i);

			if (collision.ground_santa(ground[i], santa_Nor[0], 50.0f, 0.0f)) {

				//// サンタが地面の上にいる場合
				if (santa_pos.y > ground_pos.y + ground[i].GetSize().y / 2.0f) {
					santa_pos.y = ground_pos.y + ground[i].GetSize().y / 2.0f + santa_Nor[0].GetSize().y / 2.0f;
					/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
				}
				else {
					/*std::cout << "\nSanta is falling." << std::endl;*/
				}

				// サンタが地面の右側にぶつかった場合
				if (santa_pos.x < ground_pos.x && santa_pos.y < ground_pos.y) {

					collision.canMoveRight = false; // 右に移動中なら移動を停止
				}

				// サンタが地面にぶつかった場合
				if (santa_pos.x > ground_pos.x && santa_pos.y < ground_pos.y) {
					collision.canMoveLeft = false; // 左に移動中なら移動を停止
				}
			}
		}

		if (collision.goal_santa(goal, santa_Nor[0], 250.0f, 0.0f))
		{

			// サンタがゴールの右側にぶつかった場合
			if (santa_pos.x < goal_pos.x && santa_pos.y < goal_pos.y)
			{

				changescene = RESULT;
				//初期化
				santa_pos.x = -400;

				mounten_pos1.x = 0;
				mounten_pos2.x = 1280;
				mounten_pos3.x = 2560;

				wood_pos1.x = 0;
				wood_pos2.x = 1280;
				wood_pos3.x = 2560;

				rock_pos1.x = -250;
				rock_pos2.x = 300;
				rock_pos3.x = 1100;
				rock_pos4.x = 1100;
				rock_pos5.x = 2300;
				rock_pos6.x = 4400;

				snowball_pos1.x = 1500;
				snowball_pos2.x = 2900;
				snowball_pos3.x = 4000;

				ground_pos1.x = 0;
				ground_pos2.x = 1300;
				ground_pos3.x = 3100;
				ground_pos4.x = 4500;
				ground_pos5.x = 5300;

				stairs_pos1.x = 540;
				stairs_pos2.x = 565;
				stairs_pos3.x = 600;
				stairs_pos4.x = 2800;

				snowman_pos1.x = 30;
				snowman_pos2.x = 1400;
				snowman_pos3.x = 2700;

				bigpresent_pos1.x = 5400;

				star_monster_pos.x = 4800;
				tonakai_pos.x = 3600;

				present_pos1.x = 800;
				present_pos2.x = 2800;
				present_pos3.x = 4500;

				tree_pos.x = 1900;
				goal_pos.x = 5800;

			}

		}

		// サンタがアイテムに当たった時
		bool itemCollected = false; // アイテムが既に回収されたかどうかのフラグ

		const float rightScreen = 670.0f; // 画面の右端
		const float leftScreen = -670.0f; // 画面の左端


		if (collision.item_santa(rock[1], santa_Nor[0], 100.0f, 0.0f) && rock_visible1 == 0)
		{
			if (input.GetKeyTrigger(VK_S) && !itemCollected || input.GetButtonTrigger(XINPUT_B) && !itemCollected)
			{
				/*itemID = 1;*/
				item->ItemGet(1); // いわを回収
				bugPower=item->GetItemCnt(); // 現在の袋のアイテム個数を代入
				itemCollected = true;

				rock_visible1 = 1;

			}
		}

		if (collision.item_santa(rock[2], santa_Nor[0], 100.0f, 0.0f) && rock_visible2 == 0)
		{
			if (input.GetKeyTrigger(VK_S) && !itemCollected || input.GetButtonTrigger(XINPUT_B) && !itemCollected)
			{
				/*itemID = 1;*/
				item->ItemGet(1); // いわを回収
				bugPower = item->GetItemCnt(); // 現在の袋のアイテム個数を代入
				itemCollected = true;

				rock_visible2 = 1;
			}
		}

		if (collision.item_santa(rock[3], santa_Nor[0], 100.0f, 0.0f) && rock_visible3 == 0)
		{
			if (input.GetKeyTrigger(VK_S) && !itemCollected || input.GetButtonTrigger(XINPUT_B) && !itemCollected)
			{
				/*itemID = 1;*/
				item->ItemGet(1); // いわを回収
				bugPower = item->GetItemCnt(); // 現在の袋のアイテム個数を代入
				itemCollected = true;

				rock_visible3 = 1;
			}
		}

		if (collision.item_santa(rock[4], santa_Nor[0], 100.0f, 0.0f) && rock_visible4 == 0)
		{
			if (input.GetKeyTrigger(VK_S) && !itemCollected || input.GetButtonTrigger(XINPUT_B) && !itemCollected)
			{
				/*itemID = 1;*/
				item->ItemGet(1); // いわを回収
				bugPower = item->GetItemCnt(); // 現在の袋のアイテム個数を代入
				itemCollected = true;

				rock_visible4 = 1;
			}
		}

		if (collision.item_santa(rock[5], santa_Nor[0], 100.0f, 0.0f) && rock_visible5 == 0)
		{
			if (input.GetKeyTrigger(VK_S) && !itemCollected || input.GetButtonTrigger(XINPUT_B) && !itemCollected)
			{
				/*itemID = 1;*/
				item->ItemGet(1); // いわを回収
				bugPower = item->GetItemCnt(); // 現在の袋のアイテム個数を代入
				itemCollected = true;

				rock_visible5 = 1;
			}
		}

		if (collision.item_santa(rock[6], santa_Nor[0], 100.0f, 0.0f) && rock_visible6 == 0)
		{
			if (input.GetKeyTrigger(VK_S) && !itemCollected || input.GetButtonTrigger(XINPUT_B) && !itemCollected)
			{
				/*itemID = 1;*/
				item->ItemGet(1); // いわを回収
				bugPower = item->GetItemCnt(); // 現在の袋のアイテム個数を代入
				itemCollected = true;

				rock_visible6 = 1;
			}
		}

		if (collision.item_santa(snowball[1], santa_Nor[0], 100.0f, 0.0f) && snow_visible1 == 0)
		{
			if (input.GetKeyTrigger(VK_S) && !itemCollected || input.GetButtonTrigger(XINPUT_B) && !itemCollected)
			{
				/*itemID = 1;*/
				item->ItemGet(2); // いわを回収
				bugPower = item->GetItemCnt(); // 現在の袋のアイテム個数を代入
					
				snow_visible1 = 1;
			}
		}

		if (collision.item_santa(snowball[2], santa_Nor[0], 100.0f, 0.0f) && snow_visible1 == 0)
		{
			if (input.GetKeyTrigger(VK_S) && !itemCollected || input.GetButtonTrigger(XINPUT_B) && !itemCollected)
			{
				/*itemID = 1;*/
				item->ItemGet(2); // いわを回収
				bugPower = item->GetItemCnt(); // 現在の袋のアイテム個数を代入
				itemCollected = true;

				snow_visible2 = 1;
			}
		}

		if (collision.item_santa(snowball[3], santa_Nor[0], 100.0f, 0.0f) && snow_visible1 == 0)
		{
			if (input.GetKeyTrigger(VK_S) && !itemCollected|| input.GetButtonTrigger(XINPUT_B) && !itemCollected)
			{
				/*itemID = 1;*/
				item->ItemGet(2); // いわを回収
				bugPower = item->GetItemCnt(); // 現在の袋のアイテム個数を代入
				itemCollected = true;

				snow_visible3 = 1;
			}
		}

		// 画面外に行くと、アイテムが再スポーンする処理
		if (leftScreen > rock_pos1.x || rock_pos1.x > rightScreen) {
			rock_visible1 = 0;
		}
		if (leftScreen > rock_pos2.x || rock_pos2.x > rightScreen) {
			rock_visible2 = 0;
		}
		if (leftScreen > rock_pos3.x || rock_pos3.x > rightScreen) {
			rock_visible3 = 0;
		}
		if (leftScreen > rock_pos4.x || rock_pos4.x > rightScreen) {
			rock_visible4 = 0;
		}
		if (leftScreen > rock_pos5.x || rock_pos5.x > rightScreen) {
			rock_visible5 = 0;
		}
		if (leftScreen > rock_pos6.x || rock_pos6.x > rightScreen) {
			rock_visible6 = 0;
		}
		if (leftScreen > snowball_pos1.x || snowball_pos1.x > rightScreen) {
			snow_visible1 = 0;
		}
		if (leftScreen > snowball_pos2.x || snowball_pos2.x > rightScreen) {
			snow_visible2 = 0;
		}
		if (leftScreen > snowball_pos3.x || snowball_pos3.x > rightScreen) {
			snow_visible3 = 0;
		}


		if (!itemCollected && !changeItem) {// 当たってない場合
			if (input.GetKeyTrigger(VK_S) && pauseFg == false || input.GetButtonTrigger(XINPUT_B) && pauseFg == false)
			{
				if (item->GetItem_3() > 0) {
					changeItem = true;

					if (item->GetItem_3() == 1) {
						use_rock_pos3.x = santa_pos.x;
						use_rock_pos3.y = santa_pos.y;
						
						itemID_3 = 1;
						itemMove3 = true;
					}
					else if (item->GetItem_3() == 2) {
						use_snowball_pos3.x = santa_pos.x;
						use_snowball_pos3.y = santa_pos.y;
						itemID_3 = 2;
						itemMove3 = true;
					}

				}
				else if (item->GetItem_3() < 0) {

					if (item->GetItem_2() > 0) {

						if (item->GetItem_2() == 1) {
							use_rock_pos2.x = santa_pos.x;
							use_rock_pos2.y = santa_pos.y;
							itemID_2 = 1;
							itemMove2 = true;
						}
						else if (item->GetItem_2() == 2) {
							use_snowball_pos2.x = santa_pos.x;
							use_snowball_pos2.y = santa_pos.y;
							itemID_2 = 2;
							itemMove2 = true;
						}

					}
					else if (item->GetItem_2() < 0) {

						if (item->GetItem_1() > 0) {

							if (item->GetItem_1() == 1) {
								use_rock_pos1.x = santa_pos.x;
								use_rock_pos1.y = santa_pos.y;
								itemID_1 = 1;
								itemMove1 = true;
							}
							else if (item->GetItem_1() == 2) {
								use_snowball_pos1.x = santa_pos.x;
								use_snowball_pos1.y = santa_pos.y;
								itemID_1 = 2;
								itemMove1 = true;
							}

						}
					}
				}
				
				
				item->ItemRelease(); // 取り出す
				bugPower=item->GetItemCnt();
			}
		}

		// 投げ物の動き　その① 
		if (itemMove1 == true) {
			if (direction == 0) { // 右向き

				if (itemID_1 == 1) { // 岩

					if (itemMove1_M == true || use_rock_pos1.y >= -100.0f) {
						itemMove1_M = true;
						use_rock_pos1.y -= 3.00f;
						use_rock_pos1.x += 3.00f;
					}
					else if (itemMove1_M == false) {
						use_rock_pos1.y += 3.00f;
						use_rock_pos1.x += 3.00f;
					}
					if (use_rock_pos1.y <= -190.0f && itemMove1_M == true) {
						itemID_1 = 0;
						itemMove1_M = false;
						itemMove1 = false;
					}
				}
				else if (itemID_1 == 2) {
					if (use_snowball_pos1.x >= rightScreen) {
						itemID_1 = 0;
						itemMove1 = false;
					}
					else if (use_snowball_pos1.x <= rightScreen) {
						use_snowball_pos1.x += 20.00f;
					}
				}
			}
			else if (direction == 1) { // 左向き

				if (itemID_1 == 1) { // 岩

					if (itemMove1_M == true || use_rock_pos1.y >= -100.0f) {
						itemMove1_M = true;
						use_rock_pos1.y -= 3.00f;
						use_rock_pos1.x -= 3.00f;
					}
					else if (itemMove1_M == false) {
						use_rock_pos1.y += 3.00f;
						use_rock_pos1.x -= 3.00f;
					}
					if (use_rock_pos1.y <= -190.0f && itemMove1_M == true) {
						itemID_1 = 0;
						itemMove1_M = false;
						itemMove1 = false;
					}
				}
				else if (itemID_1 == 2) {
					if (use_snowball_pos1.x <= leftScreen) {
						itemID_1 = 0;
						itemMove1 = false;
					}
					else if (use_snowball_pos1.x >= leftScreen) {
						use_snowball_pos1.x -= 20.00f;
					}
				}
			}
			
			

		}

		// 投げ物の動き　その②
		if (itemMove2 == true) {
			if (direction == 0) { // 右向き

				if (itemID_2 == 1) { //岩

					if (itemMove2_M == true || use_rock_pos2.y >= -100.0f) {
						itemMove2_M = true;
						use_rock_pos2.y -= 3.00f;
						use_rock_pos2.x += 3.00f;
					}
					else if (itemMove2_M == false) {
						use_rock_pos2.y += 3.00f;
						use_rock_pos2.x += 3.00f;
					}
					if (use_rock_pos2.y <= -190.0f && itemMove2_M == true) {
						itemID_2 = 0;
						itemMove2_M = false;
						itemMove2 = false;
					}
				}
				else if (itemID_2 == 2) {
					if (use_snowball_pos2.x >= rightScreen) {
						itemID_2 = 0;
						itemMove2 = false;
					}
					else if (use_snowball_pos2.x <= rightScreen) {
						use_snowball_pos2.x += 20.00f;
					}
				}
			}
			else if (direction == 1) { // 左向き

				if (itemID_2 == 1) { //岩

					if (itemMove2_M == true || use_rock_pos2.y >= -100.0f) {
						itemMove2_M = true;
						use_rock_pos2.y -= 3.00f;
						use_rock_pos2.x -= 3.00f;
					}
					else if (itemMove2_M == false) {
						use_rock_pos2.y += 3.00f;
						use_rock_pos2.x -= 3.00f;
					}
					if (use_rock_pos2.y <= -190.0f && itemMove2_M == true) {
						itemID_2 = 0;
						itemMove2_M = false;
						itemMove2 = false;
					}
				}
				else if (itemID_2 == 2) {
					if (use_snowball_pos2.x <= leftScreen) {
						itemID_2 = 0;
						itemMove2 = false;
					}
					else if (use_snowball_pos2.x >= leftScreen) {
						use_snowball_pos2.x -= 20.00f;
					}
				}
			}
			

		}

		// 投げ物の動き　その③
		if (itemMove3 == true) {
			
			if (direction == 0) { // 右向き

				if (itemID_3 == 1) { // 岩

					if (itemMove3_M == true || use_rock_pos3.y >= -100.0f) {
						itemMove3_M = true;
						use_rock_pos3.y -= 3.00f;
						use_rock_pos3.x += 3.00f;
					}
					else if (itemMove3_M == false) {
						use_rock_pos3.y += 3.00f;
						use_rock_pos3.x += 3.00f;
					}
					if (use_rock_pos3.y <= -190.0f && itemMove3_M == true) {
						itemID_3 = 0;
						itemMove3_M = false;
						itemMove3 = false;
						changeItem = false;
					}
				}
				else if (itemID_3 == 2) {
					if (use_snowball_pos3.x >= rightScreen) {
						itemID_3 = 0;
						itemMove3 = false;
						changeItem = false;
					}
					else if (use_snowball_pos3.x <= rightScreen) {
						use_snowball_pos3.x += 30.00f;
					}
				}
			}
			else if (direction == 1) { // 左向き

				if (itemID_3 == 1) { // 岩

					if (itemMove3_M == true || use_rock_pos3.y >= -100.0f) {
						itemMove3_M = true;
						use_rock_pos3.y -= 3.00f;
						use_rock_pos3.x -= 3.00f;
					}
					else if (itemMove3_M == false) {
						use_rock_pos3.y += 3.00f;
						use_rock_pos3.x -= 3.00f;
					}
					if (use_rock_pos3.y <= -190.0f && itemMove3_M == true) {
						itemID_3 = 0;
						itemMove3_M = false;
						itemMove3 = false;
						changeItem = false;
					}
				}
				else if (itemID_3 == 2) {
					if (use_snowball_pos3.x <= leftScreen) {
						itemID_3 = 0;
						itemMove3 = false;
						changeItem = false;
					}
					else if (use_snowball_pos3.x >= leftScreen) {
						use_snowball_pos3.x -= 30.00f;
					}
				}
			}
			
			
		}




		//
		// 木との当たり判定の追加　ゴロイ
		if (collision.tree_santa(tree, santa_Nor[0], 200.0f, 0.0f)) {

			//// サンタが木の右側にぶつかった場合
			//if (santa_pos.x < tree_pos.x) {

				//collision.canMoveRight = false; // 右に移動中なら移動を停止


		}
		// サンタが木の左側にぶつかった場合
		if (santa_pos.x > tree_pos.x) {
			//	collision.canMoveRight = false; // 右に移動中なら移動を停止
			//	
			//	
			//}
			//// サンタが木の左側にぶつかった場合
			//if (santa_pos.x > tree_pos.x) {

			//	collision.canMoveLeft = false; // 左に移動中なら移動を停止

			//}
		}

		santa_pos6.x = santa_pos.x;
		santa_pos6.y = santa_pos.y;
		santa_pos7.x = santa_pos.x;
		santa_pos7.y = santa_pos.y;


		// 12/30  サンタの移動アニメーション追加  	畦内
		//移動速度
		if (bugPower == 0) { // 袋が空の時
			
			speed = 7;
		}
		else {
			
			speed = 5;
		}
		

		

		// 固有能力発動！！！！！！！
		if (bugPower > 0 && sp_ani == false&&input.GetKeyPress(VK_Q) || input.GetButtonTrigger(XINPUT_X)) { // 袋が空っぽの時
			sp_ani = true;
		}/*else if()*/

		if (sp_ani == true) {

			santaImage = 7;
			
			if (direction == 0) {

				// 威力弱
				if (bugPower == 1) {
					if (changeRight_SP == true)
					{
						//初期化
						santa_Nor[7].numU = 0;
						santa_Nor[7].numV = 0;
						changeRight_SP = false;//一旦falseにして一回しか処理されないようにする
					}
					framcount3++; //フレームカウント
					if (framcount3 % 4 == 0) //１０フレームに一回行われる
					{
						santa_Nor[7].numU++;
						if (santa_Nor[7].numU >= 5)
						{
							sp_ani = false;
							santaImage = 0;
							santa_Nor[7].numU = 0;

						}
					}
				}
				// 威力中
				else if (bugPower == 2) {
					if (changeRight_SP == true)
					{
						//初期化
						santa_Nor[7].numU = 0;
						santa_Nor[7].numV = 0;
						changeRight_SP = false;//一旦falseにして一回しか処理されないようにする
					}
					framcount3++; //フレームカウント
					if (framcount3 % 7 == 0) //１０フレームに一回行われる
					{
						santa_Nor[7].numU++;
						if (santa_Nor[7].numU >= 5)
						{
							sp_ani = false;
							santaImage = 0;
							santa_Nor[7].numU = 0;

						}
					}
				}
				// 威力強
				else if (bugPower == 3) {
					if (changeRight_SP == true)
					{
						//初期化
						santa_Nor[7].numU = 0;
						santa_Nor[7].numV = 0;
						changeRight_SP = false;//一旦falseにして一回しか処理されないようにする
					}
					framcount3++; //フレームカウント
					if (framcount3 % 10 == 0) //１０フレームに一回行われる
					{
						santa_Nor[7].numU++;
						if (santa_Nor[7].numU >= 5)
						{
							sp_ani = false;
							santaImage = 0;
							santa_Nor[7].numU = 0;

						}
					}
				}
			}
			if (direction == 1) {

				// 威力弱
				if (bugPower == 1) {
					if (changeRight_SP == true)
					{
						//初期化
						santa_Nor[7].numU = 0;
						santa_Nor[7].numV = 1;
						changeRight_SP = false;//一旦falseにして一回しか処理されないようにする
					}
					framcount3++; //フレームカウント
					if (framcount3 % 4 == 0) //１０フレームに一回行われる
					{
						santa_Nor[7].numU++;
						if (santa_Nor[7].numU >= 5)
						{
							sp_ani = false;
							santaImage = 0;
							santa_Nor[7].numU = 0;

						}
					}
				}
				// 威力中
				else if (bugPower == 2) {
					if (changeRight_SP == true)
					{
						//初期化
						santa_Nor[7].numU = 0;
						santa_Nor[7].numV = 1;
						changeRight_SP = false;//一旦falseにして一回しか処理されないようにする
					}
					framcount3++; //フレームカウント
					if (framcount3 % 7 == 0) //１０フレームに一回行われる
					{
						santa_Nor[7].numU++;
						if (santa_Nor[7].numU >= 5)
						{
							sp_ani = false;
							santaImage = 0;
							santa_Nor[7].numU = 0;

						}
					}
				}
				// 威力強
				else if (bugPower == 3) {
					if (changeRight_SP == true)
					{
						//初期化
						santa_Nor[7].numU = 0;
						santa_Nor[7].numV = 1;
						changeRight_SP = false;//一旦falseにして一回しか処理されないようにする
					}
					framcount3++; //フレームカウント
					if (framcount3 % 10 == 0) //１０フレームに一回行われる
					{
						santa_Nor[7].numU++;
						if (santa_Nor[7].numU >= 5)
						{
							sp_ani = false;
							santaImage = 0;
							santa_Nor[7].numU = 0;

						}
					}
				}
			}
			
		}
		
		// 右移動
		if (sp_ani==false && gameoverFg==false&&collision.canMoveRight && input.GetKeyPress(VK_D) && pauseFg == false || gameoverFg == false && collision.canMoveRight && input.GetLeftAnalogStick().x >= 0.1 && pauseFg == false)
		{
			direction = 0; // 方向
			santa_pos.x += 5;//右移動

			if (bugPower == 0) {
				santaImage = 6;
				if (changeRight_SP_1 == true)
				{
					//初期化
					santa_Nor[6].numU = 0;
					santa_Nor[6].numV = 0;
					changeRight_SP_1 = false;//一旦falseにして一回しか処理されないようにする
				}
				framcount4++; //フレームカウント
				if (framcount4 % 4 == 0) //１０フレームに一回行われる
				{
					santa_Nor[6].numU++;
					if (santa_Nor[6].numU >= 4)
					{
						santa_Nor[6].numU = 0;

					}
				}
			}
			else if (bugPower > 0) {
				santaImage = 0;
				if (changeRight == true)
				{
					//初期化
					santa_Nor[0].numU = 0;
					santa_Nor[0].numV = 0;
					changeRight = false;//一旦falseにして一回しか処理されないようにする
				}
				framcount++; //フレームカウント
				if (framcount % 10 == 0) //１０フレームに一回行われる
				{
					santa_Nor[0].numU++;
					if (santa_Nor[0].numU >= 4)
					{
						santa_Nor[0].numU = 0;
						santa_Nor[0].numV++;
						if (santa_Nor[0].numV >= 2)
						{
							santa_Nor[0].numV = 0;
						}
					}
			}
		
			}

			if (santa_pos.x >= 0) //プレイヤーが画面真ん中に行ったとき
			{
				santa_pos.x -= 5;

				//背景などを左に動かしてプレイヤーが右に動いてるように見せる
				//山
				mounten_pos1.x -= speed - 4.5;
				mounten_pos2.x -= speed - 4.5;
				mounten_pos3.x -= speed - 4.5;
				//背景の木
				wood_pos1.x -= speed - 2;
				wood_pos2.x -= speed - 2;
				wood_pos3.x -= speed - 2;
				//拾える石
				rock_pos1.x -= speed;
				rock_pos2.x -= speed;
				rock_pos3.x -= speed;
				rock_pos4.x -= speed;
				rock_pos5.x -= speed;
				rock_pos6.x -= speed;
				//地面
				ground_pos1.x -= speed;
				ground_pos2.x -= speed;
				ground_pos3.x -= speed;
				ground_pos4.x -= speed;
				ground_pos5.x -= speed;
				//階段
				stairs_pos1.x -= speed;
				stairs_pos2.x -= speed;
				stairs_pos3.x -= speed;
				stairs_pos4.x -= speed;
				//雪だるま
				snowman_pos1.x -= speed;
				snowman_pos2.x -= speed;
				snowman_pos3.x -= speed;
				//雪玉
				snowball_pos1.x -= speed;
				snowball_pos2.x -= speed;
				snowball_pos3.x -= speed;
				//星のてき
				star_monster_pos.x -= speed;
				//トナカイ
				tonakai_pos.x -= speed;
				//プレゼント
				present_pos1.x -= speed;
				present_pos2.x -= speed;
				present_pos3.x -= speed;
				//大きいプレゼント
				bigpresent_pos1.x -= speed;
				//木
				tree_pos.x -= speed;
				//ゴール
				goal_pos.x -= speed;

				//投げアイテム
				use_rock_pos1.x -= speed;
				use_rock_pos2.x -= speed;
				use_rock_pos3.x -= speed;
				use_snowball_pos1.x -= speed;
				use_snowball_pos2.x -= speed;
				use_snowball_pos3.x -= speed;

			}
		}
		else
		{
			//キーを離すとtrueに戻る
			if (sp_ani == false && changeRight_SP_1 == false) {
				santa_Nor[0].numU = 0;
				santa_Nor[0].numV = 0;
				santaImage = 0;
			}
			
			changeRight = true;
			changeRight_SP_1 = true;
		}

		// 左移動
		if (sp_ani == false && gameoverFg == false&&collision.canMoveLeft && input.GetKeyPress(VK_A) && pauseFg == false || gameoverFg == false && collision.canMoveLeft && input.GetLeftAnalogStick().x <= -0.1 && pauseFg == false)
		{
			direction = 1; // 方向
			santa_pos.x -= 5;//左移動

			if (bugPower == 0) {

				santaImage = 6;
				if (changeLeft_SP_1 == true)
				{
					//初期化
					santa_Nor[6].numU = 0;
					santa_Nor[6].numV = 1;
					changeLeft_SP_1 = false;//一旦falseにして一回しか処理されないようにする
				}
				framcount4++; //フレームカウント
				if (framcount4 % 4 == 0) //１０フレームに一回行われる
				{
					santa_Nor[6].numU++;
					if (santa_Nor[6].numU >= 4)
					{
				
						santa_Nor[6].numU = 0;

					}
				}
			}
			else if (bugPower > 0) {

				if (changeLeft == true)
				{
					//初期化
					santa_Nor[0].numU = 0;
					santa_Nor[0].numV = 2;
					changeLeft = false;//一旦falseにして一回しか処理されないようにする
				}
				framcount++; //フレームカウント
				if (framcount % 10 == 0) //１０フレームに一回行われる
				{
					santa_Nor[0].numU++;
					if (santa_Nor[0].numU >= 4)
					{
						santa_Nor[0].numU = 0;
						santa_Nor[0].numV++;
						if (santa_Nor[0].numV >= 4)
						{
							santa_Nor[0].numV = 2;
						}
					}
				}
			}
			
			

			if (santa_pos.x <= 0) //プレイヤーが画面真ん中に行ったとき
			{
				santa_pos.x += 5;



				//背景などを左に動かしてプレイヤーが右に動いてるように見せる
				//山
				mounten_pos1.x += speed - 4.5;
				mounten_pos2.x += speed - 4.5;
				mounten_pos3.x += speed - 4.5;
				//背景の木
				wood_pos1.x += speed - 2;
				wood_pos2.x += speed - 2;
				wood_pos3.x += speed - 2;
				//拾える石
				rock_pos1.x += speed;
				rock_pos2.x += speed;
				rock_pos3.x += speed;
				rock_pos4.x += speed;
				rock_pos5.x += speed;
				rock_pos6.x += speed;
				//地面
				ground_pos1.x += speed;
				ground_pos2.x += speed;
				ground_pos3.x += speed;
				ground_pos4.x += speed;
				ground_pos5.x += speed;
				//階段
				stairs_pos1.x += speed;
				stairs_pos2.x += speed;
				stairs_pos3.x += speed;
				stairs_pos4.x += speed;
				//雪だるま
				snowman_pos1.x += speed;
				snowman_pos2.x += speed;
				snowman_pos3.x += speed;
				//雪玉
				snowball_pos1.x += speed;
				snowball_pos2.x += speed;
				snowball_pos3.x += speed;
				//星のてき
				star_monster_pos.x += speed;
				//トナカイ
				tonakai_pos.x += speed;
				//プレゼント
				present_pos1.x += speed;
				present_pos2.x += speed;
				present_pos3.x += speed;
				//大きいプレゼント
				bigpresent_pos1.x += speed;
				//木
				tree_pos.x += speed;
				//ゴール
				goal_pos.x += speed;

				//投げアイテム
				use_rock_pos1.x += speed;
				use_rock_pos2.x += speed;
				use_rock_pos3.x += speed;
				use_snowball_pos1.x += speed;
				use_snowball_pos2.x += speed;
				use_snowball_pos3.x += speed;
			}
		}
		else
		{
			//キーを離すとtrueに戻る

			
			if (sp_ani == false && changeLeft_SP_1 == false) {
				santa_Nor[0].numU = 0;
				santa_Nor[0].numV = 2;
				santaImage = 0;
			}
			changeLeft = true;
			changeLeft_SP_1 = true;
		}


		//画像が画面外に行ったときにその画像を一番後ろに置く
			//例　画像１が画面外→画像３の後ろに 
			//山のスクロール　1280=画面サイズ
		if (mounten_pos1.x <= -1280 * 2)
		{
			mounten_pos1.x = mounten_pos3.x + SCREEN_WIDTH;

		}

		if (mounten_pos2.x <= -1280 * 2)
		{
			mounten_pos2.x = mounten_pos1.x + SCREEN_WIDTH;

		}

		if (mounten_pos3.x <= -1280 * 2)
		{
			mounten_pos3.x = mounten_pos2.x + SCREEN_WIDTH;

		}

		//木のスクロール
		if (wood_pos1.x <= -1280 * 2)
		{
			wood_pos1.x = wood_pos3.x + SCREEN_WIDTH;

		}

		if (wood_pos2.x <= -1280 * 2)
		{
			wood_pos2.x = wood_pos1.x + SCREEN_WIDTH;

		}

		if (wood_pos3.x <= -1280 * 2)
		{
			wood_pos3.x = wood_pos2.x + SCREEN_WIDTH;

		}




		santa_Nor[0].SetPos(santa_pos.x, santa_pos.y, santa_pos.z);
		santa_Nor[1].SetPos(santa_pos1.x, santa_pos1.y, santa_pos1.z);
		santa_Nor[2].SetPos(santa_pos2.x, santa_pos2.y, santa_pos2.z);
		santa_Nor[3].SetPos(santa_pos3.x, santa_pos3.y, santa_pos3.z);
		santa_Nor[4].SetPos(santa_pos4.x, santa_pos4.y, santa_pos4.z);
		santa_Nor[5].SetPos(santa_pos5.x, santa_pos5.y, santa_pos5.z);
		santa_Nor[6].SetPos(santa_pos6.x, santa_pos6.y, santa_pos6.z);
		santa_Nor[7].SetPos(santa_pos7.x, santa_pos7.y, santa_pos7.z);

		goal.SetPos(goal_pos.x, goal_pos.y, goal_pos.z);

		mounten[1].SetPos(mounten_pos1.x, mounten_pos1.y, mounten_pos1.z);
		mounten[2].SetPos(mounten_pos2.x, mounten_pos2.y, mounten_pos2.z);
		mounten[3].SetPos(mounten_pos3.x, mounten_pos3.y, mounten_pos3.z);

		wood[1].SetPos(wood_pos1.x, wood_pos1.y, wood_pos1.z);
		wood[2].SetPos(wood_pos2.x, wood_pos2.y, wood_pos2.z);
		wood[3].SetPos(wood_pos3.x, wood_pos3.y, wood_pos3.z);

		rock[1].SetPos(rock_pos1.x, rock_pos1.y, rock_pos1.z);
		rock[2].SetPos(rock_pos2.x, rock_pos2.y, rock_pos2.z);
		rock[3].SetPos(rock_pos3.x, rock_pos3.y, rock_pos3.z);
		rock[4].SetPos(rock_pos4.x, rock_pos4.y, rock_pos4.z);
		rock[5].SetPos(rock_pos5.x, rock_pos5.y, rock_pos5.z);
		rock[6].SetPos(rock_pos6.x, rock_pos6.y, rock_pos6.z);

		snowball[1].SetPos(snowball_pos1.x, snowball_pos1.y, snowball_pos1.z);
		snowball[2].SetPos(snowball_pos2.x, snowball_pos2.y, snowball_pos2.z);
		snowball[3].SetPos(snowball_pos3.x, snowball_pos3.y, snowball_pos3.z);

		stairs[1].SetPos(stairs_pos1.x, stairs_pos1.y, stairs_pos1.z);
		stairs[2].SetPos(stairs_pos2.x, stairs_pos2.y, stairs_pos2.z);
		stairs[3].SetPos(stairs_pos3.x, stairs_pos3.y, stairs_pos3.z);
		stairs[4].SetPos(stairs_pos4.x, stairs_pos4.y, stairs_pos4.z);

		snowman[1].SetPos(snowman_pos1.x, snowman_pos1.y, snowman_pos1.z);
		snowman[2].SetPos(snowman_pos2.x, snowman_pos2.y, snowman_pos2.z);
		snowman[3].SetPos(snowman_pos3.x, snowman_pos3.y, snowman_pos3.z);

		present[1].SetPos(present_pos1.x, present_pos1.y, present_pos1.z);
		present[2].SetPos(present_pos2.x, present_pos2.y, present_pos2.z);
		present[3].SetPos(present_pos3.x, present_pos3.y, present_pos3.z);

		BigPresent[1].SetPos(bigpresent_pos1.x, bigpresent_pos1.y, bigpresent_pos1.z);

		tree.SetPos(tree_pos.x, tree_pos.y, tree_pos.z);
		star_monster.SetPos(star_monster_pos.x, star_monster_pos.y, star_monster_pos.z);
		tonakai.SetPos(tonakai_pos.x, tonakai_pos.y, tonakai_pos.z);

		ground[1].SetPos(ground_pos1.x, ground_pos1.y, ground_pos1.z);
		ground[2].SetPos(ground_pos2.x, ground_pos2.y, ground_pos2.z);
		ground[3].SetPos(ground_pos3.x, ground_pos3.y, ground_pos3.z);

		ground[4].SetPos(ground_pos4.x, ground_pos4.y, ground_pos4.z);
		ground[5].SetPos(ground_pos5.x, ground_pos5.y, ground_pos5.z);

		use_rock[0].SetPos(use_rock_pos1.x, use_rock_pos1.y, use_rock_pos1.z);
		use_rock[1].SetPos(use_rock_pos2.x, use_rock_pos2.y, use_rock_pos2.z);
		use_rock[2].SetPos(use_rock_pos3.x, use_rock_pos3.y, use_rock_pos3.z);

		use_snowball[0].SetPos(use_snowball_pos1.x, use_snowball_pos1.y, use_snowball_pos1.z);
		use_snowball[1].SetPos(use_snowball_pos2.x, use_snowball_pos2.y, use_snowball_pos2.z);
		use_snowball[2].SetPos(use_snowball_pos3.x, use_snowball_pos3.y, use_snowball_pos3.z);

		Cursor.SetPos(cursor_pos.x, cursor_pos.y, cursor_pos.z);
		
	}
	break;

	case STAGE_2:
	{
		//サンタ
		DirectX::XMFLOAT3 santa_pos = santa_Nor[0].GetPos();

		//山
		DirectX::XMFLOAT3 mounten_pos1 = mounten[1].GetPos();
		DirectX::XMFLOAT3 mounten_pos2 = mounten[2].GetPos();
		DirectX::XMFLOAT3 mounten_pos3 = mounten[3].GetPos();

		//地面
		DirectX::XMFLOAT3 ground_pos1 = Ground_Stge2[1].GetPos();
		DirectX::XMFLOAT3 ground_pos2 = Ground_Stge2[2].GetPos();
		DirectX::XMFLOAT3 ground_pos3 = Ground_Stge2[3].GetPos();
		DirectX::XMFLOAT3 ground_pos4 = Ground_Stge2[4].GetPos();
		DirectX::XMFLOAT3 ground_pos5 = Ground_Stge2[5].GetPos();
		DirectX::XMFLOAT3 ground_pos6 = Ground_Stge2[6].GetPos();
		DirectX::XMFLOAT3 ground_pos7 = Ground_Stge2[7].GetPos();
		//つらら
		DirectX::XMFLOAT3 icicle_pos1 = Icicles_Stge2[1].GetPos();
		DirectX::XMFLOAT3 icicle_pos2 = Icicles_Stge2[2].GetPos();
		DirectX::XMFLOAT3 icicle_pos3 = Icicles_Stge2[3].GetPos();
		//階段
		DirectX::XMFLOAT3 stairs_pos1 = Stairs_Stge2[1].GetPos();
		DirectX::XMFLOAT3 stairs_pos2 = Stairs_Stge2[2].GetPos();
		DirectX::XMFLOAT3 stairs_pos3 = Stairs_Stge2[3].GetPos();
		DirectX::XMFLOAT3 stairs_pos4 = Stairs_Stge2[4].GetPos();
		DirectX::XMFLOAT3 stairs_pos5 = Stairs_Stge2[5].GetPos();
		//木
		DirectX::XMFLOAT3 tree_pos1 = Tree_Stge2[1].GetPos();
		//つららの上
		DirectX::XMFLOAT3 block_pos1 = Block_Stge2[1].GetPos();
		//プレゼント
		DirectX::XMFLOAT3 present_pos1 = Present_Stage2[1].GetPos();
		DirectX::XMFLOAT3 present_pos2 = Present_Stage2[2].GetPos();
		DirectX::XMFLOAT3 present_pos3 = Present_Stage2[3].GetPos();
		DirectX::XMFLOAT3 bigpresent_pos1 = BigPresent_Stage2[1].GetPos();
		//拾える岩
		DirectX::XMFLOAT3 rock_pos1 = Collectrock_Stage2[1].GetPos();
		DirectX::XMFLOAT3 rock_pos2 = Collectrock_Stage2[2].GetPos();
		DirectX::XMFLOAT3 rock_pos3 = Collectrock_Stage2[3].GetPos();
		DirectX::XMFLOAT3 rock_pos4 = Collectrock_Stage2[4].GetPos();
		DirectX::XMFLOAT3 rock_pos5 = Collectrock_Stage2[5].GetPos();
		DirectX::XMFLOAT3 rock_pos6 = Collectrock_Stage2[6].GetPos();
		//雪玉
		DirectX::XMFLOAT3 snowball_pos1 = Snowball_Stage2[1].GetPos();
		DirectX::XMFLOAT3 snowball_pos2 = Snowball_Stage2[2].GetPos();
		DirectX::XMFLOAT3 snowball_pos3 = Snowball_Stage2[3].GetPos();
		//壊せる岩
		DirectX::XMFLOAT3 breakrock_pos1 = Breakrock_Stge2[1].GetPos();

		// 地面との当たり判定の追加 ゴロイ
		for (int i = 0; i < image; i++) {
			DirectX::XMFLOAT3 ground_pos = GetGroundPos(i);

			if (collision.ground_santa(ground[i], santa_Nor[0], 50.0f, 0.0f)) {

				//// サンタが地面の上にいる場合
				if (santa_pos.y > ground_pos.y + ground[i].GetSize().y / 2.0f) {
					santa_pos.y = ground_pos.y + ground[i].GetSize().y / 2.0f + santa_Nor[0].GetSize().y / 2.0f;
					/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
				}
				else {
					/*std::cout << "\nSanta is falling." << std::endl;*/
				}

				// サンタが地面の右側にぶつかった場合
				if (santa_pos.x < ground_pos.x && santa_pos.y < ground_pos.y) {

					collision.canMoveRight = false; // 右に移動中なら移動を停止
				}

				// サンタが地面にぶつかった場合
				if (santa_pos.x > ground_pos.x && santa_pos.y < ground_pos.y) {
					collision.canMoveLeft = false; // 左に移動中なら移動を停止
				}
			}
		}


		// サンタがアイテムに当たった時
		bool itemCollected = false; // アイテムが既に回収されたかどうかのフラグ

		if (collision.item_santa(Collectrock_Stage2[1], santa_Nor[0], 100.0f, 0.0f))
		{
			if (input.GetKeyTrigger(VK_S) && !itemCollected)
			{
				/*itemID = 1;*/
				item->ItemGet(1); // いわを回収
				itemCollected = true;

			}
		}

		if (collision.item_santa(Collectrock_Stage2[2], santa_Nor[0], 100.0f, 0.0f))
		{
			if (input.GetKeyTrigger(VK_S) && !itemCollected)
			{
				/*itemID = 1;*/
				item->ItemGet(1); // いわを回収
				itemCollected = true;

			}
		}

		if (collision.item_santa(Collectrock_Stage2[3], santa_Nor[0], 100.0f, 0.0f))
		{
			if (input.GetKeyTrigger(VK_S) && !itemCollected)
			{
				/*itemID = 1;*/
				item->ItemGet(1); // いわを回収
				itemCollected = true;

			}
		}

		if (collision.item_santa(Collectrock_Stage2[4], santa_Nor[0], 100.0f, 0.0f))
		{
			if (input.GetKeyTrigger(VK_S) && !itemCollected)
			{
				/*itemID = 1;*/
				item->ItemGet(1); // いわを回収
				itemCollected = true;

			}
		}

		if (collision.item_santa(Collectrock_Stage2[5], santa_Nor[0], 100.0f, 0.0f))
		{
			if (input.GetKeyTrigger(VK_S) && !itemCollected)
			{
				/*itemID = 1;*/
				item->ItemGet(1); // いわを回収
				itemCollected = true;

			}
		}

		if (collision.item_santa(Collectrock_Stage2[6], santa_Nor[0], 100.0f, 0.0f))
		{
			if (input.GetKeyTrigger(VK_S) && !itemCollected)
			{
				/*itemID = 1;*/
				item->ItemGet(1); // いわを回収
				itemCollected = true;

			}
		}

		if (!itemCollected) {// 当たってない場合
			if (input.GetKeyTrigger(VK_S))
			{
				item->ItemRelease(); // 取り出す
			}
		}


		//速度
		speed = 10;

		//右移動
		if (collision.canMoveRight && input.GetKeyPress(VK_D))
		{
			santa_pos.x += 5;//右移動
			if (changeRight == true)
			{
				//初期化
				santa_Nor[0].numU = 0;
				santa_Nor[0].numV = 0;
				changeRight = false;//一旦falseにして一回しか処理されないようにする
			}
			framcount++; //フレームカウント
			if (framcount % 10 == 0) //１０フレームに一回行われる
			{
				santa_Nor[0].numU++;
				if (santa_Nor[0].numU >= 4)
				{
					santa_Nor[0].numU = 0;
					santa_Nor[0].numV++;
					if (santa_Nor[0].numV >= 2)
					{
						santa_Nor[0].numV = 0;
					}
				}
			}

			if (santa_pos.x >= 0) //プレイヤーが画面真ん中に行ったとき
			{
				santa_pos.x -= 5;

				//背景などを左に動かしてプレイヤーが右に動いてるように見せる
				//山
				mounten_pos1.x -= speed-4.5;
				mounten_pos2.x -= speed-4.5;
				mounten_pos3.x -= speed-4.5;
				//地面
				ground_pos1.x -= speed;
				ground_pos2.x -= speed;
				ground_pos3.x -= speed;
				ground_pos4.x -= speed;
				ground_pos5.x -= speed;
				ground_pos6.x -= speed;
				ground_pos7.x -= speed;
				//木
				tree_pos1.x -= speed;
				//つらら上
				block_pos1.x -= speed;
				//つらら
				icicle_pos1.x -= speed;
				icicle_pos2.x -= speed;
				icicle_pos3.x -= speed;
				//階段
				stairs_pos1.x -= speed;
				stairs_pos2.x -= speed;
				stairs_pos3.x -= speed;
				stairs_pos4.x -= speed;
				stairs_pos5.x -= speed;

				//プレゼント
				present_pos1.x -= speed;
				present_pos2.x -= speed;
				present_pos3.x -= speed;

				bigpresent_pos1.x -= speed;
				//壊せる岩
				breakrock_pos1.x -= speed;
				//回収岩
				rock_pos1.x -= speed;
				rock_pos2.x -= speed;
				rock_pos3.x -= speed;
				rock_pos4.x -= speed;
				rock_pos5.x -= speed;
				rock_pos6.x -= speed;

				//回収雪玉
				snowball_pos1.x -= speed;
				snowball_pos2.x -= speed;
				snowball_pos3.x -= speed;


			}
		}
		else
		{
			//キーを離すとtrueに戻る
			changeRight = true;
		}
		//左移動
		if (collision.canMoveLeft && input.GetKeyPress(VK_A))
		{
			santa_pos.x -= 5;//左移動
			if (changeLeft == true)
			{
				//初期化
				santa_Nor[0].numU = 0;
				santa_Nor[0].numV = 2;
				changeLeft = false;//一旦falseにして一回しか処理されないようにする
			}
			framcount++; //フレームカウント
			if (framcount % 10 == 0) //１０フレームに一回行われる
			{
				santa_Nor[0].numU++;
				if (santa_Nor[0].numU >= 4)
				{
					santa_Nor[0].numU = 0;
					santa_Nor[0].numV++;
					if (santa_Nor[0].numV >= 4)
					{
						santa_Nor[0].numV = 2;
					}
				}
			}

			if (santa_pos.x <= 0) //プレイヤーが画面真ん中に行ったとき
			{
				santa_pos.x += 5;

				//背景などを左に動かしてプレイヤーが右に動いてるように見せる
				//山
				mounten_pos1.x += speed - 4.5;
				mounten_pos2.x += speed - 4.5;
				mounten_pos3.x += speed - 4.5;
				//地面
				ground_pos1.x += speed;
				ground_pos2.x += speed;
				ground_pos3.x += speed;
				ground_pos4.x += speed;
				ground_pos5.x += speed;
				ground_pos6.x += speed;
				ground_pos7.x += speed;
				//木
				tree_pos1.x += speed;
				//つらら上
				block_pos1.x += speed;
				//つらら
				icicle_pos1.x += speed;
				icicle_pos2.x += speed;
				icicle_pos3.x += speed;
				//階段
				stairs_pos1.x += speed;
				stairs_pos2.x += speed;
				stairs_pos3.x += speed;
				stairs_pos4.x += speed;
				stairs_pos5.x += speed;

				//プレゼント
				present_pos1.x += speed;
				present_pos2.x += speed;
				present_pos3.x += speed;

				bigpresent_pos1.x += speed;
				//壊せる岩
				breakrock_pos1.x += speed;
				//回収岩
				rock_pos1.x += speed;
				rock_pos2.x += speed;
				rock_pos3.x += speed;
				rock_pos4.x += speed;
				rock_pos5.x += speed;
				rock_pos6.x += speed;

				//回収雪玉
				snowball_pos1.x += speed;
				snowball_pos2.x += speed;
				snowball_pos3.x += speed;
			}
		}
		else
		{
			//キーを離すとtrueに戻る
			changeLeft = true;
		}

		//画像が画面外に行ったときにその画像を一番後ろに置く
			//例　画像１が画面外→画像３の後ろに 
			//山のスクロール　1280=画面サイズ
		if (mounten_pos1.x <= -1280 * 2)
		{
			mounten_pos1.x = mounten_pos3.x + SCREEN_WIDTH;

		}

		if (mounten_pos2.x <= -1280 * 2)
		{
			mounten_pos2.x = mounten_pos1.x + SCREEN_WIDTH;

		}

		if (mounten_pos3.x <= -1280 * 2)
		{
			mounten_pos3.x = mounten_pos2.x + SCREEN_WIDTH;

		}


		santa_Nor[0].SetPos(santa_pos.x, santa_pos.y, santa_pos.z);//サンタ

		//背景　山
		mounten[1].SetPos(mounten_pos1.x, mounten_pos1.y, mounten_pos1.z);
		mounten[2].SetPos(mounten_pos2.x, mounten_pos2.y, mounten_pos2.z);
		mounten[3].SetPos(mounten_pos3.x, mounten_pos3.y, mounten_pos3.z);
		//ステージ地面
		Ground_Stge2[1].SetPos(ground_pos1.x, ground_pos1.y, ground_pos1.z);
		Ground_Stge2[2].SetPos(ground_pos2.x, ground_pos2.y, ground_pos2.z);
		Ground_Stge2[3].SetPos(ground_pos3.x, ground_pos3.y, ground_pos3.z);
		Ground_Stge2[4].SetPos(ground_pos4.x, ground_pos4.y, ground_pos4.z);
		Ground_Stge2[5].SetPos(ground_pos5.x, ground_pos5.y, ground_pos5.z);
		Ground_Stge2[6].SetPos(ground_pos6.x, ground_pos6.y, ground_pos6.z);
		Ground_Stge2[7].SetPos(ground_pos7.x, ground_pos7.y, ground_pos7.z);
		//つらら
		Icicles_Stge2[1].SetPos(icicle_pos1.x, icicle_pos1.y, icicle_pos1.z);
		Icicles_Stge2[2].SetPos(icicle_pos2.x, icicle_pos2.y, icicle_pos2.z);
		Icicles_Stge2[3].SetPos(icicle_pos3.x, icicle_pos3.y, icicle_pos3.z);
		//階段
		Stairs_Stge2[1].SetPos(stairs_pos1.x, stairs_pos1.y, stairs_pos1.z);
		Stairs_Stge2[2].SetPos(stairs_pos2.x, stairs_pos2.y, stairs_pos2.z);
		Stairs_Stge2[3].SetPos(stairs_pos3.x, stairs_pos3.y, stairs_pos3.z);
		Stairs_Stge2[4].SetPos(stairs_pos4.x, stairs_pos4.y, stairs_pos4.z);
		Stairs_Stge2[5].SetPos(stairs_pos5.x, stairs_pos5.y, stairs_pos5.z);
		//木
		Tree_Stge2[1].SetPos(tree_pos1.x, tree_pos1.y, tree_pos1.z);
		//つらら上
		Block_Stge2[1].SetPos(block_pos1.x, block_pos1.y, block_pos1.z);
		//プレゼント
		Present_Stage2[1].SetPos(present_pos1.x, present_pos1.y, present_pos1.z);
		Present_Stage2[2].SetPos(present_pos2.x, present_pos2.y, present_pos2.z);
		Present_Stage2[3].SetPos(present_pos3.x, present_pos3.y, present_pos3.z);
		BigPresent_Stage2[1].SetPos(bigpresent_pos1.x, bigpresent_pos1.y, bigpresent_pos1.z);
		//壊せる岩
		Breakrock_Stge2[1].SetPos(breakrock_pos1.x, breakrock_pos1.y, breakrock_pos1.z);
		//ステージ地面
		Collectrock_Stage2[1].SetPos(rock_pos1.x, rock_pos1.y, rock_pos1.z);
		Collectrock_Stage2[2].SetPos(rock_pos2.x, rock_pos2.y, rock_pos2.z);
		Collectrock_Stage2[3].SetPos(rock_pos3.x, rock_pos3.y, rock_pos3.z);
		Collectrock_Stage2[4].SetPos(rock_pos4.x, rock_pos4.y, rock_pos4.z);
		Collectrock_Stage2[5].SetPos(rock_pos5.x, rock_pos5.y, rock_pos5.z);
		Collectrock_Stage2[6].SetPos(rock_pos6.x, rock_pos6.y, rock_pos6.z);
		//雪玉
		Snowball_Stage2[1].SetPos(snowball_pos1.x, snowball_pos1.y, snowball_pos1.z);
		Snowball_Stage2[2].SetPos(snowball_pos2.x, snowball_pos2.y, snowball_pos2.z);
		Snowball_Stage2[3].SetPos(snowball_pos3.x, snowball_pos3.y, snowball_pos3.z);
	}
	break;

	case BOSS:
		
		//キー入力でタイトル移動
		if (input.GetKeyTrigger(VK_RETURN))
		{
			changescene = RESULT;//リザルトへ
		}
		break;

	case RESULT:
		score = 1;
		//キー入力でタイトル移動
		if (input.GetKeyTrigger(VK_RETURN)||input.GetButtonPress(XINPUT_B))
		{
			//初期化
			time = 150;
			framcount = 0;
			framcount2 = 0;
			score = 0;
			presentcount = 0;
			time = 150;
			cleartime = 0;
			
			changescene = TITLE;//タイトルへ
		}
		break;


	default:
		break;
	}

}

void Game::Draw(void)
{

	D3D_StartRender();//描画開始

	int keta = 0;//スコア
	int keta2 = 0;//制限時間
	int keta3 = 0;//クリア時間

	DirectX::XMFLOAT3 scorepos = Number_UI[1].GetPos();
	DirectX::XMFLOAT3 scoresize = Number_UI[1].GetSize();

	DirectX::XMFLOAT3 timepos = Number_UI[2].GetPos();
	DirectX::XMFLOAT3 timesize = Number_UI[2].GetSize();

	switch (changescene)
	{
	case TITLE://タイトル
		background.Draw();//プレイヤー描画
		titlesanta.Draw();
		title.Draw();
		PressBbotton.Draw();
		
		break;
	case STAGESELECT:
		StegeSelect.Draw();
		SantaCursor.Draw();
		break;
	case STAGE1_LOADING:
		Stage1_Loading.Draw();
		break;
	case STAGE_1://ゲーム



		sky.Draw();
		star.Draw();

		//やま
		for (int i = 1; i < image; i++)
		{
			mounten[i].Draw();//ゲーム背景
		}
		//き
		for (int i = 1; i < image; i++)
		{
			wood[i].Draw();
		}
		//いわ
		if (rock_visible1 == 0) {
			rock[1].Draw();
		}
		if (rock_visible2 == 0) {
			rock[2].Draw();
		}
		if (rock_visible3 == 0) {
			rock[3].Draw();
		}
		if (rock_visible4 == 0) {
			rock[4].Draw();
		}
		if (rock_visible5 == 0) {
			rock[5].Draw();
		}
		if (rock_visible6 == 0) {
			rock[6].Draw();
		}

		//雪玉
		if (snow_visible1 == 0)
		{
			snowball[1].Draw();
		}
		if (snow_visible2 == 0)
		{
			snowball[2].Draw();
		}
		if (snow_visible3 == 0)
		{
			snowball[3].Draw();
		}

		//プレゼント
		for (int i = 1; i < image; i++)
		{
			present[i].Draw();
		}
		//じめん
		for (int i = 1; i < image; i++)
		{
			ground[i].Draw();
		}
		//階段
		for (int i = 1; i < image; i++)
		{
			stairs[i].Draw();
		}
		//階段
		for (int i = 1; i < image; i++)
		{
			stairs[i].Draw();
		}
		//雪だるま
		for (int i = 1; i < image; i++)
		{
			snowman[i].Draw();
		}

		BigPresent[1].Draw();

		tonakai.Draw();
		star_monster.Draw();

		tree.Draw();

		if (santaImage == 0) {
			santa_Nor[0].Draw();//プレイヤー描画
		}
		else if(santaImage==6){
			santa_Nor[6].Draw();
		}
		else if (santaImage == 7) {
			santa_Nor[7].Draw();
		}
		
		goal.Draw();

		ItemStock.Draw();

		///////// 投げ物 ///////////////////

		if (itemID_1 == 1) {
			use_rock[0].Draw();
		}
		if (itemID_2 == 1) {
			use_rock[1].Draw();
		}
		if (itemID_3 == 1) {
			use_rock[2].Draw();
		}
			
		if (itemID_1 == 2) {
			use_snowball[0].Draw();
		}
		if (itemID_2 == 2) {
			use_snowball[1].Draw();
		}
		if (itemID_3 == 2) {
			use_snowball[2].Draw();
		}
		

		///////// UI  ///////////////////

		// bug1
		if (item->GetItem_1() == 1) // 岩
		{
			itemUi[0].Draw();
		}
		if (item->GetItem_1() == 2) // 雪玉
		{
			itemUi[3].Draw();
		}
		if (item->GetItem_1() == 3) // つらら
		{
			itemUi[6].Draw();
		}

		// bug2
		if (item->GetItem_2() == 1) // 岩
		{
			itemUi[1].Draw();
		}
		if (item->GetItem_2() == 2) // 雪玉
		{
			itemUi[4].Draw();
		}
		if (item->GetItem_2() == 3) // つらら
		{
			itemUi[7].Draw();
		}

		// bug3
		if (item->GetItem_3() == 1) // 岩
		{
			itemUi[2].Draw();
		}
		if (item->GetItem_3() == 2) // 雪玉
		{
			itemUi[5].Draw();
		}
		if (item->GetItem_3() == 3) // つらら
		{
			itemUi[8].Draw();
		}

		/////////////////////////////////

		ScoreCounter.Draw();
		//スコア
		do {
			Number_UI[1].numU = score % (int)pow(10, keta + 1) / (int)pow(10, keta);//一桁を切り出す
			Number_UI[1].SetPos(scorepos.x - scoresize.x * keta, scorepos.y, scoresize.z);//位置を設定

			Number_UI[1].Draw();//スコアを描画
			keta++;
		} while (score >= (int)pow(10, keta));
		Number_UI[1].SetPos(scorepos.x, scorepos.y, scorepos.z);

		Time.Draw();
		
		//制限時間
		do {
			Number_UI[2].numU = time % (int)pow(10, keta2 + 1) / (int)pow(10, keta2);//一桁を切り出す
			Number_UI[2].SetPos(timepos.x - timesize.x * keta2, timepos.y, timesize.z);//位置を設定

			Number_UI[2].Draw();//スコアを描画
			keta2++;
		} while (time >= (int)pow(10, keta2));
		Number_UI[2].SetPos(timepos.x, timepos.y, timepos.z);


		if (gameoverFg == true)
		{
			pause.Draw();
			Gameover.Draw();
			GoodMorning.Draw();
			TitleBack.Draw();
			Retry.Draw();
			Cursor.Draw();
		}

		if (pauseFg == true)
		{
			pause.Draw();
			Gameover.Draw();
			rule.Draw();
		}


		
		break;
	case STAGE_2://ステージ２


		sky.Draw();
		star.Draw();

		//やま
		for (int i = 1; i < image; i++)
		{
			mounten[i].Draw();//ゲーム背景
		}

		//じめん
		for (int i = 1; i < image; i++)
		{
			Ground_Stge2[i].Draw();
		}

		//木
		for (int i = 1; i < image; i++)
		{
			Tree_Stge2[i].Draw();
		}

		//ブロック
		for (int i = 1; i < image; i++)
		{
			Block_Stge2[i].Draw();
		}
		//つらら
		for (int i = 1; i < image; i++)
		{
			Icicles_Stge2[i].Draw();
		}
		//階段
		for (int i = 1; i < image; i++)
		{
			Stairs_Stge2[i].Draw();
		}
		//プレゼント
		for (int i = 1; i < image; i++)
		{
			Present_Stage2[i].Draw();
		}
		//回収いわ
		for (int i = 1; i < image; i++)
		{
			Collectrock_Stage2[i].Draw();
		}
		//回収雪玉
		for (int i = 1; i < image; i++)
		{
			Snowball_Stage2[i].Draw();
		}

		ScoreCounter.Draw();
		//スコア
		do {
			Number_UI[1].numU = score % (int)pow(10, keta + 1) / (int)pow(10, keta);//一桁を切り出す
			Number_UI[1].SetPos(scorepos.x - scoresize.x * keta, scorepos.y, scoresize.z);//位置を設定

			Number_UI[1].Draw();//スコアを描画
			keta++;
		} while (score >= (int)pow(10, keta));
		Number_UI[1].SetPos(scorepos.x, scorepos.y, scorepos.z);

		Time.Draw();

		//制限時間
		do {
			Number_UI[2].numU = time % (int)pow(10, keta2 + 1) / (int)pow(10, keta2);//一桁を切り出す
			Number_UI[2].SetPos(timepos.x - timesize.x * keta2, timepos.y, timesize.z);//位置を設定

			Number_UI[2].Draw();//スコアを描画
			keta2++;
		} while (time >= (int)pow(10, keta2));
		Number_UI[2].SetPos(timepos.x, timepos.y, timepos.z);

		Breakrock_Stge2[1].Draw();
		BigPresent_Stage2[1].Draw();
		santa_Nor[0].Draw();//プレイヤー描画
		ItemStock.Draw();
		break;
	
	case RESULT://リザルト
		DirectX::XMFLOAT3 timepos = Number[1].GetPos();
		DirectX::XMFLOAT3 timesize = Number[1].GetSize();



		Result.Draw();//リザルト背景
		
		cleartime = 150 - time;
		do {
			Number[1].numU = cleartime % (int)pow(10, keta3 + 1) / (int)pow(10, keta3);//一桁を切り出す
			Number[1].SetPos(timepos.x - timesize.x * keta3, timepos.y, timesize.z);//位置を設定

			Number[1].Draw();//スコアを描画
			keta3++;
		} while (cleartime >= (int)pow(10, keta3));
		Number[1].SetPos(timepos.x, timepos.y, timepos.z);

		//クリアタイムに応じてスコア加算
		if (cleartime <= 20)
		{
			score++;
		}

		//一定のスコアを超えていると色付きの星になる処理　  あぜ
		if (score >= 500)
		{
			ResultStar[1].Draw();
		}
		else
		{
			GrayStar[1].Draw();
		}

		if (score >= 1000)
		{
			ResultStar[2].Draw();
		}
		else
		{
			GrayStar[2].Draw();
		}

		if (score >= 1500)
		{
			ResultStar[3].Draw();
		}
		else
		{
			GrayStar[3].Draw();
		}

		if (score >= 2500)
		{
			ResultStar[4].Draw();
		}
		else
		{
			GrayStar[4].Draw();
		}

		break;
	}



	D3D_FinishRender();//描画終了
}

void Game::Uninit(void)
{

	delete item;
	background.Uninit();//プレイヤー終了
	titlesanta.Uninit();//終了
	title.Uninit();//終了

	sky.Uninit();//終了
	star.Uninit();//終了
	Stage1_Loading.Uninit();
	for (int i = 1; i < image; i++)
	{
		ground[i].Uninit();
		wood[i].Uninit();
		mounten[i].Uninit();
		rock[i].Uninit();
		stairs[i].Uninit();
		snowman[i].Uninit();
		present[i].Uninit();
		snowball[i].Uninit();

		//ステージ2
		Ground_Stge2[i].Uninit();
		Tree_Stge2[i].Uninit();
		Block_Stge2[i].Uninit();
		Icicles_Stge2[i].Uninit();
		Stairs_Stge2[i].Uninit();
		Present_Stage2[i].Uninit();
		Collectrock_Stage2[i].Uninit();
		Snowball_Stage2[i].Uninit();
	}

	BigPresent[1].Uninit();
	BigPresent_Stage2[1].Uninit();
	Breakrock_Stge2[1].Uninit();
	tree.Uninit();
	star_monster.Uninit();
	tonakai.Uninit();
	goal.Uninit();

	Result.Uninit();//リザルト背景
	Number[1].Uninit();//数字
	ResultStar[1].Uninit();
	ResultStar[2].Uninit();
	ResultStar[3].Uninit();
	ResultStar[4].Uninit();

	Number_UI[1].Uninit();
	Number_UI[2].Uninit();


	rule.Uninit();
	Gameover.Uninit();
	GoodMorning.Uninit();
	TitleBack.Uninit();
	Retry.Uninit();
	Cursor.Uninit();
	PressBbotton.Uninit();
	pause.Uninit();
	SantaCursor.Uninit();
	ScoreCounter.Uninit();
	Time.Uninit();
	ItemStock.Uninit();
	StegeSelect.Uninit();
	sound.Uninit();//サウンドを終了
	// DirectXの解放処理
	D3D_Release();//DirextXを終了
}

DirectX::XMFLOAT3 Game::GetSantaPos() const {
	return santa_Nor[0].GetPos();
}

const Object& Game::GetSanta() const {
	return santa_Nor[0];
}


DirectX::XMFLOAT3 Game::GetGroundPos(int index) const {
	if (index >= 0 && index < image) {
		return ground[index].GetPos();
	}
	else {
		return { 0.0f, 0.0f, 0.0f }; // 範囲外の場合、デフォルト値を返す
	}
}

const Object& Game::GetGround(int index) const {
	if (index >= 0 && index < image) {
		return ground[index];
	}
	else {
		static Object dummy;
		return dummy; // 範囲外の場合、ダミーオブジェクトを返す
	}
}
