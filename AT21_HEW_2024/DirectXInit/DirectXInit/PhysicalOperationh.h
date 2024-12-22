#pragma once
#include"Direct3d.h"
#include"Object.h"
#include"Game.h"

#include <iostream>

// プレイヤーの状態
enum class PlayerState { Normal, Gliding, Falling };

// プレイヤー構造体
struct Player {
    double mass;       // 質量 (kg)
    double posX;       // X座標
    double posY;       // Y座標
    double velX;       // X方向速度
    double velY;       // Y方向速度
    int glideCount;    // 残り滑空回数
    PlayerState state; // プレイヤーの状態
};

// 入力構造体
struct Input {
    bool glide;      // 滑空ボタンが押されたか
    bool cancel;     // 滑空キャンセルボタンが押されたか
    double stickX;   // スティックのX方向入力 (-1.0 ~ 1.0)
};

// 定数
const double GRAVITY = 9.81;      // 重力加速度 (m/s^2)
const double DELTA_TIME = 0.016;  // 1フレームの時間 (約60FPS)

// 関数プロトタイプ
void updatePlayer(Player& player, const Input& input);  // プレイヤー状態の更新
void startGlide(Player& player);                        // 滑空開始
bool checkCollision(double posX, double posY);          // 障害物の衝突チェック
