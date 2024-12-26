#include "GameController.h"
#include <windows.h>

//作成者：内野
GameController::GameController() {      //コンストラクタ
    ZeroMemory(&state, sizeof(XINPUT_STATE));       //構造体初期化
    isConnected = false;        //最初は接続なし
}

void GameController::Update() {         //状態更新
    DWORD dwResult = XInputGetState(0, &state);

    if (dwResult == ERROR_SUCCESS) {    //接続あり
        isConnected = true;
    }
    else {                              //接続なし
        isConnected = false;
    }
}

bool GameController::IsButtonPressed(WORD button) const {
    return isConnected && (state.Gamepad.wButtons & button);
}



