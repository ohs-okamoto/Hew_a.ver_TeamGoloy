#include "Collision.h"

// 2024/12/22 �쐬�ҁ@�S���C


// �l�p�`�Ǝl�p�`�̓����蔻��
bool Collision::square_square(Object obj1, Object obj2)
{
	float coord1 = 0.0f, coord2 = 0.0f;

	// 1�̉E�[��2�̍��[
	coord1 = obj1.GetPos().x + obj1.GetSize().x / 2.0f;
	coord2 = obj2.GetPos().x - obj2.GetSize().x / 2.0f;
	if (coord1 < coord2) { return false; } // 1�̉E�[<2�̍��[�@�������ĂȂ��̂Ŕ���I��

	// 1�̉E�[��2�̍��[
	coord1 = obj1.GetPos().x - obj1.GetSize().x / 2.0f;
	coord2 = obj2.GetPos().x + obj2.GetSize().x / 2.0f;
	if (coord1 > coord2) { return false; } // 1�̍��[>2�̉E�[�@�������ĂȂ��̂Ŕ���I��

	// 1�̉��[��2�̏�[
	coord1 = obj1.GetPos().y + obj1.GetSize().y / 2.0f;
	coord2 = obj2.GetPos().y - obj2.GetSize().y / 2.0f;
	if (coord1 < coord2) { return false; } // 1�̉��[<2�̏�[�@�������ĂȂ��̂Ŕ���I��

	// 1�̏�[��2�̉��[
	coord1 = obj1.GetPos().y - obj1.GetSize().y / 2.0f;
	coord2 = obj2.GetPos().y + obj2.GetSize().y / 2.0f;
	if (coord1 > coord2) { return false; } // 1�̉��[>2�̏�[�@�������ĂȂ��̂Ŕ���I��

	// �����܂ł��ǂ蒅������A�������Ă���
	return true;
}
