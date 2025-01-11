#pragma once
#include <stdlib.h>
#include "Object.h"

 

enum EnemyType
{
	MobEnemy1,	// �Ⴞ��܂̓G�@
	MobEnemy2,  // ���̓G�@
	MobEnemy3,  // �c���[�̓G
	Boss,		// �{�X

};


class Enemy : public Object
{
private:
	EnemyType m_enemyType;								// �G�̎��								
public:
	// �R���X�g���N�^
	Enemy(EnemyType _enemyType, DirectX::XMFLOAT3 _pos, DirectX::XMFLOAT3 _size,
									DirectX::XMFLOAT4 _color, float _speed, int _hp = 5);
	// �f�X�g���N�^
	~Enemy();
	void Update(void);			// �X�V����
	void UpdateBoss(void);		// �{�X�̍X�V����

	EnemyType GetEnemyType(void);	// �G�̎�ނ��擾
	

	void Move(void);			// �ړ�����
	void MoveBoss(void);		// �{�X�̈ړ�����
};

