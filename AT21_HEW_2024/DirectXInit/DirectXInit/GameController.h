#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

//作成者：内野
//====================================================
//概　要：コントローラーの状態を管理するためのクラス
//====================================================

#include <Xinput.h>

class GameController {      
public:

    //-------------------------------------------------
    //概　要：XINPUT_STATE初期化
    //引　数：なし
    //戻り値：なし
    //-------------------------------------------------
    GameController();       //コンストラクタ

    //-------------------------------------------------
    //概　要：コントローラの状態更新
    //引　数：なし
    //戻り値：isConnected(true / false)
    //-------------------------------------------------
    void Update();          //コントローラーの状態更新

    //-------------------------------------------------
    //概　要：指定された関数が押されているか
    //引　数：button
    //戻り値：どのボタンが押されているか
    //------------------------------------------------- 
    bool IsButtonPressed(WORD button) const;

private:
    XINPUT_STATE state;
    bool isConnected;
};

#endif // GAME_CONTROLLER_H
