#include "Game.h"
#include "Texture.h"
#include "Collision.h"
#include <iostream>

using namespace std;

//2024年12/24 横スクロール 作成　畦内

//2024年12/31  ステージ１作成 　畦内
void Game::Init(HWND hWnd)
{
	D3D_Create(hWnd);//Directxを初期化
//====================================================
//プレイヤー関連
//====================================================
	santa.Init(L"asset/Santa_Normal_Move.png", 4, 4);//サンタを初期化
	santa.SetPos(-400.0f, -175.0f, 0.0f);		//位置を設定
	santa.SetSize(180.0f, 90.0f, 0.f);	//大きさを設定
	santa.SetAngle(0.0f);             		//角度を設定
	santa.SetColor(1.0f, 1.0f, 1.0f, 1.0f); //色を設定
//====================================================
//タイトル
//====================================================
	title.Init(L"asset/title.png", 1, 1);//サンタを初期化
	title.SetPos(150.0f, 50.0f, 0.0f);		//位置を設定
	title.SetSize(250.0f, 150.0f, 0.f);	//大きさを設定
	title.SetAngle(0.0f);             		//角度を設定
	title.SetColor(1.0f, 1.0f, 1.0f, 1.0f); //色を設定

	titlesanta.Init(L"asset/Hukuro_2.png", 1, 1);//を初期化
	titlesanta.SetPos(0.0f, 0.0f, 0.0f);         //位置を設定
	titlesanta.SetSize(1280.0f, 720.0f, 0.f);     //大きさ設定
	titlesanta.SetAngle(0.0f);//角度を設定	    

	background.Init(L"asset/background.png",1,1);//プレイヤーを初期化
	background.SetPos(0.0f, 0.0f, 0.0f);         //位置を設定
	background.SetSize(1280.0f, 720.0f, 0.f);     //大きさ設定
	background.SetAngle(0.0f);//角度を設定	    
//====================================================
//ステージ
//====================================================
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
	ground[1].Init(L"asset/ground.png", 1, 1);//地面
	ground[1].SetPos(0.0f, -300.0f, 0.0f);//位置を特定
	ground[1].SetSize(1280, 200.0f, 0.0f);//大きさ設定
	ground[1].SetAngle(0.0f);//角度設定

	ground[2].Init(L"asset/ground.png", 1, 1);//地面
	ground[2].SetPos(1300.0f, -300.0f, 0.0f);//位置を特定
	ground[2].SetSize(700.0f, 200.0f, 0.0f);//大きさ設定
	ground[2].SetAngle(0.0f);//角度設定

	ground[3].Init(L"asset/ground.png", 1, 1);//地面
	ground[3].SetPos(3100.0f, -300.0f, 0.0f);//位置を特定
	ground[3].SetSize(2500.0f, 200.0f, 0.0f);//大きさ設定
	ground[3].SetAngle(0.0f);//角度設定

	ground[4].Init(L"asset/ground.png", 1, 1);//地面
	ground[4].SetPos(4500.0f, -450.0f, 0.0f);//位置を特定
	ground[4].SetSize(500.0f, 200.0f, 0.0f);//大きさ設定
	ground[4].SetAngle(0.0f);//角度設定

	ground[5].Init(L"asset/ground.png", 1, 1);//地面
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

	tree.Init(L"asset/koyoju.png", 1, 1);//木
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

	//いわ
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
	rock[4].SetPos(1100.0f, -175.0f, 0.0f);////位置を特定
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
	stairs[1].Init(L"asset/stairs.png", 1, 1);//いわ
	stairs[1].SetPos(540.0f, -165.0f, 0.0f);//位置を特定
	stairs[1].SetSize(200.0f, 70.0f, 0.0f);//大きさ設定
	stairs[1].SetAngle(0.0f);//角度設定

	stairs[2].Init(L"asset/stairs.png", 1, 1);//いわ
	stairs[2].SetPos(565.0f, -95.0f, 0.0f);//位置を特定
	stairs[2].SetSize(150.0f, 70.0f, 0.0f);//大きさ設定
	stairs[2].SetAngle(0.0f);//角度設定

	stairs[3].Init(L"asset/stairs.png", 1, 1);//いわあ
	stairs[3].SetPos(600.0f, -25.0f, 0.0f);////位置を特定
	stairs[3].SetSize(75.0f, 70.0f, 0.0f);//大きさ設定
	stairs[3].SetAngle(0.0f);//角度設定

	stairs[4].Init(L"asset/stairs.png", 1, 1);//いわあ
	stairs[4].SetPos(2800.0f, 80.0f, 0.0f);////位置を特定
	stairs[4].SetSize(300.0f, 70.0f, 0.0f);//大きさ設定
	stairs[4].SetAngle(0.0f);//角度設定


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

//====================================================
//てき
//====================================================

	snowman[1].Init(L"asset/snowman.png", 4, 1);//雪だるまを初期化
	snowman[1].SetPos(30.0f, -160.0f, 0.0f);		//位置を設定
	snowman[1].SetSize(180.0f, 90.0f, 0.f);	//大きさを設定
	snowman[1].SetAngle(0.0f);             		//角度を設定
	snowman[1].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //色を設定

	snowman[2].Init(L"asset/snowman.png", 4, 1);//雪だるまを初期化
	snowman[2].SetPos(1400.0f, -160.0f, 0.0f);		//位置を設定
	snowman[2].SetSize(180.0f, 90.0f, 0.f);	//大きさを設定
	snowman[2].SetAngle(0.0f);             		//角度を設定
	snowman[2].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //色を設定

	snowman[3].Init(L"asset/snowman.png", 4, 1);//ゆきを初期化
	snowman[3].SetPos(2700.0f, -160.0f, 0.0f);		//位置を設定
	snowman[3].SetSize(180.0f, 90.0f, 0.f);	//大きさを設定
	snowman[3].SetAngle(0.0f);             		//角度を設定
	snowman[3].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //色を設定


	star_monster.Init(L"asset/star_monster.png", 3, 2);//ほしを初期化
	star_monster.SetPos(3600.0f, -150.0f, 0.0f);		//位置を設定
	star_monster.SetSize(200.0f, 110.0f, 0.f);	//大きさを設定
	star_monster.SetAngle(0.0f);             		//角度を設定
	star_monster.SetColor(1.0f, 1.0f, 1.0f, 1.0f); //色を設定

	tonakai.Init(L"asset/tonakai.png", 4, 1);//となかいを初期化
	tonakai.SetPos(4800.0f, -140.0f, 0.0f);		//位置を設定
	tonakai.SetSize(220.0f, 130.0f, 0.f);	//大きさを設定
	tonakai.SetAngle(0.0f);             		//角度を設定
	tonakai.SetColor(1.0f, 1.0f, 1.0f, 1.0f); //色を設定


	changescene = TITLE;//シーン初期化
}

void Game::Update(void) {
	input.Update();

	Collision collision; // 宣言
	collision.canMoveRight = true; // フラグを初期化
	collision.canMoveLeft = true; // フラグを初期化


	//値更新する処理の後に入力処理を記述すること byほたか

	switch (changescene)
	{
	case TITLE:
		//キー入力で本編
		if (input.GetKeyTrigger(VK_RETURN))
		{
			changescene = STAGE_1;
		}


		break;
	case STAGE_1:
	{
		//サンタ
		DirectX::XMFLOAT3 santa_pos = santa.GetPos();
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

		//階段
		DirectX::XMFLOAT3 stairs_pos1 = stairs[1].GetPos();
		DirectX::XMFLOAT3 stairs_pos2 = stairs[2].GetPos();
		DirectX::XMFLOAT3 stairs_pos3 = stairs[3].GetPos();
		DirectX::XMFLOAT3 stairs_pos4 = stairs[4].GetPos();

		DirectX::XMFLOAT3 snowman_pos1 = snowman[1].GetPos();
		DirectX::XMFLOAT3 snowman_pos2 = snowman[2].GetPos();
		DirectX::XMFLOAT3 snowman_pos3 = snowman[3].GetPos();
		DirectX::XMFLOAT3 star_monster_pos = star_monster.GetPos();
		DirectX::XMFLOAT3 tonakai_pos = tonakai.GetPos();


		DirectX::XMFLOAT3 present_pos1 = present[1].GetPos();
		DirectX::XMFLOAT3 present_pos2 = present[2].GetPos();
		DirectX::XMFLOAT3 present_pos3 = present[3].GetPos();


		// 一旦仮で重力的なものをを追加します　ゴロイ
		santa_pos.y -= 1;
		
		// サンタが下に落ちた時に初期位置に戻る処理　ゴロイ
		if (santa_pos.y == -250.0f)
		{
			santa_pos.x = -400.0f;
			santa_pos.y = -175.0f;
		}

		

			// 地面との当たり判定の追加 ゴロイ
		for (int i = 0; i < image; i++) {
			DirectX::XMFLOAT3 ground_pos = GetGroundPos(i);

			if (collision.ground_santa(ground[i], santa, 50.0f, 0.0f)) {

				//// サンタが地面の上にいる場合
				if (santa_pos.y > ground_pos1.y + ground[i].GetSize().y / 2.0f) {
                    santa_pos.y = ground_pos1.y + ground[i].GetSize().y / 2.0f + santa.GetSize().y / 2.0f;
					/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
				}
				else {
					/*std::cout << "\nSanta is falling." << std::endl;*/
				}

				// サンタが地面の右側にぶつかった場合
				if (santa_pos.x < ground_pos1.x && santa_pos.y < ground_pos1.y) {

					collision.canMoveRight = false; // 右に移動中なら移動を停止
				}

				// サンタが地面にぶつかった場合
				if (santa_pos.x > ground_pos1.x && santa_pos.y < ground_pos1.y) {
					collision.canMoveLeft = false; // 左に移動中なら移動を停止
				}
			}
		}

		
		// 木との当たり判定の追加　ゴロイ
		if (collision.tree_santa(tree, santa, 200.0f, 0.0f)) {

			// サンタが木の右側にぶつかった場合
			if (santa_pos.x < tree_pos.x) {

				collision.canMoveRight = false; // 右に移動中なら移動を停止

			}
			// サンタが木の左側にぶつかった場合
			if (santa_pos.x > tree_pos.x) {

				collision.canMoveLeft = false; // 左に移動中なら移動を停止

			}
		}

		//
		// 12/30  サンタの移動アニメーション追加  	畦内　
		if (collision.canMoveRight && input.GetKeyPress(VK_D))
		{
			santa_pos.x += 5;//右移動
			if (changeRight == true)
			{
				//初期化
				santa.numU = 0;
				santa.numV = 0;
				changeRight = false;//一旦falseにして一回しか処理されないようにする
			}
			framcount++; //フレームカウント
			if (framcount % 10 == 0) //１０フレームに一回行われる
			{
				santa.numU++;
				if (santa.numU >= 4)
				{
					santa.numU = 0;
					santa.numV++;
					if (santa.numV >= 2)
					{
						santa.numV = 0;
					}
				}
			}

			if (santa_pos.x >= 0) //プレイヤーが画面真ん中に行ったとき
			{
				santa_pos.x -= 5;

				//背景などを左に動かしてプレイヤーが右に動いてるように見せる
				mounten_pos1.x -= 0.5;
				mounten_pos2.x -= 0.5;
				mounten_pos3.x -= 0.5;

				wood_pos1.x -= 3;
				wood_pos2.x -= 3;
				wood_pos3.x -= 3;

				rock_pos1.x -= 5;
				rock_pos2.x -= 5;
				rock_pos3.x -= 5;
				rock_pos4.x -= 5;
				rock_pos5.x -= 5;
				rock_pos6.x -= 5;

				ground_pos1.x -= 5;
				ground_pos2.x -= 5;
				ground_pos3.x -= 5;
				ground_pos4.x -= 5;
				ground_pos5.x -= 5;

				stairs_pos1.x -= 5;
				stairs_pos2.x -= 5;
				stairs_pos3.x -= 5;
				stairs_pos4.x -= 5;
				
				snowman_pos1.x -= 5;
				snowman_pos2.x -= 5;
				snowman_pos3.x -= 5;

				star_monster_pos.x -= 5;
				tonakai_pos.x -= 5;

				present_pos1.x -= 5;
				present_pos2.x -= 5;
				present_pos3.x -= 5;

				tree_pos.x -= 5;
			}
		}
		else
		{
			//キーを離すとtrueに戻るう
			changeRight = true;
		}

		if (collision.canMoveLeft && input.GetKeyPress(VK_A))
		{
			santa_pos.x -= 5;//左移動
			if (changeLeft == true)
			{
				//初期化
				santa.numU = 0;
				santa.numV = 2;
				changeLeft = false;//一旦falseにして一回しか処理されないようにする
			}
			framcount++; //フレームカウント
			if (framcount % 10 == 0) //１０フレームに一回行われる
			{
				santa.numU++;
				if (santa.numU >= 4)
				{
					santa.numU = 0;
					santa.numV++;
					if (santa.numV >= 4)
					{
						santa.numV = 2;
					}
				}
			}

			if (santa_pos.x <= 0) //プレイヤーが画面真ん中に行ったとき
			{
				santa_pos.x += 5;

				//背景などを左に動かしてプレイヤーが右に動いてるように見せる
				mounten_pos1.x += 0.5;
				mounten_pos2.x += 0.5;
				mounten_pos3.x += 0.5;

				wood_pos1.x += 3;
				wood_pos2.x += 3;
				wood_pos3.x += 3;

				rock_pos1.x += 5;
				rock_pos2.x += 5;
				rock_pos3.x += 5;
				rock_pos4.x += 5;
				rock_pos5.x += 5;
				rock_pos6.x += 5;

				ground_pos1.x += 5;
				ground_pos2.x += 5;
				ground_pos3.x += 5;
				ground_pos4.x += 5;
				ground_pos5.x += 5;

				stairs_pos1.x += 5;
				stairs_pos2.x += 5;
				stairs_pos3.x += 5;
				stairs_pos4.x += 5;


				star_monster_pos.x += 5;
				tonakai_pos.x += 5;

				snowman_pos1.x += 5;
				snowman_pos2.x += 5;
				snowman_pos3.x += 5;
				  


				present_pos1.x += 5;
				present_pos2.x += 5;
				present_pos3.x += 5;

				tree_pos.x += 5;
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



		santa.SetPos(santa_pos.x, santa_pos.y, santa_pos.z);

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

		tree.SetPos(tree_pos.x, tree_pos.y, tree_pos.z);
		star_monster.SetPos(star_monster_pos.x, star_monster_pos.y, star_monster_pos.z);
		tonakai.SetPos(tonakai_pos.x, tonakai_pos.y, tonakai_pos.z);

		ground[1].SetPos(ground_pos1.x, ground_pos1.y, ground_pos1.z);
		ground[2].SetPos(ground_pos2.x, ground_pos2.y, ground_pos2.z);
		ground[3].SetPos(ground_pos3.x, ground_pos3.y, ground_pos3.z);
//<<<<<<< HEAD


//=======
		ground[4].SetPos(ground_pos4.x, ground_pos4.y, ground_pos4.z);
		ground[5].SetPos(ground_pos5.x, ground_pos5.y, ground_pos5.z);
//>>>>>>> e8321b3097c4f2e0599a6db2b02d5b3f315aeefc
	}
	break;
	case RESULT:
		//キー入力でタイトル移動
		if (input.GetKeyTrigger(VK_RETURN))
		{

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
	
	switch (changescene)
	{
	case TITLE://タイトル
		background.Draw();//プレイヤー描画
		titlesanta.Draw();
		title.Draw();
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
		for (int i = 1; i < image; i++)
		{
			rock[i].Draw();
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
		tonakai.Draw();
		star_monster.Draw();

		tree.Draw();

		santa.Draw();//プレイヤー描画
		
		break;

	case 2://リザルト

		break;
	}



	D3D_FinishRender();//描画終了
}

void Game::Uninit(void)
{
	background.Uninit();//プレイヤー終了
	titlesanta.Uninit();//終了
	title.Uninit();//終了

	sky.Uninit();//終了
	star.Uninit();//終了

	for (int i = 1; i < image; i++)
	{
		ground[i].Uninit();
		wood[i].Uninit();
		mounten[i].Uninit();
		rock[i].Uninit();
		stairs[i].Uninit();
		snowman[i].Uninit();
		present[i].Uninit();
		
	}
	tree.Uninit();
	star_monster.Uninit();
	tonakai.Uninit();
	
	// DirectXの解放処理
	D3D_Release();//DirextXを終了
}

DirectX::XMFLOAT3 Game::GetSantaPos() const {
	return santa.GetPos();
}

const Object& Game::GetSanta() const {
	return santa;
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
