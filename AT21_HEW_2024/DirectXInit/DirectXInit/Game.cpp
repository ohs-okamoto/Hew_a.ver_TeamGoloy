#include "Game.h"


void Game::Init(HWND hWnd)
{
	D3D_Create(hWnd);//Directx��������
	player.Init(L"asset/char01.png",3,4);//�v���C���[��������
	player.SetPos(100.0f, 0.0f, 0.0f);		//�ʒu��ݒ�
	player.SetSize(200.0f, 300.0f, 0.f);	//�傫����ݒ�
	player.SetAngle(0.0f);             		//�p�x��ݒ�
	player.SetColor(1.0f, 1.0f, 1.0f, 1.0f); //�F��ݒ�

	background.Init(L"asset/background.png",1,1);//�v���C���[��������
	background.SetPos(0.0f, 0.0f, 0.0f);         //�ʒu��ݒ�
	background.SetSize(640.0f, 480.0f, 0.f);     //�傫���ݒ�
	background.SetAngle(0.0f);//�p�x��ݒ�	    
}

void Game::Update(void) {
	input.Update();

	DirectX::XMFLOAT3 pos = player.GetPos();
	pos.x = 1.0f; //�l���X�V
	player.SetPos(pos.x, pos.y, pos.z);

	//�l�X�V���鏈���̌�ɓ��͏������L�q���邱�� by�ق���
}

void Game::Draw(void)
{
	D3D_StartRender();//�`��J�n
	background.Draw();//�v���C���[�`��
	player.Draw();//�v���C���[�`��
	D3D_FinishRender();//�`��I��
}

void Game::Uninit(void)
{
	player.Uninit();//�v���C���[�I��
	background.Uninit();//�v���C���[�I��
	
	// DirectX�̉������
	D3D_Release();//DirextX���I��
}