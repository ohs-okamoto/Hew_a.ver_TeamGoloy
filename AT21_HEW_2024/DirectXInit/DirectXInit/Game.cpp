#include "Game.h"
#include "Texture.h"
#include "Collision.h"
#include "Item.h"
#include <iostream>


using namespace std;

//2024�N12/24 ���X�N���[�� �쐬�@�l��
//2024�N12/31  �X�e�[�W�P�쐬 �@�l��



void Game::Init(HWND hWnd)
{
	D3D_Create(hWnd);//Directx��������

	//====================================================
	//�v���C���[�֘A
	//====================================================

	santa.Init(L"asset/Santa_Normal_Move_v2.png", 4, 4);//�T���^��������
	santa.SetPos(-400.0f, -175.0f, 0.0f);		//�ʒu��ݒ�
	santa.SetSize(150.0f, 120.0f, 0.f);	//�傫����ݒ�
	santa.SetAngle(0.0f);             		//�p�x��ݒ�
	santa.SetColor(1.0f, 1.0f, 1.0f, 1.0f); //�F��ݒ�


	//====================================================
	//�^�C�g��
	//====================================================
	title.Init(L"asset/title.png", 1, 1);//�T���^��������
	title.SetPos(150.0f, 50.0f, 0.0f);		//�ʒu��ݒ�
	title.SetSize(250.0f, 150.0f, 0.f);	//�傫����ݒ�
	title.SetAngle(0.0f);             		//�p�x��ݒ�
	title.SetColor(1.0f, 1.0f, 1.0f, 1.0f); //�F��ݒ�

	titlesanta.Init(L"asset/Hukuro_2.png", 1, 1);//��������
	titlesanta.SetPos(0.0f, 0.0f, 0.0f);         //�ʒu��ݒ�
	titlesanta.SetSize(1280.0f, 720.0f, 0.f);     //�傫���ݒ�
	titlesanta.SetAngle(0.0f);//�p�x��ݒ�	    

	background.Init(L"asset/background.png", 1, 1);//�v���C���[��������
	background.SetPos(0.0f, 0.0f, 0.0f);         //�ʒu��ݒ�
	background.SetSize(1280.0f, 720.0f, 0.f);     //�傫���ݒ�
	background.SetAngle(0.0f);//�p�x��ݒ�	 


	//====================================================
	// UI
	//====================================================

		// ���� bug1
	itemUi[0].Init(L"asset/iwa.png", 1, 1); //����
	itemUi[0].SetPos(-600.0f, 300.0f, 0.0f);//�ʒu�����
	itemUi[0].SetSize(100.0f, 100.0f, 0.0f);//�傫���ݒ�
	itemUi[0].SetAngle(0.0f);//�p�x�ݒ�

	// ���� bug2
	itemUi[1].Init(L"asset/iwa.png", 1, 1); //����
	itemUi[1].SetPos(-600.0f, 220.0f, 0.0f);//�ʒu�����
	itemUi[1].SetSize(100.0f, 100.0f, 0.0f);//�傫���ݒ�
	itemUi[1].SetAngle(0.0f);//�p�x�ݒ�

	// ���� bud3
	itemUi[2].Init(L"asset/iwa.png", 1, 1); //����
	itemUi[2].SetPos(-600.0f, 90.0f, 0.0f);//�ʒu�����
	itemUi[2].SetSize(100.0f, 100.0f, 0.0f);//�傫���ݒ�
	itemUi[2].SetAngle(0.0f);//�p�x�ݒ�

	// ��� bug1
	itemUi[3].Init(L"asset/yukidama.png", 1, 1); //���
	itemUi[3].SetPos(-600.0f, 300.0f, 0.0f);//�ʒu�����
	itemUi[3].SetSize(70.0f, 70.0f, 0.0f);//�傫���ݒ�
	itemUi[3].SetAngle(0.0f);//�p�x�ݒ�

	// ��� bug2
	itemUi[4].Init(L"asset/yukidama.png", 1, 1); //���
	itemUi[4].SetPos(-600.0f, 220.0f, 0.0f);//�ʒu�����
	itemUi[4].SetSize(70.0f, 70.0f, 0.0f);//�傫���ݒ�
	itemUi[4].SetAngle(0.0f);//�p�x�ݒ�

	// ��� bug3
	itemUi[5].Init(L"asset/yukidama.png", 1, 1); //���
	itemUi[5].SetPos(-600.0f, 90.0f, 0.0f);//�ʒu�����
	itemUi[5].SetSize(70.0f, 70.0f, 0.0f);//�傫���ݒ�
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
	rock[4].SetPos(1100.0f, -175.0f, 0.0f);////�ʒu�����
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
	BigPresent[1].Init(L"asset/big_present.png", 1, 1);//���킠
	BigPresent[1].SetPos(5400.0f, -25.0f, 0.0f);////�ʒu�����
	BigPresent[1].SetSize(105.0f, 100.0f, 0.0f);//�傫���ݒ�
	BigPresent[1].SetAngle(0.0f);//�p�x�ݒ�

	//====================================================
	//�X�e�[�W2
	//====================================================

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
	Collectrock_Stage2[1].SetPos(6300.0f, 100.0f, 0.0f);//�ʒu�����
	Collectrock_Stage2[1].SetSize(75.0f, 70.0f, 0.0f);//�傫���ݒ�
	Collectrock_Stage2[1].SetAngle(0.0f);//�p�x�ݒ�

	Collectrock_Stage2[2].Init(L"asset/iwa.png", 1, 1);//�v���[���g
	Collectrock_Stage2[2].SetPos(6300.0f, 100.0f, 0.0f);//�ʒu�����
	Collectrock_Stage2[2].SetSize(75.0f, 70.0f, 0.0f);//�傫���ݒ�
	Collectrock_Stage2[2].SetAngle(0.0f);//�p�x�ݒ�

	Collectrock_Stage2[3].Init(L"asset/iwa.png", 1, 1);//�v���[���g
	Collectrock_Stage2[3].SetPos(6300.0f, 100.0f, 0.0f);//�ʒu�����
	Collectrock_Stage2[3].SetSize(75.0f, 70.0f, 0.0f);//�傫���ݒ�
	Collectrock_Stage2[3].SetAngle(0.0f);//�p�x�ݒ�

	Collectrock_Stage2[4].Init(L"asset/iwa.png", 1, 1);//�v���[���g
	Collectrock_Stage2[4].SetPos(6300.0f, 100.0f, 0.0f);//�ʒu�����
	Collectrock_Stage2[4].SetSize(75.0f, 70.0f, 0.0f);//�傫���ݒ�
	Collectrock_Stage2[4].SetAngle(0.0f);//�p�x�ݒ�

	Collectrock_Stage2[5].Init(L"asset/iwa.png", 1, 1);//�v���[���g
	Collectrock_Stage2[5].SetPos(6300.0f, 100.0f, 0.0f);//�ʒu�����
	Collectrock_Stage2[5].SetSize(75.0f, 70.0f, 0.0f);//�傫���ݒ�
	Collectrock_Stage2[5].SetAngle(0.0f);//�p�x�ݒ�

	Collectrock_Stage2[6].Init(L"asset/iwa.png", 1, 1);//�v���[���g
	Collectrock_Stage2[6].SetPos(6300.0f, 100.0f, 0.0f);//�ʒu�����
	Collectrock_Stage2[6].SetSize(75.0f, 70.0f, 0.0f);//�傫���ݒ�
	Collectrock_Stage2[6].SetAngle(0.0f);//�p�x�ݒ�

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
	BigPresent_Stage2[1].Init(L"asset/big_present.png", 1, 1);//�v���[���g
	BigPresent_Stage2[1].SetPos(4450.0f, -250.0f, 0.0f);////�ʒu�����
	BigPresent_Stage2[1].SetSize(75.0f, 70.0f, 0.0f);//�傫���ݒ�
	BigPresent_Stage2[1].SetAngle(0.0f);//�p�x�ݒ�

	//�󂹂��
	Breakrock_Stge2[1].Init(L"asset/iwa_yuki.png", 1, 1);//�v���[���g
	Breakrock_Stge2[1].SetPos(4450.0f, -250.0f, 0.0f);////�ʒu�����
	Breakrock_Stge2[1].SetSize(350.0f, 300.0f, 0.0f);//�傫���ݒ�
	Breakrock_Stge2[1].SetAngle(0.0f);//�p�x�ݒ�

	//====================================================
	//�Ă�
	//====================================================

	snowman[1].Init(L"asset/Snowman_Move_v3.png", 4, 2);//�Ⴞ��܂�������
	snowman[1].SetPos(30.0f, -160.0f, 0.0f);		//�ʒu��ݒ�
	snowman[1].SetSize(180.0f, 90.0f, 0.f);	//�傫����ݒ�
	snowman[1].SetAngle(0.0f);             		//�p�x��ݒ�
	snowman[1].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //�F��ݒ�

	snowman[2].Init(L"asset/Snowman_Move_v3.png", 4, 2);//�Ⴞ��܂�������
	snowman[2].SetPos(1400.0f, -160.0f, 0.0f);		//�ʒu��ݒ�
	snowman[2].SetSize(180.0f, 90.0f, 0.f);	//�傫����ݒ�
	snowman[2].SetAngle(0.0f);             		//�p�x��ݒ�
	snowman[2].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //�F��ݒ�

	snowman[3].Init(L"asset/Snowman_Move_v3.png", 4, 2);//�䂫��������
	snowman[3].SetPos(2000.0f, -160.0f, 0.0f);		//�ʒu��ݒ�
	snowman[3].SetSize(180.0f, 90.0f, 0.f);	//�傫����ݒ�
	snowman[3].SetAngle(0.0f);             		//�p�x��ݒ�
	snowman[3].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //�F��ݒ�


	star_monster.Init(L"asset/Star_Move_v3.png", 6, 2);//�ق���������
	star_monster.SetPos(3600.0f, -150.0f, 0.0f);		//�ʒu��ݒ�
	star_monster.SetSize(200.0f, 110.0f, 0.f);	//�傫����ݒ�
	star_monster.SetAngle(0.0f);             		//�p�x��ݒ�
	star_monster.SetColor(1.0f, 1.0f, 1.0f, 1.0f); //�F��ݒ�

	tonakai.Init(L"asset/Tonakai_Move_v3.png", 4, 2);//�ƂȂ�����������
	tonakai.SetPos(4800.0f, -140.0f, 0.0f);		//�ʒu��ݒ�
	tonakai.SetSize(220.0f, 130.0f, 0.f);	//�傫����ݒ�
	tonakai.SetAngle(0.0f);             		//�p�x��ݒ�
	tonakai.SetColor(1.0f, 1.0f, 1.0f, 1.0f); //�F��ݒ�


	changescene = TITLE;//�V�[��������
	framcount = 0;
	item = new Item(1);

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

		if (input.GetKeyTrigger(VK_RETURN) || input.GetButtonPress(XINPUT_B))

		if (input.GetKeyTrigger(VK_RETURN)||input.GetButtonPress(XINPUT_A))

		{
			changescene = STAGE1_LOADING;
		}
		//�Q�������ƃX�e�[�W�Q��	
		if (input.GetKeyTrigger(VK_2))
		{
			changescene = STAGE_2;
		}

	}
	break;
	//�X�e�[�W�I��������ɏo����
	case STAGE1_LOADING:
	{
		framcount++;
		if (framcount % 100 == 0) //�Q�b�ギ�炢�ŃV�[���؂�ւ�
		{
			changescene = STAGE_1;
		}
	}
	break;
	case STAGE_1:
	{
		//�T���^
		DirectX::XMFLOAT3 santa_pos = santa.GetPos();
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
		//�v���[���g
		DirectX::XMFLOAT3 present_pos1 = present[1].GetPos();
		DirectX::XMFLOAT3 present_pos2 = present[2].GetPos();
		DirectX::XMFLOAT3 present_pos3 = present[3].GetPos();
		//�v���[���g��
		DirectX::XMFLOAT3 bigpresent_pos1 = BigPresent[1].GetPos();

		//item->GetItem_1();

		// ��U���ŏd�͓I�Ȃ��̂���ǉ����܂��@�S���C
		//santa_pos.y -= 1;

		// �T���^�����ɗ��������ɏ����ʒu�ɖ߂鏈���@�S���C
		if (santa_pos.y == -250.0f)
		{
			santa_pos.x = -400.0f;
			santa_pos.y = -175.0f;
		}


		framcount2++;
		if (framcount2 % 10 == 0) //�P�O�t���[���Ɉ��s����
		{
			snowman[1].numU++;
			snowman[2].numU++;
			snowman[3].numU++;
			star_monster.numU++;
			tonakai.numU++;
			if (snowman[1].numU >= 4 || snowman[2].numU >= 4 || snowman[3].numU >= 4 ||tonakai.numU >= 4)
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

		//-------�G�ړ�--------//

		//�Ⴞ��܁i�P�j
		if (moveFg1 == false)
		{
			snowman[1].numV = 0;
			snowman_pos1.x -= 1;
			if (snowman_pos1.x < ground_pos1.x - 240)//���͂��ɍs������
			{
				moveFg1 = true;
			}
		}

		if (moveFg1 == true)
		{
			
			snowman[1].numV = 1;
			snowman_pos1.x += 1;
			if (snowman_pos1.x > ground_pos1.x + 240)//�E�[�ɍs������
			{
				moveFg1 = false;
			}
		}

		//�Ⴞ��܁i2�j
		if (moveFg2 == false)
		{
			snowman[2].numV = 0;
			snowman_pos2.x -= 1;
			if (snowman_pos2.x < ground_pos2.x - 180)//���͂��ɍs������
			{
				moveFg2 = true;
			}
		}

		if (moveFg2 == true)
		{
			snowman[2].numV = 1;
			snowman_pos2.x += 1;
			if (snowman_pos2.x > ground_pos2.x + 240)//�E�[�ɍs������
			{
				moveFg2 = false;
			}
		}

		//�Ⴞ��܁i3�j
		if (moveFg3 == false)
		{
			snowman[3].numV = 0;
			snowman_pos3.x -= 1;
			if (snowman_pos3.x < ground_pos3.x - 700)//���ɍs������
			{
				moveFg3 = true;
			}
		}

		if (moveFg3 == true)
		{
			snowman[3].numV = 1;
			snowman_pos3.x += 1;
			if (snowman_pos3.x > ground_pos3.x - 200)//�E�[�ɍs������
			{
				moveFg3 = false;
			}
		}

		//���̓G�i�P)
		
		if (moveFg4 == false)
		{
			star_monster.numV = 0;
			star_monster_pos.x -= 2;
			if (star_monster_pos.x < ground_pos3.x - 130)//���ɍs������
			{
				moveFg4 = true;
			}
		}

		if (moveFg4 == true)
		{
			star_monster.numV = 1;
			star_monster_pos.x += 2;
			if (star_monster_pos.x > ground_pos3.x + 700)//�E�[�ɍs������
			{
				moveFg4 = false;
			}
		}
		

		//�g�i�J�C�̓G
		if (moveFg5 == false)
		{
			tonakai.numV = 0;
			tonakai_pos.x -= 2;
			if (tonakai_pos.x < ground_pos5.x - 400)//���ɍs������
			{
				moveFg5 = true;
			}
		}

		if (moveFg5 == true)
		{
			tonakai.numV = 1;
			tonakai_pos.x += 2;
			if (tonakai_pos.x > ground_pos5.x + 200)//�E�[�ɍs������
			{
				moveFg5 = false;
			}
		}



		// �n�ʂƂ̓����蔻��̒ǉ� �S���C
		for (int i = 0; i < image; i++) {
			DirectX::XMFLOAT3 ground_pos = GetGroundPos(i);

			if (collision.ground_santa(ground[i], santa, 50.0f, 0.0f)) {

				//// �T���^���n�ʂ̏�ɂ���ꍇ
				if (santa_pos.y > ground_pos.y + ground[i].GetSize().y / 2.0f) {
					santa_pos.y = ground_pos.y + ground[i].GetSize().y / 2.0f + santa.GetSize().y / 2.0f;
					/*std::cout << "\nSanta is on top of the ground." << std::endl;*/
				}
				else {
					/*std::cout << "\nSanta is falling." << std::endl;*/
				}

				// �T���^���n�ʂ̉E���ɂԂ������ꍇ
				if (santa_pos.x < ground_pos.x && santa_pos.y < ground_pos.y) {

					collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
				}

				// �T���^���n�ʂɂԂ������ꍇ
				if (santa_pos.x > ground_pos.x && santa_pos.y < ground_pos.y) {
					collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~
				}
			}
		}

		if (collision.goal_santa(goal, santa, 250.0f, 0.0f))
		{

			// �T���^���S�[���̉E���ɂԂ������ꍇ
			if (santa_pos.x < goal_pos.x && santa_pos.y < goal_pos.y)
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

				tree_pos.x = 1900;

				goal_pos.x = 5800;
			}


			// �T���^���S�[���ɂԂ������ꍇ
			/*if (santa_pos.x > goal_pos.x && santa_pos.y < goal_pos.y) {
				changescene = RESULT;
			}*/
		}

		// �T���^���A�C�e���ɓ���������
		bool itemCollected = false; // �A�C�e�������ɉ�����ꂽ���ǂ����̃t���O

		if (collision.item_santa(rock[1], santa, 100.0f, 0.0f))
		{
			if (input.GetKeyTrigger(VK_S) && !itemCollected)
			{
				/*itemID = 1;*/
				item->ItemGet(1); // ��������
				itemCollected = true;

			}
		}

		if (collision.item_santa(rock[2], santa, 100.0f, 0.0f))
		{
			if (input.GetKeyTrigger(VK_S) && !itemCollected)
			{
				/*itemID = 1;*/
				item->ItemGet(1); // ��������
				itemCollected = true;

			}
		}

		if (collision.item_santa(rock[3], santa, 100.0f, 0.0f))
		{
			if (input.GetKeyTrigger(VK_S) && !itemCollected)
			{
				/*itemID = 1;*/
				item->ItemGet(1); // ��������
				itemCollected = true;

			}
		}

		if (collision.item_santa(rock[4], santa, 100.0f, 0.0f))
		{
			if (input.GetKeyTrigger(VK_S) && !itemCollected)
			{
				/*itemID = 1;*/
				item->ItemGet(1); // ��������
				itemCollected = true;

			}
		}

		if (collision.item_santa(rock[5], santa, 100.0f, 0.0f))
		{
			if (input.GetKeyTrigger(VK_S) && !itemCollected)
			{
				/*itemID = 1;*/
				item->ItemGet(1); // ��������
				itemCollected = true;

			}
		}

		if (collision.item_santa(rock[6], santa, 100.0f, 0.0f))
		{
			if (input.GetKeyTrigger(VK_S) && !itemCollected)
			{
				/*itemID = 1;*/
				item->ItemGet(1); // ��������
				itemCollected = true;

			}
		}
		
		if (collision.item_santa(snowball[1], santa, 100.0f, 0.0f))
		{
			if (input.GetKeyTrigger(VK_S) && !itemCollected)
			{
				/*itemID = 1;*/
				item->ItemGet(2); // ��������
				itemCollected = true;

			}
		}

		if (collision.item_santa(snowball[2], santa, 100.0f, 0.0f))
		{
			if (input.GetKeyTrigger(VK_S) && !itemCollected)
			{
				/*itemID = 1;*/
				item->ItemGet(2); // ��������
				itemCollected = true;

			}
		}

		if (collision.item_santa(snowball[3], santa, 100.0f, 0.0f))
		{
			if (input.GetKeyTrigger(VK_S) && !itemCollected)
			{
				/*itemID = 1;*/
				item->ItemGet(2); // ��������
				itemCollected = true;

			}
		}

		if (collision.item_santa(snowball[4], santa, 100.0f, 0.0f))
		{
			if (input.GetKeyTrigger(VK_S) && !itemCollected)
			{
				/*itemID = 1;*/
				item->ItemGet(2); // ��������
				itemCollected = true;

			}
		}

		if (collision.item_santa(snowball[5], santa, 100.0f, 0.0f))
		{
			if (input.GetKeyTrigger(VK_S) && !itemCollected)
			{
				/*itemID = 1;*/
				item->ItemGet(2); // ��������
				itemCollected = true;

			}
		}

		if (collision.item_santa(snowball[6], santa, 100.0f, 0.0f))
		{
			if (input.GetKeyTrigger(VK_S) && !itemCollected)
			{
				/*itemID = 1;*/
				item->ItemGet(2); // ��������
				itemCollected = true;

			}
		}

		if (!itemCollected) {// �������ĂȂ��ꍇ
			if (input.GetKeyTrigger(VK_S))
			{
				item->ItemRelease(); // ���o��
			}
		}




		//
		// �؂Ƃ̓����蔻��̒ǉ��@�S���C
		if (collision.tree_santa(tree, santa, 200.0f, 0.0f)) {

			//// �T���^���؂̉E���ɂԂ������ꍇ
			//if (santa_pos.x < tree_pos.x) {

				collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~


			}
			// �T���^���؂̍����ɂԂ������ꍇ
			if (santa_pos.x > tree_pos.x) {
			//	collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~
			//	
			//	
			//}
			//// �T���^���؂̍����ɂԂ������ꍇ
			//if (santa_pos.x > tree_pos.x) {

			//	collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~

			//}
		}

	
		// 12/30  �T���^�̈ړ��A�j���[�V�����ǉ�  	�l��
		//�ړ����x
		speed = 5;

		if (collision.canMoveRight && input.GetKeyPress(VK_D)||input.GetLeftAnalogStick().x>=0.1)
		{
			santa_pos.x += 5;//�E�ړ�
			if (changeRight == true)
			{
				//������
				santa.numU = 0;
				santa.numV = 0;
				changeRight = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���
			}
			framcount++; //�t���[���J�E���g
			if (framcount % 10 == 0) //�P�O�t���[���Ɉ��s����
			{
				santa.numU++;
				if (santa.numU >= 4)
				{
					santa.numU = 0;
					santa.numV++;
					if (santa.numV >= 2)
					{
						santa.numV = 0;
					}
				}
			}

			if (santa_pos.x >= 0) //�v���C���[����ʐ^�񒆂ɍs�����Ƃ�
			{
				santa_pos.x -= 5;

				//�w�i�Ȃǂ����ɓ������ăv���C���[���E�ɓ����Ă�悤�Ɍ�����
				//�R
				mounten_pos1.x -= speed-4.5;
				mounten_pos2.x -= speed-4.5;
				mounten_pos3.x -= speed-4.5;
				//�w�i�̖�
				wood_pos1.x -= speed-2;
				wood_pos2.x -= speed-2;
				wood_pos3.x -= speed-2;
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
			}
		}
		else
		{
			//�L�[�𗣂���true�ɖ߂�
			changeRight = true;
		}

		if (collision.canMoveLeft && input.GetKeyPress(VK_A)|| input.GetLeftAnalogStick().x<=-0.1)
		{
			
			santa_pos.x -= 5;//���ړ�
			if (changeLeft == true)
			{
				//������
				santa.numU = 0;
				santa.numV = 2;
				changeLeft = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���
			}
			framcount++; //�t���[���J�E���g
			if (framcount % 10 == 0) //�P�O�t���[���Ɉ��s����
			{
				santa.numU++;
				if (santa.numU >= 4)
				{
					santa.numU = 0;
					santa.numV++;
					if (santa.numV >= 4)
					{
						santa.numV = 2;
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
			}
		}
		else
		{
			//�L�[�𗣂���true�ɖ߂�
			changeLeft = true;
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




		santa.SetPos(santa_pos.x, santa_pos.y, santa_pos.z);

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
		star_monster.SetPos(star_monster_pos.x, star_monster_pos.y, star_monster_pos.z);
		tonakai.SetPos(tonakai_pos.x, tonakai_pos.y, tonakai_pos.z);

		ground[1].SetPos(ground_pos1.x, ground_pos1.y, ground_pos1.z);
		ground[2].SetPos(ground_pos2.x, ground_pos2.y, ground_pos2.z);
		ground[3].SetPos(ground_pos3.x, ground_pos3.y, ground_pos3.z);

		ground[4].SetPos(ground_pos4.x, ground_pos4.y, ground_pos4.z);
		ground[5].SetPos(ground_pos5.x, ground_pos5.y, ground_pos5.z);

	}
	break;

	case STAGE_2:
	{
		//�T���^
		DirectX::XMFLOAT3 santa_pos = santa.GetPos();

		//�R
		DirectX::XMFLOAT3 mounten_pos1 = mounten[1].GetPos();
		DirectX::XMFLOAT3 mounten_pos2 = mounten[2].GetPos();
		DirectX::XMFLOAT3 mounten_pos3 = mounten[3].GetPos();

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
		//���̏�
		DirectX::XMFLOAT3 block_pos1 = Block_Stge2[1].GetPos();
		//�v���[���g
		DirectX::XMFLOAT3 present_pos1 = Present_Stage2[1].GetPos();
		DirectX::XMFLOAT3 present_pos2 = Present_Stage2[2].GetPos();
		DirectX::XMFLOAT3 present_pos3 = Present_Stage2[3].GetPos();



		// �T���^���A�C�e���ɓ���������
		bool itemCollected = false; // �A�C�e�������ɉ�����ꂽ���ǂ����̃t���O

		if (collision.item_santa(Collectrock_Stage2[1], santa, 100.0f, 0.0f))
		{
			if (input.GetKeyTrigger(VK_S) && !itemCollected)
			{
				/*itemID = 1;*/
				item->ItemGet(1); // ��������
				itemCollected = true;

			}
		}

		if (collision.item_santa(Collectrock_Stage2[2], santa, 100.0f, 0.0f))
		{
			if (input.GetKeyTrigger(VK_S) && !itemCollected)
			{
				/*itemID = 1;*/
				item->ItemGet(1); // ��������
				itemCollected = true;

			}
		}

		if (collision.item_santa(Collectrock_Stage2[3], santa, 100.0f, 0.0f))
		{
			if (input.GetKeyTrigger(VK_S) && !itemCollected)
			{
				/*itemID = 1;*/
				item->ItemGet(1); // ��������
				itemCollected = true;

			}
		}

		if (collision.item_santa(Collectrock_Stage2[4], santa, 100.0f, 0.0f))
		{
			if (input.GetKeyTrigger(VK_S) && !itemCollected)
			{
				/*itemID = 1;*/
				item->ItemGet(1); // ��������
				itemCollected = true;

			}
		}

		if (collision.item_santa(Collectrock_Stage2[5], santa, 100.0f, 0.0f))
		{
			if (input.GetKeyTrigger(VK_S) && !itemCollected)
			{
				/*itemID = 1;*/
				item->ItemGet(1); // ��������
				itemCollected = true;

			}
		}

		if (collision.item_santa(Collectrock_Stage2[6], santa, 100.0f, 0.0f))
		{
			if (input.GetKeyTrigger(VK_S) && !itemCollected)
			{
				/*itemID = 1;*/
				item->ItemGet(1); // ��������
				itemCollected = true;

			}
		}

		if (!itemCollected) {// �������ĂȂ��ꍇ
			if (input.GetKeyTrigger(VK_S))
			{
				item->ItemRelease(); // ���o��
			}
		}


		DirectX::XMFLOAT3 bigpresent_pos1 = BigPresent_Stage2[1].GetPos();
		//�󂹂��
		DirectX::XMFLOAT3 breakrock_pos1 = Breakrock_Stge2[1].GetPos();
		speed = 10;

		//�E�ړ�
		if (collision.canMoveRight && input.GetKeyPress(VK_D))
		{
			santa_pos.x += 5;//�E�ړ�
			if (changeRight == true)
			{
				//������
				santa.numU = 0;
				santa.numV = 0;
				changeRight = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���
			}
			framcount++; //�t���[���J�E���g
			if (framcount % 10 == 0) //�P�O�t���[���Ɉ��s����
			{
				santa.numU++;
				if (santa.numU >= 4)
				{
					santa.numU = 0;
					santa.numV++;
					if (santa.numV >= 2)
					{
						santa.numV = 0;
					}
				}
			}

			if (santa_pos.x >= 0) //�v���C���[����ʐ^�񒆂ɍs�����Ƃ�
			{
				santa_pos.x -= 5;

				//�w�i�Ȃǂ����ɓ������ăv���C���[���E�ɓ����Ă�悤�Ɍ�����
				//�R
				mounten_pos1.x -= speed-4.5;
				mounten_pos2.x -= speed-4.5;
				mounten_pos3.x -= speed-4.5;
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
			}
		}
		else
		{
			//�L�[�𗣂���true�ɖ߂�
			changeRight = true;
		}
		//���ړ�
		if (collision.canMoveLeft && input.GetKeyPress(VK_A))
		{
			santa_pos.x -= 5;//���ړ�
			if (changeLeft == true)
			{
				//������
				santa.numU = 0;
				santa.numV = 2;
				changeLeft = false;//��Ufalse�ɂ��Ĉ�񂵂���������Ȃ��悤�ɂ���
			}
			framcount++; //�t���[���J�E���g
			if (framcount % 10 == 0) //�P�O�t���[���Ɉ��s����
			{
				santa.numU++;
				if (santa.numU >= 4)
				{
					santa.numU = 0;
					santa.numV++;
					if (santa.numV >= 4)
					{
						santa.numV = 2;
					}
				}
			}

			if (santa_pos.x <= 0) //�v���C���[����ʐ^�񒆂ɍs�����Ƃ�
			{
				santa_pos.x += 5;

				//�w�i�Ȃǂ����ɓ������ăv���C���[���E�ɓ����Ă�悤�Ɍ�����
				//�R
				mounten_pos1.x += 0.5;
				mounten_pos2.x += 0.5;
				mounten_pos3.x += 0.5;
				//�n��
				ground_pos1.x += 5;
				ground_pos2.x += 5;
				ground_pos3.x += 5;
				ground_pos4.x += 5;
				ground_pos5.x += 5;
				ground_pos6.x += 5;
				ground_pos7.x += 5;
				//��
				tree_pos1.x += 5;
				//����
				block_pos1.x += 5;
				//���
				icicle_pos1.x += 5;
				icicle_pos2.x += 5;
				icicle_pos3.x += 5;
				//�K�i
				stairs_pos1.x += 5;
				stairs_pos2.x += 5;
				stairs_pos3.x += 5;
				stairs_pos4.x += 5;
				stairs_pos5.x += 5;

				//�v���[���g
				present_pos1.x += 5;
				present_pos2.x += 5;
				present_pos3.x += 5;

				bigpresent_pos1.x += 5;
				//�󂹂��
				breakrock_pos1.x += 5;
			}
		}
		else
		{
			//�L�[�𗣂���true�ɖ߂�
			changeLeft = true;
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


		santa.SetPos(santa_pos.x, santa_pos.y, santa_pos.z);//�T���^

		//�w�i�@�R
		mounten[1].SetPos(mounten_pos1.x, mounten_pos1.y, mounten_pos1.z);
		mounten[2].SetPos(mounten_pos2.x, mounten_pos2.y, mounten_pos2.z);
		mounten[3].SetPos(mounten_pos3.x, mounten_pos3.y, mounten_pos3.z);
		//�X�e�[�W�n��
		Ground_Stge2[1].SetPos(ground_pos1.x, ground_pos1.y, ground_pos1.z);
		Ground_Stge2[2].SetPos(ground_pos2.x, ground_pos2.y, ground_pos2.z);



		/*	item.SetItem_1();*/

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
		Tree_Stge2[1].SetPos(tree_pos1.x, tree_pos1.y, tree_pos1.z);
		//����
		Block_Stge2[1].SetPos(block_pos1.x, block_pos1.y, block_pos1.z);
		//�v���[���g
		Present_Stage2[1].SetPos(present_pos1.x, present_pos1.y, present_pos1.z);
		Present_Stage2[2].SetPos(present_pos2.x, present_pos2.y, present_pos2.z);
		Present_Stage2[3].SetPos(present_pos3.x, present_pos3.y, present_pos3.z);

		BigPresent_Stage2[1].SetPos(bigpresent_pos1.x, bigpresent_pos1.y, bigpresent_pos1.z);

		Breakrock_Stge2[1].SetPos(breakrock_pos1.x, breakrock_pos1.y, breakrock_pos1.z);

	}
	break;

	case RESULT:
		//�L�[���͂Ń^�C�g���ړ�
		if (input.GetKeyTrigger(VK_RETURN))
		{
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


	switch (changescene)
	{
	case TITLE://�^�C�g��
		background.Draw();//�v���C���[�`��
		titlesanta.Draw();
		title.Draw();
		break;
	case STAGE1_LOADING:
		Stage1_Loading.Draw();
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
		for (int i = 1; i < image; i++)
		{
			rock[i].Draw();
		}
		//���
		for (int i = 1; i < image; i++)
		{
			snowball[i].Draw();
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
		for (int i = 1; i < image; i++)
		{
			snowman[i].Draw();
		}

		BigPresent[1].Draw();

		tonakai.Draw();
		star_monster.Draw();

		tree.Draw();

		santa.Draw();//�v���C���[�`��
		goal.Draw();


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

		Breakrock_Stge2[1].Draw();
		BigPresent_Stage2[1].Draw();
		santa.Draw();//�v���C���[�`��
		break;

	case RESULT://���U���g

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


		Ground_Stge2[i].Uninit();
		Tree_Stge2[i].Uninit();
		Block_Stge2[i].Uninit();
		Icicles_Stge2[i].Uninit();
		Stairs_Stge2[i].Uninit();
		Present_Stage2[i].Uninit();

	}

	BigPresent[1].Uninit();
	BigPresent_Stage2[1].Uninit();
	Breakrock_Stge2[1].Uninit();
	tree.Uninit();
	star_monster.Uninit();
	tonakai.Uninit();
	goal.Uninit();

	// DirectX�̉������
	D3D_Release();//DirextX���I��
}

DirectX::XMFLOAT3 Game::GetSantaPos() const {
	return santa.GetPos();
}

const Object& Game::GetSanta() const {
	return santa;
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
