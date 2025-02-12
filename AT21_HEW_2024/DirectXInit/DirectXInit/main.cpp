#undef UNICODE  // Unicodeではなく、マルチバイト文字を使う

#include <Windows.h>
#include "Game.h"
#include "Collision.h"
#include <iostream>
#include <iomanip> // <iomanip>を追加

// マクロ定義
#define CLASS_NAME   "DX21Smpl"// ウインドウクラスの名前
#define WINDOW_NAME  "DirectX初期化"// ウィンドウの名前

// 関数のプロトタイプ宣言
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

//// コンソールに関する関数 ゴロイ
//void SetupConsole() {
//	AllocConsole();
//	FILE* file;
//	freopen_s(&file, "CONOUT$", "w", stdout);
//	freopen_s(&file, "CONOUT$", "w", stderr);
//	freopen_s(&file, "CONOUT$", "w", stdin);
//}

// コンソールのカーソル位置を設定する関数
void SetConsoleCursorPosition(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}





//--------------------------------------------------------------------------------------
// エントリポイント＝一番最初に実行される関数　　※作成者　岡本穂高
//--------------------------------------------------------------------------------------
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	//// コンソールウィンドウの初期化 ゴロイ
	//SetupConsole();

	// ウィンドウクラス情報をまとめる
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_CLASSDC;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = CLASS_NAME;
	wc.hIconSm = NULL;

	RegisterClassEx(&wc);

	// ウィンドウの情報をまとめる
	HWND hWnd;
	hWnd = CreateWindowEx(0,	// 拡張ウィンドウスタイル
		CLASS_NAME,				// ウィンドウクラスの名前
		WINDOW_NAME,			// ウィンドウの名前
		WS_OVERLAPPEDWINDOW,	// ウィンドウスタイル
		CW_USEDEFAULT,			// ウィンドウの左上Ｘ座標
		CW_USEDEFAULT,			// ウィンドウの左上Ｙ座標 
		SCREEN_WIDTH,			// ウィンドウの幅
		SCREEN_HEIGHT,			// ウィンドウの高さ
		NULL,					// 親ウィンドウのハンドル
		NULL,					// メニューハンドルまたは子ウィンドウID
		hInstance,				// インスタンスハンドル
		NULL);					// ウィンドウ作成データ

	//ウィンドウのサイズを表示
	RECT rc1, rc2;
	GetWindowRect(hWnd, &rc1);
	GetClientRect(hWnd, &rc2);
	int sx = SCREEN_WIDTH;
	int sy = SCREEN_HEIGHT;
	sx += ((rc1.right - rc1.left) - (rc2.right - rc2.left));
	sy += ((rc1.bottom - rc1.top) - (rc2.bottom - rc2.top));
	SetWindowPos(hWnd, NULL, 0, 0, sx, sy, (SWP_NOZORDER | SWP_NOOWNERZORDER | SWP_NOMOVE)); //ウィンドウサイズを変更

	// 指定されたウィンドウの表示状態を設定(ウィンドウを表示)
	ShowWindow(hWnd, nCmdShow);
	// ウィンドウの状態を直ちに反映(ウィンドウのクライアント領域を更新)
	UpdateWindow(hWnd);

	//ゲーム初期化
	Game game;
	game.Init(hWnd);

	Texture texture;
	// ゲームループに入る前にDirectXの初期化をする
	MSG msg;

	// FPS計測用変数
	int fpsCounter = 0;
	long long oldTick = GetTickCount64();	//前回計測時の時間
	long long nowTick = oldTick;			//今回計測時の時間

	//FPS固定用変数
	LARGE_INTEGER liwork;//workがつく変数は作業用変数
	long long frequency;//どれくらい細かく時間をカウントできるか
	QueryPerformanceFrequency(&liwork);
	frequency = liwork.QuadPart;
	//時間（単位：カウント）取得
	QueryPerformanceCounter(&liwork);
	long long oldCount = liwork.QuadPart;//前回計測時の時間
	long long nowCount = oldCount;		 //今回の計測時間


	// ゲームループ
	while(1)
	{
		// 新たにメッセージがあれば
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			// ウィンドウプロシージャにメッセージを送る
			DispatchMessage(&msg);

			// 「WM_QUIT」メッセージを受け取ったらループを抜ける
			if (msg.message == WM_QUIT) {
				break;
			}
		}
		{
			QueryPerformanceCounter(&liwork);//現在時間を取得
			nowCount = liwork.QuadPart;
			//1/60秒が経過したか
			if (nowCount >= oldCount + frequency / 60) {
				//ゲーム処理実行
				game.Update();


				// コンソールを先頭に戻して新しい情報を表示 ゴロイ

				//texture.Load();変更途中
				// コンソールを先頭に戻して新しい情報を表示
				// 

				
				//SetConsoleCursorPosition(0, 0);
				//auto santaPos = game.GetSantaPos();
				//std::cout<<"サンタの座標 : (" << game.GetSantaPos().x << ", " << game.GetSantaPos().y << ")\n" << std::endl;
				//
				//
				//// 地面の座標を出力
				//for (int i = 0; i < image; ++i) {
				//	auto groundPos = game.GetGroundPos(i);
				//	const auto& groundObj = game.GetGround(i);
				//	const auto& santaObj = game.GetGround(i);
				//	Collision collision; // 当たり判定オブジェクト

				//	


				//	// 地面とサンタの当たり判定チェック
				//	bool isColliding = collision.ground_santa(groundObj, santaObj, 50.0f, 50.0f);
				//	std::cout << "Ground[" << i << "]の座標 : (" << groundPos.x << "," << groundPos.y << "," << groundPos.z << ") - Collision : " << (collision.isColliding ? "〇":"×") << " - Direction: " << collision.collisionDirection<< "\n";
				//}
				
				game.Draw();

				fpsCounter++;//ゲーム処理を実行したら＋１する
				oldCount = nowCount;
			}

			nowTick = GetTickCount64();//現在時間を取得
			//前回計測から１００００ミリ秒が経過したか？
			if (nowTick >= oldTick + 1000) {
				//FPS表示
				char str[32];
				wsprintfA(str, "FPS=%d", fpsCounter);
				SetWindowTextA(hWnd, str);
				//カウンターリセット
				fpsCounter = 0;
				oldTick = nowTick;
			}

		}
	}
	game.Uninit();

	UnregisterClass(CLASS_NAME, hInstance);

	return (int)msg.wParam;
}

//--------------------------------------------------------------------------------------
//ウィンドウプロシージャ　　※作成者　岡本穂高
//--------------------------------------------------------------------------------------

//以下のコードいじるなら岡本まで

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	static bool isFullscreen = false;
	static bool isMessageBoxShowed = false;
	switch (uMsg)
	{
	case WM_DESTROY:// ウィンドウ破棄のメッセージ
		PostQuitMessage(0);// 「WM_QUIT」メッセージを送る　→　アプリ終了
		break;

	case WM_CLOSE:  // 「x」ボタンが押されたら
		{
			int res = MessageBoxA(NULL, "終了しますか？", "確認", MB_OKCANCEL);
			if (res == IDOK) {
				DestroyWindow(hWnd);  // 「WM_DESTROY」メッセージを送る
			}
		}
		break;

	case WM_KEYDOWN: //キー入力があったメッセージ
		if (LOWORD(wParam) == VK_ESCAPE) { //入力されたキーがESCAPEなら
			PostMessage(hWnd, WM_CLOSE, wParam, lParam);//「WM_CLOSE」を送る
		}
		else if (LOWORD(wParam) == VK_F11) {
			//F11でフルスクリーンに切り替え
			isFullscreen = !isFullscreen;
			if (isFullscreen) {
				//疑似フルスクリーンモードに変更
				SetWindowLongPtr(hWnd, GWL_STYLE, WS_POPUP | WS_MINIMIZEBOX); //ウィンドウ粋を解除
				//ディスプレイ解像度を取得
				int screenWidth = GetSystemMetrics(SM_CXSCREEN);
				int screenHeight = GetSystemMetrics(SM_CYSCREEN);
				SetWindowPos(hWnd, HWND_TOP, 0, 0, screenWidth, screenHeight, SWP_FRAMECHANGED | SWP_SHOWWINDOW);

			}
			else {
				//通常ウィンドウに戻す
				SetWindowLongPtr(hWnd, GWL_STYLE, WS_OVERLAPPEDWINDOW);//ウィンドウ粋を戻す
				SetWindowPos(hWnd, HWND_TOP, 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SWP_FRAMECHANGED | SWP_SHOWWINDOW);

			}
		}
		break;
	case WM_ACTIVATE:
		if (wParam == WA_INACTIVE) {
			if (isFullscreen && !isMessageBoxShowed)//フルスクリーン表示かつメッセージボックス非表示
			{
				ShowWindow(hWnd, SW_MINIMIZE);//ウィンドウを最小化する（タスク切り替え時に背後に残る問題対策）

			}
		}
		return DefWindowProc(hWnd, uMsg, wParam, lParam);//標準挙動を実行させるため
	default:
		// 受け取ったメッセージに対してデフォルトの処理を実行
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
		break;
	}

	return 0;
}
