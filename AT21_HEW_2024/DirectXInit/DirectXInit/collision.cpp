#include "Collision.h"
#include <iostream>
using namespace std;

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

bool Collision::ground_santa(Object obj1, Object obj2,float bufferX,float bufferY)
{
    float coord1 = 0.0f, coord2 = 0.0f;
    isColliding = false; // ������
    collisionDirection = "None";

    // 1�̉E�[��2�̍��[
    coord1 = obj1.GetPos().x + (obj1.GetSize().x - bufferX) / 2.0f;
    coord2 = obj2.GetPos().x - obj2.GetSize().x / 2.0f;
    if (coord1 < coord2) {
        collisionDirection = "�@";
        return false; } // 1�̉E�[<2�̍��[�@�������ĂȂ��̂Ŕ���I��


    // 1�̍��[��2�̉E�[
    coord1 = obj1.GetPos().x - (obj1.GetSize().x - bufferX) / 2.0f;
    coord2 = obj2.GetPos().x + obj2.GetSize().x / 2.0f;
    if (coord1 > coord2) {
        collisionDirection = "�@";
        return false; } // 1�̍��[>2�̉E�[�@�������ĂȂ��̂Ŕ���I��

    // 1�̉��[��2�̏�[
    coord1 = obj1.GetPos().y + (obj1.GetSize().y - bufferY) / 2.0f;
    coord2 = obj2.GetPos().y - obj2.GetSize().y / 2.0f;
    if (coord1 < coord2) {
        collisionDirection = "�@";
        return false; } // 1�̉��[<2�̏�[�@�������ĂȂ��̂Ŕ���I��

    // 1�̏�[��2�̉��[
    coord1 = obj1.GetPos().y - (obj1.GetSize().y - bufferY) / 2.0f;
    coord2 = obj2.GetPos().y + obj2.GetSize().y / 2.0f;
    if (coord1 > coord2) {
        collisionDirection = "�@";
        return false; } // 1�̏�[>2�̉��[�@�������ĂȂ��̂Ŕ���I��

    // �����܂ł��ǂ蒅������A�������Ă���

    isColliding = true; // �����蔻�肪���������Ƃ��t���O�Ŏ���

    // �Փ˂̕����𔻒�
    if (obj1.GetPos().y < obj2.GetPos().y) {
        collisionDirection = "��";
    }
    else if (obj1.GetPos().x < obj2.GetPos().x) {
        collisionDirection = "��";
    }
    else if (obj1.GetPos().x > obj2.GetPos().x) {
        collisionDirection = "��";
    }
    else {
        collisionDirection = "��";
    }

    return true;
}

bool Collision::tree_santa(Object obj1, Object obj2, float bufferX, float bufferY)
{
    float coord1 = 0.0f, coord2 = 0.0f;
    /*float buffer = 50.0f;*/  // ����̃I�u�W�F�N�g�̓����蔻����k�����邽�߂̃o�b�t�@

    // 1�̉E�[��2�̍��[
    coord1 = obj1.GetPos().x + (obj1.GetSize().x - bufferX) / 2.0f;
    coord2 = obj2.GetPos().x - obj2.GetSize().x / 2.0f;
    if (coord1 < coord2) {
        std::cout << "\nNo collision on the right side." << std::endl;
        return false;
    } // 1�̉E�[<2�̍��[�@�������ĂȂ��̂Ŕ���I��


// 1�̍��[��2�̉E�[
    coord1 = obj1.GetPos().x - (obj1.GetSize().x - bufferX) / 2.0f;
    coord2 = obj2.GetPos().x + obj2.GetSize().x / 2.0f;
    if (coord1 > coord2) {
        std::cout << "\nNo collision on the left side." << std::endl;
        return false;
    } // 1�̍��[>2�̉E�[�@�������ĂȂ��̂Ŕ���I��

// 1�̉��[��2�̏�[
    coord1 = obj1.GetPos().y + (obj1.GetSize().y - bufferY) / 2.0f;
    coord2 = obj2.GetPos().y - obj2.GetSize().y / 2.0f;
    if (coord1 < coord2) {
        std::cout << "\nNo collision on the bottom side." << std::endl;
        return false;
    } // 1�̉��[<2�̏�[�@�������ĂȂ��̂Ŕ���I��

// 1�̏�[��2�̉��[
    coord1 = obj1.GetPos().y - (obj1.GetSize().y - bufferY) / 2.0f;
    coord2 = obj2.GetPos().y + obj2.GetSize().y / 2.0f;
    if (coord1 > coord2) {
        std::cout << "No collision on the top side." << std::endl;
        return false;
    } // 1�̏�[>2�̉��[�@�������ĂȂ��̂Ŕ���I��

// �����܂ł��ǂ蒅������A�������Ă���
    std::cout << "�������Ă��܂��B" << std::endl;
    return true;
}