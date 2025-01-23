#include "Item.h"

// 2025/01/20 ゴロイ
Item::Item(int id):id(id),bug1(0),bug2(0),bug3(0) { // コンストラクタ


}

Item::~Item() { // デストラクタ

}



void Item::ItemGet(int item) { // アイテムを取る
	if (!QueueFull()) { // キューが満杯じゃ無ければ・・・

		id = item; // アイテムを変数「id」の中に入れる
		itemQueue.push(id); // キューに追加

		GetQueue();
	}
	else {}
}

void Item::ItemRelease() { // アイテムを取り出す
	if (!itemQueue.empty())
	{
		itemQueue.pop(); // キューの先頭のアイテムを取り出し削除
		GetQueue();
	}
}

bool Item::QueueFull() const { // キューが満杯かどうかを確認
	return itemQueue.size() >= MAX_ITEMS;
}

void Item::ItemEffect() { // アイテム効果

}

void Item::GetQueue(){
	std::queue<int> copyQueue = itemQueue; // キューをコピー
	std::vector<int> elements;             // コピーの内容を保持するvector

	// キューの内容をベクターに移す
	while (!copyQueue.empty()) {
		elements.push_back(copyQueue.front());
		copyQueue.pop();
	}

	if (elements.size() >= 1) {
		bug1 = elements[0];
	}
	else {
		bug1 = -1; // デフォルト値
	}
	if (elements.size() >= 2) {
		bug2 = elements[1];
	}
	else {
		bug2 = -1; // デフォルト値
	}
	if (elements.size() >= 3) {
		bug3 = elements[2];
	}
	else {
		bug3 = -1; // デフォルト値
	}
	

	
}

//void Item::SetItem_1() {
//	item1 = bug1;
//}
//void Item::SetItem_2(int bug2) {
//	item2 = bug2;
//}
//void Item::SetItem_3(int bug3) {
//	item3 = bug3;
//}


int Item::GetItem_1() {
	return bug1;
}

int Item::GetItem_2() const{
	return bug2;
}

int Item::GetItem_3() const{
	return bug3;
}