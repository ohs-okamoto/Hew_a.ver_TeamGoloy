//#include "Enemy.h"
//
////�쐬�ҁF���{
////2025:1:11
//
//// �R���X�g���N�^
//Enemy::Enemy(EnemyType _enemyType, DirectX::XMFLOAT3 _pos, DirectX::XMFLOAT3 _size, DirectX::XMFLOAT4 _color, float _speed, int _hp)
//	: Object(_pos, _size, _color, _speed, _hp)
//{
//	
//	// �G�̎��
//	m_enemyType = _enemyType;
//	// �G�̏�����
//	switch (m_enemyType)
//	{
//	case MobEnemy1:
//		Init(L"asset/mobEnemyLeft.png", 4);       //�ȉ��̃t�@�C�����K���ɏ����Ă邩�炩���Ȃ����Ă�
//		
//		break;
//	case MobEnemy2:
//		Init(L"asset/mobEnemyRight.png", 4);
//		
//		break;
//	case MobEnemy3:
//		Init(L"asset/midBoss.png", 1);
//		
//		break;
//	case Boss:
//		Init(L"asset/boss01.png", 1, 3);
//		
//		
//}
