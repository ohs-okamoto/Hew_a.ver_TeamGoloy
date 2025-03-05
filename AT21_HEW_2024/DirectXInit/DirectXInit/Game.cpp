#include "Game.h"
#include "Texture.h"
#include "Collision.h"
#include "Item.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
using namespace std;

//2024�N12/24 ���X�N���[�� �쐬�@�l��
//2024�N12/31  �X�e�[�W�P�쐬 �@�l��



void Game::Init(HWND hWnd)
{
	D3D_Create(hWnd);//Directx��������
	sound.Init();//�T�E���h��������
	//====================================================
	//�v���C���[�֘A
	//====================================================
	
	// �ʏ��
	santa_Nor[0].Init(L"asset/Santa_Normal_Move_v2.png", 4, 4);//�T���^��������
	santa_Nor[0].SetPos(-400.0f, -175.0f, 0.0f);		//�ʒu��ݒ�
	santa_Nor[0].SetSize(150.0f, 120.0f, 0.f);	//�傫����ݒ�
	santa_Nor[0].SetAngle(0.0f);             		//�p�x��ݒ�
	santa_Nor[0].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //�F��ݒ�

	santa_Nor[1].Init(L"asset/Santa_Normal_Pack_Move_v4.png", 4, 4);//�T���^��������
	santa_Nor[1].SetPos(-400.0f, -175.0f, 0.0f);		//�ʒu��ݒ�
	santa_Nor[1].SetSize(150.0f, 120.0f, 0.f);	//�傫����ݒ�
	santa_Nor[1].SetAngle(0.0f);             		//�p�x��ݒ�
	santa_Nor[1].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //�F��ݒ�

	santa_Nor[2].Init(L"asset/Santa_Normal_Jump_v2.png", 1, 2);//�T���^��������
	santa_Nor[2].SetPos(-400.0f, -175.0f, 0.0f);		//�ʒu��ݒ�
	santa_Nor[2].SetSize(150.0f, 120.0f, 0.f);	//�傫����ݒ�
	santa_Nor[2].SetAngle(0.0f);             		//�p�x��ݒ�
	santa_Nor[2].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //�F��ݒ�

	santa_Nor[3].Init(L"asset/Santa_Normal_Pack_Jump_v2.png", 1, 2);//�T���^��������
	santa_Nor[3].SetPos(-400.0f, -175.0f, 0.0f);		//�ʒu��ݒ�
	santa_Nor[3].SetSize(150.0f, 120.0f, 0.f);	//�傫����ݒ�
	santa_Nor[3].SetAngle(0.0f);             		//�p�x��ݒ�
	santa_Nor[3].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //�F��ݒ�

	santa_Nor[4].Init(L"asset/Santa_Normal_In_v2.png", 5, 2);//�T���^��������
	santa_Nor[4].SetPos(-400.0f, -175.0f, 0.0f);		//�ʒu��ݒ�
	santa_Nor[4].SetSize(150.0f, 120.0f, 0.f);	//�傫����ݒ�
	santa_Nor[4].SetAngle(0.0f);             		//�p�x��ݒ�
	santa_Nor[4].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //�F��ݒ�

	santa_Nor[5].Init(L"asset/Santa_Normal_Out_v2.png", 5, 2);//�T���^��������
	santa_Nor[5].SetPos(-400.0f, -175.0f, 0.0f);		//�ʒu��ݒ�
	santa_Nor[5].SetSize(150.0f, 120.0f, 0.f);	//�傫����ݒ�
	santa_Nor[5].SetAngle(0.0f);             		//�p�x��ݒ�
	santa_Nor[5].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //�F��ݒ�

	santa_Nor[6].Init(L"asset/Santa_Normal_SP_v2.png", 4, 2);//�T���^��������
	santa_Nor[6].SetPos(-400.0f, -175.0f, 0.0f);		//�ʒu��ݒ�
	santa_Nor[6].SetSize(150.0f, 120.0f, 0.f);	//�傫����ݒ�
	santa_Nor[6].SetAngle(0.0f);             		//�p�x��ݒ�
	santa_Nor[6].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //�F��ݒ�

	santa_Nor[7].Init(L"asset/Santa_Normal_Pack_SP_v2.png", 5, 2);//�T���^��������
	santa_Nor[7].SetPos(-400.0f, -175.0f, 0.0f);		//�ʒu��ݒ�
	santa_Nor[7].SetSize(150.0f, 120.0f, 0.f);	//�傫����ݒ�
	santa_Nor[7].SetAngle(0.0f);             		//�p�x��ݒ�
	santa_Nor[7].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //�F��ݒ�
	santa_Nor[7].SetATK(2);

	// ���C�~
	santa_Huro[0].Init(L"asset/Santa_Huro_Move_v2.png", 4, 4);//�T���^��������
	santa_Huro[0].SetPos(-400.0f, -175.0f, 0.0f);		//�ʒu��ݒ�
	santa_Huro[0].SetSize(150.0f, 120.0f, 0.f);	//�傫����ݒ�
	santa_Huro[0].SetAngle(0.0f);             		//�p�x��ݒ�
	santa_Huro[0].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //�F��ݒ�

	santa_Huro[1].Init(L"asset/Santa_Huro_Pack_Move_v2.png", 4, 4);//�T���^��������
	santa_Huro[1].SetPos(-400.0f, -175.0f, 0.0f);		//�ʒu��ݒ�
	santa_Huro[1].SetSize(150.0f, 120.0f, 0.f);	//�傫����ݒ�
	santa_Huro[1].SetAngle(0.0f);             		//�p�x��ݒ�
	santa_Huro[1].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //�F��ݒ�

	santa_Huro[2].Init(L"asset/Santa_Huro_Jump_v2.png", 1, 2);//�T���^��������
	santa_Huro[2].SetPos(-400.0f, -175.0f, 0.0f);		//�ʒu��ݒ�
	santa_Huro[2].SetSize(150.0f, 120.0f, 0.f);	//�傫����ݒ�
	santa_Huro[2].SetAngle(0.0f);             		//�p�x��ݒ�
	santa_Huro[2].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //�F��ݒ�

	santa_Huro[3].Init(L"asset/Santa_Huro_Pack_Jump_v2.png", 1, 2);//�T���^��������
	santa_Huro[3].SetPos(-400.0f, -175.0f, 0.0f);		//�ʒu��ݒ�
	santa_Huro[3].SetSize(150.0f, 120.0f, 0.f);	//�傫����ݒ�
	santa_Huro[3].SetAngle(0.0f);             		//�p�x��ݒ�
	santa_Huro[3].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //�F��ݒ�

	santa_Huro[4].Init(L"asset/Santa_Huro_In_v2.png", 5, 2);//�T���^��������
	santa_Huro[4].SetPos(-400.0f, -175.0f, 0.0f);		//�ʒu��ݒ�
	santa_Huro[4].SetSize(150.0f, 120.0f, 0.f);	//�傫����ݒ�
	santa_Huro[4].SetAngle(0.0f);             		//�p�x��ݒ�
	santa_Huro[4].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //�F��ݒ�

	santa_Huro[5].Init(L"asset/Santa_Huro_Out_v2.png", 5, 2);//�T���^��������
	santa_Huro[5].SetPos(-400.0f, -175.0f, 0.0f);		//�ʒu��ݒ�
	santa_Huro[5].SetSize(150.0f, 120.0f, 0.f);	//�傫����ݒ�
	santa_Huro[5].SetAngle(0.0f);             		//�p�x��ݒ�
	santa_Huro[5].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //�F��ݒ�

	santa_Huro[6].Init(L"asset/Santa_Huro_SP.png", 5, 2);//�T���^��������
	santa_Huro[6].SetPos(-400.0f, -175.0f, 0.0f);		//�ʒu��ݒ�
	santa_Huro[6].SetSize(150.0f, 120.0f, 0.f);	//�傫����ݒ�
	santa_Huro[6].SetAngle(0.0f);             		//�p�x��ݒ�
	santa_Huro[6].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //�F��ݒ�

	santa_Huro[7].Init(L"asset/Santa_Huro_Pack_SP.png", 5, 2);//�T���^��������
	santa_Huro[7].SetPos(-400.0f, -175.0f, 0.0f);		//�ʒu��ݒ�
	santa_Huro[7].SetSize(150.0f, 120.0f, 0.f);	//�傫����ݒ�
	santa_Huro[7].SetAngle(0.0f);             		//�p�x��ݒ�
	santa_Huro[7].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //�F��ݒ�

	// �В���
	santa_Kin[0].Init(L"asset/Santa_Kin_Move_v2.png", 4, 4);//�T���^��������
	santa_Kin[0].SetPos(-400.0f, -175.0f, 0.0f);		//�ʒu��ݒ�
	santa_Kin[0].SetSize(150.0f, 120.0f, 0.f);	//�傫����ݒ�
	santa_Kin[0].SetAngle(0.0f);             		//�p�x��ݒ�
	santa_Kin[0].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //�F��ݒ�

	santa_Kin[1].Init(L"asset/Santa_Kin_Pack_Move_v2.png", 4, 4);//�T���^��������
	santa_Kin[1].SetPos(-400.0f, -175.0f, 0.0f);		//�ʒu��ݒ�
	santa_Kin[1].SetSize(150.0f, 120.0f, 0.f);	//�傫����ݒ�
	santa_Kin[1].SetAngle(0.0f);             		//�p�x��ݒ�
	santa_Kin[1].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //�F��ݒ�

	santa_Kin[2].Init(L"asset/Santa_Kin_Jump_v2.png", 1, 2);//�T���^��������
	santa_Kin[2].SetPos(-400.0f, -175.0f, 0.0f);		//�ʒu��ݒ�
	santa_Kin[2].SetSize(150.0f, 120.0f, 0.f);	//�傫����ݒ�
	santa_Kin[2].SetAngle(0.0f);             		//�p�x��ݒ�
	santa_Kin[2].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //�F��ݒ�

	santa_Kin[3].Init(L"asset/Santa_Kin_Pack_Jump_v2.png", 1, 2);//�T���^��������
	santa_Kin[3].SetPos(-400.0f, -175.0f, 0.0f);		//�ʒu��ݒ�
	santa_Kin[3].SetSize(150.0f, 120.0f, 0.f);	//�傫����ݒ�
	santa_Kin[3].SetAngle(0.0f);             		//�p�x��ݒ�
	santa_Kin[3].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //�F��ݒ�

	santa_Kin[4].Init(L"asset/Santa_Kin_In_v2.png", 5, 2);//�T���^��������
	santa_Kin[4].SetPos(-400.0f, -175.0f, 0.0f);		//�ʒu��ݒ�
	santa_Kin[4].SetSize(150.0f, 120.0f, 0.f);	//�傫����ݒ�
	santa_Kin[4].SetAngle(0.0f);             		//�p�x��ݒ�
	santa_Kin[4].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //�F��ݒ�

	santa_Kin[5].Init(L"asset/Santa_Kin_Out_v2.png", 5, 2);//�T���^��������
	santa_Kin[5].SetPos(-400.0f, -175.0f, 0.0f);		//�ʒu��ݒ�
	santa_Kin[5].SetSize(150.0f, 120.0f, 0.f);	//�傫����ݒ�
	santa_Kin[5].SetAngle(0.0f);             		//�p�x��ݒ�
	santa_Kin[5].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //�F��ݒ�

	santa_Kin[6].Init(L"asset/Santa_Kin_SP.png", 3, 2);//�T���^��������
	santa_Kin[6].SetPos(-400.0f, -175.0f, 0.0f);		//�ʒu��ݒ�
	santa_Kin[6].SetSize(150.0f, 120.0f, 0.f);	//�傫����ݒ�
	santa_Kin[6].SetAngle(0.0f);             		//�p�x��ݒ�
	santa_Kin[6].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //�F��ݒ�

	hitbox.Init(L"asset/yukidama.png", 1, 1);//�T���^��������
	hitbox.SetPos(-400.0f, -175.0f, 0.0f);		//�ʒu��ݒ�
	hitbox.SetSize(80.0f, 80.0f, 0.f);	//�傫����ݒ�
	hitbox.SetAngle(0.0f);

	hitbox2.Init(L"asset/yukidama.png", 1, 1);//�T���^��������
	hitbox2.SetPos(-400.0f, -175.0f, 0.0f);		//�ʒu��ݒ�
	hitbox2.SetSize(80.0f, 80.0f, 0.f);	//�傫����ݒ�
	hitbox2.SetAngle(0.0f);

	//====================================================
	//�В��̂��
	//====================================================
	kintyaku[0].Init(L"asset/Kintyaku_SP.png", 1, 2);//�T���^��������
	kintyaku[0].SetPos(-400.0f, -175.0f, 0.0f);		//�ʒu��ݒ�
	kintyaku[0].SetSize(100.0f, 25.0f, 0.f);	//�傫����ݒ�
	kintyaku[0].SetAngle(0.0f);             		//�p�x��ݒ�

	kintyaku[1].Init(L"asset/Kintyaku_Pack_SP.png", 1, 2);//�T���^��������
	kintyaku[1].SetPos(-400.0f, -175.0f, 0.0f);		//�ʒu��ݒ�
	kintyaku[1].SetSize(100.0f, 50.0f, 0.f);	//�傫����ݒ�
	kintyaku[1].SetAngle(0.0f);

	himo.Init(L"asset/Kintyaku_Himo.png",1,1);//�T���^��������
	himo.SetPos(-400.0f, -175.0f, 0.0f);		//�ʒu��ݒ�
	himo.SetSize(10.0f, 120.0f, 0.f);	//�傫����ݒ�
	himo.SetAngle(0.0f);
	
	//====================================================
	//�^�C�g��
	//====================================================
	title.Init(L"asset/Main_Rogo.png", 1, 1);//�T���^��������
	title.SetPos(250.0f, 100.0f, 0.0f);		//�ʒu��ݒ�
	title.SetSize(650.0f, 550.0f, 0.f);	//�傫����ݒ�
	title.SetAngle(0.0f);             		//�p�x��ݒ�
	title.SetColor(1.0f, 1.0f, 1.0f, 1.0f); //�F��ݒ�

	PressBbotton.Init(L"asset/preb.png", 1, 1);//�T���^��������
	PressBbotton.SetPos(250.0f, -200.0f, 0.0f);		//�ʒu��ݒ�
	PressBbotton.SetSize(550.0f, 400.0f, 0.f);	//�傫����ݒ�
	PressBbotton.SetAngle(0.0f);             		//�p�x��ݒ�
	PressBbotton.SetColor(1.0f, 1.0f, 1.0f, 1.0f); //�F��ݒ�

	titlesanta.Init(L"asset/Main_Ilust.png", 1, 1);//��������
	titlesanta.SetPos(0.0f, 0.0f, 0.0f);         //�ʒu��ݒ�
	titlesanta.SetSize(1280.0f, 720.0f, 0.f);     //�傫���ݒ�
	titlesanta.SetAngle(0.0f);//�p�x��ݒ�	    

	background.Init(L"asset/background.png", 1, 1);//�v���C���[��������
	background.SetPos(0.0f, 0.0f, 0.0f);         //�ʒu��ݒ�
	background.SetSize(1280.0f, 720.0f, 0.f);     //�傫���ݒ�
	background.SetAngle(0.0f);//�p�x��ݒ�	 

	//====================================================
	// �Z�N���g���
	//====================================================
	StegeSelect.Init(L"asset/Stageselect.png", 1, 1);//��������
	StegeSelect.SetPos(0.0f, 0.0f, 0.0f);         //�ʒu��ݒ�
	StegeSelect.SetSize(1280.0f, 720.0f, 0.f);     //�傫���ݒ�
	StegeSelect.SetAngle(0.0f);//�p�x��ݒ�	    

	SantaCursor.Init(L"asset/Santa_Normal_Pack_Move_v4.png", 4, 4);//��������
	SantaCursor.SetPos(-430.0f, 0.0f, 0.0f);         //�ʒu��ݒ�
	SantaCursor.SetSize(200.0f, 180.0f, 0.f);     //�傫���ݒ�
	SantaCursor.SetAngle(0.0f);//�p�x��ݒ�	   

	//====================================================
	// UI
	//====================================================

		// ���� bug1
	itemUi[0].Init(L"asset/iwa.png", 1, 1); //����
	itemUi[0].SetPos(-590.0f, 320.0f, 0.0f);//�ʒu�����
	itemUi[0].SetSize(60.0f, 60.0f, 0.0f);//�傫���ݒ�
	itemUi[0].SetAngle(0.0f);//�p�x�ݒ�

	// ���� bug2
	itemUi[1].Init(L"asset/iwa.png", 1, 1); //����
	itemUi[1].SetPos(-520.0f, 300.0f, 0.0f);//�ʒu�����
	itemUi[1].SetSize(90.0f, 90.0f, 0.0f);//�傫���ݒ�
	itemUi[1].SetAngle(0.0f);//�p�x�ݒ�

	// ���� bud3
	itemUi[2].Init(L"asset/iwa.png", 1, 1); //����
	itemUi[2].SetPos(-440.0f, 290.0f, 0.0f);//�ʒu�����
	itemUi[2].SetSize(110.0f, 110.0f, 0.0f);//�傫���ݒ�
	itemUi[2].SetAngle(0.0f);//�p�x�ݒ�

	
	// ��� bug1
	itemUi[3].Init(L"asset/yukidama.png", 1, 1); //���
	itemUi[3].SetPos(-590.0f, 320.0f, 0.0f);//�ʒu�����
	itemUi[3].SetSize(50.0f, 50.0f, 0.0f);//�傫���ݒ�
	itemUi[3].SetAngle(0.0f);//�p�x�ݒ�

	// ��� bug2
	itemUi[4].Init(L"asset/yukidama.png", 1, 1); //���
	itemUi[4].SetPos(-520.0f, 300.0f, 0.0f);//�ʒu�����
	itemUi[4].SetSize(80.0f, 80.0f, 0.0f);//�傫���ݒ�
	itemUi[4].SetAngle(0.0f);//�p�x�ݒ�

	// ��� bug3
	itemUi[5].Init(L"asset/yukidama.png", 1, 1); //���
	itemUi[5].SetPos(-590.0f, 320.0f, 0.0f);//�ʒu�����
	itemUi[5].SetSize(100.0f, 100.0f, 0.0f);//�傫���ݒ�
	itemUi[5].SetAngle(0.0f);//�p�x�ݒ�

	// ��� bug1
	itemUi[6].Init(L"asset/turara.png", 1, 1); //����
	itemUi[6].SetPos(-600.0f, 300.0f, 0.0f);//�ʒu�����
	itemUi[6].SetSize(90.0f, 90.0f, 0.0f);//�傫���ݒ�
	itemUi[6].SetAngle(0.0f);//�p�x�ݒ�

	// ��� bug2
	itemUi[7].Init(L"asset/turara.png", 1, 1); //����
	itemUi[7].SetPos(-600.0f, 220.0f, 0.0f);//�ʒu�����
	itemUi[7].SetSize(90.0f, 90.0f, 0.0f);//�傫���ݒ�
	itemUi[7].SetAngle(0.0f);//�p�x�ݒ�

	// ��� bug3
	itemUi[8].Init(L"asset/turara.png", 1, 1); //����
	itemUi[8].SetPos(-600.0f, 120.0f, 0.0f);//�ʒu�����
	itemUi[8].SetSize(90.0f, 90.0f, 0.0f);//�傫���ݒ�
	itemUi[8].SetAngle(0.0f);//�p�x�ݒ�

	//====================================================
	//�X�e�[�W1
	//====================================================
	Stage1_Loading.Init(L"asset/Stage1.png", 1, 1);//��������
	Stage1_Loading.SetPos(0.0f, 0.0f, 0.0f);         //�ʒu��ݒ�
	Stage1_Loading.SetSize(1280.0f, 720.0f, 0.f);     //�傫���ݒ�
	Stage1_Loading.SetAngle(0.0f);//�p�x��ݒ�	  

	invisiblewall[1].Init(L"asset/tree.png", 1, 1);//��������
	invisiblewall[1].SetPos(-600.0f, 0.0f, 0.0f);         //�ʒu��ݒ�
	invisiblewall[1].SetSize(240.0f, 1000.0f, 0.f);     //�傫���ݒ�
	invisiblewall[1].SetAngle(0.0f);//�p�x��ݒ�

	invisiblewall[2].Init(L"asset/tree.png", 1, 1);//��������
	invisiblewall[2].SetPos(5850.0f, 500.0f, 0.0f);         //�ʒu��ݒ�
	invisiblewall[2].SetSize(240.0f, 1000.0f, 0.f);     //�傫���ݒ�
	invisiblewall[2].SetAngle(0.0f);//�p�x��ݒ�

	invisiblewall[3].Init(L"asset/tree.png", 1, 1);//��������
	invisiblewall[3].SetPos(-600.0f, 0.0f, 0.0f);         //�ʒu��ݒ�
	invisiblewall[3].SetSize(240.0f, 1000.0f, 0.f);     //�傫���ݒ�
	invisiblewall[3].SetAngle(0.0f);//�p�x��ݒ�

	invisiblewall[4].Init(L"asset/tree.png", 1, 1);//��������
	invisiblewall[4].SetPos(7850.0f, 500.0f, 0.0f);         //�ʒu��ݒ�
	invisiblewall[4].SetSize(240.0f, 1000.0f, 0.f);     //�傫���ݒ�
	invisiblewall[4].SetAngle(0.0f);//�p�x��ݒ�



	goal.Init(L"asset/house.png", 1, 1);//�S�[��
	goal.SetPos(5800.0f, -70.0f, 0.0f);//�ʒu�����
	goal.SetSize(240.0f, 250.0f, 0.0f);//�傫���ݒ�
	goal.SetAngle(0.0f);//�p�x�ݒ�
	//�R
	mounten[1].Init(L"asset/background_stage_1_v03.png", 1, 1);//�Q�[���w�i
	mounten[1].SetPos(0.0f, 0.0f, 0.0f);//�ʒu�����
	mounten[1].SetSize(1280.0f, 720.0f, 0.0f);//�傫���ݒ�
	mounten[1].SetAngle(0.0f);//�p�x�ݒ�

	mounten[2].Init(L"asset/background_stage_1_v03.png", 1, 1);//�Q�[���w�i
	mounten[2].SetPos(1280.0f, 0.0f, 0.0f);//�ʒu�����
	mounten[2].SetSize(1280.0f, 720.0f, 0.0f);//�傫���ݒ�
	mounten[2].SetAngle(0.0f);//�p�x�ݒ�

	mounten[3].Init(L"asset/background_stage_1_v03.png", 1, 1);//�Q�[���w�i
	mounten[3].SetPos(2560.0f, 0.0f, 0.0f);//�ʒu�����
	mounten[3].SetSize(1280.0f, 720.0f, 0.0f);//�傫���ݒ�
	mounten[3].SetAngle(0.0f);//�p�x�ݒ�

	mounten[4].Init(L"asset/background_stage_1_v03.png", 1, 1);//�Q�[���w�i
	mounten[4].SetPos(-1280.0f, 0.0f, 0.0f);//�ʒu�����
	mounten[4].SetSize(1280.0f, 720.0f, 0.0f);//�傫���ݒ�
	mounten[4].SetAngle(0.0f);//�p�x�ݒ�

	//�n��
	ground[1].Init(L"asset/Stage.png", 1, 1);//�n��
	ground[1].SetPos(0.0f, -300.0f, 0.0f);//�ʒu�����
	ground[1].SetSize(1280, 200.0f, 0.0f);//�傫���ݒ�
	ground[1].SetAngle(0.0f);//�p�x�ݒ�

	ground[2].Init(L"asset/Stage.png", 1, 1);//�n��
	ground[2].SetPos(1300.0f, -300.0f, 0.0f);//�ʒu�����
	ground[2].SetSize(700.0f, 200.0f, 0.0f);//�傫���ݒ�
	ground[2].SetAngle(0.0f);//�p�x�ݒ�

	ground[3].Init(L"asset/Stage.png", 1, 1);//�n��
	ground[3].SetPos(3100.0f, -300.0f, 0.0f);//�ʒu�����
	ground[3].SetSize(2500.0f, 200.0f, 0.0f);//�傫���ݒ�
	ground[3].SetAngle(0.0f);//�p�x�ݒ�

	ground[4].Init(L"asset/Stage.png", 1, 1);//�n��
	ground[4].SetPos(4500.0f, -450.0f, 0.0f);//�ʒu�����
	ground[4].SetSize(400.0f, 200.0f, 0.0f);//�傫���ݒ�
	ground[4].SetAngle(0.0f);//�p�x�ݒ�

	ground[5].Init(L"asset/Stage.png", 1, 1);//�n��
	ground[5].SetPos(5300.0f, -300.0f, 0.0f);//�ʒu�����
	ground[5].SetSize(1280.0f, 200.0f, 0.0f);//�傫���ݒ�
	ground[5].SetAngle(0.0f);//�p�x�ݒ�

	//��
	wood[1].Init(L"asset/wood_stage_1.png", 1, 1);//��
	wood[1].SetPos(0.0f, -30.0f, 0.0f);//�ʒu�����
	wood[1].SetSize(1280.0f, 420.0f, 0.0f);//�傫���ݒ�
	wood[1].SetAngle(0.0f);//�p�x�ݒ�

	wood[2].Init(L"asset/wood_stage_1.png", 1, 1);//��
	wood[2].SetPos(1280.0f, -30.0f, 0.0f);//�ʒu�����
	wood[2].SetSize(1280.0f, 420.0f, 0.0f);//�傫���ݒ�
	wood[2].SetAngle(0.0f);//�p�x�ݒ�

	wood[3].Init(L"asset/wood_stage_1.png", 1, 1);//��
	wood[3].SetPos(2560.0f, -30.0f, 0.0f);//�ʒu�����
	wood[3].SetSize(1280.0f, 420.0f, 0.0f);//�傫���ݒ�
	wood[3].SetAngle(0.0f);//�p�x�ݒ�

	tree.Init(L"asset/tree.png", 1, 1);//��
	tree.SetPos(1900.0f, -70.0f, 0.0f);//�ʒu�����
	tree.SetSize(240.0f, 250.0f, 0.0f);//�傫���ݒ�
	tree.SetAngle(0.0f);//�p�x�ݒ�

	sky.Init(L"asset/sky.png", 1, 1);//�Q�[���w�i
	sky.SetPos(0.0f, 0.0f, 0.0f);//�ʒu�����
	sky.SetSize(1280.0f, 720.0f, 0.0f);//�傫���ݒ�
	sky.SetAngle(0.0f);//�p�x�ݒ�

	star.Init(L"asset/star.png", 1, 1);//��
	star.SetPos(0.0f, 0.0f, 0.0f);//�ʒu�����
	star.SetSize(1280.0f, 720.0f, 0.0f);//�傫���ݒ�
	star.SetAngle(0.0f);//�p�x�ݒ�

	//�������
	rock[1].Init(L"asset/iwa.png", 1, 1);//����
	rock[1].SetPos(-250.0f, -175.0f, 0.0f);//�ʒu�����
	rock[1].SetSize(70.0f, 70.0f, 0.0f);//�傫���ݒ�
	rock[1].SetAngle(0.0f);//�p�x�ݒ�

	rock[2].Init(L"asset/iwa.png", 1, 1);//����
	rock[2].SetPos(300.0f, -175.0f, 0.0f);//�ʒu�����
	rock[2].SetSize(70.0f, 70.0f, 0.0f);//�傫���ݒ�
	rock[2].SetAngle(0.0f);//�p�x�ݒ�

	rock[3].Init(L"asset/iwa.png", 1, 1);//���킠
	rock[3].SetPos(1100.0f, -175.0f, 0.0f);////�ʒu�����
	rock[3].SetSize(70.0f, 70.0f, 0.0f);//�傫���ݒ�
	rock[3].SetAngle(0.0f);//�p�x�ݒ�

	rock[4].Init(L"asset/iwa.png", 1, 1);//���킠
	rock[4].SetPos(5000.0f, -175.0f, 0.0f);////�ʒu�����
	rock[4].SetSize(70.0f, 70.0f, 0.0f);//�傫���ݒ�
	rock[4].SetAngle(0.0f);//�p�x�ݒ�

	rock[5].Init(L"asset/iwa.png", 1, 1);//���킠
	rock[5].SetPos(2300.0f, -175.0f, 0.0f);////�ʒu�����
	rock[5].SetSize(70.0f, 70.0f, 0.0f);//�傫���ݒ�
	rock[5].SetAngle(0.0f);//�p�x�ݒ�

	rock[6].Init(L"asset/iwa.png", 1, 1);//���킠
	rock[6].SetPos(4400.0f, -300.0f, 0.0f);////�ʒu�����
	rock[6].SetSize(70.0f, 70.0f, 0.0f);//�傫���ݒ�
	rock[6].SetAngle(0.0f);//�p�x�ݒ�

	//kaidan
	stairs[1].Init(L"asset/block.png", 1, 1);//����
	stairs[1].SetPos(540.0f, -165.0f, 0.0f);//�ʒu�����
	stairs[1].SetSize(200.0f, 70.0f, 0.0f);//�傫���ݒ�
	stairs[1].SetAngle(0.0f);//�p�x�ݒ�

	stairs[2].Init(L"asset/block.png", 1, 1);//����
	stairs[2].SetPos(565.0f, -95.0f, 0.0f);//�ʒu�����
	stairs[2].SetSize(150.0f, 70.0f, 0.0f);//�傫���ݒ�
	stairs[2].SetAngle(0.0f);//�p�x�ݒ�

	stairs[3].Init(L"asset/block.png", 1, 1);//���킠
	stairs[3].SetPos(600.0f, -25.0f, 0.0f);////�ʒu�����
	stairs[3].SetSize(75.0f, 70.0f, 0.0f);//�傫���ݒ�
	stairs[3].SetAngle(0.0f);//�p�x�ݒ�

	stairs[4].Init(L"asset/stairs.png", 1, 1);//���킠
	stairs[4].SetPos(2800.0f, 80.0f, 0.0f);////�ʒu�����
	stairs[4].SetSize(300.0f, 70.0f, 0.0f);//�傫���ݒ�
	stairs[4].SetAngle(0.0f);//�p�x�ݒ�

	//�v���[���g
	present[1].Init(L"asset/present.png", 1, 1);//���킠
	present[1].SetPos(800.0f, -25.0f, 0.0f);////�ʒu�����
	present[1].SetSize(75.0f, 70.0f, 0.0f);//�傫���ݒ�
	present[1].SetAngle(0.0f);//�p�x�ݒ�

	present[2].Init(L"asset/present.png", 1, 1);//���킠
	present[2].SetPos(2800.0f, 160.0f, 0.0f);////�ʒu�����
	present[2].SetSize(75.0f, 70.0f, 0.0f);//�傫���ݒ�
	present[2].SetAngle(0.0f);//�p�x�ݒ�

	present[3].Init(L"asset/present.png", 1, 1);//���킠
	present[3].SetPos(4500.0f, -300.0f, 0.0f);////�ʒu�����
	present[3].SetSize(75.0f, 70.0f, 0.0f);//�傫���ݒ�
	present[3].SetAngle(0.0f);//�p�x�ݒ�

	//���
	snowball[1].Init(L"asset/yukidama.png", 1, 1);//��
	snowball[1].SetPos(1500.0f, -175.0f, 0.0f);////�ʒu�����
	snowball[1].SetSize(70.0f, 70.0f, 0.0f);//�傫���ݒ�
	snowball[1].SetAngle(0.0f);//�p�x�ݒ�

	snowball[2].Init(L"asset/yukidama.png", 1, 1);//��
	snowball[2].SetPos(2900.0f, -175.0f, 0.0f);////�ʒu�����
	snowball[2].SetSize(70.0f, 70.0f, 0.0f);//�傫���ݒ�
	snowball[2].SetAngle(0.0f);//�p�x�ݒ�

	snowball[3].Init(L"asset/yukidama.png", 1, 1);//��
	snowball[3].SetPos(4000.0f, -175.0f, 0.0f);////�ʒu�����
	snowball[3].SetSize(70.0f, 70.0f, 0.0f);//�傫���ݒ�
	snowball[3].SetAngle(0.0f);//�p�x�ݒ�

	//�傫���v���[���g
	BigPresent[1].Init(L"asset/boxv2.png", 1, 1);//���킠
	BigPresent[1].SetPos(5400.0f, -25.0f, 0.0f);////�ʒu�����
	BigPresent[1].SetSize(105.0f, 100.0f, 0.0f);//�傫���ݒ�
	BigPresent[1].SetAngle(0.0f);//�p�x�ݒ�



	//====================================================
	//�X�e�[�W2
	//====================================================

	Stage2_Loading.Init(L"asset/Stage2.png", 1, 1);//��������
	Stage2_Loading.SetPos(0.0f, 0.0f, 0.0f);         //�ʒu��ݒ�
	Stage2_Loading.SetSize(1280.0f, 720.0f, 0.f);     //�傫���ݒ�
	Stage2_Loading.SetAngle(0.0f);//�p�x��ݒ�	


		//�n��
	Ground_Stge2[1].Init(L"asset/Stage.png", 1, 1);//�n��
	Ground_Stge2[1].SetPos(0.0f, -300.0f, 0.0f);//�ʒu�����
	Ground_Stge2[1].SetSize(1280, 200.0f, 0.0f);//�傫���ݒ�
	Ground_Stge2[1].SetAngle(0.0f);//�p�x�ݒ�

	Ground_Stge2[2].Init(L"asset/Stage.png", 1, 1);//�n��
	Ground_Stge2[2].SetPos(2000.0f, -300.0f, 0.0f);//�ʒu�����
	Ground_Stge2[2].SetSize(2350.0f, 200.0f, 0.0f);//�傫���ݒ�
	Ground_Stge2[2].SetAngle(0.0f);//�p�x�ݒ�

	Ground_Stge2[3].Init(L"asset/Stage.png", 1, 1);//�n��
	Ground_Stge2[3].SetPos(3300.0f, -420.0f, 0.0f);//�ʒu�����
	Ground_Stge2[3].SetSize(250.0f, 200.0f, 0.0f);//�傫���ݒ�
	Ground_Stge2[3].SetAngle(0.0f);//�p�x�ݒ�

	Ground_Stge2[4].Init(L"asset/Stage.png", 1, 1);//�n��
	Ground_Stge2[4].SetPos(3800.0f, -300.0f, 0.0f);//�ʒu�����
	Ground_Stge2[4].SetSize(800, 200.0f, 0.0f);//�傫���ݒ�
	Ground_Stge2[4].SetAngle(0.0f);//�p�x�ݒ�

	Ground_Stge2[5].Init(L"asset/Stage.png", 1, 1);//�n��
	Ground_Stge2[5].SetPos(4450.0f, -420.0f, 0.0f);//�ʒu�����
	Ground_Stge2[5].SetSize(500, 200.0f, 0.0f);//�傫���ݒ�
	Ground_Stge2[5].SetAngle(0.0f);//�p�x�ݒ�

	Ground_Stge2[6].Init(L"asset/Stage.png", 1, 1);//�n��
	Ground_Stge2[6].SetPos(5300.0f, -300.0f, 0.0f);//�ʒu�����
	Ground_Stge2[6].SetSize(1200.0f, 200.0f, 0.0f);//�傫���ݒ�
	Ground_Stge2[6].SetAngle(0.0f);//�p�x�ݒ�

	Ground_Stge2[7].Init(L"asset/Stage.png", 1, 1);//�n��
	Ground_Stge2[7].SetPos(7400.0f, -300.0f, 0.0f);//�ʒu�����
	Ground_Stge2[7].SetSize(1300.0f, 200.0f, 0.0f);//�傫���ݒ�
	Ground_Stge2[7].SetAngle(0.0f);//�p�x�ݒ�

	//�u���b�N
	Block_Stge2[1].Init(L"asset/stairs.png", 1, 1);//�u���b�N
	Block_Stge2[1].SetPos(2000.0f, 200.0f, 0.0f);//�ʒu�����
	Block_Stge2[1].SetSize(450, 50.0f, 0.0f);//�傫���ݒ�
	Block_Stge2[1].SetAngle(0.0f);//�p�x�ݒ�

	//���
	Icicles_Stge2[1].Init(L"asset/turara.png", 1, 1);//���
	Icicles_Stge2[1].SetPos(1800.0f, 100.0f, 0.0f);//�ʒu�����
	Icicles_Stge2[1].SetSize(150, 200.0f, 0.0f);//�傫���ݒ�
	Icicles_Stge2[1].SetAngle(0.0f);//�p�x�ݒ�

	Icicles_Stge2[2].Init(L"asset/turara.png", 1, 1);//���
	Icicles_Stge2[2].SetPos(2000.0f, 100.0f, 0.0f);//�ʒu�����
	Icicles_Stge2[2].SetSize(150, 200.0f, 0.0f);//�傫���ݒ�
	Icicles_Stge2[2].SetAngle(0.0f);//�p�x�ݒ�

	Icicles_Stge2[3].Init(L"asset/turara.png", 1, 1);//���
	Icicles_Stge2[3].SetPos(2200.0f, 100.0f, 0.0f);//�ʒu�����
	Icicles_Stge2[3].SetSize(150, 200.0f, 0.0f);//�傫���ݒ�
	Icicles_Stge2[3].SetAngle(0.0f);//�p�x�ݒ�

	//��
	Tree_Stge2[1].Init(L"asset/tree3.png", 1, 1);//��
	Tree_Stge2[1].SetPos(900.0f, -70.0f, 0.0f);//�ʒu�����
	Tree_Stge2[1].SetSize(240.0f, 250.0f, 0.0f);//�傫���ݒ�
	Tree_Stge2[1].SetAngle(0.0f);//�p�x�ݒ�

	Tree_Stge2[2].Init(L"asset/tree3.png", 1, 1);//��
	Tree_Stge2[2].SetPos(3450.0f, -70.0f, 0.0f);//�ʒu�����
	Tree_Stge2[2].SetSize(240.0f, 250.0f, 0.0f);//�傫���ݒ�
	Tree_Stge2[2].SetAngle(0.0f);//�p�x�ݒ�

	//kaidan
	Stairs_Stge2[1].Init(L"asset/block2.png", 1, 1);//����
	Stairs_Stge2[1].SetPos(5720.0f, -170.0f, 0.0f);//�ʒu�����
	Stairs_Stge2[1].SetSize(370.0f, 65.0f, 0.0f);//�傫���ݒ�
	Stairs_Stge2[1].SetAngle(0.0f);//�p�x�ݒ�

	Stairs_Stge2[2].Init(L"asset/block2.png", 1, 1);//����
	Stairs_Stge2[2].SetPos(5755.0f, -105.0f, 0.0f);//�ʒu�����
	Stairs_Stge2[2].SetSize(300.0f, 65.0f, 0.0f);//�傫���ݒ�
	Stairs_Stge2[2].SetAngle(0.0f);//�p�x�ݒ�

	Stairs_Stge2[3].Init(L"asset/block2.png", 1, 1);//���킠
	Stairs_Stge2[3].SetPos(5790.0f, -40.0f, 0.0f);////�ʒu�����
	Stairs_Stge2[3].SetSize(230.0f, 65.0f, 0.0f);//�傫���ݒ�
	Stairs_Stge2[3].SetAngle(0.0f);//�p�x�ݒ�

	Stairs_Stge2[4].Init(L"asset/block2.png", 1, 1);//����
	Stairs_Stge2[4].SetPos(5825.0f, 25.0f, 0.0f);//�ʒu�����
	Stairs_Stge2[4].SetSize(160.0f, 65.0f, 0.0f);//�傫���ݒ�
	Stairs_Stge2[4].SetAngle(0.0f);//�p�x�ݒ�

	Stairs_Stge2[5].Init(L"asset/block2.png", 1, 1);//����
	Stairs_Stge2[5].SetPos(5860.0f, 90.0f, 0.0f);//�ʒu�����
	Stairs_Stge2[5].SetSize(90.0f, 65.0f, 0.0f);//�傫���ݒ�
	Stairs_Stge2[5].SetAngle(0.0f);//�p�x�ݒ�



	//����ł����
	Collectrock_Stage2[1].Init(L"asset/iwa.png", 1, 1);//�v���[���g
	Collectrock_Stage2[1].SetPos(-275.0f, -175.0f, 0.0f);//�ʒu�����
	Collectrock_Stage2[1].SetSize(75.0f, 70.0f, 0.0f);//�傫���ݒ�
	Collectrock_Stage2[1].SetAngle(0.0f);//�p�x�ݒ�

	Collectrock_Stage2[2].Init(L"asset/iwa.png", 1, 1);//�v���[���g
	Collectrock_Stage2[2].SetPos(5000.0f, -175.0f, 0.0f);//�ʒu�����
	Collectrock_Stage2[2].SetSize(75.0f, 70.0f, 0.0f);//�傫���ݒ�
	Collectrock_Stage2[2].SetAngle(0.0f);//�p�x�ݒ�

	Collectrock_Stage2[3].Init(L"asset/iwa.png", 1, 1);//�v���[���g
	Collectrock_Stage2[3].SetPos(1100.0f, -175.0f, 0.0f);//�ʒu�����
	Collectrock_Stage2[3].SetSize(75.0f, 70.0f, 0.0f);//�傫���ݒ�
	Collectrock_Stage2[3].SetAngle(0.0f);//�p�x�ݒ�

	Collectrock_Stage2[4].Init(L"asset/iwa.png", 1, 1);//�v���[���g
	Collectrock_Stage2[4].SetPos(2800.0f, -175.0f, 0.0f);//�ʒu�����
	Collectrock_Stage2[4].SetSize(75.0f, 70.0f, 0.0f);//�傫���ݒ�
	Collectrock_Stage2[4].SetAngle(0.0f);//�p�x�ݒ�

	Collectrock_Stage2[5].Init(L"asset/iwa.png", 1, 1);//�v���[���g
	Collectrock_Stage2[5].SetPos(4000.0f, -175.0f, 0.0f);//�ʒu�����
	Collectrock_Stage2[5].SetSize(75.0f, 70.0f, 0.0f);//�傫���ݒ�
	Collectrock_Stage2[5].SetAngle(0.0f);//�p�x�ݒ�

	Collectrock_Stage2[6].Init(L"asset/iwa.png", 1, 1);//�v���[���g
	Collectrock_Stage2[6].SetPos(7500.0f, -175.0f, 0.0f);//�ʒu�����
	Collectrock_Stage2[6].SetSize(75.0f, 70.0f, 0.0f);//�傫���ݒ�
	Collectrock_Stage2[6].SetAngle(0.0f);//�p�x�ݒ�

	//����ł�����
	Snowball_Stage2[1].Init(L"asset/yukidama.png", 1, 1);//�v���[���g
	Snowball_Stage2[1].SetPos(3100.0f, -175.0f, 0.0f);//�ʒu�����
	Snowball_Stage2[1].SetSize(75.0f, 70.0f, 0.0f);//�傫���ݒ�
	Snowball_Stage2[1].SetAngle(0.0f);//�p�x�ݒ�

	Snowball_Stage2[2].Init(L"asset/yukidama.png", 1, 1);//�v���[���g
	Snowball_Stage2[2].SetPos(5500.0f, -175.0f, 0.0f);//�ʒu�����
	Snowball_Stage2[2].SetSize(75.0f, 70.0f, 0.0f);//�傫���ݒ�
	Snowball_Stage2[2].SetAngle(0.0f);//�p�x�ݒ�

	Snowball_Stage2[3].Init(L"asset/yukidama.png", 1, 1);//�v���[���g
	Snowball_Stage2[3].SetPos(7000.0f, -175.0f, 0.0f);//�ʒu�����
	Snowball_Stage2[3].SetSize(75.0f, 70.0f, 0.0f);//�傫���ݒ�
	Snowball_Stage2[3].SetAngle(0.0f);//�p�x�ݒ�


	//�v���[���g
	Present_Stage2[1].Init(L"asset/present.png", 1, 1);//�v���[���g
	Present_Stage2[1].SetPos(3300.0f, -265.0f, 0.0f);////�ʒu�����
	Present_Stage2[1].SetSize(75.0f, 70.0f, 0.0f);//�傫���ݒ�
	Present_Stage2[1].SetAngle(0.0f);//�p�x�ݒ�

	Present_Stage2[2].Init(L"asset/present.png", 1, 1);//�v���[���g
	Present_Stage2[2].SetPos(6300.0f, 100.0f, 0.0f);////�ʒu�����
	Present_Stage2[2].SetSize(75.0f, 70.0f, 0.0f);//�傫���ݒ�
	Present_Stage2[2].SetAngle(0.0f);//�p�x�ݒ�

	Present_Stage2[3].Init(L"asset/present.png", 1, 1);//�v���[���g
	Present_Stage2[3].SetPos(2000.0f, 280.0f, 0.0f);////�ʒu�����
	Present_Stage2[3].SetSize(75.0f, 70.0f, 0.0f);//�傫���ݒ�
	Present_Stage2[3].SetAngle(0.0f);//�p�x�ݒ�

	//�v���[���g��
	BigPresent_Stage2[1].Init(L"asset/boxv2.png", 1, 1);//�v���[���g
	BigPresent_Stage2[1].SetPos(4450.0f, -250.0f, 0.0f);////�ʒu�����
	BigPresent_Stage2[1].SetSize(75.0f, 70.0f, 0.0f);//�傫���ݒ�
	BigPresent_Stage2[1].SetAngle(0.0f);//�p�x�ݒ�

	//�󂹂��
	Breakrock_Stge2[1].Init(L"asset/iwa_yuki2.png", 1, 1);//�v���[���g
	Breakrock_Stge2[1].SetPos(4450.0f, -250.0f, 0.0f);////�ʒu�����
	Breakrock_Stge2[1].SetSize(300.0f, 200.0f, 0.0f);//�傫���ݒ�
	Breakrock_Stge2[1].SetAngle(0.0f);//�p�x�ݒ�

	Breakmoji.Init(L"asset/Break2_another.png", 1, 1);//�v���[���g
	Breakmoji.SetPos(4450.0f, -150.0f, 0.0f);////�ʒu�����
	Breakmoji.SetSize(200.0f, 100.0f, 0.0f);//�傫���ݒ�
	Breakmoji.SetAngle(0.0f);//�p�x�ݒ�


	Goal_Stage2.Init(L"asset/house.png", 1, 1);//�S�[��
	Goal_Stage2.SetPos(7900.0f, -70.0f, 0.0f);//�ʒu�����
	Goal_Stage2.SetSize(240.0f, 250.0f, 0.0f);//�傫���ݒ�
	Goal_Stage2.SetAngle(0.0f);//�p�x�ݒ�


	//====================================================
	//���U���g
	//====================================================
	Result.Init(L"asset/Result_v2.png", 1, 1);//��������
	Result.SetPos(0.0f, 0.0f, 0.0f);         //�ʒu��ݒ�
	Result.SetSize(1280.0f, 720.0f, 0.f);     //�傫���ݒ�
	Result.SetAngle(0.0f);//�p�x��ݒ�	    
	
	ResultStar[1].Init(L"asset/ResultStar.png", 1, 1);//��������
	ResultStar[1].SetPos(-180.0f, 100.0f, 0.0f);         //�ʒu��ݒ�
	ResultStar[1].SetSize(100.0f, 100.0f, 0.f);     //�傫���ݒ�
	ResultStar[1].SetAngle(0.0f);//�p�x��ݒ�

	ResultStar[2].Init(L"asset/ResultStar.png", 1, 1);//��������
	ResultStar[2].SetPos(-80.0f, 100.0f, 0.0f);         //�ʒu��ݒ�
	ResultStar[2].SetSize(100.0f, 100.0f, 0.f);     //�傫���ݒ�
	ResultStar[2].SetAngle(0.0f);//�p�x��ݒ�

	ResultStar[3].Init(L"asset/ResultStar.png", 1, 1);//��������
	ResultStar[3].SetPos(20.0f, 100.0f, 0.0f);         //�ʒu��ݒ�
	ResultStar[3].SetSize(100.0f, 100.0f, 0.f);     //�傫���ݒ�
	ResultStar[3].SetAngle(0.0f);//�p�x��ݒ�

	ResultStar[4].Init(L"asset/ResultStar.png", 1, 1);//��������
	ResultStar[4].SetPos(120.0f, 100.0f, 0.0f);         //�ʒu��ݒ�
	ResultStar[4].SetSize(100.0f, 100.0f, 0.f);     //�傫���ݒ�
	ResultStar[4].SetAngle(0.0f);//�p�x��ݒ�

	GrayStar[1].Init(L"asset/ResultStar_Null.png", 1, 1);//��������
	GrayStar[1].SetPos(-180.0f, 100.0f, 0.0f);         //�ʒu��ݒ�
	GrayStar[1].SetSize(100.0f, 100.0f, 0.f);     //�傫���ݒ�
	GrayStar[1].SetAngle(0.0f);//�p�x��ݒ�	  

	GrayStar[2].Init(L"asset/ResultStar_Null.png", 1, 1);//��������
	GrayStar[2].SetPos(-80.0f, 100.0f, 0.0f);         //�ʒu��ݒ�
	GrayStar[2].SetSize(100.0f, 100.0f, 0.f);     //�傫���ݒ�
	GrayStar[2].SetAngle(0.0f);//�p�x��ݒ�	  

	GrayStar[3].Init(L"asset/ResultStar_Null.png", 1, 1);//��������
	GrayStar[3].SetPos(20.0f, 100.0f, 0.0f);         //�ʒu��ݒ�
	GrayStar[3].SetSize(100.0f, 100.0f, 0.f);     //�傫���ݒ�
	GrayStar[3].SetAngle(0.0f);//�p�x��ݒ�	  

	GrayStar[4].Init(L"asset/ResultStar_Null.png", 1, 1);//��������
	GrayStar[4].SetPos(120.0f, 100.0f, 0.0f);         //�ʒu��ݒ�
	GrayStar[4].SetSize(100.0f, 100.0f, 0.f);     //�傫���ݒ�
	GrayStar[4].SetAngle(0.0f);//�p�x��ݒ�	  

	Number[1].Init(L"asset/Nunber_Result.png", 11, 1);//��������
	Number[1].SetPos(100.0f, 0.0f, 0.0f);         //�ʒu��ݒ�
	Number[1].SetSize(70.0f, 70.0f, 0.f);     //�傫���ݒ�
	Number[1].SetAngle(0.0f);//�p�x��ݒ�	

	Number[2].Init(L"asset/Nunber_Result.png", 11, 1);//��������
	Number[2].SetPos(550.0f, -245.0f, 0.0f);         //�ʒu��ݒ�
	Number[2].SetSize(70.0f, 70.0f, 0.f);     //�傫���ݒ�
	Number[2].SetAngle(0.0f);//�p�x��ݒ�

	Number[3].Init(L"asset/Nunber_Result.png", 11, 1);//��������
	Number[3].SetPos(30.0f, -70.0f, 0.0f);         //�ʒu��ݒ�
	Number[3].SetSize(70.0f, 70.0f, 0.f);     //�傫���ݒ�
	Number[3].SetAngle(0.0f);//�p�x��ݒ�

	Number[4].Init(L"asset/Nunber_Result.png", 11, 1);//��������
	Number[4].SetPos(30.0f, -130.0f, 0.0f);         //�ʒu��ݒ�
	Number[4].SetSize(70.0f, 70.0f, 0.f);     //�傫���ݒ�
	Number[4].SetAngle(0.0f);//�p�x��ݒ�

	Number[5].Init(L"asset/Nunber_Result.png", 11, 1);//��������
	Number[5].SetPos(500.0f, -70.0f, 0.0f);         //�ʒu��ݒ�
	Number[5].SetSize(70.0f, 70.0f, 0.f);     //�傫���ݒ�
	Number[5].SetAngle(0.0f);//�p�x��ݒ�

	Number[6].Init(L"asset/Nunber_Result.png", 11, 1);//��������
	Number[6].SetPos(500.0f, -130.0f, 0.0f);         //�ʒu��ݒ�
	Number[6].SetSize(70.0f, 70.0f, 0.f);     //�傫���ݒ�
	Number[6].SetAngle(0.0f);//�p�x��ݒ�

	X[1].Init(L"asset/Nunber_Result.png", 11, 1);//��������
	X[1].SetPos(120.0f, -70.0f, 0.0f);         //�ʒu��ݒ�
	X[1].SetSize(70.0f, 70.0f, 0.f);     //�傫���ݒ�
	X[1].SetAngle(0.0f);//�p�x��ݒ�	

	X[2].Init(L"asset/Nunber_Result.png", 11, 1);//��������
	X[2].SetPos(120.0f, -130.0f, 0.0f);         //�ʒu��ݒ�
	X[2].SetSize(70.0f, 70.0f, 0.f);     //�傫���ݒ�
	X[2].SetAngle(0.0f);//�p�x��ݒ�

	Result_present.Init(L"asset/present.png", 1, 1);//�v���[���g
	Result_present.SetPos(-100.0f, -70.0f, 0.0f);////�ʒu�����
	Result_present.SetSize(70.0f, 70.0f, 0.0f);//�傫���ݒ�
	Result_present.SetAngle(0.0f);//�p�x�ݒ�

	//�v���[���g��
	Result_Bigpresent.Init(L"asset/boxv2.png", 1, 1);//�v���[���g
	Result_Bigpresent.SetPos(-100.0f, -130.0f, 0.0f);////�ʒu�����
	Result_Bigpresent.SetSize(70.0f, 70.0f, 0.0f);//�傫���ݒ�
	Result_Bigpresent.SetAngle(0.0f);//�p�x�ݒ�


	//====================================================
	//UI
	//====================================================
	Time.Init(L"asset/Time_v2.png", 1, 1);//��������
	Time.SetPos(0.0f, 300.0f, 0.0f);         //�ʒu��ݒ�
	Time.SetSize(250.0f, 150.0f, 0.f);     //�傫���ݒ�
	Time.SetAngle(0.0f);//�p�x��ݒ�	

	Number_UI[1].Init(L"asset/Number_v2.png", 10, 1);//�X�R�A��������
	Number_UI[1].SetPos(-300.0f, -300.0f, 0.0f);         //�ʒu��ݒ�
	Number_UI[1].SetSize(40.0f, 40.0f, 0.f);     //�傫���ݒ�
	Number_UI[1].SetAngle(0.0f);//�p�x��ݒ�

	Number_UI[2].Init(L"asset/Number_v2.png", 10, 1);//���Ԃ�������
	Number_UI[2].SetPos(50.0f, 300.0f, 0.0f);         //�ʒu��ݒ�
	Number_UI[2].SetSize(40.0f, 40.0f, 0.f);     //�傫���ݒ�
	Number_UI[2].SetAngle(0.0f);//�p�x��ݒ�

	ScoreCounter.Init(L"asset/ScoreCounter_v2.png", 1, 1);//��������
	ScoreCounter.SetPos(-550.0f, -300.0f, 0.0f);         //�ʒu��ݒ�
	ScoreCounter.SetSize(80.0f, 80.0f, 0.f);     //�傫���ݒ�
	ScoreCounter.SetAngle(0.0f);//�p�x��ݒ�	

	ItemStock.Init(L"asset/ItemStock.png", 1, 1);//��������
	ItemStock.SetPos(-500.0f, 280.0f, 0.0f);         //�ʒu��ݒ�
	ItemStock.SetSize(230.0f, 130.0f, 0.f);     //�傫���ݒ�
	ItemStock.SetAngle(0.0f);//�p�x��ݒ�	
	ItemStock.SetColor(1.0f, 1.0f, 1.0f, 1.0f);

	//�Q�[���ɖ߂�
	Returntogame.Init(L"asset/Returntogame.png", 1, 1);//���킠
	Returntogame.SetPos(5400.0f, -25.0f, 0.0f);////�ʒu�����
	Returntogame.SetSize(250.0f, 250.0f, 0.0f);//�傫���ݒ�
	Returntogame.SetAngle(0.0f);//�p�x�ݒ�

	damage.Init(L"asset/damage5.png", 1, 1);//��������
	damage.SetPos(100.0f, 330.0f, 0.0f);         //�ʒu��ݒ�
	damage.SetSize(70.0f, 70.0f, 0.f);     //�傫���ݒ�
	damage.SetAngle(-20.0f);//�p�x��ݒ�

	UseBag.Init(L"asset/UseBag_v2.png", 1, 1);//��������
	UseBag.SetPos(500.0f, 290.0f, 0.0f);         //�ʒu��ݒ�
	UseBag.SetSize(300.0f, 150.0f, 0.f);     //�傫���ݒ�
	UseBag.SetAngle(0.0f);//�p�x��ݒ�

	normalUI.Init(L"asset/Normal.png", 1, 1);//��������
	normalUI.SetPos(400.0f, 290.0f, 0.0f);         //�ʒu��ݒ�
	normalUI.SetSize(100.0f, 100.0f, 0.f);     //�傫���ݒ�
	normalUI.SetAngle(0.0f);//�p�x��ݒ�

	hurosikilUI.Init(L"asset/HuroshikiUI.png", 1, 1);//��������
	hurosikilUI.SetPos(400.0f, 290.0f, 0.0f);         //�ʒu��ݒ�
	hurosikilUI.SetSize(100.0f, 100.0f, 0.f);     //�傫���ݒ�
	hurosikilUI.SetAngle(0.0f);//�p�x��ݒ�

	kintyakuUI.Init(L"asset/KintyakuUI.png", 1, 1);//��������
	kintyakuUI.SetPos(400.0f, 290.0f, 0.0f);         //�ʒu��ݒ�
	kintyakuUI.SetSize(100.0f, 100.0f, 0.f);     //�傫���ݒ�
	kintyakuUI.SetAngle(0.0f);//�p�x��ݒ�


	normalmoji.Init(L"asset/hukuro_v2.png", 1, 1);//��������
	normalmoji.SetPos(530.0f, 270.0f, 0.0f);         //�ʒu��ݒ�
	normalmoji.SetSize(120.0f, 70.0f, 0.f);     //�傫���ݒ�
	normalmoji.SetAngle(0.0f);//�p�x��ݒ�

	hurosikimoji.Init(L"asset/huroshiki_v2.png", 1, 1);//��������
	hurosikimoji.SetPos(530.0f, 270.0f, 0.0f);         //�ʒu��ݒ�
	hurosikimoji.SetSize(120.0f, 70.0f, 0.f);     //�傫���ݒ�
	hurosikimoji.SetAngle(0.0f);//�p�x��ݒ�

	kintyakumoji.Init(L"asset/kintyaku_v2.png", 1, 1);//��������
	kintyakumoji.SetPos(530.0f, 270.0f, 0.0f);         //�ʒu��ݒ�
	kintyakumoji.SetSize(120.0f, 70.0f, 0.f);     //�傫���ݒ�
	kintyakumoji.SetAngle(0.0f);//�p�x��ݒ�

	//====================================================
	//������
	//====================================================
	
	//����1
	use_rock[0].Init(L"asset/iwa.png", 1, 1);//����
	use_rock[0].SetPos(-2500.0f, -175.0f, 0.0f);//�ʒu�����
	use_rock[0].SetSize(70.0f, 70.0f, 0.0f);//�傫���ݒ�
	use_rock[0].SetAngle(0.0f);//�p�x�ݒ�

	//����2
	use_rock[1].Init(L"asset/iwa.png", 1, 1);//����
	use_rock[1].SetPos(-2500.0f, -175.0f, 0.0f);//�ʒu�����
	use_rock[1].SetSize(70.0f, 70.0f, 0.0f);//�傫���ݒ�
	use_rock[1].SetAngle(0.0f);//�p�x�ݒ�

	//����3
	use_rock[2].Init(L"asset/iwa.png", 1, 1);//����
	use_rock[2].SetPos(-2500.0f, -175.0f, 0.0f);//�ʒu�����
	use_rock[2].SetSize(70.0f, 70.0f, 0.0f);//�傫���ݒ�
	use_rock[2].SetAngle(0.0f);//�p�x�ݒ�

	//���1
	use_snowball[0].Init(L"asset/yukidama.png", 1, 1);//��
	use_snowball[0].SetPos(-2500.0f, -175.0f, 0.0f);////�ʒu�����
	use_snowball[0].SetSize(70.0f, 70.0f, 0.0f);//�傫���ݒ�
	use_snowball[0].SetAngle(0.0f);//�p�x�ݒ�

	//���2
	use_snowball[1].Init(L"asset/yukidama.png", 1, 1);//��
	use_snowball[1].SetPos(-2500.0f, -175.0f, 0.0f);////�ʒu�����
	use_snowball[1].SetSize(70.0f, 70.0f, 0.0f);//�傫���ݒ�
	use_snowball[1].SetAngle(0.0f);//�p�x�ݒ�

	//���3
	use_snowball[2].Init(L"asset/yukidama.png", 1, 1);//��
	use_snowball[2].SetPos(-2500.0f, -175.0f, 0.0f);////�ʒu�����
	use_snowball[2].SetSize(70.0f, 70.0f, 0.0f);//�傫���ݒ�
	use_snowball[2].SetAngle(0.0f);//�p�x�ݒ�

	//====================================================
	//�Q�[���I�[�o�[
	//====================================================

	Gameover.Init(L"asset/MorningFilter_v3.png", 1, 1);//��������
	Gameover.SetPos(0.0f, 0.0f, 0.0f);         //�ʒu��ݒ�
	Gameover.SetSize(1280.0f, 720.0f, 0.f);     //�傫���ݒ�
	Gameover.SetAngle(0.0f);//�p�x��ݒ�
	Gameover.SetColor(0.8f, 0.8f, 0.8f, 0.8f); //�F��ݒ�

	GoodMorning.Init(L"asset/Gameover.png", 1, 1);//��������
	GoodMorning.SetPos(0.0f, 190.0f, 0.0f);         //�ʒu��ݒ�
	GoodMorning.SetSize(650.0f, 400.0f, 0.f);     //�傫���ݒ�
	GoodMorning.SetAngle(0.0f);//�p�x��ݒ�

	Retry.Init(L"asset/Retry.png", 1, 1);//��������
	Retry.SetPos(0.0f, -100.0f, 0.0f);         //�ʒu��ݒ�
	Retry.SetSize(250.0f, 150.0f, 0.f);     //�傫���ݒ�
	Retry.SetAngle(0.0f);//�p�x��ݒ�

	TitleBack.Init(L"asset/TitleBack.png", 1, 1);//��������
	TitleBack.SetPos(0.0f, -200.0f, 0.0f);         //�ʒu��ݒ�
	TitleBack.SetSize(250.0f, 150.0f, 0.f);     //�傫���ݒ�
	TitleBack.SetAngle(0.0f);//�p�x��ݒ�

	Cursor.Init(L"asset/Cursor.png", 1, 1);//��������
	Cursor.SetPos(-150.0f, -100.0f, 0.0f);         //�ʒu��ݒ�
	Cursor.SetSize(100.0f, 100.0f, 0.f);     //�傫���ݒ�
	Cursor.SetAngle(0.0f);//�p�x��ݒ�

	//====================================================
	//�|�[�Y���
	//====================================================
	pause.SetPos(100.0f, 0.0f, 0.0f);//�ʒu�����
	pause.SetSize(1280.0f, 720.0f, 0.0f);//�傫���ݒ�
	gameoverFg = false;//�|�[�Y�t���O������

	rule.Init(L"asset/Setsumei.png", 1, 1);//��������
	rule.SetPos(-200.0f, 20.0f, 0.0f);         //�ʒu��ݒ�
	rule.SetSize(850.0f, 600.0f, 0.f);     //�傫���ݒ�
	rule.SetAngle(0.0f);//�p�x��ݒ�]

	PauseGameback.Init(L"asset/Returntogame.png", 1, 1);//��������
	PauseGameback.SetPos(450.0f, 100.0f, 0.0f);         //�ʒu��ݒ�
	PauseGameback.SetSize(300.0f, 150.0f, 0.f);     //�傫���ݒ�
	PauseGameback.SetAngle(0.0f);//�p�x��ݒ�

	//PauseRetry.Init(L"asset/Retry.png", 1, 1);//��������
	//PauseRetry.SetPos(500.0f, 0.0f, 0.0f);         //�ʒu��ݒ�
	//PauseRetry.SetSize(200.0f, 150.0f, 0.f);     //�傫���ݒ�
	//PauseRetry.SetAngle(0.0f);//�p�x��ݒ�

	PauseTitleBack.Init(L"asset/TitleBack.png", 1, 1);//��������
	PauseTitleBack.SetPos(500.0f, -100.0f, 0.0f);         //�ʒu��ݒ�
	PauseTitleBack.SetSize(200.0f, 150.0f, 0.f);     //�傫���ݒ�
	PauseTitleBack.SetAngle(0.0f);//�p�x��ݒ�

	PauseCursor.Init(L"asset/Cursor.png", 1, 1);//��������
	PauseCursor.SetPos(250.0f, 100.0f, 0.0f);         //�ʒu��ݒ�
	PauseCursor.SetSize(100.0f, 100.0f, 0.f);     //�傫���ݒ�
	PauseCursor.SetAngle(0.0f);//�p�x��ݒ�

	Pausemoji.Init(L"asset/Pause.png", 1, 1);//��������
	Pausemoji.SetPos(500.0f, 300.0f, 0.0f);         //�ʒu��ݒ�
	Pausemoji.SetSize(250.0f, 150.0f, 0.f);     //�傫���ݒ�
	Pausemoji.SetAngle(0.0f);//�p�x��ݒ�

	//====================================================
	//�{�X
	//====================================================

	BOSSBACK.Init(L"asset/Background_Stage_3.png", 1, 1);//�Ⴞ��܂�������
	BOSSBACK.SetPos(0.0f, 0.0f, 0.0f);		//�ʒu��ݒ�
	BOSSBACK.SetSize(1280.0f, 720.0f, 0.f);	//�傫����ݒ�
	BOSSBACK.SetAngle(0.0f);             		//�p�x��ݒ�
	BOSSBACK.SetColor(1.0f, 1.0f, 1.0f, 1.0f); //�F��ݒ�

	BOSS_Loading.Init(L"asset/Stage3.png", 1, 1);//�Ⴞ��܂�������
	BOSS_Loading.SetPos(0.0f, 0.0f, 0.0f);		//�ʒu��ݒ�
	BOSS_Loading.SetSize(1280.0f, 720.0f, 0.f);	//�傫����ݒ�
	BOSS_Loading.SetAngle(0.0f);             		//�p�x��ݒ�
	BOSS_Loading.SetColor(1.0f, 1.0f, 1.0f, 1.0f); //�F��ݒ�

	Bossground.Init(L"asset/Stage.png", 1, 1);//�Ⴞ��܂�������
	Bossground.SetPos(0.0f, -455.0f, 0.0f);		//�ʒu��ݒ�
	Bossground.SetSize(1280.0f, 250.0f, 0.f);	//�傫����ݒ�
	Bossground.SetAngle(0.0f);             		//�p�x��ݒ�
	Bossground.SetColor(1.0f, 1.0f, 1.0f, 1.0f); //�F��ݒ�

	
	boss_monster.Init(L"asset/Boss_Taiki.png", 6, 1);//�Ⴞ��܃{�X��������
	boss_monster.SetPos(190.0f, -160.0f, 0.0f);		//�ʒu��ݒ�
	boss_monster.SetSize(500.0f, 350.0f, 0.0f);	//�傫����ݒ�
	boss_monster.SetAngle(0.0f);             		//�p�x��ݒ�
	boss_monster.SetColor(1.0f, 1.0f, 1.0f, 1.0f); //�F��ݒ�

	boss_toujou.Init(L"asset/Boss_Touzyou_v2.png", 6, 2);//�Ⴞ��܃{�X��������
	boss_toujou.SetPos(190.0f, -160.0f, 0.0f);		//�ʒu��ݒ�
	boss_toujou.SetSize(500.0f, 350.0f, 0.0f);	//�傫����ݒ�
	boss_toujou.SetAngle(0.0f);             		//�p�x��ݒ�
	boss_toujou.SetColor(1.0f, 1.0f, 1.0f, 1.0f); //�F��ݒ�

	boss_punch.Init(L"asset/Boss_Punch.png", 6, 2);//�Ⴞ��܃{�X��������
	boss_punch.SetPos(190.0f, -160.0f, 0.0f);		//�ʒu��ݒ�
	boss_punch.SetSize(500.0f, 350.0f, 0.0f);	//�傫����ݒ�
	boss_punch.SetAngle(0.0f);             		//�p�x��ݒ�
	boss_punch.SetColor(1.0f, 1.0f, 1.0f, 1.0f); //�F��ݒ�

	boss_yobidashi.Init(L"asset/Boss_Yobidashi.png", 6, 2);//�Ⴞ��܃{�X��������
	boss_yobidashi.SetPos(190.0f, -160.0f, 0.0f);		//�ʒu��ݒ�
	boss_yobidashi.SetSize(500.0f, 350.0f, 0.0f);	//�傫����ݒ�
	boss_yobidashi.SetAngle(0.0f);             		//�p�x��ݒ�
	boss_yobidashi.SetColor(1.0f, 1.0f, 1.0f, 1.0f); //�F��ݒ�


	//====================================================
	//�Ă�
	//====================================================

	snowman[1].Init(L"asset/Snowman_Move_v3.png", 4, 2);//�Ⴞ��܂�������
	snowman[1].SetPos(30.0f, -160.0f, 0.0f);		//�ʒu��ݒ�
	snowman[1].SetSize(180.0f, 90.0f, 0.f);	//�傫����ݒ�
	snowman[1].SetAngle(0.0f);             		//�p�x��ݒ�
	snowman[1].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //�F��ݒ�
	snowman[1].SetHP(20);

	snowman[2].Init(L"asset/Snowman_Move_v3.png", 4, 2);//�Ⴞ��܂�������
	snowman[2].SetPos(1600.0f, -160.0f, 0.0f);		//�ʒu��ݒ�
	snowman[2].SetSize(180.0f, 90.0f, 0.f);	//�傫����ݒ�
	snowman[2].SetAngle(0.0f);             		//�p�x��ݒ�
	snowman[2].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //�F��ݒ�
	snowman[2].SetHP(20);

	snowman[3].Init(L"asset/Snowman_Move_v3.png", 4, 2);//�䂫��������
	snowman[3].SetPos(2000.0f, -160.0f, 0.0f);		//�ʒu��ݒ�
	snowman[3].SetSize(180.0f, 90.0f, 0.f);	//�傫����ݒ�
	snowman[3].SetAngle(0.0f);             		//�p�x��ݒ�
	snowman[3].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //�F��ݒ�
	snowman[3].SetHP(20);

	star_monster.Init(L"asset/Star_Move_v3.png", 6, 2);//�ق���������
	star_monster.SetPos(3600.0f, -150.0f, 0.0f);		//�ʒu��ݒ�
	star_monster.SetSize(200.0f, 110.0f, 0.f);	//�傫����ݒ�
	star_monster.SetAngle(0.0f);             		//�p�x��ݒ�
	star_monster.SetColor(1.0f, 1.0f, 1.0f, 1.0f); //�F��ݒ�
	star_monster.SetHP(40);



	tonakai.Init(L"asset/Tonakai_Move_v3.png", 4, 2);//�ƂȂ�����������
	tonakai.SetPos(4800.0f, -140.0f, 0.0f);		//�ʒu��ݒ�
	tonakai.SetSize(220.0f, 130.0f, 0.f);	//�傫����ݒ�
	tonakai.SetAngle(0.0f);             		//�p�x��ݒ�
	tonakai.SetColor(1.0f, 1.0f, 1.0f, 1.0f); //�F��ݒ�
	tonakai.SetHP(60);

	Snowman_Stage2[1].Init(L"asset/Snowman_Move_v3.png", 4, 2);//�Ⴞ��܂�������
	Snowman_Stage2[1].SetPos(30.0f, -160.0f, 0.0f);		//�ʒu��ݒ�
	Snowman_Stage2[1].SetSize(180.0f, 90.0f, 0.f);	//�傫����ݒ�
	Snowman_Stage2[1].SetAngle(0.0f);             		//�p�x��ݒ�
	Snowman_Stage2[1].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //�F��ݒ�
	Snowman_Stage2[1].SetHP(40);

	Snowman_Stage2[2].Init(L"asset/Snowman_Move_v3.png", 4, 2);//�Ⴞ��܂�������
	Snowman_Stage2[2].SetPos(1400.0f, -160.0f, 0.0f);		//�ʒu��ݒ�
	Snowman_Stage2[2].SetSize(180.0f, 90.0f, 0.f);	//�傫����ݒ�
	Snowman_Stage2[2].SetAngle(0.0f);             		//�p�x��ݒ�
	Snowman_Stage2[2].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //�F��ݒ�
	Snowman_Stage2[2].SetHP(20);

	Snowman_Stage2[3].Init(L"asset/Snowman_Move_v3.png", 4, 2);//�Ⴞ��܂�������
	Snowman_Stage2[3].SetPos(3800.0f, -160.0f, 0.0f);		//�ʒu��ݒ�
	Snowman_Stage2[3].SetSize(180.0f, 90.0f, 0.f);	//�傫����ݒ�
	Snowman_Stage2[3].SetAngle(0.0f);             		//�p�x��ݒ�
	Snowman_Stage2[3].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //�F��ݒ�
	Snowman_Stage2[3].SetHP(20);

	Snowman_Stage2[4].Init(L"asset/Snowman_Move_v3.png", 4, 2);//�Ⴞ��܂�������
	Snowman_Stage2[4].SetPos(7000.0f, -160.0f, 0.0f);		//�ʒu��ݒ�
	Snowman_Stage2[4].SetSize(180.0f, 90.0f, 0.f);	//�傫����ݒ�
	Snowman_Stage2[4].SetAngle(0.0f);             		//�p�x��ݒ�
	Snowman_Stage2[4].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //�F��ݒ�
	Snowman_Stage2[4].SetHP(20);

	Star_Stage2[1].Init(L"asset/Star_Move_v3.png", 6, 2);//�Ⴞ��܂�������
	Star_Stage2[1].SetPos(2000.0f, -160.0f, 0.0f);		//�ʒu��ݒ�
	Star_Stage2[1].SetSize(180.0f, 90.0f, 0.f);	//�傫����ݒ�
	Star_Stage2[1].SetAngle(0.0f);             		//�p�x��ݒ�
	Star_Stage2[1].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //�F��ݒ�
	Star_Stage2[1].SetHP(40);


	Star_Stage2[2].Init(L"asset/Star_Move_v3.png", 6, 2);//�Ⴞ��܂�������
	Star_Stage2[2].SetPos(5000.0f, -160.0f, 0.0f);		//�ʒu��ݒ�
	Star_Stage2[2].SetSize(180.0f, 90.0f, 0.f);	//�傫����ݒ�
	Star_Stage2[2].SetAngle(0.0f);             		//�p�x��ݒ�
	Star_Stage2[2].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //�F��ݒ�
	Star_Stage2[2].SetHP(40);

	Tonakai_Stage2[1].Init(L"asset/Tonakai_Move_v3.png", 4, 2);//�Ⴞ��܂�������
	Tonakai_Stage2[1].SetPos(2600.0f, -160.0f, 0.0f);		//�ʒu��ݒ�
	Tonakai_Stage2[1].SetSize(180.0f, 90.0f, 0.f);	//�傫����ݒ�
	Tonakai_Stage2[1].SetAngle(0.0f);             		//�p�x��ݒ�
	Tonakai_Stage2[1].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //�F��ݒ�
	Tonakai_Stage2[1].SetHP(60);


	Tonakai_Stage2[2].Init(L"asset/Tonakai_Move_v3.png", 4, 2);//�Ⴞ��܂�������
	Tonakai_Stage2[2].SetPos(7500.0f, -160.0f, 0.0f);		//�ʒu��ݒ�
	Tonakai_Stage2[2].SetSize(180.0f, 90.0f, 0.f);	//�傫����ݒ�
	Tonakai_Stage2[2].SetAngle(0.0f);             		//�p�x��ݒ�
	Tonakai_Stage2[2].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //�F��ݒ�
	Tonakai_Stage2[2].SetHP(60);

	
	
	particle.Init(L"asset/X-removebg-preview.png", 7, 1);//�p�[�e�B�N����������
	particle.SetPos(190.0f, -160.0f, 0.0f);		//�ʒu��ݒ�
	particle.SetSize(100.0f, 100.0f, 0.0f);	//�傫����ݒ�
	particle.SetAngle(0.0f);             		//�p�x��ݒ�
	particle.SetColor(1.0f, 1.0f, 1.0f, 1.0f); //�F��ݒ�

	//���傫��
	changescene = TITLE;//�V�[��������
	framcount = 0;
	framcount2 = 0;
	score = 0;
	presentcount = 0;
	time = 150;
	cleartime = 0;
	item = new Item(1);
	select=1;
	pauseFg = false;

	sound.Play(SOUND_LABEL_BGM002);//BGM���Đ�
}

void Game::Update(void) {
	input.Update();

	Collision collision; // �錾
	collision.canMoveRight = true; // �t���O��������
	collision.canMoveLeft = true; // �t���O��������

	//Item* item;


	//�l�X�V���鏈���̌�ɓ��͏������L�q���邱�� by���{

	switch (changescene)
	{
	case TITLE:
	{

		
		//�L�[���͂Ŗ{��
		if (input.GetKeyTrigger(VK_RETURN)||input.GetButtonPress(XINPUT_B))

		{
			changescene = STAGESELECT;
			//changescene = RESULT;
			
		}
	}
	break;
	case STAGESELECT:
	{
		DirectX::XMFLOAT3 pos = SantaCursor.GetPos();
		pauseFg = false;
		kari = false;
		if (pos.x == -430) { select = 1; }//�X�e�[�W�P
		if (pos.x == 0)    { select = 2; }//�X�e�[�W�Q
		if (pos.x == 430)  { select = 3; }//�{�X

		if (input.GetKeyTrigger(VK_M)) { pos.x = -430; }
		if (select !=3&&input.GetKeyTrigger(VK_D) && Select_MoverightFg == false && Select_MoveleftFg == false || select != 3 && input.GetLeftAnalogStick().x >= 0.5&& Select_MoverightFg == false && Select_MoveleftFg == false)
		{
			Select_MoverightFg = true;
			//sound.Play(SOUND_LABEL_SE005);
			// sound.Stop(SOUND_LABEL_BGM002);//BGM���Đ�
			//���������݂������ɕύX
			SantaCursor.numU = 0;
			SantaCursor.numV = 0;
			StopCheck = false;
		}
		if (select != 1&&input.GetKeyTrigger(VK_A) && Select_MoveleftFg == false && Select_MoverightFg == false || select != 1 && input.GetLeftAnalogStick().x <= -0.5 && Select_MoveleftFg == false && Select_MoverightFg == false)
		{
			Select_MoveleftFg = true;
			//���������������ɕύX
			SantaCursor.numU = 0;
			SantaCursor.numV = 3;
			//sound.Play(SOUND_LABEL_SE005);
			StopCheck = false;
		}

		if (Select_MoverightFg == true) 
		{
			if(select!=3){ pos.x += 10; }
			framcount++; //�t���[���J�E���g
			if (framcount % 5 == 0) //5�t���[���Ɉ��s����
			{
				SantaCursor.numU++;
				if (SantaCursor.numU >= 4)
				{
					SantaCursor.numU = 0;
					SantaCursor.numV++;
					if (SantaCursor.numV >= 2)
					{
						SantaCursor.numV = 0;
					}
				}
			}
			if (pos.x == 0){Select_MoverightFg = false; StopCheck = true;}
			if (pos.x == 430) { Select_MoverightFg = false; StopCheck = true;}
		}

		if (Select_MoveleftFg == true)
		{
			if (select != 1) { pos.x -= 10; }
			framcount++; //�t���[���J�E���g
			if (framcount % 5 == 0) //5�t���[���Ɉ��s����
			{
				SantaCursor.numU++;
				if (SantaCursor.numU >= 4)
				{
					SantaCursor.numU = 0;
					SantaCursor.numV++;
					if (SantaCursor.numV >= 4)
					{
						SantaCursor.numV = 2;
					}
				}
			}
			if (pos.x == 0) { Select_MoveleftFg = false; StopCheck = true;}
			if (pos.x == -430) { Select_MoveleftFg = false; StopCheck = true;}

		}

		//�L�[�{�[�h����
		
		//�L�[���͂Ŗ{��
		if (input.GetKeyTrigger(VK_RETURN) &&select == 1&&StopCheck)
		{
			changescene = STAGE1_LOADING;
			santa_bug = 0;
			sound.Stop(SOUND_LABEL_BGM002);//BGM���Đ�
			sound.Play(SOUND_LABEL_SE003);
		}
		//�X�e�[�W�Q��	
		if (input.GetKeyTrigger(VK_RETURN) && select ==2 && StopCheck)
		{
			changescene = STAGE2_LOADING;
			sound.Stop(SOUND_LABEL_BGM002);//BGM���Đ�
			sound.Play(SOUND_LABEL_SE003);
			santa_bug = 0;
		}
		//�{�X��	
		if (input.GetKeyTrigger(VK_RETURN) && select == 3 && StopCheck)
		{
			changescene = BOSS_LOADING;
			sound.Stop(SOUND_LABEL_BGM002);//BGM���Đ�
			sound.Play(SOUND_LABEL_SE003);
			
			santa_bug = 0;
		}

		//�R���g���[���[����
		if (input.GetButtonTrigger(XINPUT_B) && select == 1 && StopCheck)
		{
			changescene = STAGE1_LOADING;
			sound.Stop(SOUND_LABEL_BGM002);//BGM���Đ�
			sound.Play(SOUND_LABEL_SE003);
			santa_bug = 0;

		}
		//�X�e�[�W�Q��	
		if (input.GetButtonTrigger(XINPUT_B) && select == 2 && StopCheck)
		{
			changescene = STAGE2_LOADING;
			sound.Stop(SOUND_LABEL_BGM002);//BGM���Đ�
			sound.Play(SOUND_LABEL_SE003);
			santa_bug = 0;
		}
		//�{�X��	
		if (input.GetButtonTrigger(XINPUT_B) && select == 3 && StopCheck)
		{
			changescene = BOSS_LOADING;
			sound.Stop(SOUND_LABEL_BGM002);//BGM���Đ�
			sound.Play(SOUND_LABEL_SE003);
		
			santa_bug = 0;

		}


		SantaCursor.SetPos(pos.x,pos.y,pos.z);

	}
	break;
	//�X�e�[�W�I��������ɏo����
	case STAGE1_LOADING:
	{
		//sound.Stop(SOUND_LABEL_BGM000);
		kari = false;
		pauseFg = false;
		framcount++;
		if (framcount % 100 == 0) //�Q�b�ギ�炢�ŃV�[���؂�ւ�
		{

			//������
			enemylive1 = true;
			enemylive2 = true;
			enemylive3 = true;
			enemylive4 = true;
			enemylive5 = true;
			enemylive6 = true;
			enemylive7 = true;
			enemylive8 = true;
			enemylive9 = true;
			rocklive = true;
			santa_bug = 0;


			DirectX::XMFLOAT3 tree_pos = tree.GetPos();
			float tree_angle = tree.GetAngle();
			tree_pos.x = 1900;
			tree_pos.y = -70;
			tree_angle = 0.0f;

			tree.SetPos(tree_pos.x, tree_pos.y, tree_pos.z);
			tree.SetAngle(tree_angle);
			tree_Fg = false;
			tree_Ground = 2;


			attackhit = false;
			time = 150;
			framcount = 0;
			framcount2 = 0;
			score = 0;
			presentcount = 0;
			bigpresentcount = 0;
			time = 150;
			cleartime = 0;
			changescene = STAGE_1;
			sound.Play(SOUND_LABEL_BGM000);//BGM���Đ�
			sound.SetVolume(SOUND_LABEL_BGM000, 0.5f);//���Ƃ̉��ʂ�80�p�[�Z���g�ɐݒ�
		
		}
	}
	break;
	case STAGE2_LOADING:
	{
		sound.Stop(SOUND_LABEL_BGM002);
		kari = false;
		pauseFg = false;
		framcount++;
		if (framcount % 100 == 0) //�Q�b�ギ�炢�ŃV�[���؂�ւ�
		{
			//������
			enemylive1 = true;
			enemylive2 = true;
			enemylive3 = true;
			enemylive4 = true;
			enemylive5 = true;
			enemylive6 = true;
			enemylive7 = true;
			enemylive8 = true;
			enemylive9 = true;
			rocklive = true;
			framcount = 0;
			framcount2 = 0;
			score = 0;
			presentcount = 0;
			bigpresentcount = 0;
			time = 150;
			cleartime = 0;
			changescene = STAGE_2;

			sound.Play(SOUND_LABEL_BGM000);//BGM���Đ�
			sound.SetVolume(SOUND_LABEL_BGM000, 0.8f);//���Ƃ̉��ʂ�80�p�[�Z���g�ɐݒ�
			
		}
	}
	break;
	case BOSS_LOADING:
	{

		sound.Stop(SOUND_LABEL_BGM002);
		kari = false;
		pauseFg = false;
		framcount++;
		bossImage = 0;
		if (framcount % 100 == 0) //�Q�b�ギ�炢�ŃV�[���؂�ւ�
		{
			//������
			enemylive1 = true;
			enemylive2 = true;
			enemylive3 = true;
			enemylive4 = true;
			enemylive5 = true;
			enemylive6 = true;
			enemylive7 = true;
			enemylive8 = true;
			enemylive9 = true;
			rocklive = true;
			framcount = 0;
			framcount2 = 0;
			score = 0;
			presentcount = 0;
			bigpresentcount = 0;
			time = 150;
			cleartime = 0;
			changescene = BOSS;

			sound.Play(SOUND_LABEL_BGM003);
			sound.SetVolume(SOUND_LABEL_BGM003, 0.8f);//���Ƃ̉��ʂ�80�p�[�Z���g�ɐݒ�

		}
	}
	break;
	case STAGE_1:
	{
		//�T���^ �ʏ��
		DirectX::XMFLOAT3 santa_pos =  santa_Nor[0].GetPos();
		DirectX::XMFLOAT3 santa_pos1 = santa_Nor[1].GetPos();
		DirectX::XMFLOAT3 santa_pos2 = santa_Nor[2].GetPos();
		DirectX::XMFLOAT3 santa_pos3 = santa_Nor[3].GetPos();
		DirectX::XMFLOAT3 santa_pos4 = santa_Nor[4].GetPos();
		DirectX::XMFLOAT3 santa_pos5 = santa_Nor[5].GetPos();
		DirectX::XMFLOAT3 santa_pos6 = santa_Nor[6].GetPos();
		DirectX::XMFLOAT3 santa_pos7 = santa_Nor[7].GetPos();
		//�T���^ ���C�~
		DirectX::XMFLOAT3 santa_huro_pos = santa_Huro[0].GetPos();
		DirectX::XMFLOAT3 santa_huro_pos1 = santa_Huro[1].GetPos();
		DirectX::XMFLOAT3 santa_huro_pos2 = santa_Huro[2].GetPos();
		DirectX::XMFLOAT3 santa_huro_pos3 = santa_Huro[3].GetPos();
		DirectX::XMFLOAT3 santa_huro_pos4 = santa_Huro[4].GetPos();
		DirectX::XMFLOAT3 santa_huro_pos5 = santa_Huro[5].GetPos();
		DirectX::XMFLOAT3 santa_huro_pos6 = santa_Huro[6].GetPos();
		DirectX::XMFLOAT3 santa_huro_pos7 = santa_Huro[7].GetPos();
		//�T���^ �В���
		DirectX::XMFLOAT3 santa_kin_pos = santa_Kin[0].GetPos();
		DirectX::XMFLOAT3 santa_kin_pos1 = santa_Kin[1].GetPos();
		DirectX::XMFLOAT3 santa_kin_pos2 = santa_Kin[2].GetPos();
		DirectX::XMFLOAT3 santa_kin_pos3 = santa_Kin[3].GetPos();
		DirectX::XMFLOAT3 santa_kin_pos4 = santa_Kin[4].GetPos();
		DirectX::XMFLOAT3 santa_kin_pos5 = santa_Kin[5].GetPos();
		DirectX::XMFLOAT3 santa_kin_pos6 = santa_Kin[6].GetPos();
		//�В���
		DirectX::XMFLOAT3 kintyaku_pos = kintyaku[0].GetPos();
		DirectX::XMFLOAT3 kintyaku_pos1 = kintyaku[1].GetPos();
		DirectX::XMFLOAT3 himo_pos = himo.GetPos();
		DirectX::XMFLOAT3 himo_size = himo.GetSize();
		//�S�[��
		DirectX::XMFLOAT3 goal_pos = goal.GetPos();
		//�R
		DirectX::XMFLOAT3 mounten_pos1 = mounten[1].GetPos();
		DirectX::XMFLOAT3 mounten_pos2 = mounten[2].GetPos();
		DirectX::XMFLOAT3 mounten_pos3 = mounten[3].GetPos();

		//�w�i�̖�
		DirectX::XMFLOAT3 wood_pos1 = wood[1].GetPos();
		DirectX::XMFLOAT3 wood_pos2 = wood[2].GetPos();
		DirectX::XMFLOAT3 wood_pos3 = wood[3].GetPos();

		DirectX::XMFLOAT3 tree_pos = tree.GetPos();
		float tree_angle = tree.GetAngle();


		//�n��
		DirectX::XMFLOAT3 ground_pos1 = ground[1].GetPos();
		DirectX::XMFLOAT3 ground_pos2 = ground[2].GetPos();
		DirectX::XMFLOAT3 ground_pos3 = ground[3].GetPos();
		DirectX::XMFLOAT3 ground_pos4 = ground[4].GetPos();
		DirectX::XMFLOAT3 ground_pos5 = ground[5].GetPos();

		//����
		DirectX::XMFLOAT3 rock_pos1 = rock[1].GetPos();
		DirectX::XMFLOAT3 rock_pos2 = rock[2].GetPos();
		DirectX::XMFLOAT3 rock_pos3 = rock[3].GetPos();
		DirectX::XMFLOAT3 rock_pos4 = rock[4].GetPos();
		DirectX::XMFLOAT3 rock_pos5 = rock[5].GetPos();
		DirectX::XMFLOAT3 rock_pos6 = rock[6].GetPos();

		//���
		DirectX::XMFLOAT3 snowball_pos1 = snowball[1].GetPos();
		DirectX::XMFLOAT3 snowball_pos2 = snowball[2].GetPos();
		DirectX::XMFLOAT3 snowball_pos3 = snowball[3].GetPos();

		//�K�i
		DirectX::XMFLOAT3 stairs_pos1 = stairs[1].GetPos();
		DirectX::XMFLOAT3 stairs_pos2 = stairs[2].GetPos();
		DirectX::XMFLOAT3 stairs_pos3 = stairs[3].GetPos();
		DirectX::XMFLOAT3 stairs_pos4 = stairs[4].GetPos();

		//�G
		DirectX::XMFLOAT3 snowman_pos1 = snowman[1].GetPos();          //��̓G
		DirectX::XMFLOAT3 snowman_pos2 = snowman[2].GetPos();		   //��̓G
		DirectX::XMFLOAT3 snowman_pos3 = snowman[3].GetPos();		   //��̓G
		DirectX::XMFLOAT3 star_monster_pos = star_monster.GetPos();	   //���̓G
		DirectX::XMFLOAT3 tonakai_pos = tonakai.GetPos();			   //���̓G
	
		//�U���̓����蔻��
		DirectX::XMFLOAT3 hitboxpos = hitbox.GetPos();



		int snowman_hp1 = snowman[1].GetHP();          //��̓G
		int snowman_hp2 = snowman[2].GetHP();		   //��̓G
		int snowman_hp3 = snowman[3].GetHP();		   //��̓G

		int  star_monster_hp1 = star_monster.GetHP();          //�ق��̓G
		int tonakai_hp = tonakai.GetHP();	                   //�g�i�J�C�̓G
		int santa_atk = santa_Nor[7].GetATK();
		//�v���[���g
		DirectX::XMFLOAT3 present_pos1 = present[1].GetPos();
		DirectX::XMFLOAT3 present_pos2 = present[2].GetPos();
		DirectX::XMFLOAT3 present_pos3 = present[3].GetPos();
		//�v���[���g��
		DirectX::XMFLOAT3 bigpresent_pos1 = BigPresent[1].GetPos();

		//�������@����
		DirectX::XMFLOAT3 use_rock_pos1 = use_rock[0].GetPos();
		DirectX::XMFLOAT3 use_rock_pos2 = use_rock[1].GetPos();
		DirectX::XMFLOAT3 use_rock_pos3 = use_rock[2].GetPos();

		//�������@���
		DirectX::XMFLOAT3 use_snowball_pos1 = use_snowball[0].GetPos();
		DirectX::XMFLOAT3 use_snowball_pos2 = use_snowball[1].GetPos();
		DirectX::XMFLOAT3 use_snowball_pos3 = use_snowball[2].GetPos();

		DirectX::XMFLOAT3 cursor_pos = Cursor.GetPos();
		DirectX::XMFLOAT3 cursor1_pos = PauseCursor.GetPos();

		DirectX::XMFLOAT3 wall_pos1 = invisiblewall[1].GetPos();
		DirectX::XMFLOAT3 wall_pos2 = invisiblewall[2].GetPos();

		DirectX::XMFLOAT3 particlepos = particle.GetPos();

		//item->GetItem_1();

		// ��U���ŏd�͓I�Ȃ��̂���ǉ����܂��@�S���C
		//santa_pos.y -= 1;
		
		if (direction == 0)
		{
			hitboxpos.x = santa_pos.x + 60;
			hitboxpos.y = santa_pos.y;
		}
		if (direction == 1)
		{
			hitboxpos.x = santa_pos.x - 60;
			hitboxpos.y = santa_pos.y;
		}

		

		// �T���^�����ɗ��������ɏ����ʒu�ɖ߂鏈���@�S���C
	/*	if (santa_pos.y == -250.0f)
		{
			santa_pos.x = -400.0f;
			santa_pos.y = -175.0f;
		}*/


		framcount2++;
		if (framcount2 % 10 == 0) //�P�O�t���[���Ɉ��s����
		{
			snowman[1].numU++;
			snowman[2].numU++;
			snowman[3].numU++;
			star_monster.numU++;
			tonakai.numU++;
			if (snowman[1].numU >= 4 || snowman[2].numU >= 4 || snowman[3].numU >= 4 || tonakai.numU >= 4)
			{
				snowman[1].numU = 0;
				snowman[2].numU = 0;
				snowman[3].numU = 0;
				star_monster.numU = 0;
				tonakai.numU = 0;


				tonakai.numU = 0;
			}
			if (star_monster.numU >= 6)
			{
				star_monster.numU = 0;
			}
		}

		//�|�[�Y���
		if (input.GetKeyTrigger(VK_P) && pauseFg == false || input.GetButtonPress(XINPUT_START) && pauseFg == false)
		{
			pauseFg = true;
		}

		if (pauseFg == true)
		{			
			sound.Stop(SOUND_LABEL_BGM000);
			if (cursor1_pos.y == 100)
			{

				if (input.GetKeyTrigger(VK_S) || input.GetLeftAnalogStick().y < -0.5)
				{
					
					cursor1_pos.y = -100;
					cursor1_pos.x = 350;
				}
				
				//�L�[����
				if (input.GetKeyTrigger(VK_RETURN)|| input.GetButtonTrigger(XINPUT_B))
				{
					sound.Resume(SOUND_LABEL_BGM000);
					pauseFg = false;
				}
			}
		
			if (cursor1_pos.y ==-100)
			{
				if (input.GetKeyTrigger(VK_W) || input.GetLeftAnalogStick().y >0.5)
				{
					cursor1_pos.y = 100;
					cursor1_pos.x = 250;
				}
				//�L�[����
				if (input.GetKeyTrigger(VK_RETURN) || input.GetButtonTrigger(XINPUT_B))
				{
					changescene = TITLE;
					//������
					santa_pos.x = -400;
					santa_pos.y = -175;

					santa_huro_pos.x = -400;
					santa_huro_pos.y = -170;

					santa_kin_pos.x = -400;
					santa_kin_pos.y = -160;

					attackhit = false;

					mounten_pos1.x = 0;
					mounten_pos2.x = 1280;
					mounten_pos3.x = 2560;

					wood_pos1.x = 0;
					wood_pos2.x = 1280;
					wood_pos3.x = 2560;

					rock_pos1.x = -250;
					rock_pos2.x = 300;
					rock_pos3.x = 1100;
					rock_pos4.x = 1100;
					rock_pos5.x = 2300;
					rock_pos6.x = 4400;

					snowball_pos1.x = 1500;
					snowball_pos2.x = 2900;
					snowball_pos3.x = 4000;

					ground_pos1.x = 0;
					ground_pos2.x = 1300;
					ground_pos3.x = 3100;
					ground_pos4.x = 4500;
					ground_pos5.x = 5300;

					stairs_pos1.x = 540;
					stairs_pos2.x = 565;
					stairs_pos3.x = 600;
					stairs_pos4.x = 2800;

					snowman_pos1.x = 30;
					snowman_pos2.x = 1400;
					snowman_pos3.x = 2700;

					bigpresent_pos1.x = 5400;
					bigpresent_pos1.y = -25;

					star_monster_pos.x = 4800;
					tonakai_pos.x = 3600;

					present_pos1.x = 800;
					present_pos2.x = 2800;
					present_pos3.x = 4500;

					present_pos1.y = -25;
					present_pos2.y = 160;
					present_pos3.y= -300;

					wall_pos1.x = -600;
					wall_pos2.x = 5750;


					tree_pos.x = 1900;
					goal_pos.x = 5800;
				}
			}
		}

		//��������
		if (framcount2 % 60 == 0&&pauseFg==false)//1�b�Ɉ��s����
		{
			time--;

		}

		

		if (time <= 0&& gameoverFg == false|| santa_pos.y < -420 && !gameoverFg)//�^�C���I�[�o�[�ɂȂ�����
		{
			gameoverFg = true;
			sound.Play(SOUND_LABEL_BGM001);//BGM���Đ�
		}
		if (gameoverFg == true)
		{
			sound.Stop(SOUND_LABEL_BGM000);

			if (cursor_pos.y == -100)
			{
				if (input.GetKeyTrigger(VK_S) ||input.GetLeftAnalogStick().y<-0.5)
				{
					cursor_pos.y = -200;
				}

				if (input.GetKeyTrigger(VK_RETURN)||input.GetButtonTrigger(XINPUT_B))
				{
					changescene = STAGE1_LOADING;//���g���C
					gameoverFg = false;
					//������

					attackhit = false;
					time = 150;
					framcount = 0;
					framcount2 = 0;
					score = 0;
					presentcount = 0;
					time = 150;
					cleartime = 0;
					jumpVelocity = 0.0f;

					santa_pos.x = -400;
					santa_pos.y = -175;

					santa_huro_pos.x = -400;
					santa_huro_pos.y = -175;

					santa_kin_pos.x = -400;
					santa_kin_pos.y = -160;

					mounten_pos1.x = 0;
					mounten_pos2.x = 1280;
					mounten_pos3.x = 2560;

					wood_pos1.x = 0;
					wood_pos2.x = 1280;
					wood_pos3.x = 2560;

					rock_pos1.x = -250;
					rock_pos2.x = 300;
					rock_pos3.x = 1100;
					rock_pos4.x = 1100;
					rock_pos5.x = 2300;
					rock_pos6.x = 4400;

					snowball_pos1.x = 1500;
					snowball_pos2.x = 2900;
					snowball_pos3.x = 4000;

					ground_pos1.x = 0;
					ground_pos2.x = 1300;
					ground_pos3.x = 3100;
					ground_pos4.x = 4500;
					ground_pos5.x = 5300;

					stairs_pos1.x = 540;
					stairs_pos2.x = 565;
					stairs_pos3.x = 600;
					stairs_pos4.x = 2800;

					snowman_pos1.x = 30;
					snowman_pos2.x = 1400;
					snowman_pos3.x = 2700;

					bigpresent_pos1.x = 5400;

					star_monster_pos.x = 4800;
					tonakai_pos.x = 3600;

					present_pos1.x = 800;
					present_pos2.x = 2800;
					present_pos3.x = 4500;

					present_pos1.y = -25;
					present_pos2.y = 160;
					present_pos3.y = -300;
					bigpresent_pos1.y = -25;

					wall_pos1.x = -600;
					wall_pos2.x = 5750;

					tree_pos.x = 1900;
					goal_pos.x = 5800;

				}
			}

			if (cursor_pos.y == -200)
			{
				if (input.GetKeyTrigger(VK_W)||input.GetLeftAnalogStick().y > 0.5)
				{
					cursor_pos.y = -100;
				}

				if (input.GetKeyTrigger(VK_RETURN) || input.GetButtonTrigger(XINPUT_B))
				{
					changescene = TITLE;//�^�C�g��
					gameoverFg = false;
					//������
					time = 150;
					framcount = 0;
					framcount2 = 0;
					score = 0;
					presentcount = 0;
					time = 150;
					cleartime = 0;
					jumpVelocity = 0.0f;
					santa_pos.x = -400;
					santa_pos.y = -175;

					santa_huro_pos.x = -400;
					santa_huro_pos.y = -175;

					santa_kin_pos.x = -400;
					santa_kin_pos.y = -160;

					mounten_pos1.x = 0;
					mounten_pos2.x = 1280;
					mounten_pos3.x = 2560;

					wood_pos1.x = 0;
					wood_pos2.x = 1280;
					wood_pos3.x = 2560;

					rock_pos1.x = -250;
					rock_pos2.x = 300;
					rock_pos3.x = 1100;
					rock_pos4.x = 1100;
					rock_pos5.x = 2300;
					rock_pos6.x = 4400;

					snowball_pos1.x = 1500;
					snowball_pos2.x = 2900;
					snowball_pos3.x = 4000;

					ground_pos1.x = 0;
					ground_pos2.x = 1300;
					ground_pos3.x = 3100;
					ground_pos4.x = 4500;
					ground_pos5.x = 5300;

					stairs_pos1.x = 540;
					stairs_pos2.x = 565;
					stairs_pos3.x = 600;
					stairs_pos4.x = 2800;

					snowman_pos1.x = 30;
					snowman_pos2.x = 1400;
					snowman_pos3.x = 2700;
					

					bigpresent_pos1.x = 5400;

					star_monster_pos.x = 4800;
					tonakai_pos.x = 3600;

					present_pos1.x = 800;
					present_pos2.x = 2800;
					present_pos3.x = 4500;

					present_pos1.y = -25;
					present_pos2.y = 160;
					present_pos3.y = -300;
					bigpresent_pos1.y = -25;

					wall_pos1.x = -600;
					wall_pos1.x = 5750;

					tree_pos.x = 1900;
					goal_pos.x = 5800;

				}

			}
		}

		



		//-------�G�ړ�--------//
		//�Ⴞ��܁i�P�j
		if (moveFg1 == false && pauseFg == false)
		{
			snowman[1].numV = 0;
			snowman_pos1.x -= 1;
			if (snowman_pos1.x < ground_pos1.x - 240)//���͂��ɍs������
			{
				moveFg1 = true;
			}
		}

		if (moveFg1 == true && pauseFg == false)
		{

			snowman[1].numV = 1;
			snowman_pos1.x += 1;
			if (snowman_pos1.x > ground_pos1.x + 240)//�E�[�ɍs������
			{
				moveFg1 = false;
			}
		}

		//�Ⴞ��܁i2�j
		if (moveFg2 == false && pauseFg == false)
		{
			snowman[2].numV = 0;
			snowman_pos2.x -= 1;
			if (snowman_pos2.x < ground_pos2.x - 180)//���͂��ɍs������
			{
				moveFg2 = true;
			}
		}

		if (moveFg2 == true && pauseFg == false)
		{
			snowman[2].numV = 1;
			snowman_pos2.x += 1;
			if (snowman_pos2.x > ground_pos2.x + 240)//�E�[�ɍs������
			{
				moveFg2 = false;
			}
		}

		//�Ⴞ��܁i3�j
		if (moveFg3 == false && pauseFg == false)
		{
			snowman[3].numV = 0;
			snowman_pos3.x -= 1;
			if (snowman_pos3.x < ground_pos3.x - 700)//���ɍs������
			{
				moveFg3 = true;
			}
		}

		if (moveFg3 == true && pauseFg == false)
		{
			snowman[3].numV = 1;
			snowman_pos3.x += 1;
			if (snowman_pos3.x > ground_pos3.x - 200)//�E�[�ɍs������
			{
				moveFg3 = false;
			}
		}

		//���̓G�i�P)

		if (moveFg4 == false && pauseFg == false)
		{
			star_monster.numV = 0;
			star_monster_pos.x -= 2;
			if (star_monster_pos.x < ground_pos3.x - 130)//���ɍs������
			{
				moveFg4 = true;
			}
		}

		if (moveFg4 == true && pauseFg == false)
		{
			star_monster.numV = 1;
			star_monster_pos.x += 2;
			if (star_monster_pos.x > ground_pos3.x + 700)//�E�[�ɍs������
			{
				moveFg4 = false;
			}
		}


		//�g�i�J�C�̓G
		if (moveFg5 == false && pauseFg == false)
		{
			tonakai.numV = 0;
			tonakai_pos.x -= 2;
			if (tonakai_pos.x < ground_pos5.x - 400)//���ɍs������
			{
				moveFg5 = true;
			}
		}

		if (moveFg5 == true && pauseFg == false)
		{
			tonakai.numV = 1;
			tonakai_pos.x += 2;
			if (tonakai_pos.x > ground_pos5.x + 200)//�E�[�ɍs������
			{
				moveFg5 = false;
			}
		}


		hitcooltime++;
		//�G�ɓ����������Q�b���G��
		if (hitcooltime % 80 == 0&&HitFg==true)
		{
			HitFg = false;//
		}


		

		// �T���^���A�C�e���ɓ���������
		bool itemCollected = false; // �A�C�e�������ɉ�����ꂽ���ǂ����̃t���O

		const float rightScreen = 670.0f; // ��ʂ̉E�[
		const float leftScreen = -670.0f; // ��ʂ̍��[


		// �܂̐؂�ւ�
		if (input.GetKeyTrigger(VK_UP)||input.GetButtonTrigger(XINPUT_UP))
		{
			santa_bug = 0;

		}

		if (input.GetKeyTrigger(VK_LEFT) || input.GetButtonTrigger(XINPUT_LEFT))
		{
			santa_bug = 1;
		}

		if (input.GetKeyTrigger(VK_RIGHT) || input.GetButtonTrigger(XINPUT_RIGHT))
		{
			santa_bug = 2;
		}
		
		

		santa_pos1.x = santa_pos.x;
		santa_pos1.y = santa_pos.y;
		santa_pos2.x = santa_pos.x;
		santa_pos2.y = santa_pos.y;
		santa_pos3.x = santa_pos.x;
		santa_pos3.y = santa_pos.y;
		santa_pos4.x = santa_pos.x;
		santa_pos4.y = santa_pos.y;
		santa_pos5.x = santa_pos.x;
		santa_pos5.y = santa_pos.y;
		santa_pos6.x = santa_pos.x;
		santa_pos6.y = santa_pos.y;
		santa_pos7.x = santa_pos.x;
		santa_pos7.y = santa_pos.y;

		santa_huro_pos1.x = santa_huro_pos.x;
		santa_huro_pos1.y = santa_huro_pos.y;
		santa_huro_pos2.x = santa_huro_pos.x;
		santa_huro_pos2.y = santa_huro_pos.y;
		santa_huro_pos3.x = santa_huro_pos.x;
		santa_huro_pos3.y = santa_huro_pos.y;
		santa_huro_pos4.x = santa_huro_pos.x;
		santa_huro_pos4.y = santa_huro_pos.y;
		santa_huro_pos5.x = santa_huro_pos.x;
		santa_huro_pos5.y = santa_huro_pos.y;
		santa_huro_pos6.x = santa_huro_pos.x;
		santa_huro_pos6.y = santa_huro_pos.y;
		santa_huro_pos7.x = santa_huro_pos.x;
		santa_huro_pos7.y = santa_huro_pos.y;

		santa_kin_pos1.x = santa_kin_pos.x;
		santa_kin_pos1.y = santa_kin_pos.y;
		santa_kin_pos2.x = santa_kin_pos.x;
		santa_kin_pos2.y = santa_kin_pos.y;
		santa_kin_pos3.x = santa_kin_pos.x;
		santa_kin_pos3.y = santa_kin_pos.y;
		santa_kin_pos4.x = santa_kin_pos.x;
		santa_kin_pos4.y = santa_kin_pos.y;
		santa_kin_pos5.x = santa_kin_pos.x;
		santa_kin_pos5.y = santa_kin_pos.y;
		santa_kin_pos6.x = santa_kin_pos.x;
		santa_kin_pos6.y = santa_kin_pos.y;

		

		// �ʏ��
		if (santa_bug == 0){


			santa_huro_pos.x = santa_pos.x;
			santa_kin_pos.x = santa_pos.x;

			santa_huro_pos.y = santa_pos.y;
			santa_kin_pos.y = santa_pos.y;


			// �Ⴞ��܂Ƃ̓����蔻��ǉ� 

			if (collision.enemy_santa(snowman[1], santa_Nor[0], 200.0f, 0.0f) && HitFg == false && pauseFg == false && gameoverFg == false)
			{
				time -= 5;
				hitcooltime = 0;
				sound.Play(SOUND_LABEL_SE000);
				damage5 = true;
				HitFg = true;
			}

			if (collision.enemy_santa(snowman[2], santa_Nor[0], 200.0f, 0.0f) && HitFg == false && pauseFg == false && gameoverFg == false)
			{
				time -= 5;
				hitcooltime = 0;
				sound.Play(SOUND_LABEL_SE000);
				damage5 = true;
				HitFg = true;
			}

			if (collision.enemy_santa(snowman[3], santa_Nor[0], 200.0f, 0.0f) && HitFg == false && pauseFg == false && gameoverFg == false)
			{
				time -= 5;
				hitcooltime = 0;
				sound.Play(SOUND_LABEL_SE000);
				damage5 = true;
				HitFg = true;
			}

			// ���Ƃ̓����蔻��ǉ� 
			if (collision.enemy_santa(star_monster, santa_Nor[0], 200.0f, 0.0f) && HitFg == false && pauseFg == false && gameoverFg == false)
			{
				sound.Play(SOUND_LABEL_SE000);
				time -= 5;
				hitcooltime = 0;
				damage5 = true;
				HitFg = true;
			}
			//�g�i�J�C �Ƃ̓����蔻��ǉ� 
			if (collision.enemy_santa(tonakai, santa_Nor[0], 200.0f, 0.0f) && HitFg == false && pauseFg == false && gameoverFg == false)
			{
				sound.Play(SOUND_LABEL_SE000);
				time -= 5;
				hitcooltime = 0;
				damage5 = true;
				HitFg = true;
			}


			//�v���[���g�̓����蔻��
			if (collision.item_santa(present[1], santa_Nor[0], 100.0f, 0.0f) && pauseFg == false)

			{
				presentcount += 1;
				score += 5000;
				present_pos1.y = 100000;
				sound.Play(SOUND_present);
			}

			if (collision.item_santa(present[2], santa_Nor[0], 100.0f, 0.0f))
			{
				presentcount += 1;
				score += 5000;
				present_pos2.y = 100000;
				sound.Play(SOUND_present);
			}

			if (collision.item_santa(present[3], santa_Nor[0], 100.0f, 0.0f))
			{
				presentcount += 1;
				score += 5000;
				present_pos3.y = 100000;
				sound.Play(SOUND_present);
			}

			if (collision.item_santa(BigPresent[1], santa_Nor[0], 100.0f, 0.0f))
			{
				bigpresentcount += 1;
				score += 10000;
				bigpresent_pos1.y = 100000;
				sound.Play(SOUND_present);
			}


			// �K�i�̓����蔻��@�l��
			//�K�i�����蔻��
			if (collision.block_santa(stairs[1], santa_Nor[0], 100.0f, 0.0f))
			{
				if (santa_pos.y > stairs_pos1.y + stairs[1].GetSize().y / 2.0f) {
					santa_pos.y = stairs_pos1.y + stairs[1].GetSize().y / 2.0f + santa_Nor[0].GetSize().y / 2.0f;
					jumpVelocity = 0.0f;
					/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
				}
				else {
					/*std::cout << "\nSanta is falling." << std::endl;*/
				}

				if (santa_pos.x < stairs_pos1.x)
				{
					collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
				}

				// �T���^���Ԃ������ꍇ
				if (santa_pos.x > stairs_pos1.x)
				{
					collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
				}
			}

			if (collision.block_santa(stairs[2], santa_Nor[0], 100.0f, 0.0f))
			{
				if (santa_pos.y > stairs_pos2.y + stairs[2].GetSize().y / 2.0f) {
					santa_pos.y = stairs_pos2.y + stairs[2].GetSize().y / 2.0f + santa_Nor[0].GetSize().y / 2.0f;
					jumpVelocity = 0.0f;
					/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
				}
				else {
					/*std::cout << "\nSanta is falling." << std::endl;*/
				}

				if (santa_pos.x < stairs_pos2.x)
				{
					collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
				}

				// �T���^���Ԃ������ꍇ
				if (santa_pos.x > stairs_pos2.x)
				{
					collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
				}
			}
			if (collision.block_santa(stairs[3], santa_Nor[0], 100.0f, 0.0f))
			{
				if (santa_pos.y > stairs_pos3.y + stairs[3].GetSize().y / 2.0f) {
					santa_pos.y = stairs_pos3.y + stairs[3].GetSize().y / 2.0f + santa_Nor[0].GetSize().y / 2.0f;
					jumpVelocity = 0.0f;
					/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
				}
				else {
					/*std::cout << "\nSanta is falling." << std::endl;*/
				}
				if (santa_pos.x < stairs_pos3.x && santa_pos.y / 2 < stairs_pos3.y / 3)
				{
					collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
				}

				// �T���^���Ԃ������ꍇ
				if (santa_pos.x > stairs_pos3.x && santa_pos.y / 2 < stairs_pos3.y / 3)
				{
					collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
				}
			}

			if (collision.block_santa(stairs[4], santa_Nor[0], 100.0f, 0.0f))
			{
				if (santa_pos.y > stairs_pos4.y + stairs[4].GetSize().y / 2.0f) {
					santa_pos.y = stairs_pos4.y + stairs[4].GetSize().y / 2.0f + santa_Nor[0].GetSize().y / 2.0f;
					jumpVelocity = 0.0f;
					/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
				}
				else {
					/*std::cout << "\nSanta is falling." << std::endl;*/
				}
				if (santa_pos.x < stairs_pos4.x && santa_pos.y / 2 < stairs_pos4.y / 3)
				{
					collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
				}

				// �T���^���Ԃ������ꍇ
				if (santa_pos.x > stairs_pos4.x && santa_pos.y / 2 < stairs_pos4.y / 3)
				{
					collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
				}
			}




			// �n�ʂƂ̓����蔻��̒ǉ� �S���C

			if (collision.ground_santa(ground[1], santa_Nor[0], 50.0f, 0.0f))
			{
				//// �T���^���n�ʂ̏�ɂ���ꍇ
				if (santa_pos.y > ground_pos1.y + ground[1].GetSize().y / 2.0f) {
					santa_pos.y = ground_pos1.y + ground[1].GetSize().y / 2.0f + santa_Nor[0].GetSize().y / 2.0f;
					jumpVelocity = 0.0f;
					/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
				}
				else {
					/*std::cout << "\nSanta is falling." << std::endl;*/
				}

				// �T���^���n�ʂ̉E���ɂԂ������ꍇ
				if (santa_pos.x < ground_pos1.x && santa_pos.y < ground_pos1.y) {

					collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
				}

				// �T���^���n�ʂɂԂ������ꍇ
				if (santa_pos.x > ground_pos1.x && santa_pos.y < ground_pos1.y) {
					collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
				}
			}

			if (collision.ground_santa(ground[2], santa_Nor[0], 50.0f, 0.0f))
			{
				//// �T���^���n�ʂ̏�ɂ���ꍇ
				if (santa_pos.y > ground_pos2.y + ground[2].GetSize().y / 2.0f) {
					santa_pos.y = ground_pos2.y + ground[2].GetSize().y / 2.0f + santa_Nor[0].GetSize().y / 2.0f;
					jumpVelocity = 0.0f;
					/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
				}
				else {
					/*std::cout << "\nSanta is falling." << std::endl;*/
				}

				// �T���^���n�ʂ̉E���ɂԂ������ꍇ
				if (santa_pos.x < ground_pos2.x && santa_pos.y < ground_pos2.y) {

					collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
				}

				// �T���^���n�ʂɂԂ������ꍇ
				if (santa_pos.x > ground_pos2.x && santa_pos.y < ground_pos2.y) {
					collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
				}
			}

			if (collision.ground_santa(ground[3], santa_Nor[0], 50.0f, 0.0f))
			{
				//// �T���^���n�ʂ̏�ɂ���ꍇ
				if (santa_pos.y > ground_pos3.y + ground[3].GetSize().y / 2.0f) {
					santa_pos.y = ground_pos3.y + ground[3].GetSize().y / 2.0f + santa_Nor[0].GetSize().y / 2.0f;
					jumpVelocity = 0.0f;
					/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
				}
				else {
					/*std::cout << "\nSanta is falling." << std::endl;*/
				}

				// �T���^���n�ʂ̉E���ɂԂ������ꍇ
				if (santa_pos.x < ground_pos3.x && santa_pos.y < ground_pos3.y) {

					collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
				}

				// �T���^���n�ʂɂԂ������ꍇ
				if (santa_pos.x > ground_pos3.x && santa_pos.y < ground_pos3.y) {
					collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
				}
			}

			if (collision.ground_santa(ground[4], santa_Nor[0], 50.0f, 0.0f))
			{
				//// �T���^���n�ʂ̏�ɂ���ꍇ
				if (santa_pos.y > ground_pos4.y + ground[4].GetSize().y / 2.0f) {
					santa_pos.y = ground_pos4.y + ground[4].GetSize().y / 2.0f + santa_Nor[0].GetSize().y / 2.0f;
					jumpVelocity = 0.0f;
					/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
				}
				else {
					/*std::cout << "\nSanta is falling." << std::endl;*/
				}

				// �T���^���n�ʂ̉E���ɂԂ������ꍇ
				if (santa_pos.x < ground_pos4.x && santa_pos4.y < ground_pos4.y) {

					collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
				}

				// �T���^���n�ʂɂԂ������ꍇ
				if (santa_pos.x > ground_pos4.x && santa_pos.y < ground_pos4.y) {
					collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
				}
			}

			if (collision.ground_santa(ground[5], santa_Nor[0], 50.0f, 0.0f))
			{
				//// �T���^���n�ʂ̏�ɂ���ꍇ
				if (santa_pos.y > ground_pos5.y + ground[5].GetSize().y / 2.0f) {
					santa_pos.y = ground_pos5.y + ground[5].GetSize().y / 2.0f + santa_Nor[0].GetSize().y / 2.0f;
					jumpVelocity = 0.0f;
					/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
				}
				else {
					/*std::cout << "\nSanta is falling." << std::endl;*/
				}

				// �T���^���n�ʂ̉E���ɂԂ������ꍇ
				if (santa_pos.x < ground_pos5.x && santa_pos.y < ground_pos5.y) {

					collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
				}

				// �T���^���n�ʂɂԂ������ꍇ
				if (santa_pos.x > ground_pos5.x && santa_pos.y < ground_pos5.y) {
					collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
				}
			}
			if (collision.goal_santa(goal, santa_Nor[0], 250.0f, 0.0f))
			{

				// �T���^���S�[���̉E���ɂԂ������ꍇ
				if (santa_pos.x < goal_pos.x && santa_pos.y < goal_pos.y)
				{

					changescene = RESULT;
					//������
					santa_pos.x = -400;
					santa_pos.y = -175;

					santa_huro_pos.x = -400;
					santa_huro_pos.y = -175;

					santa_kin_pos.x = -400;
					santa_kin_pos.y = -160;

					mounten_pos1.x = 0;
					mounten_pos2.x = 1280;
					mounten_pos3.x = 2560;

					wood_pos1.x = 0;
					wood_pos2.x = 1280;
					wood_pos3.x = 2560;

					wall_pos1.x = -600;
					wall_pos2.x = 5750;

					rock_pos1.x = -250;
					rock_pos2.x = 300;
					rock_pos3.x = 1100;
					rock_pos4.x = 1100;
					rock_pos5.x = 2300;
					rock_pos6.x = 4400;

					snowball_pos1.x = 1500;
					snowball_pos2.x = 2900;
					snowball_pos3.x = 4000;

					ground_pos1.x = 0;
					ground_pos2.x = 1300;
					ground_pos3.x = 3100;
					ground_pos4.x = 4500;
					ground_pos5.x = 5300;

					stairs_pos1.x = 540;
					stairs_pos2.x = 565;
					stairs_pos3.x = 600;
					stairs_pos4.x = 2800;

					snowman_pos1.x = 30;
					snowman_pos2.x = 1400;
					snowman_pos3.x = 2700;

					bigpresent_pos1.x = 5400;

					star_monster_pos.x = 4800;
					tonakai_pos.x = 3600;

					

					present_pos1.x = 800;
					present_pos2.x = 2800;
					present_pos3.x = 4500;

					present_pos1.y = -25;
					present_pos2.y = 160;
					present_pos3.y = -300;
					bigpresent_pos1.y = -25;

					tree_pos.x = 1900;
					goal_pos.x = 5800;
					sound.Stop(SOUND_LABEL_BGM000);
				}

			}

			// �T���^���A�C�e���ɓ���������
			bool itemCollected = false; // �A�C�e�������ɉ�����ꂽ���ǂ����̃t���O

			const float rightScreen = 670.0f; // ��ʂ̉E�[
			const float leftScreen = -670.0f; // ��ʂ̍��[


			if (collision.item_santa(rock[1], santa_Nor[0], 100.0f, 0.0f) && rock_visible1 == 0)
			{
				if (input.GetKeyTrigger(VK_S) && !itemCollected && !sp_ani || input.GetButtonTrigger(XINPUT_B) && !itemCollected && !sp_ani)
				{

					item->ItemGet(1); // ��������
					bugPower = item->GetItemCnt(); // ���݂̑܂̃A�C�e��������
					itemCollected = true;
					santaImage = 4;

					rock_visible1 = 1;

				}
			}

			if (collision.item_santa(rock[2], santa_Nor[0], 100.0f, 0.0f) && rock_visible2 == 0)
			{
				if (input.GetKeyTrigger(VK_S) && !itemCollected && !sp_ani || input.GetButtonTrigger(XINPUT_B) && !itemCollected && !sp_ani)
				{
					/*itemID = 1;*/
					item->ItemGet(1); // ��������
					bugPower = item->GetItemCnt(); // ���݂̑܂̃A�C�e��������
					itemCollected = true;
					santaImage = 4;

					rock_visible2 = 1;
				}
			}

			if (collision.item_santa(rock[3], santa_Nor[0], 100.0f, 0.0f) && rock_visible3 == 0)
			{
				if (input.GetKeyTrigger(VK_S) && !itemCollected && !sp_ani || input.GetButtonTrigger(XINPUT_B) && !itemCollected && !sp_ani)
				{
					/*itemID = 1;*/
					item->ItemGet(1); // ��������
					bugPower = item->GetItemCnt(); // ���݂̑܂̃A�C�e��������
					itemCollected = true;
					santaImage = 4;

					rock_visible3 = 1;
				}
			}

			if (collision.item_santa(rock[4], santa_Nor[0], 100.0f, 0.0f) && rock_visible4 == 0)
			{
				if (input.GetKeyTrigger(VK_S) && !itemCollected && !sp_ani || input.GetButtonTrigger(XINPUT_B) && !itemCollected && !sp_ani)
				{
					/*itemID = 1;*/
					item->ItemGet(1); // ��������
					bugPower = item->GetItemCnt(); // ���݂̑܂̃A�C�e��������
					itemCollected = true;
					santaImage = 4;

					rock_visible4 = 1;
				}
			}

			if (collision.item_santa(rock[5], santa_Nor[0], 100.0f, 0.0f) && rock_visible5 == 0)
			{
				if (input.GetKeyTrigger(VK_S) && !itemCollected && !sp_ani || input.GetButtonTrigger(XINPUT_B) && !itemCollected && !sp_ani)
				{
					/*itemID = 1;*/
					item->ItemGet(1); // ��������
					bugPower = item->GetItemCnt(); // ���݂̑܂̃A�C�e��������
					itemCollected = true;
					santaImage = 4;

					rock_visible5 = 1;
				}
			}

			if (collision.item_santa(rock[6], santa_Nor[0], 100.0f, 0.0f) && rock_visible6 == 0)
			{
				if (input.GetKeyTrigger(VK_S) && !itemCollected && !sp_ani || input.GetButtonTrigger(XINPUT_B) && !itemCollected && !sp_ani)
				{
					/*itemID = 1;*/
					item->ItemGet(1); // ��������
					bugPower = item->GetItemCnt(); // ���݂̑܂̃A�C�e��������
					itemCollected = true;
					santaImage = 4;

					rock_visible6 = 1;
				}
			}

			if (collision.item_santa(snowball[1], santa_Nor[0], 100.0f, 0.0f) && snow_visible1 == 0)
			{
				if (input.GetKeyTrigger(VK_S) && !itemCollected && !sp_ani || input.GetButtonTrigger(XINPUT_B) && !itemCollected && !sp_ani)
				{
					/*itemID = 1;*/
					item->ItemGet(2); // ��������
					bugPower = item->GetItemCnt(); // ���݂̑܂̃A�C�e��������
					itemCollected = true;
					santaImage = 4;

					snow_visible1 = 1;
				}
			}

			if (collision.item_santa(snowball[2], santa_Nor[0], 100.0f, 0.0f) && snow_visible1 == 0)
			{
				if (input.GetKeyTrigger(VK_S) && !itemCollected && !sp_ani || input.GetButtonTrigger(XINPUT_B) && !itemCollected && !sp_ani)
				{
					/*itemID = 1;*/
					item->ItemGet(2); // ��������
					bugPower = item->GetItemCnt(); // ���݂̑܂̃A�C�e��������
					itemCollected = true;
					santaImage = 4;

					snow_visible2 = 1;
				}
			}

			if (collision.item_santa(snowball[3], santa_Nor[0], 100.0f, 0.0f) && snow_visible1 == 0)
			{
				if (input.GetKeyTrigger(VK_S) && !itemCollected && !sp_ani|| input.GetButtonTrigger(XINPUT_B) && !itemCollected && !sp_ani)
				{
					/*itemID = 1;*/
					item->ItemGet(2); // ��������
					bugPower = item->GetItemCnt(); // ���݂̑܂̃A�C�e��������
					itemCollected = true;
					santaImage = 4;

					snow_visible3 = 1;
				}
			}

			// ��ʊO�ɍs���ƁA�A�C�e�����ăX�|�[�����鏈��
			if (leftScreen > rock_pos1.x || rock_pos1.x > rightScreen) {
				rock_visible1 = 0;
			}
			if (leftScreen > rock_pos2.x || rock_pos2.x > rightScreen) {
				rock_visible2 = 0;
			}
			if (leftScreen > rock_pos3.x || rock_pos3.x > rightScreen) {
				rock_visible3 = 0;
			}
			if (leftScreen > rock_pos4.x || rock_pos4.x > rightScreen) {
				rock_visible4 = 0;
			}
			if (leftScreen > rock_pos5.x || rock_pos5.x > rightScreen) {
				rock_visible5 = 0;
			}
			if (leftScreen > rock_pos6.x || rock_pos6.x > rightScreen) {
				rock_visible6 = 0;
			}
			if (leftScreen > snowball_pos1.x || snowball_pos1.x > rightScreen) {
				snow_visible1 = 0;
			}
			if (leftScreen > snowball_pos2.x || snowball_pos2.x > rightScreen) {
				snow_visible2 = 0;
			}
			if (leftScreen > snowball_pos3.x || snowball_pos3.x > rightScreen) {
				snow_visible3 = 0;
			}


			if (!itemCollected && !changeItem) {// �������ĂȂ��ꍇ
				if (input.GetKeyTrigger(VK_S) && pauseFg == false && !sp_ani || input.GetButtonTrigger(XINPUT_B) && pauseFg == false && !sp_ani)
				{

					if (item->GetItem_3() > 0) {
						changeItem = true;

						if (item->GetItem_3() == 1) {
							use_rock_pos3.x = santa_pos.x;
							use_rock_pos3.y = santa_pos.y;
							sound.Play(SOUND_LABEL_SE003);
							itemID_3 = 1;
							itemMove3 = true;
						}
						else if (item->GetItem_3() == 2) {
							use_snowball_pos3.x = santa_pos.x;
							use_snowball_pos3.y = santa_pos.y;
							sound.Play(SOUND_LABEL_SE003);
							itemID_3 = 2;
							itemMove3 = true;
						}

					}
					else if (item->GetItem_3() < 0) {

						if (item->GetItem_2() > 0) {

							if (item->GetItem_2() == 1) {
								use_rock_pos2.x = santa_pos.x;
								use_rock_pos2.y = santa_pos.y;
								sound.Play(SOUND_LABEL_SE003);
								itemID_2 = 1;
								itemMove2 = true;
							}
							else if (item->GetItem_2() == 2) {
								use_snowball_pos2.x = santa_pos.x;
								use_snowball_pos2.y = santa_pos.y;
								sound.Play(SOUND_LABEL_SE003);
								itemID_2 = 2;
								itemMove2 = true;
							}

						}
						else if (item->GetItem_2() < 0) {

							if (item->GetItem_1() > 0) {

								if (item->GetItem_1() == 1) {
									use_rock_pos1.x = santa_pos.x;
									use_rock_pos1.y = santa_pos.y;
									itemID_1 = 1;
									itemMove1 = true;
								}
								else if (item->GetItem_1() == 2) {
									use_snowball_pos1.x = santa_pos.x;
									use_snowball_pos1.y = santa_pos.y;
									itemID_1 = 2;
									itemMove1 = true;
								}

							}
						}
					}

					santaImage = 5;
					item->ItemRelease(); // ���o��
					bugPower = item->GetItemCnt();
				}
			}

			// ����A�j���[�V����
			if (santaImage == 4) {
				getItem = 1;
				if (direction == 0) { // �E����
					if (changeRight_get == true)
					{
						//������
						santa_Nor[4].numU = 0;
						santa_Nor[4].numV = 0;
						changeRight_get = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���
					}
					framcount4++; //�t���[���J�E���g
					if (framcount4 % 4 == 0) //�P�O�t���[���Ɉ��s����
					{
						santa_Nor[4].numU++;
						if (santa_Nor[4].numU >= 5)
						{
							sp_ani = false;
							santaImage = 1;
							getItem = 0;
							santa_Nor[4].numU = 0;

						}
					}
				}
				else if (direction == 1) {
					if (changeLeft_get == true)
					{
						//������
						santa_Nor[4].numU = 0;
						santa_Nor[4].numV = 1;
						changeLeft_get = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���
					}
					framcount4++; //�t���[���J�E���g
					if (framcount4 % 4 == 0) //�P�O�t���[���Ɉ��s����
					{
						santa_Nor[4].numU++;
						if (santa_Nor[4].numU >= 5)
						{
							sp_ani = false;
							santaImage = 1;
							getItem = 0;
							santa_Nor[4].numU = 0;

						}
					}
				}
			}

			// ��o�A�j���[�V����
			if (santaImage == 5) {

				if (direction == 0) { // �E����
					if (changeRight_out == true)
					{
						//������
						santa_Nor[5].numU = 0;
						santa_Nor[5].numV = 0;
						changeRight_out = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���
					}
					framcount5++; //�t���[���J�E���g
					if (framcount5 % 4 == 0) //�P�O�t���[���Ɉ��s����
					{
						santa_Nor[5].numU++;
						if (santa_Nor[5].numU >= 5)
						{
							sp_ani = false;
							if (bugPower > 0) {
								santaImage = 1;
							}
							else if (bugPower == 0) {
								santaImage = 0;
							}

							santa_Nor[5].numU = 0;
							changeRight_out = true;

						}
					}
				}
				else if (direction == 1) {
					if (changeLeft_out == true)
					{
						//������
						santa_Nor[5].numU = 0;
						santa_Nor[5].numV = 1;
						changeLeft_out = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���
					}
					framcount5++; //�t���[���J�E���g
					if (framcount5 % 4 == 0) //�P�O�t���[���Ɉ��s����
					{
						santa_Nor[5].numU++;
						if (santa_Nor[5].numU >= 5)
						{
							sp_ani = false;
							if (bugPower > 0) {
								santaImage = 1;
							}
							else if (bugPower == 0) {
								santaImage = 0;
							}
							santa_Nor[5].numU = 0;
							changeLeft_out = true;

						}
					}
				}
			}

			// �������̓����@���̇@ 
			if (itemMove1 == true) {
				if (direction == 0) { // �E����

					if (itemID_1 == 1) { // ��

						if (itemMove1_M == true || use_rock_pos1.y >= -100.0f) {
							itemMove1_M = true;
							use_rock_pos1.y -= 3.00f;
							use_rock_pos1.x += 3.00f;
						}
						else if (itemMove1_M == false) {
							use_rock_pos1.y += 3.00f;
							use_rock_pos1.x += 3.00f;
						}
						if (use_rock_pos1.y <= -190.0f && itemMove1_M == true) {
							itemID_1 = 0;
							itemMove1_M = false;
							itemMove1 = false;
						}
					}
					else if (itemID_1 == 2) {
						if (use_snowball_pos1.x >= rightScreen) {
							itemID_1 = 0;
							itemMove1 = false;
						}
						else if (use_snowball_pos1.x <= rightScreen) {
							use_snowball_pos1.x += 20.00f;
						}
					}
				}
				else if (direction == 1) { // ������

					if (itemID_1 == 1) { // ��

						if (itemMove1_M == true || use_rock_pos1.y >= -100.0f) {
							itemMove1_M = true;
							use_rock_pos1.y -= 3.00f;
							use_rock_pos1.x -= 3.00f;
						}
						else if (itemMove1_M == false) {
							use_rock_pos1.y += 3.00f;
							use_rock_pos1.x -= 3.00f;
						}
						if (use_rock_pos1.y <= -190.0f && itemMove1_M == true) {
							itemID_1 = 0;
							itemMove1_M = false;
							itemMove1 = false;
						}
					}
					else if (itemID_1 == 2) {
						if (use_snowball_pos1.x <= leftScreen) {
							itemID_1 = 0;
							itemMove1 = false;
						}
						else if (use_snowball_pos1.x >= leftScreen) {
							use_snowball_pos1.x -= 20.00f;
						}
					}
				}



			}

			// �������̓����@���̇A
			if (itemMove2 == true) {
				if (direction == 0) { // �E����

					if (itemID_2 == 1) { //��

						if (itemMove2_M == true || use_rock_pos2.y >= -100.0f) {
							itemMove2_M = true;
							use_rock_pos2.y -= 3.00f;
							use_rock_pos2.x += 3.00f;
						}
						else if (itemMove2_M == false) {
							use_rock_pos2.y += 3.00f;
							use_rock_pos2.x += 3.00f;
						}
						if (use_rock_pos2.y <= -190.0f && itemMove2_M == true) {
							itemID_2 = 0;
							itemMove2_M = false;
							itemMove2 = false;
						}
					}
					else if (itemID_2 == 2) {
						if (use_snowball_pos2.x >= rightScreen) {
							itemID_2 = 0;
							itemMove2 = false;
						}
						else if (use_snowball_pos2.x <= rightScreen) {
							use_snowball_pos2.x += 20.00f;
						}
					}
				}
				else if (direction == 1) { // ������

					if (itemID_2 == 1) { //��

						if (itemMove2_M == true || use_rock_pos2.y >= -100.0f) {
							itemMove2_M = true;
							use_rock_pos2.y -= 3.00f;
							use_rock_pos2.x -= 3.00f;
						}
						else if (itemMove2_M == false) {
							use_rock_pos2.y += 3.00f;
							use_rock_pos2.x -= 3.00f;
						}
						if (use_rock_pos2.y <= -190.0f && itemMove2_M == true) {
							itemID_2 = 0;
							itemMove2_M = false;
							itemMove2 = false;
						}
					}
					else if (itemID_2 == 2) {
						if (use_snowball_pos2.x <= leftScreen) {
							itemID_2 = 0;
							itemMove2 = false;
						}
						else if (use_snowball_pos2.x >= leftScreen) {
							use_snowball_pos2.x -= 20.00f;
						}
					}
				}


			}

			// �������̓����@���̇B
			if (itemMove3 == true) {

				if (direction == 0) { // �E����

					if (itemID_3 == 1) { // ��

						if (itemMove3_M == true || use_rock_pos3.y >= -100.0f) {
							itemMove3_M = true;
							use_rock_pos3.y -= 3.00f;
							use_rock_pos3.x += 3.00f;
						}
						else if (itemMove3_M == false) {
							use_rock_pos3.y += 3.00f;
							use_rock_pos3.x += 3.00f;
						}
						if (use_rock_pos3.y <= -190.0f && itemMove3_M == true) {
							itemID_3 = 0;
							itemMove3_M = false;
							itemMove3 = false;
							changeItem = false;
						}
					}
					else if (itemID_3 == 2) {
						if (use_snowball_pos3.x >= rightScreen) {
							itemID_3 = 0;
							itemMove3 = false;
							changeItem = false;
						}
						else if (use_snowball_pos3.x <= rightScreen) {
							use_snowball_pos3.x += 30.00f;
						}
					}
				}
				else if (direction == 1) { // ������

					if (itemID_3 == 1) { // ��

						if (itemMove3_M == true || use_rock_pos3.y >= -100.0f) {
							itemMove3_M = true;
							use_rock_pos3.y -= 3.00f;
							use_rock_pos3.x -= 3.00f;
						}
						else if (itemMove3_M == false) {
							use_rock_pos3.y += 3.00f;
							use_rock_pos3.x -= 3.00f;
						}
						if (use_rock_pos3.y <= -190.0f && itemMove3_M == true) {
							itemID_3 = 0;
							itemMove3_M = false;
							itemMove3 = false;
							changeItem = false;
						}
					}
					else if (itemID_3 == 2) {
						if (use_snowball_pos3.x <= leftScreen) {
							itemID_3 = 0;
							itemMove3 = false;
							changeItem = false;
						}
						else if (use_snowball_pos3.x >= leftScreen) {
							use_snowball_pos3.x -= 30.00f;
						}
					}
				}


			}


			// �������̓����蔻�� ��

				// �Ⴞ��܂P
			if (collision.square_square(snowman[1], use_rock[0]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp1 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos1.x;
				particlepos.y = snowman_pos1.y;

				if (snowman_hp1 < 0)
				{
					enemylive1 = false;
					snowman_hp1 = 20;
					snowman_pos1.x = 400000000;
				}
			}

			if (collision.square_square(snowman[1], use_rock[1]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp1 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos1.x;
				particlepos.y = snowman_pos1.y;

				if (snowman_hp1 < 0)
				{
					enemylive1 = false;
					snowman_hp1 = 20;
					snowman_pos1.x = 400000000;
				}
			}

			if (collision.square_square(snowman[1], use_rock[2]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp1 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos1.x;
				particlepos.y = snowman_pos1.y;

				if (snowman_hp1 < 0)
				{
					enemylive1 = false;
					snowman_hp1 = 20;
					snowman_pos1.x = 400000000;
				}
			}

			// �Ⴞ��܂Q
			if (collision.square_square(snowman[2], use_rock[0]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp2 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos2.x;
				particlepos.y = snowman_pos2.y;

				if (snowman_hp2 < 0)
				{
					enemylive2 = false;
					snowman_hp2 = 20;
					snowman_pos2.x = 400000000;
				}
			}

			if (collision.square_square(snowman[2], use_rock[1]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp2 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos2.x;
				particlepos.y = snowman_pos2.y;

				if (snowman_hp2 < 0)
				{
					enemylive2 = false;
					snowman_hp2 = 20;
					snowman_pos2.x = 400000000;
				}
			}

			if (collision.square_square(snowman[2], use_rock[2]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp2 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos2.x;
				particlepos.y = snowman_pos2.y;

				if (snowman_hp2 < 0)
				{
					enemylive2 = false;
					snowman_hp2 = 20;
					snowman_pos2.x = 400000000;
				}
			}

			// �Ⴞ���3
			if (collision.square_square(snowman[3], use_rock[0]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp3 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos3.x;
				particlepos.y = snowman_pos3.y;

				if (snowman_hp3 < 0)
				{
					enemylive3 = false;
					snowman_hp3 = 20;
					snowman_pos3.x = 400000000;
				}
			}

			if (collision.square_square(snowman[3], use_rock[1]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp3 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos3.x;
				particlepos.y = snowman_pos3.y;

				if (snowman_hp3 < 0)
				{
					enemylive3 = false;
					snowman_hp3 = 20;
					snowman_pos3.x = 400000000;
				}
			}

			if (collision.square_square(snowman[3], use_rock[2]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp3 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos3.x;
				particlepos.y = snowman_pos3.y;

				if (snowman_hp3 < 0)
				{
					enemylive3 = false;
					snowman_hp3 = 20;
					snowman_pos3.x = 400000000;
				}
			}

			// �N���X�}�X�c���[
			if (collision.square_square(star_monster, use_rock[0]) == true) {
				star_monster_hp1 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = star_monster_pos.x;
				particlepos.y = star_monster_pos.y;
				if (star_monster_hp1 < 0)
				{
					enemylive4 = false;
					star_monster_hp1 = 40;
					star_monster_pos.x = 400000000;
				}
			}

			if (collision.square_square(star_monster, use_rock[1]) == true) {
				star_monster_hp1 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = star_monster_pos.x;
				particlepos.y = star_monster_pos.y;
				if (star_monster_hp1 < 0)
				{
					enemylive4 = false;
					star_monster_hp1 = 40;
					star_monster_pos.x = 400000000;
				}
			}

			if (collision.square_square(star_monster, use_rock[2]) == true) {
				star_monster_hp1 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = star_monster_pos.x;
				particlepos.y = star_monster_pos.y;
				if (star_monster_hp1 < 0)
				{
					enemylive4 = false;
					star_monster_hp1 = 40;
					star_monster_pos.x = 400000000;
				}
			}

			// �g�i�J�C
			if (collision.square_square(tonakai, use_rock[0]) == true) {
				tonakai_hp -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = tonakai_pos.x;
				particlepos.y = tonakai_pos.y;
				if (tonakai_hp < 0)
				{
					enemylive5 = false;
					tonakai_hp = 60;
					tonakai_pos.x = 400000000;
				}
			}

			if (collision.square_square(tonakai, use_rock[1]) == true) {
				tonakai_hp -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = tonakai_pos.x;
				particlepos.y = tonakai_pos.y;
				if (tonakai_hp < 0)
				{
					enemylive5 = false;
					tonakai_hp = 60;
					tonakai_pos.x = 400000000;
				}
			}

			if (collision.square_square(tonakai, use_rock[2]) == true) {
				tonakai_hp -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = tonakai_pos.x;
				particlepos.y = tonakai_pos.y;
				if (tonakai_hp < 0)
				{
					enemylive5 = false;
					tonakai_hp = 60;
					tonakai_pos.x = 400000000;
				}
			}


			// �������̓����蔻�� ���

			// �Ⴞ��܂P
			if (collision.square_square(snowman[1], use_snowball[0]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp1 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos1.x;
				particlepos.y = snowman_pos1.y;

				if (snowman_hp1 < 0)
				{
					enemylive1 = false;
					snowman_hp1 = 20;
					snowman_pos1.x = 400000000;
				}
			}

			if (collision.square_square(snowman[1], use_snowball[1]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp1 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos1.x;
				particlepos.y = snowman_pos1.y;

				if (snowman_hp1 < 0)
				{
					enemylive1 = false;
					snowman_hp1 = 20;
					snowman_pos1.x = 400000000;
				}
			}

			if (collision.square_square(snowman[1], use_snowball[2]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp1 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos1.x;
				particlepos.y = snowman_pos1.y;

				if (snowman_hp1 < 0)
				{
					enemylive1 = false;
					snowman_hp1 = 20;
					snowman_pos1.x = 400000000;
				}
			}

			// �Ⴞ��܂Q
			if (collision.square_square(snowman[2], use_snowball[0]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp2 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos2.x;
				particlepos.y = snowman_pos2.y;

				if (snowman_hp2 < 0)
				{
					enemylive2 = false;
					snowman_hp2 = 20;
					snowman_pos2.x = 400000000;
				}
			}

			if (collision.square_square(snowman[2], use_snowball[1]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp2 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos2.x;
				particlepos.y = snowman_pos2.y;

				if (snowman_hp2 < 0)
				{
					enemylive2 = false;
					snowman_hp2 = 20;
					snowman_pos2.x = 400000000;
				}
			}

			if (collision.square_square(snowman[2], use_snowball[2]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp2 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos2.x;
				particlepos.y = snowman_pos2.y;

				if (snowman_hp2 < 0)
				{
					enemylive2 = false;
					snowman_hp2 = 20;
					snowman_pos2.x = 400000000;
				}
			}

			// �Ⴞ���3
			if (collision.square_square(snowman[3], use_snowball[0]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp3 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos3.x;
				particlepos.y = snowman_pos3.y;

				if (snowman_hp3 < 0)
				{
					enemylive3 = false;
					snowman_hp3 = 20;
					snowman_pos3.x = 400000000;
				}
			}

			if (collision.square_square(snowman[3], use_snowball[1]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp3 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos3.x;
				particlepos.y = snowman_pos3.y;

				if (snowman_hp3 < 0)
				{
					enemylive3 = false;
					snowman_hp3 = 20;
					snowman_pos3.x = 400000000;
				}
			}

			if (collision.square_square(snowman[3], use_snowball[2]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp3 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos3.x;
				particlepos.y = snowman_pos3.y;

				if (snowman_hp3 < 0)
				{
					enemylive3 = false;
					snowman_hp3 = 20;
					snowman_pos3.x = 400000000;
				}
			}

			// �N���X�}�X�c���[
			if (collision.square_square(star_monster, use_snowball[0]) == true) {
				star_monster_hp1 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = star_monster_pos.x;
				particlepos.y = star_monster_pos.y;
				if (star_monster_hp1 < 0)
				{
					enemylive4 = false;
					star_monster_hp1 = 40;
					star_monster_pos.x = 400000000;
				}
			}

			if (collision.square_square(star_monster, use_snowball[1]) == true) {
				star_monster_hp1 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = star_monster_pos.x;
				particlepos.y = star_monster_pos.y;
				if (star_monster_hp1 < 0)
				{
					enemylive4 = false;
					star_monster_hp1 = 40;
					star_monster_pos.x = 400000000;
				}
			}

			if (collision.square_square(star_monster, use_snowball[2]) == true) {
				star_monster_hp1 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = star_monster_pos.x;
				particlepos.y = star_monster_pos.y;
				if (star_monster_hp1 < 0)
				{
					enemylive4 = false;
					star_monster_hp1 = 40;
					star_monster_pos.x = 400000000;
				}
			}

			// �g�i�J�C
			if (collision.square_square(tonakai, use_snowball[0]) == true) {
				tonakai_hp -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = tonakai_pos.x;
				particlepos.y = tonakai_pos.y;
				if (tonakai_hp < 0)
				{
					enemylive5 = false;
					tonakai_hp = 60;
					tonakai_pos.x = 400000000;
				}
			}

			if (collision.square_square(tonakai, use_snowball[1]) == true) {
				tonakai_hp -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = tonakai_pos.x;
				particlepos.y = tonakai_pos.y;
				if (tonakai_hp < 0)
				{
					enemylive5 = false;
					tonakai_hp = 60;
					tonakai_pos.x = 400000000;
				}
			}

			if (collision.square_square(tonakai, use_snowball[2]) == true) {
				tonakai_hp -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = tonakai_pos.x;
				particlepos.y = tonakai_pos.y;
				if (tonakai_hp < 0)
				{
					enemylive5 = false;
					tonakai_hp = 60;
					tonakai_pos.x = 400000000;
				}
			}

			//�p�[�e�B�N���A�j���[�V����
			if (particleFg)
			{
				particlecount++;
				if (particlecount % 5 == 0)
				{
					//particleFg = false;
					particle.numU++;
					if (particle.numU > 7)
					{
						particle.numU = 0;
						particleFg = false;
					}
				}

			}

			// �W�����v
			if (input.GetKeyTrigger(VK_SPACE) && jump == 0 || input.GetButtonTrigger(XINPUT_A) && jump == 0) {
				if (direction == 0) { // �E����
					if (bugPower == 0) {
						santaImage = 2;
						jump = 1;
						santa_Nor[2].numU = 0;
						santa_Nor[2].numV = 0;
					}
					else if (bugPower > 0) {
						santaImage = 3;
						jump = 2;
						santa_Nor[3].numU = 0;
						santa_Nor[3].numV = 0;
					}
					get_jump_old = santa_pos.y;
				}
				else if (direction == 1) { // �E����
					if (bugPower == 0) {
						santaImage = 2;
						jump = 1;
						santa_Nor[2].numU = 0;
						santa_Nor[2].numV = 1;
					}
					else if (bugPower > 0) {
						santaImage = 3;
						jump = 2;
						santa_Nor[3].numU = 0;
						santa_Nor[3].numV = 1;
					}
				}
				get_jump_old = santa_pos.y;
				jumpVelocity = 10.0f;
			}


			// �d��
			if (jump == 0) {
				santa_pos.y += jumpVelocity;
				//	 �d�͂𑬓x�ɓK�p
				jumpVelocity += gravity;
				/*santa_kin_pos.y -= 2.0f;*/
			}

			//�W�����v����
			if (jump == 1 || jump == 2) {

				if (santa_pos.y >= get_jump_old + 100.5f && jump == 1 || santa_pos.y >= get_jump_old + 100.0f && jump == 2) {
					jump = 3;
				}
				else if (santa_pos.y <= get_jump_old + 175.0f && jump == 1 || santa_pos.y <= get_jump_old + 175.0f && jump == 2) {
					/*santa_kin_pos.y += 7.50;*/
					santa_pos.y += jumpVelocity;
					//	 �d�͂𑬓x�ɓK�p
					jumpVelocity += gravity;
				}

			}
			if (jump == 3) {

				santa_pos.y += jumpVelocity;
				//	 �d�͂𑬓x�ɓK�p
				jumpVelocity += gravity;
				if (collision.ground_santa(ground[1], santa_Kin[0], 50.0f, 0.0f) == true ||
					collision.ground_santa(ground[2], santa_Kin[0], 50.0f, 0.0f) == true ||
					collision.ground_santa(ground[3], santa_Kin[0], 50.0f, 0.0f) == true ||
					collision.ground_santa(ground[4], santa_Kin[0], 50.0f, 0.0f) == true ||
					collision.ground_santa(ground[5], santa_Kin[0], 50.0f, 0.0f) == true ||
					collision.block_santa(stairs[1], santa_Kin[0], 100.0f, 0.0f) == true ||
					collision.block_santa(stairs[2], santa_Kin[0], 100.0f, 0.0f) == true ||
					collision.block_santa(stairs[3], santa_Kin[0], 100.0f, 0.0f) == true ||
					collision.block_santa(stairs[4], santa_Kin[0], 100.0f, 0.0f) == true ||
					collision.tree_santa(tree, santa_Kin[0], 1000.0f, 0.0f) == true)
				{

					jump = 0;
					jumpVelocity = 0.0f;
				}
			}

			// �؂Ƃ̓����蔻��̒ǉ��@�S���C
			if (collision.tree_santa(tree, santa_Nor[0], 200.0f, 0.0f))
			{
				if (tree_Ground == 3) {
					if (santa_pos.y >= tree_pos.y) {
						jumpVelocity = 0.0f;
					}
				}
				else {
					//// �T���^���؂̉E���ɂԂ������ꍇ
					if (santa_pos.x < tree_pos.x)
					{

						collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~

					}
				}


			}

			if (collision.tree_santa(invisiblewall[1], santa_Nor[0], 200.0f, 0.0f))
			{

				//// �T���^���؂̉E���ɂԂ������ꍇ
				if (santa_pos.x < wall_pos1.x)
				{
					collision.canMoveRight = false; //�E�Ɉړ����Ȃ�ړ����~
				}

				// �T���^���؂̍����ɂԂ������ꍇ
				if (santa_pos.x > wall_pos1.x)
				{
					collision.canMoveLeft = false; //�E�Ɉړ����Ȃ�ړ����~
				}
			}

			if (collision.tree_santa(invisiblewall[2], santa_Nor[0], 200.0f, 0.0f))
			{

				//// �T���^���؂̉E���ɂԂ������ꍇ
				if (santa_pos.x < wall_pos2.x)
				{
					collision.canMoveRight = false; //�E�Ɉړ����Ȃ�ړ����~
				}

				// �T���^���؂̍����ɂԂ������ꍇ
				if (santa_pos.x > wall_pos2.x)
				{
					collision.canMoveLeft = false; //�E�Ɉړ����Ȃ�ړ����~
				}

			}

			// 12/30  �T���^�̈ړ��A�j���[�V�����ǉ�  	�l��
			//�ړ����x
			if (bugPower == 0) { // �܂���̎�

				speed = 9;
			}
			else {

				speed = 7;
			}

			// �ŗL�\�͔����I�I�I�I�I�I�I
			if (bugPower > 0 && sp_ani == false && input.GetKeyPress(VK_Q)
				|| input.GetButtonTrigger(XINPUT_X) && bugPower > 0 && sp_ani == false) { // �܂�����ۂ̎�

				sp_ani = true;
				
			}

			if (sp_ani == true) {

				santaImage = 7;

				if (direction == 0) {

					// �З͎�
					if (bugPower == 1) {
						if (changeRight_SP == true)
						{
							//������
							santa_Nor[7].numU = 0;
							santa_Nor[7].numV = 0;
							attackhit = false;
							changeRight_SP = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���
						}
						framcount7++; //�t���[���J�E���g
						if (framcount7 % 4 == 0) //�P�O�t���[���Ɉ��s����
						{
							santa_Nor[7].numU++;

							if (santa_Nor[7].numU == 2)
							{
								attackhit = true;
							}
							
							
							if (santa_Nor[7].numU >= 5)
							{
								sp_ani = false;
								santaImage = 1;
								santa_Nor[7].numU = 0;
								changeLeft_SP = true;
								santaatack = 0;
								attackhit = true;
								
							}
						}
					}
					// �З͒�
					else if (bugPower == 2) {
						if (changeRight_SP == true)
						{
							//������
							santa_Nor[7].numU = 0;
							santa_Nor[7].numV = 0;
							attackhit = false;
							changeRight_SP = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���
						}
						framcount7++; //�t���[���J�E���g
						if (framcount7 % 7 == 0) //�P�O�t���[���Ɉ��s����
						{
							santa_Nor[7].numU++;
							if (santa_Nor[7].numU == 2)
							{
								attackhit = true;
							}
							
							if (santa_Nor[7].numU >= 5)
							{
								sp_ani = false;
								santaImage = 1;
								santa_Nor[7].numU = 0;
								attackhit = true;
								changeLeft_SP = true;
							}
						}
					}
					// �З͋�
					else if (bugPower == 3) {
						if (changeRight_SP == true)
						{
							//������
							santa_Nor[7].numU = 0;
							santa_Nor[7].numV = 0;
							attackhit = false;
							changeRight_SP = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���
						}
						framcount7++; //�t���[���J�E���g
						if (framcount7 % 10 == 0) //�P�O�t���[���Ɉ��s����
						{
							santa_Nor[7].numU++;
							if (santa_Nor[7].numU == 2)
							{
								attackhit = true;
							}
							if (santa_Nor[7].numU >= 5)
							{
								sp_ani = false;
								santaImage = 1;
								santa_Nor[7].numU = 0;
								attackhit = true;
								changeLeft_SP = true;
							}
						}
					}
				}
				if (direction == 1) {

					// �З͎�
					if (bugPower == 1) {
						if (changeRight_SP == true)
						{
							//������
							santa_Nor[7].numU = 0;
							santa_Nor[7].numV = 1;
							attackhit = false;
							changeRight_SP = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���
						}
						framcount7++; //�t���[���J�E���g
						if (framcount7 % 4 == 0) //�P�O�t���[���Ɉ��s����
						{
							santa_Nor[7].numU++;
							if (santa_Nor[7].numU == 2)
							{
								attackhit = true;
							}
				
							if (santa_Nor[7].numU >= 5)
							{
								sp_ani = false;
								santaImage = 1;
								santa_Nor[7].numU = 0;
								attackhit = false;
								changeRight_SP = true;

							}
						}
					}
					// �З͒�
					else if (bugPower == 2) {
						if (changeRight_SP == true)
						{
							//������
							santa_Nor[7].numU = 0;
							santa_Nor[7].numV = 1;
							attackhit = false;
							changeRight_SP = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���
						}
						framcount7++; //�t���[���J�E���g
						if (framcount7 % 7 == 0) //�P�O�t���[���Ɉ��s����
						{
							santa_Nor[7].numU++;
							if (santa_Nor[7].numU == 2)
							{
								attackhit = true;
							}
							
							if (santa_Nor[7].numU >= 5)
							{
								sp_ani = false;
								santaImage = 1;
								santa_Nor[7].numU = 0;
								attackhit = true;
								changeRight_SP = true;
							}
						}
					}
					// �З͋�
					else if (bugPower == 3) {
						if (changeRight_SP == true)
						{
							//������
							santa_Nor[7].numU = 0;
							santa_Nor[7].numV = 1;
							attackhit = false;
							changeRight_SP = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���
						}
						framcount7++; //�t���[���J�E���g
						if (framcount7 % 10 == 0) //�P�O�t���[���Ɉ��s����
						{
							santa_Nor[7].numU++;
							if (santa_Nor[7].numU == 2)
							{
								attackhit = true;
							}
							
							if (santa_Nor[7].numU >= 5)
							{
								sp_ani = false;
								santaImage = 1;
								santa_Nor[7].numU = 0;
								
								changeRight_SP = true;
							}
						}
					}
				}

			}
			else
			{
				attackhit = false;
			}


			//�U��
			if (attackhit)
			{
				if (collision.enemy_santa(snowman[1], hitbox, 100.0f, 100.0f) && HitFg == false && pauseFg == false && gameoverFg == false)
				{
					sound.Play(SOUND_LABEL_SE004);
					snowman_hp1 -= santa_atk;

					particleFg = true;
					particlepos.x = snowman_pos1.x;
					particlepos.y = snowman_pos1.y;

					if (snowman_hp1 < 0)
					{
						enemylive1 = false;
						snowman_hp1 = 20;
						snowman_pos1.x = 400000000;
					}
				}

				if (collision.enemy_santa(snowman[2], hitbox, 100.0f, 100.0f) && HitFg == false && pauseFg == false && gameoverFg == false)
				{
					snowman_hp2 -= santa_atk;
					sound.Play(SOUND_LABEL_SE004);
					particleFg = true;
					particlepos.x = snowman_pos2.x;
					particlepos.y = snowman_pos2.y;
					if (snowman_hp2 < 0)
					{

						enemylive2 = false;
						snowman_hp2 = 20;
						snowman_pos2.x = 400000000;
					}

				}

				if (collision.enemy_santa(snowman[3], hitbox, 100.0f, 100.0f) && HitFg == false && pauseFg == false && gameoverFg == false)
				{
					snowman_hp3 -= santa_atk;
					sound.Play(SOUND_LABEL_SE004);
					particleFg = true;
					particlepos.x = snowman_pos3.x;
					particlepos.y = snowman_pos3.y;
					if (snowman_hp3 < 0)
					{
						enemylive3 = false;
						snowman_hp3 = 20;
						snowman_pos3.x = 400000000;
					}
				}
				//��
				if (collision.enemy_santa(star_monster, hitbox, 50.0f, 50.0f) && HitFg == false && pauseFg == false && gameoverFg == false)
				{
					star_monster_hp1 -= santa_atk;
					sound.Play(SOUND_LABEL_SE004);
					particleFg = true;
					particlepos.x = star_monster_pos.x;
					particlepos.y = star_monster_pos.y;
					if (star_monster_hp1 < 0)
					{
						enemylive4 = false;
						star_monster_hp1 = 40;
						star_monster_pos.x = 400000000;
					}
				}

				//�ƂȂ���
				if (collision.enemy_santa(tonakai, hitbox, 50.0f,50.0f) && HitFg == false && pauseFg == false && gameoverFg == false)
				{
					tonakai_hp -= santa_atk;
					sound.Play(SOUND_LABEL_SE004);
					particleFg = true;
					particlepos.x = tonakai_pos.x;
					particlepos.y = tonakai_pos.y;
					if (tonakai_hp < 0)
					{
						enemylive5 = false;
						tonakai_hp = 60;
						tonakai_pos.x = 400000000;
					}
				}
				
			}
			//�p�[�e�B�N���A�j���[�V����
			if (particleFg)
			{
				particlecount++;
				if (particlecount % 5 == 0)
				{
					//particleFg = false;
					particle.numU++;
					if (particle.numU > 7)
					{
						particle.numU=0;
						particleFg = false;
					}
				}
				
			}
			

			// �E�ړ�
			if (sp_ani == false && gameoverFg == false && collision.canMoveRight && input.GetKeyPress(VK_D) && pauseFg == false
				|| gameoverFg == false && collision.canMoveRight && input.GetLeftAnalogStick().x >= 0.1 && pauseFg == false)
			{
				direction = 0; // ����
				santa_pos.x += 5;//�E�ړ�


				if (bugPower == 0) {
					santaImage = 6;
					if (changeRight_SP_1 == true)
					{
						//������
						santa_Nor[6].numU = 0;
						santa_Nor[6].numV = 0;
						changeRight_SP_1 = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���
					}
					framcount6++; //�t���[���J�E���g
					if (framcount6 % 4 == 0) //�P�O�t���[���Ɉ��s����
					{
						santa_Nor[6].numU++;
						if (santa_Nor[6].numU >= 4)
						{
							santa_Nor[6].numU = 0;

						}
					}

				}
				else if (bugPower > 0) {
					santaImage = 1;
					if (changeRight == true)
					{
						//������
						santa_Nor[1].numU = 0;
						santa_Nor[1].numV = 0;
						changeRight = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���
					}
					framcount++; //�t���[���J�E���g
					if (framcount % 10 == 0) //�P�O�t���[���Ɉ��s����
					{
						santa_Nor[1].numU++;
						if (santa_Nor[1].numU >= 4)
						{
							santa_Nor[1].numU = 0;
							santa_Nor[1].numV++;
							if (santa_Nor[1].numV >= 2)
							{
								santa_Nor[1].numV = 0;
							}
						}
					}

				}

				if (santa_pos.x >= 0) //�v���C���[����ʐ^�񒆂ɍs�����Ƃ�
				{
					santa_pos.x -= 5;

					//�w�i�Ȃǂ����ɓ������ăv���C���[���E�ɓ����Ă�悤�Ɍ�����
					//�R
					mounten_pos1.x -= speed - 4.5;
					mounten_pos2.x -= speed - 4.5;
					mounten_pos3.x -= speed - 4.5;
					//�w�i�̖�
					wood_pos1.x -= speed - 2;
					wood_pos2.x -= speed - 2;
					wood_pos3.x -= speed - 2;
					//�E�����
					rock_pos1.x -= speed;
					rock_pos2.x -= speed;
					rock_pos3.x -= speed;
					rock_pos4.x -= speed;
					rock_pos5.x -= speed;
					rock_pos6.x -= speed;
					//�n��
					ground_pos1.x -= speed;
					ground_pos2.x -= speed;
					ground_pos3.x -= speed;
					ground_pos4.x -= speed;
					ground_pos5.x -= speed;
					//�K�i
					stairs_pos1.x -= speed;
					stairs_pos2.x -= speed;
					stairs_pos3.x -= speed;
					stairs_pos4.x -= speed;
					//�Ⴞ���
					snowman_pos1.x -= speed;
					snowman_pos2.x -= speed;
					snowman_pos3.x -= speed;
					//���
					snowball_pos1.x -= speed;
					snowball_pos2.x -= speed;
					snowball_pos3.x -= speed;
					//���̂Ă�
					star_monster_pos.x -= speed;
					//�g�i�J�C
					tonakai_pos.x -= speed;
					//�v���[���g
					present_pos1.x -= speed;
					present_pos2.x -= speed;
					present_pos3.x -= speed;
					//�傫���v���[���g
					bigpresent_pos1.x -= speed;
					//��
					tree_pos.x -= speed;
					//�S�[��
					goal_pos.x -= speed;

					wall_pos1.x -= speed;
					wall_pos2.x -= speed;

					//�����A�C�e��
					use_rock_pos1.x -= speed;
					use_rock_pos2.x -= speed;
					use_rock_pos3.x -= speed;
					use_snowball_pos1.x -= speed;
					use_snowball_pos2.x -= speed;
					use_snowball_pos3.x -= speed;

				}
			}
			else
			{
				//�L�[�𗣂���true�ɖ߂�
				if (sp_ani == false && changeRight_SP_1 == false) {

					santa_Nor[0].numU = 0;
					santa_Nor[0].numV = 0;
					santa_Nor[1].numU = 0;
					santa_Nor[1].numV = 0;
					if (bugPower > 0) {
						santaImage = 1;
					}
					else if (bugPower == 0) {
						santaImage = 0;
					}

				}

				changeRight = true;
				changeRight_SP_1 = true;
			}

			// ���ړ�
			if (sp_ani == false && gameoverFg == false && collision.canMoveLeft && input.GetKeyPress(VK_A) && pauseFg == false
				|| gameoverFg == false && collision.canMoveLeft && input.GetLeftAnalogStick().x <= -0.1 && pauseFg == false)
			{
				direction = 1; // ����
				santa_pos.x -= 5;//���ړ�


				if (bugPower == 0) {

					santaImage = 6;
					if (changeLeft_SP_1 == true)
					{
						//������
						santa_Nor[6].numU = 0;
						santa_Nor[6].numV = 1;
						changeLeft_SP_1 = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���
					}
					framcount6++; //�t���[���J�E���g
					if (framcount6 % 4 == 0) //�P�O�t���[���Ɉ��s����
					{
						santa_Nor[6].numU++;
						if (santa_Nor[6].numU >= 4)
						{

							santa_Nor[6].numU = 0;

						}
					}
				}
				else if (bugPower > 0) {

					if (changeLeft == true)
					{
						//������
						santa_Nor[1].numU = 0;
						santa_Nor[1].numV = 2;
						changeLeft = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���
					}
					framcount++; //�t���[���J�E���g
					if (framcount % 10 == 0) //�P�O�t���[���Ɉ��s����
					{
						santa_Nor[1].numU++;
						if (santa_Nor[1].numU >= 4)
						{
							santa_Nor[1].numU = 0;
							santa_Nor[1].numV++;
							if (santa_Nor[1].numV >= 4)
							{
								santa_Nor[1].numV = 2;
							}
						}
					}
				}
				if (santa_pos.x <= 0) //�v���C���[����ʐ^�񒆂ɍs�����Ƃ�
				{
					santa_pos.x += 5;



					//�w�i�Ȃǂ����ɓ������ăv���C���[���E�ɓ����Ă�悤�Ɍ�����
					//�R
					mounten_pos1.x += speed - 4.5;
					mounten_pos2.x += speed - 4.5;
					mounten_pos3.x += speed - 4.5;
					//�w�i�̖�
					wood_pos1.x += speed - 2;
					wood_pos2.x += speed - 2;
					wood_pos3.x += speed - 2;
					//�E�����
					rock_pos1.x += speed;
					rock_pos2.x += speed;
					rock_pos3.x += speed;
					rock_pos4.x += speed;
					rock_pos5.x += speed;
					rock_pos6.x += speed;
					//�n��
					ground_pos1.x += speed;
					ground_pos2.x += speed;
					ground_pos3.x += speed;
					ground_pos4.x += speed;
					ground_pos5.x += speed;
					//�K�i
					stairs_pos1.x += speed;
					stairs_pos2.x += speed;
					stairs_pos3.x += speed;
					stairs_pos4.x += speed;
					//�Ⴞ���
					snowman_pos1.x += speed;
					snowman_pos2.x += speed;
					snowman_pos3.x += speed;
					//���
					snowball_pos1.x += speed;
					snowball_pos2.x += speed;
					snowball_pos3.x += speed;
					//���̂Ă�
					star_monster_pos.x += speed;
					//�g�i�J�C
					tonakai_pos.x += speed;
					//�v���[���g
					present_pos1.x += speed;
					present_pos2.x += speed;
					present_pos3.x += speed;
					//�傫���v���[���g
					bigpresent_pos1.x += speed;
					//��
					tree_pos.x += speed;
					//�S�[��
					goal_pos.x += speed;

					wall_pos1.x += speed;
					wall_pos2.x += speed;

					//�����A�C�e��
					use_rock_pos1.x += speed;
					use_rock_pos2.x += speed;
					use_rock_pos3.x += speed;
					use_snowball_pos1.x += speed;
					use_snowball_pos2.x += speed;
					use_snowball_pos3.x += speed;
				}
			}
			else
			{
				//�L�[�𗣂���true�ɖ߂�
				if (sp_ani == false && changeLeft_SP_1 == false) {
					santa_Nor[0].numU = 0;
					santa_Nor[0].numV = 2;
					santa_Nor[1].numU = 0;
					santa_Nor[1].numV = 2;
					if (bugPower > 0) {
						santaImage = 1;
					}
					else if (bugPower == 0) {
						santaImage = 0;
					}
				}
				changeLeft = true;
				changeLeft_SP_1 = true;
			}

		}
		else if (santa_bug == 1) 
		{
			santa_pos.x = santa_huro_pos.x;
			santa_kin_pos.x = santa_huro_pos.x;

			santa_pos.y = santa_huro_pos.y;
			santa_kin_pos.y = santa_huro_pos.y;


			// �Ⴞ��܂Ƃ̓����蔻��ǉ� 

			if (collision.enemy_santa(snowman[1], santa_Huro[0], 200.0f, 0.0f) && HitFg == false && pauseFg == false && gameoverFg == false)
			{
				time -= 5;
				hitcooltime = 0;
				sound.Play(SOUND_LABEL_SE000);
				damage5 = true;
				HitFg = true;
			}

			if (collision.enemy_santa(snowman[2], santa_Huro[0], 200.0f, 0.0f) && HitFg == false && pauseFg == false && gameoverFg == false)
			{
				time -= 5;
				hitcooltime = 0;
				sound.Play(SOUND_LABEL_SE000);
				damage5 = true;
				HitFg = true;
			}

			if (collision.enemy_santa(snowman[3], santa_Huro[0], 200.0f, 0.0f) && HitFg == false && pauseFg == false && gameoverFg == false)
			{
				time -= 5;
				hitcooltime = 0;
				sound.Play(SOUND_LABEL_SE000);
				damage5 = true;
				HitFg = true;
			}

			// ���Ƃ̓����蔻��ǉ� 
			if (collision.enemy_santa(star_monster, santa_Huro[0], 200.0f, 0.0f) && HitFg == false && pauseFg == false && gameoverFg == false)
			{
				sound.Play(SOUND_LABEL_SE000);
				time -= 5;
				hitcooltime = 0;
				damage5 = true;
				HitFg = true;
			}
			//�g�i�J�C �Ƃ̓����蔻��ǉ� 
			if (collision.enemy_santa(tonakai, santa_Huro[0], 200.0f, 0.0f) && HitFg == false && pauseFg == false && gameoverFg == false)
			{
				sound.Play(SOUND_LABEL_SE000);
				time -= 5;
				hitcooltime = 0;
				damage5 = true;
				HitFg = true;
			}


			//�v���[���g�̓����蔻��
			if (collision.item_santa(present[1], santa_Huro[0], 100.0f, 0.0f) && pauseFg == false)

			{
				presentcount += 1;
				score += 5000;
				present_pos1.y = 100000;
				sound.Play(SOUND_present);
			}

			if (collision.item_santa(present[2], santa_Huro[0], 100.0f, 0.0f))
			{
				presentcount += 1;
				score += 5000;
				present_pos2.y = 100000;
				sound.Play(SOUND_present);
			}

			if (collision.item_santa(present[3], santa_Huro[0], 100.0f, 0.0f))
			{
				presentcount += 1;
				score += 5000;
				present_pos3.y = 100000;
				sound.Play(SOUND_present);
			}

			if (collision.item_santa(BigPresent[1], santa_Huro[0], 100.0f, 0.0f))
			{
				bigpresentcount += 1;
				score += 10000;
				bigpresent_pos1.y = 100000;
				sound.Play(SOUND_present);
			}



			if (collision.block_santa(stairs[1], santa_Huro[0], 50.0f, 0.0f))
			{

				if (santa_huro_pos.y > stairs_pos1.y + stairs[1].GetSize().y / 2.0f) {
					santa_huro_pos.y = stairs_pos1.y + stairs[1].GetSize().y / 2.0f + santa_Huro[0].GetSize().y / 2.0f;
					jumpVelocity = 0.0f;
					/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
				}
				else {
					/*std::cout << "\nSanta is falling." << std::endl;*/
				}

				if (santa_huro_pos.x < stairs_pos1.x)
				{
					//collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
				}

				// �T���^���Ԃ������ꍇ
				if (santa_huro_pos.x > stairs_pos1.x)
				{
					//collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
				}
			}

			if (collision.block_santa(stairs[2], santa_Huro[0], 100.0f, 0.0f))
			{

				if (santa_huro_pos.y > stairs_pos2.y + stairs[2].GetSize().y / 2.0f) {
					santa_huro_pos.y = stairs_pos2.y + stairs[2].GetSize().y / 2.0f + santa_Huro[0].GetSize().y / 2.0f;
					jumpVelocity = 0.0f;
					/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
				}
				else {
					/*std::cout << "\nSanta is falling." << std::endl;*/
				}

				if (santa_huro_pos.x < stairs_pos2.x)
				{
					collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
				}

				// �T���^���Ԃ������ꍇ
				if (santa_huro_pos.x > stairs_pos2.x)
				{
					collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
				}
			}
			if (collision.block_santa(stairs[3], santa_Huro[0], 100.0f, 0.0f))
			{

				if (santa_huro_pos.y > stairs_pos3.y + stairs[3].GetSize().y / 2.0f) {
					santa_huro_pos.y = stairs_pos3.y + stairs[3].GetSize().y / 2.0f + santa_Huro[0].GetSize().y / 2.0f;
					jumpVelocity = 0.0f;
					/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
				}
				else {
					/*std::cout << "\nSanta is falling." << std::endl;*/
				}
				if (santa_huro_pos.x < stairs_pos3.x && santa_huro_pos.y / 2 < stairs_pos3.y / 3)
				{
					collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
				}

				// �T���^���Ԃ������ꍇ
				if (santa_huro_pos.x > stairs_pos3.x && santa_huro_pos.y / 2 < stairs_pos3.y / 3)
				{
					collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
				}
			}

			if (collision.block_santa(stairs[4], santa_Huro[0], 100.0f, 0.0f))
			{
				if (santa_huro_pos.y > stairs_pos4.y + stairs[4].GetSize().y / 2.0f) {
					santa_huro_pos.y = stairs_pos4.y + stairs[4].GetSize().y / 2.0f + santa_Huro[0].GetSize().y / 2.0f;
					jumpVelocity = 0.0f;
					/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
				}
				else {
					/*std::cout << "\nSanta is falling." << std::endl;*/
				}
				if (santa_huro_pos.x < stairs_pos4.x && santa_huro_pos.y / 2 < stairs_pos4.y / 3)
				{
					collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
				}

				// �T���^���Ԃ������ꍇ
				if (santa_huro_pos.x > stairs_pos4.x && santa_huro_pos.y / 2 < stairs_pos4.y / 3)
				{
					collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
				}
			}




			// �n�ʂƂ̓����蔻��̒ǉ� �S���C

			if (collision.ground_santa(ground[1], santa_Huro[0], 50.0f, 0.0f))
			{
				//// �T���^���n�ʂ̏�ɂ���ꍇ
				if (santa_huro_pos.y > ground_pos1.y + ground[1].GetSize().y / 2.0f) {
					santa_huro_pos.y = ground_pos1.y + ground[1].GetSize().y / 2.0f + santa_Huro[0].GetSize().y / 2.0f;
					jumpVelocity = 0.0f;
					/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
				}
				else {
					/*std::cout << "\nSanta is falling." << std::endl;*/
				}

				// �T���^���n�ʂ̉E���ɂԂ������ꍇ
				if (santa_huro_pos.x < ground_pos1.x && santa_huro_pos.y < ground_pos1.y) {

					collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
				}

				// �T���^���n�ʂɂԂ������ꍇ
				if (santa_huro_pos.x > ground_pos1.x && santa_huro_pos.y < ground_pos1.y) {
					collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
				}
			}

			if (collision.ground_santa(ground[2], santa_Huro[0], 50.0f, 0.0f))
			{
				//// �T���^���n�ʂ̏�ɂ���ꍇ
				if (santa_huro_pos.y > ground_pos2.y + ground[2].GetSize().y / 2.0f) {
					santa_huro_pos.y = ground_pos2.y + ground[2].GetSize().y / 2.0f + santa_Huro[0].GetSize().y / 2.0f;
					jumpVelocity = 0.0f;
					/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
				}
				else {
					/*std::cout << "\nSanta is falling." << std::endl;*/
				}

				// �T���^���n�ʂ̉E���ɂԂ������ꍇ
				if (santa_huro_pos.x < ground_pos2.x && santa_huro_pos.y < ground_pos2.y) {

					collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
				}

				// �T���^���n�ʂɂԂ������ꍇ
				if (santa_huro_pos.x > ground_pos2.x && santa_huro_pos.y < ground_pos2.y) {
					collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
				}
			}

			if (collision.ground_santa(ground[3], santa_Huro[0], 50.0f, 0.0f))
			{
				jump = 0;
				//// �T���^���n�ʂ̏�ɂ���ꍇ
				if (santa_huro_pos.y > ground_pos3.y + ground[3].GetSize().y / 2.0f) {
					santa_huro_pos.y = ground_pos3.y + ground[3].GetSize().y / 2.0f + santa_Huro[0].GetSize().y / 2.0f;
					jumpVelocity = 0.0f;
					/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
				}
				else {
					/*std::cout << "\nSanta is falling." << std::endl;*/
				}

				// �T���^���n�ʂ̉E���ɂԂ������ꍇ
				if (santa_huro_pos.x < ground_pos3.x && santa_huro_pos.y < ground_pos3.y) {

					collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
				}

				// �T���^���n�ʂɂԂ������ꍇ
				if (santa_huro_pos.x > ground_pos3.x && santa_huro_pos.y < ground_pos3.y) {
					collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
				}
			}

			if (collision.ground_santa(ground[4], santa_Huro[0], 50.0f, 0.0f))
			{
				//// �T���^���n�ʂ̏�ɂ���ꍇ
				if (santa_huro_pos.y > ground_pos4.y + ground[4].GetSize().y / 2.0f) {
					santa_huro_pos.y = ground_pos4.y + ground[4].GetSize().y / 2.0f + santa_Huro[0].GetSize().y / 2.0f;
					jumpVelocity = 0.0f;
					/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
				}
				else {
					/*std::cout << "\nSanta is falling." << std::endl;*/
				}

				// �T���^���n�ʂ̉E���ɂԂ������ꍇ
				if (santa_huro_pos.x < ground_pos4.x && santa_huro_pos.y < ground_pos4.y) {

					collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
				}

				// �T���^���n�ʂɂԂ������ꍇ
				if (santa_huro_pos.x > ground_pos4.x && santa_huro_pos.y < ground_pos4.y) {
					collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
				}
			}

			if (collision.ground_santa(ground[5], santa_Huro[0], 50.0f, 0.0f))
			{
				//// �T���^���n�ʂ̏�ɂ���ꍇ
				if (santa_huro_pos.y > ground_pos5.y + ground[5].GetSize().y / 2.0f) {
					santa_huro_pos.y = ground_pos5.y + ground[5].GetSize().y / 2.0f + santa_Huro[0].GetSize().y / 2.0f;
					jumpVelocity = 0.0f;
					/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
				}
				else {
					/*std::cout << "\nSanta is falling." << std::endl;*/
				}

				// �T���^���n�ʂ̉E���ɂԂ������ꍇ
				if (santa_huro_pos.x < ground_pos5.x && santa_huro_pos.y < ground_pos5.y) {

					collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
				}

				// �T���^���n�ʂɂԂ������ꍇ
				if (santa_huro_pos.x > ground_pos5.x && santa_huro_pos.y < ground_pos5.y) {
					collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
				}
			}
			if (collision.goal_santa(goal, santa_Huro[0], 250.0f, 0.0f))
			{

				// �T���^���S�[���̉E���ɂԂ������ꍇ
				if (santa_huro_pos.x < goal_pos.x && santa_huro_pos.y < goal_pos.y)
				{

					changescene = RESULT;
					//������
					santa_pos.x = -400;

					mounten_pos1.x = 0;
					mounten_pos2.x = 1280;
					mounten_pos3.x = 2560;

					wood_pos1.x = 0;
					wood_pos2.x = 1280;
					wood_pos3.x = 2560;

					wall_pos1.x = -600;
					wall_pos2.x = 5750;

					rock_pos1.x = -250;
					rock_pos2.x = 300;
					rock_pos3.x = 1100;
					rock_pos4.x = 1100;
					rock_pos5.x = 2300;
					rock_pos6.x = 4400;

					snowball_pos1.x = 1500;
					snowball_pos2.x = 2900;
					snowball_pos3.x = 4000;

					ground_pos1.x = 0;
					ground_pos2.x = 1300;
					ground_pos3.x = 3100;
					ground_pos4.x = 4500;
					ground_pos5.x = 5300;

					stairs_pos1.x = 540;
					stairs_pos2.x = 565;
					stairs_pos3.x = 600;
					stairs_pos4.x = 2800;

					snowman_pos1.x = 30;
					snowman_pos2.x = 1400;
					snowman_pos3.x = 2700;

					bigpresent_pos1.x = 5400;

					star_monster_pos.x = 4800;
					tonakai_pos.x = 3600;

					present_pos1.x = 800;
					present_pos2.x = 2800;
					present_pos3.x = 4500;

					present_pos1.y = -25;
					present_pos2.y = 160;
					present_pos3.y = -300;
					bigpresent_pos1.y = -25;

					tree_pos.x = 1900;
					goal_pos.x = 5800;
					sound.Stop(SOUND_LABEL_BGM000);
				}

			}





			if (collision.item_santa(rock[1], santa_Huro[0], 100.0f, 0.0f) && rock_visible1 == 0)
			{
				if (input.GetKeyTrigger(VK_S) && !itemCollected || input.GetButtonTrigger(XINPUT_B) && !itemCollected)
				{

					item->ItemGet(1); // ��������
					bugPower = item->GetItemCnt(); // ���݂̑܂̃A�C�e��������
					itemCollected = true;
					santaImage = 13;

					rock_visible1 = 1;

				}
			}

			if (collision.item_santa(rock[2], santa_Huro[0], 100.0f, 0.0f) && rock_visible2 == 0)
			{
				if (input.GetKeyTrigger(VK_S) && !itemCollected || input.GetButtonTrigger(XINPUT_B) && !itemCollected)
				{
					/*itemID = 1;*/
					item->ItemGet(1); // ��������
					bugPower = item->GetItemCnt(); // ���݂̑܂̃A�C�e��������
					itemCollected = true;
					santaImage = 13;

					rock_visible2 = 1;
				}
			}

			if (collision.item_santa(rock[3], santa_Huro[0], 100.0f, 0.0f) && rock_visible3 == 0)
			{
				if (input.GetKeyTrigger(VK_S) && !itemCollected || input.GetButtonTrigger(XINPUT_B) && !itemCollected)
				{
					/*itemID = 1;*/
					item->ItemGet(1); // ��������
					bugPower = item->GetItemCnt(); // ���݂̑܂̃A�C�e��������
					itemCollected = true;
					santaImage = 13;

					rock_visible3 = 1;
				}
			}

			if (collision.item_santa(rock[4], santa_Huro[0], 100.0f, 0.0f) && rock_visible4 == 0)
			{
				if (input.GetKeyTrigger(VK_S) && !itemCollected || input.GetButtonTrigger(XINPUT_B) && !itemCollected)
				{
					/*itemID = 1;*/
					item->ItemGet(1); // ��������
					bugPower = item->GetItemCnt(); // ���݂̑܂̃A�C�e��������
					itemCollected = true;
					santaImage = 13;

					rock_visible4 = 1;
				}
			}

			if (collision.item_santa(rock[5], santa_Huro[0], 100.0f, 0.0f) && rock_visible5 == 0)
			{
				if (input.GetKeyTrigger(VK_S) && !itemCollected || input.GetButtonTrigger(XINPUT_B) && !itemCollected)
				{
					/*itemID = 1;*/
					item->ItemGet(1); // ��������
					bugPower = item->GetItemCnt(); // ���݂̑܂̃A�C�e��������
					itemCollected = true;
					santaImage = 13;

					rock_visible5 = 1;
				}
			}

			if (collision.item_santa(rock[6], santa_Huro[0], 100.0f, 0.0f) && rock_visible6 == 0)
			{
				if (input.GetKeyTrigger(VK_S) && !itemCollected || input.GetButtonTrigger(XINPUT_B) && !itemCollected)
				{
					/*itemID = 1;*/
					item->ItemGet(1); // ��������
					bugPower = item->GetItemCnt(); // ���݂̑܂̃A�C�e��������
					itemCollected = true;
					santaImage = 13;

					rock_visible6 = 1;
				}
			}

			if (collision.item_santa(snowball[1], santa_Huro[0], 100.0f, 0.0f) && snow_visible1 == 0)
			{
				if (input.GetKeyTrigger(VK_S) && !itemCollected || input.GetButtonTrigger(XINPUT_B) && !itemCollected)
				{
					/*itemID = 1;*/
					item->ItemGet(2); // ��������
					bugPower = item->GetItemCnt(); // ���݂̑܂̃A�C�e��������
					itemCollected = true;
					santaImage = 13;

					snow_visible1 = 1;
				}
			}

			if (collision.item_santa(snowball[2], santa_Huro[0], 100.0f, 0.0f) && snow_visible1 == 0)
			{
				if (input.GetKeyTrigger(VK_S) && !itemCollected || input.GetButtonTrigger(XINPUT_B) && !itemCollected)
				{
					/*itemID = 1;*/
					item->ItemGet(2); // ��������
					bugPower = item->GetItemCnt(); // ���݂̑܂̃A�C�e��������
					itemCollected = true;
					santaImage = 13;

					snow_visible2 = 1;
				}
			}

			if (collision.item_santa(snowball[3], santa_Huro[0], 100.0f, 0.0f) && snow_visible1 == 0)
			{
				if (input.GetKeyTrigger(VK_S) && !itemCollected || input.GetButtonTrigger(XINPUT_B) && !itemCollected)
				{
					/*itemID = 1;*/
					item->ItemGet(2); // ��������
					bugPower = item->GetItemCnt(); // ���݂̑܂̃A�C�e��������
					itemCollected = true;
					santaImage = 13;

					snow_visible3 = 1;
				}
			}

			// ��ʊO�ɍs���ƁA�A�C�e�����ăX�|�[�����鏈��
			if (leftScreen > rock_pos1.x || rock_pos1.x > rightScreen) {
				rock_visible1 = 0;
			}
			if (leftScreen > rock_pos2.x || rock_pos2.x > rightScreen) {
				rock_visible2 = 0;
			}
			if (leftScreen > rock_pos3.x || rock_pos3.x > rightScreen) {
				rock_visible3 = 0;
			}
			if (leftScreen > rock_pos4.x || rock_pos4.x > rightScreen) {
				rock_visible4 = 0;
			}
			if (leftScreen > rock_pos5.x || rock_pos5.x > rightScreen) {
				rock_visible5 = 0;
			}
			if (leftScreen > rock_pos6.x || rock_pos6.x > rightScreen) {
				rock_visible6 = 0;
			}
			if (leftScreen > snowball_pos1.x || snowball_pos1.x > rightScreen) {
				snow_visible1 = 0;
			}
			if (leftScreen > snowball_pos2.x || snowball_pos2.x > rightScreen) {
				snow_visible2 = 0;
			}
			if (leftScreen > snowball_pos3.x || snowball_pos3.x > rightScreen) {
				snow_visible3 = 0;
			}


			if (!itemCollected && !changeItem) {// �������ĂȂ��ꍇ
				if (input.GetKeyTrigger(VK_S) && pauseFg == false || input.GetButtonTrigger(XINPUT_B) && pauseFg == false)
				{

					if (item->GetItem_3() > 0) {
						changeItem = true;

						if (item->GetItem_3() == 1) {
							use_rock_pos3.x = santa_huro_pos.x;
							use_rock_pos3.y = santa_huro_pos.y;
							sound.Play(SOUND_LABEL_SE003);
							itemID_3 = 1;
							itemMove3 = true;
						}
						else if (item->GetItem_3() == 2) {
							use_snowball_pos3.x = santa_huro_pos.x;
							use_snowball_pos3.y = santa_huro_pos.y;
							sound.Play(SOUND_LABEL_SE003);
							itemID_3 = 2;
							itemMove3 = true;
						}

					}
					else if (item->GetItem_3() < 0) {

						if (item->GetItem_2() > 0) {

							if (item->GetItem_2() == 1) {
								use_rock_pos2.x = santa_huro_pos.x;
								use_rock_pos2.y = santa_huro_pos.y;
								sound.Play(SOUND_LABEL_SE003);
								itemID_2 = 1;
								itemMove2 = true;
							}
							else if (item->GetItem_2() == 2) {
								use_snowball_pos2.x = santa_huro_pos.x;
								use_snowball_pos2.y = santa_huro_pos.y;
								sound.Play(SOUND_LABEL_SE003);
								itemID_2 = 2;
								itemMove2 = true;
							}

						}
						else if (item->GetItem_2() < 0) {

							if (item->GetItem_1() > 0) {

								if (item->GetItem_1() == 1) {
									use_rock_pos1.x = santa_huro_pos.x;
									use_rock_pos1.y = santa_huro_pos.y;
									itemID_1 = 1;
									itemMove1 = true;
								}
								else if (item->GetItem_1() == 2) {
									use_snowball_pos1.x = santa_huro_pos.x;
									use_snowball_pos1.y = santa_huro_pos.y;
									itemID_1 = 2;
									itemMove1 = true;
								}

							}
						}
					}

					santaImage = 14;
					item->ItemRelease(); // ���o��
					bugPower = item->GetItemCnt();
				}
			}

			// ����A�j���[�V����
			if (santaImage == 13) {
				getItem = 1;
				if (direction == 0) { // �E����
					if (changeRight_get == true)
					{
						//������
						santa_Huro[4].numU = 0;
						santa_Huro[4].numV = 0;
						changeRight_get = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���
					}
					framcount4++; //�t���[���J�E���g
					if (framcount4 % 4 == 0) //�P�O�t���[���Ɉ��s����
					{
						santa_Huro[4].numU++;
						if (santa_Huro[4].numU >= 5)
						{
							sp_ani = false;
							santaImage = 9;
							getItem = 0;
							santa_Huro[4].numU = 0;

						}
					}
				}
				else if (direction == 1) {
					if (changeLeft_get == true)
					{
						//������
						santa_Huro[4].numU = 0;
						santa_Huro[4].numV = 1;
						changeLeft_get = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���
					}
					framcount4++; //�t���[���J�E���g
					if (framcount4 % 4 == 0) //�P�O�t���[���Ɉ��s����
					{
						santa_Huro[4].numU++;
						if (santa_Huro[4].numU >= 5)
						{
							sp_ani = false;
							santaImage = 9;
							getItem = 0;
							santa_Huro[4].numU = 0;

						}
					}
				}
			}

			// ��o�A�j���[�V����
			if (santaImage == 14) {

				if (direction == 0) { // �E����
					if (changeRight_out == true)
					{
						//������
						santa_Huro[5].numU = 0;
						santa_Huro[5].numV = 0;
						changeRight_out = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���
					}
					framcount5++; //�t���[���J�E���g
					if (framcount5 % 4 == 0) //�P�O�t���[���Ɉ��s����
					{
						santa_Huro[5].numU++;
						if (santa_Huro[5].numU >= 5)
						{
							sp_ani = false;
							if (bugPower > 0) {
								santaImage = 9;
							}
							else if (bugPower == 0) {
								santaImage = 8;
							}

							santa_Huro[5].numU = 0;
							changeRight_out = true;

						}
					}
				}
				else if (direction == 1) {
					if (changeLeft_out == true)
					{
						//������
						santa_Huro[5].numU = 0;
						santa_Huro[5].numV = 1;
						changeLeft_out = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���
					}
					framcount5++; //�t���[���J�E���g
					if (framcount5 % 4 == 0) //�P�O�t���[���Ɉ��s����
					{
						santa_Huro[5].numU++;
						if (santa_Huro[5].numU >= 5)
						{
							sp_ani = false;
							if (bugPower > 0) {
								santaImage = 9;
							}
							else if (bugPower == 0) {
								santaImage = 8;
							}
							santa_Huro[5].numU = 0;
							changeLeft_out = true;

						}
					}
				}
			}

			// �������̓����@���̇@ 
			if (itemMove1 == true) {
				if (direction == 0) { // �E����

					if (itemID_1 == 1) { // ��

						if (itemMove1_M == true || use_rock_pos1.y >= -100.0f) {
							itemMove1_M = true;
							use_rock_pos1.y -= 3.00f;
							use_rock_pos1.x += 3.00f;
						}
						else if (itemMove1_M == false) {
							use_rock_pos1.y += 3.00f;
							use_rock_pos1.x += 3.00f;
						}
						if (use_rock_pos1.y <= -190.0f && itemMove1_M == true) {
							itemID_1 = 0;
							itemMove1_M = false;
							itemMove1 = false;
						}
					}
					else if (itemID_1 == 2) {
						if (use_snowball_pos1.x >= rightScreen) {
							itemID_1 = 0;
							itemMove1 = false;
						}
						else if (use_snowball_pos1.x <= rightScreen) {
							use_snowball_pos1.x += 20.00f;
						}
					}
				}
				else if (direction == 1) { // ������

					if (itemID_1 == 1) { // ��

						if (itemMove1_M == true || use_rock_pos1.y >= -100.0f) {
							itemMove1_M = true;
							use_rock_pos1.y -= 3.00f;
							use_rock_pos1.x -= 3.00f;
						}
						else if (itemMove1_M == false) {
							use_rock_pos1.y += 3.00f;
							use_rock_pos1.x -= 3.00f;
						}
						if (use_rock_pos1.y <= -190.0f && itemMove1_M == true) {
							itemID_1 = 0;
							itemMove1_M = false;
							itemMove1 = false;
						}
					}
					else if (itemID_1 == 2) {
						if (use_snowball_pos1.x <= leftScreen) {
							itemID_1 = 0;
							itemMove1 = false;
						}
						else if (use_snowball_pos1.x >= leftScreen) {
							use_snowball_pos1.x -= 20.00f;
						}
					}
				}



			}

			// �������̓����@���̇A
			if (itemMove2 == true) {
				if (direction == 0) { // �E����

					if (itemID_2 == 1) { //��

						if (itemMove2_M == true || use_rock_pos2.y >= -100.0f) {
							itemMove2_M = true;
							use_rock_pos2.y -= 3.00f;
							use_rock_pos2.x += 3.00f;
						}
						else if (itemMove2_M == false) {
							use_rock_pos2.y += 3.00f;
							use_rock_pos2.x += 3.00f;
						}
						if (use_rock_pos2.y <= -190.0f && itemMove2_M == true) {
							itemID_2 = 0;
							itemMove2_M = false;
							itemMove2 = false;
						}
					}
					else if (itemID_2 == 2) {
						if (use_snowball_pos2.x >= rightScreen) {
							itemID_2 = 0;
							itemMove2 = false;
						}
						else if (use_snowball_pos2.x <= rightScreen) {
							use_snowball_pos2.x += 20.00f;
						}
					}
				}
				else if (direction == 1) { // ������

					if (itemID_2 == 1) { //��

						if (itemMove2_M == true || use_rock_pos2.y >= -100.0f) {
							itemMove2_M = true;
							use_rock_pos2.y -= 3.00f;
							use_rock_pos2.x -= 3.00f;
						}
						else if (itemMove2_M == false) {
							use_rock_pos2.y += 3.00f;
							use_rock_pos2.x -= 3.00f;
						}
						if (use_rock_pos2.y <= -190.0f && itemMove2_M == true) {
							itemID_2 = 0;
							itemMove2_M = false;
							itemMove2 = false;
						}
					}
					else if (itemID_2 == 2) {
						if (use_snowball_pos2.x <= leftScreen) {
							itemID_2 = 0;
							itemMove2 = false;
						}
						else if (use_snowball_pos2.x >= leftScreen) {
							use_snowball_pos2.x -= 20.00f;
						}
					}
				}


			}

			// �������̓����@���̇B
			if (itemMove3 == true) {

				if (direction == 0) { // �E����

					if (itemID_3 == 1) { // ��

						if (itemMove3_M == true || use_rock_pos3.y >= -100.0f) {
							itemMove3_M = true;
							use_rock_pos3.y -= 3.00f;
							use_rock_pos3.x += 3.00f;
						}
						else if (itemMove3_M == false) {
							use_rock_pos3.y += 3.00f;
							use_rock_pos3.x += 3.00f;
						}
						if (use_rock_pos3.y <= -190.0f && itemMove3_M == true) {
							itemID_3 = 0;
							itemMove3_M = false;
							itemMove3 = false;
							changeItem = false;
						}
					}
					else if (itemID_3 == 2) {
						if (use_snowball_pos3.x >= rightScreen) {
							itemID_3 = 0;
							itemMove3 = false;
							changeItem = false;
						}
						else if (use_snowball_pos3.x <= rightScreen) {
							use_snowball_pos3.x += 30.00f;
						}
					}
				}
				else if (direction == 1) { // ������

					if (itemID_3 == 1) { // ��

						if (itemMove3_M == true || use_rock_pos3.y >= -100.0f) {
							itemMove3_M = true;
							use_rock_pos3.y -= 3.00f;
							use_rock_pos3.x -= 3.00f;
						}
						else if (itemMove3_M == false) {
							use_rock_pos3.y += 3.00f;
							use_rock_pos3.x -= 3.00f;
						}
						if (use_rock_pos3.y <= -190.0f && itemMove3_M == true) {
							itemID_3 = 0;
							itemMove3_M = false;
							itemMove3 = false;
							changeItem = false;
						}
					}
					else if (itemID_3 == 2) {
						if (use_snowball_pos3.x <= leftScreen) {
							itemID_3 = 0;
							itemMove3 = false;
							changeItem = false;
						}
						else if (use_snowball_pos3.x >= leftScreen) {
							use_snowball_pos3.x -= 30.00f;
						}
					}
				}


			}

			// �������̓����蔻�� ��

				// �Ⴞ��܂P
			if (collision.square_square(snowman[1], use_rock[0]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp1 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos1.x;
				particlepos.y = snowman_pos1.y;

				if (snowman_hp1 < 0)
				{
					enemylive1 = false;
					snowman_hp1 = 20;
					snowman_pos1.x = 400000000;
				}
			}

			if (collision.square_square(snowman[1], use_rock[1]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp1 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos1.x;
				particlepos.y = snowman_pos1.y;

				if (snowman_hp1 < 0)
				{
					enemylive1 = false;
					snowman_hp1 = 20;
					snowman_pos1.x = 400000000;
				}
			}

			if (collision.square_square(snowman[1], use_rock[2]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp1 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos1.x;
				particlepos.y = snowman_pos1.y;

				if (snowman_hp1 < 0)
				{
					enemylive1 = false;
					snowman_hp1 = 20;
					snowman_pos1.x = 400000000;
				}
			}

			// �Ⴞ��܂Q
			if (collision.square_square(snowman[2], use_rock[0]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp2 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos2.x;
				particlepos.y = snowman_pos2.y;

				if (snowman_hp2 < 0)
				{
					enemylive2 = false;
					snowman_hp2 = 20;
					snowman_pos2.x = 400000000;
				}
			}

			if (collision.square_square(snowman[2], use_rock[1]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp2 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos2.x;
				particlepos.y = snowman_pos2.y;

				if (snowman_hp2 < 0)
				{
					enemylive2 = false;
					snowman_hp2 = 20;
					snowman_pos2.x = 400000000;
				}
			}

			if (collision.square_square(snowman[2], use_rock[2]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp2 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos2.x;
				particlepos.y = snowman_pos2.y;

				if (snowman_hp2 < 0)
				{
					enemylive2 = false;
					snowman_hp2 = 20;
					snowman_pos2.x = 400000000;
				}
			}

			// �Ⴞ���3
			if (collision.square_square(snowman[3], use_rock[0]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp3 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos3.x;
				particlepos.y = snowman_pos3.y;

				if (snowman_hp3 < 0)
				{
					enemylive3 = false;
					snowman_hp3 = 20;
					snowman_pos3.x = 400000000;
				}
			}

			if (collision.square_square(snowman[3], use_rock[1]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp3 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos3.x;
				particlepos.y = snowman_pos3.y;

				if (snowman_hp3 < 0)
				{
					enemylive3 = false;
					snowman_hp3 = 20;
					snowman_pos3.x = 400000000;
				}
			}

			if (collision.square_square(snowman[3], use_rock[2]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp3 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos3.x;
				particlepos.y = snowman_pos3.y;

				if (snowman_hp3 < 0)
				{
					enemylive3 = false;
					snowman_hp3 = 20;
					snowman_pos3.x = 400000000;
				}
			}

			// �N���X�}�X�c���[
			if (collision.square_square(star_monster, use_rock[0]) == true) {
				star_monster_hp1 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = star_monster_pos.x;
				particlepos.y = star_monster_pos.y;
				if (star_monster_hp1 < 0)
				{
					enemylive4 = false;
					star_monster_hp1 = 40;
					star_monster_pos.x = 400000000;
				}
			}

			if (collision.square_square(star_monster, use_rock[1]) == true) {
				star_monster_hp1 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = star_monster_pos.x;
				particlepos.y = star_monster_pos.y;
				if (star_monster_hp1 < 0)
				{
					enemylive4 = false;
					star_monster_hp1 = 40;
					star_monster_pos.x = 400000000;
				}
			}

			if (collision.square_square(star_monster, use_rock[2]) == true) {
				star_monster_hp1 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = star_monster_pos.x;
				particlepos.y = star_monster_pos.y;
				if (star_monster_hp1 < 0)
				{
					enemylive4 = false;
					star_monster_hp1 = 40;
					star_monster_pos.x = 400000000;
				}
			}

			// �g�i�J�C
			if (collision.square_square(tonakai, use_rock[0]) == true) {
				tonakai_hp -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = tonakai_pos.x;
				particlepos.y = tonakai_pos.y;
				if (tonakai_hp < 0)
				{
					enemylive5 = false;
					tonakai_hp = 60;
					tonakai_pos.x = 400000000;
				}
			}

			if (collision.square_square(tonakai, use_rock[1]) == true) {
				tonakai_hp -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = tonakai_pos.x;
				particlepos.y = tonakai_pos.y;
				if (tonakai_hp < 0)
				{
					enemylive5 = false;
					tonakai_hp = 60;
					tonakai_pos.x = 400000000;
				}
			}

			if (collision.square_square(tonakai, use_rock[2]) == true) {
				tonakai_hp -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = tonakai_pos.x;
				particlepos.y = tonakai_pos.y;
				if (tonakai_hp < 0)
				{
					enemylive5 = false;
					tonakai_hp = 60;
					tonakai_pos.x = 400000000;
				}
			}


			// �������̓����蔻�� ���

			// �Ⴞ��܂P
			if (collision.square_square(snowman[1], use_snowball[0]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp1 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos1.x;
				particlepos.y = snowman_pos1.y;

				if (snowman_hp1 < 0)
				{
					enemylive1 = false;
					snowman_hp1 = 20;
					snowman_pos1.x = 400000000;
				}
			}

			if (collision.square_square(snowman[1], use_snowball[1]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp1 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos1.x;
				particlepos.y = snowman_pos1.y;

				if (snowman_hp1 < 0)
				{
					enemylive1 = false;
					snowman_hp1 = 20;
					snowman_pos1.x = 400000000;
				}
			}

			if (collision.square_square(snowman[1], use_snowball[2]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp1 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos1.x;
				particlepos.y = snowman_pos1.y;

				if (snowman_hp1 < 0)
				{
					enemylive1 = false;
					snowman_hp1 = 20;
					snowman_pos1.x = 400000000;
				}
			}

			// �Ⴞ��܂Q
			if (collision.square_square(snowman[2], use_snowball[0]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp2 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos2.x;
				particlepos.y = snowman_pos2.y;

				if (snowman_hp2 < 0)
				{
					enemylive2 = false;
					snowman_hp2 = 20;
					snowman_pos2.x = 400000000;
				}
			}

			if (collision.square_square(snowman[2], use_snowball[1]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp2 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos2.x;
				particlepos.y = snowman_pos2.y;

				if (snowman_hp2 < 0)
				{
					enemylive2 = false;
					snowman_hp2 = 20;
					snowman_pos2.x = 400000000;
				}
			}

			if (collision.square_square(snowman[2], use_snowball[2]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp2 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos2.x;
				particlepos.y = snowman_pos2.y;

				if (snowman_hp2 < 0)
				{
					enemylive2 = false;
					snowman_hp2 = 20;
					snowman_pos2.x = 400000000;
				}
			}

			// �Ⴞ���3
			if (collision.square_square(snowman[3], use_snowball[0]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp3 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos3.x;
				particlepos.y = snowman_pos3.y;

				if (snowman_hp3 < 0)
				{
					enemylive3 = false;
					snowman_hp3 = 20;
					snowman_pos3.x = 400000000;
				}
			}

			if (collision.square_square(snowman[3], use_snowball[1]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp3 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos3.x;
				particlepos.y = snowman_pos3.y;

				if (snowman_hp3 < 0)
				{
					enemylive3 = false;
					snowman_hp3 = 20;
					snowman_pos3.x = 400000000;
				}
			}

			if (collision.square_square(snowman[3], use_snowball[2]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp3 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos3.x;
				particlepos.y = snowman_pos3.y;

				if (snowman_hp3 < 0)
				{
					enemylive3 = false;
					snowman_hp3 = 20;
					snowman_pos3.x = 400000000;
				}
			}

			// �N���X�}�X�c���[
			if (collision.square_square(star_monster, use_snowball[0]) == true) {
				star_monster_hp1 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = star_monster_pos.x;
				particlepos.y = star_monster_pos.y;
				if (star_monster_hp1 < 0)
				{
					enemylive4 = false;
					star_monster_hp1 = 40;
					star_monster_pos.x = 400000000;
				}
			}

			if (collision.square_square(star_monster, use_snowball[1]) == true) {
				star_monster_hp1 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = star_monster_pos.x;
				particlepos.y = star_monster_pos.y;
				if (star_monster_hp1 < 0)
				{
					enemylive4 = false;
					star_monster_hp1 = 40;
					star_monster_pos.x = 400000000;
				}
			}

			if (collision.square_square(star_monster, use_snowball[2]) == true) {
				star_monster_hp1 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = star_monster_pos.x;
				particlepos.y = star_monster_pos.y;
				if (star_monster_hp1 < 0)
				{
					enemylive4 = false;
					star_monster_hp1 = 40;
					star_monster_pos.x = 400000000;
				}
			}

			// �g�i�J�C
			if (collision.square_square(tonakai, use_snowball[0]) == true) {
				tonakai_hp -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = tonakai_pos.x;
				particlepos.y = tonakai_pos.y;
				if (tonakai_hp < 0)
				{
					enemylive5 = false;
					tonakai_hp = 60;
					tonakai_pos.x = 400000000;
				}
			}

			if (collision.square_square(tonakai, use_snowball[1]) == true) {
				tonakai_hp -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = tonakai_pos.x;
				particlepos.y = tonakai_pos.y;
				if (tonakai_hp < 0)
				{
					enemylive5 = false;
					tonakai_hp = 60;
					tonakai_pos.x = 400000000;
				}
			}

			if (collision.square_square(tonakai, use_snowball[2]) == true) {
				tonakai_hp -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = tonakai_pos.x;
				particlepos.y = tonakai_pos.y;
				if (tonakai_hp < 0)
				{
					enemylive5 = false;
					tonakai_hp = 60;
					tonakai_pos.x = 400000000;
				}
			}

			//�p�[�e�B�N���A�j���[�V����
			if (particleFg)
			{
				particlecount++;
				if (particlecount % 5 == 0)
				{
					//particleFg = false;
					particle.numU++;
					if (particle.numU > 7)
					{
						particle.numU = 0;
						particleFg = false;
					}
				}

			}

			// �W�����v
			if (input.GetKeyTrigger(VK_SPACE) && jump == 0 || input.GetButtonTrigger(XINPUT_A) && jump == 0) {
				if (direction == 0) { // �E����
					if (bugPower == 0) {
						santaImage = 10;
						jump = 1;
						santa_Huro[2].numU = 0;
						santa_Huro[2].numV = 0;
					}
					else if (bugPower > 0) {
						santaImage = 12;
						jump = 2;
						santa_Nor[3].numU = 0;
						santa_Nor[3].numV = 0;
					}
				}
				else if (direction == 1) { // �E����
					if (bugPower == 0) {
						santaImage = 10;
						jump = 1;
						santa_Nor[2].numU = 0;
						santa_Nor[2].numV = 1;
					}
					else if (bugPower > 0) {
						santaImage = 12;
						jump = 2;
						santa_Nor[3].numU = 0;
						santa_Nor[3].numV = 1;
					}
				}
				get_jump_old = santa_huro_pos.y;

				jumpVelocity = 10.0f;

			}


			// �d��
			if (jump == 0) {
				santa_huro_pos.y += jumpVelocity;
				//	 �d�͂𑬓x�ɓK�p
				jumpVelocity += gravity;
				/*santa_kin_pos.y -= 2.0f;*/
			}


			//�W�����v����
			if (jump == 1 || jump == 2) {

				if (santa_huro_pos.y >= get_jump_old + 100.5f && jump == 1 || santa_huro_pos.y >= get_jump_old + 100.0f && jump == 2) {
					jump = 3;
				}
				else if (santa_huro_pos.y <= get_jump_old + 175.0f && jump == 1 || santa_huro_pos.y <= get_jump_old + 175.0f && jump == 2) {
					/*santa_kin_pos.y += 7.50;*/
					santa_huro_pos.y += jumpVelocity;
					//	 �d�͂𑬓x�ɓK�p
					jumpVelocity += gravity;
				}

			}
			if (jump == 3) {

				glideFg = true;
				if (input.GetKeyPress(VK_Q) && bugPower <= 0 || input.GetButtonPress(XINPUT_X) && bugPower <= 0)
				{
					santaImage = 16;
					glideFg = true;
					santa_huro_pos.y -= 1.5f;

					if (direction == 0) { // �E����
						santa_Huro[7].numU = 0;
						santa_Huro[7].numV = 0;
					}
					else if (direction == 1) { // ������
						santa_Huro[7].numU = 0;
						santa_Huro[7].numV = 1;
					}
					
				}
				else
				{
					santa_huro_pos.y += jumpVelocity;
					//	 �d�͂𑬓x�ɓK�p
					jumpVelocity += gravity;
					glideFg = false;
				}

				
				if (collision.ground_santa(ground[1], santa_Huro[0], 50.0f, 0.0f) == true ||
					collision.ground_santa(ground[2], santa_Huro[0], 50.0f, 0.0f) == true ||
					collision.ground_santa(ground[3], santa_Huro[0], 50.0f, 0.0f) == true ||
					collision.ground_santa(ground[4], santa_Huro[0], 50.0f, 0.0f) == true ||
					collision.ground_santa(ground[5], santa_Huro[0], 50.0f, 0.0f) == true ||
					collision.block_santa(stairs[1], santa_Huro[0], 100.0f, 0.0f) == true ||
					collision.block_santa(stairs[2], santa_Huro[0], 100.0f, 0.0f) == true ||
					collision.block_santa(stairs[3], santa_Huro[0], 100.0f, 0.0f) == true ||
					collision.block_santa(stairs[4], santa_Huro[0], 100.0f, 0.0f) == true ||
					collision.tree_santa(tree, santa_Huro[0], 1000.0f, 0.0f) == true)
				{

					jump = 0;
					jumpVelocity = 0.0f;
					glideFg = false;
					if (bugPower > 0) {
						santaImage = 9;
					}
					else if (bugPower == 0) {
						santaImage = 8;
					}
				}
			}

			// �؂Ƃ̓����蔻��̒ǉ��@�S���C
			if (collision.tree_santa(tree, santa_Huro[0], 200.0f, 0.0f))
			{
				if (tree_Ground == 3) {
					if (santa_huro_pos.y >= tree_pos.y) {
						jumpVelocity = 0.0f;
					}
				}
				else {
					//// �T���^���؂̉E���ɂԂ������ꍇ
					if (santa_huro_pos.x < tree_pos.x)
					{

						collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~

					}
				}


			}

			// �؂Ƃ̓����蔻��̒ǉ��@�S���C
			//if (collision.tree_santa(tree, santa_Huro[0], 200.0f, 0.0f))
			//{

			//	//// �T���^���؂̉E���ɂԂ������ꍇ
			//	if (santa_huro_pos.x < tree_pos.x)
			//	{

			//		collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~

			//	}

			//}
			//// �T���^���؂̍����ɂԂ������ꍇ
			//if (santa_pos.x > tree_pos.x) {
			//	//	collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
			//	//	
			//	//	
			//	//}
			//	//// �T���^���؂̍����ɂԂ������ꍇ
			//	if (santa_pos.x > tree_pos.x) {

			//		collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~

			//	}
			//}


			if (collision.tree_santa(invisiblewall[1], santa_Huro[0], 200.0f, 0.0f))
			{

				//// �T���^���؂̉E���ɂԂ������ꍇ
				if (santa_huro_pos.x < wall_pos1.x)
				{
					collision.canMoveRight = false; //�E�Ɉړ����Ȃ�ړ����~
				}

				// �T���^���؂̍����ɂԂ������ꍇ
				if (santa_huro_pos.x > wall_pos1.x)
				{
					collision.canMoveLeft = false; //�E�Ɉړ����Ȃ�ړ����~
				}
			}

			if (collision.tree_santa(invisiblewall[2], santa_Huro[0], 200.0f, 0.0f))
			{

				//// �T���^���؂̉E���ɂԂ������ꍇ
				if (santa_huro_pos.x < wall_pos2.x)
				{
					collision.canMoveRight = false; //�E�Ɉړ����Ȃ�ړ����~
				}

				// �T���^���؂̍����ɂԂ������ꍇ
				if (santa_huro_pos.x > wall_pos2.x)
				{
					collision.canMoveLeft = false; //�E�Ɉړ����Ȃ�ړ����~
				}

			}


			// 12/30  �T���^�̈ړ��A�j���[�V�����ǉ�  	�l��
			//�ړ����x


			speed = 5;





			// �ŗL�\�͔����I�I�I�I�I�I�I
			if (bugPower > 0 && input.GetKeyTrigger(VK_Q)&&glideFg==false && !wazafg || bugPower > 0 && input.GetButtonTrigger(XINPUT_X) && glideFg == false && !wazafg) { // �܂�����ۂ̎�
				
				santaImage = 15;
				if (changeRight_SP == true)
				{
					//������
					santa_Huro[6].numU = 0;
					santa_Huro[6].numV = 0;
					SantaAttackFg = true;
					changeRight_SP = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���
				}	
			}

			if (SantaAttackFg == true)
			{
				framcount3++; //�t���[���J�E���g
				if (framcount3 % 10== 0) //�P�O�t���[���Ɉ��s����
				{
					santa_Huro[6].numU++;
					if (santa_Huro[6].numU >= 5)
					{
						santa_Huro[6].numU = 0;
						SantaAttackFg = false;
						changeRight_SP = true;
						santaImage = 15;
						sound.Play(SOUND_huroshiki);
						ui = true;
					}
				}

			}
			//���C�~�̒��g����Ƃ��̔\��
			if (ui==true&&glideFg==false&&bugPower!=0&& !wazafg)
			{
				santa_huro_pos.y += 20;
				if (santa_huro_pos1.y >= 200 && glideFg == false)
				{
					ui = false;
					wazafg = true;
				}
			}
			if (wazafg)
			{
				if (santa_huro_pos1.y <= -140)
				{
					wazafg = false;
				}
			}
			

			// �E�ړ�
			if (sp_ani == false && gameoverFg == false && collision.canMoveRight && input.GetKeyPress(VK_D) && pauseFg == false
				&& SantaAttackFg == false || gameoverFg == false && collision.canMoveRight && input.GetLeftAnalogStick().x >= 0.1 && pauseFg == false)
			{
				direction = 0; // ����
				santa_huro_pos.x += 5;//�E�ړ�
				/*santa_kin_pos.x += 5;
				santa_pos.x += 5;*/


				if (bugPower == 0 && glideFg == false) {
					santaImage = 8;
					if (changeRight_SP_1 == true&&glideFg==false)
					{
						//������
						santa_Huro[0].numU = 0;
						santa_Huro[0].numV = 0;
						changeRight_SP_1 = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���
					}
					framcount6++; //�t���[���J�E���g
					if (framcount6 % 10 == 0 && glideFg == false) //�P�O�t���[���Ɉ��s����
					{
						santa_Huro[0].numU++;
						if (santa_Huro[0].numU >= 4)
						{
							santa_Huro[0].numU = 0;
							santa_Huro[0].numV++;
							if (santa_Huro[0].numV >= 2)
							{
								santa_Huro[0].numV = 0;
							}
						}
					}


				}
				else if (bugPower > 0 && glideFg == false) {
					santaImage = 9;
					if (changeRight == true && glideFg == false)
					{
						//������
						santa_Huro[1].numU = 0;
						santa_Huro[1].numV = 0;
						changeRight = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���
					}
					framcount++; //�t���[���J�E���g
					if (framcount % 10 == 0 && glideFg == false) //�P�O�t���[���Ɉ��s����
					{
						santa_Huro[1].numU++;
						if (santa_Huro[1].numU >= 4)
						{
							santa_Huro[1].numU = 0;
							santa_Huro[1].numV++;
							if (santa_Huro[1].numV >= 2)
							{
								santa_Huro[1].numV = 0;
							}
						}
					}

				}

				if (santa_huro_pos.x >= 0) //�v���C���[����ʐ^�񒆂ɍs�����Ƃ�
				{
					santa_huro_pos.x -= 5;

					//�w�i�Ȃǂ����ɓ������ăv���C���[���E�ɓ����Ă�悤�Ɍ�����
					//�R
					mounten_pos1.x -= speed - 4.5;
					mounten_pos2.x -= speed - 4.5;
					mounten_pos3.x -= speed - 4.5;
					//�w�i�̖�
					wood_pos1.x -= speed - 2;
					wood_pos2.x -= speed - 2;
					wood_pos3.x -= speed - 2;
					//�E�����
					rock_pos1.x -= speed;
					rock_pos2.x -= speed;
					rock_pos3.x -= speed;
					rock_pos4.x -= speed;
					rock_pos5.x -= speed;
					rock_pos6.x -= speed;
					//�n��
					ground_pos1.x -= speed;
					ground_pos2.x -= speed;
					ground_pos3.x -= speed;
					ground_pos4.x -= speed;
					ground_pos5.x -= speed;
					//�K�i
					stairs_pos1.x -= speed;
					stairs_pos2.x -= speed;
					stairs_pos3.x -= speed;
					stairs_pos4.x -= speed;
					//�Ⴞ���
					snowman_pos1.x -= speed;
					snowman_pos2.x -= speed;
					snowman_pos3.x -= speed;
					//���
					snowball_pos1.x -= speed;
					snowball_pos2.x -= speed;
					snowball_pos3.x -= speed;
					//���̂Ă�
					star_monster_pos.x -= speed;
					//�g�i�J�C
					tonakai_pos.x -= speed;
					//�v���[���g
					present_pos1.x -= speed;
					present_pos2.x -= speed;
					present_pos3.x -= speed;
					//�傫���v���[���g
					bigpresent_pos1.x -= speed;
					//��
					tree_pos.x -= speed;
					//�S�[��
					goal_pos.x -= speed;

					wall_pos1.x -= speed;
					wall_pos2.x -= speed;

					//�����A�C�e��
					use_rock_pos1.x -= speed;
					use_rock_pos2.x -= speed;
					use_rock_pos3.x -= speed;
					use_snowball_pos1.x -= speed;
					use_snowball_pos2.x -= speed;
					use_snowball_pos3.x -= speed;

				}
			}
			else
			{
				//�L�[�𗣂���true�ɖ߂�
				if (sp_ani == false && changeRight_SP_1 == false && glideFg == false) {

					santa_Huro[0].numU = 0;
					santa_Huro[0].numV = 0;
					santa_Huro[1].numU = 0;
					santa_Huro[1].numV = 0;
					if (bugPower > 0) {
						santaImage = 9;
					}
					else if (bugPower == 0) {
						santaImage = 8;
					}

				}

				changeRight = true;
				changeRight_SP_1 = true;
			}

			// ���ړ�
			if (sp_ani == false && gameoverFg == false && collision.canMoveLeft && input.GetKeyPress(VK_A) && pauseFg == false
				&& SantaAttackFg == false || gameoverFg == false && collision.canMoveLeft && input.GetLeftAnalogStick().x <= -0.1 && pauseFg == false)
			{
				direction = 1; // ����
				santa_huro_pos.x -= 5;//���ړ�


				if (bugPower == 0 && glideFg == false) {

					santaImage = 8;
					if (changeLeft_SP_1 == true)
					{
						//������
						santa_Huro[0].numU = 0;
						santa_Huro[0].numV = 2;
						changeLeft_SP_1 = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���
					}
					framcount6++; //�t���[���J�E���g
					if (framcount6 % 10 == 0) //�P�O�t���[���Ɉ��s����
					{
						santa_Huro[0].numU++;
						if (santa_Huro[0].numU >= 4)
						{

							santa_Huro[0].numU = 0;

						}
					}
				}
				else if (bugPower > 0&&glideFg == false) {

					if (changeLeft == true)
					{
						//������
						santa_Huro[1].numU = 0;
						santa_Huro[1].numV = 2;
						changeLeft = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���
					}
					framcount++; //�t���[���J�E���g
					if (framcount % 10 == 0) //�P�O�t���[���Ɉ��s����
					{
						santa_Huro[1].numU++;
						if (santa_Huro[1].numU >= 4)
						{
							santa_Huro[1].numU = 0;
							santa_Huro[1].numV++;
							if (santa_Huro[1].numV >= 4)
							{
								santa_Huro[1].numV = 2;
							}
						}
					}
				}
				if (santa_huro_pos.x <= 0) //�v���C���[����ʐ^�񒆂ɍs�����Ƃ�
				{
					santa_huro_pos.x += 5;



					//�w�i�Ȃǂ����ɓ������ăv���C���[���E�ɓ����Ă�悤�Ɍ�����
					//�R
					mounten_pos1.x += speed - 4.5;
					mounten_pos2.x += speed - 4.5;
					mounten_pos3.x += speed - 4.5;
					//�w�i�̖�
					wood_pos1.x += speed - 2;
					wood_pos2.x += speed - 2;
					wood_pos3.x += speed - 2;
					//�E�����
					rock_pos1.x += speed;
					rock_pos2.x += speed;
					rock_pos3.x += speed;
					rock_pos4.x += speed;
					rock_pos5.x += speed;
					rock_pos6.x += speed;
					//�n��
					ground_pos1.x += speed;
					ground_pos2.x += speed;
					ground_pos3.x += speed;
					ground_pos4.x += speed;
					ground_pos5.x += speed;
					//�K�i
					stairs_pos1.x += speed;
					stairs_pos2.x += speed;
					stairs_pos3.x += speed;
					stairs_pos4.x += speed;
					//�Ⴞ���
					snowman_pos1.x += speed;
					snowman_pos2.x += speed;
					snowman_pos3.x += speed;
					//���
					snowball_pos1.x += speed;
					snowball_pos2.x += speed;
					snowball_pos3.x += speed;
					//���̂Ă�
					star_monster_pos.x += speed;
					//�g�i�J�C
					tonakai_pos.x += speed;
					//�v���[���g
					present_pos1.x += speed;
					present_pos2.x += speed;
					present_pos3.x += speed;
					//�傫���v���[���g
					bigpresent_pos1.x += speed;
					//��
					tree_pos.x += speed;
					//�S�[��
					goal_pos.x += speed;

					wall_pos1.x += speed;
					wall_pos2.x += speed;

					//�����A�C�e��
					use_rock_pos1.x += speed;
					use_rock_pos2.x += speed;
					use_rock_pos3.x += speed;
					use_snowball_pos1.x += speed;
					use_snowball_pos2.x += speed;
					use_snowball_pos3.x += speed;
				}
			}
			else
			{
				//�L�[�𗣂���true�ɖ߂�
				if (sp_ani == false && changeLeft_SP_1 == false) {
					santa_Huro[0].numU = 0;
					santa_Huro[0].numV = 2;
					santa_Huro[1].numU = 0;
					santa_Huro[1].numV = 2;
					if (bugPower > 0) {
						santaImage = 9;
					}
					else if (bugPower == 0) {
						santaImage = 8;
					}
				}
				changeLeft = true;
				changeLeft_SP_1 = true;
			}
		}
		else if (santa_bug == 2)
		{
			santa_huro_pos.x = santa_kin_pos.x;
			santa_pos.x = santa_kin_pos.x;

			santa_huro_pos.y = santa_kin_pos.y;
			santa_pos.y = santa_kin_pos.y;
			
				// �Ⴞ��܂Ƃ̓����蔻��ǉ� 

				if (collision.enemy_santa(snowman[1], santa_Kin[0], 200.0f, 0.0f) && HitFg == false && pauseFg == false && gameoverFg == false)
				{
					time -= 5;
					hitcooltime = 0;
					sound.Play(SOUND_LABEL_SE000);
					damage5 = true;
					HitFg = true;
				}

				if (collision.enemy_santa(snowman[2], santa_Kin[0], 200.0f, 0.0f) && HitFg == false && pauseFg == false && gameoverFg == false)
				{
					time -= 5;
					hitcooltime = 0;
					sound.Play(SOUND_LABEL_SE000);
					damage5 = true;
					HitFg = true;
				}

				if (collision.enemy_santa(snowman[3], santa_Kin[0], 200.0f, 0.0f) && HitFg == false && pauseFg == false && gameoverFg == false)
				{
					time -= 5;
					hitcooltime = 0;
					sound.Play(SOUND_LABEL_SE000);
					damage5 = true;
					HitFg = true;
				}

				// ���Ƃ̓����蔻��ǉ� 
				if (collision.enemy_santa(star_monster, santa_Kin[0], 200.0f, 0.0f) && HitFg == false && pauseFg == false && gameoverFg == false)
				{
					sound.Play(SOUND_LABEL_SE000);
					time -= 5;
					hitcooltime = 0;
					damage5 = true;
					HitFg = true;
				}
				//�g�i�J�C �Ƃ̓����蔻��ǉ� 
				if (collision.enemy_santa(tonakai, santa_Kin[0], 200.0f, 0.0f) && HitFg == false && pauseFg == false && gameoverFg == false)
				{
					sound.Play(SOUND_LABEL_SE000);
					time -= 5;
					hitcooltime = 0;
					damage5 = true;
					HitFg = true;
				}


				//�v���[���g�̓����蔻��
				if (collision.item_santa(present[1], santa_Kin[0], 100.0f, 0.0f) && pauseFg == false)

				{
					presentcount += 1;
					score += 5000;
					present_pos1.y = 100000;
					sound.Play(SOUND_present);
				}

				if (collision.item_santa(present[2], santa_Kin[0], 100.0f, 0.0f))
				{
					presentcount += 1;
					score += 5000;
					present_pos2.y = 100000;
					sound.Play(SOUND_present);
				}

				if (collision.item_santa(present[3], santa_Kin[0], 100.0f, 0.0f))
				{
					presentcount += 1;
					score += 5000;
					present_pos3.y = 100000;
					sound.Play(SOUND_present);
				}

				if (collision.item_santa(BigPresent[1], santa_Kin[0], 100.0f, 0.0f))
				{
					bigpresentcount += 1;
					score += 10000;
					bigpresent_pos1.y = 100000;
					sound.Play(SOUND_present);
				}

				
				

				if (collision.block_santa(stairs[1], santa_Kin[0], 100.0f, 0.0f))
				{

					if (santa_kin_pos.y > stairs_pos1.y + stairs[1].GetSize().y / 2.0f) {
						santa_kin_pos.y = stairs_pos1.y + stairs[1].GetSize().y / 2.0f + santa_Kin[0].GetSize().y / 2.0f;
						jumpVelocity = 0.0f;
						/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
					}
					else {
						
					}

					if (santa_kin_pos.x < stairs_pos1.x)
					{
						collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
					}

					// �T���^���Ԃ������ꍇ
					if (santa_kin_pos.x > stairs_pos1.x)
					{
						collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
					}
				}
				else {
				
				}

				if (collision.block_santa(stairs[2], santa_Kin[0], 100.0f, 0.0f))
				{

					if (santa_kin_pos.y > stairs_pos2.y + stairs[2].GetSize().y / 2.0f) {
						santa_kin_pos.y = stairs_pos2.y + stairs[2].GetSize().y / 2.0f + santa_Kin[0].GetSize().y / 2.0f;
						jumpVelocity = 0.0f;
						/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
					}
					else {
						/*std::cout << "\nSanta is falling." << std::endl;*/
					}

					if (santa_kin_pos.x < stairs_pos2.x)
					{
						collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
					}

					// �T���^���Ԃ������ꍇ
					if (santa_kin_pos.x > stairs_pos2.x)
					{
						collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
					}
				}
				if (collision.block_santa(stairs[3], santa_Kin[0], 100.0f, 0.0f))
				{

					if (santa_kin_pos.y > stairs_pos3.y + stairs[3].GetSize().y / 2.0f) {
						santa_kin_pos.y = stairs_pos3.y + stairs[3].GetSize().y / 2.0f + santa_Kin[0].GetSize().y / 2.0f;
						/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
						jumpVelocity = 0.0f;
					}
					else {
						/*std::cout << "\nSanta is falling." << std::endl;*/
					}
					if (santa_kin_pos.x < stairs_pos3.x && santa_kin_pos.y / 2 < stairs_pos3.y / 3)
					{
						collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
					}

					// �T���^���Ԃ������ꍇ
					if (santa_kin_pos.x > stairs_pos3.x && santa_kin_pos.y / 2 < stairs_pos3.y / 3)
					{
						collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
					}
				}

				if (collision.block_santa(stairs[4], santa_Kin[0], 100.0f, 0.0f))
				{
					if (santa_kin_pos.y > stairs_pos4.y + stairs[4].GetSize().y / 2.0f) {
						santa_kin_pos.y = stairs_pos4.y + stairs[4].GetSize().y / 2.0f + santa_Kin[0].GetSize().y / 2.0f;
						jumpVelocity = 0.0f;
						/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
					}
					else {
						/*std::cout << "\nSanta is falling." << std::endl;*/
					}
					if (santa_kin_pos.x < stairs_pos4.x && santa_kin_pos.y / 2 < stairs_pos4.y / 3)
					{
						collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
					}

					// �T���^���Ԃ������ꍇ
					if (santa_kin_pos.x > stairs_pos4.x && santa_kin_pos.y / 2 < stairs_pos4.y / 3)
					{
						collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
					}
				}




				// �n�ʂƂ̓����蔻��̒ǉ� �S���C

				if (collision.ground_santa(ground[1], santa_Kin[0], 50.0f, 0.0f))
				{
					//// �T���^���n�ʂ̏�ɂ���ꍇ
					if (santa_kin_pos.y > ground_pos1.y + ground[1].GetSize().y / 2.0f) {
						santa_kin_pos.y = ground_pos1.y + ground[1].GetSize().y / 2.0f + santa_Kin[0].GetSize().y / 2.0f;
						jumpVelocity = 0.0f;
						/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
					}
					else {
						/*std::cout << "\nSanta is falling." << std::endl;*/
					}

					// �T���^���n�ʂ̉E���ɂԂ������ꍇ
					if (santa_kin_pos.x < ground_pos1.x && santa_kin_pos.y < ground_pos1.y) {

						collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
					}

					// �T���^���n�ʂɂԂ������ꍇ
					if (santa_kin_pos.x > ground_pos1.x && santa_kin_pos.y < ground_pos1.y) {
						collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
					}
				}

				if (collision.ground_santa(ground[2], santa_Kin[0], 50.0f, 0.0f))
				{
					//// �T���^���n�ʂ̏�ɂ���ꍇ
					if (santa_kin_pos.y > ground_pos2.y + ground[2].GetSize().y / 2.0f) {
						santa_kin_pos.y = ground_pos2.y + ground[2].GetSize().y / 2.0f + santa_Kin[0].GetSize().y / 2.0f;
						jumpVelocity = 0.0f;
						/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
					}
					else {
						/*std::cout << "\nSanta is falling." << std::endl;*/
					}

					// �T���^���n�ʂ̉E���ɂԂ������ꍇ
					if (santa_kin_pos.x < ground_pos2.x && santa_kin_pos.y < ground_pos2.y) {

						collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
					}

					// �T���^���n�ʂɂԂ������ꍇ
					if (santa_kin_pos.x > ground_pos2.x && santa_kin_pos.y < ground_pos2.y) {
						collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
					}
				}

				if (collision.ground_santa(ground[3], santa_Kin[0], 50.0f, 0.0f))
				{
					jump = 0;
					//// �T���^���n�ʂ̏�ɂ���ꍇ
					if (santa_kin_pos.y > ground_pos3.y + ground[3].GetSize().y / 2.0f) {
						santa_kin_pos.y = ground_pos3.y + ground[3].GetSize().y / 2.0f + santa_Kin[0].GetSize().y / 2.0f;
						jumpVelocity = 0.0f;
						/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
					}
					else {
						/*std::cout << "\nSanta is falling." << std::endl;*/
					}

					// �T���^���n�ʂ̉E���ɂԂ������ꍇ
					if (santa_kin_pos.x < ground_pos3.x && santa_kin_pos.y < ground_pos3.y) {

						collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
					}

					// �T���^���n�ʂɂԂ������ꍇ
					if (santa_kin_pos.x > ground_pos3.x && santa_kin_pos.y < ground_pos3.y) {
						collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
					}
				}

				if (collision.ground_santa(ground[4], santa_Kin[0], 50.0f, 0.0f))
				{
					//// �T���^���n�ʂ̏�ɂ���ꍇ
					if (santa_kin_pos.y > ground_pos4.y + ground[4].GetSize().y / 2.0f) {
						santa_kin_pos.y = ground_pos4.y + ground[4].GetSize().y / 2.0f + santa_Kin[0].GetSize().y / 2.0f;
						jumpVelocity = 0.0f;
						/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
					}
					else {
						/*std::cout << "\nSanta is falling." << std::endl;*/
					}

					// �T���^���n�ʂ̉E���ɂԂ������ꍇ
					if (santa_kin_pos.x < ground_pos4.x && santa_kin_pos.y < ground_pos4.y) {

						collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
					}

					// �T���^���n�ʂɂԂ������ꍇ
					if (santa_kin_pos.x > ground_pos4.x && santa_kin_pos.y < ground_pos4.y) {
						collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
					}
				}

				if (collision.ground_santa(ground[5], santa_Kin[0], 50.0f, 0.0f))
				{
					//// �T���^���n�ʂ̏�ɂ���ꍇ
					if (santa_kin_pos.y > ground_pos5.y + ground[5].GetSize().y / 2.0f) {
						santa_kin_pos.y = ground_pos5.y + ground[5].GetSize().y / 2.0f + santa_Kin[0].GetSize().y / 2.0f;
						jumpVelocity = 0.0f;
						/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
					}
					else {
						/*std::cout << "\nSanta is falling." << std::endl;*/
					}

					// �T���^���n�ʂ̉E���ɂԂ������ꍇ
					if (santa_kin_pos.x < ground_pos5.x && santa_kin_pos.y < ground_pos5.y) {

						collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
					}

					// �T���^���n�ʂɂԂ������ꍇ
					if (santa_kin_pos.x > ground_pos5.x && santa_kin_pos.y < ground_pos5.y) {
						collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
					}
				}
				if (collision.goal_santa(goal, santa_Kin[0], 250.0f, 0.0f))
				{

					// �T���^���S�[���̉E���ɂԂ������ꍇ
					if (santa_kin_pos.x < goal_pos.x && santa_kin_pos.y < goal_pos.y)
					{

						changescene = RESULT;
						//������
						santa_pos.x = -400;
						santa_kin_pos.x = -400;
						santa_huro_pos.x = -400;
						mounten_pos1.x = 0;
						mounten_pos2.x = 1280;
						mounten_pos3.x = 2560;

						santa_pos.x = -400;
						santa_pos.y = -175;

						santa_huro_pos.x = -400;
						santa_huro_pos.y = -175;

						santa_kin_pos.x = -400;
						santa_kin_pos.y = -175;

						wood_pos1.x = 0;
						wood_pos2.x = 1280;
						wood_pos3.x = 2560;

						wall_pos1.x = -600;
						wall_pos2.x = 5750;

						rock_pos1.x = -250;
						rock_pos2.x = 300;
						rock_pos3.x = 1100;
						rock_pos4.x = 1100;
						rock_pos5.x = 2300;
						rock_pos6.x = 4400;

						snowball_pos1.x = 1500;
						snowball_pos2.x = 2900;
						snowball_pos3.x = 4000;

						ground_pos1.x = 0;
						ground_pos2.x = 1300;
						ground_pos3.x = 3100;
						ground_pos4.x = 4500;
						ground_pos5.x = 5300;

						stairs_pos1.x = 540;
						stairs_pos2.x = 565;
						stairs_pos3.x = 600;
						stairs_pos4.x = 2800;

						snowman_pos1.x = 30;
						snowman_pos2.x = 1400;
						snowman_pos3.x = 2700;

						bigpresent_pos1.x = 5400;

						star_monster_pos.x = 4800;
						tonakai_pos.x = 3600;

						present_pos1.x = 800;
						present_pos2.x = 2800;
						present_pos3.x = 4500;

						present_pos1.y = -25;
						present_pos2.y = 160;
						present_pos3.y = -300;
						bigpresent_pos1.y = -25;

						tree_pos.x = 1900;
						goal_pos.x = 5800;
						sound.Stop(SOUND_LABEL_BGM000);
					}

				}





				if (collision.item_santa(rock[1], santa_Kin[0], 100.0f, 0.0f) && rock_visible1 == 0)
				{
					if (input.GetKeyTrigger(VK_S) && !itemCollected || input.GetButtonTrigger(XINPUT_B) && !itemCollected)
					{

						item->ItemGet(1); // ��������
						bugPower = item->GetItemCnt(); // ���݂̑܂̃A�C�e��������
						itemCollected = true;
						santaImage = 21;

						rock_visible1 = 1;

					}
				}

				if (collision.item_santa(rock[2], santa_Kin[0], 100.0f, 0.0f) && rock_visible2 == 0)
				{
					if (input.GetKeyTrigger(VK_S) && !itemCollected || input.GetButtonTrigger(XINPUT_B) && !itemCollected)
					{
						/*itemID = 1;*/
						item->ItemGet(1); // ��������
						bugPower = item->GetItemCnt(); // ���݂̑܂̃A�C�e��������
						itemCollected = true;
						santaImage = 21;

						rock_visible2 = 1;
					}
				}

				if (collision.item_santa(rock[3], santa_Kin[0], 100.0f, 0.0f) && rock_visible3 == 0)
				{
					if (input.GetKeyTrigger(VK_S) && !itemCollected || input.GetButtonTrigger(XINPUT_B) && !itemCollected)
					{
						/*itemID = 1;*/
						item->ItemGet(1); // ��������
						bugPower = item->GetItemCnt(); // ���݂̑܂̃A�C�e��������
						itemCollected = true;
						santaImage = 21;

						rock_visible3 = 1;
					}
				}

				if (collision.item_santa(rock[4], santa_Kin[0], 100.0f, 0.0f) && rock_visible4 == 0)
				{
					if (input.GetKeyTrigger(VK_S) && !itemCollected || input.GetButtonTrigger(XINPUT_B) && !itemCollected)
					{
						/*itemID = 1;*/
						item->ItemGet(1); // ��������
						bugPower = item->GetItemCnt(); // ���݂̑܂̃A�C�e��������
						itemCollected = true;
						santaImage = 21;

						rock_visible4 = 1;
					}
				}

				if (collision.item_santa(rock[5], santa_Kin[0], 100.0f, 0.0f) && rock_visible5 == 0)
				{
					if (input.GetKeyTrigger(VK_S) && !itemCollected || input.GetButtonTrigger(XINPUT_B) && !itemCollected)
					{
						/*itemID = 1;*/
						item->ItemGet(1); // ��������
						bugPower = item->GetItemCnt(); // ���݂̑܂̃A�C�e��������
						itemCollected = true;
						santaImage = 21;

						rock_visible5 = 1;
					}
				}

				if (collision.item_santa(rock[6], santa_Kin[0], 100.0f, 0.0f) && rock_visible6 == 0)
				{
					if (input.GetKeyTrigger(VK_S) && !itemCollected || input.GetButtonTrigger(XINPUT_B) && !itemCollected)
					{
						/*itemID = 1;*/
						item->ItemGet(1); // ��������
						bugPower = item->GetItemCnt(); // ���݂̑܂̃A�C�e��������
						itemCollected = true;
						santaImage = 21;

						rock_visible6 = 1;
					}
				}

				if (collision.item_santa(snowball[1], santa_Kin[0], 100.0f, 0.0f) && snow_visible1 == 0)
				{
					if (input.GetKeyTrigger(VK_S) && !itemCollected || input.GetButtonTrigger(XINPUT_B) && !itemCollected)
					{
						/*itemID = 1;*/
						item->ItemGet(2); // ��������
						bugPower = item->GetItemCnt(); // ���݂̑܂̃A�C�e��������
						itemCollected = true;
						santaImage = 21;

						snow_visible1 = 1;
					}
				}

				if (collision.item_santa(snowball[2], santa_Kin[0], 100.0f, 0.0f) && snow_visible1 == 0)
				{
					if (input.GetKeyTrigger(VK_S) && !itemCollected || input.GetButtonTrigger(XINPUT_B) && !itemCollected)
					{
						/*itemID = 1;*/
						item->ItemGet(2); // ��������
						bugPower = item->GetItemCnt(); // ���݂̑܂̃A�C�e��������
						itemCollected = true;
						santaImage = 21;

						snow_visible2 = 1;
					}
				}

				if (collision.item_santa(snowball[3], santa_Kin[0], 100.0f, 0.0f) && snow_visible1 == 0)
				{
					if (input.GetKeyTrigger(VK_S) && !itemCollected || input.GetButtonTrigger(XINPUT_B) && !itemCollected)
					{
						/*itemID = 1;*/
						item->ItemGet(2); // ��������
						bugPower = item->GetItemCnt(); // ���݂̑܂̃A�C�e��������
						itemCollected = true;
						santaImage = 21;

						snow_visible3 = 1;
					}
				}

				// ��ʊO�ɍs���ƁA�A�C�e�����ăX�|�[�����鏈��
				if (leftScreen > rock_pos1.x || rock_pos1.x > rightScreen) {
					rock_visible1 = 0;
				}
				if (leftScreen > rock_pos2.x || rock_pos2.x > rightScreen) {
					rock_visible2 = 0;
				}
				if (leftScreen > rock_pos3.x || rock_pos3.x > rightScreen) {
					rock_visible3 = 0;
				}
				if (leftScreen > rock_pos4.x || rock_pos4.x > rightScreen) {
					rock_visible4 = 0;
				}
				if (leftScreen > rock_pos5.x || rock_pos5.x > rightScreen) {
					rock_visible5 = 0;
				}
				if (leftScreen > rock_pos6.x || rock_pos6.x > rightScreen) {
					rock_visible6 = 0;
				}
				if (leftScreen > snowball_pos1.x || snowball_pos1.x > rightScreen) {
					snow_visible1 = 0;
				}
				if (leftScreen > snowball_pos2.x || snowball_pos2.x > rightScreen) {
					snow_visible2 = 0;
				}
				if (leftScreen > snowball_pos3.x || snowball_pos3.x > rightScreen) {
					snow_visible3 = 0;
				}


				if (!itemCollected && !changeItem) {// �������ĂȂ��ꍇ
					if (input.GetKeyTrigger(VK_S) && pauseFg == false || input.GetButtonTrigger(XINPUT_B) && pauseFg == false)
					{

						if (item->GetItem_3() > 0) {
							changeItem = true;

							if (item->GetItem_3() == 1) {
								use_rock_pos3.x = santa_kin_pos.x;
								use_rock_pos3.y = santa_kin_pos.y;
								sound.Play(SOUND_LABEL_SE003);
								itemID_3 = 1;
								itemMove3 = true;
							}
							else if (item->GetItem_3() == 2) {
								use_snowball_pos3.x = santa_kin_pos.x;
								use_snowball_pos3.y = santa_kin_pos.y;
								sound.Play(SOUND_LABEL_SE003);
								itemID_3 = 2;
								itemMove3 = true;
							}

						}
						else if (item->GetItem_3() < 0) {

							if (item->GetItem_2() > 0) {

								if (item->GetItem_2() == 1) {
									use_rock_pos2.x = santa_kin_pos.x;
									use_rock_pos2.y = santa_kin_pos.y;
									sound.Play(SOUND_LABEL_SE003);
									itemID_2 = 1;
									itemMove2 = true;
								}
								else if (item->GetItem_2() == 2) {
									use_snowball_pos2.x = santa_kin_pos.x;
									use_snowball_pos2.y = santa_kin_pos.y;
									sound.Play(SOUND_LABEL_SE003);
									itemID_2 = 2;
									itemMove2 = true;
								}

							}
							else if (item->GetItem_2() < 0) {

								if (item->GetItem_1() > 0) {

									if (item->GetItem_1() == 1) {
										use_rock_pos1.x = santa_kin_pos.x;
										use_rock_pos1.y = santa_kin_pos.y;
										itemID_1 = 1;
										itemMove1 = true;
									}
									else if (item->GetItem_1() == 2) {
										use_snowball_pos1.x = santa_kin_pos.x;
										use_snowball_pos1.y = santa_kin_pos.y;
										itemID_1 = 2;
										itemMove1 = true;
									}

								}
							}
						}

						santaImage = 22;
						item->ItemRelease(); // ���o��
						bugPower = item->GetItemCnt();
					}
				}



				// ����A�j���[�V����
				if (santaImage == 21) {
					getItem = 1;
					if (direction == 0) { // �E����
						if (changeRight_get == true)
						{
							//������
							santa_Kin[4].numU = 0;
							santa_Kin[4].numV = 0;
							changeRight_get = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���
						}
						framcount4++; //�t���[���J�E���g
						if (framcount4 % 4 == 0) //�P�O�t���[���Ɉ��s����
						{
							santa_Kin[4].numU++;
							if (santa_Kin[4].numU >= 5)
							{
								sp_ani = false;
								santaImage = 18;
								getItem = 0;
								santa_Kin[4].numU = 0;

							}
						}
					}
					else if (direction == 1) {
						if (changeLeft_get == true)
						{
							//������
							santa_Kin[4].numU = 0;
							santa_Kin[4].numV = 1;
							changeLeft_get = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���
						}
						framcount4++; //�t���[���J�E���g
						if (framcount4 % 4 == 0) //�P�O�t���[���Ɉ��s����
						{
							santa_Kin[4].numU++;
							if (santa_Kin[4].numU >= 5)
							{
								sp_ani = false;
								santaImage = 18;
								getItem = 0;
								santa_Kin[4].numU = 0;

							}
						}
					}
				}

				// ��o�A�j���[�V����
				if (santaImage == 22) {

					if (direction == 0) { // �E����
						if (changeRight_out == true)
						{
							//������
							santa_Kin[5].numU = 0;
							santa_Kin[5].numV = 0;
							changeRight_out = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���
						}
						framcount5++; //�t���[���J�E���g
						if (framcount5 % 4 == 0) //�P�O�t���[���Ɉ��s����
						{
							santa_Kin[5].numU++;
							if (santa_Kin[5].numU >= 5)
							{
								sp_ani = false;
								if (bugPower > 0) {
									santaImage = 18;
								}
								else if (bugPower == 0) {
									santaImage = 17;
								}

								santa_Kin[5].numU = 0;
								changeRight_out = true;

							}
						}
					}
					else if (direction == 1) {
						if (changeLeft_out == true)
						{
							//������
							santa_Kin[5].numU = 0;
							santa_Kin[5].numV = 1;
							changeLeft_out = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���
						}
						framcount5++; //�t���[���J�E���g
						if (framcount5 % 4 == 0) //�P�O�t���[���Ɉ��s����
						{
							santa_Kin[5].numU++;
							if (santa_Kin[5].numU >= 5)
							{
								sp_ani = false;
								if (bugPower > 0) {
									santaImage = 18;
								}
								else if (bugPower == 0) {
									santaImage = 17;
								}
								santa_Kin[5].numU = 0;
								changeLeft_out = true;

							}
						}
					}
				}

				// �������̓����@���̇@ 
				if (itemMove1 == true) {
					if (direction == 0) { // �E����

						if (itemID_1 == 1) { // ��

							if (itemMove1_M == true || use_rock_pos1.y >= -100.0f) {
								itemMove1_M = true;
								use_rock_pos1.y -= 3.00f;
								use_rock_pos1.x += 3.00f;
							}
							else if (itemMove1_M == false) {
								use_rock_pos1.y += 3.00f;
								use_rock_pos1.x += 3.00f;
							}
							if (use_rock_pos1.y <= -190.0f && itemMove1_M == true) {
								itemID_1 = 0;
								itemMove1_M = false;
								itemMove1 = false;
							}
						}
						else if (itemID_1 == 2) {
							if (use_snowball_pos1.x >= rightScreen) {
								itemID_1 = 0;
								itemMove1 = false;
							}
							else if (use_snowball_pos1.x <= rightScreen) {
								use_snowball_pos1.x += 20.00f;
							}
						}
					}
					else if (direction == 1) { // ������

						if (itemID_1 == 1) { // ��

							if (itemMove1_M == true || use_rock_pos1.y >= -100.0f) {
								itemMove1_M = true;
								use_rock_pos1.y -= 3.00f;
								use_rock_pos1.x -= 3.00f;
							}
							else if (itemMove1_M == false) {
								use_rock_pos1.y += 3.00f;
								use_rock_pos1.x -= 3.00f;
							}
							if (use_rock_pos1.y <= -190.0f && itemMove1_M == true) {
								itemID_1 = 0;
								itemMove1_M = false;
								itemMove1 = false;
							}
						}
						else if (itemID_1 == 2) {
							if (use_snowball_pos1.x <= leftScreen) {
								itemID_1 = 0;
								itemMove1 = false;
							}
							else if (use_snowball_pos1.x >= leftScreen) {
								use_snowball_pos1.x -= 20.00f;
							}
						}
					}



				}

				// �������̓����@���̇A
				if (itemMove2 == true) {
					if (direction == 0) { // �E����

						if (itemID_2 == 1) { //��

							if (itemMove2_M == true || use_rock_pos2.y >= -100.0f) {
								itemMove2_M = true;
								use_rock_pos2.y -= 3.00f;
								use_rock_pos2.x += 3.00f;
							}
							else if (itemMove2_M == false) {
								use_rock_pos2.y += 3.00f;
								use_rock_pos2.x += 3.00f;
							}
							if (use_rock_pos2.y <= -190.0f && itemMove2_M == true) {
								itemID_2 = 0;
								itemMove2_M = false;
								itemMove2 = false;
							}
						}
						else if (itemID_2 == 2) {
							if (use_snowball_pos2.x >= rightScreen) {
								itemID_2 = 0;
								itemMove2 = false;
							}
							else if (use_snowball_pos2.x <= rightScreen) {
								use_snowball_pos2.x += 20.00f;
							}
						}
					}
					else if (direction == 1) { // ������

						if (itemID_2 == 1) { //��

							if (itemMove2_M == true || use_rock_pos2.y >= -100.0f) {
								itemMove2_M = true;
								use_rock_pos2.y -= 3.00f;
								use_rock_pos2.x -= 3.00f;
							}
							else if (itemMove2_M == false) {
								use_rock_pos2.y += 3.00f;
								use_rock_pos2.x -= 3.00f;
							}
							if (use_rock_pos2.y <= -190.0f && itemMove2_M == true) {
								itemID_2 = 0;
								itemMove2_M = false;
								itemMove2 = false;
							}
						}
						else if (itemID_2 == 2) {
							if (use_snowball_pos2.x <= leftScreen) {
								itemID_2 = 0;
								itemMove2 = false;
							}
							else if (use_snowball_pos2.x >= leftScreen) {
								use_snowball_pos2.x -= 20.00f;
							}
						}
					}


				}

				// �������̓����@���̇B
				if (itemMove3 == true) {

					if (direction == 0) { // �E����

						if (itemID_3 == 1) { // ��

							if (itemMove3_M == true || use_rock_pos3.y >= -100.0f) {
								itemMove3_M = true;
								use_rock_pos3.y -= 3.00f;
								use_rock_pos3.x += 3.00f;
							}
							else if (itemMove3_M == false) {
								use_rock_pos3.y += 3.00f;
								use_rock_pos3.x += 3.00f;
							}
							if (use_rock_pos3.y <= -190.0f && itemMove3_M == true) {
								itemID_3 = 0;
								itemMove3_M = false;
								itemMove3 = false;
								changeItem = false;
							}
						}
						else if (itemID_3 == 2) {
							if (use_snowball_pos3.x >= rightScreen) {
								itemID_3 = 0;
								itemMove3 = false;
								changeItem = false;
							}
							else if (use_snowball_pos3.x <= rightScreen) {
								use_snowball_pos3.x += 30.00f;
							}
						}
					}
					else if (direction == 1) { // ������

						if (itemID_3 == 1) { // ��

							if (itemMove3_M == true || use_rock_pos3.y >= -100.0f) {
								itemMove3_M = true;
								use_rock_pos3.y -= 3.00f;
								use_rock_pos3.x -= 3.00f;
							}
							else if (itemMove3_M == false) {
								use_rock_pos3.y += 3.00f;
								use_rock_pos3.x -= 3.00f;
							}
							if (use_rock_pos3.y <= -190.0f && itemMove3_M == true) {
								itemID_3 = 0;
								itemMove3_M = false;
								itemMove3 = false;
								changeItem = false;
							}
						}
						else if (itemID_3 == 2) {
							if (use_snowball_pos3.x <= leftScreen) {
								itemID_3 = 0;
								itemMove3 = false;
								changeItem = false;
							}
							else if (use_snowball_pos3.x >= leftScreen) {
								use_snowball_pos3.x -= 30.00f;
							}
						}
					}


				}

				// �������̓����蔻�� ��

				// �Ⴞ��܂P
				if (collision.square_square(snowman[1], use_rock[0]) == true) {
					sound.Play(SOUND_LABEL_SE004);
					snowman_hp1 -= santa_atk;

					particleFg = true;
					particlepos.x = snowman_pos1.x;
					particlepos.y = snowman_pos1.y;

					if (snowman_hp1 < 0)
					{
						enemylive1 = false;
						snowman_hp1 = 20;
						snowman_pos1.x = 400000000;
					}
				}

				if (collision.square_square(snowman[1], use_rock[1]) == true) {
					sound.Play(SOUND_LABEL_SE004);
					snowman_hp1 -= santa_atk;

					particleFg = true;
					particlepos.x = snowman_pos1.x;
					particlepos.y = snowman_pos1.y;

					if (snowman_hp1 < 0)
					{
						enemylive1 = false;
						snowman_hp1 = 20;
						snowman_pos1.x = 400000000;
					}
				}

				if (collision.square_square(snowman[1], use_rock[2]) == true) {
					sound.Play(SOUND_LABEL_SE004);
					snowman_hp1 -= santa_atk;

					particleFg = true;
					particlepos.x = snowman_pos1.x;
					particlepos.y = snowman_pos1.y;

					if (snowman_hp1 < 0)
					{
						enemylive1 = false;
						snowman_hp1 = 20;
						snowman_pos1.x = 400000000;
					}
				}

				// �Ⴞ��܂Q
				if (collision.square_square(snowman[2], use_rock[0]) == true) {
					sound.Play(SOUND_LABEL_SE004);
					snowman_hp2 -= santa_atk;

					particleFg = true;
					particlepos.x = snowman_pos2.x;
					particlepos.y = snowman_pos2.y;

					if (snowman_hp2 < 0)
					{
						enemylive2 = false;
						snowman_hp2 = 20;
						snowman_pos2.x = 400000000;
					}
				}

				if (collision.square_square(snowman[2], use_rock[1]) == true) {
					sound.Play(SOUND_LABEL_SE004);
					snowman_hp2 -= santa_atk;

					particleFg = true;
					particlepos.x = snowman_pos2.x;
					particlepos.y = snowman_pos2.y;

					if (snowman_hp2 < 0)
					{
						enemylive2 = false;
						snowman_hp2 = 20;
						snowman_pos2.x = 400000000;
					}
				}

				if (collision.square_square(snowman[2], use_rock[2]) == true) {
					sound.Play(SOUND_LABEL_SE004);
					snowman_hp2 -= santa_atk;

					particleFg = true;
					particlepos.x = snowman_pos2.x;
					particlepos.y = snowman_pos2.y;

					if (snowman_hp2 < 0)
					{
						enemylive2 = false;
						snowman_hp2 = 20;
						snowman_pos2.x = 400000000;
					}
				}

				// �Ⴞ���3
				if (collision.square_square(snowman[3], use_rock[0]) == true) {
					sound.Play(SOUND_LABEL_SE004);
					snowman_hp3 -= santa_atk;

					particleFg = true;
					particlepos.x = snowman_pos3.x;
					particlepos.y = snowman_pos3.y;

					if (snowman_hp3 < 0)
					{
						enemylive3 = false;
						snowman_hp3 = 20;
						snowman_pos3.x = 400000000;
					}
				}

				if (collision.square_square(snowman[3], use_rock[1]) == true) {
					sound.Play(SOUND_LABEL_SE004);
					snowman_hp3 -= santa_atk;

					particleFg = true;
					particlepos.x = snowman_pos3.x;
					particlepos.y = snowman_pos3.y;

					if (snowman_hp3 < 0)
					{
						enemylive3 = false;
						snowman_hp3 = 20;
						snowman_pos3.x = 400000000;
					}
				}

				if (collision.square_square(snowman[3], use_rock[2]) == true) {
					sound.Play(SOUND_LABEL_SE004);
					snowman_hp3 -= santa_atk;

					particleFg = true;
					particlepos.x = snowman_pos3.x;
					particlepos.y = snowman_pos3.y;

					if (snowman_hp3 < 0)
					{
						enemylive3 = false;
						snowman_hp3 = 20;
						snowman_pos3.x = 400000000;
					}
				}

				// �N���X�}�X�c���[
				if (collision.square_square(star_monster, use_rock[0]) == true) {
					star_monster_hp1 -= santa_atk;
					sound.Play(SOUND_LABEL_SE004);
					particleFg = true;
					particlepos.x = star_monster_pos.x;
					particlepos.y = star_monster_pos.y;
					if (star_monster_hp1 < 0)
					{
						enemylive4 = false;
						star_monster_hp1 = 40;
						star_monster_pos.x = 400000000;
					}
				}

				if (collision.square_square(star_monster, use_rock[1]) == true) {
					star_monster_hp1 -= santa_atk;
					sound.Play(SOUND_LABEL_SE004);
					particleFg = true;
					particlepos.x = star_monster_pos.x;
					particlepos.y = star_monster_pos.y;
					if (star_monster_hp1 < 0)
					{
						enemylive4 = false;
						star_monster_hp1 = 40;
						star_monster_pos.x = 400000000;
					}
				}

				if (collision.square_square(star_monster, use_rock[2]) == true) {
					star_monster_hp1 -= santa_atk;
					sound.Play(SOUND_LABEL_SE004);
					particleFg = true;
					particlepos.x = star_monster_pos.x;
					particlepos.y = star_monster_pos.y;
					if (star_monster_hp1 < 0)
					{
						enemylive4 = false;
						star_monster_hp1 = 40;
						star_monster_pos.x = 400000000;
					}
				}

				// �g�i�J�C
				if (collision.square_square(tonakai, use_rock[0]) == true) {
					tonakai_hp -= santa_atk;
					sound.Play(SOUND_LABEL_SE004);
					particleFg = true;
					particlepos.x = tonakai_pos.x;
					particlepos.y = tonakai_pos.y;
					if (tonakai_hp < 0)
					{
						enemylive5 = false;
						tonakai_hp = 60;
						tonakai_pos.x = 400000000;
					}
				}

				if (collision.square_square(tonakai, use_rock[1]) == true) {
					tonakai_hp -= santa_atk;
					sound.Play(SOUND_LABEL_SE004);
					particleFg = true;
					particlepos.x = tonakai_pos.x;
					particlepos.y = tonakai_pos.y;
					if (tonakai_hp < 0)
					{
						enemylive5 = false;
						tonakai_hp = 60;
						tonakai_pos.x = 400000000;
					}
				}

				if (collision.square_square(tonakai, use_rock[2]) == true) {
					tonakai_hp -= santa_atk;
					sound.Play(SOUND_LABEL_SE004);
					particleFg = true;
					particlepos.x = tonakai_pos.x;
					particlepos.y = tonakai_pos.y;
					if (tonakai_hp < 0)
					{
						enemylive5 = false;
						tonakai_hp = 60;
						tonakai_pos.x = 400000000;
					}
				}


				// �������̓����蔻�� ���

				// �Ⴞ��܂P
				if (collision.square_square(snowman[1],use_snowball[0]) == true) {
					sound.Play(SOUND_LABEL_SE004);
					snowman_hp1 -= santa_atk;

					particleFg = true;
					particlepos.x = snowman_pos1.x;
					particlepos.y = snowman_pos1.y;

					if (snowman_hp1 < 0)
					{
						enemylive1 = false;
						snowman_hp1 = 20;
						snowman_pos1.x = 400000000;
					}
				}

				if (collision.square_square(snowman[1], use_snowball[1]) == true) {
					sound.Play(SOUND_LABEL_SE004);
					snowman_hp1 -= santa_atk;

					particleFg = true;
					particlepos.x = snowman_pos1.x;
					particlepos.y = snowman_pos1.y;

					if (snowman_hp1 < 0)
					{
						enemylive1 = false;
						snowman_hp1 = 20;
						snowman_pos1.x = 400000000;
					}
				}

				if (collision.square_square(snowman[1], use_snowball[2]) == true) {
					sound.Play(SOUND_LABEL_SE004);
					snowman_hp1 -= santa_atk;

					particleFg = true;
					particlepos.x = snowman_pos1.x;
					particlepos.y = snowman_pos1.y;

					if (snowman_hp1 < 0)
					{
						enemylive1 = false;
						snowman_hp1 = 20;
						snowman_pos1.x = 400000000;
					}
				}

				// �Ⴞ��܂Q
				if (collision.square_square(snowman[2], use_snowball[0]) == true) {
					sound.Play(SOUND_LABEL_SE004);
					snowman_hp2 -= santa_atk;

					particleFg = true;
					particlepos.x = snowman_pos2.x;
					particlepos.y = snowman_pos2.y;

					if (snowman_hp2 < 0)
					{
						enemylive2 = false;
						snowman_hp2 = 20;
						snowman_pos2.x = 400000000;
					}
				}

				if (collision.square_square(snowman[2], use_snowball[1]) == true) {
					sound.Play(SOUND_LABEL_SE004);
					snowman_hp2 -= santa_atk;

					particleFg = true;
					particlepos.x = snowman_pos2.x;
					particlepos.y = snowman_pos2.y;

					if (snowman_hp2 < 0)
					{
						enemylive2 = false;
						snowman_hp2 = 20;
						snowman_pos2.x = 400000000;
					}
				}

				if (collision.square_square(snowman[2], use_snowball[2]) == true) {
					sound.Play(SOUND_LABEL_SE004);
					snowman_hp2 -= santa_atk;

					particleFg = true;
					particlepos.x = snowman_pos2.x;
					particlepos.y = snowman_pos2.y;

					if (snowman_hp2 < 0)
					{
						enemylive2 = false;
						snowman_hp2 = 20;
						snowman_pos2.x = 400000000;
					}
				}

				// �Ⴞ���3
				if (collision.square_square(snowman[3], use_snowball[0]) == true) {
					sound.Play(SOUND_LABEL_SE004);
					snowman_hp3 -= santa_atk;

					particleFg = true;
					particlepos.x = snowman_pos3.x;
					particlepos.y = snowman_pos3.y;

					if (snowman_hp3 < 0)
					{
						enemylive3 = false;
						snowman_hp3 = 20;
						snowman_pos3.x = 400000000;
					}
				}

				if (collision.square_square(snowman[3], use_snowball[1]) == true) {
					sound.Play(SOUND_LABEL_SE004);
					snowman_hp3 -= santa_atk;

					particleFg = true;
					particlepos.x = snowman_pos3.x;
					particlepos.y = snowman_pos3.y;

					if (snowman_hp3 < 0)
					{
						enemylive3 = false;
						snowman_hp3 = 20;
						snowman_pos3.x = 400000000;
					}
				}

				if (collision.square_square(snowman[3], use_snowball[2]) == true) {
					sound.Play(SOUND_LABEL_SE004);
					snowman_hp3 -= santa_atk;

					particleFg = true;
					particlepos.x = snowman_pos3.x;
					particlepos.y = snowman_pos3.y;

					if (snowman_hp3 < 0)
					{
						enemylive3 = false;
						snowman_hp3 = 20;
						snowman_pos3.x = 400000000;
					}
				}

				// �N���X�}�X�c���[
				if (collision.square_square(star_monster, use_snowball[0]) == true) {
					star_monster_hp1 -= santa_atk;
					sound.Play(SOUND_LABEL_SE004);
					particleFg = true;
					particlepos.x = star_monster_pos.x;
					particlepos.y = star_monster_pos.y;
					if (star_monster_hp1 < 0)
					{
						enemylive4 = false;
						star_monster_hp1 = 40;
						star_monster_pos.x = 400000000;
					}
				}

				if (collision.square_square(star_monster, use_snowball[1]) == true) {
					star_monster_hp1 -= santa_atk;
					sound.Play(SOUND_LABEL_SE004);
					particleFg = true;
					particlepos.x = star_monster_pos.x;
					particlepos.y = star_monster_pos.y;
					if (star_monster_hp1 < 0)
					{
						enemylive4 = false;
						star_monster_hp1 = 40;
						star_monster_pos.x = 400000000;
					}
				}

				if (collision.square_square(star_monster, use_snowball[2]) == true) {
					star_monster_hp1 -= santa_atk;
					sound.Play(SOUND_LABEL_SE004);
					particleFg = true;
					particlepos.x = star_monster_pos.x;
					particlepos.y = star_monster_pos.y;
					if (star_monster_hp1 < 0)
					{
						enemylive4 = false;
						star_monster_hp1 = 40;
						star_monster_pos.x = 400000000;
					}
				}

				// �g�i�J�C
				if (collision.square_square(tonakai, use_snowball[0]) == true) {
					tonakai_hp -= santa_atk;
					sound.Play(SOUND_LABEL_SE004);
					particleFg = true;
					particlepos.x = tonakai_pos.x;
					particlepos.y = tonakai_pos.y;
					if (tonakai_hp < 0)
					{
						enemylive5 = false;
						tonakai_hp = 60;
						tonakai_pos.x = 400000000;
					}
				}

				if (collision.square_square(tonakai, use_snowball[1]) == true) {
					tonakai_hp -= santa_atk;
					sound.Play(SOUND_LABEL_SE004);
					particleFg = true;
					particlepos.x = tonakai_pos.x;
					particlepos.y = tonakai_pos.y;
					if (tonakai_hp < 0)
					{
						enemylive5 = false;
						tonakai_hp = 60;
						tonakai_pos.x = 400000000;
					}
				}

				if (collision.square_square(tonakai, use_snowball[2]) == true) {
					tonakai_hp -= santa_atk;
					sound.Play(SOUND_LABEL_SE004);
					particleFg = true;
					particlepos.x = tonakai_pos.x;
					particlepos.y = tonakai_pos.y;
					if (tonakai_hp < 0)
					{
						enemylive5 = false;
						tonakai_hp = 60;
						tonakai_pos.x = 400000000;
					}
				}



				// �W�����v
				if (input.GetKeyTrigger(VK_SPACE) && jump == 0 || input.GetButtonTrigger(XINPUT_A) && jump == 0) {
 					if (direction == 0) { // �E����
						if (bugPower == 0) {
							santaImage = 19;
							jump = 1;
							santa_Kin[2].numU = 0;
							santa_Kin[2].numV = 0;
						}
						else if (bugPower > 0) {
							santaImage = 20;
							jump = 2;
							santa_Kin[3].numU = 0;
							santa_Kin[3].numV = 0;
						}
						get_jump_old = santa_kin_pos.y;
					}
					else if (direction == 1) { // �E����
						if (bugPower == 0) {
							santaImage = 19;
							jump = 1;
							santa_Kin[2].numU = 0;
							santa_Kin[2].numV = 1;
						}
						else if (bugPower > 0) {
							santaImage = 20;
							jump = 2;
							santa_Kin[3].numU = 0;
							santa_Kin[3].numV = 1;
						}
					}
					get_jump_old = santa_kin_pos.y;
					
					jumpVelocity = 10.0f;
				}

				// �d��
				if (jump == 0) {
					santa_kin_pos.y += jumpVelocity;
					//	 �d�͂𑬓x�ɓK�p
					jumpVelocity += gravity;
					/*santa_kin_pos.y -= 2.0f;*/
				}
				

				//�W�����v����
				if (jump == 1 || jump == 2) {

					if (santa_kin_pos.y >= get_jump_old + 100.5f && jump == 1 || santa_kin_pos.y >= get_jump_old + 100.0f && jump == 2) {
						jump = 3;
					}
					else if (santa_kin_pos.y <= get_jump_old + 175.0f && jump == 1 || santa_kin_pos.y <= get_jump_old + 175.0f && jump == 2) {
						/*santa_kin_pos.y += 7.50;*/
						santa_kin_pos.y += jumpVelocity;
						//	 �d�͂𑬓x�ɓK�p
						jumpVelocity += gravity;
					}
					
				}
				if (jump == 3) {
					
					santa_kin_pos.y += jumpVelocity;
					//	 �d�͂𑬓x�ɓK�p
					jumpVelocity += gravity;
					if (collision.ground_santa(ground[1], santa_Kin[0], 50.0f, 0.0f) == true ||
						collision.ground_santa(ground[2], santa_Kin[0], 50.0f, 0.0f) == true ||
						collision.ground_santa(ground[3], santa_Kin[0], 50.0f, 0.0f) == true ||
						collision.ground_santa(ground[4], santa_Kin[0], 50.0f, 0.0f) == true ||
						collision.ground_santa(ground[5], santa_Kin[0], 50.0f, 0.0f) == true ||
						collision.block_santa(stairs[1], santa_Kin[0], 100.0f, 0.0f) == true ||
						collision.block_santa(stairs[2], santa_Kin[0], 100.0f, 0.0f) == true ||
						collision.block_santa(stairs[3], santa_Kin[0], 100.0f, 0.0f) == true ||
						collision.block_santa(stairs[4], santa_Kin[0], 100.0f, 0.0f) == true||
						collision.tree_santa(tree, santa_Kin[0], 1000.0f, 0.0f) == true)
					{

                        jump = 0;
						jumpVelocity = 0.0f;
					}
				}



				// �؂Ƃ̓����蔻��̒ǉ��@�S���C
				if (collision.tree_santa(tree, santa_Kin[0], 200.0f, 0.0f))
				{
					if (tree_Ground == 3) {
						if (santa_kin_pos.y >= tree_pos.y) {
							jumpVelocity = 0.0f;
						}
					}
					else {
						//// �T���^���؂̉E���ɂԂ������ꍇ
						if (santa_kin_pos.x < tree_pos.x)
						{

							collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~

						}
					}
					

				}
				// �T���^���؂̍����ɂԂ������ꍇ
				if (santa_kin_pos.x > tree_pos.x) {
					//	collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
					//	
					//	
					//}
					//// �T���^���؂̍����ɂԂ������ꍇ
					//if (santa_pos.x > tree_pos.x) {

					//	collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~

					//}
				}


				if (collision.tree_santa(invisiblewall[1], santa_Kin[0], 200.0f, 0.0f))
				{

					//// �T���^���؂̉E���ɂԂ������ꍇ
					if (santa_kin_pos.x < wall_pos1.x)
					{
						collision.canMoveRight = false; //�E�Ɉړ����Ȃ�ړ����~
					}

					// �T���^���؂̍����ɂԂ������ꍇ
					if (santa_kin_pos.x > wall_pos1.x)
					{
						collision.canMoveLeft = false; //�E�Ɉړ����Ȃ�ړ����~
					}
				}

				if (collision.tree_santa(invisiblewall[2], santa_Kin[0], 200.0f, 0.0f))
				{

					//// �T���^���؂̉E���ɂԂ������ꍇ
					if (santa_kin_pos.x < wall_pos2.x)
					{
						collision.canMoveRight = false; //�E�Ɉړ����Ȃ�ړ����~
					}

					// �T���^���؂̍����ɂԂ������ꍇ
					if (santa_kin_pos.x > wall_pos2.x)
					{
						collision.canMoveLeft = false; //�E�Ɉړ����Ȃ�ړ����~
					}

				}

				// 12/30  �T���^�̈ړ��A�j���[�V�����ǉ�  	�l��
				//�ړ����x
				speed = 5;

				// �ŗL�\�͔����I�I�I�I�I�I�I
				if (sp_ani == false && input.GetKeyPress(VK_Q)
					|| input.GetButtonTrigger(XINPUT_X) && sp_ani == false) { 

					if (bugPower > 0) { //  �܂ɒ��g������ꍇ

						if (direction == 0) { // �E����
							kintyaku_pos1.x = santa_kin_pos.x;
							kintyaku_pos1.y = santa_kin_pos.y - 25.0f;
							himo_pos.x = santa_kin_pos.x + 40;
							himo_pos.y = santa_kin_pos.y;
						}
						else if (direction == 1) { // ������
							kintyaku_pos1.x = santa_kin_pos.x;
							kintyaku_pos1.y = santa_kin_pos.y - 25.0f;
							himo_pos.x = santa_kin_pos.x - 40;
							himo_pos.y = santa_kin_pos.y;
						}

						sp_ani = true;
						kintyaku_go1 = true;

					}
					else if (bugPower == 0) { // �܂�����ۂ̎�

						if (direction == 0) { // �E����
							kintyaku_pos.x = santa_kin_pos.x;
							kintyaku_pos.y = santa_kin_pos.y - 25.0f;
							himo_pos.x = santa_kin_pos.x + 40;
							himo_pos.y = santa_kin_pos.y;
						}
						else if (direction == 1) { // ������
							kintyaku_pos.x = santa_kin_pos.x;
							kintyaku_pos.y = santa_kin_pos.y - 25.0f;
							himo_pos.x = santa_kin_pos.x - 40;
							himo_pos.y = santa_kin_pos.y;
						}

						sp_ani = true;
						kintyaku_go = true;


						
					}

					
				}
				
				//	�В��̃A�j���[�V�����֌W
				if (sp_ani == true) {

				
					if (direction == 0) // �����E�����Ȃ�
					{
						if (bugPower == 0) {
							kintyaku[0].numU = 0;
							kintyaku[0].numV = 0;
						}
						else if(bugPower > 0) {
							kintyaku[1].numU = 0;
							kintyaku[1].numV = 0;
						}
						
						if (changeRight_SP == true)
						{
							if (ani_stop == true) { // �����ŃA�j���[�V�������Œ肷��
								santa_Kin[6].numU = 2;
								santa_Kin[6].numV = 0;
								
							}
							else if (ani_stop == false) { // false�̏ꍇ�́A����������i�ŏ��͂����ɂ���j

								//������
								santaImage = 23;
								santa_Kin[6].numU = 0;
								santa_Kin[6].numV = 0;
								
							}

							changeRight_SP = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���
						}
						if (ani_stop == true) {

						}
						else if (ani_stop == false) {

							framcount7++; //�t���[���J�E���g
							if (framcount7 % 4 == 0) //�P�O�t���[���Ɉ��s����
							{
								santa_Kin[6].numU++;
								if (santa_Kin[6].numU >= 3)
								{
									changeRight_SP = true;
									ani_stop = true;

								}
							}
						}

					}
					else if (direction == 1) // ������
					{
						if (bugPower <= 0) {
							kintyaku[0].numU = 0;
							kintyaku[0].numV = 1;
						}
						else if (bugPower >= 0) {
							kintyaku[1].numU = 0;
							kintyaku[1].numV = 1;
						}

						if (changeLeft_SP == true)

							if (ani_stop == true) { // �����ŃA�j���[�V�������Œ肷��
								santa_Kin[6].numU = 2;
								santa_Kin[6].numV = 1;

							}
							else if (ani_stop == false) {
								//������
								santaImage = 23;
								santa_Kin[6].numU = 0;
								santa_Kin[6].numV = 1;
							}
							changeLeft_SP = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���

							if (ani_stop == true) {

							}
							else if (ani_stop == false) {
								framcount7++; //�t���[���J�E���g
								if (framcount7 % 4 == 0) //�P�O�t���[���Ɉ��s����
								{
									santa_Kin[6].numU++;
									if (santa_Kin[6].numU >= 3)
									{

										changeLeft_SP = true;
										ani_stop = true;

									}
								}
							}
					}

				}

				// �В��܂̈ړ� (���g�Ȃ�)
				if (kintyaku_go == true) {

					if (direction == 0) { // �E����

						if (kintyaku_Fg == true) { // �܂������̂Ƃ��ɖ߂鏈��

							get_Kintyaku -= 15.0f;
							kintyaku_pos.x -= 15.0f;

							himo_pos.x -= 6.5f;
							himo_size.x -= 13.0f;
						}
						else {                     // �܂��΂�����
							get_Kintyaku += 15.0f;
							kintyaku_pos.x += 15.0f;

							himo_pos.x += 6.5f;
							himo_size.x += 13.0f;
						}

						if (collision.square_square(kintyaku[0], tree) == true && tree_Ground==1) {
							tree_Ground = 2;
						}

						if (get_Kintyaku >= 300.0f && kintyaku_Fg==false) { // �܂��ő勗���܂ňړ������ꍇ
							kintyaku_Fg = true;
						}
						else if (get_Kintyaku <= 0.0f && kintyaku_Fg == true) { // �܂������̌��ɖ߂������̏���
							changeRight_SP = true;
							santaImage = 17;
							santa_Kin[6].numU = 0;
							sp_ani = false;
							kintyaku_go = false;
							ani_stop = false;
							himo_size.x = 10.0f;

							get_Kintyaku = 0.0f;
							kintyaku_Fg = false;
						}
					}
				else if (direction == 1) { // �E����

						if (kintyaku_Fg== true) { // �܂������̂Ƃ��ɖ߂鏈��

							get_Kintyaku += 15.0f;
							kintyaku_pos.x += 15.0f;

							himo_pos.x += 6.5f;
							himo_size.x += -13.0f;
						}
						else {                     // �܂��΂�����
							get_Kintyaku -= 15.0f;
							kintyaku_pos.x += -15.0f;

							himo_pos.x -= 6.5f;
							himo_size.x += 13.0f;
						}

						if (get_Kintyaku <= -300.0f && kintyaku_Fg == false) { // �܂��ő勗���܂ňړ������ꍇ
							kintyaku_Fg = true;
						}
						else if (get_Kintyaku >= 0.0f && kintyaku_Fg == true) { // �܂������̌��ɖ߂������̏���
							changeLeft_SP = true;
							santaImage = 17;
							santa_Kin[6].numU = 0;
							sp_ani = false;
							kintyaku_go = false;
							ani_stop = false;
							himo_size.x = 10.0f;

							get_Kintyaku = 0.0f;
							kintyaku_Fg = false;
						}
					}
					
				}

				// �В��܂̈ړ� (���g����j
				if (kintyaku_go1 == true) {

					if (direction == 0) { // �E����

						if (kintyaku_Fg == true) { // �܂������̂Ƃ��ɖ߂鏈��

							get_Kintyaku -= 15.0f;
							kintyaku_pos1.x -= 15.0f;

							himo_pos.x -= 6.5f;
							himo_size.x -= 13.0f;
						}
						else {                     // �܂��΂�����
							get_Kintyaku += 15.0f;
							kintyaku_pos1.x += 15.0f;

							himo_pos.x += 6.5f;
							himo_size.x += 13.0f;
						}

						if (get_Kintyaku >= 300.0f && kintyaku_Fg == false) { // �܂��ő勗���܂ňړ������ꍇ
							kintyaku_Fg = true;
						}
						else if (get_Kintyaku <= 0.0f && kintyaku_Fg == true) { // �܂������̌��ɖ߂������̏���
							changeRight_SP = true;
							santaImage = 17;
							santa_Kin[6].numU = 0;
							sp_ani = false;
							kintyaku_go1 = false;
							ani_stop = false;
							himo_size.x = 10.0f;

							get_Kintyaku = 0.0f;
							kintyaku_Fg = false;
						}
					}
					else if (direction == 1) { // �E����

						if (kintyaku_Fg == true) { // �܂������̂Ƃ��ɖ߂鏈��

							get_Kintyaku += 15.0f;
							kintyaku_pos1.x += 15.0f;

							himo_pos.x += 6.5f;
							himo_size.x += -13.0f;
						}
						else {                     // �܂��΂�����
							get_Kintyaku -= 15.0f;
							kintyaku_pos1.x += -15.0f;

							himo_pos.x -= 6.5f;
							himo_size.x += 13.0f;
						}

						if (get_Kintyaku <= -300.0f && kintyaku_Fg == false) { // �܂��ő勗���܂ňړ������ꍇ
							kintyaku_Fg = true;
						}
						else if (get_Kintyaku >= 0.0f && kintyaku_Fg == true) { // �܂������̌��ɖ߂������̏���
							changeLeft_SP = true;
							santaImage = 17;
							santa_Kin[6].numU = 0;
							sp_ani = false;
							kintyaku_go1 = false;
							ani_stop = false;
							himo_size.x = 10.0f;

							get_Kintyaku = 0.0f;
							kintyaku_Fg = false;
						}
					}

				}

				// �В��܂ƓG�̓����蔻��
				if (kintyaku_go1 == true && kintyaku_Fg == false) {
					if (collision.square_square(snowman[1], kintyaku[1]) == true) {
						sound.Play(SOUND_LABEL_SE004);
						snowman_hp1 -= santa_atk;

						particleFg = true;
						particlepos.x = snowman_pos1.x;
						particlepos.y = snowman_pos1.y;

						if (snowman_hp1 < 0)
						{
							enemylive1 = false;
							snowman_hp1 = 20;
							snowman_pos1.x = 400000000;
						}
					}

					if (collision.square_square(snowman[2], kintyaku[1]) == true) {
						snowman_hp2 -= santa_atk;
								sound.Play(SOUND_LABEL_SE004);
								particleFg = true;
								particlepos.x = snowman_pos2.x;
								particlepos.y = snowman_pos2.y;
								if (snowman_hp2 < 0)
								{

									enemylive2 = false;
									snowman_hp2 = 20;
									snowman_pos2.x = 400000000;
								}
					}

					if (collision.square_square(snowman[3], kintyaku[1]) == true) {
						snowman_hp3 -= santa_atk;
						sound.Play(SOUND_LABEL_SE004);
						particleFg = true;
						particlepos.x = snowman_pos3.x;
						particlepos.y = snowman_pos3.y;
						if (snowman_hp3 < 0)
						{

							enemylive3 = false;
							snowman_hp3 = 20;
							snowman_pos3.x = 400000000;
						}
					}

					if (collision.square_square(star_monster, kintyaku[1]) == true) {
						star_monster_hp1 -= santa_atk;
								sound.Play(SOUND_LABEL_SE004);
								particleFg = true;
								particlepos.x = star_monster_pos.x;
								particlepos.y = star_monster_pos.y;
								if (star_monster_hp1 < 0)
								{
									enemylive4 = false;
									star_monster_hp1 = 40;
									star_monster_pos.x = 400000000;
								}
					}

					if (collision.square_square(tonakai, kintyaku[1]) == true) {
								tonakai_hp -= santa_atk;
						sound.Play(SOUND_LABEL_SE004);
						particleFg = true;
						particlepos.x = tonakai_pos.x;
						particlepos.y = tonakai_pos.y;
						if (tonakai_hp < 0)
						{
							enemylive5 = false;
							tonakai_hp = 60;
							tonakai_pos.x = 400000000;
						}
					}

				}
				
				//�p�[�e�B�N���A�j���[�V����
				if (particleFg)
				{
					particlecount++;
					if (particlecount % 5 == 0)
					{
						//particleFg = false;
						particle.numU++;
						if (particle.numU > 7)
						{
							particle.numU = 0;
							particleFg = false;
						}
					}

				}




				//�@�В��܂Ɩ؂̓����蔻��
				if (collision.square_square(kintyaku[0], tree)==true ) {
					if (tree_Ground == 2 && tree_Fg==false) {
						tree_x = tree_pos.x;
						tree_y = tree_pos.y;
						
						tree_Fg = true;
					}
					
					if (tree_Fg == true) {
						tree_angle = 80.0f;
						tree_pos.y = tree_y + (-130.0f);
						tree_pos.x = tree_x + (-170.0f);
						sound.Play(SOUND_kintyaku);
						tree_Fg = false;
					}
					if (tree_angle == 80.0f) {
						tree_Ground = 3;
						/*tree_pos.y = tree_x + 10;*/

					}
				}



				// �E�ړ�
				if (sp_ani == false && gameoverFg == false && collision.canMoveRight && input.GetKeyPress(VK_D) && pauseFg == false
					|| gameoverFg == false && collision.canMoveRight && input.GetLeftAnalogStick().x >= 0.1 && pauseFg == false)
				{
					direction = 0; // ����
					santa_kin_pos.x += 5;//�E�ړ�
					/*santa_kin_pos.x += 5;
					santa_pos.x += 5;*/


					if (bugPower == 0) {
						santaImage = 17;
						if (changeRight_SP_1 == true)
						{
							//������
							santa_Kin[0].numU = 0;
							santa_Kin[0].numV = 0;
							changeRight_SP_1 = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���
						}
						framcount6++; //�t���[���J�E���g
						if (framcount6 % 10 == 0) //�P�O�t���[���Ɉ��s����
						{
							santa_Kin[0].numU++;
							if (santa_Kin[0].numU >= 4)
							{
								santa_Kin[0].numU = 0;
								santa_Kin[0].numV++;
								if (santa_Kin[0].numV >= 2)
								{
									santa_Kin[0].numV = 0;
								}
							}
						}

					}
					else if (bugPower > 0) {
						santaImage = 18;
						if (changeRight == true)
						{
							//������
							santa_Kin[1].numU = 0;
							santa_Kin[1].numV = 0;
							changeRight = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���
						}
						framcount++; //�t���[���J�E���g
						if (framcount % 10 == 0) //�P�O�t���[���Ɉ��s����
						{
							santa_Kin[1].numU++;
							if (santa_Kin[1].numU >= 4)
							{
								santa_Kin[1].numU = 0;
								santa_Kin[1].numV++;
								if (santa_Kin[1].numV >= 2)
								{
									santa_Kin[1].numV = 0;
								}
							}
						}

					}

					if (santa_kin_pos.x >= 0) //�v���C���[����ʐ^�񒆂ɍs�����Ƃ�
					{
						santa_kin_pos.x -= 5;

						//�w�i�Ȃǂ����ɓ������ăv���C���[���E�ɓ����Ă�悤�Ɍ�����
						//�R
						mounten_pos1.x -= speed - 4.5;
						mounten_pos2.x -= speed - 4.5;
						mounten_pos3.x -= speed - 4.5;
						//�w�i�̖�
						wood_pos1.x -= speed - 2;
						wood_pos2.x -= speed - 2;
						wood_pos3.x -= speed - 2;
						//�E�����
						rock_pos1.x -= speed;
						rock_pos2.x -= speed;
						rock_pos3.x -= speed;
						rock_pos4.x -= speed;
						rock_pos5.x -= speed;
						rock_pos6.x -= speed;
						//�n��
						ground_pos1.x -= speed;
						ground_pos2.x -= speed;
						ground_pos3.x -= speed;
						ground_pos4.x -= speed;
						ground_pos5.x -= speed;
						//�K�i
						stairs_pos1.x -= speed;
						stairs_pos2.x -= speed;
						stairs_pos3.x -= speed;
						stairs_pos4.x -= speed;
						//�Ⴞ���
						snowman_pos1.x -= speed;
						snowman_pos2.x -= speed;
						snowman_pos3.x -= speed;
						//���
						snowball_pos1.x -= speed;
						snowball_pos2.x -= speed;
						snowball_pos3.x -= speed;
						//���̂Ă�
						star_monster_pos.x -= speed;
						//�g�i�J�C
						tonakai_pos.x -= speed;
						//�v���[���g
						present_pos1.x -= speed;
						present_pos2.x -= speed;
						present_pos3.x -= speed;
						//�傫���v���[���g
						bigpresent_pos1.x -= speed;
						//��
						tree_pos.x -= speed;
						//�S�[��
						goal_pos.x -= speed;

						wall_pos1.x -= speed;
						wall_pos2.x -= speed;

						//�����A�C�e��
						use_rock_pos1.x -= speed;
						use_rock_pos2.x -= speed;
						use_rock_pos3.x -= speed;
						use_snowball_pos1.x -= speed;
						use_snowball_pos2.x -= speed;
						use_snowball_pos3.x -= speed;

					}
				}
				else
				{
					//�L�[�𗣂���true�ɖ߂�
					if (sp_ani == false && changeRight_SP_1 == false) {

						santa_Kin[0].numU = 0;
						santa_Kin[0].numV = 0;
						santa_Kin[1].numU = 0;
						santa_Kin[1].numV = 0;
						if (bugPower > 0) {
							santaImage = 18;
						}
						else if (bugPower == 0) {
							santaImage = 17;
						}

					}

					changeRight = true;
					changeRight_SP_1 = true;
				}

				// ���ړ�
				if (sp_ani == false && gameoverFg == false && collision.canMoveLeft && input.GetKeyPress(VK_A) && pauseFg == false
					|| gameoverFg == false && collision.canMoveLeft && input.GetLeftAnalogStick().x <= -0.1 && pauseFg == false)
				{
					direction = 1; // ����
					santa_kin_pos.x -= 5;//���ړ�
					//santa_huro_pos.x -= 5;//���ړ�
					//santa_pos.x -= 5;//���ړ�


					if (bugPower == 0) {

						santaImage = 17;
						if (changeLeft_SP_1 == true)
						{
							//������
							santa_Kin[0].numU = 0;
							santa_Kin[0].numV = 2;
							changeLeft_SP_1 = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���
						}
						framcount6++; //�t���[���J�E���g
						if (framcount6 % 10 == 0) //�P�O�t���[���Ɉ��s����
						{
							santa_Kin[0].numU++;
							if (santa_Kin[0].numU >= 4)
							{

								santa_Kin[0].numU = 0;

							}
						}
					}
					else if (bugPower > 0) {

						if (changeLeft == true)
						{
							//������
							santa_Kin[1].numU = 0;
							santa_Kin[1].numV = 2;
							changeLeft = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���
						}
						framcount++; //�t���[���J�E���g
						if (framcount % 10 == 0) //�P�O�t���[���Ɉ��s����
						{
							santa_Kin[1].numU++;
							if (santa_Kin[1].numU >= 4)
							{
								santa_Kin[1].numU = 0;
								santa_Kin[1].numV++;
								if (santa_Kin[1].numV >= 4)
								{
									santa_Kin[1].numV = 2;
								}
							}
						}
					}



					if (santa_kin_pos.x <= 0) //�v���C���[����ʐ^�񒆂ɍs�����Ƃ�
					{
						santa_kin_pos.x += 5;



						//�w�i�Ȃǂ����ɓ������ăv���C���[���E�ɓ����Ă�悤�Ɍ�����
						//�R
						mounten_pos1.x += speed - 4.5;
						mounten_pos2.x += speed - 4.5;
						mounten_pos3.x += speed - 4.5;
						//�w�i�̖�
						wood_pos1.x += speed - 2;
						wood_pos2.x += speed - 2;
						wood_pos3.x += speed - 2;
						//�E�����
						rock_pos1.x += speed;
						rock_pos2.x += speed;
						rock_pos3.x += speed;
						rock_pos4.x += speed;
						rock_pos5.x += speed;
						rock_pos6.x += speed;
						//�n��
						ground_pos1.x += speed;
						ground_pos2.x += speed;
						ground_pos3.x += speed;
						ground_pos4.x += speed;
						ground_pos5.x += speed;
						//�K�i
						stairs_pos1.x += speed;
						stairs_pos2.x += speed;
						stairs_pos3.x += speed;
						stairs_pos4.x += speed;
						//�Ⴞ���
						snowman_pos1.x += speed;
						snowman_pos2.x += speed;
						snowman_pos3.x += speed;
						//���
						snowball_pos1.x += speed;
						snowball_pos2.x += speed;
						snowball_pos3.x += speed;
						//���̂Ă�
						star_monster_pos.x += speed;
						//�g�i�J�C
						tonakai_pos.x += speed;
						//�v���[���g
						present_pos1.x += speed;
						present_pos2.x += speed;
						present_pos3.x += speed;
						//�傫���v���[���g
						bigpresent_pos1.x += speed;
						//��
						tree_pos.x += speed;
						//�S�[��
						goal_pos.x += speed;

						wall_pos1.x += speed;
						wall_pos2.x += speed;

						//�����A�C�e��
						use_rock_pos1.x += speed;
						use_rock_pos2.x += speed;
						use_rock_pos3.x += speed;
						use_snowball_pos1.x += speed;
						use_snowball_pos2.x += speed;
						use_snowball_pos3.x += speed;
					}
				}
				else
				{
					//�L�[�𗣂���true�ɖ߂�
					if (sp_ani == false && changeLeft_SP_1 == false) {
						santa_Kin[0].numU = 0;
						santa_Kin[0].numV = 2;
						santa_Kin[1].numU = 0;
						santa_Kin[1].numV = 2;
						if (bugPower > 0) {
							santaImage = 18;
						}
						else if (bugPower == 0) {
							santaImage = 17;
						}
					}
					changeLeft = true;
					changeLeft_SP_1 = true;
				}
			


		}

		

		//�摜����ʊO�ɍs�����Ƃ��ɂ��̉摜����Ԍ��ɒu��
			//��@�摜�P����ʊO���摜�R�̌��� 
			//�R�̃X�N���[���@1280=��ʃT�C�Y
		if (mounten_pos1.x <= -1280 * 2)
		{
			mounten_pos1.x = mounten_pos3.x + SCREEN_WIDTH;

		}

		if (mounten_pos2.x <= -1280 * 2)
		{
			mounten_pos2.x = mounten_pos1.x + SCREEN_WIDTH;

		}

		if (mounten_pos3.x <= -1280 * 2)
		{
			mounten_pos3.x = mounten_pos2.x + SCREEN_WIDTH;

		}

		//�؂̃X�N���[��
		if (wood_pos1.x <= -1280 * 2)
		{
			wood_pos1.x = wood_pos3.x + SCREEN_WIDTH;

		}

		if (wood_pos2.x <= -1280 * 2)
		{
			wood_pos2.x = wood_pos1.x + SCREEN_WIDTH;

		}

		if (wood_pos3.x <= -1280 * 2)
		{
			wood_pos3.x = wood_pos2.x + SCREEN_WIDTH;

		}




		santa_Nor[0].SetPos(santa_pos.x, santa_pos.y, santa_pos.z);
		santa_Nor[1].SetPos(santa_pos1.x, santa_pos1.y, santa_pos1.z);
		santa_Nor[2].SetPos(santa_pos2.x, santa_pos2.y, santa_pos2.z);
		santa_Nor[3].SetPos(santa_pos3.x, santa_pos3.y, santa_pos3.z);
		santa_Nor[4].SetPos(santa_pos4.x, santa_pos4.y, santa_pos4.z);
		santa_Nor[5].SetPos(santa_pos5.x, santa_pos5.y, santa_pos5.z);
		santa_Nor[6].SetPos(santa_pos6.x, santa_pos6.y, santa_pos6.z);
		santa_Nor[7].SetPos(santa_pos7.x, santa_pos7.y, santa_pos7.z);
		santa_Huro[0].SetPos(santa_huro_pos.x, santa_huro_pos.y, santa_huro_pos.z);
		santa_Huro[1].SetPos(santa_huro_pos1.x, santa_huro_pos1.y, santa_huro_pos1.z);
		santa_Huro[2].SetPos(santa_huro_pos2.x, santa_huro_pos2.y, santa_huro_pos2.z);
		santa_Huro[3].SetPos(santa_huro_pos3.x, santa_huro_pos3.y, santa_huro_pos3.z);
		santa_Huro[4].SetPos(santa_huro_pos4.x, santa_huro_pos4.y, santa_huro_pos4.z);
		santa_Huro[5].SetPos(santa_huro_pos5.x, santa_huro_pos5.y, santa_huro_pos5.z);
		santa_Huro[6].SetPos(santa_huro_pos6.x, santa_huro_pos6.y, santa_huro_pos6.z);
		santa_Huro[7].SetPos(santa_huro_pos7.x, santa_huro_pos7.y, santa_huro_pos7.z);
		santa_Kin[0].SetPos(santa_kin_pos.x, santa_kin_pos.y, santa_kin_pos.z);
		santa_Kin[1].SetPos(santa_kin_pos1.x, santa_kin_pos1.y, santa_kin_pos1.z);
		santa_Kin[2].SetPos(santa_kin_pos2.x, santa_kin_pos2.y, santa_kin_pos2.z);
		santa_Kin[3].SetPos(santa_kin_pos3.x, santa_kin_pos3.y, santa_kin_pos3.z);
		santa_Kin[4].SetPos(santa_kin_pos4.x, santa_kin_pos4.y, santa_kin_pos4.z);
		santa_Kin[5].SetPos(santa_kin_pos5.x, santa_kin_pos5.y, santa_kin_pos5.z);
		santa_Kin[6].SetPos(santa_kin_pos6.x, santa_kin_pos6.y, santa_kin_pos6.z);

		kintyaku[0].SetPos(kintyaku_pos.x, kintyaku_pos.y, kintyaku_pos.z);
		kintyaku[1].SetPos(kintyaku_pos1.x, kintyaku_pos1.y, kintyaku_pos1.z);

		himo.SetPos(himo_pos.x, himo_pos.y, himo_pos.z);
		himo.SetSize(himo_size.x, himo_size.y, himo_size.z);

		goal.SetPos(goal_pos.x, goal_pos.y, goal_pos.z);

		mounten[1].SetPos(mounten_pos1.x, mounten_pos1.y, mounten_pos1.z);
		mounten[2].SetPos(mounten_pos2.x, mounten_pos2.y, mounten_pos2.z);
		mounten[3].SetPos(mounten_pos3.x, mounten_pos3.y, mounten_pos3.z);

		wood[1].SetPos(wood_pos1.x, wood_pos1.y, wood_pos1.z);
		wood[2].SetPos(wood_pos2.x, wood_pos2.y, wood_pos2.z);
		wood[3].SetPos(wood_pos3.x, wood_pos3.y, wood_pos3.z);

		rock[1].SetPos(rock_pos1.x, rock_pos1.y, rock_pos1.z);
		rock[2].SetPos(rock_pos2.x, rock_pos2.y, rock_pos2.z);
		rock[3].SetPos(rock_pos3.x, rock_pos3.y, rock_pos3.z);
		rock[4].SetPos(rock_pos4.x, rock_pos4.y, rock_pos4.z);
		rock[5].SetPos(rock_pos5.x, rock_pos5.y, rock_pos5.z);
		rock[6].SetPos(rock_pos6.x, rock_pos6.y, rock_pos6.z);

		snowball[1].SetPos(snowball_pos1.x, snowball_pos1.y, snowball_pos1.z);
		snowball[2].SetPos(snowball_pos2.x, snowball_pos2.y, snowball_pos2.z);
		snowball[3].SetPos(snowball_pos3.x, snowball_pos3.y, snowball_pos3.z);

		stairs[1].SetPos(stairs_pos1.x, stairs_pos1.y, stairs_pos1.z);
		stairs[2].SetPos(stairs_pos2.x, stairs_pos2.y, stairs_pos2.z);
		stairs[3].SetPos(stairs_pos3.x, stairs_pos3.y, stairs_pos3.z);
		stairs[4].SetPos(stairs_pos4.x, stairs_pos4.y, stairs_pos4.z);

		snowman[1].SetPos(snowman_pos1.x, snowman_pos1.y, snowman_pos1.z);
		snowman[2].SetPos(snowman_pos2.x, snowman_pos2.y, snowman_pos2.z);
		snowman[3].SetPos(snowman_pos3.x, snowman_pos3.y, snowman_pos3.z);

		present[1].SetPos(present_pos1.x, present_pos1.y, present_pos1.z);
		present[2].SetPos(present_pos2.x, present_pos2.y, present_pos2.z);
		present[3].SetPos(present_pos3.x, present_pos3.y, present_pos3.z);

		BigPresent[1].SetPos(bigpresent_pos1.x, bigpresent_pos1.y, bigpresent_pos1.z);

		tree.SetPos(tree_pos.x, tree_pos.y, tree_pos.z);
		tree.SetAngle(tree_angle);

		star_monster.SetPos(star_monster_pos.x, star_monster_pos.y, star_monster_pos.z);
		tonakai.SetPos(tonakai_pos.x, tonakai_pos.y, tonakai_pos.z);

		ground[1].SetPos(ground_pos1.x, ground_pos1.y, ground_pos1.z);
		ground[2].SetPos(ground_pos2.x, ground_pos2.y, ground_pos2.z);
		ground[3].SetPos(ground_pos3.x, ground_pos3.y, ground_pos3.z);

		ground[4].SetPos(ground_pos4.x, ground_pos4.y, ground_pos4.z);
		ground[5].SetPos(ground_pos5.x, ground_pos5.y, ground_pos5.z);

		use_rock[0].SetPos(use_rock_pos1.x, use_rock_pos1.y, use_rock_pos1.z);
		use_rock[1].SetPos(use_rock_pos2.x, use_rock_pos2.y, use_rock_pos2.z);
		use_rock[2].SetPos(use_rock_pos3.x, use_rock_pos3.y, use_rock_pos3.z);

		use_snowball[0].SetPos(use_snowball_pos1.x, use_snowball_pos1.y, use_snowball_pos1.z);
		use_snowball[1].SetPos(use_snowball_pos2.x, use_snowball_pos2.y, use_snowball_pos2.z);
		use_snowball[2].SetPos(use_snowball_pos3.x, use_snowball_pos3.y, use_snowball_pos3.z);

		Cursor.SetPos(cursor_pos.x, cursor_pos.y, cursor_pos.z);
		PauseCursor.SetPos(cursor1_pos.x, cursor1_pos.y, cursor1_pos.z);


		invisiblewall[1].SetPos(wall_pos1.x, wall_pos1.y, wall_pos1.z);
		invisiblewall[2].SetPos(wall_pos2.x, wall_pos2.y, wall_pos2.z);

		hitbox.SetPos(hitboxpos.x, hitboxpos.y, hitboxpos.z);
		particle.SetPos(particlepos.x, particlepos.y, particlepos.z);

		snowman[1].SetHP(snowman_hp1);
		snowman[2].SetHP(snowman_hp2);
		snowman[3].SetHP(snowman_hp3);
		star_monster.SetHP(star_monster_hp1);
		tonakai.SetHP(tonakai_hp);


		santa_Nor[7].SetATK(santa_atk);
	}
	break;

	case STAGE_2:
	{
		//�T���^ �ʏ��
		DirectX::XMFLOAT3 santa_pos = santa_Nor[0].GetPos();
		DirectX::XMFLOAT3 santa_pos1 = santa_Nor[1].GetPos();
		DirectX::XMFLOAT3 santa_pos2 = santa_Nor[2].GetPos();
		DirectX::XMFLOAT3 santa_pos3 = santa_Nor[3].GetPos();
		DirectX::XMFLOAT3 santa_pos4 = santa_Nor[4].GetPos();
		DirectX::XMFLOAT3 santa_pos5 = santa_Nor[5].GetPos();
		DirectX::XMFLOAT3 santa_pos6 = santa_Nor[6].GetPos();
		DirectX::XMFLOAT3 santa_pos7 = santa_Nor[7].GetPos();
		//�T���^ ���C�~
		DirectX::XMFLOAT3 santa_huro_pos = santa_Huro[0].GetPos();
		DirectX::XMFLOAT3 santa_huro_pos1 = santa_Huro[1].GetPos();
		DirectX::XMFLOAT3 santa_huro_pos2 = santa_Huro[2].GetPos();
		DirectX::XMFLOAT3 santa_huro_pos3 = santa_Huro[3].GetPos();
		DirectX::XMFLOAT3 santa_huro_pos4 = santa_Huro[4].GetPos();
		DirectX::XMFLOAT3 santa_huro_pos5 = santa_Huro[5].GetPos();
		DirectX::XMFLOAT3 santa_huro_pos6 = santa_Huro[6].GetPos();
		DirectX::XMFLOAT3 santa_huro_pos7 = santa_Huro[7].GetPos();
		//�T���^ �В���
		DirectX::XMFLOAT3 santa_kin_pos = santa_Kin[0].GetPos();
		DirectX::XMFLOAT3 santa_kin_pos1 = santa_Kin[1].GetPos();
		DirectX::XMFLOAT3 santa_kin_pos2 = santa_Kin[2].GetPos();
		DirectX::XMFLOAT3 santa_kin_pos3 = santa_Kin[3].GetPos();
		DirectX::XMFLOAT3 santa_kin_pos4 = santa_Kin[4].GetPos();
		DirectX::XMFLOAT3 santa_kin_pos5 = santa_Kin[5].GetPos();
		DirectX::XMFLOAT3 santa_kin_pos6 = santa_Kin[6].GetPos();
		//�В���
		DirectX::XMFLOAT3 kintyaku_pos = kintyaku[0].GetPos();
		DirectX::XMFLOAT3 kintyaku_pos1 = kintyaku[1].GetPos();
		DirectX::XMFLOAT3 himo_pos = himo.GetPos();
		DirectX::XMFLOAT3 himo_size = himo.GetSize();

		//�U���̓����蔻��
		DirectX::XMFLOAT3 hitboxpos = hitbox2.GetPos();

		int snowman_hp1 = Snowman_Stage2[1].GetHP();          //��̓G
		int snowman_hp2 = Snowman_Stage2[2].GetHP();		   //��̓G
		int snowman_hp3 = Snowman_Stage2[3].GetHP();		   //��̓G
		int snowman_hp4 = Snowman_Stage2[4].GetHP();		   //��̓G

		int  star_monster_hp1 = Star_Stage2[1].GetHP();          //�ق��̓G
		int  star_monster_hp2 = Star_Stage2[2].GetHP();          //�ق��̓G
		int tonakai_hp1 = Tonakai_Stage2[1].GetHP();	                   //�g�i�J�C�̓G
		int tonakai_hp2 = Tonakai_Stage2[2].GetHP();	                   //�g�i�J�C�̓G
		int santa_atk = santa_Nor[7].GetATK();

		DirectX::XMFLOAT3 tree_pos = tree.GetPos();
		float tree_angle = tree.GetAngle();

		//�R
		DirectX::XMFLOAT3 mounten_pos1 = mounten[1].GetPos();
		DirectX::XMFLOAT3 mounten_pos2 = mounten[2].GetPos();
		DirectX::XMFLOAT3 mounten_pos3 = mounten[3].GetPos();
		DirectX::XMFLOAT3 mounten_pos4 = mounten[4].GetPos();

		//�n��
		DirectX::XMFLOAT3 ground_pos1 = Ground_Stge2[1].GetPos();
		DirectX::XMFLOAT3 ground_pos2 = Ground_Stge2[2].GetPos();
		DirectX::XMFLOAT3 ground_pos3 = Ground_Stge2[3].GetPos();
		DirectX::XMFLOAT3 ground_pos4 = Ground_Stge2[4].GetPos();
		DirectX::XMFLOAT3 ground_pos5 = Ground_Stge2[5].GetPos();
		DirectX::XMFLOAT3 ground_pos6 = Ground_Stge2[6].GetPos();
		DirectX::XMFLOAT3 ground_pos7 = Ground_Stge2[7].GetPos();
		//���
		DirectX::XMFLOAT3 icicle_pos1 = Icicles_Stge2[1].GetPos();
		DirectX::XMFLOAT3 icicle_pos2 = Icicles_Stge2[2].GetPos();
		DirectX::XMFLOAT3 icicle_pos3 = Icicles_Stge2[3].GetPos();
		//�K�i
		DirectX::XMFLOAT3 stairs_pos1 = Stairs_Stge2[1].GetPos();
		DirectX::XMFLOAT3 stairs_pos2 = Stairs_Stge2[2].GetPos();
		DirectX::XMFLOAT3 stairs_pos3 = Stairs_Stge2[3].GetPos();
		DirectX::XMFLOAT3 stairs_pos4 = Stairs_Stge2[4].GetPos();
		DirectX::XMFLOAT3 stairs_pos5 = Stairs_Stge2[5].GetPos();
		//��
		DirectX::XMFLOAT3 tree_pos1 = Tree_Stge2[1].GetPos();
		DirectX::XMFLOAT3 tree_pos2 = Tree_Stge2[2].GetPos();
		//���̏�
		DirectX::XMFLOAT3 block_pos1 = Block_Stge2[1].GetPos();
		//�v���[���g
		DirectX::XMFLOAT3 present_pos1 = Present_Stage2[1].GetPos();
		DirectX::XMFLOAT3 present_pos2 = Present_Stage2[2].GetPos();
		DirectX::XMFLOAT3 present_pos3 = Present_Stage2[3].GetPos();
		DirectX::XMFLOAT3 bigpresent_pos1 = BigPresent_Stage2[1].GetPos();
		//�E�����
		DirectX::XMFLOAT3 rock_pos1 = Collectrock_Stage2[1].GetPos();
		DirectX::XMFLOAT3 rock_pos2 = Collectrock_Stage2[2].GetPos();
		DirectX::XMFLOAT3 rock_pos3 = Collectrock_Stage2[3].GetPos();
		DirectX::XMFLOAT3 rock_pos4 = Collectrock_Stage2[4].GetPos();
		DirectX::XMFLOAT3 rock_pos5 = Collectrock_Stage2[5].GetPos();
		DirectX::XMFLOAT3 rock_pos6 = Collectrock_Stage2[6].GetPos();
		//���
		DirectX::XMFLOAT3 snowball_pos1 = Snowball_Stage2[1].GetPos();
		DirectX::XMFLOAT3 snowball_pos2 = Snowball_Stage2[2].GetPos();
		DirectX::XMFLOAT3 snowball_pos3 = Snowball_Stage2[3].GetPos();
		//�󂹂��
		DirectX::XMFLOAT3 breakrock_pos1 = Breakrock_Stge2[1].GetPos();

		//�G
		DirectX::XMFLOAT3 snowman_pos1 = Snowman_Stage2[1].GetPos();
		DirectX::XMFLOAT3 snowman_pos2 = Snowman_Stage2[2].GetPos();
		DirectX::XMFLOAT3 snowman_pos3 = Snowman_Stage2[3].GetPos();
		DirectX::XMFLOAT3 snowman_pos4 = Snowman_Stage2[4].GetPos();

		DirectX::XMFLOAT3 star_pos1 = Star_Stage2[1].GetPos();
		DirectX::XMFLOAT3 star_pos2 = Star_Stage2[2].GetPos();

		DirectX::XMFLOAT3 tonakai_pos1 = Tonakai_Stage2[1].GetPos();
		DirectX::XMFLOAT3 tonakai_pos2 = Tonakai_Stage2[2].GetPos();

		//�������@����
		DirectX::XMFLOAT3 use_rock_pos1 = use_rock[0].GetPos();
		DirectX::XMFLOAT3 use_rock_pos2 = use_rock[1].GetPos();
		DirectX::XMFLOAT3 use_rock_pos3 = use_rock[2].GetPos();

		//�������@���
		DirectX::XMFLOAT3 use_snowball_pos1 = use_snowball[0].GetPos();
		DirectX::XMFLOAT3 use_snowball_pos2 = use_snowball[1].GetPos();
		DirectX::XMFLOAT3 use_snowball_pos3 = use_snowball[2].GetPos();


		DirectX::XMFLOAT3 cursor_pos = Cursor.GetPos();
		DirectX::XMFLOAT3 cursor1_pos = PauseCursor.GetPos();
		DirectX::XMFLOAT3 goal_pos = Goal_Stage2.GetPos();
		DirectX::XMFLOAT3 moji_pos = Breakmoji.GetPos();

		DirectX::XMFLOAT3 wall_pos1 = invisiblewall[3].GetPos();
		DirectX::XMFLOAT3 wall_pos2 = invisiblewall[4].GetPos();

		DirectX::XMFLOAT3 particlepos = particle.GetPos();
		
		if (direction == 0)
		{
			hitboxpos.x = santa_pos.x + 60;
			hitboxpos.y = santa_pos.y;
		}
		if (direction == 1)
		{
			hitboxpos.x = santa_pos.x - 60;
			hitboxpos.y = santa_pos.y;
		}

		if (icicle_pos1.x <= 0 && santa_pos.y < 0)
		{
			turarafall1 = true;
		}


		if (icicle_pos2.x <= 0 && santa_pos.y < 0)
		{
			turarafall2 = true;
		}


		if (icicle_pos3.x <= 0 && santa_pos.y < 0)
		{
			turarafall3 = true;
		}

		if (turarafall1 == true)
		{
			icicle_pos1.y -= 6;
			if (icicle_pos1.y <= -800)
			{
				turarafall1 = false;
			}
		}

		if (turarafall2 == true)
		{
			icicle_pos2.y -= 6;
			if (icicle_pos2.y <= -800)
			{
				turarafall2 = false;
			}
		}

		if (turarafall3 == true)
		{
			icicle_pos3.y -= 6;
			if (icicle_pos3.y <= -800)
			{
				turarafall3 = false;
			}
		}
		
		framcount2++;
		if (framcount2 % 10 == 0) //�P�O�t���[���Ɉ��s����
		{
			Snowman_Stage2[1].numU++;
			Snowman_Stage2[2].numU++;
			Snowman_Stage2[3].numU++;
			Snowman_Stage2[4].numU++;
			Tonakai_Stage2[1].numU++;
			Tonakai_Stage2[2].numU++;
			Star_Stage2[1].numU++;
			Star_Stage2[2].numU++;

			if (Snowman_Stage2[1].numU >= 4 || Snowman_Stage2[2].numU >= 4 || Snowman_Stage2[3].numU >= 4 
				|| Snowman_Stage2[4].numU >= 4||Tonakai_Stage2[1].numU>=4|| Tonakai_Stage2[2].numU >= 4)
			{
				Snowman_Stage2[1].numU = 0;
				Snowman_Stage2[2].numU = 0;
				Snowman_Stage2[3].numU = 0;
				Snowman_Stage2[4].numU = 0;
				Tonakai_Stage2[1].numU=0;
				Tonakai_Stage2[2].numU=0;
				
			}
			if (Star_Stage2[1].numU >= 6 || Star_Stage2[2].numU >= 6)
			{
				Star_Stage2[1].numU = 0;
				Star_Stage2[2].numU = 0;

			}

		}

		//-------�G�ړ�--------//
		//�Ⴞ��܁i�P�j
		if (moveFg1 == false && pauseFg == false)
		{
			Snowman_Stage2[1].numV = 0;
			snowman_pos1.x -= 1;
			if (snowman_pos1.x < ground_pos1.x - 100)//���͂��ɍs������
			{
				moveFg1 = true;
			}
		}

		if (moveFg1 == true && pauseFg == false)
		{

			Snowman_Stage2[1].numV = 1;
			snowman_pos1.x += 1;
			if (snowman_pos1.x > ground_pos1.x + 300)//�E�[�ɍs������
			{
				moveFg1 = false;
			}
		}

		//�Ⴞ��܁i2�j
		if (moveFg2 == false && pauseFg == false)
		{
			Snowman_Stage2[2].numV = 0;
			snowman_pos2.x -= 1;
			if (snowman_pos2.x < ground_pos2.x - 750)//���͂��ɍs������
			{
				moveFg2 = true;
			}
		}

		if (moveFg2 == true && pauseFg == false)
		{
			Snowman_Stage2[2].numV = 1;
			snowman_pos2.x += 1;
			if (snowman_pos2.x > ground_pos2.x -250)//�E�[�ɍs������
			{
				moveFg2 = false;
			}
		}

		//�Ⴞ��܁i3�j
		if (moveFg3 == false && pauseFg == false)
		{
			Snowman_Stage2[3].numV = 0;
			snowman_pos3.x -= 1;
			if (snowman_pos3.x < ground_pos4.x - 0)//���ɍs������
			{
				moveFg3 = true;
			}
		}

		if (moveFg3 == true && pauseFg == false)
		{
			Snowman_Stage2[3].numV = 1;
			snowman_pos3.x += 1;
			if (snowman_pos3.x > ground_pos4.x+300)//�E�[�ɍs������
			{
				moveFg3 = false;
			}
		}

		//�Ⴞ��܁i4�j
		if (moveFg4 == false && pauseFg == false)
		{
			Snowman_Stage2[4].numV = 0;
			snowman_pos4.x -= 1;
			if (snowman_pos4.x < ground_pos7.x - 100)//���ɍs������
			{
				moveFg4 = true;
			}
		}

		if (moveFg4 == true && pauseFg == false)
		{
			Snowman_Stage2[4].numV = 1;
			snowman_pos4.x += 1;
			if (snowman_pos4.x > ground_pos7.x + 300)//�E�[�ɍs������
			{
				moveFg4 = false;
			}
		}
		//�ق��i1�j
		if (moveFg5 == false && pauseFg == false)
		{
			Star_Stage2[1].numV = 0;
			star_pos1.x -= 2;
			if (star_pos1.x < ground_pos2.x - 100)//���ɍs������
			{
				moveFg5 = true;
			}
		}

		if (moveFg5 == true && pauseFg == false)
		{
			Star_Stage2[1].numV = 1;
			star_pos1.x += 2;
			if (star_pos1.x > ground_pos2.x + 400)//�E�[�ɍs������
			{
				moveFg5 = false;
			}
		}

		//�ق��i2�j
		if (moveFg6 == false && pauseFg == false)
		{
			Star_Stage2[2].numV = 0;
			star_pos2.x -= 2;
			if (star_pos2.x < ground_pos6.x - 200)//���ɍs������
			{
				moveFg6 = true;
			}
		}

		if (moveFg6 == true && pauseFg == false)
		{
			Star_Stage2[2].numV = 1;
			star_pos2.x += 2;
			if (star_pos2.x > ground_pos6.x + 50)//�E�[�ɍs������
			{
				moveFg6 = false;
			}
		}

		//�ƂȂ����i1�j
		if (moveFg7 == false && pauseFg == false)
		{
			Tonakai_Stage2[1].numV = 0;
			tonakai_pos1.x -= 3;
			if (tonakai_pos1.x < ground_pos2.x + 400)//���ɍs������
			{
				moveFg7 = true;
			}
		}

		if (moveFg7 == true && pauseFg == false)
		{
			Tonakai_Stage2[1].numV = 1;
			tonakai_pos1.x += 3;
			if (tonakai_pos1.x > ground_pos2.x + 900)//�E�[�ɍs������
			{
				moveFg7 = false;
			}
		}

		//�ƂȂ����i2�j
		if (moveFg8 == false && pauseFg == false)
		{
			Tonakai_Stage2[2].numV = 0;
			tonakai_pos2.x -= 3;
			if (tonakai_pos2.x < ground_pos7.x -200)//���ɍs������
			{
				moveFg8 = true;
			}
		}

		if (moveFg8 == true && pauseFg == false)
		{
			Tonakai_Stage2[2].numV = 1;
			tonakai_pos2.x += 3;
			if (tonakai_pos2.x > ground_pos7.x + 300)//�E�[�ɍs������
			{
				moveFg8 = false;
			}
		}
		


		//�|�[�Y���
		if (input.GetKeyTrigger(VK_P) && pauseFg == false || input.GetButtonPress(XINPUT_START) && pauseFg == false)
		{
			pauseFg = true;
		}

		if (pauseFg == true)
		{
			sound.Stop(SOUND_LABEL_BGM000);
			if (cursor1_pos.y == 100)
			{

				if (input.GetKeyTrigger(VK_S) || input.GetLeftAnalogStick().y < -0.5)
				{

					cursor1_pos.y = -100;
					cursor1_pos.x = 350;
				}

				//�L�[����
				if (input.GetKeyTrigger(VK_RETURN) || input.GetButtonTrigger(XINPUT_B))
				{
					sound.Resume(SOUND_LABEL_BGM000);
					pauseFg = false;
				}
			}
			
			if (cursor1_pos.y == -100)
			{
				if (input.GetKeyTrigger(VK_W) || input.GetLeftAnalogStick().y > 0.5)
				{
					cursor1_pos.y = 100;
					cursor1_pos.x = 250;
				}
				//�L�[����
				if (input.GetKeyTrigger(VK_RETURN) || input.GetButtonTrigger(XINPUT_B))
				{
					changescene = TITLE;
					//������
					time = 150;
					framcount = 0;
					framcount2 = 0;
					score = 0;
					presentcount = 0;
					time = 150;
					cleartime = 0;
					santa_pos.x = -400;
					santa_pos.y = -160;

					santa_huro_pos.x = -400;
					santa_huro_pos.y = -160;

					santa_kin_pos.x = -400;
					santa_kin_pos.y = -160;;

					mounten_pos1.x = 0;
					mounten_pos2.x = 1280;
					mounten_pos3.x = 2560;

					rock_pos1.x = -275;
					rock_pos2.x = 5000;
					rock_pos3.x = 1100;
					rock_pos4.x = 2800;
					rock_pos5.x = 4000;
					rock_pos6.x = 7500;

					snowball_pos1.x = 3100;
					snowball_pos2.x = 5500;
					snowball_pos3.x = 7000;

					ground_pos1.x = 0;
					ground_pos2.x = 2000;
					ground_pos3.x = 3300;
					ground_pos4.x = 3800;
					ground_pos5.x = 4450;
					ground_pos6.x = 5300;
					ground_pos7.x = 7400;

					block_pos1.x = 2000;

					icicle_pos1.x = 1800;
					icicle_pos2.x = 2000;
					icicle_pos3.x = 2200;

					icicle_pos1.y = 100;
					icicle_pos2.y = 100;
					icicle_pos3.y = 100;

					tree_pos1.x = 900;
					tree_pos2.x = 3450;


					stairs_pos1.x = 5720;
					stairs_pos2.x = 5755;
					stairs_pos3.x = 5790;
					stairs_pos4.x = 5825;
					stairs_pos5.x = 5860;

					snowman_pos1.x = 30;
					snowman_pos2.x = 1400;
					snowman_pos3.x = 3800;
					snowman_pos4.x = 7000;

					star_pos1.x = 2000;
					star_pos2.x = 5000;

					tonakai_pos1.x = 26000;
					tonakai_pos2.x = 7500;


					bigpresent_pos1.x = 4450;
					present_pos1.x = 3300;
					present_pos2.x = 6300;
					present_pos3.x = 2000;

					bigpresent_pos1.y = -250;
					present_pos1.y = -265;
					present_pos2.y = 100;
					present_pos3.y = 280;

					wall_pos1.x = -600;
					wall_pos2.x = 7850;


					breakrock_pos1.x = 4450;

					goal_pos.x = 7900;

				}
			}
		}

		//��������
		if (framcount2 % 60 == 0 && pauseFg == false)//1�b�Ɉ��s����
		{
			time--;
		}
		if (time <= 0&& gameoverFg == false || santa_pos.y < -420 && !gameoverFg)//�^�C���I�[�o�[�ɂȂ�����
		{
			sound.Play(SOUND_LABEL_BGM001);
			gameoverFg = true;
		}
		if (gameoverFg == true)
		{
			
			sound.Stop(SOUND_LABEL_BGM000);
			

			if (cursor_pos.y == -100)
			{
				if (input.GetKeyTrigger(VK_S) || input.GetLeftAnalogStick().y < -0.5)
				{
					cursor_pos.y = -200;
				}

				if (input.GetKeyTrigger(VK_RETURN) || input.GetButtonTrigger(XINPUT_B))
				{
					changescene = STAGE2_LOADING;//���g���C
					gameoverFg = false;
					//������
					time = 150;
					framcount = 0;
					framcount2 = 0;
					score = 0;
					presentcount = 0;
					time = 150;
					cleartime = 0;
					jumpVelocity = 0.0f;
					santa_pos.x = -400;
					santa_pos.y = -160;

					santa_huro_pos.x = -400;
					santa_huro_pos.y = -160;

					santa_kin_pos.x = -400;
					santa_kin_pos.y = -160;

					mounten_pos1.x = 0;
					mounten_pos2.x = 1280;
					mounten_pos3.x = 2560;

					rock_pos1.x = -275;
					rock_pos2.x = 5000;
					rock_pos3.x = 1100;
					rock_pos4.x = 2800;
					rock_pos5.x = 4000;
					rock_pos6.x = 7500;

					snowball_pos1.x = 3100;
					snowball_pos2.x = 5500;
					snowball_pos3.x = 7000;

					ground_pos1.x = 0;
					ground_pos2.x = 2000;
					ground_pos3.x = 3300;
					ground_pos4.x = 3800;
					ground_pos5.x = 4450;
					ground_pos6.x = 5300;
					ground_pos7.x = 7400;

					block_pos1.x = 2000;

					icicle_pos1.x = 1800;
					icicle_pos2.x = 2000;
					icicle_pos3.x = 2200;

					icicle_pos1.y = 100;
					icicle_pos2.y = 100;
					icicle_pos3.y = 100;

					tree_pos1.x = 900;
					tree_pos2.x = 3450;

					stairs_pos1.x = 5720;
					stairs_pos2.x = 5755;
					stairs_pos3.x = 5790;
					stairs_pos4.x = 5825;
					stairs_pos5.x = 5860;

					snowman_pos1.x = 30;
					snowman_pos2.x = 1400;
					snowman_pos3.x = 3800;
					snowman_pos4.x = 7000;

					star_pos1.x = 2000;
					star_pos2.x = 5000;

					tonakai_pos1.x = 26000;
					tonakai_pos2.x = 7500;

					bigpresent_pos1.x = 4450;
					present_pos1.x = 3300;
					present_pos2.x = 6300;
					present_pos3.x = 2000;

					bigpresent_pos1.y = -250;
					present_pos1.y = -265;
					present_pos2.y = 100;
					present_pos3.y = 280;

					breakrock_pos1.x = 4450;
					moji_pos.x = 4450;
					goal_pos.x = 7900;

					wall_pos1.x = -600;
					wall_pos2.x = 7850;


				}
			}

			if (cursor_pos.y == -200)
			{
				if (input.GetKeyTrigger(VK_W) || input.GetLeftAnalogStick().y > 0.5)
				{
					cursor_pos.y = -100;
				}

				if (input.GetKeyTrigger(VK_RETURN) || input.GetButtonTrigger(XINPUT_B))
				{
					changescene = TITLE;//�^�C�g��
					gameoverFg = false;
					//������
					time = 150;
					framcount = 0;
					framcount2 = 0;
					score = 0;
					presentcount = 0;
					time = 150;
					cleartime = 0;
					jumpVelocity = 0.0f;
					santa_pos.x = -400;
					santa_pos.y = -160;

					santa_huro_pos.x = -400;
					santa_huro_pos.y = -160;

					santa_kin_pos.x = -400;
					santa_kin_pos.y = -160;

					mounten_pos1.x = 0;
					mounten_pos2.x = 1280;
					mounten_pos3.x = 2560;

					rock_pos1.x = -275;
					rock_pos2.x = 5000;
					rock_pos3.x = 1100;
					rock_pos4.x = 2800;
					rock_pos5.x = 4000;
					rock_pos6.x = 7500;

					snowball_pos1.x = 3100;
					snowball_pos2.x = 5500;
					snowball_pos3.x = 7000;

					ground_pos1.x = 0;
					ground_pos2.x = 2000;
					ground_pos3.x = 3300;
					ground_pos4.x = 3800;
					ground_pos5.x = 4450;
					ground_pos6.x = 5300;
					ground_pos7.x = 7400;

					block_pos1.x = 2000;

					icicle_pos1.x = 1800;
					icicle_pos2.x = 2000;
					icicle_pos3.x = 2200;

					tree_pos1.x = 900;


					stairs_pos1.x = 5720;
					stairs_pos2.x = 5755;
					stairs_pos3.x = 5790;
					stairs_pos4.x = 5825;
					stairs_pos5.x = 5860;

					snowman_pos1.x = 30;
					snowman_pos2.x = 1400;
					snowman_pos3.x = 3800;
					snowman_pos4.x = 7000;

					star_pos1.x = 2000;
					star_pos2.x = 5000;

					tonakai_pos1.x = 26000;
					tonakai_pos2.x = 7500;

					bigpresent_pos1.x = 4450;
					present_pos1.x = 3300;
					present_pos2.x = 6300;
					present_pos3.x = 2000;

					bigpresent_pos1.y = -250;
					present_pos1.y = -265;
					present_pos2.y = 100;
					present_pos3.y = 280;

					breakrock_pos1.x = 4450;
					moji_pos.x = 4450;
					goal_pos.x = 7900;

					wall_pos1.x = -600;
					wall_pos2.x = 7850;



				}

			}
		}

		hitcooltime++;
		//�G�ɓ����������Q�b���G��
		if (hitcooltime % 80 == 0 && HitFg == true)
		{
			HitFg = false;//
		}

		// �T���^���A�C�e���ɓ���������
		bool itemCollected = false; // �A�C�e�������ɉ�����ꂽ���ǂ����̃t���O

		const float rightScreen = 670.0f; // ��ʂ̉E�[
		const float leftScreen = -670.0f; // ��ʂ̍��[


		// �܂̐؂�ւ�
		if (input.GetKeyTrigger(VK_UP) || input.GetButtonTrigger(XINPUT_UP))
		{
			santa_bug = 0;

		}

		if (input.GetKeyTrigger(VK_LEFT) || input.GetButtonTrigger(XINPUT_LEFT))
		{
			santa_bug = 1;
		}

		if (input.GetKeyTrigger(VK_RIGHT) || input.GetButtonTrigger(XINPUT_RIGHT))
		{
			santa_bug = 2;
		}
		santa_pos1.x = santa_pos.x;
		santa_pos1.y = santa_pos.y;
		santa_pos2.x = santa_pos.x;
		santa_pos2.y = santa_pos.y;
		santa_pos3.x = santa_pos.x;
		santa_pos3.y = santa_pos.y;
		santa_pos4.x = santa_pos.x;
		santa_pos4.y = santa_pos.y;
		santa_pos5.x = santa_pos.x;
		santa_pos5.y = santa_pos.y;
		santa_pos6.x = santa_pos.x;
		santa_pos6.y = santa_pos.y;
		santa_pos7.x = santa_pos.x;
		santa_pos7.y = santa_pos.y;

		santa_huro_pos1.x = santa_huro_pos.x;
		santa_huro_pos1.y = santa_huro_pos.y;
		santa_huro_pos2.x = santa_huro_pos.x;
		santa_huro_pos2.y = santa_huro_pos.y;
		santa_huro_pos3.x = santa_huro_pos.x;
		santa_huro_pos3.y = santa_huro_pos.y;
		santa_huro_pos4.x = santa_huro_pos.x;
		santa_huro_pos4.y = santa_huro_pos.y;
		santa_huro_pos5.x = santa_huro_pos.x;
		santa_huro_pos5.y = santa_huro_pos.y;
		santa_huro_pos6.x = santa_huro_pos.x;
		santa_huro_pos6.y = santa_huro_pos.y;
		santa_huro_pos7.x = santa_huro_pos.x;
		santa_huro_pos7.y = santa_huro_pos.y;

		santa_kin_pos1.x = santa_kin_pos.x;
		santa_kin_pos1.y = santa_kin_pos.y;
		santa_kin_pos2.x = santa_kin_pos.x;
		santa_kin_pos2.y = santa_kin_pos.y;
		santa_kin_pos3.x = santa_kin_pos.x;
		santa_kin_pos3.y = santa_kin_pos.y;
		santa_kin_pos4.x = santa_kin_pos.x;
		santa_kin_pos4.y = santa_kin_pos.y;
		santa_kin_pos5.x = santa_kin_pos.x;
		santa_kin_pos5.y = santa_kin_pos.y;
		santa_kin_pos6.x = santa_kin_pos.x;
		santa_kin_pos6.y = santa_kin_pos.y;

		
	    //�ʏ�
		if(santa_bug==0)
		{

			santa_huro_pos.x = santa_pos.x;
			santa_kin_pos.x = santa_pos.x;

			santa_huro_pos.y = santa_pos.y;
			santa_kin_pos.y = santa_pos.y;
			// �Ⴞ��܂Ƃ̓����蔻��ǉ� 
			if (collision.enemy_santa(Snowman_Stage2[1], santa_Nor[0], 200.0f, 0.0f) && HitFg == false && pauseFg == false && gameoverFg == false)
			{
				time -= 5;
				hitcooltime = 0;
				sound.Play(SOUND_LABEL_SE000);
				damage5 = true;
				HitFg = true;
				
			}

			if (collision.enemy_santa(Snowman_Stage2[2], santa_Nor[0], 200.0f, 0.0f) && HitFg == false && pauseFg == false && gameoverFg == false)
			{

				time -= 5;
				hitcooltime = 0;
				sound.Play(SOUND_LABEL_SE000);
				damage5 = true;
				HitFg = true;
			}

			if (collision.enemy_santa(Snowman_Stage2[3], santa_Nor[0], 200.0f, 0.0f) && HitFg == false && pauseFg == false && gameoverFg == false)
			{
				time -= 5;
				hitcooltime = 0;
				sound.Play(SOUND_LABEL_SE000);
				damage5 = true;
				HitFg = true;
			}

			if (collision.enemy_santa(Snowman_Stage2[4], santa_Nor[0], 200.0f, 0.0f) && HitFg == false && pauseFg == false && gameoverFg == false)
			{

				time -= 5;
				hitcooltime = 0;
				sound.Play(SOUND_LABEL_SE000);
				damage5 = true;
				HitFg = true;
			}

			// ���Ƃ̓����蔻��ǉ� 
			if (collision.enemy_santa(Star_Stage2[1], santa_Nor[0], 200.0f, 0.0f) && HitFg == false && pauseFg == false && gameoverFg == false)
			{
				time -= 5;
				hitcooltime = 0;
				sound.Play(SOUND_LABEL_SE000);
				damage5 = true;
				HitFg = true;
			}

			if (collision.enemy_santa(Star_Stage2[2], santa_Nor[0], 200.0f, 0.0f) && HitFg == false && pauseFg == false && gameoverFg == false)
			{
				time -= 5;
				hitcooltime = 0;
				sound.Play(SOUND_LABEL_SE000);
				damage5 = true;
				HitFg = true;
			}

			//�g�i�J�C �Ƃ̓����蔻��ǉ� 

			if (collision.enemy_santa(Tonakai_Stage2[1], santa_Nor[0], 200.0f, 0.0f) && HitFg == false && pauseFg == false && gameoverFg == false)
			{
				time -= 5;
				hitcooltime = 0;
				sound.Play(SOUND_LABEL_SE000);
				damage5 = true;
				HitFg = true;
			}

			if (collision.enemy_santa(Tonakai_Stage2[2], santa_Nor[0], 200.0f, 0.0f) && HitFg == false && pauseFg == false && gameoverFg == false)
			{
				time -= 5;
				hitcooltime = 0;
				sound.Play(SOUND_LABEL_SE000);
				damage5 = true;
				HitFg = true;
			}
			if (rocklive)
			{
				if (collision.tree_santa(Breakrock_Stge2[1], santa_Nor[0], 200.0f,50.0f))
				{
					if (santa_huro_pos.y > breakrock_pos1.y + Breakrock_Stge2[1].GetSize().y / 2.0f) {

						santa_huro_pos.y = breakrock_pos1.y + Breakrock_Stge2[1].GetSize().y / 2.0f + santa_Nor[0].GetSize().y / 2.0f;
						tachFg = true;
					}
					else {
						tachFg = false;
					}

					//// �T���^���؂̉E���ɂԂ������ꍇ
					if (santa_pos.x < breakrock_pos1.x&& tachFg == false)
					{
						collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
					}
					// �T���^���؂̍����ɂԂ������ꍇ
					if (santa_pos.x > breakrock_pos1.x && tachFg == false)
					{

						collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
					}
				}
			}
			


			// �؂Ƃ̓����蔻��̒ǉ��@�S���C
			if (collision.tree_santa(Tree_Stge2[1], santa_Nor[0], 200.0f, 0.0f))
			{

				//// �T���^���؂̉E���ɂԂ������ꍇ
				if (santa_pos.x < tree_pos1.x)
				{
					collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
				}
				// �T���^���؂̍����ɂԂ������ꍇ
				if (santa_pos.x > tree_pos1.x)
				{

					collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
				}
			}

			if (collision.tree_santa(Tree_Stge2[2], santa_Nor[0], 200.0f, 0.0f))
			{

				//// �T���^���؂̉E���ɂԂ������ꍇ
				if (santa_pos.x < tree_pos2.x)
				{
					collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
				}
				// �T���^���؂̍����ɂԂ������ꍇ
				if (santa_pos.x > tree_pos2.x)
				{
					collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~

				}
			}

			if (collision.tree_santa(invisiblewall[3], santa_Nor[0], 200.0f, 0.0f))
			{

				//// �T���^���؂̉E���ɂԂ������ꍇ
				if (santa_pos.x < wall_pos1.x)
				{
					collision.canMoveRight = false; //�E�Ɉړ����Ȃ�ړ����~
				}

				// �T���^���؂̍����ɂԂ������ꍇ
				if (santa_pos.x > wall_pos1.x)
				{
					collision.canMoveLeft = false; //�E�Ɉړ����Ȃ�ړ����~
				}
			}

			if (collision.tree_santa(invisiblewall[4], santa_Nor[0], 200.0f, 0.0f))
			{

				//// �T���^���؂̉E���ɂԂ������ꍇ
				if (santa_pos.x < wall_pos2.x)
				{
					collision.canMoveRight = false; //�E�Ɉړ����Ȃ�ړ����~
				}

				// �T���^���؂̍����ɂԂ������ꍇ
				if (santa_pos.x > wall_pos2.x)
				{
					collision.canMoveLeft = false; //�E�Ɉړ����Ȃ�ړ����~
				}
			}

			if (collision.block_santa(Stairs_Stge2[1], santa_Nor[0], 100.0f, 0.0f))
			{
				if (santa_pos.y > stairs_pos1.y + Stairs_Stge2[1].GetSize().y / 2.0f) {
					santa_pos.y = stairs_pos1.y + Stairs_Stge2[1].GetSize().y / 2.0f + santa_Nor[0].GetSize().y / 2.0f;
					jumpVelocity = 0.0f;
					tachFg = true;
					/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
				}
				else {
					tachFg = false;
					/*std::cout << "\nSanta is falling." << std::endl;*/
				}

				if (santa_pos.x < stairs_pos1.x&& tachFg == false)
				{
					collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
				}

				// �T���^���Ԃ������ꍇ
				if (santa_pos.x > stairs_pos1.x && tachFg == false)
				{
					collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
				}
			}

			if (collision.block_santa(Stairs_Stge2[2], santa_Nor[0], 100.0f, 0.0f))
			{
				if (santa_pos.y > stairs_pos2.y + Stairs_Stge2[2].GetSize().y / 2.0f) {
					santa_pos.y = stairs_pos2.y + Stairs_Stge2[2].GetSize().y / 2.0f + santa_Nor[0].GetSize().y / 2.0f;
					jumpVelocity = 0.0f;
					tachFg = true;
					/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
				}
				else {
					tachFg = false;
					/*std::cout << "\nSanta is falling." << std::endl;*/
				}

				if (santa_pos.x < stairs_pos2.x&& tachFg == false)
				{
					collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
				}

				// �T���^���Ԃ������ꍇ
				if (santa_pos.x > stairs_pos2.x&&tachFg == false)
				{
					collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
				}
			}

			if (collision.block_santa(Stairs_Stge2[3], santa_Nor[0], 100.0f, 0.0f))
			{
				if (santa_pos.y > stairs_pos3.y + Stairs_Stge2[3].GetSize().y / 2.0f) {
					santa_pos.y = stairs_pos3.y + Stairs_Stge2[3].GetSize().y / 2.0f + santa_Nor[0].GetSize().y / 2.0f;
					jumpVelocity = 0.0f;
					tachFg = true;
					/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
				}
				else {
					tachFg = false;
					/*std::cout << "\nSanta is falling." << std::endl;*/
				}

				if (santa_pos.x < stairs_pos3.x	&&tachFg == false)
				{
					collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
				}

				// �T���^���Ԃ������ꍇ
				if (santa_pos.x > stairs_pos3.x&& tachFg == false)
				{
					collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
				}
			}

			if (collision.block_santa(Stairs_Stge2[4], santa_Nor[0], 100.0f, 0.0f))
			{
				if (santa_pos.y > stairs_pos4.y + Stairs_Stge2[4].GetSize().y / 2.0f) {
					santa_pos.y = stairs_pos4.y + Stairs_Stge2[4].GetSize().y / 2.0f + santa_Nor[0].GetSize().y / 2.0f;
					jumpVelocity = 0.0f;
					tachFg = true;
					/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
				}
				else {
					tachFg = false;
					/*std::cout << "\nSanta is falling." << std::endl;*/
				}

				if (santa_pos.x < stairs_pos4.x&& tachFg == false)
				{
					collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
				}

				// �T���^���Ԃ������ꍇ
				if (santa_pos.x > stairs_pos4.x&& tachFg == false)
				{
					collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
				}
			}

			if (collision.block_santa(Stairs_Stge2[5], santa_Nor[0], 100.0f, 0.0f))
			{
				if (santa_pos.y > stairs_pos5.y + Stairs_Stge2[5].GetSize().y / 2.0f) {
					santa_pos.y = stairs_pos5.y + Stairs_Stge2[5].GetSize().y / 2.0f + santa_Nor[0].GetSize().y / 2.0f;
					jumpVelocity = 0.0f;
					tachFg = true;
					/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
				}
				else {
					tachFg = false;
					/*std::cout << "\nSanta is falling." << std::endl;*/
				}

				if (santa_pos.x < stairs_pos5.x && santa_pos.y / 2 < stairs_pos5.y / 3&& tachFg == false)
				{
					collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
				}

				// �T���^���Ԃ������ꍇ
				if (santa_pos.x > stairs_pos5.x && santa_pos.y / 2 < stairs_pos5.y / 3&& tachFg == false)
				{
					collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
				}
			}




			//�v���[���g�̓����蔻��
			if (collision.item_santa(Present_Stage2[1], santa_Nor[0], 100.0f, 0.0f) && pauseFg == false)

			{
				presentcount += 1;
				score += 5000;
				present_pos1.y = 100000;
				sound.Play(SOUND_present);
			}

			if (collision.item_santa(Present_Stage2[2], santa_Nor[0], 100.0f, 0.0f))
			{
				presentcount += 1;
				score += 5000;
				present_pos2.y = 100000;
				sound.Play(SOUND_present);
			}

			if (collision.item_santa(Present_Stage2[3], santa_Nor[0], 100.0f, 0.0f))
			{
				presentcount += 1;
				score += 5000;
				present_pos3.y = 100000;
				sound.Play(SOUND_present);
			}

			if (collision.item_santa(BigPresent_Stage2[1], santa_Nor[0], 100.0f, 0.0f))
			{
				bigpresentcount += 1;
				score += 10000;
				bigpresent_pos1.y = 100000;
				sound.Play(SOUND_present);
			}
			// �n�ʂƂ̓����蔻��̒ǉ� �S���C


			if (collision.ground_santa(Ground_Stge2[1], santa_Nor[0], 50.0f, 0.0f)) {

				//// �T���^���n�ʂ̏�ɂ���ꍇ
				if (santa_pos.y > ground_pos1.y + Ground_Stge2[1].GetSize().y / 2.0f) {
					santa_pos.y = ground_pos1.y + Ground_Stge2[1].GetSize().y / 2.0f + santa_Nor[0].GetSize().y / 2.0f;
					jumpVelocity = 0.0f;
					/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
				}
				else {
					/*std::cout << "\nSanta is falling." << std::endl;*/
				}

				// �T���^���n�ʂ̉E���ɂԂ������ꍇ
				if (santa_pos.x < ground_pos1.x && santa_pos.y < ground_pos1.y) {

					collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
				}

				// �T���^���n�ʂɂԂ������ꍇ
				if (santa_pos.x > ground_pos1.x && santa_pos.y < ground_pos1.y) {
					collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
				}
			}

			if (collision.ground_santa(Ground_Stge2[2], santa_Nor[0], 50.0f, 0.0f))
			{

				//// �T���^���n�ʂ̏�ɂ���ꍇ
				if (santa_pos.y > ground_pos2.y + Ground_Stge2[2].GetSize().y / 2.0f) {
					santa_pos.y = ground_pos2.y + Ground_Stge2[2].GetSize().y / 2.0f + santa_Nor[0].GetSize().y / 2.0f;
					jumpVelocity = 0.0f;
					/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
				}
				else {
					/*std::cout << "\nSanta is falling." << std::endl;*/
				}

				// �T���^���n�ʂ̉E���ɂԂ������ꍇ
				if (santa_pos.x < ground_pos2.x && santa_pos.y < ground_pos2.y) {

					collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
				}

				// �T���^���n�ʂɂԂ������ꍇ
				if (santa_pos.x > ground_pos2.x && santa_pos.y < ground_pos2.y) {
					collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
				}
			}

			if (collision.ground_santa(Ground_Stge2[3], santa_Nor[0], 50.0f, 0.0f)) {

				//// �T���^���n�ʂ̏�ɂ���ꍇ
				if (santa_pos.y > ground_pos3.y + Ground_Stge2[3].GetSize().y / 2.0f) {
					santa_pos.y = ground_pos3.y + Ground_Stge2[3].GetSize().y / 2.0f + santa_Nor[0].GetSize().y / 2.0f;
					jumpVelocity = 0.0f;
					/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
				}
				else {
					/*std::cout << "\nSanta is falling." << std::endl;*/
				}

				// �T���^���n�ʂ̉E���ɂԂ������ꍇ
				if (santa_pos.x < ground_pos3.x && santa_pos.y < ground_pos3.y) {

					collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
				}

				// �T���^���n�ʂɂԂ������ꍇ
				if (santa_pos.x > ground_pos3.x && santa_pos.y < ground_pos3.y) {
					collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
				}
			}

			if (collision.ground_santa(Ground_Stge2[4], santa_Nor[0], 50.0f, 0.0f)) {

				//// �T���^���n�ʂ̏�ɂ���ꍇ
				if (santa_pos.y > ground_pos4.y + Ground_Stge2[4].GetSize().y / 2.0f) {
					santa_pos.y = ground_pos4.y + Ground_Stge2[4].GetSize().y / 2.0f + santa_Nor[0].GetSize().y / 2.0f;
					jumpVelocity = 0.0f;
					/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
				}
				else {
					/*std::cout << "\nSanta is falling." << std::endl;*/
				}

				// �T���^���n�ʂ̉E���ɂԂ������ꍇ
				if (santa_pos.x < ground_pos4.x && santa_pos.y < ground_pos4.y) {

					collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
				}

				// �T���^���n�ʂɂԂ������ꍇ
				if (santa_pos.x > ground_pos4.x && santa_pos.y < ground_pos4.y) {
					collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
				}
			}

			if (collision.ground_santa(Ground_Stge2[5], santa_Nor[0], 50.0f, 0.0f)) {

				//// �T���^���n�ʂ̏�ɂ���ꍇ
				if (santa_pos.y > ground_pos5.y + Ground_Stge2[5].GetSize().y / 2.0f) {
					santa_pos.y = ground_pos5.y + Ground_Stge2[5].GetSize().y / 2.0f + santa_Nor[0].GetSize().y / 2.0f;
					jumpVelocity = 0.0f;
					/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
				}
				else {
					/*std::cout << "\nSanta is falling." << std::endl;*/
				}

				// �T���^���n�ʂ̉E���ɂԂ������ꍇ
				if (santa_pos.x < ground_pos5.x && santa_pos.y < ground_pos5.y) {

					collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
				}

				// �T���^���n�ʂɂԂ������ꍇ
				if (santa_pos.x > ground_pos5.x && santa_pos.y < ground_pos5.y) {
					collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
				}
			}

			if (collision.ground_santa(Ground_Stge2[6], santa_Nor[0], 50.0f, 0.0f)) {

				//// �T���^���n�ʂ̏�ɂ���ꍇ
				if (santa_pos.y > ground_pos6.y + Ground_Stge2[6].GetSize().y / 2.0f) {
					santa_pos.y = ground_pos6.y + Ground_Stge2[6].GetSize().y / 2.0f + santa_Nor[0].GetSize().y / 2.0f;
					jumpVelocity = 0.0f;
					/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
				}
				else {
					/*std::cout << "\nSanta is falling." << std::endl;*/
				}

				// �T���^���n�ʂ̉E���ɂԂ������ꍇ
				if (santa_pos.x < ground_pos6.x && santa_pos.y < ground_pos6.y) {

					collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
				}

				// �T���^���n�ʂɂԂ������ꍇ
				if (santa_pos.x > ground_pos6.x && santa_pos.y < ground_pos6.y) {
					collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
				}
			}

			if (collision.ground_santa(Ground_Stge2[7], santa_Nor[0], 50.0f, 0.0f)) {

				//// �T���^���n�ʂ̏�ɂ���ꍇ
				if (santa_pos.y > ground_pos7.y + Ground_Stge2[7].GetSize().y / 2.0f) {
					santa_pos.y = ground_pos7.y + Ground_Stge2[7].GetSize().y / 2.0f + santa_Nor[0].GetSize().y / 2.0f;
					jumpVelocity = 0.0f;
					/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
				}
				else {
					/*std::cout << "\nSanta is falling." << std::endl;*/
				}

				// �T���^���n�ʂ̉E���ɂԂ������ꍇ
				if (santa_pos.x < ground_pos7.x && santa_pos.y < ground_pos7.y) {

					collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
				}

				// �T���^���n�ʂɂԂ������ꍇ
				if (santa_pos.x > ground_pos7.x && santa_pos.y < ground_pos7.y) {
					collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
				}
			}

			if (collision.ground_santa(Block_Stge2[1], santa_Nor[0], 50.0f, 0.0f)) {

				//// �T���^���n�ʂ̏�ɂ���ꍇ
				if (santa_pos.y > block_pos1.y + Block_Stge2[1].GetSize().y / 2.0f) {
					santa_pos.y = block_pos1.y + Block_Stge2[1].GetSize().y / 2.0f + santa_Nor[0].GetSize().y / 2.0f;
					jumpVelocity = 0.0f;
					/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
				}
				else {
					/*std::cout << "\nSanta is falling." << std::endl;*/
				}

				// �T���^���n�ʂ̉E���ɂԂ������ꍇ
				if (santa_pos.x < block_pos1.x && santa_pos.y < block_pos1.y) {

					collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
				}

				// �T���^���n�ʂɂԂ������ꍇ
				if (santa_pos.x > block_pos1.x && santa_pos.y < block_pos1.y) {
					collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
				}
			}



			//�S�[�������蔻��
			if (collision.goal_santa(Goal_Stage2, santa_Nor[0], 250.0f, 0.0f))
			{
				changescene = RESULT;
				gameoverFg = false;
				//������
				santa_pos.x = -400;
				santa_pos.y = -160;

				santa_kin_pos.x = -400;
				santa_kin_pos.y = -160;

				santa_huro_pos.x = -400;
				santa_huro_pos.y = -160;

				mounten_pos1.x = 0;
				mounten_pos2.x = 1280;
				mounten_pos3.x = 2560;

				rock_pos1.x = -275;
				rock_pos2.x = 5000;
				rock_pos3.x = 1100;
				rock_pos4.x = 2800;
				rock_pos5.x = 4000;
				rock_pos6.x = 7500;

				snowball_pos1.x = 3100;
				snowball_pos2.x = 5500;
				snowball_pos3.x = 7000;

				ground_pos1.x = 0;
				ground_pos2.x = 2000;
				ground_pos3.x = 3300;
				ground_pos4.x = 3800;
				ground_pos5.x = 4450;
				ground_pos6.x = 5300;
				ground_pos7.x = 7400;

				block_pos1.x = 2000;

				icicle_pos1.x = 1800;
				icicle_pos2.x = 2000;
				icicle_pos3.x = 2200;

				icicle_pos1.y = 100;
				icicle_pos2.y = 100;
				icicle_pos3.y = 100;

				tree_pos1.x = 900;
				tree_pos2.x = 3450;

				stairs_pos1.x = 5720;
				stairs_pos2.x = 5755;
				stairs_pos3.x = 5790;
				stairs_pos4.x = 5825;
				stairs_pos5.x = 5860;

				snowman_pos1.x = 30;
				snowman_pos2.x = 1400;
				snowman_pos3.x = 3800;
				snowman_pos4.x = 7000;

				star_pos1.x = 2000;
				star_pos2.x = 5000;

				tonakai_pos1.x = 26000;
				tonakai_pos2.x = 7500;
				bigpresent_pos1.x = 4450;
				present_pos1.x = 3300;
				present_pos2.x = 6300;
				present_pos3.x = 2000;

				breakrock_pos1.x = 4450;
				moji_pos.x = 4450;

				goal_pos.x = 7900;

				wall_pos1.x = -600;
				wall_pos2.x = 7850;

			}


			// �������̓����蔻�� ��

				// �Ⴞ��܂P
			if (collision.square_square(Snowman_Stage2[1], use_rock[0]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp1 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos1.x;
				particlepos.y = snowman_pos1.y;

				if (snowman_hp1 < 0)
				{
					enemylive1 = false;
					snowman_hp1 = 20;
					snowman_pos1.x = 400000000;
				}
			}

			if (collision.square_square(Snowman_Stage2[1], use_rock[1]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp1 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos1.x;
				particlepos.y = snowman_pos1.y;

				if (snowman_hp1 < 0)
				{
					enemylive1 = false;
					snowman_hp1 = 20;
					snowman_pos1.x = 400000000;
				}
			}

			if (collision.square_square(Snowman_Stage2[1], use_rock[2]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp1 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos1.x;
				particlepos.y = snowman_pos1.y;

				if (snowman_hp1 < 0)
				{
					enemylive1 = false;
					snowman_hp1 = 20;
					snowman_pos1.x = 400000000;
				}
			}

			// �Ⴞ��܂Q
			if (collision.square_square(Snowman_Stage2[2], use_rock[0]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp2 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos2.x;
				particlepos.y = snowman_pos2.y;

				if (snowman_hp2 < 0)
				{
					enemylive2 = false;
					snowman_hp2 = 20;
					snowman_pos2.x = 400000000;
				}
			}

			if (collision.square_square(Snowman_Stage2[2], use_rock[1]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp2 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos2.x;
				particlepos.y = snowman_pos2.y;

				if (snowman_hp2 < 0)
				{
					enemylive2 = false;
					snowman_hp2 = 20;
					snowman_pos2.x = 400000000;
				}
			}

			if (collision.square_square(Snowman_Stage2[2], use_rock[2]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp2 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos2.x;
				particlepos.y = snowman_pos2.y;

				if (snowman_hp2 < 0)
				{
					enemylive2 = false;
					snowman_hp2 = 20;
					snowman_pos2.x = 400000000;
				}
			}

			// �Ⴞ���3
			if (collision.square_square(Snowman_Stage2[3], use_rock[0]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp3 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos3.x;
				particlepos.y = snowman_pos3.y;

				if (snowman_hp3 < 0)
				{
					enemylive3 = false;
					snowman_hp3 = 20;
					snowman_pos3.x = 400000000;
				}
			}

			if (collision.square_square(Snowman_Stage2[3], use_rock[1]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp3 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos3.x;
				particlepos.y = snowman_pos3.y;

				if (snowman_hp3 < 0)
				{
					enemylive3 = false;
					snowman_hp3 = 20;
					snowman_pos3.x = 400000000;
				}
			}

			if (collision.square_square(Snowman_Stage2[3], use_rock[2]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp3 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos3.x;
				particlepos.y = snowman_pos3.y;

				if (snowman_hp3 < 0)
				{
					enemylive3 = false;
					snowman_hp3 = 20;
					snowman_pos3.x = 400000000;
				}
			}

			// �Ⴞ���3
			if (collision.square_square(Snowman_Stage2[4], use_rock[0]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp4 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos4.x;
				particlepos.y = snowman_pos4.y;

				if (snowman_hp4 < 0)
				{
					enemylive4 = false;
					snowman_hp4 = 20;
					snowman_pos4.x = 400000000;
				}
			}

			if (collision.square_square(Snowman_Stage2[4], use_rock[1]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp4 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos4.x;
				particlepos.y = snowman_pos4.y;

				if (snowman_hp4 < 0)
				{
					enemylive4 = false;
					snowman_hp4 = 20;
					snowman_pos4.x = 400000000;
				}
			}

			if (collision.square_square(Snowman_Stage2[4], use_rock[2]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp4 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos4.x;
				particlepos.y = snowman_pos4.y;

				if (snowman_hp4 < 0)
				{
					enemylive4 = false;
					snowman_hp4 = 20;
					snowman_pos4.x = 400000000;
				}
			}

			// �N���X�}�X�c���[1
			if (collision.square_square(Star_Stage2[1], use_rock[0]) == true) {
				star_monster_hp1 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = star_pos1.x;
				particlepos.y = star_pos1.y;
				if (star_monster_hp1 < 0)
				{
					enemylive5 = false;
					star_monster_hp1 = 40;
					star_pos1.x = 400000000;
				}
			}

			if (collision.square_square(Star_Stage2[1], use_rock[1]) == true) {
				star_monster_hp1 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = star_pos1.x;
				particlepos.y = star_pos1.y;
				if (star_monster_hp1 < 0)
				{
					enemylive5 = false;
					star_monster_hp1 = 40;
					star_pos1.x = 400000000;
				}
			}

			if (collision.square_square(Star_Stage2[1], use_rock[2]) == true) {
				star_monster_hp1 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = star_pos1.x;
				particlepos.y = star_pos1.y;
				if (star_monster_hp1 < 0)
				{
					enemylive5 = false;
					star_monster_hp1 = 40;
					star_pos1.x = 400000000;
				}
			}

			// �N���X�}�X�c���[2
			if (collision.square_square(Star_Stage2[2], use_rock[0]) == true) {
				star_monster_hp2 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = star_pos2.x;
				particlepos.y = star_pos2.y;
				if (star_monster_hp2 < 0)
				{
					enemylive6 = false;
					star_monster_hp2 = 40;
					star_pos2.x = 400000000;
				}
			}

			if (collision.square_square(Star_Stage2[2], use_rock[1]) == true) {
				star_monster_hp2 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = star_pos2.x;
				particlepos.y = star_pos2.y;
				if (star_monster_hp2 < 0)
				{
					enemylive6 = false;
					star_monster_hp2 = 40;
					star_pos2.x = 400000000;
				}
			}

			if (collision.square_square(Star_Stage2[2], use_rock[2]) == true) {
				star_monster_hp2 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = star_pos2.x;
				particlepos.y = star_pos2.y;
				if (star_monster_hp2 < 0)
				{
					enemylive6 = false;
					star_monster_hp2 = 40;
					star_pos2.x = 400000000;
				}
			}

			// �g�i�J�C1
			if (collision.square_square(Tonakai_Stage2[1], use_rock[0]) == true) {
				tonakai_hp1 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = tonakai_pos1.x;
				particlepos.y = tonakai_pos1.y;
				if (tonakai_hp1 < 0)
				{
					enemylive7 = false;
					tonakai_hp1 = 60;
					tonakai_pos1.x = 400000000;
				}
			}

			if (collision.square_square(Tonakai_Stage2[1], use_rock[1]) == true) {
				tonakai_hp1 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = tonakai_pos1.x;
				particlepos.y = tonakai_pos1.y;
				if (tonakai_hp1 < 0)
				{
					enemylive7 = false;
					tonakai_hp1 = 60;
					tonakai_pos1.x = 400000000;
				}
			}

			if (collision.square_square(Tonakai_Stage2[1], use_rock[2]) == true) {
				tonakai_hp1 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = tonakai_pos1.x;
				particlepos.y = tonakai_pos1.y;
				if (tonakai_hp1 < 0)
				{
					enemylive7 = false;
					tonakai_hp1 = 60;
					tonakai_pos1.x = 400000000;
				}
			}

			// �g�i�J�C2
			if (collision.square_square(Tonakai_Stage2[2], use_rock[0]) == true) {
				tonakai_hp2 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = tonakai_pos2.x;
				particlepos.y = tonakai_pos2.y;
				if (tonakai_hp2 < 0)
				{
					enemylive8 = false;
					tonakai_hp2 = 60;
					tonakai_pos2.x = 400000000;
				}
			}

			if (collision.square_square(Tonakai_Stage2[2], use_rock[1]) == true) {
				tonakai_hp2 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = tonakai_pos2.x;
				particlepos.y = tonakai_pos2.y;
				if (tonakai_hp2 < 0)
				{
					enemylive8 = false;
					tonakai_hp2 = 60;
					tonakai_pos2.x = 400000000;
				}
			}

			if (collision.square_square(Tonakai_Stage2[2], use_rock[2]) == true) {
				tonakai_hp2 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = tonakai_pos2.x;
				particlepos.y = tonakai_pos2.y;
				if (tonakai_hp2 < 0)
				{
					enemylive8 = false;
					tonakai_hp2 = 60;
					tonakai_pos2.x = 400000000;
				}
			}


			// �������̓����蔻�� ���
			// �Ⴞ��܂P
			if (collision.square_square(Snowman_Stage2[1], use_snowball[0]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp1 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos1.x;
				particlepos.y = snowman_pos1.y;

				if (snowman_hp1 < 0)
				{
					enemylive1 = false;
					snowman_hp1 = 20;
					snowman_pos1.x = 400000000;
				}
			}

			if (collision.square_square(Snowman_Stage2[1], use_snowball[1]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp1 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos1.x;
				particlepos.y = snowman_pos1.y;

				if (snowman_hp1 < 0)
				{
					enemylive1 = false;
					snowman_hp1 = 20;
					snowman_pos1.x = 400000000;
				}
			}

			if (collision.square_square(Snowman_Stage2[1], use_snowball[2]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp1 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos1.x;
				particlepos.y = snowman_pos1.y;

				if (snowman_hp1 < 0)
				{
					enemylive1 = false;
					snowman_hp1 = 20;
					snowman_pos1.x = 400000000;
				}
			}

			// �Ⴞ��܂Q
			if (collision.square_square(Snowman_Stage2[2], use_snowball[0]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp2 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos2.x;
				particlepos.y = snowman_pos2.y;

				if (snowman_hp2 < 0)
				{
					enemylive2 = false;
					snowman_hp2 = 20;
					snowman_pos2.x = 400000000;
				}
			}

			if (collision.square_square(Snowman_Stage2[2], use_snowball[1]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp2 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos2.x;
				particlepos.y = snowman_pos2.y;

				if (snowman_hp2 < 0)
				{
					enemylive2 = false;
					snowman_hp2 = 20;
					snowman_pos2.x = 400000000;
				}
			}

			if (collision.square_square(Snowman_Stage2[2], use_snowball[2]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp2 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos2.x;
				particlepos.y = snowman_pos2.y;

				if (snowman_hp2 < 0)
				{
					enemylive2 = false;
					snowman_hp2 = 20;
					snowman_pos2.x = 400000000;
				}
			}

			// �Ⴞ���3
			if (collision.square_square(Snowman_Stage2[3], use_snowball[0]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp3 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos3.x;
				particlepos.y = snowman_pos3.y;

				if (snowman_hp3 < 0)
				{
					enemylive3 = false;
					snowman_hp3 = 20;
					snowman_pos3.x = 400000000;
				}
			}

			if (collision.square_square(Snowman_Stage2[3], use_snowball[1]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp3 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos3.x;
				particlepos.y = snowman_pos3.y;

				if (snowman_hp3 < 0)
				{
					enemylive3 = false;
					snowman_hp3 = 20;
					snowman_pos3.x = 400000000;
				}
			}

			if (collision.square_square(Snowman_Stage2[3], use_snowball[2]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp3 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos3.x;
				particlepos.y = snowman_pos3.y;

				if (snowman_hp3 < 0)
				{
					enemylive3 = false;
					snowman_hp3 = 20;
					snowman_pos3.x = 400000000;
				}
			}

			// �Ⴞ���3
			if (collision.square_square(Snowman_Stage2[4], use_snowball[0]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp4 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos4.x;
				particlepos.y = snowman_pos4.y;

				if (snowman_hp4 < 0)
				{
					enemylive4 = false;
					snowman_hp4 = 20;
					snowman_pos4.x = 400000000;
				}
			}

			if (collision.square_square(Snowman_Stage2[4], use_snowball[1]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp4 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos4.x;
				particlepos.y = snowman_pos4.y;

				if (snowman_hp4 < 0)
				{
					enemylive4 = false;
					snowman_hp4 = 20;
					snowman_pos4.x = 400000000;
				}
			}

			if (collision.square_square(Snowman_Stage2[4], use_snowball[2]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp4 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos4.x;
				particlepos.y = snowman_pos4.y;

				if (snowman_hp4 < 0)
				{
					enemylive4 = false;
					snowman_hp4 = 20;
					snowman_pos4.x = 400000000;
				}
			}

			// �N���X�}�X�c���[1
			if (collision.square_square(Star_Stage2[1], use_snowball[0]) == true) {
				star_monster_hp1 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = star_pos1.x;
				particlepos.y = star_pos1.y;
				if (star_monster_hp1 < 0)
				{
					enemylive5 = false;
					star_monster_hp1 = 40;
					star_pos1.x = 400000000;
				}
			}

			if (collision.square_square(Star_Stage2[1], use_snowball[1]) == true) {
				star_monster_hp1 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = star_pos1.x;
				particlepos.y = star_pos1.y;
				if (star_monster_hp1 < 0)
				{
					enemylive5 = false;
					star_monster_hp1 = 40;
					star_pos1.x = 400000000;
				}
			}

			if (collision.square_square(Star_Stage2[1], use_snowball[2]) == true) {
				star_monster_hp1 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = star_pos1.x;
				particlepos.y = star_pos1.y;
				if (star_monster_hp1 < 0)
				{
					enemylive5 = false;
					star_monster_hp1 = 40;
					star_pos1.x = 400000000;
				}
			}

			// �N���X�}�X�c���[2
			if (collision.square_square(Star_Stage2[2], use_snowball[0]) == true) {
				star_monster_hp2 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = star_pos2.x;
				particlepos.y = star_pos2.y;
				if (star_monster_hp2 < 0)
				{
					enemylive6 = false;
					star_monster_hp2 = 40;
					star_pos2.x = 400000000;
				}
			}

			if (collision.square_square(Star_Stage2[2], use_snowball[1]) == true) {
				star_monster_hp2 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = star_pos2.x;
				particlepos.y = star_pos2.y;
				if (star_monster_hp2 < 0)
				{
					enemylive6 = false;
					star_monster_hp2 = 40;
					star_pos2.x = 400000000;
				}
			}

			if (collision.square_square(Star_Stage2[2], use_snowball[2]) == true) {
				star_monster_hp2 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = star_pos2.x;
				particlepos.y = star_pos2.y;
				if (star_monster_hp2 < 0)
				{
					enemylive6 = false;
					star_monster_hp2 = 40;
					star_pos2.x = 400000000;
				}
			}

			// �g�i�J�C1
			if (collision.square_square(Tonakai_Stage2[1], use_snowball[0]) == true) {
				tonakai_hp1 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = tonakai_pos1.x;
				particlepos.y = tonakai_pos1.y;
				if (tonakai_hp1 < 0)
				{
					enemylive7 = false;
					tonakai_hp1 = 60;
					tonakai_pos1.x = 400000000;
				}
			}

			if (collision.square_square(Tonakai_Stage2[1], use_snowball[1]) == true) {
				tonakai_hp1 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = tonakai_pos1.x;
				particlepos.y = tonakai_pos1.y;
				if (tonakai_hp1 < 0)
				{
					enemylive7 = false;
					tonakai_hp1 = 60;
					tonakai_pos1.x = 400000000;
				}
			}

			if (collision.square_square(Tonakai_Stage2[1], use_snowball[2]) == true) {
				tonakai_hp1 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = tonakai_pos1.x;
				particlepos.y = tonakai_pos1.y;
				if (tonakai_hp1 < 0)
				{
					enemylive7 = false;
					tonakai_hp1 = 60;
					tonakai_pos1.x = 400000000;
				}
			}
			
			// �g�i�J�C2
			if (collision.square_square(Tonakai_Stage2[2], use_snowball[0]) == true) {
				tonakai_hp2 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = tonakai_pos2.x;
				particlepos.y = tonakai_pos2.y;
				if (tonakai_hp2 < 0)
				{
					enemylive8 = false;
					tonakai_hp2 = 60;
					tonakai_pos2.x = 400000000;
				}
			}

			if (collision.square_square(Tonakai_Stage2[2], use_snowball[1]) == true) {
				tonakai_hp2 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = tonakai_pos2.x;
				particlepos.y = tonakai_pos2.y;
				if (tonakai_hp2 < 0)
				{
					enemylive8 = false;
					tonakai_hp2 = 60;
					tonakai_pos2.x = 400000000;
				}
			}

			if (collision.square_square(Tonakai_Stage2[2], use_snowball[2]) == true) {
				tonakai_hp2 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = tonakai_pos2.x;
				particlepos.y = tonakai_pos2.y;
				if (tonakai_hp2 < 0)
				{
					enemylive8 = false;
					tonakai_hp2 = 60;
					tonakai_pos2.x = 400000000;
				}
			}

			//�p�[�e�B�N���A�j���[�V����
			if (particleFg)
			{
				particlecount++;
				if (particlecount % 5 == 0)
				{
					//particleFg = false;
					particle.numU++;
					if (particle.numU > 7)
					{
						particle.numU = 0;
						particleFg = false;
					}
				}

			}

			// �W�����v
			if (input.GetKeyTrigger(VK_SPACE) && jump == 0 || input.GetButtonTrigger(XINPUT_A) && jump == 0) {
				if (direction == 0) { // �E����
					if (bugPower == 0) {
						santaImage = 2;
						jump = 1;
						santa_Nor[2].numU = 0;
						santa_Nor[2].numV = 0;
					}
					else if (bugPower > 0) {
						santaImage = 3;
						jump = 2;
						santa_Nor[3].numU = 0;
						santa_Nor[3].numV = 0;
					}
					get_jump_old = santa_pos.y;
				}
				else if (direction == 1) { // �E����
					if (bugPower == 0) {
						santaImage = 2;
						jump = 1;
						santa_Nor[2].numU = 0;
						santa_Nor[2].numV = 1;
					}
					else if (bugPower > 0) {
						santaImage = 3;
						jump = 2;
						santa_Nor[3].numU = 0;
						santa_Nor[3].numV = 1;
					}
				}
				get_jump_old = santa_pos.y;
				jumpVelocity = 10.0f;
			}

			// �d��
			if (jump == 0) {
				santa_pos.y += jumpVelocity;
				//	 �d�͂𑬓x�ɓK�p
				jumpVelocity += gravity;
				/*santa_kin_pos.y -= 2.0f;*/
			}

			//�W�����v����
			if (jump == 1 || jump == 2) {

				if (santa_pos.y >= get_jump_old + 50.0f && jump == 1 || santa_pos.y >= get_jump_old + 50.0f && jump == 2) {
					jump = 3;
				}
				else if (santa_pos.y <= get_jump_old + 175.0f && jump == 1 || santa_pos.y <= get_jump_old + 175.0f && jump == 2) {
					/*santa_kin_pos.y += 7.50;*/
					santa_pos.y += jumpVelocity;
					//	 �d�͂𑬓x�ɓK�p
					jumpVelocity += gravity;
				}

			}
			if (jump == 3) {

				santa_pos.y += jumpVelocity;
				//	 �d�͂𑬓x�ɓK�p
				jumpVelocity += gravity;
				if (collision.ground_santa(Ground_Stge2[1], santa_Nor[0], 50.0f, 0.0f) == true ||
					collision.ground_santa(Ground_Stge2[2], santa_Nor[0], 50.0f, 0.0f) == true ||
					collision.ground_santa(Ground_Stge2[3], santa_Nor[0], 50.0f, 0.0f) == true ||
					collision.ground_santa(Ground_Stge2[4], santa_Nor[0], 50.0f, 0.0f) == true ||
					collision.ground_santa(Ground_Stge2[5], santa_Nor[0], 50.0f, 0.0f) == true ||
					collision.ground_santa(Ground_Stge2[6], santa_Nor[0], 50.0f, 0.0f) == true ||
					collision.ground_santa(Ground_Stge2[7], santa_Nor[0], 50.0f, 0.0f) == true ||
					collision.block_santa(Stairs_Stge2[1], santa_Nor[0], 100.0f, 0.0f) == true ||
					collision.block_santa(Stairs_Stge2[2], santa_Nor[0], 100.0f, 0.0f) == true ||
					collision.block_santa(Stairs_Stge2[3], santa_Nor[0], 100.0f, 0.0f) == true ||
					collision.block_santa(Stairs_Stge2[4], santa_Nor[0], 100.0f, 0.0f) == true ||
					collision.block_santa(Stairs_Stge2[5], santa_Nor[0], 100.0f, 0.0f) == true ||
					collision.tree_santa(tree, santa_Nor[0], 1000.0f, 0.0f) == true)
				{

					jump = 0;
					jumpVelocity = 0.0f;
				}
			}


			// �T���^���A�C�e���ɓ���������
			bool itemCollected = false; // �A�C�e�������ɉ�����ꂽ���ǂ����̃t���O


			const float rightScreen = 670.0f; // ��ʂ̉E�[
			const float leftScreen = -670.0f; // ��ʂ̍��[


			if (collision.item_santa(Collectrock_Stage2[1], santa_Nor[0], 100.0f, 0.0f) && rock_visible1 == 0)
			{

				if (input.GetKeyTrigger(VK_S) && !itemCollected && !sp_ani || input.GetButtonTrigger(XINPUT_B) && !itemCollected && !sp_ani)
				{

					item->ItemGet(1); // ��������
					bugPower = item->GetItemCnt(); // ���݂̑܂̃A�C�e��������
					itemCollected = true;
					santaImage = 4;

					rock_visible1 = 1;

				}

				//if (input.GetKeyTrigger(VK_S) && !itemCollected || input.GetButtonTrigger(XINPUT_B) && !itemCollected)
				//{
				//	/*itemID = 1;*/
				//	item->ItemGet(1); // ��������
				//	bugPower = item->GetItemCnt(); // ���݂̑܂̃A�C�e��������
				//	itemCollected = true;

				//	rock_visible1 = 1;

				//}
			}

			if (collision.item_santa(Collectrock_Stage2[2], santa_Nor[0], 100.0f, 0.0f) && rock_visible2 == 0)
			{
				if (input.GetKeyTrigger(VK_S) && !itemCollected && !sp_ani || input.GetButtonTrigger(XINPUT_B) && !itemCollected && !sp_ani)
				{

					item->ItemGet(1); // ��������
					bugPower = item->GetItemCnt(); // ���݂̑܂̃A�C�e��������
					itemCollected = true;
					santaImage = 4;

					rock_visible2 = 1;

				}
			}

			if (collision.item_santa(Collectrock_Stage2[3], santa_Nor[0], 100.0f, 0.0f) && rock_visible3 == 0)
			{
				if (input.GetKeyTrigger(VK_S) && !itemCollected && !sp_ani || input.GetButtonTrigger(XINPUT_B) && !itemCollected && !sp_ani)
				{

					item->ItemGet(1); // ��������
					bugPower = item->GetItemCnt(); // ���݂̑܂̃A�C�e��������
					itemCollected = true;
					santaImage = 4;

					rock_visible3 = 1;

				}
			}

			if (collision.item_santa(Collectrock_Stage2[4], santa_Nor[0], 100.0f, 0.0f) && rock_visible4 == 0)
			{
				if (input.GetKeyTrigger(VK_S) && !itemCollected && !sp_ani || input.GetButtonTrigger(XINPUT_B) && !itemCollected && !sp_ani)
				{

					item->ItemGet(1); // ��������
					bugPower = item->GetItemCnt(); // ���݂̑܂̃A�C�e��������
					itemCollected = true;
					santaImage = 4;

					rock_visible4 = 1;

				}
			}

			if (collision.item_santa(Collectrock_Stage2[5], santa_Nor[0], 100.0f, 0.0f) && rock_visible5 == 0)
			{
				if (input.GetKeyTrigger(VK_S) && !itemCollected && !sp_ani || input.GetButtonTrigger(XINPUT_B) && !itemCollected && !sp_ani)
				{

					item->ItemGet(1); // ��������
					bugPower = item->GetItemCnt(); // ���݂̑܂̃A�C�e��������
					itemCollected = true;
					santaImage = 4;

					rock_visible5 = 1;

				}
			}

			if (collision.item_santa(Collectrock_Stage2[6], santa_Nor[0], 100.0f, 0.0f) && rock_visible6 == 0)
			{
				if (input.GetKeyTrigger(VK_S) && !itemCollected || input.GetButtonTrigger(XINPUT_B) && !itemCollected)
				{
					if (input.GetKeyTrigger(VK_S) && !itemCollected && !sp_ani || input.GetButtonTrigger(XINPUT_B) && !itemCollected && !sp_ani)
					{

						item->ItemGet(1); // ��������
						bugPower = item->GetItemCnt(); // ���݂̑܂̃A�C�e��������
						itemCollected = true;
						santaImage = 4;

						rock_visible6 = 1;

					}
				}
			}

			if (collision.item_santa(Snowball_Stage2[1], santa_Nor[0], 100.0f, 0.0f) && snow_visible1 == 0)
			{
				if (input.GetKeyTrigger(VK_S) && !itemCollected && !sp_ani || input.GetButtonTrigger(XINPUT_B) && !itemCollected && !sp_ani)
				{
					/*itemID = 1;*/
					item->ItemGet(2); // ��������
					bugPower = item->GetItemCnt(); // ���݂̑܂̃A�C�e��������
					itemCollected = true;
					santaImage = 4;

					snow_visible1 = 1;
				}
			}

			if (collision.item_santa(Snowball_Stage2[2], santa_Nor[0], 100.0f, 0.0f) && snow_visible1 == 0)
			{
				if (input.GetKeyTrigger(VK_S) && !itemCollected && !sp_ani || input.GetButtonTrigger(XINPUT_B) && !itemCollected && !sp_ani)
				{
					/*itemID = 1;*/
					item->ItemGet(2); // ��������
					bugPower = item->GetItemCnt(); // ���݂̑܂̃A�C�e��������
					itemCollected = true;
					santaImage = 4;

					snow_visible2 = 1;
				}
			}

			if (collision.item_santa(Snowball_Stage2[3], santa_Nor[0], 100.0f, 0.0f) && snow_visible1 == 0)
			{
				if (input.GetKeyTrigger(VK_S) && !itemCollected && !sp_ani || input.GetButtonTrigger(XINPUT_B) && !itemCollected && !sp_ani)
				{
					/*itemID = 1;*/
					item->ItemGet(2); // ��������
					bugPower = item->GetItemCnt(); // ���݂̑܂̃A�C�e��������
					itemCollected = true;
					santaImage = 4;

					snow_visible3 = 1;
				}
			}

			// ��ʊO�ɍs���ƁA�A�C�e�����ăX�|�[�����鏈��
			if (leftScreen > rock_pos1.x || rock_pos1.x > rightScreen) {
				rock_visible1 = 0;
			}
			if (leftScreen > rock_pos2.x || rock_pos2.x > rightScreen) {
				rock_visible2 = 0;
			}
			if (leftScreen > rock_pos3.x || rock_pos3.x > rightScreen) {
				rock_visible3 = 0;
			}
			if (leftScreen > rock_pos4.x || rock_pos4.x > rightScreen) {
				rock_visible4 = 0;
			}
			if (leftScreen > rock_pos5.x || rock_pos5.x > rightScreen) {
				rock_visible5 = 0;
			}
			if (leftScreen > rock_pos6.x || rock_pos6.x > rightScreen) {
				rock_visible6 = 0;
			}
			if (leftScreen > snowball_pos1.x || snowball_pos1.x > rightScreen) {
				snow_visible1 = 0;
			}
			if (leftScreen > snowball_pos2.x || snowball_pos2.x > rightScreen) {
				snow_visible2 = 0;
			}
			if (leftScreen > snowball_pos3.x || snowball_pos3.x > rightScreen) {
				snow_visible3 = 0;
			}


			if (!itemCollected && !changeItem) {// �������ĂȂ��ꍇ
				if (input.GetKeyTrigger(VK_S) && pauseFg == false || input.GetButtonTrigger(XINPUT_B) && pauseFg == false)
				{

					if (item->GetItem_3() > 0) {
						changeItem = true;

						if (item->GetItem_3() == 1) {
							use_rock_pos3.x = santa_pos.x;
							use_rock_pos3.y = santa_pos.y;
							sound.Play(SOUND_LABEL_SE004);
							itemID_3 = 1;
							itemMove3 = true;
						}
						else if (item->GetItem_3() == 2) {
							use_snowball_pos3.x = santa_pos.x;
							use_snowball_pos3.y = santa_pos.y;
							sound.Play(SOUND_LABEL_SE002);
							itemID_3 = 2;
							itemMove3 = true;
						}

					}
					else if (item->GetItem_3() < 0) {

						if (item->GetItem_2() > 0) {

							if (item->GetItem_2() == 1) {
								use_rock_pos2.x = santa_pos.x;
								use_rock_pos2.y = santa_pos.y;
								sound.Play(SOUND_LABEL_SE004);
								itemID_2 = 1;
								itemMove2 = true;
							}
							else if (item->GetItem_2() == 2) {
								use_snowball_pos2.x = santa_pos.x;
								use_snowball_pos2.y = santa_pos.y;
								sound.Play(SOUND_LABEL_SE004);
								itemID_2 = 2;
								itemMove2 = true;
							}

						}
						else if (item->GetItem_2() < 0) {

							if (item->GetItem_1() > 0) {

								if (item->GetItem_1() == 1) {
									use_rock_pos1.x = santa_pos.x;
									use_rock_pos1.y = santa_pos.y;
									itemID_1 = 1;
									itemMove1 = true;
								}
								else if (item->GetItem_1() == 2) {
									use_snowball_pos1.x = santa_pos.x;
									use_snowball_pos1.y = santa_pos.y;
									itemID_1 = 2;
									itemMove1 = true;
								}

							}
						}
					}


					item->ItemRelease(); // ���o��
					bugPower = item->GetItemCnt();
				}
			}




			if (collision.enemy_santa(Icicles_Stge2[1], santa_Nor[0], 200.0f, 0.0f) && HitFg == false && turarafall1 == true)
			{
				time -= 5;
				hitcooltime = 0;
				sound.Play(SOUND_LABEL_SE000);
				damage5 = true;
				HitFg = true;
			}

			if (collision.enemy_santa(Icicles_Stge2[2], santa_Nor[0], 200.0f, 0.0f) && HitFg == false && turarafall3 == true)
			{
				time -= 5;
				hitcooltime = 0;
				sound.Play(SOUND_LABEL_SE000);
				damage5 = true;
				HitFg = true;
			}

			if (collision.enemy_santa(Icicles_Stge2[3], santa_Nor[0], 200.0f, 0.0f) && HitFg == false && turarafall3 == true)
			{
				time -= 5;
				hitcooltime = 0;
				sound.Play(SOUND_LABEL_SE000);
				damage5 = true;
				HitFg = true;
			}

			if (!itemCollected && !changeItem) {// �������ĂȂ��ꍇ
				if (input.GetKeyTrigger(VK_S) && pauseFg == false && !sp_ani || input.GetButtonTrigger(XINPUT_B) && pauseFg == false && !sp_ani)
				{

					if (item->GetItem_3() > 0) {
						changeItem = true;

						if (item->GetItem_3() == 1) {
							use_rock_pos3.x = santa_pos.x;
							use_rock_pos3.y = santa_pos.y;
							sound.Play(SOUND_LABEL_SE003);
							itemID_3 = 1;
							itemMove3 = true;
						}
						else if (item->GetItem_3() == 2) {
							use_snowball_pos3.x = santa_pos.x;
							use_snowball_pos3.y = santa_pos.y;
							sound.Play(SOUND_LABEL_SE003);
							itemID_3 = 2;
							itemMove3 = true;
						}

					}
					else if (item->GetItem_3() < 0) {

						if (item->GetItem_2() > 0) {

							if (item->GetItem_2() == 1) {
								use_rock_pos2.x = santa_pos.x;
								use_rock_pos2.y = santa_pos.y;
								sound.Play(SOUND_LABEL_SE003);
								itemID_2 = 1;
								itemMove2 = true;
							}
							else if (item->GetItem_2() == 2) {
								use_snowball_pos2.x = santa_pos.x;
								use_snowball_pos2.y = santa_pos.y;
								sound.Play(SOUND_LABEL_SE003);
								itemID_2 = 2;
								itemMove2 = true;
							}

						}
						else if (item->GetItem_2() < 0) {

							if (item->GetItem_1() > 0) {

								if (item->GetItem_1() == 1) {
									use_rock_pos1.x = santa_pos.x;
									use_rock_pos1.y = santa_pos.y;
									itemID_1 = 1;
									itemMove1 = true;
								}
								else if (item->GetItem_1() == 2) {
									use_snowball_pos1.x = santa_pos.x;
									use_snowball_pos1.y = santa_pos.y;
									itemID_1 = 2;
									itemMove1 = true;
								}

							}
						}
					}

					santaImage = 5;
					item->ItemRelease(); // ���o��
					bugPower = item->GetItemCnt();
				}
			}


			// ����A�j���[�V����
			if (santaImage == 4) {
				getItem = 1;
				if (direction == 0) { // �E����
					if (changeRight_get == true)
					{
						//������
						santa_Nor[4].numU = 0;
						santa_Nor[4].numV = 0;
						changeRight_get = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���
					}
					framcount4++; //�t���[���J�E���g
					if (framcount4 % 4 == 0) //�P�O�t���[���Ɉ��s����
					{
						santa_Nor[4].numU++;
						if (santa_Nor[4].numU >= 5)
						{
							sp_ani = false;
							santaImage = 1;
							getItem = 0;
							santa_Nor[4].numU = 0;

						}
					}
				}
				else if (direction == 1) {
					if (changeLeft_get == true)
					{
						//������
						santa_Nor[4].numU = 0;
						santa_Nor[4].numV = 1;
						changeLeft_get = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���
					}
					framcount4++; //�t���[���J�E���g
					if (framcount4 % 4 == 0) //�P�O�t���[���Ɉ��s����
					{
						santa_Nor[4].numU++;
						if (santa_Nor[4].numU >= 5)
						{
							sp_ani = false;
							santaImage = 1;
							getItem = 0;
							santa_Nor[4].numU = 0;

						}
					}
				}
			}

			// ��o�A�j���[�V����
			if (santaImage == 5) {

				if (direction == 0) { // �E����
					if (changeRight_out == true)
					{
						//������
						santa_Nor[5].numU = 0;
						santa_Nor[5].numV = 0;
						changeRight_out = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���
					}
					framcount5++; //�t���[���J�E���g
					if (framcount5 % 4 == 0) //�P�O�t���[���Ɉ��s����
					{
						santa_Nor[5].numU++;
						if (santa_Nor[5].numU >= 5)
						{
							sp_ani = false;
							if (bugPower > 0) {
								santaImage = 1;
							}
							else if (bugPower == 0) {
								santaImage = 0;
							}

							santa_Nor[5].numU = 0;
							changeRight_out = true;

						}
					}
				}
				else if (direction == 1) {
					if (changeLeft_out == true)
					{
						//������
						santa_Nor[5].numU = 0;
						santa_Nor[5].numV = 1;
						changeLeft_out = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���
					}
					framcount5++; //�t���[���J�E���g
					if (framcount5 % 4 == 0) //�P�O�t���[���Ɉ��s����
					{
						santa_Nor[5].numU++;
						if (santa_Nor[5].numU >= 5)
						{
							sp_ani = false;
							if (bugPower > 0) {
								santaImage = 1;
							}
							else if (bugPower == 0) {
								santaImage = 0;
							}
							santa_Nor[5].numU = 0;
							changeLeft_out = true;

						}
					}
				}
			}



			// �������̓����@���̇@ 
			if (itemMove1 == true) {
				if (direction == 0) { // �E����

					if (itemID_1 == 1) { // ��

						if (itemMove1_M == true || use_rock_pos1.y >= -100.0f) {
							itemMove1_M = true;
							use_rock_pos1.y -= 3.00f;
							use_rock_pos1.x += 3.00f;
						}
						else if (itemMove1_M == false) {
							use_rock_pos1.y += 3.00f;
							use_rock_pos1.x += 3.00f;
						}
						if (use_rock_pos1.y <= -190.0f && itemMove1_M == true) {
							itemID_1 = 0;
							itemMove1_M = false;
							itemMove1 = false;
						}
					}
					else if (itemID_1 == 2) {
						if (use_snowball_pos1.x >= rightScreen) {
							itemID_1 = 0;
							itemMove1 = false;
						}
						else if (use_snowball_pos1.x <= rightScreen) {
							use_snowball_pos1.x += 20.00f;
						}
					}
				}
				else if (direction == 1) { // ������

					if (itemID_1 == 1) { // ��

						if (itemMove1_M == true || use_rock_pos1.y >= -100.0f) {
							itemMove1_M = true;
							use_rock_pos1.y -= 3.00f;
							use_rock_pos1.x -= 3.00f;
						}
						else if (itemMove1_M == false) {
							use_rock_pos1.y += 3.00f;
							use_rock_pos1.x -= 3.00f;
						}
						if (use_rock_pos1.y <= -190.0f && itemMove1_M == true) {
							itemID_1 = 0;
							itemMove1_M = false;
							itemMove1 = false;
						}
					}
					else if (itemID_1 == 2) {
						if (use_snowball_pos1.x <= leftScreen) {
							itemID_1 = 0;
							itemMove1 = false;
						}
						else if (use_snowball_pos1.x >= leftScreen) {
							use_snowball_pos1.x -= 20.00f;
						}
					}
				}



			}

			// �������̓����@���̇A
			if (itemMove2 == true) {
				if (direction == 0) { // �E����

					if (itemID_2 == 1) { //��

						if (itemMove2_M == true || use_rock_pos2.y >= -100.0f) {
							itemMove2_M = true;
							use_rock_pos2.y -= 3.00f;
							use_rock_pos2.x += 3.00f;
						}
						else if (itemMove2_M == false) {
							use_rock_pos2.y += 3.00f;
							use_rock_pos2.x += 3.00f;
						}
						if (use_rock_pos2.y <= -190.0f && itemMove2_M == true) {
							itemID_2 = 0;
							itemMove2_M = false;
							itemMove2 = false;
						}
					}
					else if (itemID_2 == 2) {
						if (use_snowball_pos2.x >= rightScreen) {
							itemID_2 = 0;
							itemMove2 = false;
						}
						else if (use_snowball_pos2.x <= rightScreen) {
							use_snowball_pos2.x += 20.00f;
						}
					}
				}
				else if (direction == 1) { // ������

					if (itemID_2 == 1) { //��

						if (itemMove2_M == true || use_rock_pos2.y >= -100.0f) {
							itemMove2_M = true;
							use_rock_pos2.y -= 3.00f;
							use_rock_pos2.x -= 3.00f;
						}
						else if (itemMove2_M == false) {
							use_rock_pos2.y += 3.00f;
							use_rock_pos2.x -= 3.00f;
						}
						if (use_rock_pos2.y <= -190.0f && itemMove2_M == true) {
							itemID_2 = 0;
							itemMove2_M = false;
							itemMove2 = false;
						}
					}
					else if (itemID_2 == 2) {
						if (use_snowball_pos2.x <= leftScreen) {
							itemID_2 = 0;
							itemMove2 = false;
						}
						else if (use_snowball_pos2.x >= leftScreen) {
							use_snowball_pos2.x -= 20.00f;
						}
					}
				}


			}

			// �������̓����@���̇B
			if (itemMove3 == true) {

				if (direction == 0) { // �E����

					if (itemID_3 == 1) { // ��

						if (itemMove3_M == true || use_rock_pos3.y >= -100.0f) {
							itemMove3_M = true;
							use_rock_pos3.y -= 3.00f;
							use_rock_pos3.x += 3.00f;
						}
						else if (itemMove3_M == false) {
							use_rock_pos3.y += 3.00f;
							use_rock_pos3.x += 3.00f;
						}
						if (use_rock_pos3.y <= -190.0f && itemMove3_M == true) {
							itemID_3 = 0;
							itemMove3_M = false;
							itemMove3 = false;
							changeItem = false;
						}
					}
					else if (itemID_3 == 2) {
						if (use_snowball_pos3.x >= rightScreen) {
							itemID_3 = 0;
							itemMove3 = false;
							changeItem = false;
						}
						else if (use_snowball_pos3.x <= rightScreen) {
							use_snowball_pos3.x += 30.00f;
						}
					}
				}
				else if (direction == 1) { // ������

					if (itemID_3 == 1) { // ��

						if (itemMove3_M == true || use_rock_pos3.y >= -100.0f) {
							itemMove3_M = true;
							use_rock_pos3.y -= 3.00f;
							use_rock_pos3.x -= 3.00f;
						}
						else if (itemMove3_M == false) {
							use_rock_pos3.y += 3.00f;
							use_rock_pos3.x -= 3.00f;
						}
						if (use_rock_pos3.y <= -190.0f && itemMove3_M == true) {
							itemID_3 = 0;
							itemMove3_M = false;
							itemMove3 = false;
							changeItem = false;
						}
					}
					else if (itemID_3 == 2) {
						if (use_snowball_pos3.x <= leftScreen) {
							itemID_3 = 0;
							itemMove3 = false;
							changeItem = false;
						}
						else if (use_snowball_pos3.x >= leftScreen) {
							use_snowball_pos3.x -= 30.00f;
						}
					}
				}


			}


			//�ړ����x
			if (bugPower == 0) { // �܂���̎�

				speed = 9;
			}
			else {

				speed = 7;
			}

			// �ŗL�\�͔����I�I�I�I�I�I�I
			if (bugPower > 0 && sp_ani == false && input.GetKeyPress(VK_Q)
				|| input.GetButtonTrigger(XINPUT_X) && bugPower > 0 && sp_ani == false) { // �܂�����ۂ̎�

				sp_ani = true;

			}

			if (sp_ani == true) {

				santaImage = 7;

				if (direction == 0) {

					// �З͎�
					if (bugPower == 1) {
						if (changeRight_SP == true)
						{
							//������
							santa_Nor[7].numU = 0;
							santa_Nor[7].numV = 0;
							attackhit = false;
							changeRight_SP = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���
						}
						framcount7++; //�t���[���J�E���g
						if (framcount7 % 4 == 0) //�P�O�t���[���Ɉ��s����
						{
							santa_Nor[7].numU++;

							if (santa_Nor[7].numU == 2)
							{
								attackhit = true;
							}


							if (santa_Nor[7].numU >= 5)
							{

								sp_ani = false;
								santaImage = 1;
								santa_Nor[7].numU = 0;
								changeLeft_SP = true;
								santaatack = 0;
								attackhit = true;

							}
						}
					}
					// �З͒�
					else if (bugPower == 2) {
						if (changeRight_SP == true)
						{
							//������
							santa_Nor[7].numU = 0;
							santa_Nor[7].numV = 0;
							attackhit = false;
							changeRight_SP = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���
						}
						framcount7++; //�t���[���J�E���g
						if (framcount7 % 7 == 0) //�P�O�t���[���Ɉ��s����
						{
							santa_Nor[7].numU++;
							if (santa_Nor[7].numU == 2)
							{
								attackhit = true;
							}

							if (santa_Nor[7].numU >= 5)
							{
								sp_ani = false;
								santaImage = 1;
								santa_Nor[7].numU = 0;
								attackhit = true;
								changeLeft_SP = true;
							}
						}
					}
					// �З͋�
					else if (bugPower == 3) {
						if (changeRight_SP == true)
						{
							//������
							santa_Nor[7].numU = 0;
							santa_Nor[7].numV = 0;
							attackhit = false;
							changeRight_SP = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���
						}
						framcount7++; //�t���[���J�E���g
						if (framcount7 % 10 == 0) //�P�O�t���[���Ɉ��s����
						{
							santa_Nor[7].numU++;
							if (santa_Nor[7].numU == 2)
							{
								attackhit = true;
							}
							if (santa_Nor[7].numU >= 5)
							{
								sp_ani = false;
								santaImage = 1;
								santa_Nor[7].numU = 0;
								attackhit = true;
								changeLeft_SP = true;
							}
						}
					}
				}
				if (direction == 1) {

					// �З͎�
					if (bugPower == 1) {
						if (changeRight_SP == true)
						{
							//������
							santa_Nor[7].numU = 0;
							santa_Nor[7].numV = 1;
							attackhit = false;
							changeRight_SP = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���
						}
						framcount7++; //�t���[���J�E���g
						if (framcount7 % 4 == 0) //�P�O�t���[���Ɉ��s����
						{
							santa_Nor[7].numU++;
							if (santa_Nor[7].numU == 2)
							{
								attackhit = true;
							}

							if (santa_Nor[7].numU >= 5)
							{
								sp_ani = false;
								santaImage = 1;
								santa_Nor[7].numU = 0;
								attackhit = false;
								changeRight_SP = true;

							}
						}
					}
					// �З͒�
					else if (bugPower == 2) {
						if (changeRight_SP == true)
						{
							//������
							santa_Nor[7].numU = 0;
							santa_Nor[7].numV = 1;
							attackhit = false;
							changeRight_SP = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���
						}
						framcount7++; //�t���[���J�E���g
						if (framcount7 % 7 == 0) //�P�O�t���[���Ɉ��s����
						{
							santa_Nor[7].numU++;
							if (santa_Nor[7].numU == 2)
							{
								attackhit = true;
							}

							if (santa_Nor[7].numU >= 5)
							{
								sp_ani = false;
								santaImage = 1;
								santa_Nor[7].numU = 0;
								attackhit = true;
								changeRight_SP = true;
							}
						}
					}
					// �З͋�
					else if (bugPower == 3) {
						if (changeRight_SP == true)
						{
							//������
							santa_Nor[7].numU = 0;
							santa_Nor[7].numV = 1;
							attackhit = false;
							changeRight_SP = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���
						}
						framcount7++; //�t���[���J�E���g
						if (framcount7 % 10 == 0) //�P�O�t���[���Ɉ��s����
						{
							santa_Nor[7].numU++;
							if (santa_Nor[7].numU == 2)
							{
								attackhit = true;
							}

							if (santa_Nor[7].numU >= 5)
							{
								sp_ani = false;
								santaImage = 1;
								santa_Nor[7].numU = 0;

								changeRight_SP = true;
							}
						}
					}
				}

			}
			else
			{
				attackhit = false;
			}


			//�U��
			if (attackhit==true)
			{
				if (collision.enemy_santa(Snowman_Stage2[1], hitbox2, 100.0f, 100.0f) && HitFg == false && pauseFg == false && gameoverFg == false)
				{
					sound.Play(SOUND_LABEL_SE004);
					snowman_hp1 -= santa_atk;

					particleFg = true;
					particlepos.x = snowman_pos1.x;
					particlepos.y = snowman_pos1.y;

					if (snowman_hp1 < 0)
					{
						enemylive1 = false;
						snowman_hp1 = 20;
						snowman_pos1.x = 400000000;
					}
				}

				if (collision.enemy_santa(Snowman_Stage2[2], hitbox2, 100.0f, 100.0f) && HitFg == false && pauseFg == false && gameoverFg == false)
				{
					snowman_hp2 -= santa_atk;
					sound.Play(SOUND_LABEL_SE004);
					particleFg = true;
					particlepos.x = snowman_pos2.x;
					particlepos.y = snowman_pos2.y;
					if (snowman_hp2 < 0)
					{

						enemylive2 = false;
						snowman_hp2 = 20;
						snowman_pos2.x = 400000000;
					}

				}

				if (collision.enemy_santa(Snowman_Stage2[3], hitbox2, 100.0f, 100.0f) && HitFg == false && pauseFg == false && gameoverFg == false)
				{
					snowman_hp3 -= santa_atk;
					sound.Play(SOUND_LABEL_SE004);
					particleFg = true;
					particlepos.x = snowman_pos3.x;
					particlepos.y = snowman_pos3.y;
					if (snowman_hp3 < 0)
					{
						enemylive3 = false;
						snowman_hp3 = 20;
						snowman_pos3.x = 400000000;
					}
				}

				if (collision.enemy_santa(Snowman_Stage2[4], hitbox2, 100.0f, 100.0f) && HitFg == false && pauseFg == false && gameoverFg == false)
				{
					snowman_hp4 -= santa_atk;
					sound.Play(SOUND_LABEL_SE004);
					particleFg = true;
					particlepos.x = snowman_pos4.x;
					particlepos.y = snowman_pos4.y;
					if (snowman_hp4 < 0)
					{
						enemylive4 = false;
						snowman_hp4 = 20;
						snowman_pos4.x = 400000000;
					}
				}

				//��
				if (collision.enemy_santa(Star_Stage2[1], hitbox2, 50.0f, 50.0f) && HitFg == false && pauseFg == false && gameoverFg == false)
				{
					star_monster_hp1 -= santa_atk;
					sound.Play(SOUND_LABEL_SE004);
					particleFg = true;
					particlepos.x = star_pos1.x;
					particlepos.y = star_pos1.y;
					if (star_monster_hp1 < 0)
					{
						enemylive5 = false;
						star_monster_hp1 = 40;
						star_pos1.x = 400000000;
					}
				}

				//��
				if (collision.enemy_santa(Star_Stage2[2], hitbox2, 50.0f, 50.0f) && HitFg == false && pauseFg == false && gameoverFg == false)
				{
					star_monster_hp2 -= santa_atk;
					sound.Play(SOUND_LABEL_SE004);
					particleFg = true;
					particlepos.x = star_pos2.x;
					particlepos.y = star_pos2.y;
					if (star_monster_hp2 < 0)
					{
						enemylive6 = false;
						star_monster_hp2 = 40;
						star_pos1.x = 400000000;
					}
				}

				//�ƂȂ���
				if (collision.enemy_santa(Tonakai_Stage2[1], hitbox2, 50.0f, 50.0f) && HitFg == false && pauseFg == false && gameoverFg == false)
				{
					tonakai_hp1 -= santa_atk;
					sound.Play(SOUND_LABEL_SE004);
					particleFg = true;
					particlepos.x = tonakai_pos1.x;
					particlepos.y = tonakai_pos1.y;
					if (tonakai_hp1 < 0)
					{
						enemylive7 = false;
						tonakai_hp1 = 60;
						tonakai_pos1.x = 400000000;
					}
				}

				if (collision.enemy_santa(Tonakai_Stage2[2], hitbox2, 50.0f, 50.0f) && HitFg == false && pauseFg == false && gameoverFg == false)
				{
					tonakai_hp2 -= santa_atk;
					sound.Play(SOUND_LABEL_SE004);
					particleFg = true;
					particlepos.x = tonakai_pos2.x;
					particlepos.y = tonakai_pos2.y;
					if (tonakai_hp2 < 0)
					{
						enemylive8 = false;
						tonakai_hp2 = 60;
						tonakai_pos2.x = 400000000;
					}
				}

				if (bugPower >= 2)
				{
					if (collision.tree_santa(Breakrock_Stge2[1], hitbox2, 50.0f, 50.0f) && HitFg == false && pauseFg == false && gameoverFg == false)
					{

						rocklive = false;

						breakrock_pos1.x = 400000000;
						moji_pos.x = 400000000;
					}
				}
				

			}
			//�p�[�e�B�N���A�j���[�V����
			if (particleFg)
			{
				particlecount++;
				if (particlecount % 5 == 0)
				{
					//particleFg = false;
					particle.numU++;
					if (particle.numU > 7)
					{
						particle.numU = 0;
						particleFg = false;
					}
				}

			}

			
			//�E�ړ�
			if (sp_ani == false && gameoverFg == false && collision.canMoveRight && input.GetKeyPress(VK_D) && pauseFg == false
				|| gameoverFg == false && collision.canMoveRight && input.GetLeftAnalogStick().x >= 0.1 && pauseFg == false)
			{
				direction = 0; // ����
				santa_pos.x += 5;//�E�ړ�


				if (bugPower == 0) {
					santaImage = 6;
					if (changeRight_SP_1 == true)
					{
						//������
						santa_Nor[6].numU = 0;
						santa_Nor[6].numV = 0;
						changeRight_SP_1 = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���
					}
					framcount6++; //�t���[���J�E���g
					if (framcount6 % 4 == 0) //�P�O�t���[���Ɉ��s����
					{
						santa_Nor[6].numU++;
						if (santa_Nor[6].numU >= 4)
						{
							santa_Nor[6].numU = 0;

						}
					}

				}
				else if (bugPower > 0) {
					santaImage = 1;
					if (changeRight == true)
					{
						//������
						santa_Nor[1].numU = 0;
						santa_Nor[1].numV = 0;
						changeRight = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���
					}
					framcount++; //�t���[���J�E���g
					if (framcount % 10 == 0) //�P�O�t���[���Ɉ��s����
					{
						santa_Nor[1].numU++;
						if (santa_Nor[1].numU >= 4)
						{
							santa_Nor[1].numU = 0;
							santa_Nor[1].numV++;
							if (santa_Nor[1].numV >= 2)
							{
								santa_Nor[1].numV = 0;
							}
						}
					}

				}

				if (santa_pos.x >= 0) //�v���C���[����ʐ^�񒆂ɍs�����Ƃ�
				{
					santa_pos.x -= 5;

					//�w�i�Ȃǂ����ɓ������ăv���C���[���E�ɓ����Ă�悤�Ɍ�����
					//�R
					mounten_pos1.x -= speed - 4.5;
					mounten_pos2.x -= speed - 4.5;
					mounten_pos3.x -= speed - 4.5;
					mounten_pos4.x -= speed - 4.5;
					//�n��
					ground_pos1.x -= speed;
					ground_pos2.x -= speed;
					ground_pos3.x -= speed;
					ground_pos4.x -= speed;
					ground_pos5.x -= speed;
					ground_pos6.x -= speed;
					ground_pos7.x -= speed;
					//��
					tree_pos1.x -= speed;
					tree_pos2.x -= speed;
					//����
					block_pos1.x -= speed;
					//���
					icicle_pos1.x -= speed;
					icicle_pos2.x -= speed;
					icicle_pos3.x -= speed;
					//�K�i
					stairs_pos1.x -= speed;
					stairs_pos2.x -= speed;
					stairs_pos3.x -= speed;
					stairs_pos4.x -= speed;
					stairs_pos5.x -= speed;

					//�v���[���g
					present_pos1.x -= speed;
					present_pos2.x -= speed;
					present_pos3.x -= speed;

					bigpresent_pos1.x -= speed;
					//�󂹂��
					breakrock_pos1.x -= speed;
					moji_pos.x -= speed;
					//�����
					rock_pos1.x -= speed;
					rock_pos2.x -= speed;
					rock_pos3.x -= speed;
					rock_pos4.x -= speed;
					rock_pos5.x -= speed;
					rock_pos6.x -= speed;

					//������
					snowball_pos1.x -= speed;
					snowball_pos2.x -= speed;
					snowball_pos3.x -= speed;

					//�G
					snowman_pos1.x -= speed;
					snowman_pos2.x -= speed;
					snowman_pos3.x -= speed;
					snowman_pos4.x -= speed;

					star_pos1.x -= speed;
					star_pos2.x -= speed;

					tonakai_pos1.x -= speed;
					tonakai_pos2.x -= speed;

					wall_pos1.x -= speed;
					wall_pos2.x -= speed;

					goal_pos.x -= speed;

				}
			}
			else
			{
				//�L�[�𗣂���true�ɖ߂�
				if (sp_ani == false && changeRight_SP_1 == false) {

					santa_Nor[0].numU = 0;
					santa_Nor[0].numV = 0;
					santa_Nor[1].numU = 0;
					santa_Nor[1].numV = 0;
					if (bugPower > 0) {
						santaImage = 1;
					}
					else if (bugPower == 0) {
						santaImage = 0;
					}

				}

				changeRight = true;
				changeRight_SP_1 = true;
			}
			//���ړ�
			if (sp_ani == false && gameoverFg == false && collision.canMoveLeft && input.GetKeyPress(VK_A) && pauseFg == false
				|| gameoverFg == false && collision.canMoveLeft && input.GetLeftAnalogStick().x <= -0.1 && pauseFg == false)
			{

				direction = 1; // ����
				santa_pos.x -= 5;//���ړ�


				if (bugPower == 0) {

					santaImage = 6;
					if (changeLeft_SP_1 == true)
					{
						//������
						santa_Nor[6].numU = 0;
						santa_Nor[6].numV = 1;
						changeLeft_SP_1 = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���
					}
					framcount6++; //�t���[���J�E���g
					if (framcount6 % 4 == 0) //�P�O�t���[���Ɉ��s����
					{
						santa_Nor[6].numU++;
						if (santa_Nor[6].numU >= 4)
						{

							santa_Nor[6].numU = 0;

						}
					}
				}
				else if (bugPower > 0) {

					if (changeLeft == true)
					{
						//������
						santa_Nor[1].numU = 0;
						santa_Nor[1].numV = 2;
						changeLeft = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���
					}
					framcount++; //�t���[���J�E���g
					if (framcount % 10 == 0) //�P�O�t���[���Ɉ��s����
					{
						santa_Nor[1].numU++;
						if (santa_Nor[1].numU >= 4)
						{
							santa_Nor[1].numU = 0;
							santa_Nor[1].numV++;
							if (santa_Nor[1].numV >= 4)
							{
								santa_Nor[1].numV = 2;
							}
						}
					}
				}

				if (santa_pos.x <= 0) //�v���C���[����ʐ^�񒆂ɍs�����Ƃ�
				{
					santa_pos.x += 5;

					//�w�i�Ȃǂ����ɓ������ăv���C���[���E�ɓ����Ă�悤�Ɍ�����
					//�R
					mounten_pos1.x += speed - 4.5;
					mounten_pos2.x += speed - 4.5;
					mounten_pos3.x += speed - 4.5;
					mounten_pos4.x += speed - 4.5;
					//�n��
					ground_pos1.x += speed;
					ground_pos2.x += speed;
					ground_pos3.x += speed;
					ground_pos4.x += speed;
					ground_pos5.x += speed;
					ground_pos6.x += speed;
					ground_pos7.x += speed;
					//��
					tree_pos1.x += speed;
					tree_pos2.x += speed;
					//����
					block_pos1.x += speed;
					//���
					icicle_pos1.x += speed;
					icicle_pos2.x += speed;
					icicle_pos3.x += speed;
					//�K�i
					stairs_pos1.x += speed;
					stairs_pos2.x += speed;
					stairs_pos3.x += speed;
					stairs_pos4.x += speed;
					stairs_pos5.x += speed;

					//�v���[���g
					present_pos1.x += speed;
					present_pos2.x += speed;
					present_pos3.x += speed;

					bigpresent_pos1.x += speed;
					//�󂹂��
					breakrock_pos1.x += speed;
					moji_pos.x += speed;
					//�����
					rock_pos1.x += speed;
					rock_pos2.x += speed;
					rock_pos3.x += speed;
					rock_pos4.x += speed;
					rock_pos5.x += speed;
					rock_pos6.x += speed;

					//������
					snowball_pos1.x += speed;
					snowball_pos2.x += speed;
					snowball_pos3.x += speed;

					//�G
					snowman_pos1.x += speed;
					snowman_pos2.x += speed;
					snowman_pos3.x += speed;
					snowman_pos4.x += speed;

					star_pos1.x += speed;
					star_pos2.x += speed;

					tonakai_pos1.x += speed;
					tonakai_pos2.x += speed;

					wall_pos1.x += speed;
					wall_pos2.x += speed;



					goal_pos.x += speed;

				}
			}
			else
			{
				//�L�[�𗣂���true�ɖ߂�
				if (sp_ani == false && changeLeft_SP_1 == false) {
					santa_Nor[0].numU = 0;
					santa_Nor[0].numV = 2;
					santa_Nor[1].numU = 0;
					santa_Nor[1].numV = 2;
					if (bugPower > 0) {
						santaImage = 1;
					}
					else if (bugPower == 0) {
						santaImage = 0;
					}
				}
				changeLeft = true;
				changeLeft_SP_1 = true;
			}
		}
		//���C
		if (santa_bug == 1)
		{
			santa_pos.x = santa_huro_pos.x;
			santa_kin_pos.x = santa_huro_pos.x;

			santa_pos.y = santa_huro_pos.y;
			santa_kin_pos.y = santa_huro_pos.y;


			// �Ⴞ��܂Ƃ̓����蔻��ǉ� 
			if (collision.enemy_santa(Snowman_Stage2[1], santa_Huro[0], 200.0f, 0.0f) && HitFg == false && pauseFg == false && gameoverFg == false)
			{
				time -= 5;
				hitcooltime = 0;
				sound.Play(SOUND_LABEL_SE000);
				damage5 = true;
				HitFg = true;

			}

			if (collision.enemy_santa(Snowman_Stage2[2], santa_Huro[0], 200.0f, 0.0f) && HitFg == false && pauseFg == false && gameoverFg == false)
			{

				time -= 5;
				hitcooltime = 0;
				sound.Play(SOUND_LABEL_SE000);
				damage5 = true;
				HitFg = true;
			}

			if (collision.enemy_santa(Snowman_Stage2[3], santa_Huro[0], 200.0f, 0.0f) && HitFg == false && pauseFg == false && gameoverFg == false)
			{
				time -= 5;
				hitcooltime = 0;
				sound.Play(SOUND_LABEL_SE000);
				damage5 = true;
				HitFg = true;
			}

			if (collision.enemy_santa(Snowman_Stage2[4], santa_Huro[0], 200.0f, 0.0f) && HitFg == false && pauseFg == false && gameoverFg == false)
			{

				time -= 5;
				hitcooltime = 0;
				sound.Play(SOUND_LABEL_SE000);
				damage5 = true;
				HitFg = true;
			}

			// ���Ƃ̓����蔻��ǉ� 
			if (collision.enemy_santa(Star_Stage2[1], santa_Huro[0], 200.0f, 0.0f) && HitFg == false && pauseFg == false && gameoverFg == false)
			{
				time -= 5;
				hitcooltime = 0;
				sound.Play(SOUND_LABEL_SE000);
				damage5 = true;
				HitFg = true;
			}

			if (collision.enemy_santa(Star_Stage2[2], santa_Huro[0], 200.0f, 0.0f) && HitFg == false && pauseFg == false && gameoverFg == false)
			{
				time -= 5;
				hitcooltime = 0;
				sound.Play(SOUND_LABEL_SE000);
				damage5 = true;
				HitFg = true;
			}

			//�g�i�J�C �Ƃ̓����蔻��ǉ� 

			if (collision.enemy_santa(Tonakai_Stage2[1], santa_Huro[0], 200.0f, 0.0f) && HitFg == false && pauseFg == false && gameoverFg == false)
			{
				time -= 5;
				hitcooltime = 0;
				sound.Play(SOUND_LABEL_SE000);
				damage5 = true;
				HitFg = true;
			}

			if (collision.enemy_santa(Tonakai_Stage2[2], santa_Huro[0], 200.0f, 0.0f) && HitFg == false && pauseFg == false && gameoverFg == false)
			{
				time -= 5;
				hitcooltime = 0;
				sound.Play(SOUND_LABEL_SE000);
				damage5 = true;
				HitFg = true;
			}
			if (rocklive)
			{
				if (collision.tree_santa(Breakrock_Stge2[1], santa_Huro[0], 200.0f, 0.0f))
				{

					if (santa_huro_pos.y > breakrock_pos1.y + Breakrock_Stge2[1].GetSize().y / 2.0f) {
						
						santa_huro_pos.y = breakrock_pos1.y + Breakrock_Stge2[1].GetSize().y / 2.0f + santa_Huro[0].GetSize().y / 2.0f;
						tachFg = true;
					}
					else {
						tachFg = false;
					}

					//// �T���^���؂̉E���ɂԂ������ꍇ
					if (santa_huro_pos.x < breakrock_pos1.x&& tachFg == false)
					{

						collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
					}
					// �T���^���؂̍����ɂԂ������ꍇ
					if (santa_huro_pos.x > breakrock_pos1.x && tachFg == false)
					{

						collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
					}
				}
			}



			// �؂Ƃ̓����蔻��̒ǉ��@�S���C
			if (collision.tree_santa(Tree_Stge2[1], santa_Huro[0], 200.0f, 0.0f))
			{

				//// �T���^���؂̉E���ɂԂ������ꍇ
				if (santa_huro_pos.x < tree_pos1.x)
				{
					collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
				}
				// �T���^���؂̍����ɂԂ������ꍇ
				if (santa_huro_pos.x > tree_pos1.x)
				{

					collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
				}
			}

			if (collision.tree_santa(Tree_Stge2[2], santa_Huro[0], 200.0f, 0.0f))
			{

				//// �T���^���؂̉E���ɂԂ������ꍇ
				if (santa_huro_pos.x < tree_pos2.x)
				{
					collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
				}
				// �T���^���؂̍����ɂԂ������ꍇ
				if (santa_huro_pos.x > tree_pos2.x)
				{
					collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~

				}
			}

			if (collision.tree_santa(invisiblewall[3], santa_Huro[0], 200.0f, 0.0f))
			{

				//// �T���^���؂̉E���ɂԂ������ꍇ
				if (santa_huro_pos.x < wall_pos1.x)
				{
					collision.canMoveRight = false; //�E�Ɉړ����Ȃ�ړ����~
				}

				// �T���^���؂̍����ɂԂ������ꍇ
				if (santa_huro_pos.x > wall_pos1.x)
				{
					collision.canMoveLeft = false; //�E�Ɉړ����Ȃ�ړ����~
				}
			}

			if (collision.tree_santa(invisiblewall[4], santa_Huro[0], 200.0f, 0.0f))
			{

				//// �T���^���؂̉E���ɂԂ������ꍇ
				if (santa_huro_pos.x < wall_pos2.x)
				{
					collision.canMoveRight = false; //�E�Ɉړ����Ȃ�ړ����~
				}

				// �T���^���؂̍����ɂԂ������ꍇ
				if (santa_huro_pos.x > wall_pos2.x)
				{
					collision.canMoveLeft = false; //�E�Ɉړ����Ȃ�ړ����~
				}
			}

			if (collision.block_santa(Stairs_Stge2[1], santa_Huro[0], 100.0f, 0.0f))
			{
				if (santa_huro_pos.y > stairs_pos1.y + Stairs_Stge2[1].GetSize().y / 2.0f) {
					santa_huro_pos.y = stairs_pos1.y + Stairs_Stge2[1].GetSize().y / 2.0f + santa_Huro[0].GetSize().y / 2.0f;
					/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
				}
				else {
					/*std::cout << "\nSanta is falling." << std::endl;*/
				}

				if (santa_huro_pos.x < stairs_pos1.x)
				{
					collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
				}

				// �T���^���Ԃ������ꍇ
				if (santa_huro_pos.x > stairs_pos1.x)
				{
					collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
				}
			}


			if (collision.block_santa(Stairs_Stge2[2], santa_Huro[0], 100.0f, 0.0f))
			{
				if (santa_huro_pos.y > stairs_pos2.y + Stairs_Stge2[2].GetSize().y / 2.0f) {
					santa_huro_pos.y = stairs_pos2.y + Stairs_Stge2[2].GetSize().y / 2.0f + santa_Huro[0].GetSize().y / 2.0f;
					/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
				}
				else {
					/*std::cout << "\nSanta is falling." << std::endl;*/
				}

				if (santa_huro_pos.x < stairs_pos2.x)
				{
					collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
				}

				// �T���^���Ԃ������ꍇ
				if (santa_huro_pos.x > stairs_pos2.x)
				{
					collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
				}
			}

			if (collision.block_santa(Stairs_Stge2[3], santa_Huro[0], 100.0f, 0.0f))
			{
				if (santa_huro_pos.y > stairs_pos3.y + Stairs_Stge2[3].GetSize().y / 2.0f) {
					santa_huro_pos.y = stairs_pos3.y + Stairs_Stge2[3].GetSize().y / 2.0f + santa_Huro[0].GetSize().y / 2.0f;
					/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
				}
				else {
					/*std::cout << "\nSanta is falling." << std::endl;*/
				}

				if (santa_huro_pos.x < stairs_pos3.x)
				{
					collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
				}

				// �T���^���Ԃ������ꍇ
				if (santa_huro_pos.x > stairs_pos3.x)
				{
					collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
				}
			}

			if (collision.block_santa(Stairs_Stge2[4], santa_Huro[0], 100.0f, 0.0f))
			{
				if (santa_huro_pos.y > stairs_pos4.y + Stairs_Stge2[4].GetSize().y / 2.0f) {
					santa_huro_pos.y = stairs_pos4.y + Stairs_Stge2[4].GetSize().y / 2.0f + santa_Huro[0].GetSize().y / 2.0f;
					/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
				}
				else {
					/*std::cout << "\nSanta is falling." << std::endl;*/
				}

				if (santa_huro_pos.x < stairs_pos4.x)
				{
					collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
				}

				// �T���^���Ԃ������ꍇ
				if (santa_huro_pos.x > stairs_pos4.x)
				{
					collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
				}
			}

			if (collision.block_santa(Stairs_Stge2[5], santa_Huro[0], 100.0f, 0.0f))
			{
				if (santa_huro_pos.y > stairs_pos5.y + Stairs_Stge2[5].GetSize().y / 2.0f) {
					santa_huro_pos.y = stairs_pos5.y + Stairs_Stge2[5].GetSize().y / 2.0f + santa_Huro[0].GetSize().y / 2.0f;
					/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
				}
				else {
					/*std::cout << "\nSanta is falling." << std::endl;*/
				}

				if (santa_huro_pos.x < stairs_pos5.x)
				{
					collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
				}

				// �T���^���Ԃ������ꍇ
				if (santa_huro_pos.x > stairs_pos5.x)
				{
					collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
				}
			}

			


			//�v���[���g�̓����蔻��
			if (collision.item_santa(Present_Stage2[1], santa_Huro[0], 100.0f, 0.0f) && pauseFg == false)

			{
				presentcount += 1;
				score += 5000;
				present_pos1.y = 100000;
				sound.Play(SOUND_present);
			}

			if (collision.item_santa(Present_Stage2[2], santa_Huro[0], 100.0f, 0.0f))
			{
				presentcount += 1;
				score += 5000;
				present_pos2.y = 100000;
				sound.Play(SOUND_present);
			}

			if (collision.item_santa(Present_Stage2[3], santa_Huro[0], 100.0f, 0.0f))
			{
				presentcount += 1;
				score += 5000;
				present_pos3.y = 100000;
				sound.Play(SOUND_present);
			}

			if (collision.item_santa(BigPresent_Stage2[1], santa_Huro[0], 100.0f, 0.0f))
			{
				bigpresentcount += 1;
				score += 10000;
				bigpresent_pos1.y = 100000;
				sound.Play(SOUND_present);
			}
			// �n�ʂƂ̓����蔻��̒ǉ� �S���C


			if (collision.ground_santa(Ground_Stge2[1], santa_Huro[0], 50.0f, 0.0f)) {

				//// �T���^���n�ʂ̏�ɂ���ꍇ
				if (santa_huro_pos.y > ground_pos1.y + Ground_Stge2[1].GetSize().y / 2.0f) {
					santa_huro_pos.y = ground_pos1.y + Ground_Stge2[1].GetSize().y / 2.0f + santa_Huro[0].GetSize().y / 2.0f;
					/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
				}
				else {
					/*std::cout << "\nSanta is falling." << std::endl;*/
				}

				// �T���^���n�ʂ̉E���ɂԂ������ꍇ
				if (santa_huro_pos.x < ground_pos1.x && santa_huro_pos.y < ground_pos1.y) {

					collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
				}

				// �T���^���n�ʂɂԂ������ꍇ
				if (santa_huro_pos.x > ground_pos1.x && santa_huro_pos.y < ground_pos1.y) {
					collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
				}
			}


			if (collision.ground_santa(Ground_Stge2[2], santa_Huro[0], 50.0f, 0.0f)) {

				//// �T���^���n�ʂ̏�ɂ���ꍇ
				if (santa_huro_pos.y > ground_pos2.y + Ground_Stge2[2].GetSize().y / 2.0f) {
					santa_huro_pos.y = ground_pos2.y + Ground_Stge2[2].GetSize().y / 2.0f + santa_Huro[0].GetSize().y / 2.0f;
					/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
				}
				else {
					/*std::cout << "\nSanta is falling." << std::endl;*/
				}

				// �T���^���n�ʂ̉E���ɂԂ������ꍇ
				if (santa_huro_pos.x < ground_pos2.x && santa_huro_pos.y < ground_pos2.y) {

					collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
				}

				// �T���^���n�ʂɂԂ������ꍇ
				if (santa_huro_pos.x > ground_pos2.x && santa_huro_pos.y < ground_pos2.y) {
					collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
				}
			}


			if (collision.ground_santa(Ground_Stge2[3], santa_Huro[0], 50.0f, 0.0f)) {

				//// �T���^���n�ʂ̏�ɂ���ꍇ
				if (santa_huro_pos.y > ground_pos3.y + Ground_Stge2[3].GetSize().y / 2.0f) {
					santa_huro_pos.y = ground_pos3.y + Ground_Stge2[3].GetSize().y / 2.0f + santa_Huro[0].GetSize().y / 2.0f;
					/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
				}
				else {
					/*std::cout << "\nSanta is falling." << std::endl;*/
				}

				// �T���^���n�ʂ̉E���ɂԂ������ꍇ
				if (santa_huro_pos.x < ground_pos3.x && santa_huro_pos.y < ground_pos3.y) {

					collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
				}

				// �T���^���n�ʂɂԂ������ꍇ
				if (santa_huro_pos.x > ground_pos3.x && santa_huro_pos.y < ground_pos3.y) {
					collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
				}
			}


			if (collision.ground_santa(Ground_Stge2[4], santa_Huro[0], 50.0f, 0.0f)) {

				//// �T���^���n�ʂ̏�ɂ���ꍇ
				if (santa_huro_pos.y > ground_pos4.y + Ground_Stge2[4].GetSize().y / 2.0f) {
					santa_huro_pos.y = ground_pos4.y + Ground_Stge2[4].GetSize().y / 2.0f + santa_Huro[0].GetSize().y / 2.0f;
					/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
				}
				else {
					/*std::cout << "\nSanta is falling." << std::endl;*/
				}

				// �T���^���n�ʂ̉E���ɂԂ������ꍇ
				if (santa_huro_pos.x < ground_pos4.x && santa_huro_pos.y < ground_pos4.y) {

					collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
				}

				// �T���^���n�ʂɂԂ������ꍇ
				if (santa_huro_pos.x > ground_pos4.x && santa_huro_pos.y < ground_pos4.y) {
					collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
				}
			}


			if (collision.ground_santa(Ground_Stge2[5], santa_Huro[0], 50.0f, 0.0f)) {

				//// �T���^���n�ʂ̏�ɂ���ꍇ
				if (santa_huro_pos.y > ground_pos5.y+ Ground_Stge2[5].GetSize().y / 2.0f) {
					santa_huro_pos.y = ground_pos5.y + Ground_Stge2[5].GetSize().y / 2.0f + santa_Huro[0].GetSize().y / 2.0f;
					/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
				}
				else {
					/*std::cout << "\nSanta is falling." << std::endl;*/
				}

				// �T���^���n�ʂ̉E���ɂԂ������ꍇ
				if (santa_huro_pos.x < ground_pos5.x && santa_huro_pos.y < ground_pos5.y) {

					collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
				}

				// �T���^���n�ʂɂԂ������ꍇ
				if (santa_huro_pos.x > ground_pos5.x && santa_huro_pos.y < ground_pos5.y) {
					collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
				}
			}


			if (collision.ground_santa(Ground_Stge2[6], santa_Huro[0], 50.0f, 0.0f)) {

				//// �T���^���n�ʂ̏�ɂ���ꍇ
				if (santa_huro_pos.y > ground_pos6.y + Ground_Stge2[6].GetSize().y / 2.0f) {
					santa_huro_pos.y = ground_pos6.y + Ground_Stge2[6].GetSize().y / 2.0f + santa_Huro[0].GetSize().y / 2.0f;
					/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
				}
				else {
					/*std::cout << "\nSanta is falling." << std::endl;*/
				}

				// �T���^���n�ʂ̉E���ɂԂ������ꍇ
				if (santa_huro_pos.x < ground_pos6.x && santa_huro_pos.y < ground_pos6.y) {

					collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
				}

				// �T���^���n�ʂɂԂ������ꍇ
				if (santa_huro_pos.x > ground_pos6.x && santa_huro_pos.y < ground_pos6.y) {
					collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
				}
			}


			if (collision.ground_santa(Ground_Stge2[7], santa_Huro[0], 50.0f, 0.0f)) {

				//// �T���^���n�ʂ̏�ɂ���ꍇ
				if (santa_huro_pos.y > ground_pos7.y + Ground_Stge2[7].GetSize().y / 2.0f) {
					santa_huro_pos.y = ground_pos7.y + Ground_Stge2[7].GetSize().y / 2.0f + santa_Huro[0].GetSize().y / 2.0f;
					/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
				}
				else {
					/*std::cout << "\nSanta is falling." << std::endl;*/
				}

				// �T���^���n�ʂ̉E���ɂԂ������ꍇ
				if (santa_huro_pos.x < ground_pos7.x && santa_huro_pos.y < ground_pos7.y) {

					collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
				}

				// �T���^���n�ʂɂԂ������ꍇ
				if (santa_huro_pos.x > ground_pos7.x && santa_huro_pos.y < ground_pos7.y) {
					collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
				}
			}

			
			if (collision.ground_santa(Block_Stge2[1], santa_Huro[0], 50.0f, 0.0f)) {

				//// �T���^���n�ʂ̏�ɂ���ꍇ
				if (santa_huro_pos.y > block_pos1.y + Block_Stge2[1].GetSize().y / 2.0f) {
					santa_huro_pos.y = block_pos1.y + Block_Stge2[1].GetSize().y / 2.0f + santa_Huro[0].GetSize().y / 2.0f;
					/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
				}
				else {
					/*std::cout << "\nSanta is falling." << std::endl;*/
				}

				// �T���^���n�ʂ̉E���ɂԂ������ꍇ
				if (santa_huro_pos.x < block_pos1.x && santa_huro_pos.y < block_pos1.y) {

					collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
				}

				// �T���^���n�ʂɂԂ������ꍇ
				if (santa_huro_pos.x > block_pos1.x && santa_huro_pos.y < block_pos1.y) {
					collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
				}
			}



			//�S�[�������蔻��
			if (collision.goal_santa(Goal_Stage2, santa_Huro[0], 250.0f, 0.0f))
			{
				changescene = RESULT;
				gameoverFg = false;
				//������
				santa_pos.x = -400;
				santa_pos.y = -160;

				santa_kin_pos.x = -400;
				santa_kin_pos.y = -160;

				santa_huro_pos.x = -400;
				santa_huro_pos.y = -160;

				mounten_pos1.x = 0;
				mounten_pos2.x = 1280;
				mounten_pos3.x = 2560;

				rock_pos1.x = -275;
				rock_pos2.x = 5000;
				rock_pos3.x = 1100;
				rock_pos4.x = 2800;
				rock_pos5.x = 4000;
				rock_pos6.x = 7500;

				snowball_pos1.x = 3100;
				snowball_pos2.x = 5500;
				snowball_pos3.x = 7000;

				ground_pos1.x = 0;
				ground_pos2.x = 2000;
				ground_pos3.x = 3300;
				ground_pos4.x = 3800;
				ground_pos5.x = 4450;
				ground_pos6.x = 5300;
				ground_pos7.x = 7400;

				block_pos1.x = 2000;

				icicle_pos1.x = 1800;
				icicle_pos2.x = 2000;
				icicle_pos3.x = 2200;

				icicle_pos1.y = 100;
				icicle_pos2.y = 100;
				icicle_pos3.y = 100;

				tree_pos1.x = 900;
				tree_pos2.x = 3450;

				stairs_pos1.x = 5720;
				stairs_pos2.x = 5755;
				stairs_pos3.x = 5790;
				stairs_pos4.x = 5825;
				stairs_pos5.x = 5860;

				snowman_pos1.x = 30;
				snowman_pos2.x = 1400;
				snowman_pos3.x = 3800;
				snowman_pos4.x = 7000;

				star_pos1.x = 2000;
				star_pos2.x = 5000;

				tonakai_pos1.x = 26000;
				tonakai_pos2.x = 7500;
				bigpresent_pos1.x = 4450;
				present_pos1.x = 3300;
				present_pos2.x = 6300;
				present_pos3.x = 2000;

				breakrock_pos1.x = 4450;
				moji_pos.x = 4450;

				goal_pos.x = 7900;

				wall_pos1.x = -600;
				wall_pos2.x = 7850;

			}


			// �T���^���A�C�e���ɓ���������
			bool itemCollected = false; // �A�C�e�������ɉ�����ꂽ���ǂ����̃t���O


			const float rightScreen = 670.0f; // ��ʂ̉E�[
			const float leftScreen = -670.0f; // ��ʂ̍��[


			if (collision.item_santa(Collectrock_Stage2[1], santa_Huro[0], 100.0f, 0.0f) && rock_visible1 == 0)
			{

				if (input.GetKeyTrigger(VK_S) && !itemCollected && !sp_ani || input.GetButtonTrigger(XINPUT_B) && !itemCollected && !sp_ani)
				{

					item->ItemGet(1); // ��������
					bugPower = item->GetItemCnt(); // ���݂̑܂̃A�C�e��������
					itemCollected = true;
					santaImage = 13;

					rock_visible1 = 1;

				}

				
			}

			if (collision.item_santa(Collectrock_Stage2[2], santa_Huro[0], 100.0f, 0.0f) && rock_visible2 == 0)
			{
				if (input.GetKeyTrigger(VK_S) && !itemCollected && !sp_ani || input.GetButtonTrigger(XINPUT_B) && !itemCollected && !sp_ani)
				{

					item->ItemGet(1); // ��������
					bugPower = item->GetItemCnt(); // ���݂̑܂̃A�C�e��������
					itemCollected = true;
					santaImage = 13;

					rock_visible2 = 1;

				}
			}

			if (collision.item_santa(Collectrock_Stage2[3], santa_Huro[0], 100.0f, 0.0f) && rock_visible3 == 0)
			{
				if (input.GetKeyTrigger(VK_S) && !itemCollected && !sp_ani || input.GetButtonTrigger(XINPUT_B) && !itemCollected && !sp_ani)
				{

					item->ItemGet(1); // ��������
					bugPower = item->GetItemCnt(); // ���݂̑܂̃A�C�e��������
					itemCollected = true;
					santaImage = 13;

					rock_visible3 = 1;

				}
			}

			if (collision.item_santa(Collectrock_Stage2[4], santa_Huro[0], 100.0f, 0.0f) && rock_visible4 == 0)
			{
				if (input.GetKeyTrigger(VK_S) && !itemCollected && !sp_ani || input.GetButtonTrigger(XINPUT_B) && !itemCollected && !sp_ani)
				{

					item->ItemGet(1); // ��������
					bugPower = item->GetItemCnt(); // ���݂̑܂̃A�C�e��������
					itemCollected = true;
					santaImage = 13;

					rock_visible4 = 1;

				}
			}

			if (collision.item_santa(Collectrock_Stage2[5], santa_Huro[0], 100.0f, 0.0f) && rock_visible5 == 0)
			{
				if (input.GetKeyTrigger(VK_S) && !itemCollected && !sp_ani || input.GetButtonTrigger(XINPUT_B) && !itemCollected && !sp_ani)
				{

					item->ItemGet(1); // ��������
					bugPower = item->GetItemCnt(); // ���݂̑܂̃A�C�e��������
					itemCollected = true;
					santaImage = 13;

					rock_visible5 = 1;

				}
			}

			if (collision.item_santa(Collectrock_Stage2[6], santa_Huro[0], 100.0f, 0.0f) && rock_visible6 == 0)
			{
				if (input.GetKeyTrigger(VK_S) && !itemCollected || input.GetButtonTrigger(XINPUT_B) && !itemCollected)
				{
					if (input.GetKeyTrigger(VK_S) && !itemCollected && !sp_ani || input.GetButtonTrigger(XINPUT_B) && !itemCollected && !sp_ani)
					{

						item->ItemGet(1); // ��������
						bugPower = item->GetItemCnt(); // ���݂̑܂̃A�C�e��������
						itemCollected = true;
						santaImage = 13;

						rock_visible6 = 1;

					}
				}
			}

			if (collision.item_santa(Snowball_Stage2[1], santa_Huro[0], 100.0f, 0.0f) && snow_visible1 == 0)
			{
				if (input.GetKeyTrigger(VK_S) && !itemCollected && !sp_ani || input.GetButtonTrigger(XINPUT_B) && !itemCollected && !sp_ani)
				{
					/*itemID = 1;*/
					item->ItemGet(2); // ��������
					bugPower = item->GetItemCnt(); // ���݂̑܂̃A�C�e��������
					itemCollected = true;
					santaImage = 13;

					snow_visible1 = 1;
				}
			}

			if (collision.item_santa(Snowball_Stage2[2], santa_Huro[0], 100.0f, 0.0f) && snow_visible1 == 0)
			{
				if (input.GetKeyTrigger(VK_S) && !itemCollected && !sp_ani || input.GetButtonTrigger(XINPUT_B) && !itemCollected && !sp_ani)
				{
					/*itemID = 1;*/
					item->ItemGet(2); // ��������
					bugPower = item->GetItemCnt(); // ���݂̑܂̃A�C�e��������
					itemCollected = true;
					santaImage = 13;

					snow_visible2 = 1;
				}
			}

			if (collision.item_santa(Snowball_Stage2[3], santa_Huro[0], 100.0f, 0.0f) && snow_visible1 == 0)
			{
				if (input.GetKeyTrigger(VK_S) && !itemCollected && !sp_ani || input.GetButtonTrigger(XINPUT_B) && !itemCollected && !sp_ani)
				{
					/*itemID = 1;*/
					item->ItemGet(2); // ��������
					bugPower = item->GetItemCnt(); // ���݂̑܂̃A�C�e��������
					itemCollected = true;
					santaImage = 13;

					snow_visible3 = 1;
				}
			}

			// ��ʊO�ɍs���ƁA�A�C�e�����ăX�|�[�����鏈��
			if (leftScreen > rock_pos1.x || rock_pos1.x > rightScreen) {
				rock_visible1 = 0;
			}
			if (leftScreen > rock_pos2.x || rock_pos2.x > rightScreen) {
				rock_visible2 = 0;
			}
			if (leftScreen > rock_pos3.x || rock_pos3.x > rightScreen) {
				rock_visible3 = 0;
			}
			if (leftScreen > rock_pos4.x || rock_pos4.x > rightScreen) {
				rock_visible4 = 0;
			}
			if (leftScreen > rock_pos5.x || rock_pos5.x > rightScreen) {
				rock_visible5 = 0;
			}
			if (leftScreen > rock_pos6.x || rock_pos6.x > rightScreen) {
				rock_visible6 = 0;
			}
			if (leftScreen > snowball_pos1.x || snowball_pos1.x > rightScreen) {
				snow_visible1 = 0;
			}
			if (leftScreen > snowball_pos2.x || snowball_pos2.x > rightScreen) {
				snow_visible2 = 0;
			}
			if (leftScreen > snowball_pos3.x || snowball_pos3.x > rightScreen) {
				snow_visible3 = 0;
			}


			if (!itemCollected && !changeItem) {// �������ĂȂ��ꍇ
				if (input.GetKeyTrigger(VK_S) && pauseFg == false || input.GetButtonTrigger(XINPUT_B) && pauseFg == false)
				{

					if (item->GetItem_3() > 0) {
						changeItem = true;

						if (item->GetItem_3() == 1) {
							use_rock_pos3.x = santa_huro_pos.x;
							use_rock_pos3.y = santa_huro_pos.y;
							sound.Play(SOUND_LABEL_SE004);
							itemID_3 = 1;
							itemMove3 = true;
						}
						else if (item->GetItem_3() == 2) {
							use_snowball_pos3.x = santa_huro_pos.x;
							use_snowball_pos3.y = santa_huro_pos.y;
							sound.Play(SOUND_LABEL_SE002);
							itemID_3 = 2;
							itemMove3 = true;
						}

					}
					else if (item->GetItem_3() < 0) {

						if (item->GetItem_2() > 0) {

							if (item->GetItem_2() == 1) {
								use_rock_pos2.x = santa_huro_pos.x;
								use_rock_pos2.y = santa_huro_pos.y;
								sound.Play(SOUND_LABEL_SE004);
								itemID_2 = 1;
								itemMove2 = true;
							}
							else if (item->GetItem_2() == 2) {
								use_snowball_pos2.x = santa_huro_pos.x;
								use_snowball_pos2.y = santa_huro_pos.y;
								sound.Play(SOUND_LABEL_SE004);
								itemID_2 = 2;
								itemMove2 = true;
							}

						}
						else if (item->GetItem_2() < 0) {

							if (item->GetItem_1() > 0) {

								if (item->GetItem_1() == 1) {
									use_rock_pos1.x = santa_huro_pos.x;
									use_rock_pos1.y = santa_huro_pos.y;
									itemID_1 = 1;
									itemMove1 = true;
								}
								else if (item->GetItem_1() == 2) {
									use_snowball_pos1.x = santa_huro_pos.x;
									use_snowball_pos1.y = santa_huro_pos.y;
									itemID_1 = 2;
									itemMove1 = true;
								}

							}
						}
					}


					item->ItemRelease(); // ���o��
					bugPower = item->GetItemCnt();
				}
			}




			if (collision.enemy_santa(Icicles_Stge2[1], santa_Huro[0], 200.0f, 0.0f) && HitFg == false && turarafall1 == true)
			{
				time -= 5;
				hitcooltime = 0;
				sound.Play(SOUND_LABEL_SE000);
				damage5 = true;
				HitFg = true;
			}

			if (collision.enemy_santa(Icicles_Stge2[2], santa_Huro[0], 200.0f, 0.0f) && HitFg == false && turarafall3 == true)
			{
				time -= 5;
				hitcooltime = 0;
				sound.Play(SOUND_LABEL_SE000);
				damage5 = true;
				HitFg = true;
			}

			if (collision.enemy_santa(Icicles_Stge2[3], santa_Huro[0], 200.0f, 0.0f) && HitFg == false && turarafall3 == true)
			{
				time -= 5;
				hitcooltime = 0;
				sound.Play(SOUND_LABEL_SE000);
				damage5 = true;
				HitFg = true;
			}

			if (!itemCollected && !changeItem) {// �������ĂȂ��ꍇ
				if (input.GetKeyTrigger(VK_S) && pauseFg == false && !sp_ani || input.GetButtonTrigger(XINPUT_B) && pauseFg == false && !sp_ani)
				{

					if (item->GetItem_3() > 0) {
						changeItem = true;

						if (item->GetItem_3() == 1) {
							use_rock_pos3.x = santa_pos.x;
							use_rock_pos3.y = santa_pos.y;
							sound.Play(SOUND_LABEL_SE003);
							itemID_3 = 1;
							itemMove3 = true;
						}
						else if (item->GetItem_3() == 2) {
							use_snowball_pos3.x = santa_pos.x;
							use_snowball_pos3.y = santa_pos.y;
							sound.Play(SOUND_LABEL_SE003);
							itemID_3 = 2;
							itemMove3 = true;
						}

					}
					else if (item->GetItem_3() < 0) {

						if (item->GetItem_2() > 0) {

							if (item->GetItem_2() == 1) {
								use_rock_pos2.x = santa_huro_pos.x;
								use_rock_pos2.y = santa_huro_pos.y;
								sound.Play(SOUND_LABEL_SE003);
								itemID_2 = 1;
								itemMove2 = true;
							}
							else if (item->GetItem_2() == 2) {
								use_snowball_pos2.x = santa_huro_pos.x;
								use_snowball_pos2.y = santa_huro_pos.y;
								sound.Play(SOUND_LABEL_SE003);
								itemID_2 = 2;
								itemMove2 = true;
							}

						}
						else if (item->GetItem_2() < 0) {

							if (item->GetItem_1() > 0) {

								if (item->GetItem_1() == 1) {
									use_rock_pos1.x = santa_huro_pos.x;
									use_rock_pos1.y = santa_huro_pos.y;
									itemID_1 = 1;
									itemMove1 = true;
								}
								else if (item->GetItem_1() == 2) {
									use_snowball_pos1.x = santa_huro_pos.x;
									use_snowball_pos1.y = santa_huro_pos.y;
									itemID_1 = 2;
									itemMove1 = true;
								}

							}
						}
					}

					santaImage = 14;
					item->ItemRelease(); // ���o��
					bugPower = item->GetItemCnt();
				}
			}


			// ����A�j���[�V����
			if (santaImage == 13) {
				getItem = 1;
				if (direction == 0) { // �E����
					if (changeRight_get == true)
					{
						//������
						santa_Huro[4].numU = 0;
						santa_Huro[4].numV = 0;
						changeRight_get = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���
					}
					framcount4++; //�t���[���J�E���g
					if (framcount4 % 4 == 0) //�P�O�t���[���Ɉ��s����
					{
						santa_Huro[4].numU++;
						if (santa_Huro[4].numU >= 5)
						{
							sp_ani = false;
							santaImage = 1;
							getItem = 0;
							santa_Huro[4].numU = 0;

						}
					}
				}
				else if (direction == 1) {
					if (changeLeft_get == true)
					{
						//������
						santa_Huro[4].numU = 0;
						santa_Huro[4].numV = 1;
						changeLeft_get = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���
					}
					framcount4++; //�t���[���J�E���g
					if (framcount4 % 4 == 0) //�P�O�t���[���Ɉ��s����
					{
						santa_Huro[4].numU++;
						if (santa_Huro[4].numU >= 5)
						{
							sp_ani = false;
							santaImage = 1;
							getItem = 0;
							santa_Huro[4].numU = 0;

						}
					}
				}
			}

			// ��o�A�j���[�V����
			if (santaImage == 14) {

				if (direction == 0) { // �E����
					if (changeRight_out == true)
					{
						//������
						santa_Huro[5].numU = 0;
						santa_Huro[5].numV = 0;
						changeRight_out = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���
					}
					framcount5++; //�t���[���J�E���g
					if (framcount5 % 4 == 0) //�P�O�t���[���Ɉ��s����
					{
						santa_Huro[5].numU++;
						if (santa_Huro[5].numU >= 5)
						{
							sp_ani = false;
							if (bugPower > 0) {
								santaImage = 9;
							}
							else if (bugPower == 0) {
								santaImage = 8;
							}

							santa_Huro[5].numU = 0;
							changeRight_out = true;

						}
					}
				}
				else if (direction == 1) {
					if (changeLeft_out == true)
					{
						//������
						santa_Huro[5].numU = 0;
						santa_Huro[5].numV = 1;
						changeLeft_out = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���
					}
					framcount5++; //�t���[���J�E���g
					if (framcount5 % 4 == 0) //�P�O�t���[���Ɉ��s����
					{
						santa_Huro[5].numU++;
						if (santa_Huro[5].numU >= 5)
						{
							sp_ani = false;
							if (bugPower > 0) {
								santaImage = 9;
							}
							else if (bugPower == 0) {
								santaImage = 8;
							}
							santa_Huro[5].numU = 0;
							changeLeft_out = true;

						}
					}
				}
			}



			// �������̓����@���̇@ 
			if (itemMove1 == true) {
				if (direction == 0) { // �E����

					if (itemID_1 == 1) { // ��

						if (itemMove1_M == true || use_rock_pos1.y >= -100.0f) {
							itemMove1_M = true;
							use_rock_pos1.y -= 3.00f;
							use_rock_pos1.x += 3.00f;
						}
						else if (itemMove1_M == false) {
							use_rock_pos1.y += 3.00f;
							use_rock_pos1.x += 3.00f;
						}
						if (use_rock_pos1.y <= -190.0f && itemMove1_M == true) {
							itemID_1 = 0;
							itemMove1_M = false;
							itemMove1 = false;
						}
					}
					else if (itemID_1 == 2) {
						if (use_snowball_pos1.x >= rightScreen) {
							itemID_1 = 0;
							itemMove1 = false;
						}
						else if (use_snowball_pos1.x <= rightScreen) {
							use_snowball_pos1.x += 20.00f;
						}
					}
				}
				else if (direction == 1) { // ������

					if (itemID_1 == 1) { // ��

						if (itemMove1_M == true || use_rock_pos1.y >= -100.0f) {
							itemMove1_M = true;
							use_rock_pos1.y -= 3.00f;
							use_rock_pos1.x -= 3.00f;
						}
						else if (itemMove1_M == false) {
							use_rock_pos1.y += 3.00f;
							use_rock_pos1.x -= 3.00f;
						}
						if (use_rock_pos1.y <= -190.0f && itemMove1_M == true) {
							itemID_1 = 0;
							itemMove1_M = false;
							itemMove1 = false;
						}
					}
					else if (itemID_1 == 2) {
						if (use_snowball_pos1.x <= leftScreen) {
							itemID_1 = 0;
							itemMove1 = false;
						}
						else if (use_snowball_pos1.x >= leftScreen) {
							use_snowball_pos1.x -= 20.00f;
						}
					}
				}



			}

			// �������̓����@���̇A
			if (itemMove2 == true) {
				if (direction == 0) { // �E����

					if (itemID_2 == 1) { //��

						if (itemMove2_M == true || use_rock_pos2.y >= -100.0f) {
							itemMove2_M = true;
							use_rock_pos2.y -= 3.00f;
							use_rock_pos2.x += 3.00f;
						}
						else if (itemMove2_M == false) {
							use_rock_pos2.y += 3.00f;
							use_rock_pos2.x += 3.00f;
						}
						if (use_rock_pos2.y <= -190.0f && itemMove2_M == true) {
							itemID_2 = 0;
							itemMove2_M = false;
							itemMove2 = false;
						}
					}
					else if (itemID_2 == 2) {
						if (use_snowball_pos2.x >= rightScreen) {
							itemID_2 = 0;
							itemMove2 = false;
						}
						else if (use_snowball_pos2.x <= rightScreen) {
							use_snowball_pos2.x += 20.00f;
						}
					}
				}
				else if (direction == 1) { // ������

					if (itemID_2 == 1) { //��

						if (itemMove2_M == true || use_rock_pos2.y >= -100.0f) {
							itemMove2_M = true;
							use_rock_pos2.y -= 3.00f;
							use_rock_pos2.x -= 3.00f;
						}
						else if (itemMove2_M == false) {
							use_rock_pos2.y += 3.00f;
							use_rock_pos2.x -= 3.00f;
						}
						if (use_rock_pos2.y <= -190.0f && itemMove2_M == true) {
							itemID_2 = 0;
							itemMove2_M = false;
							itemMove2 = false;
						}
					}
					else if (itemID_2 == 2) {
						if (use_snowball_pos2.x <= leftScreen) {
							itemID_2 = 0;
							itemMove2 = false;
						}
						else if (use_snowball_pos2.x >= leftScreen) {
							use_snowball_pos2.x -= 20.00f;
						}
					}
				}


			}

			// �������̓����@���̇B
			if (itemMove3 == true) {

				if (direction == 0) { // �E����

					if (itemID_3 == 1) { // ��

						if (itemMove3_M == true || use_rock_pos3.y >= -100.0f) {
							itemMove3_M = true;
							use_rock_pos3.y -= 3.00f;
							use_rock_pos3.x += 3.00f;
						}
						else if (itemMove3_M == false) {
							use_rock_pos3.y += 3.00f;
							use_rock_pos3.x += 3.00f;
						}
						if (use_rock_pos3.y <= -190.0f && itemMove3_M == true) {
							itemID_3 = 0;
							itemMove3_M = false;
							itemMove3 = false;
							changeItem = false;
						}
					}
					else if (itemID_3 == 2) {
						if (use_snowball_pos3.x >= rightScreen) {
							itemID_3 = 0;
							itemMove3 = false;
							changeItem = false;
						}
						else if (use_snowball_pos3.x <= rightScreen) {
							use_snowball_pos3.x += 30.00f;
						}
					}
				}
				else if (direction == 1) { // ������

					if (itemID_3 == 1) { // ��

						if (itemMove3_M == true || use_rock_pos3.y >= -100.0f) {
							itemMove3_M = true;
							use_rock_pos3.y -= 3.00f;
							use_rock_pos3.x -= 3.00f;
						}
						else if (itemMove3_M == false) {
							use_rock_pos3.y += 3.00f;
							use_rock_pos3.x -= 3.00f;
						}
						if (use_rock_pos3.y <= -190.0f && itemMove3_M == true) {
							itemID_3 = 0;
							itemMove3_M = false;
							itemMove3 = false;
							changeItem = false;
						}
					}
					else if (itemID_3 == 2) {
						if (use_snowball_pos3.x <= leftScreen) {
							itemID_3 = 0;
							itemMove3 = false;
							changeItem = false;
						}
						else if (use_snowball_pos3.x >= leftScreen) {
							use_snowball_pos3.x -= 30.00f;
						}
					}
				}


			}


			// �������̓����蔻�� ��

				// �Ⴞ��܂P
			if (collision.square_square(Snowman_Stage2[1], use_rock[0]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp1 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos1.x;
				particlepos.y = snowman_pos1.y;

				if (snowman_hp1 < 0)
				{
					enemylive1 = false;
					snowman_hp1 = 20;
					snowman_pos1.x = 400000000;
				}
			}

			if (collision.square_square(Snowman_Stage2[1], use_rock[1]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp1 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos1.x;
				particlepos.y = snowman_pos1.y;

				if (snowman_hp1 < 0)
				{
					enemylive1 = false;
					snowman_hp1 = 20;
					snowman_pos1.x = 400000000;
				}
			}

			if (collision.square_square(Snowman_Stage2[1], use_rock[2]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp1 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos1.x;
				particlepos.y = snowman_pos1.y;

				if (snowman_hp1 < 0)
				{
					enemylive1 = false;
					snowman_hp1 = 20;
					snowman_pos1.x = 400000000;
				}
			}

			// �Ⴞ��܂Q
			if (collision.square_square(Snowman_Stage2[2], use_rock[0]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp2 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos2.x;
				particlepos.y = snowman_pos2.y;

				if (snowman_hp2 < 0)
				{
					enemylive2 = false;
					snowman_hp2 = 20;
					snowman_pos2.x = 400000000;
				}
			}

			if (collision.square_square(Snowman_Stage2[2], use_rock[1]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp2 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos2.x;
				particlepos.y = snowman_pos2.y;

				if (snowman_hp2 < 0)
				{
					enemylive2 = false;
					snowman_hp2 = 20;
					snowman_pos2.x = 400000000;
				}
			}

			if (collision.square_square(Snowman_Stage2[2], use_rock[2]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp2 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos2.x;
				particlepos.y = snowman_pos2.y;

				if (snowman_hp2 < 0)
				{
					enemylive2 = false;
					snowman_hp2 = 20;
					snowman_pos2.x = 400000000;
				}
			}

			// �Ⴞ���3
			if (collision.square_square(Snowman_Stage2[3], use_rock[0]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp3 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos3.x;
				particlepos.y = snowman_pos3.y;

				if (snowman_hp3 < 0)
				{
					enemylive3 = false;
					snowman_hp3 = 20;
					snowman_pos3.x = 400000000;
				}
			}

			if (collision.square_square(Snowman_Stage2[3], use_rock[1]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp3 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos3.x;
				particlepos.y = snowman_pos3.y;

				if (snowman_hp3 < 0)
				{
					enemylive3 = false;
					snowman_hp3 = 20;
					snowman_pos3.x = 400000000;
				}
			}

			if (collision.square_square(Snowman_Stage2[3], use_rock[2]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp3 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos3.x;
				particlepos.y = snowman_pos3.y;

				if (snowman_hp3 < 0)
				{
					enemylive3 = false;
					snowman_hp3 = 20;
					snowman_pos3.x = 400000000;
				}
			}

			// �Ⴞ���3
			if (collision.square_square(Snowman_Stage2[4], use_rock[0]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp4 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos4.x;
				particlepos.y = snowman_pos4.y;

				if (snowman_hp4 < 0)
				{
					enemylive4 = false;
					snowman_hp4 = 20;
					snowman_pos4.x = 400000000;
				}
			}

			if (collision.square_square(Snowman_Stage2[4], use_rock[1]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp4 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos4.x;
				particlepos.y = snowman_pos4.y;

				if (snowman_hp4 < 0)
				{
					enemylive4 = false;
					snowman_hp4 = 20;
					snowman_pos4.x = 400000000;
				}
			}

			if (collision.square_square(Snowman_Stage2[4], use_rock[2]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp4 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos4.x;
				particlepos.y = snowman_pos4.y;

				if (snowman_hp4 < 0)
				{
					enemylive4 = false;
					snowman_hp4 = 20;
					snowman_pos4.x = 400000000;
				}
			}

			// �N���X�}�X�c���[1
			if (collision.square_square(Star_Stage2[1], use_rock[0]) == true) {
				star_monster_hp1 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = star_pos1.x;
				particlepos.y = star_pos1.y;
				if (star_monster_hp1 < 0)
				{
					enemylive5 = false;
					star_monster_hp1 = 40;
					star_pos1.x = 400000000;
				}
			}

			if (collision.square_square(Star_Stage2[1], use_rock[1]) == true) {
				star_monster_hp1 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = star_pos1.x;
				particlepos.y = star_pos1.y;
				if (star_monster_hp1 < 0)
				{
					enemylive5 = false;
					star_monster_hp1 = 40;
					star_pos1.x = 400000000;
				}
			}

			if (collision.square_square(Star_Stage2[1], use_rock[2]) == true) {
				star_monster_hp1 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = star_pos1.x;
				particlepos.y = star_pos1.y;
				if (star_monster_hp1 < 0)
				{
					enemylive5 = false;
					star_monster_hp1 = 40;
					star_pos1.x = 400000000;
				}
			}

			// �N���X�}�X�c���[2
			if (collision.square_square(Star_Stage2[2], use_rock[0]) == true) {
				star_monster_hp2 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = star_pos2.x;
				particlepos.y = star_pos2.y;
				if (star_monster_hp2 < 0)
				{
					enemylive6 = false;
					star_monster_hp2 = 40;
					star_pos2.x = 400000000;
				}
			}

			if (collision.square_square(Star_Stage2[2], use_rock[1]) == true) {
				star_monster_hp2 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = star_pos2.x;
				particlepos.y = star_pos2.y;
				if (star_monster_hp2 < 0)
				{
					enemylive6 = false;
					star_monster_hp2 = 40;
					star_pos2.x = 400000000;
				}
			}

			if (collision.square_square(Star_Stage2[2], use_rock[2]) == true) {
				star_monster_hp2 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = star_pos2.x;
				particlepos.y = star_pos2.y;
				if (star_monster_hp2 < 0)
				{
					enemylive6 = false;
					star_monster_hp2 = 40;
					star_pos2.x = 400000000;
				}
			}

			// �g�i�J�C1
			if (collision.square_square(Tonakai_Stage2[1], use_rock[0]) == true) {
				tonakai_hp1 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = tonakai_pos1.x;
				particlepos.y = tonakai_pos1.y;
				if (tonakai_hp1 < 0)
				{
					enemylive7 = false;
					tonakai_hp1 = 60;
					tonakai_pos1.x = 400000000;
				}
			}

			if (collision.square_square(Tonakai_Stage2[1], use_rock[1]) == true) {
				tonakai_hp1 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = tonakai_pos1.x;
				particlepos.y = tonakai_pos1.y;
				if (tonakai_hp1 < 0)
				{
					enemylive7 = false;
					tonakai_hp1 = 60;
					tonakai_pos1.x = 400000000;
				}
			}

			if (collision.square_square(Tonakai_Stage2[1], use_rock[2]) == true) {
				tonakai_hp1 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = tonakai_pos1.x;
				particlepos.y = tonakai_pos1.y;
				if (tonakai_hp1 < 0)
				{
					enemylive7 = false;
					tonakai_hp1 = 60;
					tonakai_pos1.x = 400000000;
				}
			}

			// �g�i�J�C2
			if (collision.square_square(Tonakai_Stage2[2], use_rock[0]) == true) {
				tonakai_hp2 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = tonakai_pos2.x;
				particlepos.y = tonakai_pos2.y;
				if (tonakai_hp2 < 0)
				{
					enemylive8 = false;
					tonakai_hp2 = 60;
					tonakai_pos2.x = 400000000;
				}
			}

			if (collision.square_square(Tonakai_Stage2[2], use_rock[1]) == true) {
				tonakai_hp2 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = tonakai_pos2.x;
				particlepos.y = tonakai_pos2.y;
				if (tonakai_hp2 < 0)
				{
					enemylive8 = false;
					tonakai_hp2 = 60;
					tonakai_pos2.x = 400000000;
				}
			}

			if (collision.square_square(Tonakai_Stage2[2], use_rock[2]) == true) {
				tonakai_hp2 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = tonakai_pos2.x;
				particlepos.y = tonakai_pos2.y;
				if (tonakai_hp2 < 0)
				{
					enemylive8 = false;
					tonakai_hp2 = 60;
					tonakai_pos2.x = 400000000;
				}
			}


			// �������̓����蔻�� ���
			// �Ⴞ��܂P
			if (collision.square_square(Snowman_Stage2[1], use_snowball[0]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp1 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos1.x;
				particlepos.y = snowman_pos1.y;

				if (snowman_hp1 < 0)
				{
					enemylive1 = false;
					snowman_hp1 = 20;
					snowman_pos1.x = 400000000;
				}
			}

			if (collision.square_square(Snowman_Stage2[1], use_snowball[1]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp1 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos1.x;
				particlepos.y = snowman_pos1.y;

				if (snowman_hp1 < 0)
				{
					enemylive1 = false;
					snowman_hp1 = 20;
					snowman_pos1.x = 400000000;
				}
			}

			if (collision.square_square(Snowman_Stage2[1], use_snowball[2]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp1 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos1.x;
				particlepos.y = snowman_pos1.y;

				if (snowman_hp1 < 0)
				{
					enemylive1 = false;
					snowman_hp1 = 20;
					snowman_pos1.x = 400000000;
				}
			}

			// �Ⴞ��܂Q
			if (collision.square_square(Snowman_Stage2[2], use_snowball[0]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp2 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos2.x;
				particlepos.y = snowman_pos2.y;

				if (snowman_hp2 < 0)
				{
					enemylive2 = false;
					snowman_hp2 = 20;
					snowman_pos2.x = 400000000;
				}
			}

			if (collision.square_square(Snowman_Stage2[2], use_snowball[1]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp2 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos2.x;
				particlepos.y = snowman_pos2.y;

				if (snowman_hp2 < 0)
				{
					enemylive2 = false;
					snowman_hp2 = 20;
					snowman_pos2.x = 400000000;
				}
			}

			if (collision.square_square(Snowman_Stage2[2], use_snowball[2]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp2 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos2.x;
				particlepos.y = snowman_pos2.y;

				if (snowman_hp2 < 0)
				{
					enemylive2 = false;
					snowman_hp2 = 20;
					snowman_pos2.x = 400000000;
				}
			}

			// �Ⴞ���3
			if (collision.square_square(Snowman_Stage2[3], use_snowball[0]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp3 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos3.x;
				particlepos.y = snowman_pos3.y;

				if (snowman_hp3 < 0)
				{
					enemylive3 = false;
					snowman_hp3 = 20;
					snowman_pos3.x = 400000000;
				}
			}

			if (collision.square_square(Snowman_Stage2[3], use_snowball[1]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp3 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos3.x;
				particlepos.y = snowman_pos3.y;

				if (snowman_hp3 < 0)
				{
					enemylive3 = false;
					snowman_hp3 = 20;
					snowman_pos3.x = 400000000;
				}
			}

			if (collision.square_square(Snowman_Stage2[3], use_snowball[2]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp3 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos3.x;
				particlepos.y = snowman_pos3.y;

				if (snowman_hp3 < 0)
				{
					enemylive3 = false;
					snowman_hp3 = 20;
					snowman_pos3.x = 400000000;
				}
			}

			// �Ⴞ���3
			if (collision.square_square(Snowman_Stage2[4], use_snowball[0]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp4 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos4.x;
				particlepos.y = snowman_pos4.y;

				if (snowman_hp4 < 0)
				{
					enemylive4 = false;
					snowman_hp4 = 20;
					snowman_pos4.x = 400000000;
				}
			}

			if (collision.square_square(Snowman_Stage2[4], use_snowball[1]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp4 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos4.x;
				particlepos.y = snowman_pos4.y;

				if (snowman_hp4 < 0)
				{
					enemylive4 = false;
					snowman_hp4 = 20;
					snowman_pos4.x = 400000000;
				}
			}

			if (collision.square_square(Snowman_Stage2[4], use_snowball[2]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp4 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos4.x;
				particlepos.y = snowman_pos4.y;

				if (snowman_hp4 < 0)
				{
					enemylive4 = false;
					snowman_hp4 = 20;
					snowman_pos4.x = 400000000;
				}
			}

			// �N���X�}�X�c���[1
			if (collision.square_square(Star_Stage2[1], use_snowball[0]) == true) {
				star_monster_hp1 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = star_pos1.x;
				particlepos.y = star_pos1.y;
				if (star_monster_hp1 < 0)
				{
					enemylive5 = false;
					star_monster_hp1 = 40;
					star_pos1.x = 400000000;
				}
			}

			if (collision.square_square(Star_Stage2[1], use_snowball[1]) == true) {
				star_monster_hp1 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = star_pos1.x;
				particlepos.y = star_pos1.y;
				if (star_monster_hp1 < 0)
				{
					enemylive5 = false;
					star_monster_hp1 = 40;
					star_pos1.x = 400000000;
				}
			}

			if (collision.square_square(Star_Stage2[1], use_snowball[2]) == true) {
				star_monster_hp1 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = star_pos1.x;
				particlepos.y = star_pos1.y;
				if (star_monster_hp1 < 0)
				{
					enemylive5 = false;
					star_monster_hp1 = 40;
					star_pos1.x = 400000000;
				}
			}

			// �N���X�}�X�c���[2
			if (collision.square_square(Star_Stage2[2], use_snowball[0]) == true) {
				star_monster_hp2 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = star_pos2.x;
				particlepos.y = star_pos2.y;
				if (star_monster_hp2 < 0)
				{
					enemylive6 = false;
					star_monster_hp2 = 40;
					star_pos2.x = 400000000;
				}
			}

			if (collision.square_square(Star_Stage2[2], use_snowball[1]) == true) {
				star_monster_hp2 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = star_pos2.x;
				particlepos.y = star_pos2.y;
				if (star_monster_hp2 < 0)
				{
					enemylive6 = false;
					star_monster_hp2 = 40;
					star_pos2.x = 400000000;
				}
			}

			if (collision.square_square(Star_Stage2[2], use_snowball[2]) == true) {
				star_monster_hp2 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = star_pos2.x;
				particlepos.y = star_pos2.y;
				if (star_monster_hp2 < 0)
				{
					enemylive6 = false;
					star_monster_hp2 = 40;
					star_pos2.x = 400000000;
				}
			}

			// �g�i�J�C1
			if (collision.square_square(Tonakai_Stage2[1], use_snowball[0]) == true) {
				tonakai_hp1 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = tonakai_pos1.x;
				particlepos.y = tonakai_pos1.y;
				if (tonakai_hp1 < 0)
				{
					enemylive7 = false;
					tonakai_hp1 = 60;
					tonakai_pos1.x = 400000000;
				}
			}

			if (collision.square_square(Tonakai_Stage2[1], use_snowball[1]) == true) {
				tonakai_hp1 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = tonakai_pos1.x;
				particlepos.y = tonakai_pos1.y;
				if (tonakai_hp1 < 0)
				{
					enemylive7 = false;
					tonakai_hp1 = 60;
					tonakai_pos1.x = 400000000;
				}
			}

			if (collision.square_square(Tonakai_Stage2[1], use_snowball[2]) == true) {
				tonakai_hp1 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = tonakai_pos1.x;
				particlepos.y = tonakai_pos1.y;
				if (tonakai_hp1 < 0)
				{
					enemylive7 = false;
					tonakai_hp1 = 60;
					tonakai_pos1.x = 400000000;
				}
			}

			// �g�i�J�C2
			if (collision.square_square(Tonakai_Stage2[2], use_snowball[0]) == true) {
				tonakai_hp2 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = tonakai_pos2.x;
				particlepos.y = tonakai_pos2.y;
				if (tonakai_hp2 < 0)
				{
					enemylive8 = false;
					tonakai_hp2 = 60;
					tonakai_pos2.x = 400000000;
				}
			}

			if (collision.square_square(Tonakai_Stage2[2], use_snowball[1]) == true) {
				tonakai_hp2 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = tonakai_pos2.x;
				particlepos.y = tonakai_pos2.y;
				if (tonakai_hp2 < 0)
				{
					enemylive8 = false;
					tonakai_hp2 = 60;
					tonakai_pos2.x = 400000000;
				}
			}

			if (collision.square_square(Tonakai_Stage2[2], use_snowball[2]) == true) {
				tonakai_hp2 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = tonakai_pos2.x;
				particlepos.y = tonakai_pos2.y;
				if (tonakai_hp2 < 0)
				{
					enemylive8 = false;
					tonakai_hp2 = 60;
					tonakai_pos2.x = 400000000;
				}
			}

			//�p�[�e�B�N���A�j���[�V����
			if (particleFg)
			{
				particlecount++;
				if (particlecount % 5 == 0)
				{
					//particleFg = false;
					particle.numU++;
					if (particle.numU > 7)
					{
						particle.numU = 0;
						particleFg = false;
					}
				}

			}

			// �W�����v
			if (input.GetKeyTrigger(VK_SPACE) && jump == 0 || input.GetButtonTrigger(XINPUT_A) && jump == 0) {
				if (direction == 0) { // �E����
					if (bugPower == 0) {
						santaImage = 10;
						jump = 1;
						santa_Huro[2].numU = 0;
						santa_Huro[2].numV = 0;
					}
					else if (bugPower > 0) {
						santaImage = 12;
						jump = 2;
						santa_Nor[3].numU = 0;
						santa_Nor[3].numV = 0;
					}
				}
				else if (direction == 1) { // �E����
					if (bugPower == 0) {
						santaImage = 10;
						jump = 1;
						santa_Nor[2].numU = 0;
						santa_Nor[2].numV = 1;
					}
					else if (bugPower > 0) {
						santaImage = 12;
						jump = 2;
						santa_Nor[3].numU = 0;
						santa_Nor[3].numV = 1;
					}
				}
				get_jump_old = santa_huro_pos.y;

				jumpVelocity = 10.0f;

			}


			// �d��
			if (jump == 0) {
				santa_huro_pos.y += jumpVelocity;
				//	 �d�͂𑬓x�ɓK�p
				jumpVelocity += gravity;
				/*santa_kin_pos.y -= 2.0f;*/
			}


			//�W�����v����
			if (jump == 1 || jump == 2) {

				if (santa_huro_pos.y >= get_jump_old + 100.5f && jump == 1 || santa_huro_pos.y >= get_jump_old + 100.0f && jump == 2) {
					jump = 3;
				}
				else if (santa_huro_pos.y <= get_jump_old + 175.0f && jump == 1 || santa_huro_pos.y <= get_jump_old + 175.0f && jump == 2) {
					/*santa_kin_pos.y += 7.50;*/
					santa_huro_pos.y += jumpVelocity;
					//	 �d�͂𑬓x�ɓK�p
					jumpVelocity += gravity;
				}

			}
			if (jump == 3) {

				glideFg = true;
				if (input.GetKeyPress(VK_Q) && bugPower <= 0 || input.GetButtonPress(XINPUT_X) && bugPower <= 0)
				{
					santaImage = 16;
					glideFg = true;
					santa_huro_pos.y -= 1.5f;

					if (direction == 0) { // �E����
						santa_Huro[7].numU = 0;
						santa_Huro[7].numV = 0;
					}
					else if (direction == 1) { // ������
						santa_Huro[7].numU = 0;
						santa_Huro[7].numV = 1;
					}

				}
				else
				{
					santa_huro_pos.y += jumpVelocity;
					//	 �d�͂𑬓x�ɓK�p
					jumpVelocity += gravity;
					glideFg = false;
				}


				if (collision.ground_santa(Ground_Stge2[1], santa_Huro[0], 50.0f, 0.0f) == true ||
					collision.ground_santa(Ground_Stge2[2], santa_Huro[0], 50.0f, 0.0f) == true ||
					collision.ground_santa(Ground_Stge2[3], santa_Huro[0], 50.0f, 0.0f) == true ||
					collision.ground_santa(Ground_Stge2[4], santa_Huro[0], 50.0f, 0.0f) == true ||
					collision.ground_santa(Ground_Stge2[5], santa_Huro[0], 50.0f, 0.0f) == true ||
					collision.block_santa(stairs[1], santa_Huro[0], 100.0f, 0.0f) == true ||
					collision.block_santa(stairs[2], santa_Huro[0], 100.0f, 0.0f) == true ||
					collision.block_santa(stairs[3], santa_Huro[0], 100.0f, 0.0f) == true ||
					collision.block_santa(stairs[4], santa_Huro[0], 100.0f, 0.0f) == true ||
					collision.tree_santa(tree, santa_Huro[0], 1000.0f, 0.0f) == true)
				{

					jump = 0;
					jumpVelocity = 0.0f;
					glideFg = false;
					if (bugPower > 0) {
						santaImage = 9;
					}
					else if (bugPower == 0) {
						santaImage = 8;
					}
				}
			}
			
			// �ŗL�\�͔����I�I�I�I�I�I�I
			if (bugPower > 0 && input.GetKeyTrigger(VK_Q) && glideFg == false && !wazafg || bugPower > 0 && input.GetButtonTrigger(XINPUT_X) && glideFg == false && !wazafg) { // �܂�����ۂ̎�

				santaImage = 15;
				if (changeRight_SP == true)
				{
					//������
					santa_Huro[6].numU = 0;
					santa_Huro[6].numV = 0;
					SantaAttackFg = true;
					changeRight_SP = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���
				}
			}

			if (SantaAttackFg == true)
			{
				framcount3++; //�t���[���J�E���g
				if (framcount3 % 10 == 0) //�P�O�t���[���Ɉ��s����
				{
					santa_Huro[6].numU++;
					if (santa_Huro[6].numU >= 5)
					{
						santa_Huro[6].numU = 0;
						SantaAttackFg = false;
						changeRight_SP = true;
						santaImage = 15;
						sound.Play(SOUND_huroshiki);
						ui = true;
					}
				}

			}
			//���C�~�̒��g����Ƃ��̔\��
			if (ui == true && glideFg == false && bugPower != 0 && !wazafg)
			{
				santa_huro_pos.y += 20;
				if (santa_huro_pos1.y >= 200 && glideFg == false)
				{
					ui = false;
					wazafg = true;
				}
			}
			if (wazafg)
			{
				if (santa_huro_pos1.y <= -140)
				{
					wazafg = false;
				}
			}

			speed = 5;
			//�E�ړ�
			if (sp_ani == false && gameoverFg == false && collision.canMoveRight && input.GetKeyPress(VK_D) && pauseFg == false
				&& SantaAttackFg == false || gameoverFg == false && collision.canMoveRight && input.GetLeftAnalogStick().x >= 0.1 && pauseFg == false)
			{
				direction = 0; // ����
				santa_huro_pos.x += 5;//�E�ړ�
				/*santa_kin_pos.x += 5;
				santa_pos.x += 5;*/


				if (bugPower == 0 && glideFg == false) {
					santaImage = 8;
					if (changeRight_SP_1 == true && glideFg == false)
					{
						//������
						santa_Huro[0].numU = 0;
						santa_Huro[0].numV = 0;
						changeRight_SP_1 = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���
					}
					framcount6++; //�t���[���J�E���g
					if (framcount6 % 10 == 0 && glideFg == false) //�P�O�t���[���Ɉ��s����
					{
						santa_Huro[0].numU++;
						if (santa_Huro[0].numU >= 4)
						{
							santa_Huro[0].numU = 0;
							santa_Huro[0].numV++;
							if (santa_Huro[0].numV >= 2)
							{
								santa_Huro[0].numV = 0;
							}
						}
					}
				}
				else if (bugPower > 0 && glideFg == false) {
					santaImage = 9;
					if (changeRight == true && glideFg == false)
					{
						//������
						santa_Huro[1].numU = 0;
						santa_Huro[1].numV = 0;
						changeRight = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���
					}
					framcount++; //�t���[���J�E���g
					if (framcount % 10 == 0 && glideFg == false) //�P�O�t���[���Ɉ��s����
					{
						santa_Huro[1].numU++;
						if (santa_Huro[1].numU >= 4)
						{
							santa_Huro[1].numU = 0;
							santa_Huro[1].numV++;
							if (santa_Huro[1].numV >= 2)
							{
								santa_Huro[1].numV = 0;
							}
						}
					}

				}
				if (santa_pos.x >= 0) //�v���C���[����ʐ^�񒆂ɍs�����Ƃ�
				{
					santa_huro_pos.x -= 5;

					//�w�i�Ȃǂ����ɓ������ăv���C���[���E�ɓ����Ă�悤�Ɍ�����
					//�R
					mounten_pos1.x -= speed - 4.5;
					mounten_pos2.x -= speed - 4.5;
					mounten_pos3.x -= speed - 4.5;
					mounten_pos4.x -= speed - 4.5;
					//�n��
					ground_pos1.x -= speed;
					ground_pos2.x -= speed;
					ground_pos3.x -= speed;
					ground_pos4.x -= speed;
					ground_pos5.x -= speed;
					ground_pos6.x -= speed;
					ground_pos7.x -= speed;
					//��
					tree_pos1.x -= speed;
					tree_pos2.x -= speed;
					//����
					block_pos1.x -= speed;
					//���
					icicle_pos1.x -= speed;
					icicle_pos2.x -= speed;
					icicle_pos3.x -= speed;
					//�K�i
					stairs_pos1.x -= speed;
					stairs_pos2.x -= speed;
					stairs_pos3.x -= speed;
					stairs_pos4.x -= speed;
					stairs_pos5.x -= speed;

					//�v���[���g
					present_pos1.x -= speed;
					present_pos2.x -= speed;
					present_pos3.x -= speed;

					bigpresent_pos1.x -= speed;
					//�󂹂��
					breakrock_pos1.x -= speed;
					moji_pos.x -= speed;
					//�����
					rock_pos1.x -= speed;
					rock_pos2.x -= speed;
					rock_pos3.x -= speed;
					rock_pos4.x -= speed;
					rock_pos5.x -= speed;
					rock_pos6.x -= speed;

					//������
					snowball_pos1.x -= speed;
					snowball_pos2.x -= speed;
					snowball_pos3.x -= speed;

					//�G
					snowman_pos1.x -= speed;
					snowman_pos2.x -= speed;
					snowman_pos3.x -= speed;
					snowman_pos4.x -= speed;

					star_pos1.x -= speed;
					star_pos2.x -= speed;

					tonakai_pos1.x -= speed;
					tonakai_pos2.x -= speed;

					wall_pos1.x -= speed;
					wall_pos2.x -= speed;

					goal_pos.x -= speed;

				}
			}
			else
			{
				//�L�[�𗣂���true�ɖ߂�
				if (sp_ani == false && changeRight_SP_1 == false && glideFg == false) {

					santa_Huro[0].numU = 0;
					santa_Huro[0].numV = 0;
					santa_Huro[1].numU = 0;
					santa_Huro[1].numV = 0;
					if (bugPower > 0) {
						santaImage = 9;
					}
					else if (bugPower == 0) {
						santaImage = 8;
					}

				}

				changeRight = true;
				changeRight_SP_1 = true;
			}
			//���ړ�
			if (sp_ani == false && gameoverFg == false && collision.canMoveLeft && input.GetKeyPress(VK_A) && pauseFg == false
				&& SantaAttackFg == false || gameoverFg == false && collision.canMoveLeft && input.GetLeftAnalogStick().x <= -0.1 && pauseFg == false)
			{

				direction = 1; // ����
				santa_huro_pos.x -= 5;//���ړ�


				if (bugPower == 0 && glideFg == false) {

					santaImage = 8;
					if (changeLeft_SP_1 == true)
					{
						//������
						santa_Huro[0].numU = 0;
						santa_Huro[0].numV = 2;
						changeLeft_SP_1 = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���
					}
					framcount6++; //�t���[���J�E���g
					if (framcount6 % 10 == 0) //�P�O�t���[���Ɉ��s����
					{
						santa_Huro[0].numU++;
						if (santa_Huro[0].numU >= 4)
						{

							santa_Huro[0].numU = 0;

						}
					}
				}
				else if (bugPower > 0 && glideFg == false) {

					if (changeLeft == true)
					{
						//������
						santa_Huro[1].numU = 0;
						santa_Huro[1].numV = 2;
						changeLeft = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���
					}
					framcount++; //�t���[���J�E���g
					if (framcount % 10 == 0) //�P�O�t���[���Ɉ��s����
					{
						santa_Huro[1].numU++;
						if (santa_Huro[1].numU >= 4)
						{
							santa_Huro[1].numU = 0;
							santa_Huro[1].numV++;
							if (santa_Huro[1].numV >= 4)
							{
								santa_Huro[1].numV = 2;
							}
						}
					}
				}

				if (santa_pos.x <= 0) //�v���C���[����ʐ^�񒆂ɍs�����Ƃ�
				{
					santa_huro_pos.x += 5;

					//�w�i�Ȃǂ����ɓ������ăv���C���[���E�ɓ����Ă�悤�Ɍ�����
					//�R
					mounten_pos1.x += speed - 4.5;
					mounten_pos2.x += speed - 4.5;
					mounten_pos3.x += speed - 4.5;
					mounten_pos4.x += speed - 4.5;
					//�n��
					ground_pos1.x += speed;
					ground_pos2.x += speed;
					ground_pos3.x += speed;
					ground_pos4.x += speed;
					ground_pos5.x += speed;
					ground_pos6.x += speed;
					ground_pos7.x += speed;
					//��
					tree_pos1.x += speed;
					tree_pos2.x += speed;
					//����
					block_pos1.x += speed;
					//���
					icicle_pos1.x += speed;
					icicle_pos2.x += speed;
					icicle_pos3.x += speed;
					//�K�i
					stairs_pos1.x += speed;
					stairs_pos2.x += speed;
					stairs_pos3.x += speed;
					stairs_pos4.x += speed;
					stairs_pos5.x += speed;

					//�v���[���g
					present_pos1.x += speed;
					present_pos2.x += speed;
					present_pos3.x += speed;

					bigpresent_pos1.x += speed;
					//�󂹂��
					breakrock_pos1.x += speed;
					moji_pos.x += speed;
					//�����
					rock_pos1.x += speed;
					rock_pos2.x += speed;
					rock_pos3.x += speed;
					rock_pos4.x += speed;
					rock_pos5.x += speed;
					rock_pos6.x += speed;

					//������
					snowball_pos1.x += speed;
					snowball_pos2.x += speed;
					snowball_pos3.x += speed;

					//�G
					snowman_pos1.x += speed;
					snowman_pos2.x += speed;
					snowman_pos3.x += speed;
					snowman_pos4.x += speed;

					star_pos1.x += speed;
					star_pos2.x += speed;

					tonakai_pos1.x += speed;
					tonakai_pos2.x += speed;

					wall_pos1.x += speed;
					wall_pos2.x += speed;



					goal_pos.x += speed;

				}
			}
			else
			{
				//�L�[�𗣂���true�ɖ߂�
				if (sp_ani == false && changeLeft_SP_1 == false) {
					santa_Huro[0].numU = 0;
					santa_Huro[0].numV = 2;
					santa_Huro[1].numU = 0;
					santa_Huro[1].numV = 2;
					if (bugPower > 0) {
						santaImage = 9;
					}
					else if (bugPower == 0) {
						santaImage = 8;
					}
				}
				changeLeft = true;
				changeLeft_SP_1 = true;
			}

		}
		//�В�
		if (santa_bug == 2)
		{
			santa_huro_pos.x = santa_kin_pos.x;
			santa_pos.x = santa_kin_pos.x;

			santa_huro_pos.y = santa_kin_pos.y;
			santa_pos.y = santa_kin_pos.y;

			// �Ⴞ��܂Ƃ̓����蔻��ǉ� 
			if (collision.enemy_santa(Snowman_Stage2[1], santa_Kin[0], 200.0f, 0.0f) && HitFg == false && pauseFg == false && gameoverFg == false)
			{
				time -= 5;
				hitcooltime = 0;
				sound.Play(SOUND_LABEL_SE000);
				damage5 = true;
				HitFg = true;

			}

			if (collision.enemy_santa(Snowman_Stage2[2], santa_Kin[0], 200.0f, 0.0f) && HitFg == false && pauseFg == false && gameoverFg == false)
			{

				time -= 5;
				hitcooltime = 0;
				sound.Play(SOUND_LABEL_SE000);
				damage5 = true;
				HitFg = true;
			}

			if (collision.enemy_santa(Snowman_Stage2[3], santa_Kin[0], 200.0f, 0.0f) && HitFg == false && pauseFg == false && gameoverFg == false)
			{
				time -= 5;
				hitcooltime = 0;
				sound.Play(SOUND_LABEL_SE000);
				damage5 = true;
				HitFg = true;
			}

			if (collision.enemy_santa(Snowman_Stage2[4], santa_Kin[0], 200.0f, 0.0f) && HitFg == false && pauseFg == false && gameoverFg == false)
			{

				time -= 5;
				hitcooltime = 0;
				sound.Play(SOUND_LABEL_SE000);
				damage5 = true;
				HitFg = true;
			}

			// ���Ƃ̓����蔻��ǉ� 
			if (collision.enemy_santa(Star_Stage2[1], santa_Kin[0], 200.0f, 0.0f) && HitFg == false && pauseFg == false && gameoverFg == false)
			{
				time -= 5;
				hitcooltime = 0;
				sound.Play(SOUND_LABEL_SE000);
				damage5 = true;
				HitFg = true;
			}

			if (collision.enemy_santa(Star_Stage2[2], santa_Kin[0], 200.0f, 0.0f) && HitFg == false && pauseFg == false && gameoverFg == false)
			{
				time -= 5;
				hitcooltime = 0;
				sound.Play(SOUND_LABEL_SE000);
				damage5 = true;
				HitFg = true;
			}

			//�g�i�J�C �Ƃ̓����蔻��ǉ� 

			if (collision.enemy_santa(Tonakai_Stage2[1], santa_Kin[0], 200.0f, 0.0f) && HitFg == false && pauseFg == false && gameoverFg == false)
			{
				time -= 5;
				hitcooltime = 0;
				sound.Play(SOUND_LABEL_SE000);
				damage5 = true;
				HitFg = true;
			}

			if (collision.enemy_santa(Tonakai_Stage2[2], santa_Kin[0], 200.0f, 0.0f) && HitFg == false && pauseFg == false && gameoverFg == false)
			{
				time -= 5;
				hitcooltime = 0;
				sound.Play(SOUND_LABEL_SE000);
				damage5 = true;
				HitFg = true;
			}
			if (rocklive)
			{
				if (collision.tree_santa(Breakrock_Stge2[1], santa_Kin[0], 200.0f, 50.0f))
				{
					if (santa_huro_pos.y > breakrock_pos1.y + Breakrock_Stge2[1].GetSize().y / 2.0f) {

						santa_huro_pos.y = breakrock_pos1.y + Breakrock_Stge2[1].GetSize().y / 2.0f + santa_Kin[0].GetSize().y / 2.0f;
						tachFg = true;
					}
					else {
						tachFg = false;
					}

					//// �T���^���؂̉E���ɂԂ������ꍇ
					if (santa_kin_pos.x < breakrock_pos1.x && tachFg == false)
					{
						collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
					}
					// �T���^���؂̍����ɂԂ������ꍇ
					if (santa_kin_pos.x > breakrock_pos1.x && tachFg == false)
					{

						collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
					}
				}
			}



			// �؂Ƃ̓����蔻��̒ǉ��@�S���C
			if (collision.tree_santa(Tree_Stge2[1], santa_Kin[0], 200.0f, 0.0f))
			{

				//// �T���^���؂̉E���ɂԂ������ꍇ
				if (santa_kin_pos.x < tree_pos1.x)
				{
					collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
				}
				// �T���^���؂̍����ɂԂ������ꍇ
				if (santa_kin_pos.x > tree_pos1.x)
				{

					collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
				}
			}

			if (collision.tree_santa(Tree_Stge2[2], santa_Kin[0], 200.0f, 0.0f))
			{

				//// �T���^���؂̉E���ɂԂ������ꍇ
				if (santa_kin_pos.x < tree_pos2.x)
				{
					collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
				}
				// �T���^���؂̍����ɂԂ������ꍇ
				if (santa_kin_pos.x > tree_pos2.x)
				{
					collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~

				}
			}

			if (collision.tree_santa(invisiblewall[3], santa_Kin[0], 200.0f, 0.0f))
			{

				//// �T���^���؂̉E���ɂԂ������ꍇ
				if (santa_kin_pos.x < wall_pos1.x)
				{
					collision.canMoveRight = false; //�E�Ɉړ����Ȃ�ړ����~
				}

				// �T���^���؂̍����ɂԂ������ꍇ
				if (santa_kin_pos.x > wall_pos1.x)
				{
					collision.canMoveLeft = false; //�E�Ɉړ����Ȃ�ړ����~
				}
			}

			if (collision.tree_santa(invisiblewall[4], santa_Kin[0], 200.0f, 0.0f))
			{

				//// �T���^���؂̉E���ɂԂ������ꍇ
				if (santa_kin_pos.x < wall_pos2.x)
				{
					collision.canMoveRight = false; //�E�Ɉړ����Ȃ�ړ����~
				}

				// �T���^���؂̍����ɂԂ������ꍇ
				if (santa_kin_pos.x > wall_pos2.x)
				{
					collision.canMoveLeft = false; //�E�Ɉړ����Ȃ�ړ����~
				}
			}

			if (collision.block_santa(Stairs_Stge2[1], santa_Kin[0], 100.0f, 0.0f))
			{
				if (santa_kin_pos.y > stairs_pos1.y + Stairs_Stge2[1].GetSize().y / 2.0f) {
					santa_kin_pos.y = stairs_pos1.y + Stairs_Stge2[1].GetSize().y / 2.0f + santa_Kin[0].GetSize().y / 2.0f;
					/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
				}
				else {
					/*std::cout << "\nSanta is falling." << std::endl;*/
				}

				if (santa_kin_pos.x < stairs_pos1.x)
				{
					collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
				}

				// �T���^���Ԃ������ꍇ
				if (santa_kin_pos.x > stairs_pos1.x)
				{
					collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
				}
			}

			if (collision.block_santa(Stairs_Stge2[2], santa_Kin[0], 100.0f, 0.0f))
			{
				if (santa_kin_pos.y > stairs_pos2.y + Stairs_Stge2[2].GetSize().y / 2.0f) {
					santa_kin_pos.y = stairs_pos2.y + Stairs_Stge2[2].GetSize().y / 2.0f + santa_Kin[0].GetSize().y / 2.0f;
					/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
				}
				else {
					/*std::cout << "\nSanta is falling." << std::endl;*/
				}

				if (santa_kin_pos.x < stairs_pos2.x)
				{
					collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
				}

				// �T���^���Ԃ������ꍇ
				if (santa_kin_pos.x > stairs_pos2.x)
				{
					collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
				}
			}

			if (collision.block_santa(Stairs_Stge2[3], santa_Kin[0], 100.0f, 0.0f))
			{
				if (santa_kin_pos.y > stairs_pos3.y + Stairs_Stge2[3].GetSize().y / 2.0f) {
					santa_kin_pos.y = stairs_pos3.y + Stairs_Stge2[3].GetSize().y / 2.0f + santa_Kin[0].GetSize().y / 2.0f;
					/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
				}
				else {
					/*std::cout << "\nSanta is falling." << std::endl;*/
				}

				if (santa_kin_pos.x < stairs_pos3.x)
				{
					collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
				}

				// �T���^���Ԃ������ꍇ
				if (santa_kin_pos.x > stairs_pos3.x)
				{
					collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
				}
			}

			if (collision.block_santa(Stairs_Stge2[4], santa_Kin[0], 100.0f, 0.0f))
			{
				if (santa_kin_pos.y > stairs_pos4.y + Stairs_Stge2[4].GetSize().y / 2.0f) {
					santa_kin_pos.y = stairs_pos4.y + Stairs_Stge2[4].GetSize().y / 2.0f + santa_Kin[0].GetSize().y / 2.0f;
					/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
				}
				else {
					/*std::cout << "\nSanta is falling." << std::endl;*/
				}

				if (santa_kin_pos.x < stairs_pos4.x)
				{
					collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
				}

				// �T���^���Ԃ������ꍇ
				if (santa_kin_pos.x > stairs_pos4.x)
				{
					collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
				}
			}

			if (collision.block_santa(Stairs_Stge2[5], santa_Kin[0], 100.0f, 0.0f))
			{
				if (santa_kin_pos.y > stairs_pos5.y + Stairs_Stge2[5].GetSize().y / 2.0f) {
					santa_kin_pos.y = stairs_pos5.y + Stairs_Stge2[5].GetSize().y / 2.0f + santa_Kin[0].GetSize().y / 2.0f;
					/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
				}
				else {
					/*std::cout << "\nSanta is falling." << std::endl;*/
				}

				if (santa_kin_pos.x < stairs_pos5.x && santa_kin_pos.y / 2 < stairs_pos5.y / 3)
				{
					collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
				}

				// �T���^���Ԃ������ꍇ
				if (santa_kin_pos.x > stairs_pos5.x && santa_kin_pos.y / 2 < stairs_pos5.y / 3)
				{
					collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
				}
			}




			//�v���[���g�̓����蔻��
			if (collision.item_santa(Present_Stage2[1], santa_Kin[0], 100.0f, 0.0f) && pauseFg == false)

			{
				presentcount += 1;
				score += 5000;
				present_pos1.y = 100000;
				sound.Play(SOUND_present);
			}

			if (collision.item_santa(Present_Stage2[2], santa_Kin[0], 100.0f, 0.0f))
			{
				presentcount += 1;
				score += 5000;
				present_pos2.y = 100000;
				sound.Play(SOUND_present);
			}

			if (collision.item_santa(Present_Stage2[3], santa_Kin[0], 100.0f, 0.0f))
			{
				presentcount += 1;
				score += 5000;
				present_pos3.y = 100000;
				sound.Play(SOUND_present);
			}

			if (collision.item_santa(BigPresent_Stage2[1], santa_Kin[0], 100.0f, 0.0f))
			{
				bigpresentcount += 1;
				score += 10000;
				bigpresent_pos1.y = 100000;
				sound.Play(SOUND_present);
			}
			// �n�ʂƂ̓����蔻��̒ǉ� �S���C


			if (collision.ground_santa(Ground_Stge2[1], santa_Kin[0], 50.0f, 0.0f)) {

				//// �T���^���n�ʂ̏�ɂ���ꍇ
				if (santa_kin_pos.y > ground_pos1.y + Ground_Stge2[1].GetSize().y / 2.0f) {
					santa_kin_pos.y = ground_pos1.y + Ground_Stge2[1].GetSize().y / 2.0f + santa_Kin[0].GetSize().y / 2.0f;
					jumpVelocity = 0.0f;
					/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
				}
				else {
					/*std::cout << "\nSanta is falling." << std::endl;*/
				}

				// �T���^���n�ʂ̉E���ɂԂ������ꍇ
				if (santa_kin_pos.x < ground_pos1.x && santa_kin_pos.y < ground_pos1.y) {

					collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
				}

				// �T���^���n�ʂɂԂ������ꍇ
				if (santa_kin_pos.x > ground_pos1.x && santa_kin_pos.y < ground_pos1.y) {
					collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
				}
			}

			if (collision.ground_santa(Ground_Stge2[2], santa_Kin[0], 50.0f, 0.0f))
			{

				//// �T���^���n�ʂ̏�ɂ���ꍇ
				if (santa_kin_pos.y > ground_pos2.y + Ground_Stge2[2].GetSize().y / 2.0f) {
					santa_kin_pos.y = ground_pos2.y + Ground_Stge2[2].GetSize().y / 2.0f + santa_Kin[0].GetSize().y / 2.0f;
					jumpVelocity = 0.0f;
					/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
				}
				else {
					/*std::cout << "\nSanta is falling." << std::endl;*/
				}

				// �T���^���n�ʂ̉E���ɂԂ������ꍇ
				if (santa_kin_pos.x < ground_pos2.x && santa_kin_pos.y < ground_pos2.y) {

					collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
				}

				// �T���^���n�ʂɂԂ������ꍇ
				if (santa_kin_pos.x > ground_pos2.x && santa_kin_pos.y < ground_pos2.y) {
					collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
				}
			}

			if (collision.ground_santa(Ground_Stge2[3], santa_Kin[0], 50.0f, 0.0f)) {

				//// �T���^���n�ʂ̏�ɂ���ꍇ
				if (santa_kin_pos.y > ground_pos3.y + Ground_Stge2[3].GetSize().y / 2.0f) {
					santa_kin_pos.y = ground_pos3.y + Ground_Stge2[3].GetSize().y / 2.0f + santa_Kin[0].GetSize().y / 2.0f;
					jumpVelocity = 0.0f;
					/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
				}
				else {
					/*std::cout << "\nSanta is falling." << std::endl;*/
				}

				// �T���^���n�ʂ̉E���ɂԂ������ꍇ
				if (santa_kin_pos.x < ground_pos3.x && santa_kin_pos.y < ground_pos3.y) {

					collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
				}

				// �T���^���n�ʂɂԂ������ꍇ
				if (santa_kin_pos.x > ground_pos3.x && santa_kin_pos.y < ground_pos3.y) {
					collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
				}
			}

			if (collision.ground_santa(Ground_Stge2[4], santa_Kin[0], 50.0f, 0.0f)) {

				//// �T���^���n�ʂ̏�ɂ���ꍇ
				if (santa_kin_pos.y > ground_pos4.y + Ground_Stge2[4].GetSize().y / 2.0f) {
					santa_kin_pos.y = ground_pos4.y + Ground_Stge2[4].GetSize().y / 2.0f + santa_Kin[0].GetSize().y / 2.0f;
					jumpVelocity = 0.0f;
					/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
				}
				else {
					/*std::cout << "\nSanta is falling." << std::endl;*/
				}

				// �T���^���n�ʂ̉E���ɂԂ������ꍇ
				if (santa_kin_pos.x < ground_pos4.x && santa_kin_pos.y < ground_pos4.y) {

					collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
				}

				// �T���^���n�ʂɂԂ������ꍇ
				if (santa_kin_pos.x > ground_pos4.x && santa_kin_pos.y < ground_pos4.y) {
					collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
				}
			}

			if (collision.ground_santa(Ground_Stge2[5], santa_Kin[0], 50.0f, 0.0f)) {

				//// �T���^���n�ʂ̏�ɂ���ꍇ
				if (santa_kin_pos.y > ground_pos5.y + Ground_Stge2[5].GetSize().y / 2.0f) {
					santa_kin_pos.y = ground_pos5.y + Ground_Stge2[5].GetSize().y / 2.0f + santa_Kin[0].GetSize().y / 2.0f;
					jumpVelocity = 0.0f;
					/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
				}
				else {
					/*std::cout << "\nSanta is falling." << std::endl;*/
				}

				// �T���^���n�ʂ̉E���ɂԂ������ꍇ
				if (santa_kin_pos.x < ground_pos5.x && santa_kin_pos.y < ground_pos5.y) {

					collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
				}

				// �T���^���n�ʂɂԂ������ꍇ
				if (santa_kin_pos.x > ground_pos5.x && santa_kin_pos.y < ground_pos5.y) {
					collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
				}
			}

			if (collision.ground_santa(Ground_Stge2[6], santa_Kin[0], 50.0f, 0.0f)) {

				//// �T���^���n�ʂ̏�ɂ���ꍇ
				if (santa_kin_pos.y > ground_pos6.y + Ground_Stge2[6].GetSize().y / 2.0f) {
					santa_kin_pos.y = ground_pos6.y + Ground_Stge2[6].GetSize().y / 2.0f + santa_Kin[0].GetSize().y / 2.0f;
					jumpVelocity = 0.0f;
					/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
				}
				else {
					/*std::cout << "\nSanta is falling." << std::endl;*/
				}

				// �T���^���n�ʂ̉E���ɂԂ������ꍇ
				if (santa_kin_pos.x < ground_pos6.x && santa_kin_pos.y < ground_pos6.y) {

					collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
				}

				// �T���^���n�ʂɂԂ������ꍇ
				if (santa_kin_pos.x > ground_pos6.x && santa_kin_pos.y < ground_pos6.y) {
					collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
				}
			}

			if (collision.ground_santa(Ground_Stge2[7], santa_Kin[0], 50.0f, 0.0f)) {

				//// �T���^���n�ʂ̏�ɂ���ꍇ
				if (santa_kin_pos.y > ground_pos7.y + Ground_Stge2[7].GetSize().y / 2.0f) {
					santa_kin_pos.y = ground_pos7.y + Ground_Stge2[7].GetSize().y / 2.0f + santa_Kin[0].GetSize().y / 2.0f;
					jumpVelocity = 0.0f;
					/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
				}
				else {
					/*std::cout << "\nSanta is falling." << std::endl;*/
				}

				// �T���^���n�ʂ̉E���ɂԂ������ꍇ
				if (santa_kin_pos.x < ground_pos7.x && santa_kin_pos.y < ground_pos7.y) {

					collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
				}

				// �T���^���n�ʂɂԂ������ꍇ
				if (santa_kin_pos.x > ground_pos7.x && santa_kin_pos.y < ground_pos7.y) {
					collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
				}
			}

			if (collision.ground_santa(Block_Stge2[1], santa_Kin[0], 50.0f, 0.0f)) {

				//// �T���^���n�ʂ̏�ɂ���ꍇ
				if (santa_kin_pos.y > block_pos1.y + Block_Stge2[1].GetSize().y / 2.0f) {
					santa_kin_pos.y = block_pos1.y + Block_Stge2[1].GetSize().y / 2.0f + santa_Kin[0].GetSize().y / 2.0f;
					jumpVelocity = 0.0f;
					/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
				}
				else {
					/*std::cout << "\nSanta is falling." << std::endl;*/
				}

				// �T���^���n�ʂ̉E���ɂԂ������ꍇ
				if (santa_kin_pos.x < block_pos1.x && santa_kin_pos.y < block_pos1.y) {

					collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
				}

				// �T���^���n�ʂɂԂ������ꍇ
				if (santa_kin_pos.x > block_pos1.x && santa_kin_pos.y < block_pos1.y) {
					collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
				}
			}



			//�S�[�������蔻��
			if (collision.goal_santa(Goal_Stage2, santa_Kin[0], 250.0f, 0.0f))
			{
				changescene = RESULT;
				gameoverFg = false;
				//������
				santa_kin_pos.x = -400;
				santa_kin_pos.y = -160;

				santa_kin_pos.x = -400;
				santa_kin_pos.y = -160;

				santa_huro_pos.x = -400;
				santa_huro_pos.y = -160;

				mounten_pos1.x = 0;
				mounten_pos2.x = 1280;
				mounten_pos3.x = 2560;

				rock_pos1.x = -275;
				rock_pos2.x = 5000;
				rock_pos3.x = 1100;
				rock_pos4.x = 2800;
				rock_pos5.x = 4000;
				rock_pos6.x = 7500;

				snowball_pos1.x = 3100;
				snowball_pos2.x = 5500;
				snowball_pos3.x = 7000;

				ground_pos1.x = 0;
				ground_pos2.x = 2000;
				ground_pos3.x = 3300;
				ground_pos4.x = 3800;
				ground_pos5.x = 4450;
				ground_pos6.x = 5300;
				ground_pos7.x = 7400;

				block_pos1.x = 2000;

				icicle_pos1.x = 1800;
				icicle_pos2.x = 2000;
				icicle_pos3.x = 2200;

				icicle_pos1.y = 100;
				icicle_pos2.y = 100;
				icicle_pos3.y = 100;

				tree_pos1.x = 900;
				tree_pos2.x = 3450;

				stairs_pos1.x = 5720;
				stairs_pos2.x = 5755;
				stairs_pos3.x = 5790;
				stairs_pos4.x = 5825;
				stairs_pos5.x = 5860;

				snowman_pos1.x = 30;
				snowman_pos2.x = 1400;
				snowman_pos3.x = 3800;
				snowman_pos4.x = 7000;

				star_pos1.x = 2000;
				star_pos2.x = 5000;

				tonakai_pos1.x = 26000;
				tonakai_pos2.x = 7500;
				bigpresent_pos1.x = 4450;
				present_pos1.x = 3300;
				present_pos2.x = 6300;
				present_pos3.x = 2000;

				breakrock_pos1.x = 4450;
				moji_pos.x = 4450;

				goal_pos.x = 7900;

				wall_pos1.x = -600;
				wall_pos2.x = 7850;

			}


			// �������̓����蔻�� ��

				// �Ⴞ��܂P
			if (collision.square_square(Snowman_Stage2[1], use_rock[0]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp1 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos1.x;
				particlepos.y = snowman_pos1.y;

				if (snowman_hp1 < 0)
				{
					enemylive1 = false;
					snowman_hp1 = 20;
					snowman_pos1.x = 400000000;
				}
			}

			if (collision.square_square(Snowman_Stage2[1], use_rock[1]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp1 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos1.x;
				particlepos.y = snowman_pos1.y;

				if (snowman_hp1 < 0)
				{
					enemylive1 = false;
					snowman_hp1 = 20;
					snowman_pos1.x = 400000000;
				}
			}

			if (collision.square_square(Snowman_Stage2[1], use_rock[2]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp1 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos1.x;
				particlepos.y = snowman_pos1.y;

				if (snowman_hp1 < 0)
				{
					enemylive1 = false;
					snowman_hp1 = 20;
					snowman_pos1.x = 400000000;
				}
			}

			// �Ⴞ��܂Q
			if (collision.square_square(Snowman_Stage2[2], use_rock[0]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp2 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos2.x;
				particlepos.y = snowman_pos2.y;

				if (snowman_hp2 < 0)
				{
					enemylive2 = false;
					snowman_hp2 = 20;
					snowman_pos2.x = 400000000;
				}
			}

			if (collision.square_square(Snowman_Stage2[2], use_rock[1]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp2 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos2.x;
				particlepos.y = snowman_pos2.y;

				if (snowman_hp2 < 0)
				{
					enemylive2 = false;
					snowman_hp2 = 20;
					snowman_pos2.x = 400000000;
				}
			}

			if (collision.square_square(Snowman_Stage2[2], use_rock[2]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp2 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos2.x;
				particlepos.y = snowman_pos2.y;

				if (snowman_hp2 < 0)
				{
					enemylive2 = false;
					snowman_hp2 = 20;
					snowman_pos2.x = 400000000;
				}
			}

			// �Ⴞ���3
			if (collision.square_square(Snowman_Stage2[3], use_rock[0]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp3 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos3.x;
				particlepos.y = snowman_pos3.y;

				if (snowman_hp3 < 0)
				{
					enemylive3 = false;
					snowman_hp3 = 20;
					snowman_pos3.x = 400000000;
				}
			}

			if (collision.square_square(Snowman_Stage2[3], use_rock[1]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp3 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos3.x;
				particlepos.y = snowman_pos3.y;

				if (snowman_hp3 < 0)
				{
					enemylive3 = false;
					snowman_hp3 = 20;
					snowman_pos3.x = 400000000;
				}
			}

			if (collision.square_square(Snowman_Stage2[3], use_rock[2]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp3 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos3.x;
				particlepos.y = snowman_pos3.y;

				if (snowman_hp3 < 0)
				{
					enemylive3 = false;
					snowman_hp3 = 20;
					snowman_pos3.x = 400000000;
				}
			}

			// �Ⴞ���3
			if (collision.square_square(Snowman_Stage2[4], use_rock[0]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp4 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos4.x;
				particlepos.y = snowman_pos4.y;

				if (snowman_hp4 < 0)
				{
					enemylive4 = false;
					snowman_hp4 = 20;
					snowman_pos4.x = 400000000;
				}
			}

			if (collision.square_square(Snowman_Stage2[4], use_rock[1]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp4 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos4.x;
				particlepos.y = snowman_pos4.y;

				if (snowman_hp4 < 0)
				{
					enemylive4 = false;
					snowman_hp4 = 20;
					snowman_pos4.x = 400000000;
				}
			}

			if (collision.square_square(Snowman_Stage2[4], use_rock[2]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp4 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos4.x;
				particlepos.y = snowman_pos4.y;

				if (snowman_hp4 < 0)
				{
					enemylive4 = false;
					snowman_hp4 = 20;
					snowman_pos4.x = 400000000;
				}
			}

			// �N���X�}�X�c���[1
			if (collision.square_square(Star_Stage2[1], use_rock[0]) == true) {
				star_monster_hp1 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = star_pos1.x;
				particlepos.y = star_pos1.y;
				if (star_monster_hp1 < 0)
				{
					enemylive5 = false;
					star_monster_hp1 = 40;
					star_pos1.x = 400000000;
				}
			}

			if (collision.square_square(Star_Stage2[1], use_rock[1]) == true) {
				star_monster_hp1 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = star_pos1.x;
				particlepos.y = star_pos1.y;
				if (star_monster_hp1 < 0)
				{
					enemylive5 = false;
					star_monster_hp1 = 40;
					star_pos1.x = 400000000;
				}
			}

			if (collision.square_square(Star_Stage2[1], use_rock[2]) == true) {
				star_monster_hp1 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = star_pos1.x;
				particlepos.y = star_pos1.y;
				if (star_monster_hp1 < 0)
				{
					enemylive5 = false;
					star_monster_hp1 = 40;
					star_pos1.x = 400000000;
				}
			}

			// �N���X�}�X�c���[2
			if (collision.square_square(Star_Stage2[2], use_rock[0]) == true) {
				star_monster_hp2 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = star_pos2.x;
				particlepos.y = star_pos2.y;
				if (star_monster_hp2 < 0)
				{
					enemylive6 = false;
					star_monster_hp2 = 40;
					star_pos2.x = 400000000;
				}
			}

			if (collision.square_square(Star_Stage2[2], use_rock[1]) == true) {
				star_monster_hp2 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = star_pos2.x;
				particlepos.y = star_pos2.y;
				if (star_monster_hp2 < 0)
				{
					enemylive6 = false;
					star_monster_hp2 = 40;
					star_pos2.x = 400000000;
				}
			}

			if (collision.square_square(Star_Stage2[2], use_rock[2]) == true) {
				star_monster_hp2 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = star_pos2.x;
				particlepos.y = star_pos2.y;
				if (star_monster_hp2 < 0)
				{
					enemylive6 = false;
					star_monster_hp2 = 40;
					star_pos2.x = 400000000;
				}
			}

			// �g�i�J�C1
			if (collision.square_square(Tonakai_Stage2[1], use_rock[0]) == true) {
				tonakai_hp1 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = tonakai_pos1.x;
				particlepos.y = tonakai_pos1.y;
				if (tonakai_hp1 < 0)
				{
					enemylive7 = false;
					tonakai_hp1 = 60;
					tonakai_pos1.x = 400000000;
				}
			}

			if (collision.square_square(Tonakai_Stage2[1], use_rock[1]) == true) {
				tonakai_hp1 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = tonakai_pos1.x;
				particlepos.y = tonakai_pos1.y;
				if (tonakai_hp1 < 0)
				{
					enemylive7 = false;
					tonakai_hp1 = 60;
					tonakai_pos1.x = 400000000;
				}
			}

			if (collision.square_square(Tonakai_Stage2[1], use_rock[2]) == true) {
				tonakai_hp1 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = tonakai_pos1.x;
				particlepos.y = tonakai_pos1.y;
				if (tonakai_hp1 < 0)
				{
					enemylive7 = false;
					tonakai_hp1 = 60;
					tonakai_pos1.x = 400000000;
				}
			}

			// �g�i�J�C2
			if (collision.square_square(Tonakai_Stage2[2], use_rock[0]) == true) {
				tonakai_hp2 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = tonakai_pos2.x;
				particlepos.y = tonakai_pos2.y;
				if (tonakai_hp2 < 0)
				{
					enemylive8 = false;
					tonakai_hp2 = 60;
					tonakai_pos2.x = 400000000;
				}
			}

			if (collision.square_square(Tonakai_Stage2[2], use_rock[1]) == true) {
				tonakai_hp2 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = tonakai_pos2.x;
				particlepos.y = tonakai_pos2.y;
				if (tonakai_hp2 < 0)
				{
					enemylive8 = false;
					tonakai_hp2 = 60;
					tonakai_pos2.x = 400000000;
				}
			}

			if (collision.square_square(Tonakai_Stage2[2], use_rock[2]) == true) {
				tonakai_hp2 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = tonakai_pos2.x;
				particlepos.y = tonakai_pos2.y;
				if (tonakai_hp2 < 0)
				{
					enemylive8 = false;
					tonakai_hp2 = 60;
					tonakai_pos2.x = 400000000;
				}
			}


			// �������̓����蔻�� ���
			// �Ⴞ��܂P
			if (collision.square_square(Snowman_Stage2[1], use_snowball[0]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp1 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos1.x;
				particlepos.y = snowman_pos1.y;

				if (snowman_hp1 < 0)
				{
					enemylive1 = false;
					snowman_hp1 = 20;
					snowman_pos1.x = 400000000;
				}
			}

			if (collision.square_square(Snowman_Stage2[1], use_snowball[1]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp1 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos1.x;
				particlepos.y = snowman_pos1.y;

				if (snowman_hp1 < 0)
				{
					enemylive1 = false;
					snowman_hp1 = 20;
					snowman_pos1.x = 400000000;
				}
			}

			if (collision.square_square(Snowman_Stage2[1], use_snowball[2]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp1 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos1.x;
				particlepos.y = snowman_pos1.y;

				if (snowman_hp1 < 0)
				{
					enemylive1 = false;
					snowman_hp1 = 20;
					snowman_pos1.x = 400000000;
				}
			}

			// �Ⴞ��܂Q
			if (collision.square_square(Snowman_Stage2[2], use_snowball[0]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp2 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos2.x;
				particlepos.y = snowman_pos2.y;

				if (snowman_hp2 < 0)
				{
					enemylive2 = false;
					snowman_hp2 = 20;
					snowman_pos2.x = 400000000;
				}
			}

			if (collision.square_square(Snowman_Stage2[2], use_snowball[1]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp2 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos2.x;
				particlepos.y = snowman_pos2.y;

				if (snowman_hp2 < 0)
				{
					enemylive2 = false;
					snowman_hp2 = 20;
					snowman_pos2.x = 400000000;
				}
			}

			if (collision.square_square(Snowman_Stage2[2], use_snowball[2]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp2 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos2.x;
				particlepos.y = snowman_pos2.y;

				if (snowman_hp2 < 0)
				{
					enemylive2 = false;
					snowman_hp2 = 20;
					snowman_pos2.x = 400000000;
				}
			}

			// �Ⴞ���3
			if (collision.square_square(Snowman_Stage2[3], use_snowball[0]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp3 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos3.x;
				particlepos.y = snowman_pos3.y;

				if (snowman_hp3 < 0)
				{
					enemylive3 = false;
					snowman_hp3 = 20;
					snowman_pos3.x = 400000000;
				}
			}

			if (collision.square_square(Snowman_Stage2[3], use_snowball[1]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp3 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos3.x;
				particlepos.y = snowman_pos3.y;

				if (snowman_hp3 < 0)
				{
					enemylive3 = false;
					snowman_hp3 = 20;
					snowman_pos3.x = 400000000;
				}
			}

			if (collision.square_square(Snowman_Stage2[3], use_snowball[2]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp3 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos3.x;
				particlepos.y = snowman_pos3.y;

				if (snowman_hp3 < 0)
				{
					enemylive3 = false;
					snowman_hp3 = 20;
					snowman_pos3.x = 400000000;
				}
			}

			// �Ⴞ���3
			if (collision.square_square(Snowman_Stage2[4], use_snowball[0]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp4 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos4.x;
				particlepos.y = snowman_pos4.y;

				if (snowman_hp4 < 0)
				{
					enemylive4 = false;
					snowman_hp4 = 20;
					snowman_pos4.x = 400000000;
				}
			}

			if (collision.square_square(Snowman_Stage2[4], use_snowball[1]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp4 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos4.x;
				particlepos.y = snowman_pos4.y;

				if (snowman_hp4 < 0)
				{
					enemylive4 = false;
					snowman_hp4 = 20;
					snowman_pos4.x = 400000000;
				}
			}

			if (collision.square_square(Snowman_Stage2[4], use_snowball[2]) == true) {
				sound.Play(SOUND_LABEL_SE004);
				snowman_hp4 -= santa_atk;

				particleFg = true;
				particlepos.x = snowman_pos4.x;
				particlepos.y = snowman_pos4.y;

				if (snowman_hp4 < 0)
				{
					enemylive4 = false;
					snowman_hp4 = 20;
					snowman_pos4.x = 400000000;
				}
			}

			// �N���X�}�X�c���[1
			if (collision.square_square(Star_Stage2[1], use_snowball[0]) == true) {
				star_monster_hp1 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = star_pos1.x;
				particlepos.y = star_pos1.y;
				if (star_monster_hp1 < 0)
				{
					enemylive5 = false;
					star_monster_hp1 = 40;
					star_pos1.x = 400000000;
				}
			}

			if (collision.square_square(Star_Stage2[1], use_snowball[1]) == true) {
				star_monster_hp1 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = star_pos1.x;
				particlepos.y = star_pos1.y;
				if (star_monster_hp1 < 0)
				{
					enemylive5 = false;
					star_monster_hp1 = 40;
					star_pos1.x = 400000000;
				}
			}

			if (collision.square_square(Star_Stage2[1], use_snowball[2]) == true) {
				star_monster_hp1 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = star_pos1.x;
				particlepos.y = star_pos1.y;
				if (star_monster_hp1 < 0)
				{
					enemylive5 = false;
					star_monster_hp1 = 40;
					star_pos1.x = 400000000;
				}
			}

			// �N���X�}�X�c���[2
			if (collision.square_square(Star_Stage2[2], use_snowball[0]) == true) {
				star_monster_hp2 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = star_pos2.x;
				particlepos.y = star_pos2.y;
				if (star_monster_hp2 < 0)
				{
					enemylive6 = false;
					star_monster_hp2 = 40;
					star_pos2.x = 400000000;
				}
			}

			if (collision.square_square(Star_Stage2[2], use_snowball[1]) == true) {
				star_monster_hp2 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = star_pos2.x;
				particlepos.y = star_pos2.y;
				if (star_monster_hp2 < 0)
				{
					enemylive6 = false;
					star_monster_hp2 = 40;
					star_pos2.x = 400000000;
				}
			}

			if (collision.square_square(Star_Stage2[2], use_snowball[2]) == true) {
				star_monster_hp2 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = star_pos2.x;
				particlepos.y = star_pos2.y;
				if (star_monster_hp2 < 0)
				{
					enemylive6 = false;
					star_monster_hp2 = 40;
					star_pos2.x = 400000000;
				}
			}

			// �g�i�J�C1
			if (collision.square_square(Tonakai_Stage2[1], use_snowball[0]) == true) {
				tonakai_hp1 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = tonakai_pos1.x;
				particlepos.y = tonakai_pos1.y;
				if (tonakai_hp1 < 0)
				{
					enemylive7 = false;
					tonakai_hp1 = 60;
					tonakai_pos1.x = 400000000;
				}
			}

			if (collision.square_square(Tonakai_Stage2[1], use_snowball[1]) == true) {
				tonakai_hp1 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = tonakai_pos1.x;
				particlepos.y = tonakai_pos1.y;
				if (tonakai_hp1 < 0)
				{
					enemylive7 = false;
					tonakai_hp1 = 60;
					tonakai_pos1.x = 400000000;
				}
			}

			if (collision.square_square(Tonakai_Stage2[1], use_snowball[2]) == true) {
				tonakai_hp1 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = tonakai_pos1.x;
				particlepos.y = tonakai_pos1.y;
				if (tonakai_hp1 < 0)
				{
					enemylive7 = false;
					tonakai_hp1 = 60;
					tonakai_pos1.x = 400000000;
				}
			}

			// �g�i�J�C2
			if (collision.square_square(Tonakai_Stage2[2], use_snowball[0]) == true) {
				tonakai_hp2 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = tonakai_pos2.x;
				particlepos.y = tonakai_pos2.y;
				if (tonakai_hp2 < 0)
				{
					enemylive8 = false;
					tonakai_hp2 = 60;
					tonakai_pos2.x = 400000000;
				}
			}

			if (collision.square_square(Tonakai_Stage2[2], use_snowball[1]) == true) {
				tonakai_hp2 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = tonakai_pos2.x;
				particlepos.y = tonakai_pos2.y;
				if (tonakai_hp2 < 0)
				{
					enemylive8 = false;
					tonakai_hp2 = 60;
					tonakai_pos2.x = 400000000;
				}
			}

			if (collision.square_square(Tonakai_Stage2[2], use_snowball[2]) == true) {
				tonakai_hp2 -= santa_atk;
				sound.Play(SOUND_LABEL_SE004);
				particleFg = true;
				particlepos.x = tonakai_pos2.x;
				particlepos.y = tonakai_pos2.y;
				if (tonakai_hp2 < 0)
				{
					enemylive8 = false;
					tonakai_hp2 = 60;
					tonakai_pos2.x = 400000000;
				}
			}

			//�p�[�e�B�N���A�j���[�V����
			if (particleFg)
			{
				particlecount++;
				if (particlecount % 5 == 0)
				{
					//particleFg = false;
					particle.numU++;
					if (particle.numU > 7)
					{
						particle.numU = 0;
						particleFg = false;
					}
				}

			}

			// �W�����v
			if (input.GetKeyTrigger(VK_SPACE) && jump == 0 || input.GetButtonTrigger(XINPUT_A) && jump == 0) {
				if (direction == 0) { // �E����
					if (bugPower == 0) {
						santaImage = 19;
						jump = 1;
						santa_Kin[2].numU = 0;
						santa_Kin[2].numV = 0;
					}
					else if (bugPower > 0) {
						santaImage = 20;
						jump = 2;
						santa_Kin[3].numU = 0;
						santa_Kin[3].numV = 0;
					}
					get_jump_old = santa_kin_pos.y;
				}
				else if (direction == 1) { // �E����
					if (bugPower == 0) {
						santaImage = 19;
						jump = 1;
						santa_Kin[2].numU = 0;
						santa_Kin[2].numV = 1;
					}
					else if (bugPower > 0) {
						santaImage = 20;
						jump = 2;
						santa_Kin[3].numU = 0;
						santa_Kin[3].numV = 1;
					}
				}
				get_jump_old = santa_kin_pos.y;

				jumpVelocity = 10.0f;
			}

			// �d��
			if (jump == 0) {
				santa_kin_pos.y += jumpVelocity;
				//	 �d�͂𑬓x�ɓK�p
				jumpVelocity += gravity;
				/*santa_kin_pos.y -= 2.0f;*/
			}

			//�W�����v����
			if (jump == 1 || jump == 2) {

				if (santa_kin_pos.y >= get_jump_old + 50.0f && jump == 1 || santa_kin_pos.y >= get_jump_old + 50.0f && jump == 2) {
					jump = 3;
				}
				else if (santa_kin_pos.y <= get_jump_old + 175.0f && jump == 1 || santa_kin_pos.y <= get_jump_old + 175.0f && jump == 2) {
					/*santa_kin_pos.y += 7.50;*/
					santa_kin_pos.y += jumpVelocity;
					//	 �d�͂𑬓x�ɓK�p
					jumpVelocity += gravity;
				}

			}
			if (jump == 3) {

				santa_kin_pos.y += jumpVelocity;
				//	 �d�͂𑬓x�ɓK�p
				jumpVelocity += gravity;
				if (collision.ground_santa(Ground_Stge2[1], santa_Kin[0], 50.0f, 0.0f) == true ||
					collision.ground_santa(Ground_Stge2[2], santa_Kin[0], 50.0f, 0.0f) == true ||
					collision.ground_santa(Ground_Stge2[3], santa_Kin[0], 50.0f, 0.0f) == true ||
					collision.ground_santa(Ground_Stge2[4], santa_Kin[0], 50.0f, 0.0f) == true ||
					collision.ground_santa(Ground_Stge2[5], santa_Kin[0], 50.0f, 0.0f) == true ||
					collision.ground_santa(Ground_Stge2[6], santa_Kin[0], 50.0f, 0.0f) == true ||
					collision.ground_santa(Ground_Stge2[7], santa_Kin[0], 50.0f, 0.0f) == true ||
					collision.block_santa(Stairs_Stge2[1], santa_Kin[0], 100.0f, 0.0f) == true ||
					collision.tree_santa(tree, santa_Kin[0], 1000.0f, 0.0f) == true)
				{

					jump = 0;
					jumpVelocity = 0.0f;
				}
			}


			// �T���^���A�C�e���ɓ���������
			bool itemCollected = false; // �A�C�e�������ɉ�����ꂽ���ǂ����̃t���O


			const float rightScreen = 670.0f; // ��ʂ̉E�[
			const float leftScreen = -670.0f; // ��ʂ̍��[


			if (collision.item_santa(Collectrock_Stage2[1], santa_Kin[0], 100.0f, 0.0f) && rock_visible1 == 0)
			{

				if (input.GetKeyTrigger(VK_S) && !itemCollected && !sp_ani || input.GetButtonTrigger(XINPUT_B) && !itemCollected && !sp_ani)
				{

					item->ItemGet(1); // ��������
					bugPower = item->GetItemCnt(); // ���݂̑܂̃A�C�e��������
					itemCollected = true;
					santaImage = 4;

					rock_visible1 = 1;

				}

				//if (input.GetKeyTrigger(VK_S) && !itemCollected || input.GetButtonTrigger(XINPUT_B) && !itemCollected)
				//{
				//	/*itemID = 1;*/
				//	item->ItemGet(1); // ��������
				//	bugPower = item->GetItemCnt(); // ���݂̑܂̃A�C�e��������
				//	itemCollected = true;

				//	rock_visible1 = 1;

				//}
			}

			if (collision.item_santa(Collectrock_Stage2[2], santa_Kin[0], 100.0f, 0.0f) && rock_visible2 == 0)
			{
				if (input.GetKeyTrigger(VK_S) && !itemCollected && !sp_ani || input.GetButtonTrigger(XINPUT_B) && !itemCollected && !sp_ani)
				{

					item->ItemGet(1); // ��������
					bugPower = item->GetItemCnt(); // ���݂̑܂̃A�C�e��������
					itemCollected = true;
					santaImage = 4;

					rock_visible2 = 1;

				}
			}

			if (collision.item_santa(Collectrock_Stage2[3], santa_Kin[0], 100.0f, 0.0f) && rock_visible3 == 0)
			{
				if (input.GetKeyTrigger(VK_S) && !itemCollected && !sp_ani || input.GetButtonTrigger(XINPUT_B) && !itemCollected && !sp_ani)
				{

					item->ItemGet(1); // ��������
					bugPower = item->GetItemCnt(); // ���݂̑܂̃A�C�e��������
					itemCollected = true;
					santaImage = 4;

					rock_visible3 = 1;

				}
			}

			if (collision.item_santa(Collectrock_Stage2[4], santa_Kin[0], 100.0f, 0.0f) && rock_visible4 == 0)
			{
				if (input.GetKeyTrigger(VK_S) && !itemCollected && !sp_ani || input.GetButtonTrigger(XINPUT_B) && !itemCollected && !sp_ani)
				{

					item->ItemGet(1); // ��������
					bugPower = item->GetItemCnt(); // ���݂̑܂̃A�C�e��������
					itemCollected = true;
					santaImage = 4;

					rock_visible4 = 1;

				}
			}

			if (collision.item_santa(Collectrock_Stage2[5], santa_Kin[0], 100.0f, 0.0f) && rock_visible5 == 0)
			{
				if (input.GetKeyTrigger(VK_S) && !itemCollected && !sp_ani || input.GetButtonTrigger(XINPUT_B) && !itemCollected && !sp_ani)
				{

					item->ItemGet(1); // ��������
					bugPower = item->GetItemCnt(); // ���݂̑܂̃A�C�e��������
					itemCollected = true;
					santaImage = 4;

					rock_visible5 = 1;

				}
			}

			if (collision.item_santa(Collectrock_Stage2[6], santa_Kin[0], 100.0f, 0.0f) && rock_visible6 == 0)
			{
				if (input.GetKeyTrigger(VK_S) && !itemCollected || input.GetButtonTrigger(XINPUT_B) && !itemCollected)
				{
					if (input.GetKeyTrigger(VK_S) && !itemCollected && !sp_ani || input.GetButtonTrigger(XINPUT_B) && !itemCollected && !sp_ani)
					{

						item->ItemGet(1); // ��������
						bugPower = item->GetItemCnt(); // ���݂̑܂̃A�C�e��������
						itemCollected = true;
						santaImage = 4;

						rock_visible6 = 1;

					}
				}
			}

			if (collision.item_santa(Snowball_Stage2[1], santa_Kin[0], 100.0f, 0.0f) && snow_visible1 == 0)
			{
				if (input.GetKeyTrigger(VK_S) && !itemCollected && !sp_ani || input.GetButtonTrigger(XINPUT_B) && !itemCollected && !sp_ani)
				{
					/*itemID = 1;*/
					item->ItemGet(2); // ��������
					bugPower = item->GetItemCnt(); // ���݂̑܂̃A�C�e��������
					itemCollected = true;
					santaImage = 4;

					snow_visible1 = 1;
				}
			}

			if (collision.item_santa(Snowball_Stage2[2], santa_Kin[0], 100.0f, 0.0f) && snow_visible1 == 0)
			{
				if (input.GetKeyTrigger(VK_S) && !itemCollected && !sp_ani || input.GetButtonTrigger(XINPUT_B) && !itemCollected && !sp_ani)
				{
					/*itemID = 1;*/
					item->ItemGet(2); // ��������
					bugPower = item->GetItemCnt(); // ���݂̑܂̃A�C�e��������
					itemCollected = true;
					santaImage = 4;

					snow_visible2 = 1;
				}
			}

			if (collision.item_santa(Snowball_Stage2[3], santa_Kin[0], 100.0f, 0.0f) && snow_visible1 == 0)
			{
				if (input.GetKeyTrigger(VK_S) && !itemCollected && !sp_ani || input.GetButtonTrigger(XINPUT_B) && !itemCollected && !sp_ani)
				{
					/*itemID = 1;*/
					item->ItemGet(2); // ��������
					bugPower = item->GetItemCnt(); // ���݂̑܂̃A�C�e��������
					itemCollected = true;
					santaImage = 4;

					snow_visible3 = 1;
				}
			}

			// ��ʊO�ɍs���ƁA�A�C�e�����ăX�|�[�����鏈��
			if (leftScreen > rock_pos1.x || rock_pos1.x > rightScreen) {
				rock_visible1 = 0;
			}
			if (leftScreen > rock_pos2.x || rock_pos2.x > rightScreen) {
				rock_visible2 = 0;
			}
			if (leftScreen > rock_pos3.x || rock_pos3.x > rightScreen) {
				rock_visible3 = 0;
			}
			if (leftScreen > rock_pos4.x || rock_pos4.x > rightScreen) {
				rock_visible4 = 0;
			}
			if (leftScreen > rock_pos5.x || rock_pos5.x > rightScreen) {
				rock_visible5 = 0;
			}
			if (leftScreen > rock_pos6.x || rock_pos6.x > rightScreen) {
				rock_visible6 = 0;
			}
			if (leftScreen > snowball_pos1.x || snowball_pos1.x > rightScreen) {
				snow_visible1 = 0;
			}
			if (leftScreen > snowball_pos2.x || snowball_pos2.x > rightScreen) {
				snow_visible2 = 0;
			}
			if (leftScreen > snowball_pos3.x || snowball_pos3.x > rightScreen) {
				snow_visible3 = 0;
			}


			if (!itemCollected && !changeItem) {// �������ĂȂ��ꍇ
				if (input.GetKeyTrigger(VK_S) && pauseFg == false || input.GetButtonTrigger(XINPUT_B) && pauseFg == false)
				{

					if (item->GetItem_3() > 0) {
						changeItem = true;

						if (item->GetItem_3() == 1) {
							use_rock_pos3.x = santa_kin_pos.x;
							use_rock_pos3.y = santa_kin_pos.y;
							sound.Play(SOUND_LABEL_SE004);
							itemID_3 = 1;
							itemMove3 = true;
						}
						else if (item->GetItem_3() == 2) {
							use_snowball_pos3.x = santa_kin_pos.x;
							use_snowball_pos3.y = santa_kin_pos.y;
							sound.Play(SOUND_LABEL_SE002);
							itemID_3 = 2;
							itemMove3 = true;
						}

					}
					else if (item->GetItem_3() < 0) {

						if (item->GetItem_2() > 0) {

							if (item->GetItem_2() == 1) {
								use_rock_pos2.x = santa_kin_pos.x;
								use_rock_pos2.y = santa_kin_pos.y;
								sound.Play(SOUND_LABEL_SE004);
								itemID_2 = 1;
								itemMove2 = true;
							}
							else if (item->GetItem_2() == 2) {
								use_snowball_pos2.x = santa_kin_pos.x;
								use_snowball_pos2.y = santa_kin_pos.y;
								sound.Play(SOUND_LABEL_SE004);
								itemID_2 = 2;
								itemMove2 = true;
							}

						}
						else if (item->GetItem_2() < 0) {

							if (item->GetItem_1() > 0) {

								if (item->GetItem_1() == 1) {
									use_rock_pos1.x = santa_kin_pos.x;
									use_rock_pos1.y = santa_kin_pos.y;
									itemID_1 = 1;
									itemMove1 = true;
								}
								else if (item->GetItem_1() == 2) {
									use_snowball_pos1.x = santa_kin_pos.x;
									use_snowball_pos1.y = santa_kin_pos.y;
									itemID_1 = 2;
									itemMove1 = true;
								}

							}
						}
					}


					item->ItemRelease(); // ���o��
					bugPower = item->GetItemCnt();
				}
			}




			if (collision.enemy_santa(Icicles_Stge2[1], santa_Kin[0], 200.0f, 0.0f) && HitFg == false && turarafall1 == true)
			{
				time -= 5;
				hitcooltime = 0;
				sound.Play(SOUND_LABEL_SE000);
				damage5 = true;
				HitFg = true;
			}

			if (collision.enemy_santa(Icicles_Stge2[2], santa_Kin[0], 200.0f, 0.0f) && HitFg == false && turarafall3 == true)
			{
				time -= 5;
				hitcooltime = 0;
				sound.Play(SOUND_LABEL_SE000);
				damage5 = true;
				HitFg = true;
			}

			if (collision.enemy_santa(Icicles_Stge2[3], santa_Kin[0], 200.0f, 0.0f) && HitFg == false && turarafall3 == true)
			{
				time -= 5;
				hitcooltime = 0;
				sound.Play(SOUND_LABEL_SE000);
				damage5 = true;
				HitFg = true;
			}

			if (!itemCollected && !changeItem) {// �������ĂȂ��ꍇ
				if (input.GetKeyTrigger(VK_S) && pauseFg == false && !sp_ani || input.GetButtonTrigger(XINPUT_B) && pauseFg == false && !sp_ani)
				{

					if (item->GetItem_3() > 0) {
						changeItem = true;

						if (item->GetItem_3() == 1) {
							use_rock_pos3.x = santa_kin_pos.x;
							use_rock_pos3.y = santa_kin_pos.y;
							sound.Play(SOUND_LABEL_SE003);
							itemID_3 = 1;
							itemMove3 = true;
						}
						else if (item->GetItem_3() == 2) {
							use_snowball_pos3.x = santa_kin_pos.x;
							use_snowball_pos3.y = santa_kin_pos.y;
							sound.Play(SOUND_LABEL_SE003);
							itemID_3 = 2;
							itemMove3 = true;
						}

					}
					else if (item->GetItem_3() < 0) {

						if (item->GetItem_2() > 0) {

							if (item->GetItem_2() == 1) {
								use_rock_pos2.x = santa_kin_pos.x;
								use_rock_pos2.y = santa_kin_pos.y;
								sound.Play(SOUND_LABEL_SE003);
								itemID_2 = 1;
								itemMove2 = true;
							}
							else if (item->GetItem_2() == 2) {
								use_snowball_pos2.x = santa_kin_pos.x;
								use_snowball_pos2.y = santa_kin_pos.y;
								sound.Play(SOUND_LABEL_SE003);
								itemID_2 = 2;
								itemMove2 = true;
							}

						}
						else if (item->GetItem_2() < 0) {

							if (item->GetItem_1() > 0) {

								if (item->GetItem_1() == 1) {
									use_rock_pos1.x = santa_kin_pos.x;
									use_rock_pos1.y = santa_kin_pos.y;
									itemID_1 = 1;
									itemMove1 = true;
								}
								else if (item->GetItem_1() == 2) {
									use_snowball_pos1.x = santa_kin_pos.x;
									use_snowball_pos1.y = santa_kin_pos.y;
									itemID_1 = 2;
									itemMove1 = true;
								}

							}
						}
					}

					santaImage = 5;
					item->ItemRelease(); // ���o��
					bugPower = item->GetItemCnt();
				}
			}


			// ����A�j���[�V����
			if (santaImage == 4) {
				getItem = 1;
				if (direction == 0) { // �E����
					if (changeRight_get == true)
					{
						//������
						santa_Nor[4].numU = 0;
						santa_Nor[4].numV = 0;
						changeRight_get = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���
					}
					framcount4++; //�t���[���J�E���g
					if (framcount4 % 4 == 0) //�P�O�t���[���Ɉ��s����
					{
						santa_Nor[4].numU++;
						if (santa_Nor[4].numU >= 5)
						{
							sp_ani = false;
							santaImage = 1;
							getItem = 0;
							santa_Nor[4].numU = 0;

						}
					}
				}
				else if (direction == 1) {
					if (changeLeft_get == true)
					{
						//������
						santa_Nor[4].numU = 0;
						santa_Nor[4].numV = 1;
						changeLeft_get = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���
					}
					framcount4++; //�t���[���J�E���g
					if (framcount4 % 4 == 0) //�P�O�t���[���Ɉ��s����
					{
						santa_Nor[4].numU++;
						if (santa_Nor[4].numU >= 5)
						{
							sp_ani = false;
							santaImage = 1;
							getItem = 0;
							santa_Nor[4].numU = 0;

						}
					}
				}
			}

			// ��o�A�j���[�V����
			if (santaImage == 5) {

				if (direction == 0) { // �E����
					if (changeRight_out == true)
					{
						//������
						santa_Nor[5].numU = 0;
						santa_Nor[5].numV = 0;
						changeRight_out = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���
					}
					framcount5++; //�t���[���J�E���g
					if (framcount5 % 4 == 0) //�P�O�t���[���Ɉ��s����
					{
						santa_Nor[5].numU++;
						if (santa_Nor[5].numU >= 5)
						{
							sp_ani = false;
							if (bugPower > 0) {
								santaImage = 1;
							}
							else if (bugPower == 0) {
								santaImage = 0;
							}

							santa_Nor[5].numU = 0;
							changeRight_out = true;

						}
					}
				}
				else if (direction == 1) {
					if (changeLeft_out == true)
					{
						//������
						santa_Nor[5].numU = 0;
						santa_Nor[5].numV = 1;
						changeLeft_out = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���
					}
					framcount5++; //�t���[���J�E���g
					if (framcount5 % 4 == 0) //�P�O�t���[���Ɉ��s����
					{
						santa_Nor[5].numU++;
						if (santa_Nor[5].numU >= 5)
						{
							sp_ani = false;
							if (bugPower > 0) {
								santaImage = 1;
							}
							else if (bugPower == 0) {
								santaImage = 0;
							}
							santa_Nor[5].numU = 0;
							changeLeft_out = true;

						}
					}
				}
			}



			// �������̓����@���̇@ 
			if (itemMove1 == true) {
				if (direction == 0) { // �E����

					if (itemID_1 == 1) { // ��

						if (itemMove1_M == true || use_rock_pos1.y >= -100.0f) {
							itemMove1_M = true;
							use_rock_pos1.y -= 3.00f;
							use_rock_pos1.x += 3.00f;
						}
						else if (itemMove1_M == false) {
							use_rock_pos1.y += 3.00f;
							use_rock_pos1.x += 3.00f;
						}
						if (use_rock_pos1.y <= -190.0f && itemMove1_M == true) {
							itemID_1 = 0;
							itemMove1_M = false;
							itemMove1 = false;
						}
					}
					else if (itemID_1 == 2) {
						if (use_snowball_pos1.x >= rightScreen) {
							itemID_1 = 0;
							itemMove1 = false;
						}
						else if (use_snowball_pos1.x <= rightScreen) {
							use_snowball_pos1.x += 20.00f;
						}
					}
				}
				else if (direction == 1) { // ������

					if (itemID_1 == 1) { // ��

						if (itemMove1_M == true || use_rock_pos1.y >= -100.0f) {
							itemMove1_M = true;
							use_rock_pos1.y -= 3.00f;
							use_rock_pos1.x -= 3.00f;
						}
						else if (itemMove1_M == false) {
							use_rock_pos1.y += 3.00f;
							use_rock_pos1.x -= 3.00f;
						}
						if (use_rock_pos1.y <= -190.0f && itemMove1_M == true) {
							itemID_1 = 0;
							itemMove1_M = false;
							itemMove1 = false;
						}
					}
					else if (itemID_1 == 2) {
						if (use_snowball_pos1.x <= leftScreen) {
							itemID_1 = 0;
							itemMove1 = false;
						}
						else if (use_snowball_pos1.x >= leftScreen) {
							use_snowball_pos1.x -= 20.00f;
						}
					}
				}



			}

			// �������̓����@���̇A
			if (itemMove2 == true) {
				if (direction == 0) { // �E����

					if (itemID_2 == 1) { //��

						if (itemMove2_M == true || use_rock_pos2.y >= -100.0f) {
							itemMove2_M = true;
							use_rock_pos2.y -= 3.00f;
							use_rock_pos2.x += 3.00f;
						}
						else if (itemMove2_M == false) {
							use_rock_pos2.y += 3.00f;
							use_rock_pos2.x += 3.00f;
						}
						if (use_rock_pos2.y <= -190.0f && itemMove2_M == true) {
							itemID_2 = 0;
							itemMove2_M = false;
							itemMove2 = false;
						}
					}
					else if (itemID_2 == 2) {
						if (use_snowball_pos2.x >= rightScreen) {
							itemID_2 = 0;
							itemMove2 = false;
						}
						else if (use_snowball_pos2.x <= rightScreen) {
							use_snowball_pos2.x += 20.00f;
						}
					}
				}
				else if (direction == 1) { // ������

					if (itemID_2 == 1) { //��

						if (itemMove2_M == true || use_rock_pos2.y >= -100.0f) {
							itemMove2_M = true;
							use_rock_pos2.y -= 3.00f;
							use_rock_pos2.x -= 3.00f;
						}
						else if (itemMove2_M == false) {
							use_rock_pos2.y += 3.00f;
							use_rock_pos2.x -= 3.00f;
						}
						if (use_rock_pos2.y <= -190.0f && itemMove2_M == true) {
							itemID_2 = 0;
							itemMove2_M = false;
							itemMove2 = false;
						}
					}
					else if (itemID_2 == 2) {
						if (use_snowball_pos2.x <= leftScreen) {
							itemID_2 = 0;
							itemMove2 = false;
						}
						else if (use_snowball_pos2.x >= leftScreen) {
							use_snowball_pos2.x -= 20.00f;
						}
					}
				}


			}

			// �������̓����@���̇B
			if (itemMove3 == true) {

				if (direction == 0) { // �E����

					if (itemID_3 == 1) { // ��

						if (itemMove3_M == true || use_rock_pos3.y >= -100.0f) {
							itemMove3_M = true;
							use_rock_pos3.y -= 3.00f;
							use_rock_pos3.x += 3.00f;
						}
						else if (itemMove3_M == false) {
							use_rock_pos3.y += 3.00f;
							use_rock_pos3.x += 3.00f;
						}
						if (use_rock_pos3.y <= -190.0f && itemMove3_M == true) {
							itemID_3 = 0;
							itemMove3_M = false;
							itemMove3 = false;
							changeItem = false;
						}
					}
					else if (itemID_3 == 2) {
						if (use_snowball_pos3.x >= rightScreen) {
							itemID_3 = 0;
							itemMove3 = false;
							changeItem = false;
						}
						else if (use_snowball_pos3.x <= rightScreen) {
							use_snowball_pos3.x += 30.00f;
						}
					}
				}
				else if (direction == 1) { // ������

					if (itemID_3 == 1) { // ��

						if (itemMove3_M == true || use_rock_pos3.y >= -100.0f) {
							itemMove3_M = true;
							use_rock_pos3.y -= 3.00f;
							use_rock_pos3.x -= 3.00f;
						}
						else if (itemMove3_M == false) {
							use_rock_pos3.y += 3.00f;
							use_rock_pos3.x -= 3.00f;
						}
						if (use_rock_pos3.y <= -190.0f && itemMove3_M == true) {
							itemID_3 = 0;
							itemMove3_M = false;
							itemMove3 = false;
							changeItem = false;
						}
					}
					else if (itemID_3 == 2) {
						if (use_snowball_pos3.x <= leftScreen) {
							itemID_3 = 0;
							itemMove3 = false;
							changeItem = false;
						}
						else if (use_snowball_pos3.x >= leftScreen) {
							use_snowball_pos3.x -= 30.00f;
						}
					}
				}


			}

			// �ŗL�\�͔����I�I�I�I�I�I�I
			if (sp_ani == false && input.GetKeyPress(VK_Q)
				|| input.GetButtonTrigger(XINPUT_X) && sp_ani == false) {

				if (bugPower > 0) { //  �܂ɒ��g������ꍇ

					if (direction == 0) { // �E����
						kintyaku_pos1.x = santa_kin_pos.x;
						kintyaku_pos1.y = santa_kin_pos.y - 25.0f;
						himo_pos.x = santa_kin_pos.x + 40;
						himo_pos.y = santa_kin_pos.y;
					}
					else if (direction == 1) { // ������
						kintyaku_pos1.x = santa_kin_pos.x;
						kintyaku_pos1.y = santa_kin_pos.y - 25.0f;
						himo_pos.x = santa_kin_pos.x - 40;
						himo_pos.y = santa_kin_pos.y;
					}

					sp_ani = true;
					kintyaku_go1 = true;

				}
				else if (bugPower == 0) { // �܂�����ۂ̎�

					if (direction == 0) { // �E����
						kintyaku_pos.x = santa_kin_pos.x;
						kintyaku_pos.y = santa_kin_pos.y - 25.0f;
						himo_pos.x = santa_kin_pos.x + 40;
						himo_pos.y = santa_kin_pos.y;
					}
					else if (direction == 1) { // ������
						kintyaku_pos.x = santa_kin_pos.x;
						kintyaku_pos.y = santa_kin_pos.y - 25.0f;
						himo_pos.x = santa_kin_pos.x - 40;
						himo_pos.y = santa_kin_pos.y;
					}

					sp_ani = true;
					kintyaku_go = true;



				}


			}

			//	�В��̃A�j���[�V�����֌W
			if (sp_ani == true) {


				if (direction == 0) // �����E�����Ȃ�
				{
					if (bugPower == 0) {
						kintyaku[0].numU = 0;
						kintyaku[0].numV = 0;
					}
					else if (bugPower > 0) {
						kintyaku[1].numU = 0;
						kintyaku[1].numV = 0;
					}

					if (changeRight_SP == true)
					{
						if (ani_stop == true) { // �����ŃA�j���[�V�������Œ肷��
							santa_Kin[6].numU = 2;
							santa_Kin[6].numV = 0;

						}
						else if (ani_stop == false) { // false�̏ꍇ�́A����������i�ŏ��͂����ɂ���j

							//������
							santaImage = 23;
							santa_Kin[6].numU = 0;
							santa_Kin[6].numV = 0;

						}

						changeRight_SP = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���
					}
					if (ani_stop == true) {

					}
					else if (ani_stop == false) {

						framcount7++; //�t���[���J�E���g
						if (framcount7 % 4 == 0) //�P�O�t���[���Ɉ��s����
						{
							santa_Kin[6].numU++;
							if (santa_Kin[6].numU >= 3)
							{
								changeRight_SP = true;
								ani_stop = true;

							}
						}
					}

				}
				else if (direction == 1) // ������
				{
					if (bugPower <= 0) {
						kintyaku[0].numU = 0;
						kintyaku[0].numV = 1;
					}
					else if (bugPower >= 0) {
						kintyaku[1].numU = 0;
						kintyaku[1].numV = 1;
					}

					if (changeLeft_SP == true)

						if (ani_stop == true) { // �����ŃA�j���[�V�������Œ肷��
							santa_Kin[6].numU = 2;
							santa_Kin[6].numV = 1;

						}
						else if (ani_stop == false) {
							//������
							santaImage = 23;
							santa_Kin[6].numU = 0;
							santa_Kin[6].numV = 1;
						}
					changeLeft_SP = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���

					if (ani_stop == true) {

					}
					else if (ani_stop == false) {
						framcount7++; //�t���[���J�E���g
						if (framcount7 % 4 == 0) //�P�O�t���[���Ɉ��s����
						{
							santa_Kin[6].numU++;
							if (santa_Kin[6].numU >= 3)
							{

								changeLeft_SP = true;
								ani_stop = true;

							}
						}
					}
				}

			}

			// �В��܂̈ړ� (���g�Ȃ�)
			if (kintyaku_go == true) {

				if (direction == 0) { // �E����

					if (kintyaku_Fg == true) { // �܂������̂Ƃ��ɖ߂鏈��

						get_Kintyaku -= 15.0f;
						kintyaku_pos.x -= 15.0f;

						himo_pos.x -= 6.5f;
						himo_size.x -= 13.0f;
					}
					else {                     // �܂��΂�����
						get_Kintyaku += 15.0f;
						kintyaku_pos.x += 15.0f;

						himo_pos.x += 6.5f;
						himo_size.x += 13.0f;
					}

					if (collision.square_square(kintyaku[0], tree) == true && tree_Ground == 1) {
						tree_Ground = 2;
					}

					if (get_Kintyaku >= 300.0f && kintyaku_Fg == false) { // �܂��ő勗���܂ňړ������ꍇ
						kintyaku_Fg = true;
					}
					else if (get_Kintyaku <= 0.0f && kintyaku_Fg == true) { // �܂������̌��ɖ߂������̏���
						changeRight_SP = true;
						santaImage = 17;
						santa_Kin[6].numU = 0;
						sp_ani = false;
						kintyaku_go = false;
						ani_stop = false;
						himo_size.x = 10.0f;

						get_Kintyaku = 0.0f;
						kintyaku_Fg = false;
					}
				}
				else if (direction == 1) { // �E����

					if (kintyaku_Fg == true) { // �܂������̂Ƃ��ɖ߂鏈��

						get_Kintyaku += 15.0f;
						kintyaku_pos.x += 15.0f;

						himo_pos.x += 6.5f;
						himo_size.x += -13.0f;
					}
					else {                     // �܂��΂�����
						get_Kintyaku -= 15.0f;
						kintyaku_pos.x += -15.0f;

						himo_pos.x -= 6.5f;
						himo_size.x += 13.0f;
					}

					if (get_Kintyaku <= -300.0f && kintyaku_Fg == false) { // �܂��ő勗���܂ňړ������ꍇ
						kintyaku_Fg = true;
					}
					else if (get_Kintyaku >= 0.0f && kintyaku_Fg == true) { // �܂������̌��ɖ߂������̏���
						changeLeft_SP = true;
						santaImage = 17;
						santa_Kin[6].numU = 0;
						sp_ani = false;
						kintyaku_go = false;
						ani_stop = false;
						himo_size.x = 10.0f;

						get_Kintyaku = 0.0f;
						kintyaku_Fg = false;
					}
				}

			}

			// �В��܂̈ړ� (���g����j
			if (kintyaku_go1 == true) {

				if (direction == 0) { // �E����

					if (kintyaku_Fg == true) { // �܂������̂Ƃ��ɖ߂鏈��

						get_Kintyaku -= 15.0f;
						kintyaku_pos1.x -= 15.0f;

						himo_pos.x -= 6.5f;
						himo_size.x -= 13.0f;
					}
					else {                     // �܂��΂�����
						get_Kintyaku += 15.0f;
						kintyaku_pos1.x += 15.0f;

						himo_pos.x += 6.5f;
						himo_size.x += 13.0f;
					}

					if (get_Kintyaku >= 300.0f && kintyaku_Fg == false) { // �܂��ő勗���܂ňړ������ꍇ
						kintyaku_Fg = true;
					}
					else if (get_Kintyaku <= 0.0f && kintyaku_Fg == true) { // �܂������̌��ɖ߂������̏���
						changeRight_SP = true;
						santaImage = 17;
						santa_Kin[6].numU = 0;
						sp_ani = false;
						kintyaku_go1 = false;
						ani_stop = false;
						himo_size.x = 10.0f;

						get_Kintyaku = 0.0f;
						kintyaku_Fg = false;
					}
				}
				else if (direction == 1) { // �E����

					if (kintyaku_Fg == true) { // �܂������̂Ƃ��ɖ߂鏈��

						get_Kintyaku += 15.0f;
						kintyaku_pos1.x += 15.0f;

						himo_pos.x += 6.5f;
						himo_size.x += -13.0f;
					}
					else {                     // �܂��΂�����
						get_Kintyaku -= 15.0f;
						kintyaku_pos1.x += -15.0f;

						himo_pos.x -= 6.5f;
						himo_size.x += 13.0f;
					}

					if (get_Kintyaku <= -300.0f && kintyaku_Fg == false) { // �܂��ő勗���܂ňړ������ꍇ
						kintyaku_Fg = true;
					}
					else if (get_Kintyaku >= 0.0f && kintyaku_Fg == true) { // �܂������̌��ɖ߂������̏���
						changeLeft_SP = true;
						santaImage = 17;
						santa_Kin[6].numU = 0;
						sp_ani = false;
						kintyaku_go1 = false;
						ani_stop = false;
						himo_size.x = 10.0f;

						get_Kintyaku = 0.0f;
						kintyaku_Fg = false;
					}
				}

			}

			// �В��܂ƓG�̓����蔻��
			if (kintyaku_go1 == true && kintyaku_Fg == false) {
				if (collision.square_square(Snowman_Stage2[1], kintyaku[1]) == true) {
					sound.Play(SOUND_LABEL_SE004);
					snowman_hp1 -= santa_atk;

					particleFg = true;
					particlepos.x = snowman_pos1.x;
					particlepos.y = snowman_pos1.y;

					if (snowman_hp1 < 0)
					{
						enemylive1 = false;
						snowman_hp1 = 20;
						snowman_pos1.x = 400000000;
					}
				}

				if (collision.square_square(Snowman_Stage2[2], kintyaku[1]) == true) {
					snowman_hp2 -= santa_atk;
					sound.Play(SOUND_LABEL_SE004);
					particleFg = true;
					particlepos.x = snowman_pos2.x;
					particlepos.y = snowman_pos2.y;
					if (snowman_hp2 < 0)
					{

						enemylive2 = false;
						snowman_hp2 = 20;
						snowman_pos2.x = 400000000;
					}
				}

				if (collision.square_square(Snowman_Stage2[3], kintyaku[1]) == true) {
					snowman_hp3 -= santa_atk;
					sound.Play(SOUND_LABEL_SE004);
					particleFg = true;
					particlepos.x = snowman_pos3.x;
					particlepos.y = snowman_pos3.y;
					if (snowman_hp3 < 0)
					{

						enemylive3 = false;
						snowman_hp3 = 20;
						snowman_pos3.x = 400000000;
					}
				}

				if (collision.square_square(Snowman_Stage2[4], kintyaku[1]) == true) {
					snowman_hp4 -= santa_atk;
					sound.Play(SOUND_LABEL_SE004);
					particleFg = true;
					particlepos.x = snowman_pos4.x;
					particlepos.y = snowman_pos4.y;
					if (snowman_hp4 < 0)
					{

						enemylive4 = false;
						snowman_hp4 = 20;
						snowman_pos4.x = 400000000;
					}
				}

				if (collision.square_square(Star_Stage2[1], kintyaku[1]) == true) {
					star_monster_hp1 -= santa_atk;
					sound.Play(SOUND_LABEL_SE004);
					particleFg = true;
					particlepos.x = star_pos1.x;
					particlepos.y = star_pos1.y;
					if (star_monster_hp1 < 0)
					{
						enemylive5 = false;
						star_monster_hp1 = 40;
						star_pos1.x = 400000000;
					}
				}

				if (collision.square_square(Star_Stage2[2], kintyaku[1]) == true) {
					star_monster_hp2 -= santa_atk;
					sound.Play(SOUND_LABEL_SE004);
					particleFg = true;
					particlepos.x = star_pos2.x;
					particlepos.y = star_pos2.y;
					if (star_monster_hp2 < 0)
					{
						enemylive6 = false;
						star_monster_hp2 = 40;
						star_pos2.x = 400000000;
					}
				}

				if (collision.square_square(Tonakai_Stage2[1], kintyaku[1]) == true) {
					tonakai_hp1 -= santa_atk;
					sound.Play(SOUND_LABEL_SE004);
					particleFg = true;
					particlepos.x = tonakai_pos1.x;
					particlepos.y = tonakai_pos1.y;
					if (tonakai_hp1 < 0)
					{
						enemylive7 = false;
						tonakai_hp1 = 60;
						tonakai_pos1.x = 400000000;
					}
				}

				if (collision.square_square(Tonakai_Stage2[2], kintyaku[1]) == true) {
					tonakai_hp2 -= santa_atk;
					sound.Play(SOUND_LABEL_SE004);
					particleFg = true;
					particlepos.x = tonakai_pos2.x;
					particlepos.y = tonakai_pos2.y;
					if (tonakai_hp2 < 0)
					{
						enemylive8 = false;
						tonakai_hp2 = 60;
						tonakai_pos2.x = 400000000;
					}
				}

			}

			//�p�[�e�B�N���A�j���[�V����
			if (particleFg)
			{
				particlecount++;
				if (particlecount % 5 == 0)
				{
					//particleFg = false;
					particle.numU++;
					if (particle.numU > 7)
					{
						particle.numU = 0;
						particleFg = false;
					}
				}

			}


			//�E�ړ�
			if (sp_ani == false && gameoverFg == false && collision.canMoveRight && input.GetKeyPress(VK_D) && pauseFg == false
				|| gameoverFg == false && collision.canMoveRight && input.GetLeftAnalogStick().x >= 0.1 && pauseFg == false)
			{
				direction = 0; // ����
				santa_kin_pos.x += 5;//�E�ړ�
				/*santa_kin_pos.x += 5;
				santa_pos.x += 5;*/


				if (bugPower == 0) {
					santaImage = 17;
					if (changeRight_SP_1 == true)
					{
						//������
						santa_Kin[0].numU = 0;
						santa_Kin[0].numV = 0;
						changeRight_SP_1 = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���
					}
					framcount6++; //�t���[���J�E���g
					if (framcount6 % 10 == 0) //�P�O�t���[���Ɉ��s����
					{
						santa_Kin[0].numU++;
						if (santa_Kin[0].numU >= 4)
						{
							santa_Kin[0].numU = 0;
							santa_Kin[0].numV++;
							if (santa_Kin[0].numV >= 2)
							{
								santa_Kin[0].numV = 0;
							}
						}
					}

				}
				else if (bugPower > 0) {
					santaImage = 18;
					if (changeRight == true)
					{
						//������
						santa_Kin[1].numU = 0;
						santa_Kin[1].numV = 0;
						changeRight = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���
					}
					framcount++; //�t���[���J�E���g
					if (framcount % 10 == 0) //�P�O�t���[���Ɉ��s����
					{
						santa_Kin[1].numU++;
						if (santa_Kin[1].numU >= 4)
						{
							santa_Kin[1].numU = 0;
							santa_Kin[1].numV++;
							if (santa_Kin[1].numV >= 2)
							{
								santa_Kin[1].numV = 0;
							}
						}
					}

				}

				if (santa_kin_pos.x >= 0) //�v���C���[����ʐ^�񒆂ɍs�����Ƃ�
				{
					santa_kin_pos.x -= 5;

					//�w�i�Ȃǂ����ɓ������ăv���C���[���E�ɓ����Ă�悤�Ɍ�����
					//�R
					mounten_pos1.x -= speed - 4.5;
					mounten_pos2.x -= speed - 4.5;
					mounten_pos3.x -= speed - 4.5;
					mounten_pos4.x -= speed - 4.5;
					//�n��
					ground_pos1.x -= speed;
					ground_pos2.x -= speed;
					ground_pos3.x -= speed;
					ground_pos4.x -= speed;
					ground_pos5.x -= speed;
					ground_pos6.x -= speed;
					ground_pos7.x -= speed;
					//��
					tree_pos1.x -= speed;
					tree_pos2.x -= speed;
					//����
					block_pos1.x -= speed;
					//���
					icicle_pos1.x -= speed;
					icicle_pos2.x -= speed;
					icicle_pos3.x -= speed;
					//�K�i
					stairs_pos1.x -= speed;
					stairs_pos2.x -= speed;
					stairs_pos3.x -= speed;
					stairs_pos4.x -= speed;
					stairs_pos5.x -= speed;

					//�v���[���g
					present_pos1.x -= speed;
					present_pos2.x -= speed;
					present_pos3.x -= speed;

					bigpresent_pos1.x -= speed;
					//�󂹂��
					breakrock_pos1.x -= speed;
					moji_pos.x -= speed;
					//�����
					rock_pos1.x -= speed;
					rock_pos2.x -= speed;
					rock_pos3.x -= speed;
					rock_pos4.x -= speed;
					rock_pos5.x -= speed;
					rock_pos6.x -= speed;

					//������
					snowball_pos1.x -= speed;
					snowball_pos2.x -= speed;
					snowball_pos3.x -= speed;

					//�G
					snowman_pos1.x -= speed;
					snowman_pos2.x -= speed;
					snowman_pos3.x -= speed;
					snowman_pos4.x -= speed;

					star_pos1.x -= speed;
					star_pos2.x -= speed;

					tonakai_pos1.x -= speed;
					tonakai_pos2.x -= speed;

					wall_pos1.x -= speed;
					wall_pos2.x -= speed;

					goal_pos.x -= speed;

				}
			}
			else
			{
				//�L�[�𗣂���true�ɖ߂�
				if (sp_ani == false && changeRight_SP_1 == false) {

					santa_Kin[0].numU = 0;
					santa_Kin[0].numV = 0;
					santa_Kin[1].numU = 0;
					santa_Kin[1].numV = 0;
					if (bugPower > 0) {
						santaImage = 18;
					}
					else if (bugPower == 0) {
						santaImage = 17;
					}

				}

				changeRight = true;
				changeRight_SP_1 = true;
			}
			//���ړ�
			if (sp_ani == false && gameoverFg == false && collision.canMoveLeft && input.GetKeyPress(VK_A) && pauseFg == false
				|| gameoverFg == false && collision.canMoveLeft && input.GetLeftAnalogStick().x <= -0.1 && pauseFg == false)
			{

				direction = 1; // ����
				santa_kin_pos.x -= 5;//���ړ�
				//santa_huro_pos.x -= 5;//���ړ�
				//santa_pos.x -= 5;//���ړ�


				if (bugPower == 0) {

					santaImage = 17;
					if (changeLeft_SP_1 == true)
					{
						//������
						santa_Kin[0].numU = 0;
						santa_Kin[0].numV = 2;
						changeLeft_SP_1 = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���
					}
					framcount6++; //�t���[���J�E���g
					if (framcount6 % 10 == 0) //�P�O�t���[���Ɉ��s����
					{
						santa_Kin[0].numU++;
						if (santa_Kin[0].numU >= 4)
						{

							santa_Kin[0].numU = 0;

						}
					}
				}
				else if (bugPower > 0) {

					if (changeLeft == true)
					{
						//������
						santa_Kin[1].numU = 0;
						santa_Kin[1].numV = 2;
						changeLeft = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���
					}
					framcount++; //�t���[���J�E���g
					if (framcount % 10 == 0) //�P�O�t���[���Ɉ��s����
					{
						santa_Kin[1].numU++;
						if (santa_Kin[1].numU >= 4)
						{
							santa_Kin[1].numU = 0;
							santa_Kin[1].numV++;
							if (santa_Kin[1].numV >= 4)
							{
								santa_Kin[1].numV = 2;
							}
						}
					}
				}

				if (santa_kin_pos.x <= 0) //�v���C���[����ʐ^�񒆂ɍs�����Ƃ�
				{
					santa_kin_pos.x += 5;

					//�w�i�Ȃǂ����ɓ������ăv���C���[���E�ɓ����Ă�悤�Ɍ�����
					//�R
					mounten_pos1.x += speed - 4.5;
					mounten_pos2.x += speed - 4.5;
					mounten_pos3.x += speed - 4.5;
					mounten_pos4.x += speed - 4.5;
					//�n��
					ground_pos1.x += speed;
					ground_pos2.x += speed;
					ground_pos3.x += speed;
					ground_pos4.x += speed;
					ground_pos5.x += speed;
					ground_pos6.x += speed;
					ground_pos7.x += speed;
					//��
					tree_pos1.x += speed;
					tree_pos2.x += speed;
					//����
					block_pos1.x += speed;
					//���
					icicle_pos1.x += speed;
					icicle_pos2.x += speed;
					icicle_pos3.x += speed;
					//�K�i
					stairs_pos1.x += speed;
					stairs_pos2.x += speed;
					stairs_pos3.x += speed;
					stairs_pos4.x += speed;
					stairs_pos5.x += speed;

					//�v���[���g
					present_pos1.x += speed;
					present_pos2.x += speed;
					present_pos3.x += speed;

					bigpresent_pos1.x += speed;
					//�󂹂��
					breakrock_pos1.x += speed;
					moji_pos.x += speed;
					//�����
					rock_pos1.x += speed;
					rock_pos2.x += speed;
					rock_pos3.x += speed;
					rock_pos4.x += speed;
					rock_pos5.x += speed;
					rock_pos6.x += speed;

					//������
					snowball_pos1.x += speed;
					snowball_pos2.x += speed;
					snowball_pos3.x += speed;

					//�G
					snowman_pos1.x += speed;
					snowman_pos2.x += speed;
					snowman_pos3.x += speed;
					snowman_pos4.x += speed;

					star_pos1.x += speed;
					star_pos2.x += speed;

					tonakai_pos1.x += speed;
					tonakai_pos2.x += speed;

					wall_pos1.x += speed;
					wall_pos2.x += speed;



					goal_pos.x += speed;

				}
			}
			else
			{
				//�L�[�𗣂���true�ɖ߂�
				if (sp_ani == false && changeLeft_SP_1 == false) {
					santa_Kin[0].numU = 0;
					santa_Kin[0].numV = 2;
					santa_Kin[1].numU = 0;
					santa_Kin[1].numV = 2;
					if (bugPower > 0) {
						santaImage = 18;
					}
					else if (bugPower == 0) {
						santaImage = 17;
					}
				}
				changeLeft = true;
				changeLeft_SP_1 = true;
			}
		}
		//�摜����ʊO�ɍs�����Ƃ��ɂ��̉摜����Ԍ��ɒu��
			//��@�摜�P����ʊO���摜�R�̌��� 
			//�R�̃X�N���[���@1280=��ʃT�C�Y
		if (mounten_pos1.x <= -1280 * 2)
		{
			mounten_pos1.x = mounten_pos3.x + SCREEN_WIDTH;

		}

		if (mounten_pos2.x <= -1280 * 2)
		{
			mounten_pos2.x = mounten_pos1.x + SCREEN_WIDTH;

		}

		if (mounten_pos3.x <= -1280 * 2)
		{
			mounten_pos3.x = mounten_pos2.x + SCREEN_WIDTH;

		}


		santa_Nor[0].SetPos(santa_pos.x, santa_pos.y, santa_pos.z);
		santa_Nor[1].SetPos(santa_pos1.x, santa_pos1.y, santa_pos1.z);
		santa_Nor[2].SetPos(santa_pos2.x, santa_pos2.y, santa_pos2.z);
		santa_Nor[3].SetPos(santa_pos3.x, santa_pos3.y, santa_pos3.z);
		santa_Nor[4].SetPos(santa_pos4.x, santa_pos4.y, santa_pos4.z);
		santa_Nor[5].SetPos(santa_pos5.x, santa_pos5.y, santa_pos5.z);
		santa_Nor[6].SetPos(santa_pos6.x, santa_pos6.y, santa_pos6.z);
		santa_Nor[7].SetPos(santa_pos7.x, santa_pos7.y, santa_pos7.z);
		santa_Huro[0].SetPos(santa_huro_pos.x, santa_huro_pos.y, santa_huro_pos.z);
		santa_Huro[1].SetPos(santa_huro_pos1.x, santa_huro_pos1.y, santa_huro_pos1.z);
		santa_Huro[2].SetPos(santa_huro_pos2.x, santa_huro_pos2.y, santa_huro_pos2.z);
		santa_Huro[3].SetPos(santa_huro_pos3.x, santa_huro_pos3.y, santa_huro_pos3.z);
		santa_Huro[4].SetPos(santa_huro_pos4.x, santa_huro_pos4.y, santa_huro_pos4.z);
		santa_Huro[5].SetPos(santa_huro_pos5.x, santa_huro_pos5.y, santa_huro_pos5.z);
		santa_Huro[6].SetPos(santa_huro_pos6.x, santa_huro_pos6.y, santa_huro_pos6.z);
		santa_Huro[7].SetPos(santa_huro_pos7.x, santa_huro_pos7.y, santa_huro_pos7.z);
		santa_Kin[0].SetPos(santa_kin_pos.x, santa_kin_pos.y, santa_kin_pos.z);
		santa_Kin[1].SetPos(santa_kin_pos1.x, santa_kin_pos1.y, santa_kin_pos1.z);
		santa_Kin[2].SetPos(santa_kin_pos2.x, santa_kin_pos2.y, santa_kin_pos2.z);
		santa_Kin[3].SetPos(santa_kin_pos3.x, santa_kin_pos3.y, santa_kin_pos3.z);
		santa_Kin[4].SetPos(santa_kin_pos4.x, santa_kin_pos4.y, santa_kin_pos4.z);
		santa_Kin[5].SetPos(santa_kin_pos5.x, santa_kin_pos5.y, santa_kin_pos5.z);
		santa_Kin[6].SetPos(santa_kin_pos6.x, santa_kin_pos6.y, santa_kin_pos6.z);

		kintyaku[0].SetPos(kintyaku_pos.x, kintyaku_pos.y, kintyaku_pos.z);
		kintyaku[1].SetPos(kintyaku_pos1.x, kintyaku_pos1.y, kintyaku_pos1.z);

		himo.SetPos(himo_pos.x, himo_pos.y, himo_pos.z);
		himo.SetSize(himo_size.x, himo_size.y, himo_size.z);

		//�w�i�@�R
		mounten[1].SetPos(mounten_pos1.x, mounten_pos1.y, mounten_pos1.z);
		mounten[2].SetPos(mounten_pos2.x, mounten_pos2.y, mounten_pos2.z);
		mounten[3].SetPos(mounten_pos3.x, mounten_pos3.y, mounten_pos3.z);
		mounten[4].SetPos(mounten_pos4.x, mounten_pos4.y, mounten_pos4.z);
		//�X�e�[�W�n��
		Ground_Stge2[1].SetPos(ground_pos1.x, ground_pos1.y, ground_pos1.z);
		Ground_Stge2[2].SetPos(ground_pos2.x, ground_pos2.y, ground_pos2.z);
		Ground_Stge2[3].SetPos(ground_pos3.x, ground_pos3.y, ground_pos3.z);
		Ground_Stge2[4].SetPos(ground_pos4.x, ground_pos4.y, ground_pos4.z);
		Ground_Stge2[5].SetPos(ground_pos5.x, ground_pos5.y, ground_pos5.z);
		Ground_Stge2[6].SetPos(ground_pos6.x, ground_pos6.y, ground_pos6.z);
		Ground_Stge2[7].SetPos(ground_pos7.x, ground_pos7.y, ground_pos7.z);
		//���
		Icicles_Stge2[1].SetPos(icicle_pos1.x, icicle_pos1.y, icicle_pos1.z);
		Icicles_Stge2[2].SetPos(icicle_pos2.x, icicle_pos2.y, icicle_pos2.z);
		Icicles_Stge2[3].SetPos(icicle_pos3.x, icicle_pos3.y, icicle_pos3.z);
		//�K�i
		Stairs_Stge2[1].SetPos(stairs_pos1.x, stairs_pos1.y, stairs_pos1.z);
		Stairs_Stge2[2].SetPos(stairs_pos2.x, stairs_pos2.y, stairs_pos2.z);
		Stairs_Stge2[3].SetPos(stairs_pos3.x, stairs_pos3.y, stairs_pos3.z);
		Stairs_Stge2[4].SetPos(stairs_pos4.x, stairs_pos4.y, stairs_pos4.z);
		Stairs_Stge2[5].SetPos(stairs_pos5.x, stairs_pos5.y, stairs_pos5.z);
		//��
		//Tree_Stge2[1].SetPos(tree_pos1.x, tree_pos1.y, tree_pos1.z);
		//Tree_Stge2[2].SetPos(tree_pos2.x, tree_pos2.y, tree_pos2.z);
		//����
		Block_Stge2[1].SetPos(block_pos1.x, block_pos1.y, block_pos1.z);
		//�v���[���g
		Present_Stage2[1].SetPos(present_pos1.x, present_pos1.y, present_pos1.z);
		Present_Stage2[2].SetPos(present_pos2.x, present_pos2.y, present_pos2.z);
		Present_Stage2[3].SetPos(present_pos3.x, present_pos3.y, present_pos3.z);
		BigPresent_Stage2[1].SetPos(bigpresent_pos1.x, bigpresent_pos1.y, bigpresent_pos1.z);
		//�󂹂��
		Breakrock_Stge2[1].SetPos(breakrock_pos1.x, breakrock_pos1.y, breakrock_pos1.z);
		//�X�e�[�W�n��
		Collectrock_Stage2[1].SetPos(rock_pos1.x, rock_pos1.y, rock_pos1.z);
		Collectrock_Stage2[2].SetPos(rock_pos2.x, rock_pos2.y, rock_pos2.z);
		Collectrock_Stage2[3].SetPos(rock_pos3.x, rock_pos3.y, rock_pos3.z);
		Collectrock_Stage2[4].SetPos(rock_pos4.x, rock_pos4.y, rock_pos4.z);
		Collectrock_Stage2[5].SetPos(rock_pos5.x, rock_pos5.y, rock_pos5.z);
		Collectrock_Stage2[6].SetPos(rock_pos6.x, rock_pos6.y, rock_pos6.z);
		//���
		Snowball_Stage2[1].SetPos(snowball_pos1.x, snowball_pos1.y, snowball_pos1.z);
		Snowball_Stage2[2].SetPos(snowball_pos2.x, snowball_pos2.y, snowball_pos2.z);
		Snowball_Stage2[3].SetPos(snowball_pos3.x, snowball_pos3.y, snowball_pos3.z);
		//�G
		Snowman_Stage2[1].SetPos(snowman_pos1.x, snowman_pos1.y, snowman_pos1.z);
		Snowman_Stage2[2].SetPos(snowman_pos2.x, snowman_pos2.y, snowman_pos2.z);
		Snowman_Stage2[3].SetPos(snowman_pos3.x, snowman_pos3.y, snowman_pos3.z);
		Snowman_Stage2[4].SetPos(snowman_pos4.x, snowman_pos4.y, snowman_pos4.z);

		Star_Stage2[1].SetPos(star_pos1.x, star_pos1.y, star_pos1.z);
		Star_Stage2[2].SetPos(star_pos2.x, star_pos2.y, star_pos2.z);

		Tonakai_Stage2[1].SetPos(tonakai_pos1.x, tonakai_pos1.y, tonakai_pos1.z);
		Tonakai_Stage2[2].SetPos(tonakai_pos2.x, tonakai_pos2.y, tonakai_pos2.z);

		Cursor.SetPos(cursor_pos.x, cursor_pos.y, cursor_pos.z);
		PauseCursor.SetPos(cursor1_pos.x, cursor1_pos.y, cursor1_pos.z);
		Goal_Stage2.SetPos(goal_pos.x, goal_pos.y, goal_pos.z);
		Breakmoji.SetPos(moji_pos.x, moji_pos.y, moji_pos.z);

		invisiblewall[3].SetPos(wall_pos1.x, wall_pos1.y, wall_pos1.z);
		invisiblewall[4].SetPos(wall_pos2.x, wall_pos2.y, wall_pos2.z);

		use_rock[0].SetPos(use_rock_pos1.x, use_rock_pos1.y, use_rock_pos1.z);
		use_rock[1].SetPos(use_rock_pos2.x, use_rock_pos2.y, use_rock_pos2.z);
		use_rock[2].SetPos(use_rock_pos3.x, use_rock_pos3.y, use_rock_pos3.z);

		use_snowball[0].SetPos(use_snowball_pos1.x, use_snowball_pos1.y, use_snowball_pos1.z);
		use_snowball[1].SetPos(use_snowball_pos2.x, use_snowball_pos2.y, use_snowball_pos2.z);
		use_snowball[2].SetPos(use_snowball_pos3.x, use_snowball_pos3.y, use_snowball_pos3.z);

		hitbox2.SetPos(hitboxpos.x, hitboxpos.y, hitboxpos.z);
		particle.SetPos(particlepos.x, particlepos.y, particlepos.z);

		Snowman_Stage2[1].SetHP(snowman_hp1);
		Snowman_Stage2[2].SetHP(snowman_hp2);
		Snowman_Stage2[3].SetHP(snowman_hp3);
		Snowman_Stage2[4].SetHP(snowman_hp4);
		Star_Stage2[1].SetHP(star_monster_hp1);
		Star_Stage2[2].SetHP(star_monster_hp2);
		Tonakai_Stage2[1].SetHP(tonakai_hp1);
		Tonakai_Stage2[2].SetHP(tonakai_hp2);


		santa_Nor[7].SetATK(santa_atk);

	}
	break;

	case BOSS:
		DirectX::XMFLOAT3 boss_monster_pos = boss_monster.GetPos();    //�{�X
		DirectX::XMFLOAT3 boss_toujou_pos = boss_toujou.GetPos();    //�{�X
		DirectX::XMFLOAT3 boss_punch_pos = boss_punch.GetPos();    //�{�X


		
		switch (bossImage)
		{
		case 0://�o��
			framcount8++;
			if (framcount8 % 5 == 0) //�P�O�t���[���Ɉ��s����
			{
				boss_toujou.numU++;
				if (boss_toujou.numU >= 6)
				{
					boss_toujou.numU = 0;
					framcount8 = 0;
					bossImage = 1;
				}
			}
			break;
		case 1://�ҋ@
			framcount8++;
			if (framcount8 % 10 == 0) //�P�O�t���[���Ɉ��s����
			{
				boss_monster.numU++;
				if (boss_monster.numU >= 6)
				{
					boss_monster.numU = 0;
					framcount8 = 0;
					bosschange = true;
				}
			}
			break;
		case 2://��炨�Ƃ���A�܂��͍U���H
			framcount8++;
			if (framcount8 % 10 == 0) //�P�O�t���[���Ɉ��s����
			{
				boss_punch.numU++;
				if (boss_punch.numU >= 6)
				{
					boss_punch.numU = 0;
					boss_punch.numV++;
					if (boss_punch.numV >= 2)
					{
						
							boss_punch.numV = 0;
							framcount8 = 0;
							bossImage = 1;

						
					}
					
				}
			}
			break;
		case 3://��т���or��炨�Ƃ����
			framcount8++;
			if (framcount8 % 10 == 0) //�P�O�t���[���Ɉ��s����
			{
				boss_yobidashi.numU++;
				if (boss_yobidashi.numU >= 5)
				{
					boss_yobidashi.numU = 0;
					boss_yobidashi.numV++;
					if (boss_yobidashi.numV >= 2)
					{
						boss_yobidashi.numV = 0;
						framcount8 = 0;
						bossImage = 1;
					}
				}
			}
			break;

		}
		
		//�����_��
		if (bosschange)
		{
			cooltime++;
			if(cooltime%600==0)//�\�b
			{
				std::random_device rd;
				std::mt19937 gen(rd());

				//�����������͈̔͂�ς�����������()�̂Ȃ���������i��Q����T�Ȃ�i2,5�j�j//�l��
				std::uniform_int_distribution<int>dist(2, 3);//�Q����R

				bossImage = dist(gen);//�Q����3�̂͂񂢂Ń����_���Ȑ��𐶐�

				bosschange = false;
			}
			
		}

		//�L�[���͂Ń^�C�g���ړ�
		if (input.GetKeyTrigger(VK_RETURN))
		{
			changescene = RESULT;//���U���g��
			sound.Stop(SOUND_LABEL_BGM003);
		}
		break;

	case RESULT:
		sound.Stop(SOUND_LABEL_BGM000);
		
		//�L�[���͂Ń^�C�g���ړ�
		if (input.GetKeyTrigger(VK_RETURN)||input.GetButtonPress(XINPUT_B))
		{
			//������
			time = 150;
			framcount = 0;
			framcount2 = 0;
			score = 0;
			presentcount = 0;
			bigpresentcount = 0;
			time = 150;
			cleartime = 0;
			sound.Stop(SOUND_LABEL_BGM001);
			sound.Play(SOUND_LABEL_BGM002);
			enemylive1 = true;
			enemylive2 = true;
			enemylive3 = true;
			
			changescene = TITLE;//�^�C�g����
		}
		break;


	default:
		break;
	}

}

void Game::Draw(void)
{

	D3D_StartRender();//�`��J�n

	int keta = 0;//�X�R�A
	int keta2 = 0;//��������
	int keta3 = 0;//�N���A����
	int keta4 = 0;//�����
	int keta5 = 0;//�傐��
	int keta6 = 0;//��������
	int keta7 = 0;//�N���A����
	int keta8 = 0;//��������
	int keta9 = 0;//�N���A����


	DirectX::XMFLOAT3 scorepos = Number_UI[1].GetPos();
	DirectX::XMFLOAT3 scoresize = Number_UI[1].GetSize();

	DirectX::XMFLOAT3 timepos = Number_UI[2].GetPos();
	DirectX::XMFLOAT3 timesize = Number_UI[2].GetSize();

	
	

	switch (changescene)
	{
	case TITLE://�^�C�g��
		background.Draw();//�v���C���[�`��
		titlesanta.Draw();
		title.Draw();
		PressBbotton.Draw();
		
		break;
	case STAGESELECT:
		StegeSelect.Draw();
		SantaCursor.Draw();
		break;
	case STAGE1_LOADING:
		Stage1_Loading.Draw();
		break;
	case STAGE2_LOADING:
		Stage2_Loading.Draw();
		break;
	case BOSS_LOADING:
		BOSS_Loading.Draw();
		break;


	case STAGE_1://�Q�[��



		sky.Draw();
		star.Draw();

		//���
		for (int i = 1; i < image; i++)
		{
			mounten[i].Draw();//�Q�[���w�i
		}
		//��
		for (int i = 1; i < image; i++)
		{
			wood[i].Draw();
		}
		//����
		if (rock_visible1 == 0) {
			rock[1].Draw();
		}
		if (rock_visible2 == 0) {
			rock[2].Draw();
		}
		if (rock_visible3 == 0) {
			rock[3].Draw();
		}
		if (rock_visible4 == 0) {
			rock[4].Draw();
		}
		if (rock_visible5 == 0) {
			rock[5].Draw();
		}
		if (rock_visible6 == 0) {
			rock[6].Draw();
		}

		//���
		if (snow_visible1 == 0)
		{
			snowball[1].Draw();
		}
		if (snow_visible2 == 0)
		{
			snowball[2].Draw();
		}
		if (snow_visible3 == 0)
		{
			snowball[3].Draw();
		}

		//�v���[���g
		for (int i = 1; i < image; i++)
		{
			present[i].Draw();
		}
		//���߂�
		for (int i = 1; i < image; i++)
		{
			ground[i].Draw();
		}
		//�K�i
		for (int i = 1; i < image; i++)
		{
			stairs[i].Draw();
		}
		//�K�i
		for (int i = 1; i < image; i++)
		{
			stairs[i].Draw();
		}
		//�Ⴞ���

		if (enemylive1 == true)
		{
			snowman[1].Draw();
		}
		if (enemylive2 == true)
		{
			snowman[2].Draw();
		}
		if (enemylive3 == true)
		{
			snowman[3].Draw();
		}
		//�ق�
		if (enemylive4)
		{
			star_monster.Draw();
		}
		//�Ƃ�
		if (enemylive5)
		{
			tonakai.Draw();
		}

		BigPresent[1].Draw();

		
		

		tree.Draw();

		//�T���^�̉摜�؂�ւ�
		switch (santaImage)
		{
			//�ʏ�
			case 0:
				santa_Nor[0].Draw();
				break;
			case 1:
				santa_Nor[1].Draw();
				break;
			case 2:
				santa_Nor[2].Draw();
				break;
			case 3:
				santa_Nor[3].Draw();
				break;
			case 4:
				santa_Nor[4].Draw();
				break;
			case 5:
				santa_Nor[5].Draw();
				break;
			case 6:
				santa_Nor[6].Draw();
				break;
			case 7:
				santa_Nor[7].Draw();
				break;
			//huro
			case 8:
				santa_Huro[0].Draw();//�v���C���[�`��
				break;
			case 9:
				santa_Huro[1].Draw();//�v���C���[�`��
				break;
			case 10:
				santa_Huro[2].Draw();//�v���C���[�`��
				break;
			case 12:
				santa_Huro[3].Draw();//�v���C���[�`��
				break;
			case 13:
				santa_Huro[4].Draw();//�v���C���[�`��
				break;
			case 14:
				santa_Huro[5].Draw();//�v���C���[�`��
				break;
			case 15:
				santa_Huro[6].Draw();//�v���C���[�`��
				break;
			case 16:
				santa_Huro[7].Draw();//�v���C���[�`��
				break;
			//kin
			case 17:
				santa_Kin[0].Draw();//�v���C���[�`��
				break;
			case 18:
				santa_Kin[1].Draw();//�v���C���[�`��
				break;
			case 19:
				santa_Kin[2].Draw();//�v���C���[�`��
				break;
			case 20:
				santa_Kin[3].Draw();//�v���C���[�`��
				break;
			case 21:
				santa_Kin[4].Draw();//�v���C���[�`��
				break;
			case 22:
				santa_Kin[5].Draw();//�v���C���[�`��
				break;
			case 23:
				santa_Kin[6].Draw();//�v���C���[�`��
				break;
		default:
			break;
		}
		if (particleFg)
		{
			particle.Draw();
		}
		
		


		// �В��܂̑܂ƕR
		if (sp_ani == true && kintyaku_go==true || sp_ani == true && kintyaku_go1 == true) {
			himo.Draw();
		}

		if (sp_ani == true && kintyaku_go == true || sp_ani == true && kintyaku_go1) {
			if (bugPower == 0) {
				kintyaku[0].Draw();
			}
			else if (bugPower > 0) {
				kintyaku[1].Draw();
			}
		}
		
		
		goal.Draw();

		ItemStock.Draw();

		if (damage5 == true)
		{
			damage.Draw();
			framcount++;
			if (framcount%60==0)
			{
				damage5 = false;
			}
		}
	
		///////// ������ ///////////////////

		if (itemID_1 == 1) {
			use_rock[0].Draw();
		}
		if (itemID_2 == 1) {
			use_rock[1].Draw();
		}
		if (itemID_3 == 1) {
			use_rock[2].Draw();
		}
			
		if (itemID_1 == 2) {
			use_snowball[0].Draw();
		}
		if (itemID_2 == 2) {
			use_snowball[1].Draw();
		}
		if (itemID_3 == 2) {
			use_snowball[2].Draw();
		}
		

		///////// UI  ///////////////////

		// bug1
		if (item->GetItem_1() == 1) // ��
		{
			itemUi[0].Draw();
		}
		if (item->GetItem_1() == 2) // ���
		{
			itemUi[3].Draw();
		}
		if (item->GetItem_1() == 3) // ���
		{
			itemUi[6].Draw();
		}

		// bug2
		if (item->GetItem_2() == 1) // ��
		{
			itemUi[1].Draw();
		}
		if (item->GetItem_2() == 2) // ���
		{
			itemUi[4].Draw();
		}
		if (item->GetItem_2() == 3) // ���
		{
			itemUi[7].Draw();
		}

		// bug3
		if (item->GetItem_3() == 1) // ��
		{
			itemUi[2].Draw();
		}
		if (item->GetItem_3() == 2) // ���
		{
			itemUi[5].Draw();
		}
		if (item->GetItem_3() == 3) // ���
		{
			itemUi[8].Draw();
		}

		/////////////////////////////////

		ScoreCounter.Draw();
		//�X�R�A
		do {
			Number_UI[1].numU = score % (int)pow(10, keta + 1) / (int)pow(10, keta);//�ꌅ��؂�o��
			Number_UI[1].SetPos(scorepos.x - scoresize.x * keta, scorepos.y, scoresize.z);//�ʒu��ݒ�

			Number_UI[1].Draw();//�X�R�A��`��
			keta++;
		} while (score >= (int)pow(10, keta));
		Number_UI[1].SetPos(scorepos.x, scorepos.y, scorepos.z);

		Time.Draw();
		
		//��������
		do {
			Number_UI[2].numU = time % (int)pow(10, keta2 + 1) / (int)pow(10, keta2);//�ꌅ��؂�o��
			Number_UI[2].SetPos(timepos.x - timesize.x * keta2, timepos.y, timesize.z);//�ʒu��ݒ�

			Number_UI[2].Draw();//�X�R�A��`��
			keta2++;
		} while (time >= (int)pow(10, keta2));
		Number_UI[2].SetPos(timepos.x, timepos.y, timepos.z);

		UseBag.Draw();
		if (santa_bug == 0)
		{
			normalUI.Draw();
			normalmoji.Draw();
		}

		if (santa_bug == 1)
		{
			hurosikilUI.Draw();
			hurosikimoji.Draw();
		}

		if (santa_bug == 2)
		{
			kintyakuUI.Draw();
			kintyakumoji.Draw();
		}
		if (gameoverFg == true)
		{
			pause.Draw();
			Gameover.Draw();
			GoodMorning.Draw();
			TitleBack.Draw();
			Retry.Draw();
			Cursor.Draw();
		}

		if (pauseFg == true)
		{
			pause.Draw();
			Gameover.Draw();
			rule.Draw();
			Pausemoji.Draw();
			PauseTitleBack.Draw();
			///PauseRetry.Draw();
			PauseCursor.Draw();
			PauseGameback.Draw();

		}

		//hitbox.Draw();
		
		break;
	case STAGE_2://�X�e�[�W�Q


		sky.Draw();
		star.Draw();

		//���
		for (int i = 1; i < image; i++)
		{
			mounten[i].Draw();//�Q�[���w�i
		}

		//���߂�
		for (int i = 1; i < image; i++)
		{
			Ground_Stge2[i].Draw();
		}

		//��
		for (int i = 1; i < image; i++)
		{
			Tree_Stge2[i].Draw();
		}

		//�u���b�N
		for (int i = 1; i < image; i++)
		{
			Block_Stge2[i].Draw();
		}
		//���
		for (int i = 1; i < image; i++)
		{
			Icicles_Stge2[i].Draw();
		}
		//�K�i
		for (int i = 1; i < image; i++)
		{
			Stairs_Stge2[i].Draw();
		}
		//�v���[���g
		for (int i = 1; i < image; i++)
		{
			Present_Stage2[i].Draw();
		}
		
		
		//����
		if (rock_visible1 == 0) {
			Collectrock_Stage2[1].Draw();
		}
		if (rock_visible2 == 0) {
			Collectrock_Stage2[2].Draw();
		}
		if (rock_visible3 == 0) {
			Collectrock_Stage2[3].Draw();
		}
		if (rock_visible4 == 0) {
			Collectrock_Stage2[4].Draw();
		}
		if (rock_visible5 == 0) {
			Collectrock_Stage2[5].Draw();
		}
		if (rock_visible6 == 0) {
			Collectrock_Stage2[6].Draw();
		}

		//���
		if (snow_visible1 == 0)
		{
			Snowball_Stage2[1].Draw();
		}
		if (snow_visible2 == 0)
		{
			Snowball_Stage2[2].Draw();
		}
		if (snow_visible3 == 0)
		{
			Snowball_Stage2[3].Draw();
		}



		
		if (rocklive)
		{
			Breakrock_Stge2[1].Draw();
			Breakmoji.Draw();
		}
		BigPresent_Stage2[1].Draw();
		//santa_Nor[0].Draw();//�v���C���[�`��
		ItemStock.Draw();
		Goal_Stage2.Draw();

		//�Ⴞ���

		if (enemylive1 == true)
		{
			Snowman_Stage2[1].Draw();
		}
		if (enemylive2 == true)
		{
			Snowman_Stage2[2].Draw();
		}
		if (enemylive3 == true)
		{
			Snowman_Stage2[3].Draw();
		}
		if (enemylive4 == true)
		{
			Snowman_Stage2[4].Draw();
		}
		//�ق�
		if (enemylive5)
		{
			Star_Stage2[1].Draw();
		}
		
		if (enemylive6)
		{
			Star_Stage2[2].Draw();
		}

		//tonakai
		if (enemylive7)
		{
			Tonakai_Stage2[1].Draw();
		}

		if (enemylive8)
		{
			Tonakai_Stage2[2].Draw();
		}

		///////// ������ ///////////////////

		if (itemID_1 == 1) {
			use_rock[0].Draw();
		}
		if (itemID_2 == 1) {
			use_rock[1].Draw();
		}
		if (itemID_3 == 1) {
			use_rock[2].Draw();
		}

		if (itemID_1 == 2) {
			use_snowball[0].Draw();
		}
		if (itemID_2 == 2) {
			use_snowball[1].Draw();
		}
		if (itemID_3 == 2) {
			use_snowball[2].Draw();
		}

	

		///////// UI  ///////////////////

		// bug1
		if (item->GetItem_1() == 1) // ��
		{
			itemUi[0].Draw();
		}
		if (item->GetItem_1() == 2) // ���
		{
			itemUi[3].Draw();
		}
		if (item->GetItem_1() == 3) // ���
		{
			itemUi[6].Draw();
		}

		// bug2
		if (item->GetItem_2() == 1) // ��
		{
			itemUi[1].Draw();
		}
		if (item->GetItem_2() == 2) // ���
		{
			itemUi[4].Draw();
		}
		if (item->GetItem_2() == 3) // ���
		{
			itemUi[7].Draw();
		}

		// bug3
		if (item->GetItem_3() == 1) // ��
		{
			itemUi[2].Draw();
		}
		if (item->GetItem_3() == 2) // ���
		{
			itemUi[5].Draw();
		}
		if (item->GetItem_3() == 3) // ���
		{
			itemUi[8].Draw();
		}

		/////////////////////////////////

		//�T���^�̉摜�؂�ւ�
		switch (santaImage)
		{
			//�ʏ�
		case 0:
			santa_Nor[0].Draw();
			break;
		case 1:
			santa_Nor[1].Draw();
			break;
		case 2:
			santa_Nor[2].Draw();
			break;
		case 3:
			santa_Nor[3].Draw();
			break;
		case 4:
			santa_Nor[4].Draw();
			break;
		case 5:
			santa_Nor[5].Draw();
			break;
		case 6:
			santa_Nor[6].Draw();
			break;
		case 7:
			santa_Nor[7].Draw();
			break;
			//huro
		case 8:
			santa_Huro[0].Draw();//�v���C���[�`��
			break;
		case 9:
			santa_Huro[1].Draw();//�v���C���[�`��
			break;
		case 10:
			santa_Huro[2].Draw();//�v���C���[�`��
			break;
		case 12:
			santa_Huro[3].Draw();//�v���C���[�`��
			break;
		case 13:
			santa_Huro[4].Draw();//�v���C���[�`��
			break;
		case 14:
			santa_Huro[5].Draw();//�v���C���[�`��
			break;
		case 15:
			santa_Huro[6].Draw();//�v���C���[�`��
			break;
		case 16:
			santa_Huro[7].Draw();//�v���C���[�`��
			break;
			//kin
		case 17:
			santa_Kin[0].Draw();//�v���C���[�`��
			break;
		case 18:
			santa_Kin[1].Draw();//�v���C���[�`��
			break;
		case 19:
			santa_Kin[2].Draw();//�v���C���[�`��
			break;
		case 20:
			santa_Kin[3].Draw();//�v���C���[�`��
			break;
		case 21:
			santa_Kin[4].Draw();//�v���C���[�`��
			break;
		case 22:
			santa_Kin[5].Draw();//�v���C���[�`��
			break;
		case 23:
			santa_Kin[6].Draw();//�v���C���[�`��
			break;
		default:
			break;
		}
		//hitbox2.Draw();
		if (particleFg)
		{
			particle.Draw();
		}


		if (damage5 == true)
		{
			damage.Draw();
			framcount++;
			if (framcount % 60 == 0)
			{
				damage5 = false;
			}
		}


		// �В��܂̑܂ƕR
		if (sp_ani == true && kintyaku_go == true || sp_ani == true && kintyaku_go1 == true) {
			himo.Draw();
		}

		if (sp_ani == true && kintyaku_go == true || sp_ani == true && kintyaku_go1) {
			if (bugPower == 0) {
				kintyaku[0].Draw();
			}
			else if (bugPower > 0) {
				kintyaku[1].Draw();
			}
		}
		ScoreCounter.Draw();
		//�X�R�A
		do {
			Number_UI[1].numU = score % (int)pow(10, keta + 1) / (int)pow(10, keta);//�ꌅ��؂�o��
			Number_UI[1].SetPos(scorepos.x - scoresize.x * keta, scorepos.y, scoresize.z);//�ʒu��ݒ�

			Number_UI[1].Draw();//�X�R�A��`��
			keta++;
		} while (score >= (int)pow(10, keta));
		Number_UI[1].SetPos(scorepos.x, scorepos.y, scorepos.z);

		Time.Draw();

		//��������
		do {
			Number_UI[2].numU = time % (int)pow(10, keta2 + 1) / (int)pow(10, keta2);//�ꌅ��؂�o��
			Number_UI[2].SetPos(timepos.x - timesize.x * keta2, timepos.y, timesize.z);//�ʒu��ݒ�

			Number_UI[2].Draw();//�X�R�A��`��
			keta2++;
		} while (time >= (int)pow(10, keta2));
		Number_UI[2].SetPos(timepos.x, timepos.y, timepos.z);

		UseBag.Draw();
		if (santa_bug == 0)
		{
			normalUI.Draw();
			normalmoji.Draw();
		}

		if (santa_bug == 1)
		{
			hurosikilUI.Draw();
			hurosikimoji.Draw();
		}

		if (santa_bug == 2)
		{
			kintyakuUI.Draw();
			kintyakumoji.Draw();
		}

		if (gameoverFg == true)
		{
			pause.Draw();
			Gameover.Draw();
			GoodMorning.Draw();
			TitleBack.Draw();
			Retry.Draw();
			Cursor.Draw();
		}

		if (pauseFg == true)
		{
			pause.Draw();
			Gameover.Draw();
			rule.Draw();
			Pausemoji.Draw();
			PauseTitleBack.Draw();
			///PauseRetry.Draw();
			PauseCursor.Draw();
			PauseGameback.Draw();

		}


		break;
	case BOSS:
		BOSSBACK.Draw();

		switch (bossImage)
		{
		case 0://�o��
			boss_toujou.Draw();
			break;
		case 1://�ҋ@
			boss_monster.Draw();
			break;
		case 2://���ӂ点��
			boss_punch.Draw();
			break;
		case 3://��т���
			boss_yobidashi.Draw();
			break;
			
		}
		break;
	case RESULT://���U���g
		DirectX::XMFLOAT3 timepos = Number[1].GetPos();
		DirectX::XMFLOAT3 timesize = Number[1].GetSize();

		DirectX::XMFLOAT3 maxscorepos = Number[2].GetPos();
		DirectX::XMFLOAT3 maxscoresize = Number[2].GetSize();

		DirectX::XMFLOAT3 scorepos2 = Number[3].GetPos();
		DirectX::XMFLOAT3 scoresize2 = Number[3].GetSize();

		DirectX::XMFLOAT3 scorepos3 = Number[4].GetPos();
		DirectX::XMFLOAT3 scoresize3 = Number[4].GetSize();

		DirectX::XMFLOAT3 scorepos4 = Number[5].GetPos();
		DirectX::XMFLOAT3 scoresize4 = Number[5].GetSize();

		DirectX::XMFLOAT3 scorepos5 = Number[6].GetPos();
		DirectX::XMFLOAT3 scoresize5 = Number[6].GetSize();

		

		Result.Draw();//���U���g�w�i
		
		cleartime = 150 - time;
		do {
			Number[1].numU = cleartime % (int)pow(10, keta3 + 1) / (int)pow(10, keta3);//�ꌅ��؂�o��
			Number[1].SetPos(timepos.x - timesize.x * keta3, timepos.y, timesize.z);//�ʒu��ݒ�

			Number[1].Draw();//�N���A�^�C����`��
			keta3++;
		} while (cleartime >= (int)pow(10, keta3));
		Number[1].SetPos(timepos.x, timepos.y, timepos.z);


		
		//�Ƃ����v���[���g�̐�
		
		do {
			Number[3].numU = presentcount % (int)pow(10, keta4 + 1) / (int)pow(10, keta4);//�ꌅ��؂�o��
			Number[3].SetPos(scorepos2.x - scoresize2.x * keta4, scorepos2.y, scoresize2.z);//�ʒu��ݒ�

			Number[3].Draw();//�N���A�^�C����`��
			keta4++;
		} while (presentcount >= (int)pow(10, keta4));
		Number[3].SetPos(scorepos2.x, scorepos2.y, scorepos2.z);

		//�Ƃ�����v���[���g�̐�
		
		do {
			Number[4].numU = bigpresentcount % (int)pow(10, keta5 + 1) / (int)pow(10, keta5);//�ꌅ��؂�o��
			Number[4].SetPos(scorepos3.x - scoresize3.x * keta5, scorepos3.y, scoresize3.z);//�ʒu��ݒ�

			Number[4].Draw();//�N���A�^�C����`��
			keta5++;
		} while (bigpresentcount >= (int)pow(10, keta5));
		Number[4].SetPos(scorepos3.x, scorepos3.y, scorepos3.z);

		//�v���[���g�̍��v�X�R�A
		presentscore = 5000;
		do {
			Number[5].numU = presentscore % (int)pow(10, keta6 + 1) / (int)pow(10, keta6);//�ꌅ��؂�o��
			Number[5].SetPos(scorepos4.x - scoresize4.x * keta6, scorepos4.y, scoresize4.z);//�ʒu��ݒ�
			
			Number[5].Draw();//�N���A�^�C����`��
			if (presentscore <= 0) { scorepos4.x = 300; }

			keta6++;
		} while (presentscore >= (int)pow(10, keta6));
		Number[5].SetPos(scorepos4.x, scorepos4.y, scorepos4.z);

		//�v���[���g��̍��v�X�R�A
		bigpresentscore = 10000 ;
		
		do {
			Number[6].numU = bigpresentscore % (int)pow(10, keta7 + 1) / (int)pow(10, keta7);//�ꌅ��؂�o��
			Number[6].SetPos(scorepos5.x - scoresize5.x * keta7, scorepos5.y, scoresize5.z);//�ʒu��ݒ�

			Number[6].Draw();//�N���A�^�C����`��
			if (bigpresentscore <= 0) { scorepos5.x = 300; }
			keta7++;
		} while (bigpresentscore >= (int)pow(10, keta7));
		Number[6].SetPos(scorepos5.x, scorepos5.y, scorepos5.z);


		X[1].numU = 10;
		X[2].numU = 10;
		X[1].Draw();
		X[2].Draw();



		//�N���A�^�C���ɉ����ăX�R�A���Z(��)
		if (kari == false)
		{
			score += time*101;
			kari = true;
		}
		

		do {
			Number[2].numU = score % (int)pow(10, keta8 + 1) / (int)pow(10, keta8);//�ꌅ��؂�o��
			Number[2].SetPos(maxscorepos.x - maxscoresize.x * keta8, maxscorepos.y, maxscoresize.z);//�ʒu��ݒ�

			Number[2].Draw();//�N���A�^�C����`��
			keta8++;
		} while (score >= (int)pow(10, keta8));
		Number[2].SetPos(maxscorepos.x, maxscorepos.y, maxscorepos.z);

		//���̃X�R�A�𒴂��Ă���ƐF�t���̐��ɂȂ鏈���@  ����
		if (score >= 5000)
		{
			ResultStar[1].Draw();
		}
		else
		{
			GrayStar[1].Draw();
		}

		if (score >= 10000)
		{
			ResultStar[2].Draw();
		}
		else
		{
			GrayStar[2].Draw();
		}

		if (score >= 15000)
		{
			ResultStar[3].Draw();
		}
		else
		{
			GrayStar[3].Draw();
		}

		if (score >= 25000)
		{
			ResultStar[4].Draw();
		}
		else
		{
			GrayStar[4].Draw();
		}

		

		Result_present.Draw();
		Result_Bigpresent.Draw();

		break;
	}



	D3D_FinishRender();//�`��I��
}

void Game::Uninit(void)
{

	delete item;
	background.Uninit();//�v���C���[�I��
	titlesanta.Uninit();//�I��
	title.Uninit();//�I��

	sky.Uninit();//�I��
	star.Uninit();//�I��
	Stage1_Loading.Uninit();
	Stage2_Loading.Uninit();
	for (int i = 1; i < image; i++)
	{
		ground[i].Uninit();
		wood[i].Uninit();
		mounten[i].Uninit();
		rock[i].Uninit();
		stairs[i].Uninit();
		snowman[i].Uninit();
		present[i].Uninit();
		snowball[i].Uninit();

		//�X�e�[�W2
		Ground_Stge2[i].Uninit();
		Tree_Stge2[i].Uninit();
		Block_Stge2[i].Uninit();
		Icicles_Stge2[i].Uninit();
		Stairs_Stge2[i].Uninit();
		Present_Stage2[i].Uninit();
		Collectrock_Stage2[i].Uninit();
		Snowball_Stage2[i].Uninit();
		Snowman_Stage2[i].Draw();
		Star_Stage2[i].Uninit();
		Tonakai_Stage2[i].Uninit();
	}

	BigPresent[1].Uninit();
	BigPresent_Stage2[1].Uninit();
	Breakrock_Stge2[1].Uninit();
	tree.Uninit();
	star_monster.Uninit();
	tonakai.Uninit();
	goal.Uninit();

	Result.Uninit();//���U���g�w�i
	Number[1].Uninit();//����
	Number[2].Uninit();//����
	Number[3].Uninit();//����
	Number[4].Uninit();//����
	Number[5].Uninit();//����
	Number[6].Uninit();//����
	ResultStar[1].Uninit();
	ResultStar[2].Uninit();
	ResultStar[3].Uninit();
	ResultStar[4].Uninit();

	Number_UI[1].Uninit();
	Number_UI[2].Uninit();
	
	Breakmoji.Uninit();

	X[1].Uninit();
	X[2].Uninit();

	invisiblewall[1].Uninit();
	invisiblewall[2].Uninit();

	Pausemoji.Uninit();
	PauseTitleBack.Uninit();
	PauseRetry.Uninit();
	PauseCursor.Uninit();
	PauseGameback.Uninit();

	Goal_Stage2.Uninit();
	rule.Uninit();
	Gameover.Uninit();
	GoodMorning.Uninit();
	TitleBack.Uninit();
	Retry.Uninit();
	Cursor.Uninit();
	PressBbotton.Uninit();
	pause.Uninit();
	SantaCursor.Uninit();
	ScoreCounter.Uninit();
	Time.Uninit();
	ItemStock.Uninit();
	StegeSelect.Uninit();


	BOSSBACK.Uninit();
	Bossground.Uninit();
	
	Result_present.Uninit();
	Result_Bigpresent.Uninit();
	sound.Uninit();//�T�E���h���I��
	// DirectX�̉������
	D3D_Release();//DirextX���I��
}

DirectX::XMFLOAT3 Game::GetSantaPos() const {
	return santa_Nor[0].GetPos();
}

const Object& Game::GetSanta() const {
	return santa_Nor[0];
}


DirectX::XMFLOAT3 Game::GetGroundPos(int index) const {
	if (index >= 0 && index < image) {
		return ground[index].GetPos();
	}
	else {
		return { 0.0f, 0.0f, 0.0f }; // �͈͊O�̏ꍇ�A�f�t�H���g�l��Ԃ�
	}
}

const Object& Game::GetGround(int index) const {
	if (index >= 0 && index < image) {
		return ground[index];
	}
	else {
		static Object dummy;
		return dummy; // �͈͊O�̏ꍇ�A�_�~�[�I�u�W�F�N�g��Ԃ�
	}
}
