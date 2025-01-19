#include "Item.h"

// 2025/01/20 ゴロイ
Item::Item(int id):id(id) { // コンストラクタ

}

Item::~Item() { // デストラクタ

}

void Item::ItemGet(int item) { // アイテムを取る
	if (!QueueFull()) { // キューが満杯じゃ無ければ・・・

		id = item; // アイテムを変数「id」の中に入れる
		itemQueue.push(id); // キューに追加
	}
	else {}
}

void Item::ItemRelease() { // アイテムを取り出す
	itemQueue.pop(); // キューの先頭のアイテムを取り出し削除
}

bool Item::QueueFull() const { // キューが満杯かどうかを確認
	return itemQueue.size() >= MAX_ITEMS;
}

void Item::ItemEffect() { // アイテム効果

}