#pragma once
#include <queue>

// 2025/01/20 �S���C
class Item {
public:
	Item(int id); // �R���X�g���N�^
	~Item(); // �f�X�g���N�^
	
	void ItemGet(int item); // �A�C�e�������
	void ItemRelease(); // �A�C�e�������o��
	void ItemEffect(); // �A�C�e��������
	bool QueueFull() const; // �L���[�����t���ǂ������m�F
private:
	int item; // �A�C�e���̎��
	static const int MAX_ITEMS = 3; // �ő�A�C�e����
	int id; // �L���[�ɓ����p�̒l
	std::queue<int> itemQueue; // �A�C�e�����i�[����L���[
};