#pragma once
//���{�䍂�@2024/12/28 19:41

class SANTA
{
public:
	SANTA();
	~SANTA();
	void Move(); //����
	void BagAvility(); //�o�b�O�̔\�͔����֐�
	void Collectitem();//�o�b�O�̒��g

	void Init();
	void Updata();
	
private:
	int score;//�N���A�^�C���i�[�ϐ�
	int timeLife;//�T���^��HP
};

