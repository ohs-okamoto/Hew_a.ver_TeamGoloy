#pragma once
#include "direct3d.h"
#include "WICTextureLoader.h"
//���쐬�ҁ@���{�䍂
class Object
{
private:
	// ���_�f�[�^�����߂�
	Vertex vertexList[4] =
	{
		{  -0.5f,  0.5f, 0.5f,1,1,1,1,0.0f,0.0f },  // �O�Ԗڂ̒��_���W�@{ x, y, z,r,g,b,a,u,v }
		{  0.5f, 0.5f, 0.5f,1,1,1,1,1.0f,0.0f  },  // �P�Ԗڂ̒��_���W
		{ -0.5f, -0.5f, 0.5f,1,1,1,1 ,0.0f,1.0f },  // �Q�Ԗڂ̒��_���W
		{ 0.5f, -0.5f, 0.5f,1,1,1,1 ,1.0f,1.0f },  // 3�Ԗڂ̒��_���W
	};
	//���W
	DirectX::XMFLOAT3 pos = { 0.0f,0.0f,0.0f};
	//�傫��
	DirectX::XMFLOAT3 size = { 100.0f,0.0f,0.0f };
	//�p�x
	float angle = 0.0f;
	//�F
	DirectX::XMFLOAT4 color = { 1.0f,1.0f,1.0f,1.0f };
	//���_�o�b�t�@
	ID3D11Buffer* m_pVertexBuffer;
	//�e�N�X�`���p�ϐ�
	ID3D11ShaderResourceView* m_pTextureView;

	//�e�N�X�`�����c���ɉ���������邩
	int splitX = 1;
	int splitY = 1;

	DirectX::XMFLOAT3 position; // �ʒu��ێ����郁���o�ϐ�

public:

	//���ォ�牽�i�ڂ�؂蔲���ĕ\������̂�
	float numU = 0;
	float numV = 0;

	void Init(const wchar_t* imgname,int sx,int sy);//������
	void Draw();//�`��
	void Uninit();//�I��
	void SetPos(float x, float y, float z);//���W�Z�b�g
	void SetSize(float x, float y, float z);//�傫���Z�b�g
	void SetAngle(float a);//�p�x�Z�b�g
	void SetColor(float r, float g, float b, float a); //�F���Z�b�g
	DirectX::XMFLOAT3 GetPos(void) const;   //���W���Q�b�g
	DirectX::XMFLOAT3 GetSize(void);  //�傫�����Z�b�g
	DirectX::XMFLOAT4 GetColor(void); //������Z�b�g
	float GetAngle(void);			  //�p�x���Z�b�g

	// �R���X�g���N�^
	//Object();
	//Object(DirectX::XMFLOAT3 _pos, DirectX::XMFLOAT3 _size, DirectX::XMFLOAT4 _color,  float _speed, int _hp);
	//// �f�X�g���N�^
	//virtual ~Object();

	//DirectX::XMFLOAT3 GetPos() const; // const �C���q��ǉ����Đ錾
};

