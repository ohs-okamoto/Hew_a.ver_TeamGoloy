#pragma once

#include <xaudio2.h>

// サウンドファイル
typedef enum
{
	SOUND_LABEL_BGM000 = 0,		// サンプルBGM
	SOUND_LABEL_BGM001,	
	SOUND_LABEL_BGM002,
	SOUND_LABEL_SE000,		// サンプルSE
	SOUND_LABEL_SE001,			// SE
	SOUND_LABEL_SE002,		    // ジャンプSE
	SOUND_LABEL_SE003,          // 決定SE
	SOUND_LABEL_SE004,          // 攻撃SE
	SOUND_LABEL_BGM003,         //ボス戦
	SOUND_kintyaku,			// サンプルSE
	SOUND_huroshiki,
	SOUND_present,

	SOUND_LABEL_MAX,
} SOUND_LABEL;

class Sound {
private:
	// パラメータ構造体
	typedef struct
	{
		LPCSTR filename;	// 音声ファイルまでのパスを設定
		bool bLoop;			// trueでループ。通常BGMはture、SEはfalse。
	} PARAM;

	PARAM m_param[100] =
	{
		{"sound/BGM/Christmas.wav", true},	// サンプルBGM（ループさせるのでtrue設定）
		{"sound/BGM/gameover.wav", false},	    // サンプルBGM
		{"sound/BGM/title.wav", false},	    // サンプルBGM
		{"sound/SE/damage.wav", false},  		// サンプルSE（ループしないのでfalse設定）
		{"sound/SE/yukidama.wav", false},		// サンプルSE
		{"sound/SE/jump.wav", false},		// サンプルSE
		{"sound/SE/kettei.wav", false},		// サンプルSE
		{"sound/SE/重いパンチ1.wav", false},		// 攻撃SE
		{"sound/BGM/Christmasboss.wav", true},
		{"sound/SE/木が倒れる.wav", false},
		{"sound/SE/軽いパンチ1.wav", false},
		{"sound/SE/se_itemget_001.wav", false},


	};

	IXAudio2* m_pXAudio2 = NULL;
	IXAudio2MasteringVoice* m_pMasteringVoice = NULL;
	IXAudio2SourceVoice* m_pSourceVoice[SOUND_LABEL_MAX];
	WAVEFORMATEXTENSIBLE m_wfx[SOUND_LABEL_MAX]; // WAVフォーマット
	XAUDIO2_BUFFER m_buffer[SOUND_LABEL_MAX];
	BYTE* m_DataBuffer[SOUND_LABEL_MAX];

	HRESULT FindChunk(HANDLE, DWORD, DWORD&, DWORD&);
	HRESULT ReadChunkData(HANDLE, void*, DWORD, DWORD);

public:
	// ゲームループ開始前に呼び出すサウンドの初期化処理
	HRESULT Init(void);

	// ゲームループ終了後に呼び出すサウンドの解放処理
	void Uninit(void);

	// 引数で指定したサウンドを再生する
	void Play(SOUND_LABEL label);

	// 引数で指定したサウンドを停止する
	void Stop(SOUND_LABEL label);

	// 引数で指定したサウンドの再生を再開する
	void Resume(SOUND_LABEL label);

	//音量調節
	void SetVolume(SOUND_LABEL label, float volume);

};

