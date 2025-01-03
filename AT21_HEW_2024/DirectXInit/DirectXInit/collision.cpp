#include "Collision.h"
#include <iostream>
using namespace std;

// 2024/12/22 作成者　ゴロイ


// 四角形と四角形の当たり判定
bool Collision::square_square(Object obj1, Object obj2)
{
	float coord1 = 0.0f, coord2 = 0.0f;

	// 1の右端と2の左端
	coord1 = obj1.GetPos().x + obj1.GetSize().x / 2.0f;
	coord2 = obj2.GetPos().x - obj2.GetSize().x / 2.0f;
	if (coord1 < coord2) { return false; } // 1の右端<2の左端　当たってないので判定終了

	// 1の右端と2の左端
	coord1 = obj1.GetPos().x - obj1.GetSize().x / 2.0f;
	coord2 = obj2.GetPos().x + obj2.GetSize().x / 2.0f;
	if (coord1 > coord2) { return false; } // 1の左端>2の右端　当たってないので判定終了

	// 1の下端と2の上端
	coord1 = obj1.GetPos().y + obj1.GetSize().y / 2.0f;
	coord2 = obj2.GetPos().y - obj2.GetSize().y / 2.0f;
	if (coord1 < coord2) { return false; } // 1の下端<2の上端　当たってないので判定終了

	// 1の上端と2の下端
	coord1 = obj1.GetPos().y - obj1.GetSize().y / 2.0f;
	coord2 = obj2.GetPos().y + obj2.GetSize().y / 2.0f;
	if (coord1 > coord2) { return false; } // 1の下端>2の上端　当たってないので判定終了

	// ここまでたどり着いたら、当たっている
	return true;
}

bool Collision::ground_santa(Object obj1, Object obj2,float bufferX,float bufferY)
{
    float coord1 = 0.0f, coord2 = 0.0f;
    isColliding = false; // 初期化
    collisionDirection = "None";

    // 1の右端と2の左端
    coord1 = obj1.GetPos().x + (obj1.GetSize().x - bufferX) / 2.0f;
    coord2 = obj2.GetPos().x - obj2.GetSize().x / 2.0f;
    if (coord1 < coord2) {
        collisionDirection = "　";
        return false; } // 1の右端<2の左端　当たってないので判定終了


    // 1の左端と2の右端
    coord1 = obj1.GetPos().x - (obj1.GetSize().x - bufferX) / 2.0f;
    coord2 = obj2.GetPos().x + obj2.GetSize().x / 2.0f;
    if (coord1 > coord2) {
        collisionDirection = "　";
        return false; } // 1の左端>2の右端　当たってないので判定終了

    // 1の下端と2の上端
    coord1 = obj1.GetPos().y + (obj1.GetSize().y - bufferY) / 2.0f;
    coord2 = obj2.GetPos().y - obj2.GetSize().y / 2.0f;
    if (coord1 < coord2) {
        collisionDirection = "　";
        return false; } // 1の下端<2の上端　当たってないので判定終了

    // 1の上端と2の下端
    coord1 = obj1.GetPos().y - (obj1.GetSize().y - bufferY) / 2.0f;
    coord2 = obj2.GetPos().y + obj2.GetSize().y / 2.0f;
    if (coord1 > coord2) {
        collisionDirection = "　";
        return false; } // 1の上端>2の下端　当たってないので判定終了

    // ここまでたどり着いたら、当たっている

    isColliding = true; // 当たり判定があったことをフラグで示す

    // 衝突の方向を判定
    if (obj1.GetPos().y < obj2.GetPos().y) {
        collisionDirection = "↑";
    }
    else if (obj1.GetPos().x < obj2.GetPos().x) {
        collisionDirection = "→";
    }
    else if (obj1.GetPos().x > obj2.GetPos().x) {
        collisionDirection = "←";
    }
    else {
        collisionDirection = "↓";
    }

    return true;
}

bool Collision::tree_santa(Object obj1, Object obj2, float bufferX, float bufferY)
{
    float coord1 = 0.0f, coord2 = 0.0f;
    /*float buffer = 50.0f;*/  // 特定のオブジェクトの当たり判定を縮小するためのバッファ

    // 1の右端と2の左端
    coord1 = obj1.GetPos().x + (obj1.GetSize().x - bufferX) / 2.0f;
    coord2 = obj2.GetPos().x - obj2.GetSize().x / 2.0f;
    if (coord1 < coord2) {
        std::cout << "\nNo collision on the right side." << std::endl;
        return false;
    } // 1の右端<2の左端　当たってないので判定終了


// 1の左端と2の右端
    coord1 = obj1.GetPos().x - (obj1.GetSize().x - bufferX) / 2.0f;
    coord2 = obj2.GetPos().x + obj2.GetSize().x / 2.0f;
    if (coord1 > coord2) {
        std::cout << "\nNo collision on the left side." << std::endl;
        return false;
    } // 1の左端>2の右端　当たってないので判定終了

// 1の下端と2の上端
    coord1 = obj1.GetPos().y + (obj1.GetSize().y - bufferY) / 2.0f;
    coord2 = obj2.GetPos().y - obj2.GetSize().y / 2.0f;
    if (coord1 < coord2) {
        std::cout << "\nNo collision on the bottom side." << std::endl;
        return false;
    } // 1の下端<2の上端　当たってないので判定終了

// 1の上端と2の下端
    coord1 = obj1.GetPos().y - (obj1.GetSize().y - bufferY) / 2.0f;
    coord2 = obj2.GetPos().y + obj2.GetSize().y / 2.0f;
    if (coord1 > coord2) {
        std::cout << "No collision on the top side." << std::endl;
        return false;
    } // 1の上端>2の下端　当たってないので判定終了

// ここまでたどり着いたら、当たっている
    std::cout << "当たっています。" << std::endl;
    return true;
}