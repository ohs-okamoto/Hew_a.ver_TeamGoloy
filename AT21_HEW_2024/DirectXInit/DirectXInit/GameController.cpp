#include "GameController.h"
#include <windows.h>

//�쐬�ҁF����
GameController::GameController() {      //�R���X�g���N�^
    ZeroMemory(&state, sizeof(XINPUT_STATE));       //�\���̏�����
    isConnected = false;        //�ŏ��͐ڑ��Ȃ�
}

void GameController::Update() {         //��ԍX�V
    DWORD dwResult = XInputGetState(0, &state);

    if (dwResult == ERROR_SUCCESS) {    //�ڑ�����
        isConnected = true;
    }
    else {                              //�ڑ��Ȃ�
        isConnected = false;
    }
}

bool GameController::IsButtonPressed(WORD button) const {
    return isConnected && (state.Gamepad.wButtons & button);
}



