#pragma once
#include "Object.h"
#include "input.h"

#define image		(3)

enum SceneName {
	TITLE,
	STAGE_1,
	RESULT
};

class Game
{
private:
	Object player;//�v���C���[�I�u�W�F�N�g
	Object background;//�v���C���[�I�u�W�F�N�g

	Object santa;//�T���^�I�u�W�F�N�g
	Object mounten[image];//�Q�[����ʂ̔w�i�ɂ���R
	Object tree[image];//�Q�[����ʂ̔w�i�ɂ����
	Object ground[image];//�n��
	Object star;//��
	Object sky;//��


	int changescene = TITLE;//�V�[��

	Input input; //����

public:
	void Init(HWND hWnd);//������
	void Update(void);//�X�V
	void Draw();//�`��
	void Uninit();//�I��


};

