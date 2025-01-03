#include "Game.h"
#include "Texture.h"
#include "Collision.h"
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
	santa.Init(L"asset/Santa_Normal_Move.png", 4, 4);//�T���^��������
	santa.SetPos(-400.0f, -175.0f, 0.0f);		//�ʒu��ݒ�
	santa.SetSize(180.0f, 90.0f, 0.f);	//�傫����ݒ�
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

	background.Init(L"asset/background.png",1,1);//�v���C���[��������
	background.SetPos(0.0f, 0.0f, 0.0f);         //�ʒu��ݒ�
	background.SetSize(1280.0f, 720.0f, 0.f);     //�傫���ݒ�
	background.SetAngle(0.0f);//�p�x��ݒ�	    
//====================================================
//�X�e�[�W
//====================================================
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
	ground[1].Init(L"asset/ground.png", 1, 1);//�n��
	ground[1].SetPos(0.0f, -300.0f, 0.0f);//�ʒu�����
	ground[1].SetSize(1280, 200.0f, 0.0f);//�傫���ݒ�
	ground[1].SetAngle(0.0f);//�p�x�ݒ�

	ground[2].Init(L"asset/ground.png", 1, 1);//�n��
	ground[2].SetPos(1300.0f, -300.0f, 0.0f);//�ʒu�����
	ground[2].SetSize(700.0f, 200.0f, 0.0f);//�傫���ݒ�
	ground[2].SetAngle(0.0f);//�p�x�ݒ�

	ground[3].Init(L"asset/ground.png", 1, 1);//�n��
	ground[3].SetPos(3100.0f, -300.0f, 0.0f);//�ʒu�����
	ground[3].SetSize(2500.0f, 200.0f, 0.0f);//�傫���ݒ�
	ground[3].SetAngle(0.0f);//�p�x�ݒ�

	ground[4].Init(L"asset/ground.png", 1, 1);//�n��
	ground[4].SetPos(4500.0f, -450.0f, 0.0f);//�ʒu�����
	ground[4].SetSize(500.0f, 200.0f, 0.0f);//�傫���ݒ�
	ground[4].SetAngle(0.0f);//�p�x�ݒ�

	ground[5].Init(L"asset/ground.png", 1, 1);//�n��
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

	tree.Init(L"asset/koyoju.png", 1, 1);//��
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

	//����
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
	stairs[1].Init(L"asset/stairs.png", 1, 1);//����
	stairs[1].SetPos(540.0f, -165.0f, 0.0f);//�ʒu�����
	stairs[1].SetSize(200.0f, 70.0f, 0.0f);//�傫���ݒ�
	stairs[1].SetAngle(0.0f);//�p�x�ݒ�

	stairs[2].Init(L"asset/stairs.png", 1, 1);//����
	stairs[2].SetPos(565.0f, -95.0f, 0.0f);//�ʒu�����
	stairs[2].SetSize(150.0f, 70.0f, 0.0f);//�傫���ݒ�
	stairs[2].SetAngle(0.0f);//�p�x�ݒ�

	stairs[3].Init(L"asset/stairs.png", 1, 1);//���킠
	stairs[3].SetPos(600.0f, -25.0f, 0.0f);////�ʒu�����
	stairs[3].SetSize(75.0f, 70.0f, 0.0f);//�傫���ݒ�
	stairs[3].SetAngle(0.0f);//�p�x�ݒ�

	stairs[4].Init(L"asset/stairs.png", 1, 1);//���킠
	stairs[4].SetPos(2800.0f, 80.0f, 0.0f);////�ʒu�����
	stairs[4].SetSize(300.0f, 70.0f, 0.0f);//�傫���ݒ�
	stairs[4].SetAngle(0.0f);//�p�x�ݒ�


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

//====================================================
//�Ă�
//====================================================

	snowman[1].Init(L"asset/snowman.png", 4, 1);//�Ⴞ��܂�������
	snowman[1].SetPos(30.0f, -160.0f, 0.0f);		//�ʒu��ݒ�
	snowman[1].SetSize(180.0f, 90.0f, 0.f);	//�傫����ݒ�
	snowman[1].SetAngle(0.0f);             		//�p�x��ݒ�
	snowman[1].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //�F��ݒ�

	snowman[2].Init(L"asset/snowman.png", 4, 1);//�Ⴞ��܂�������
	snowman[2].SetPos(1400.0f, -160.0f, 0.0f);		//�ʒu��ݒ�
	snowman[2].SetSize(180.0f, 90.0f, 0.f);	//�傫����ݒ�
	snowman[2].SetAngle(0.0f);             		//�p�x��ݒ�
	snowman[2].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //�F��ݒ�

	snowman[3].Init(L"asset/snowman.png", 4, 1);//�䂫��������
	snowman[3].SetPos(2700.0f, -160.0f, 0.0f);		//�ʒu��ݒ�
	snowman[3].SetSize(180.0f, 90.0f, 0.f);	//�傫����ݒ�
	snowman[3].SetAngle(0.0f);             		//�p�x��ݒ�
	snowman[3].SetColor(1.0f, 1.0f, 1.0f, 1.0f); //�F��ݒ�


	star_monster.Init(L"asset/star_monster.png", 3, 2);//�ق���������
	star_monster.SetPos(3600.0f, -150.0f, 0.0f);		//�ʒu��ݒ�
	star_monster.SetSize(200.0f, 110.0f, 0.f);	//�傫����ݒ�
	star_monster.SetAngle(0.0f);             		//�p�x��ݒ�
	star_monster.SetColor(1.0f, 1.0f, 1.0f, 1.0f); //�F��ݒ�

	tonakai.Init(L"asset/tonakai.png", 4, 1);//�ƂȂ�����������
	tonakai.SetPos(4800.0f, -140.0f, 0.0f);		//�ʒu��ݒ�
	tonakai.SetSize(220.0f, 130.0f, 0.f);	//�傫����ݒ�
	tonakai.SetAngle(0.0f);             		//�p�x��ݒ�
	tonakai.SetColor(1.0f, 1.0f, 1.0f, 1.0f); //�F��ݒ�


	changescene = TITLE;//�V�[��������
}

void Game::Update(void) {
	input.Update();

	Collision collision; // �錾
	collision.canMoveRight = true; // �t���O��������
	collision.canMoveLeft = true; // �t���O��������


	//�l�X�V���鏈���̌�ɓ��͏������L�q���邱�� by�ق���

	switch (changescene)
	{
	case TITLE:
		//�L�[���͂Ŗ{��
		if (input.GetKeyTrigger(VK_RETURN))
		{
			changescene = STAGE_1;
		}


		break;
	case STAGE_1:
	{
		//�T���^
		DirectX::XMFLOAT3 santa_pos = santa.GetPos();
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

		//�K�i
		DirectX::XMFLOAT3 stairs_pos1 = stairs[1].GetPos();
		DirectX::XMFLOAT3 stairs_pos2 = stairs[2].GetPos();
		DirectX::XMFLOAT3 stairs_pos3 = stairs[3].GetPos();
		DirectX::XMFLOAT3 stairs_pos4 = stairs[4].GetPos();

		DirectX::XMFLOAT3 snowman_pos1 = snowman[1].GetPos();
		DirectX::XMFLOAT3 snowman_pos2 = snowman[2].GetPos();
		DirectX::XMFLOAT3 snowman_pos3 = snowman[3].GetPos();
		DirectX::XMFLOAT3 star_monster_pos = star_monster.GetPos();
		DirectX::XMFLOAT3 tonakai_pos = tonakai.GetPos();


		DirectX::XMFLOAT3 present_pos1 = present[1].GetPos();
		DirectX::XMFLOAT3 present_pos2 = present[2].GetPos();
		DirectX::XMFLOAT3 present_pos3 = present[3].GetPos();


		// ��U���ŏd�͓I�Ȃ��̂���ǉ����܂��@�S���C
		santa_pos.y -= 1;
		
		// �T���^�����ɗ��������ɏ����ʒu�ɖ߂鏈���@�S���C
		if (santa_pos.y == -250.0f)
		{
			santa_pos.x = -400.0f;
			santa_pos.y = -175.0f;
		}

		

			// �n�ʂƂ̓����蔻��̒ǉ� �S���C
		for (int i = 0; i < image; i++) {
			DirectX::XMFLOAT3 ground_pos = GetGroundPos(i);

			if (collision.ground_santa(ground[i], santa, 50.0f, 0.0f)) {

				//// �T���^���n�ʂ̏�ɂ���ꍇ
				if (santa_pos.y > ground_pos1.y + ground[i].GetSize().y / 2.0f) {
                    santa_pos.y = ground_pos1.y + ground[i].GetSize().y / 2.0f + santa.GetSize().y / 2.0f;
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
		}

		
		// �؂Ƃ̓����蔻��̒ǉ��@�S���C
		if (collision.tree_santa(tree, santa, 200.0f, 0.0f)) {

			// �T���^���؂̉E���ɂԂ������ꍇ
			if (santa_pos.x < tree_pos.x) {

				collision.canMoveRight = false; // �E�Ɉړ����Ȃ�ړ����~

			}
			// �T���^���؂̍����ɂԂ������ꍇ
			if (santa_pos.x > tree_pos.x) {

				collision.canMoveLeft = false; // ���Ɉړ����Ȃ�ړ����~

			}
		}

		//
		// 12/30  �T���^�̈ړ��A�j���[�V�����ǉ�  	�l���@
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
				mounten_pos1.x -= 0.5;
				mounten_pos2.x -= 0.5;
				mounten_pos3.x -= 0.5;

				wood_pos1.x -= 3;
				wood_pos2.x -= 3;
				wood_pos3.x -= 3;

				rock_pos1.x -= 5;
				rock_pos2.x -= 5;
				rock_pos3.x -= 5;
				rock_pos4.x -= 5;
				rock_pos5.x -= 5;
				rock_pos6.x -= 5;

				ground_pos1.x -= 5;
				ground_pos2.x -= 5;
				ground_pos3.x -= 5;
				ground_pos4.x -= 5;
				ground_pos5.x -= 5;

				stairs_pos1.x -= 5;
				stairs_pos2.x -= 5;
				stairs_pos3.x -= 5;
				stairs_pos4.x -= 5;
				
				snowman_pos1.x -= 5;
				snowman_pos2.x -= 5;
				snowman_pos3.x -= 5;

				star_monster_pos.x -= 5;
				tonakai_pos.x -= 5;

				present_pos1.x -= 5;
				present_pos2.x -= 5;
				present_pos3.x -= 5;

				tree_pos.x -= 5;
			}
		}
		else
		{
			//�L�[�𗣂���true�ɖ߂邤
			changeRight = true;
		}

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
				mounten_pos1.x += 0.5;
				mounten_pos2.x += 0.5;
				mounten_pos3.x += 0.5;

				wood_pos1.x += 3;
				wood_pos2.x += 3;
				wood_pos3.x += 3;

				rock_pos1.x += 5;
				rock_pos2.x += 5;
				rock_pos3.x += 5;
				rock_pos4.x += 5;
				rock_pos5.x += 5;
				rock_pos6.x += 5;

				ground_pos1.x += 5;
				ground_pos2.x += 5;
				ground_pos3.x += 5;
				ground_pos4.x += 5;
				ground_pos5.x += 5;

				stairs_pos1.x += 5;
				stairs_pos2.x += 5;
				stairs_pos3.x += 5;
				stairs_pos4.x += 5;


				star_monster_pos.x += 5;
				tonakai_pos.x += 5;

				snowman_pos1.x += 5;
				snowman_pos2.x += 5;
				snowman_pos3.x += 5;
				  


				present_pos1.x += 5;
				present_pos2.x += 5;
				present_pos3.x += 5;

				tree_pos.x += 5;
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

		tree.SetPos(tree_pos.x, tree_pos.y, tree_pos.z);
		star_monster.SetPos(star_monster_pos.x, star_monster_pos.y, star_monster_pos.z);
		tonakai.SetPos(tonakai_pos.x, tonakai_pos.y, tonakai_pos.z);

		ground[1].SetPos(ground_pos1.x, ground_pos1.y, ground_pos1.z);
		ground[2].SetPos(ground_pos2.x, ground_pos2.y, ground_pos2.z);
		ground[3].SetPos(ground_pos3.x, ground_pos3.y, ground_pos3.z);
//<<<<<<< HEAD


//=======
		ground[4].SetPos(ground_pos4.x, ground_pos4.y, ground_pos4.z);
		ground[5].SetPos(ground_pos5.x, ground_pos5.y, ground_pos5.z);
//>>>>>>> e8321b3097c4f2e0599a6db2b02d5b3f315aeefc
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
		tonakai.Draw();
		star_monster.Draw();

		tree.Draw();

		santa.Draw();//�v���C���[�`��
		
		break;

	case 2://���U���g

		break;
	}



	D3D_FinishRender();//�`��I��
}

void Game::Uninit(void)
{
	background.Uninit();//�v���C���[�I��
	titlesanta.Uninit();//�I��
	title.Uninit();//�I��

	sky.Uninit();//�I��
	star.Uninit();//�I��

	for (int i = 1; i < image; i++)
	{
		ground[i].Uninit();
		wood[i].Uninit();
		mounten[i].Uninit();
		rock[i].Uninit();
		stairs[i].Uninit();
		snowman[i].Uninit();
		present[i].Uninit();
		
	}
	tree.Uninit();
	star_monster.Uninit();
	tonakai.Uninit();
	
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
