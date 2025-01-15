#pragma once
#include <stdlib.h>
#include "Object.h"

 

enum EnemyType
{
	MobEnemy1,	// 雪だるまの敵　
	MobEnemy2,  // 鹿の敵　
	MobEnemy3,  // ツリーの敵
	Boss,		// ボス

};


class Enemy : public Object
{
private:
	EnemyType m_enemyType;								// 敵の種類								
public:
	// コンストラクタ
	Enemy(EnemyType _enemyType, DirectX::XMFLOAT3 _pos, DirectX::XMFLOAT3 _size,
									DirectX::XMFLOAT4 _color, float _speed, int _hp = 5);
	// デストラクタ
	~Enemy();
	void Update(void);			// 更新処理
	void UpdateBoss(void);		// ボスの更新処理

	EnemyType GetEnemyType(void);	// 敵の種類を取得
	

	void Move(void);			// 移動処理
	void MoveBoss(void);		// ボスの移動処理
};

