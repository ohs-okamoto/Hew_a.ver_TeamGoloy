#pragma once
#include "Object.h"
#include <string>

// 2024/12/22 作成者　ゴロイ

class Collision :public Object {

public:

	bool square_square(Object obj1, Object obj2); // 四角形と四角形の当たり判定
	bool ground_santa(Object obj1, Object obj2, float bufferX, float bufferY); // 地面とサンタの当たり判定
	bool tree_santa(Object obj1, Object obj2, float bufferX, float bufferY); // 地面とサンタの当たり判定
	bool goal_santa(Object obj1, Object obj2, float bufferX, float bufferY); // ゴールとサンタの当たり判定
	bool circle_circle(Object obj1, Object obj2); // 円と円の当たり判定
	
	bool canMoveRight = true; // 右に移動できるかどうか
	bool canMoveLeft = true;  // 左に移動できるかどうか
	bool isColliding = false;  // 当たり判定結果を保持するフラグ
	std::string collisionDirection = "None"; // 衝突の方向

	Collision() : canMoveRight(true), canMoveLeft(true), isColliding(false), collisionDirection("None") {} // コンストラクタ

	void checkCollision(Object obj1, Object obj2); // 当たり判定をチェックし、フラグを更新
};