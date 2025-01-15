#pragma once
#include "Object.h"
#include "input.h"
#include "Texture.h"

#define image		(10)

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
	Object tree;//��
	Object rock[image];//����
	Object icicle[image];//��
	Object stairs[image];//�K�i

	Object snowman[image];//�Ⴞ���
	Object tonakai;//�g�i�J�C
	Object star_monster;//����@�G
	
	Object present[image];//�v���[���g
	Object goal;//�S�[��

	bool changeRight = true;//�L������
	bool changeLeft = true;//


	int changescene = TITLE;//�V�[��
	int framcount = 0;
	Input input; //����

public:
	void Init(HWND hWnd);//������
	void Update(void);//�X�V
	void Draw();//�`��
	void Uninit();//�I��

	DirectX::XMFLOAT3 GetSantaPos()const; // �T���^�̈ʒu���擾���郁�\�b�h
	const Object& GetSanta() const; // �T���^�I�u�W�F�N�g�ւ̎Q�Ƃ��擾���郁�\�b�h

	DirectX::XMFLOAT3 GetGroundPos(int index)const;
	const Object& GetGround(int index) const; // �n�ʃI�u�W�F�N�g�ւ̎Q�Ƃ��擾����
};

