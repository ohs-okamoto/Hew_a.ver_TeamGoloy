#include"PhysicalOperationh.h"


// 障害物の衝突をチェック
bool checkCollision(double posX, double posY) {
    // シンプルな衝突判定: X, Y座標が特定範囲に入ったら衝突
    return (posX >= 50.0 && posX <= 60.0 && posY <= 10.0);
}

// プレイヤーの状態を更新
void updatePlayer(Player& player, const Input& input) {
    // 状態ごとに挙動を処理
    if (player.state == PlayerState::Gliding) {
        // 滑空中
        player.velY += GRAVITY * DELTA_TIME * 0.5; // 落下速度を軽減
        player.velX += input.stickX * 5.0 * DELTA_TIME; // スティック入力で方向転換

        if (input.cancel) {
            // キャンセルで通常落下に移行
            player.state = PlayerState::Falling;
            std::cout << "Glide canceled!" << std::endl;
        }
    }
    else if (player.state == PlayerState::Falling) {
        // 通常の自由落下
        player.velY += GRAVITY * DELTA_TIME;
    }

    // プレイヤー位置の更新
    player.posX += player.velX * DELTA_TIME;
    player.posY += player.velY * DELTA_TIME;

    // 衝突判定
    if (checkCollision(player.posX, player.posY)) {
        player.velX = 0.0;
        player.velY = 0.0;
        std::cout << "Collision detected!" << std::endl;
    }

    // 地面到達時の処理
    if (player.posY <= 0.0) {
        player.posY = 0.0;
        player.velY = 0.0;
        player.state = PlayerState::Normal;
        player.glideCount = 2; // 滑空回数をリセット
        std::cout << "Player landed!" << std::endl;
    }
}

// 滑空開始
void startGlide(Player& player) {
    if (player.state != PlayerState::Gliding && player.glideCount > 0) {
        player.state = PlayerState::Gliding;
        player.velY = -5.0; // 滑空開始時に軽い上昇を付与
        player.glideCount--;
        std::cout << "Gliding started! Remaining glides: " << player.glideCount << std::endl;
    }
}