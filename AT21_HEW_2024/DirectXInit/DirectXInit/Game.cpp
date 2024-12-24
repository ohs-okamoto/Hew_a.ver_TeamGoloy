#include "Game.h"


void Game::Init(HWND hWnd)
{
	D3D_Create(hWnd);//Directx��������

	santa.Init(L"asset/tati.png", 1, 1);//�T���^��������
	santa.SetPos(-200.0f, -150.0f, 0.0f);		//�ʒu��ݒ�
	santa.SetSize(100.0f, 80.0f, 0.f);	//�傫����ݒ�
	santa.SetAngle(0.0f);             		//�p�x��ݒ�
	santa.SetColor(1.0f, 1.0f, 1.0f, 1.0f); //�F��ݒ�

	

	background.Init(L"asset/background.png",1,1);//�v���C���[��������
	background.SetPos(0.0f, 0.0f, 0.0f);         //�ʒu��ݒ�
	background.SetSize(640.0f, 480.0f, 0.f);     //�傫���ݒ�
	background.SetAngle(0.0f);//�p�x��ݒ�	    

	//�R
	mounten[1].Init(L"asset/mountain_stage_1.png", 1, 1);//�Q�[���w�i
	mounten[1].SetPos(0.0f, 0.0f, 0.0f);//�ʒu�����
	mounten[1].SetSize(640.0f, 480.0f, 0.0f);//�傫���ݒ�
	mounten[1].SetAngle(0.0f);//�p�x�ݒ�

	mounten[2].Init(L"asset/mountain_stage_1.png", 1, 1);//�Q�[���w�i
	mounten[2].SetPos(640.0f, 0.0f, 0.0f);//�ʒu�����
	mounten[2].SetSize(640.0f, 480.0f, 0.0f);//�傫���ݒ�
	mounten[2].SetAngle(0.0f);//�p�x�ݒ�

	mounten[3].Init(L"asset/mountain_stage_1.png", 1, 1);//�Q�[���w�i
	mounten[3].SetPos(1280.0f, 0.0f, 0.0f);//�ʒu�����
	mounten[3].SetSize(640.0f, 480.0f, 0.0f);//�傫���ݒ�
	mounten[3].SetAngle(0.0f);//�p�x�ݒ�

	//�n��
	ground[1].Init(L"asset/ground.png", 1, 1);//�n��
	ground[1].SetPos(0.0f, -300.0f, 0.0f);//�ʒu�����
	ground[1].SetSize(640.0f, 200.0f, 0.0f);//�傫���ݒ�
	ground[1].SetAngle(0.0f);//�p�x�ݒ�

	ground[2].Init(L"asset/ground.png", 1, 1);//�n��
	ground[2].SetPos(700.0f, -300.0f, 0.0f);//�ʒu�����
	ground[2].SetSize(640.0f, 200.0f, 0.0f);//�傫���ݒ�
	ground[2].SetAngle(0.0f);//�p�x�ݒ�

	ground[3].Init(L"asset/ground.png", 1, 1);//�n��
	ground[3].SetPos(1400.0f, -300.0f, 0.0f);//�ʒu�����
	ground[3].SetSize(640.0f, 200.0f, 0.0f);//�傫���ݒ�
	ground[3].SetAngle(0.0f);//�p�x�ݒ�

	//��
	tree[1].Init(L"asset/wood_stage_1.png", 1, 1);//�^�C�g���w�i
	tree[1].SetPos(0.0f, -50.0f, 0.0f);//�ʒu�����
	tree[1].SetSize(640.0f, 320.0f, 0.0f);//�傫���ݒ�
	tree[1].SetAngle(0.0f);//�p�x�ݒ�

	tree[2].Init(L"asset/wood_stage_1.png", 1, 1);//�^�C�g���w�i
	tree[2].SetPos(640.0f, -50.0f, 0.0f);//�ʒu�����
	tree[2].SetSize(640.0f, 320.0f, 0.0f);//�傫���ݒ�
	tree[2].SetAngle(0.0f);//�p�x�ݒ�

	tree[3].Init(L"asset/wood_stage_1.png", 1, 1);//�^�C�g���w�i
	tree[3].SetPos(1280.0f, -50.0f, 0.0f);//�ʒu�����
	tree[3].SetSize(640.0f, 320.0f, 0.0f);//�傫���ݒ�
	tree[3].SetAngle(0.0f);//�p�x�ݒ�




	sky.Init(L"asset/sky.png", 1, 1);//�^�C�g���w�i
	sky.SetPos(0.0f, 0.0f, 0.0f);//�ʒu�����
	sky.SetSize(640.0f, 480.0f, 0.0f);//�傫���ݒ�
	sky.SetAngle(0.0f);//�p�x�ݒ�

	star.Init(L"asset/star.png", 1, 1);//��
	star.SetPos(0.0f, 0.0f, 0.0f);//�ʒu�����
	star.SetSize(640.0f, 480.0f, 0.0f);//�傫���ݒ�
	star.SetAngle(0.0f);//�p�x�ݒ�


	changescene = TITLE;//�V�[��������
}

void Game::Update(void) {
	input.Update();


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
		DirectX::XMFLOAT3 tree_pos1 = tree[1].GetPos();
		DirectX::XMFLOAT3 tree_pos2 = tree[2].GetPos();
		DirectX::XMFLOAT3 tree_pos3 = tree[3].GetPos();

		//�n��
		DirectX::XMFLOAT3 ground_pos1 = ground[1].GetPos();
		DirectX::XMFLOAT3 ground_pos2 = ground[2].GetPos();
		DirectX::XMFLOAT3 ground_pos3 = ground[3].GetPos();

		if (input.GetKeyPress(VK_D))
		{
			santa_pos.x += 5;

			if (santa_pos.x >= 0)//�v���C���[����ʐ^�񒆂ɍs�����Ƃ�
			{

				santa_pos.x -= 5;

				//�w�i�Ȃǂ����ɓ������ăv���C���[���E�ɓ����Ă�悤�Ɍ�����
				mounten_pos1.x -= 0.5;
				mounten_pos2.x -= 0.5;
				mounten_pos3.x -= 0.5;

				tree_pos1.x -= 3;
				tree_pos2.x -= 3;
				tree_pos3.x -= 3;

				ground_pos1.x -= 5;
				ground_pos2.x -= 5;
				ground_pos3.x -= 5;

			}
		}
		if (input.GetKeyPress(VK_A))
		{

			santa_pos.x -= 5;

			if (santa_pos.x <= 0)//�v���C���[����ʐ^�񒆂ɍs�����Ƃ�
			{
				santa_pos.x += 5;


				//�w�i�Ȃǂ��E�ɓ������ăv���C���[�����ɓ����Ă�悤�Ɍ�����
				mounten_pos1.x += 0.5;
				mounten_pos2.x += 0.5;
				mounten_pos3.x += 0.5;

				tree_pos1.x += 3;
				tree_pos2.x += 3;
				tree_pos3.x += 3;

				ground_pos1.x += 5;
				ground_pos2.x += 5;
				ground_pos3.x += 5;
			}
		}

		//�摜����ʊO�ɍs�����Ƃ��ɂ��̉摜����Ԍ��ɒu��
			//��@�摜�P����ʊO���摜�R�̌���

			//�R�̃X�N���[���@640=��ʃT�C�Y
		if (mounten_pos1.x <= -640 * 2)
		{
			mounten_pos1.x = mounten_pos3.x + SCREEN_WIDTH;

		}

		if (mounten_pos2.x <= -640 * 2)
		{
			mounten_pos2.x = mounten_pos1.x + SCREEN_WIDTH;

		}

		if (mounten_pos3.x <= -640* 2)
		{
			mounten_pos3.x = mounten_pos2.x + SCREEN_WIDTH;

		}

		//�؂̃X�N���[��
		if (tree_pos1.x <= -640 * 2)
		{
			tree_pos1.x = tree_pos3.x + SCREEN_WIDTH;

		}

		if (tree_pos2.x <= -640 * 2)
		{
			tree_pos2.x = tree_pos1.x + SCREEN_WIDTH;

		}

		if (tree_pos3.x <= -640 * 2)
		{
			tree_pos3.x = tree_pos2.x + SCREEN_WIDTH;

		}



		santa.SetPos(santa_pos.x, santa_pos.y, santa_pos.z);

		mounten[1].SetPos(mounten_pos1.x, mounten_pos1.y, mounten_pos1.z);
		mounten[2].SetPos(mounten_pos2.x, mounten_pos2.y, mounten_pos2.z);
		mounten[3].SetPos(mounten_pos3.x, mounten_pos3.y, mounten_pos3.z);
	
		tree[1].SetPos(tree_pos1.x, tree_pos1.y, tree_pos1.z);
		tree[2].SetPos(tree_pos2.x, tree_pos2.y, tree_pos2.z);
		tree[3].SetPos(tree_pos3.x, tree_pos3.y, tree_pos3.z);

		ground[1].SetPos(ground_pos1.x, ground_pos1.y, ground_pos1.z);
		ground[2].SetPos(ground_pos2.x, ground_pos2.y, ground_pos2.z);
		ground[3].SetPos(ground_pos3.x, ground_pos3.y, ground_pos3.z);



	}
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
		player.Draw();//�v���C���[�`��
		
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

			ground[i].Draw();

		}

		for (int i = 1; i < image; i++)
		{

			tree[i].Draw();
		}

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


	sky.Uninit();
	star.Uninit();
	for (int i = 1; i < image; i++)
	{
		ground[i].Uninit();
		tree[i].Uninit();
		mounten[i].Uninit();
	}

	
	// DirectX�̉������
	D3D_Release();//DirextX���I��
}