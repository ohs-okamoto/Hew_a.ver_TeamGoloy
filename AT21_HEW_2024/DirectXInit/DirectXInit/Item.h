#pragma once
#include <queue>

// 2025/01/20 ゴロイ
class Item {
public:
	Item(int id); // コンストラクタ
	~Item(); // デストラクタ
	
	void ItemGet(int item); // アイテムを取る
	void ItemRelease(); // アイテムを取り出す
	void ItemEffect(); // アイテムを効果
	bool QueueFull() const; // キューが満杯がどうかを確認
private:
	int item; // アイテムの種類
	static const int MAX_ITEMS = 3; // 最大アイテム数
	int id; // キューに入れる用の値
	std::queue<int> itemQueue; // アイテムを格納するキュー
};