#pragma once
#include "Object.h"
#include "input.h"
#include "Texture.h"
#include "Item.h"
#include "Sound.h"

#define image		(10)

enum SceneName {
	TITLE,
	STAGE1_LOADING,
	STAGE2_LOADING,
	BOSS_LOADING,
	STAGESELECT,
	STAGE_1,
	STAGE_2,
	BOSS,
	RESULT
};

class Game
{
private:
	Object background;//�v���C���[�I�u�W�F�N�g
	Object titlesanta;//�^�C�g��
	Object title;//�^�C�g��

	Object Stage1_Loading;


	Object santa_Nor[8];  // �T���^�I�u�W�F�N�g �ʏ��
	Object santa_Huro[8]; // �T���^�I�u�W�F�N�g ���C�~
	Object santa_Kin[7];  // �T���^�I�u�W�F�N�g �В���

	Object star;//��
	Object sky;//��
	Object mounten[image];//�Q�[����ʂ̔w�i�ɂ���R

	Object itemUi[9]; // �A�C�e�����莞��UI

	Object use_rock[3];     // ������
	Object use_snowball[3]; // ������
	Object use_turara[3];   // ������


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

	Object Returntogame;//�Q�[���ɖ߂�

	//�X�e�[�W�Q�֘A
	Object Ground_Stge2[image];//�X�e�[�W�Q�̏�
	Object Tree_Stge2[image];//��
	Object Block_Stge2[image];//�u���b�N
	Object Icicles_Stge2[image];//���
	Object Stairs_Stge2[image];//�K�i
	Object Present_Stage2[image];//�v���[���g
	Object BigPresent_Stage2[image];//�v���[���g
	Object Breakrock_Stge2[image];//�󂹂��
	Object Collectrock_Stage2[image];
	Object Snowball_Stage2[image];



	//���U���g�֘A
	Object Result;//���U���g�w�i
	Object Number[2];//����
	Object ResultStar[5];//��
	Object GrayStar[5];//�����Ȑ�
	Object Result_Bigpresent;//��v��
	Object Result_present;//�v�������

	//UI�֘A
	Object Time;//��������
	Object ItemStock;//�����Ă����A���
	Object Number_UI[3];//�����@1:�X�R�A�@2:����
	Object UseBag;//���݂̑�
	Object ScoreCounter;

	//�Q�[���I�[�o�[���
	Object Gameover;//�w�i
	Object GoodMorning;//���͂悤
	Object Retry;//���g���C
	Object TitleBack;//�^�C�g���ɖ߂�
	Object Cursor;
	//�X�e�[�W�Z���N�g
	Object StegeSelect;//�X�e�[�W�Z���N�g
	Object SantaCursor;//�T���^�J�[�\��
	Object PressBbotton;//A�����Ă�
	Object pause;//�|�[�Y��ʃI�u�W�F�N�g


	Object rule;//������@
	//Object pause;//�|�[�Y��ʃI�u�W�F�N�g

	bool gameoverFg = false;//�|�[�Y�t���O
	bool pauseFg = false;//�|�[�Y�t���O

	bool changeRight = true;//�L������
	bool changeLeft = true;//


	int changescene = TITLE;//�V�[��

	int presentcount=0;//���v���[���g�Ƃ�����

	int score = 0;//�X�R�A



	int time = 150;
	int cleartime = 0;

	bool HitFg = false;

	bool ResettingFg = false;

	int hitcooltime=0;//�G�Ɠ����������̖��G����

	//�Z�N���g��ʂł̈ړ��t���O
	bool Select_MoverightFg = false;
	bool Select_MoveleftFg = false;

	bool CursorFg = false;

	//�������~�܂��Ă邩
	bool StopCheck =true;

	//�t���[���J�E���g
	int framcount = 0;
	int framcount2 = 0;
	int framcount3 = 0;
	int framcount4 = 0;
	int framcount5 = 0;
	//�G�̈ړ��t���O
	bool moveFg1 = false;
	bool moveFg2= false;
	bool moveFg3 = false;
	bool moveFg4 = false;
	bool moveFg5 = false;

	
	float speed = 0;

	Input input; //����

	int select = 1;

	
	Item* item; //�����o�ϐ�
	Sound sound;


	// �A�C�e���𓧖��ɂ��邩���Ȃ����̕ϐ�
	int rock_visible1 = 0;
	int rock_visible2 = 0;
	int rock_visible3 = 0;
	int rock_visible4 = 0;
	int rock_visible5 = 0;
	int rock_visible6 = 0;
	int snow_visible1 = 0;
	int snow_visible2 = 0;
	int snow_visible3 = 0;
	int snow_visible4 = 0;
	int snow_visible5 = 0;
	int snow_visible6 = 0;

	// ���̐��E�ɂ͓�̕�������B�΂��ΈȊO���B 0:�����l�@1:�΁@2:���
	int itemID_1 = 0;
	int itemID_2 = 0;
	int itemID_3 = 0;

	// �A�C�e���g�p���̓���
	bool itemMove1 = false;
	bool itemMove2 = false;
	bool itemMove3 = false;

	// �A�C�e���g�p���̍��W�̊Ǘ�
	bool itemMove1_M = false;
	bool itemMove2_M = false;
	bool itemMove3_M = false;

	// ���̃A�C�e�����o��܂Ŏg���܂���
	int changeItem = 0;

	// �T���^�̌���
	int direction = 0; // 0:�E�@1:��

	// �T���^�̉摜
	int santaImage = 0;

	// �܂̗�
	int bugPower = 0; // 0:�����@1:�З͎�@2:�З͒��@3:�З͋�(�ő�З�)

	// �ŗL�\�͕ϐ�
	bool sp_ani = false; 

	bool changeRight_SP_1 = true;//�L������
	bool changeLeft_SP_1 = true;//
	bool changeRight_SP = true;//�L������
	bool changeLeft_SP = true;//

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

