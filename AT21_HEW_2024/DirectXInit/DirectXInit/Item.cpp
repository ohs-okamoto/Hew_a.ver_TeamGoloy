#include "Item.h"

// 2025/01/20 �S���C
Item::Item(int id):id(id) { // �R���X�g���N�^

}

Item::~Item() { // �f�X�g���N�^

}

void Item::ItemGet(int item) { // �A�C�e�������
	if (!QueueFull()) { // �L���[�����t���ᖳ����΁E�E�E

		id = item; // �A�C�e����ϐ��uid�v�̒��ɓ����
		itemQueue.push(id); // �L���[�ɒǉ�
	}
	else {}
}

void Item::ItemRelease() { // �A�C�e�������o��
	itemQueue.pop(); // �L���[�̐擪�̃A�C�e�������o���폜
}

bool Item::QueueFull() const { // �L���[�����t���ǂ������m�F
	return itemQueue.size() >= MAX_ITEMS;
}

void Item::ItemEffect() { // �A�C�e������

}