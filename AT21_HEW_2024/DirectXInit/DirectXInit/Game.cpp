#include "Game.h"
#include "Collision.h"
#include <iostream>

using namespace std;

//2024�N12/24 ���X�N���[�� �쐬�@�l��

void Game::Init(HWND hWnd)
{
	D3D_Create(hWnd);//Directx��������
//====================================================
//�v���C���[�֘A
//====================================================
	santa.Init(L"asset/Santa_Normal_Move.png", 4, 4);//�T���^��������
	santa.SetPos(-200.0f, -175.0f, 0.0f);		//�ʒu��ݒ�
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
	ground[2].SetPos(1400.0f, -300.0f, 0.0f);//�ʒu�����
	ground[2].SetSize(1280.0f, 200.0f, 0.0f);//�傫���ݒ�
	ground[2].SetAngle(0.0f);//�p�x�ݒ�

	ground[3].Init(L"asset/ground.png", 1, 1);//�n��
	ground[3].SetPos(2500.0f, -300.0f, 0.0f);//�ʒu�����
	ground[3].SetSize(1280.0f, 200.0f, 0.0f);//�傫���ݒ�
	ground[3].SetAngle(0.0f);//�p�x�ݒ�

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
	tree.SetPos(400.0f, -70.0f, 0.0f);//�ʒu�����
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

		// ��U���ŏd�͓I�Ȃ��̂���ǉ����܂��@�S���C
		santa_pos.y -= 1;

		// �T���^�����ɗ��������ɏ����ʒu�ɖ߂鏈���@�S���C
		if (santa_pos.y == -250.0f)
		{
			santa_pos.x = 200.0f;
			santa_pos.y = -175.0f;
		}

		

			// �n�ʂƂ̓����蔻��̒ǉ� �S���C
		for (int i = 0; i < image; i++) {
			DirectX::XMFLOAT3 ground_pos = ground[i].GetPos();

			if (collision.ground_santa(ground[i], santa, 50.0f, 0.0f)) {
				//// �T���^���n�ʂ̏�ɂ���ꍇ
				if (santa_pos.y > ground_pos1.y + ground[i].GetSize().y / 2.0f) {

					santa_pos.y = ground_pos1.y + ground[i].GetSize().y / 2.0f + santa.GetSize().y / 2.0f;
					std::cout << "\nSanta is on top of the ground." << std::endl;
				}
				else {
					std::cout << "\nSanta is falling." << std::endl;
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

				ground_pos1.x -= 5;
				ground_pos2.x -= 5;
				ground_pos3.x -= 5;

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

				ground_pos1.x += 5;
				ground_pos2.x += 5;
				ground_pos3.x += 5;

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

		tree.SetPos(tree_pos.x, tree_pos.y, tree_pos.z);

		ground[1].SetPos(ground_pos1.x, ground_pos1.y, ground_pos1.z);
		ground[2].SetPos(ground_pos2.x, ground_pos2.y, ground_pos2.z);
		ground[3].SetPos(ground_pos3.x, ground_pos3.y, ground_pos3.z);
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

		for (int i = 1; i < image; i++)
		{
			mounten[i].Draw();//�Q�[���w�i

		}

		for (int i = 1; i < image; i++)
		{

			wood[i].Draw();
		}

		for (int i = 1; i < image; i++)
		{

			ground[i].Draw();

		}

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
	}
	tree.Uninit();
	
	// DirectX�̉������
	D3D_Release();//DirextX���I��
}