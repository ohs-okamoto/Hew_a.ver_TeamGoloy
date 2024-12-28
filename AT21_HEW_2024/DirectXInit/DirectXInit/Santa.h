#pragma once
//岡本穂高　2024/12/28 19:41
class SANTA
{
public:
	SANTA();
	~SANTA();
	void Move(); //動作
	void BagAvility(); //バッグの能力発動関数
	void Collectitem();//バッグの中身
	
private:
	int score;//クリアタイム格納変数
	int timeLife;//サンタのHP
};

