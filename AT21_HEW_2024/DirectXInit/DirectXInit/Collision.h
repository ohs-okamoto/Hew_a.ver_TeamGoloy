#pragma once
#include "Object.h"
#include <string>

// 2024/12/22 �쐬�ҁ@�S���C

class Collision :public Object {

public:

	bool square_square(Object obj1, Object obj2); // �l�p�`�Ǝl�p�`�̓����蔻��
	bool ground_santa(Object obj1, Object obj2, float bufferX, float bufferY); // �n�ʂƃT���^�̓����蔻��
	bool tree_santa(Object obj1, Object obj2, float bufferX, float bufferY); // �n�ʂƃT���^�̓����蔻��
	bool goal_santa(Object obj1, Object obj2, float bufferX, float bufferY); // �S�[���ƃT���^�̓����蔻��
	bool circle_circle(Object obj1, Object obj2); // �~�Ɖ~�̓����蔻��
	
	bool canMoveRight = true; // �E�Ɉړ��ł��邩�ǂ���
	bool canMoveLeft = true;  // ���Ɉړ��ł��邩�ǂ���
	bool isColliding = false;  // �����蔻�茋�ʂ�ێ�����t���O
	std::string collisionDirection = "None"; // �Փ˂̕���

	Collision() : canMoveRight(true), canMoveLeft(true), isColliding(false), collisionDirection("None") {} // �R���X�g���N�^

	void checkCollision(Object obj1, Object obj2); // �����蔻����`�F�b�N���A�t���O���X�V
};