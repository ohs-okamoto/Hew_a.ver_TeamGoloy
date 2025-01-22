//#include "Enemy.h"
//
////作成者：岡本
////2025:1:11
//
//// コンストラクタ
//Enemy::Enemy(EnemyType _enemyType, DirectX::XMFLOAT3 _pos, DirectX::XMFLOAT3 _size, DirectX::XMFLOAT4 _color, float _speed, int _hp)	
//{
//	
//	// 敵の種類
//	m_enemyType = _enemyType;
//	// 敵の初期化
//	switch (m_enemyType)
//	{
//	case MobEnemy1:
//		Init(L"asset/snowman.png", 4, 1);
//		SetPos(30.0f, -160.0f, 0.0f);		//位置を設定
//		SetSize(180.0f, 90.0f, 0.f);	//大きさを設定
//		SetAngle(0.0f);             		//角度を設定
//		SetColor(1.0f, 1.0f, 1.0f, 1.0f); //色を設定
//
//		break;
//	case MobEnemy2:
//		Init(L"asset/star_monster.png", 3, 2);
//		SetPos(3600.0f, -150.0f, 0.0f);		//位置を設定
//		SetSize(200.0f, 110.0f, 0.f);	//大きさを設定
//		SetAngle(0.0f);             		//角度を設定
//		SetColor(1.0f, 1.0f, 1.0f, 1.0f); //色を設定
//
//		break;
//	case MobEnemy3:
//		Init(L"asset/tonakai.png", 4, 1);
//		SetPos(4800.0f, -140.0f, 0.0f);		//位置を設定
//		SetSize(220.0f, 130.0f, 0.f);	//大きさを設定
//		SetAngle(0.0f);             		//角度を設定
//		SetColor(1.0f, 1.0f, 1.0f, 1.0f); //色を設定
//
//		break;
//
//
//	}
//}
//