#pragma once
#include "Object.h"
#include "input.h"

#define image		(4)

enum SceneName {
	TITLE,
	STAGE_1,
	RESULT
};

class Game
{
private:
	Object background;//�v���C���[�I�u�W�F�N�g
	Object titlesanta;//�^�C�g��
	Object title;//�^�C�g��

	Object santa;//�T���^�I�u�W�F�N�g
	Object mounten[image];//�Q�[����ʂ̔w�i�ɂ���R
	Object wood[image];//�Q�[����ʂ̔w�i�ɂ����
	Object ground[image];//�n��
	Object star;//��
	Object sky;//��
	Object tree;


	int changescene = TITLE;//�V�[��
	int framcount = 0;
	Input input; //����

public:
	void Init(HWND hWnd);//������
	void Update(void);//�X�V
	void Draw();//�`��
	void Uninit();//�I��

	// ���݂̈ʒu���擾���郁�\�b�h 
	DirectX::XMFLOAT3 GetSantaPos() const { return santa.GetPos(); } // �T���^�̈ʒu���擾���郁�\�b�h
};

