#pragma once
#include "Object.h"
#include "input.h"
class Game
{
private:
	Object player;//�v���C���[�I�u�W�F�N�g
	Object background;//�v���C���[�I�u�W�F�N�g
	Input input; //����

public:
	void Init(HWND hWnd);//������
	void Update(void);//�X�V
	void Draw();//�`��
	void Uninit();//�I��


};

