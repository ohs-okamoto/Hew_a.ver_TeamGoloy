#include "Game.h"


void Game::Init(HWND hWnd)
{
	D3D_Create(hWnd);//Directxを初期化

	santa.Init(L"asset/tati.png", 1, 1);//サンタを初期化
	santa.SetPos(-200.0f, -150.0f, 0.0f);		//位置を設定
	santa.SetSize(100.0f, 80.0f, 0.f);	//大きさを設定
	santa.SetAngle(0.0f);             		//角度を設定
	santa.SetColor(1.0f, 1.0f, 1.0f, 1.0f); //色を設定

	

	background.Init(L"asset/background.png",1,1);//プレイヤーを初期化
	background.SetPos(0.0f, 0.0f, 0.0f);         //位置を設定
	background.SetSize(640.0f, 480.0f, 0.f);     //大きさ設定
	background.SetAngle(0.0f);//角度を設定	    

	//山
	mounten[1].Init(L"asset/mountain_stage_1.png", 1, 1);//ゲーム背景
	mounten[1].SetPos(0.0f, 0.0f, 0.0f);//位置を特定
	mounten[1].SetSize(640.0f, 480.0f, 0.0f);//大きさ設定
	mounten[1].SetAngle(0.0f);//角度設定

	mounten[2].Init(L"asset/mountain_stage_1.png", 1, 1);//ゲーム背景
	mounten[2].SetPos(640.0f, 0.0f, 0.0f);//位置を特定
	mounten[2].SetSize(640.0f, 480.0f, 0.0f);//大きさ設定
	mounten[2].SetAngle(0.0f);//角度設定

	mounten[3].Init(L"asset/mountain_stage_1.png", 1, 1);//ゲーム背景
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
	tree[1].Init(L"asset/wood_stage_1.png", 1, 1);//タイトル背景
	tree[1].SetPos(0.0f, -50.0f, 0.0f);//位置を特定
	tree[1].SetSize(640.0f, 320.0f, 0.0f);//大きさ設定
	tree[1].SetAngle(0.0f);//角度設定

	tree[2].Init(L"asset/wood_stage_1.png", 1, 1);//タイトル背景
	tree[2].SetPos(640.0f, -50.0f, 0.0f);//位置を特定
	tree[2].SetSize(640.0f, 320.0f, 0.0f);//大きさ設定
	tree[2].SetAngle(0.0f);//角度設定

	tree[3].Init(L"asset/wood_stage_1.png", 1, 1);//タイトル背景
	tree[3].SetPos(1280.0f, -50.0f, 0.0f);//位置を特定
	tree[3].SetSize(640.0f, 320.0f, 0.0f);//大きさ設定
	tree[3].SetAngle(0.0f);//角度設定




	sky.Init(L"asset/sky.png", 1, 1);//タイトル背景
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
		DirectX::XMFLOAT3 tree_pos1 = tree[1].GetPos();
		DirectX::XMFLOAT3 tree_pos2 = tree[2].GetPos();
		DirectX::XMFLOAT3 tree_pos3 = tree[3].GetPos();

		//地面
		DirectX::XMFLOAT3 ground_pos1 = ground[1].GetPos();
		DirectX::XMFLOAT3 ground_pos2 = ground[2].GetPos();
		DirectX::XMFLOAT3 ground_pos3 = ground[3].GetPos();

		if (input.GetKeyPress(VK_D))
		{
			santa_pos.x += 5;

			if (santa_pos.x >= 0)//プレイヤーが画面真ん中に行ったとき
			{

				santa_pos.x -= 5;

				//背景などを左に動かしてプレイヤーが右に動いてるように見せる
				mounten_pos1.x -= 0.5;
				mounten_pos2.x -= 0.5;
				mounten_pos3.x -= 0.5;

				tree_pos1.x -= 3;
				tree_pos2.x -= 3;
				tree_pos3.x -= 3;

				ground_pos1.x -= 5;
				ground_pos2.x -= 5;
				ground_pos3.x -= 5;

			}
		}
		if (input.GetKeyPress(VK_A))
		{

			santa_pos.x -= 5;

			if (santa_pos.x <= 0)//プレイヤーが画面真ん中に行ったとき
			{
				santa_pos.x += 5;


				//背景などを右に動かしてプレイヤーが左に動いてるように見せる
				mounten_pos1.x += 0.5;
				mounten_pos2.x += 0.5;
				mounten_pos3.x += 0.5;

				tree_pos1.x += 3;
				tree_pos2.x += 3;
				tree_pos3.x += 3;

				ground_pos1.x += 5;
				ground_pos2.x += 5;
				ground_pos3.x += 5;
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
		if (tree_pos1.x <= -640 * 2)
		{
			tree_pos1.x = tree_pos3.x + SCREEN_WIDTH;

		}

		if (tree_pos2.x <= -640 * 2)
		{
			tree_pos2.x = tree_pos1.x + SCREEN_WIDTH;

		}

		if (tree_pos3.x <= -640 * 2)
		{
			tree_pos3.x = tree_pos2.x + SCREEN_WIDTH;

		}



		santa.SetPos(santa_pos.x, santa_pos.y, santa_pos.z);

		mounten[1].SetPos(mounten_pos1.x, mounten_pos1.y, mounten_pos1.z);
		mounten[2].SetPos(mounten_pos2.x, mounten_pos2.y, mounten_pos2.z);
		mounten[3].SetPos(mounten_pos3.x, mounten_pos3.y, mounten_pos3.z);
	
		tree[1].SetPos(tree_pos1.x, tree_pos1.y, tree_pos1.z);
		tree[2].SetPos(tree_pos2.x, tree_pos2.y, tree_pos2.z);
		tree[3].SetPos(tree_pos3.x, tree_pos3.y, tree_pos3.z);

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
		player.Draw();//プレイヤー描画
		
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

			ground[i].Draw();

		}

		for (int i = 1; i < image; i++)
		{

			tree[i].Draw();
		}

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


	sky.Uninit();
	star.Uninit();
	for (int i = 1; i < image; i++)
	{
		ground[i].Uninit();
		tree[i].Uninit();
		mounten[i].Uninit();
	}

	
	// DirectXの解放処理
	D3D_Release();//DirextXを終了
}