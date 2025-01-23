#include "Item.h"

// 2025/01/20 �S���C
Item::Item(int id):id(id),bug1(0),bug2(0),bug3(0) { // �R���X�g���N�^


}

Item::~Item() { // �f�X�g���N�^

}



void Item::ItemGet(int item) { // �A�C�e�������
	if (!QueueFull()) { // �L���[�����t���ᖳ����΁E�E�E

		id = item; // �A�C�e����ϐ��uid�v�̒��ɓ����
		itemQueue.push(id); // �L���[�ɒǉ�

		GetQueue();
	}
	else {}
}

void Item::ItemRelease() { // �A�C�e�������o��
	if (!itemQueue.empty())
	{
		itemQueue.pop(); // �L���[�̐擪�̃A�C�e�������o���폜
		GetQueue();
	}
}

bool Item::QueueFull() const { // �L���[�����t���ǂ������m�F
	return itemQueue.size() >= MAX_ITEMS;
}

void Item::ItemEffect() { // �A�C�e������

}

void Item::GetQueue(){
	std::queue<int> copyQueue = itemQueue; // �L���[���R�s�[
	std::vector<int> elements;             // �R�s�[�̓��e��ێ�����vector

	// �L���[�̓��e���x�N�^�[�Ɉڂ�
	while (!copyQueue.empty()) {
		elements.push_back(copyQueue.front());
		copyQueue.pop();
	}

	if (elements.size() >= 1) {
		bug1 = elements[0];
	}
	else {
		bug1 = -1; // �f�t�H���g�l
	}
	if (elements.size() >= 2) {
		bug2 = elements[1];
	}
	else {
		bug2 = -1; // �f�t�H���g�l
	}
	if (elements.size() >= 3) {
		bug3 = elements[2];
	}
	else {
		bug3 = -1; // �f�t�H���g�l
	}
	

	
}

//void Item::SetItem_1() {
//	item1 = bug1;
//}
//void Item::SetItem_2(int bug2) {
//	item2 = bug2;
//}
//void Item::SetItem_3(int bug3) {
//	item3 = bug3;
//}


int Item::GetItem_1() {
	return bug1;
}

int Item::GetItem_2() const{
	return bug2;
}

int Item::GetItem_3() const{
	return bug3;
}