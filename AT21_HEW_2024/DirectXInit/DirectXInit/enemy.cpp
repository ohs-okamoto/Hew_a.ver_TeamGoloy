//#include "Enemy.h"
//
////�쐬�ҁF���{
////2025:1:11
//
//// �R���X�g���N�^
//Enemy::Enemy(EnemyType _enemyType, DirectX::XMFLOAT3 _pos, DirectX::XMFLOAT3 _size, DirectX::XMFLOAT4 _color, float _speed, int _hp)	
//{
//	
//	// �G�̎��
//	m_enemyType = _enemyType;
//	// �G�̏�����
//	switch (m_enemyType)
//	{
//	case MobEnemy1:
//		Init(L"asset/snowman.png", 4, 1);
//		SetPos(30.0f, -160.0f, 0.0f);		//�ʒu��ݒ�
//		SetSize(180.0f, 90.0f, 0.f);	//�傫����ݒ�
//		SetAngle(0.0f);             		//�p�x��ݒ�
//		SetColor(1.0f, 1.0f, 1.0f, 1.0f); //�F��ݒ�
//
//		break;
//	case MobEnemy2:
//		Init(L"asset/star_monster.png", 3, 2);
//		SetPos(3600.0f, -150.0f, 0.0f);		//�ʒu��ݒ�
//		SetSize(200.0f, 110.0f, 0.f);	//�傫����ݒ�
//		SetAngle(0.0f);             		//�p�x��ݒ�
//		SetColor(1.0f, 1.0f, 1.0f, 1.0f); //�F��ݒ�
//
//		break;
//	case MobEnemy3:
//		Init(L"asset/tonakai.png", 4, 1);
//		SetPos(4800.0f, -140.0f, 0.0f);		//�ʒu��ݒ�
//		SetSize(220.0f, 130.0f, 0.f);	//�傫����ݒ�
//		SetAngle(0.0f);             		//�p�x��ݒ�
//		SetColor(1.0f, 1.0f, 1.0f, 1.0f); //�F��ݒ�
//
//		break;
//
//
//	}
//}
//