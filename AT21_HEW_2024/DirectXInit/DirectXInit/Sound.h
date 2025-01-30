#pragma once

#include <xaudio2.h>

// �T�E���h�t�@�C��
typedef enum
{
	SOUND_LABEL_BGM000 = 0,		// �T���v��BGM
	SOUND_LABEL_BGM001,	
	SOUND_LABEL_SE000 = 0,		// �T���v��SE
	SOUND_LABEL_SE001,			// SE
	SOUND_LABEL_SE002,		    // �_���[�WSE
	SOUND_LABEL_SE003,// ���SE
	SOUND_LABEL_SE004,// �W�����vSE
	//SOUND_LABEL_SE003,			// �T���v��SE


	SOUND_LABEL_MAX,
} SOUND_LABEL;

class Sound {
private:
	// �p�����[�^�\����
	typedef struct
	{
		LPCSTR filename;	// �����t�@�C���܂ł̃p�X��ݒ�
		bool bLoop;			// true�Ń��[�v�B�ʏ�BGM��ture�ASE��false�B
	} PARAM;

	PARAM m_param[100] =
	{
		{"sound/BGM/Christmas.wav", true},	// �T���v��BGM�i���[�v������̂�true�ݒ�j
		{"sound/BGM/gameover.wav", false},	    // �T���v��BGM
		{"sound/SE/damage.wav", false},  		// �T���v��SE�i���[�v���Ȃ��̂�false�ݒ�j
		{"sound/SE/yukidama.wav", false},		// �T���v��SE
		{"sound/SE/jump.wav", false},		// �T���v��SE
		//{"sound/SE/yukidama.wav", false},		// �T���v��SE


	};

	IXAudio2* m_pXAudio2 = NULL;
	IXAudio2MasteringVoice* m_pMasteringVoice = NULL;
	IXAudio2SourceVoice* m_pSourceVoice[SOUND_LABEL_MAX];
	WAVEFORMATEXTENSIBLE m_wfx[SOUND_LABEL_MAX]; // WAV�t�H�[�}�b�g
	XAUDIO2_BUFFER m_buffer[SOUND_LABEL_MAX];
	BYTE* m_DataBuffer[SOUND_LABEL_MAX];

	HRESULT FindChunk(HANDLE, DWORD, DWORD&, DWORD&);
	HRESULT ReadChunkData(HANDLE, void*, DWORD, DWORD);

public:
	// �Q�[�����[�v�J�n�O�ɌĂяo���T�E���h�̏���������
	HRESULT Init(void);

	// �Q�[�����[�v�I����ɌĂяo���T�E���h�̉������
	void Uninit(void);

	// �����Ŏw�肵���T�E���h���Đ�����
	void Play(SOUND_LABEL label);

	// �����Ŏw�肵���T�E���h���~����
	void Stop(SOUND_LABEL label);

	// �����Ŏw�肵���T�E���h�̍Đ����ĊJ����
	void Resume(SOUND_LABEL label);

	//���ʒ���
	void SetVolume(SOUND_LABEL label, float volume);

};

