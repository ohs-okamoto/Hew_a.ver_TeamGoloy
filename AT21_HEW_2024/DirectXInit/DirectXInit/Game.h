#pragma once
#include "Object.h"
#include "input.h"
#include "Texture.h"
#include "Item.h"

#define image		(10)

enum SceneName {
	TITLE,
	STAGE1_LOADING,
	STAGE_1,
	STAGE_2,
	RESULT
};

class Game
{
private:
	Object background;//�v���C���[�I�u�W�F�N�g
	Object titlesanta;//�^�C�g��
	Object title;//�^�C�g��

	Object Stage1_Loading;


	Object santa;//�T���^�I�u�W�F�N�g
	Object star;//��
	Object sky;//��
	Object mounten[image];//�Q�[����ʂ̔w�i�ɂ���R

	Object itemUi[9]; // �A�C�e�����莞��UI


	Object wood[image];//�Q�[����ʂ̔w�i�ɂ����
	Object ground[image];//�n��
	Object tree;//��
	Object rock[image];//����
	Object icicle[image];//��
	Object stairs[image];//�K�i

	Object snowman[image];//�Ⴞ���
	Object tonakai;//�g�i�J�C
	Object star_monster;//����@�G
	
	Object present[image];//�v���[���g
	Object BigPresent[image];//�v���[���g
	Object snowball[image];//���
	Object goal;//�S�[��


	//�X�e�[�W�Q�֘A
	Object Ground_Stge2[image];//�X�e�[�W�Q�̏�
	Object Tree_Stge2[image];//��
	Object Block_Stge2[image];//�u���b�N
	Object Icicles_Stge2[image];//���
	Object Stairs_Stge2[image];//�K�i
	Object Present_Stage2[image];//�v���[���g
	Object Breakrock_Stge2[image];//�󂹂��
	Object Collectrock_Stage2[image];



	bool changeRight = true;//�L������
	bool changeLeft = true;//


	int changescene = TITLE;//�V�[��

	int framcount = 0;
	int framcount2 = 0;

	bool moveFg1 = false;
	bool moveFg2= false;
	bool moveFg3 = false;
	bool moveFg4 = false;
	bool moveFg5 = false;

	bool asd = false;

	float speed = 0;

	Input input; //����

	

	int itemID;
	Item* item; //�����o�ϐ�


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

