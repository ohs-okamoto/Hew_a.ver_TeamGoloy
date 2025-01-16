//#include "Enemy.h"
//
////作成者：岡本
////2025:1:11
//
//// コンストラクタ
//Enemy::Enemy(EnemyType _enemyType, DirectX::XMFLOAT3 _pos, DirectX::XMFLOAT3 _size, DirectX::XMFLOAT4 _color, float _speed, int _hp)
//	: Object(_pos, _size, _color, _speed, _hp)
//{
//	
//	// 敵の種類
//	m_enemyType = _enemyType;
//	// 敵の初期化
//	switch (m_enemyType)
//	{
//	case MobEnemy1:
//		Init(L"asset/mobEnemyLeft.png", 4);       //以下のファイル名適当に書いてるからかきなおしてね
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
