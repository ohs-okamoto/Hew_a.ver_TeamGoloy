#pragma once
#include "Object.h"

// 2024/12/22 �쐬�ҁ@�S���C

class Collision :public Object {

public:

	bool square_square(Object obj1, Object obj2); // �l�p�`�Ǝl�p�`�̓����蔻��
	bool circle_circle(Object obj1, Object obj2); // �~�Ɖ~�̓����蔻��

};