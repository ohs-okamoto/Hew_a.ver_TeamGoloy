#pragma once
#include "Object.h"

// 2024/12/22 作成者　ゴロイ

class Collision :public Object {

public:

	bool square_square(Object obj1, Object obj2); // 四角形と四角形の当たり判定
	bool circle_circle(Object obj1, Object obj2); // 円と円の当たり判定

};