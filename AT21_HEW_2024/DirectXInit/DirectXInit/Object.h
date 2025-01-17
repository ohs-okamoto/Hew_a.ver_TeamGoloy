#pragma once
#include "direct3d.h"
#include "WICTextureLoader.h"
//※作成者　岡本穂高
class Object
{
private:
	// 頂点データを決める
	Vertex vertexList[4] =
	{
		{  -0.5f,  0.5f, 0.5f,1,1,1,1,0.0f,0.0f },  // ０番目の頂点座標　{ x, y, z,r,g,b,a,u,v }
		{  0.5f, 0.5f, 0.5f,1,1,1,1,1.0f,0.0f  },  // １番目の頂点座標
		{ -0.5f, -0.5f, 0.5f,1,1,1,1 ,0.0f,1.0f },  // ２番目の頂点座標
		{ 0.5f, -0.5f, 0.5f,1,1,1,1 ,1.0f,1.0f },  // 3番目の頂点座標
	};
	//座標
	DirectX::XMFLOAT3 pos = { 0.0f,0.0f,0.0f};
	//大きさ
	DirectX::XMFLOAT3 size = { 100.0f,0.0f,0.0f };
	//角度
	float angle = 0.0f;
	//色
	DirectX::XMFLOAT4 color = { 1.0f,1.0f,1.0f,1.0f };
	//頂点バッファ
	ID3D11Buffer* m_pVertexBuffer;
	//テクスチャ用変数
	ID3D11ShaderResourceView* m_pTextureView;

	//テクスチャが縦横に何分割されるか
	int splitX = 1;
	int splitY = 1;

	DirectX::XMFLOAT3 position; // 位置を保持するメンバ変数

public:

	//左上から何段目を切り抜いて表示するのか
	float numU = 0;
	float numV = 0;

	void Init(const wchar_t* imgname,int sx,int sy);//初期化
	void Draw();//描画
	void Uninit();//終了
	void SetPos(float x, float y, float z);//座標セット
	void SetSize(float x, float y, float z);//大きさセット
	void SetAngle(float a);//角度セット
	void SetColor(float r, float g, float b, float a); //色をセット
	DirectX::XMFLOAT3 GetPos(void) const;   //座標をゲット
	DirectX::XMFLOAT3 GetSize(void);  //大きさをセット
	DirectX::XMFLOAT4 GetColor(void); //いろをセット
	float GetAngle(void);			  //角度をセット

	// コンストラクタ
	//Object();
	//Object(DirectX::XMFLOAT3 _pos, DirectX::XMFLOAT3 _size, DirectX::XMFLOAT4 _color,  float _speed, int _hp);
	//// デストラクタ
	//virtual ~Object();

	//DirectX::XMFLOAT3 GetPos() const; // const 修飾子を追加して宣言
};

