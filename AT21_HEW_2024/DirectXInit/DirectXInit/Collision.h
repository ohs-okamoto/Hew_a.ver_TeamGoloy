#pragma once
#include "Object.h"

// 2024/12/22 �쐬�ҁ@�S���C

class Collision :public Object {

public:

	bool square_square(Object obj1, Object obj2); // �l�p�`�Ǝl�p�`�̓����蔻��
	bool ground_santa(Object obj1, Object obj2, float bufferX, float bufferY); // �n�ʂƃT���^�̓����蔻��
	bool tree_santa(Object obj1, Object obj2, float bufferX, float bufferY); // �n�ʂƃT���^�̓����蔻��
	bool circle_circle(Object obj1, Object obj2); // �~�Ɖ~�̓����蔻��
	
	bool canMoveRight = true; // �E�Ɉړ��ł��邩�ǂ���
	bool canMoveLeft = true;  // ���Ɉړ��ł��邩�ǂ���

	void checkCollision(Object obj1, Object obj2); // �����蔻����`�F�b�N���A�t���O���X�V
};