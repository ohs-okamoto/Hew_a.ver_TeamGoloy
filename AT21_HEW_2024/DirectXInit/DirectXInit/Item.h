#pragma once
#include <queue>
#include <vector>
#include <iostream>
#include "Object.h"
using namespace std;

// 2025/01/20 �S���C
class Item :public Object{
public:
	Item(int id); // �R���X�g���N�^
	~Item(); // �f�X�g���N�^
	Object itemUi[3]; // �A�C�e�����莞��UI
	void Init(const wchar_t* texturePath); // texturePath �������Ɏ�� Init �֐��̐錾

	void ItemGet(int item); // �A�C�e�������
	void ItemRelease(); // �A�C�e�������o��
	int ItemEffect(); // �A�C�e��������
	bool QueueFull() const; // �L���[�����t���ǂ������m�F
	
	void GetQueue() ; // �L���[�̒��g���擾����֐�


	int GetItem_1() ;
	int GetItem_2() const;
	int GetItem_3() const;

	int GetItemCnt() const; // �A�C�e���̌���Ԃ����
private:
	int item; // �A�C�e���̎��
	static const int MAX_ITEMS = 3; // �ő�A�C�e����
	int id; // �L���[�ɓ����p�̒l
	std::queue<int> itemQueue; // �A�C�e�����i�[����L���[
	
	int item1,item2,item3;

	int bugPower; // �܂̗�

	int bug1, bug2, bug3; //���蓖��
};