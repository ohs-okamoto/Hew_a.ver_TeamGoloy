#pragma once
#include <queue>
#include <vector>
#include <iostream>
#include "Object.h"
using namespace std;

// 2025/01/20 ゴロイ
class Item :public Object{
public:
	Item(int id); // コンストラクタ
	~Item(); // デストラクタ
	Object itemUi[3]; // アイテム入手時のUI
	void Init(const wchar_t* texturePath); // texturePath を引数に取る Init 関数の宣言

	void ItemGet(int item); // アイテムを取る
	void ItemRelease(); // アイテムを取り出す
	int ItemEffect(); // アイテムを効果
	bool QueueFull() const; // キューが満杯がどうかを確認
	
	void GetQueue() ; // キューの中身を取得する関数


	int GetItem_1() ;
	int GetItem_2() const;
	int GetItem_3() const;

	int GetItemCnt() const; // アイテムの個数を返すやつ
private:
	int item; // アイテムの種類
	static const int MAX_ITEMS = 3; // 最大アイテム数
	int id; // キューに入れる用の値
	std::queue<int> itemQueue; // アイテムを格納するキュー
	
	int item1,item2,item3;

	int bugPower; // 袋の力

	int bug1, bug2, bug3; //割り当て
};