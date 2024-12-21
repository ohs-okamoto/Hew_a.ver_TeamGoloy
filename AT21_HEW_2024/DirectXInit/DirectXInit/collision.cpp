#include "Collision.h"

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
