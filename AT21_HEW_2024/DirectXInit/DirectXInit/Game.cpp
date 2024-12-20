#include "Game.h"


void Game::Init(HWND hWnd)
{
	D3D_Create(hWnd);//Directxを初期化
	player.Init(L"asset/char01.png",3,4);//プレイヤーを初期化
	player.SetPos(100.0f, 0.0f, 0.0f);		//位置を設定
	player.SetSize(200.0f, 300.0f, 0.f);	//大きさを設定
	player.SetAngle(0.0f);             		//角度を設定
	player.SetColor(1.0f, 1.0f, 1.0f, 1.0f); //色を設定

	background.Init(L"asset/background.png",1,1);//プレイヤーを初期化
	background.SetPos(0.0f, 0.0f, 0.0f);         //位置を設定
	background.SetSize(640.0f, 480.0f, 0.f);     //大きさ設定
	background.SetAngle(0.0f);//角度を設定	    
}

void Game::Update(void) {
	input.Update();

	DirectX::XMFLOAT3 pos = player.GetPos();
	pos.x = 1.0f; //値を更新
	player.SetPos(pos.x, pos.y, pos.z);

	//値更新する処理の後に入力処理を記述すること byほたか
}

void Game::Draw(void)
{
	D3D_StartRender();//描画開始
	background.Draw();//プレイヤー描画
	player.Draw();//プレイヤー描画
	D3D_FinishRender();//描画終了
}

void Game::Uninit(void)
{
	player.Uninit();//プレイヤー終了
	background.Uninit();//プレイヤー終了
	
	// DirectXの解放処理
	D3D_Release();//DirextXを終了
}