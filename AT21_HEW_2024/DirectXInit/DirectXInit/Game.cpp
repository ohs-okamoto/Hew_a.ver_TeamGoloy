#include "Game.h"
#include "Collision.h"
#include <iostream>

using namespace std;

//2024年12/24 横スクロール（仮？）作成　畦内

void Game::Init(HWND hWnd)
{
	D3D_Create(hWnd);//Directxを初期化

	santa.Init(L"asset/Santa_Nomal_Pack_Move.png", 4, 2);//サンタを初期化
	santa.SetPos(-200.0f, -175.0f, 0.0f);		//位置を設定
	santa.SetSize(70.0f, 50.0f, 0.f);	//大きさを設定
	santa.SetAngle(0.0f);             		//角度を設定
	santa.SetColor(1.0f, 1.0f, 1.0f, 1.0f); //色を設定

	title.Init(L"asset/title.png", 1, 1);//サンタを初期化
	title.SetPos(150.0f, 50.0f, 0.0f);		//位置を設定
	title.SetSize(250.0f, 150.0f, 0.f);	//大きさを設定
	title.SetAngle(0.0f);             		//角度を設定
	title.SetColor(1.0f, 1.0f, 1.0f, 1.0f); //色を設定

	titlesanta.Init(L"asset/Hukuro_2.png", 1, 1);//を初期化
	titlesanta.SetPos(0.0f, 0.0f, 0.0f);         //位置を設定
	titlesanta.SetSize(640.0f, 480.0f, 0.f);     //大きさ設定
	titlesanta.SetAngle(0.0f);//角度を設定	    

	background.Init(L"asset/background.png",1,1);//プレイヤーを初期化
	background.SetPos(0.0f, 0.0f, 0.0f);         //位置を設定
	background.SetSize(640.0f, 480.0f, 0.f);     //大きさ設定
	background.SetAngle(0.0f);//角度を設定	    

	//山
	mounten[1].Init(L"asset/background_stage_1_v02.png", 1, 1);//ゲーム背景
	mounten[1].SetPos(0.0f, 0.0f, 0.0f);//位置を特定
	mounten[1].SetSize(640.0f, 480.0f, 0.0f);//大きさ設定
	mounten[1].SetAngle(0.0f);//角度設定

	mounten[2].Init(L"asset/background_stage_1_v02.png", 1, 1);//ゲーム背景
	mounten[2].SetPos(640.0f, 0.0f, 0.0f);//位置を特定
	mounten[2].SetSize(640.0f, 480.0f, 0.0f);//大きさ設定
	mounten[2].SetAngle(0.0f);//角度設定

	mounten[3].Init(L"asset/background_stage_1_v02.png", 1, 1);//ゲーム背景
	mounten[3].SetPos(1280.0f, 0.0f, 0.0f);//位置を特定
	mounten[3].SetSize(640.0f, 480.0f, 0.0f);//大きさ設定
	mounten[3].SetAngle(0.0f);//角度設定

	//地面
	ground[1].Init(L"asset/ground.png", 1, 1);//地面
	ground[1].SetPos(0.0f, -300.0f, 0.0f);//位置を特定
	ground[1].SetSize(640.0f, 200.0f, 0.0f);//大きさ設定
	ground[1].SetAngle(0.0f);//角度設定

	ground[2].Init(L"asset/ground.png", 1, 1);//地面
	ground[2].SetPos(700.0f, -300.0f, 0.0f);//位置を特定
	ground[2].SetSize(640.0f, 200.0f, 0.0f);//大きさ設定
	ground[2].SetAngle(0.0f);//角度設定

	ground[3].Init(L"asset/ground.png", 1, 1);//地面
	ground[3].SetPos(1400.0f, -300.0f, 0.0f);//位置を特定
	ground[3].SetSize(640.0f, 200.0f, 0.0f);//大きさ設定
	ground[3].SetAngle(0.0f);//角度設定

	//木
	wood[1].Init(L"asset/wood_stage_1.png", 1, 1);//木
	wood[1].SetPos(0.0f, -30.0f, 0.0f);//位置を特定
	wood[1].SetSize(640.0f, 420.0f, 0.0f);//大きさ設定
	wood[1].SetAngle(0.0f);//角度設定

	wood[2].Init(L"asset/wood_stage_1.png", 1, 1);//木
	wood[2].SetPos(640.0f, -30.0f, 0.0f);//位置を特定
	wood[2].SetSize(640.0f, 420.0f, 0.0f);//大きさ設定
	wood[2].SetAngle(0.0f);//角度設定

	wood[3].Init(L"asset/wood_stage_1.png", 1, 1);//木
	wood[3].SetPos(1280.0f, -30.0f, 0.0f);//位置を特定
	wood[3].SetSize(640.0f, 420.0f, 0.0f);//大きさ設定
	wood[3].SetAngle(0.0f);//角度設定

	tree.Init(L"asset/koyoju.png", 1, 1);//木

	tree.SetPos(400.0f, -70.0f, 0.0f);//位置を特定
	tree.SetSize(240.0f, 250.0f, 0.0f);//大きさ設定
	tree.SetAngle(0.0f);//角度設定


	sky.Init(L"asset/sky.png", 1, 1);//ゲーム背景
	sky.SetPos(0.0f, 0.0f, 0.0f);//位置を特定
	sky.SetSize(640.0f, 480.0f, 0.0f);//大きさ設定
	sky.SetAngle(0.0f);//角度設定

	star.Init(L"asset/star.png", 1, 1);//星
	star.SetPos(0.0f, 0.0f, 0.0f);//位置を特定
	star.SetSize(640.0f, 480.0f, 0.0f);//大きさ設定
	star.SetAngle(0.0f);//角度設定


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

		// 一旦仮で重力的なものをを追加します　ゴロイ
		santa_pos.y -= 1;

		// サンタが下に落ちた時に初期位置に戻る処理　ゴロイ
		if (santa_pos.y == -250.0f)
		{
			santa_pos.x = 200.0f;
			santa_pos.y = -175.0f;
		}

		

			// 地面との当たり判定の追加 ゴロイ
		for (int i = 0; i < image; i++) {
			DirectX::XMFLOAT3 ground_pos = ground[i].GetPos();

			if (collision.ground_santa(ground[i], santa, 50.0f, 0.0f)) {
				//// サンタが地面の上にいる場合
				if (santa_pos.y > ground_pos1.y + ground[i].GetSize().y / 2.0f) {

					santa_pos.y = ground_pos1.y + ground[i].GetSize().y / 2.0f + santa.GetSize().y / 2.0f;
					std::cout << "\nSanta is on top of the ground." << std::endl;
				}
				else {
					std::cout << "\nSanta is falling." << std::endl;
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

		

		if (collision.canMoveRight && input.GetKeyPress(VK_D))
		{
			santa_pos.x += 5;
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

				ground_pos1.x -= 5;
				ground_pos2.x -= 5;
				ground_pos3.x -= 5;

				tree_pos.x -= 5;
			}
		}
		if (collision.canMoveLeft && input.GetKeyPress(VK_A))
		{
			santa_pos.x -= 5;
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

				ground_pos1.x += 5;
				ground_pos2.x += 5;
				ground_pos3.x += 5;

				tree_pos.x += 5;
			}
		}


		//画像が画面外に行ったときにその画像を一番後ろに置く
			//例　画像１が画面外→画像３の後ろに 
			//山のスクロール　640=画面サイズ
		if (mounten_pos1.x <= -640 * 2)
		{
			mounten_pos1.x = mounten_pos3.x + SCREEN_WIDTH;

		}

		if (mounten_pos2.x <= -640 * 2)
		{
			mounten_pos2.x = mounten_pos1.x + SCREEN_WIDTH;

		}

		if (mounten_pos3.x <= -640* 2)
		{
			mounten_pos3.x = mounten_pos2.x + SCREEN_WIDTH;

		}

		//木のスクロール
		if (wood_pos1.x <= -640 * 2)
		{
			wood_pos1.x = wood_pos3.x + SCREEN_WIDTH;

		}

		if (wood_pos2.x <= -640 * 2)
		{
			wood_pos2.x = wood_pos1.x + SCREEN_WIDTH;

		}

		if (wood_pos3.x <= -640 * 2)
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

		tree.SetPos(tree_pos.x, tree_pos.y, tree_pos.z);

		ground[1].SetPos(ground_pos1.x, ground_pos1.y, ground_pos1.z);
		ground[2].SetPos(ground_pos2.x, ground_pos2.y, ground_pos2.z);
		ground[3].SetPos(ground_pos3.x, ground_pos3.y, ground_pos3.z);


	}
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

		for (int i = 1; i < image; i++)
		{
			mounten[i].Draw();//ゲーム背景

		}

		for (int i = 1; i < image; i++)
		{

			wood[i].Draw();
		}

		for (int i = 1; i < image; i++)
		{

			ground[i].Draw();

		}

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
	}
	tree.Uninit();
	
	// DirectXの解放処理
	D3D_Release();//DirextXを終了
}