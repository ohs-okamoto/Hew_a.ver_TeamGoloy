#include	<iostream>
#include	"Texture.h"
#include	"stb_image.h"


// テクスチャをロード
bool Texture::Load(const std::string& filename)
{
	bool sts = true;
	unsigned char* pixels;

	// 画像読み込み
	pixels = stbi_load(filename.c_str(), &m_width, &m_height, &m_bpp, 4);
	if (pixels == nullptr) {
		std::cout << filename.c_str() << " Load error " << std::endl;
		return false;
	}

	// ピクセルイメージ解放
	stbi_image_free(pixels);

	return true;
}
// テクスチャをメモリからロード
bool Texture::LoadFromFemory(const unsigned char* Data, int len) {

	bool sts = true;
	unsigned char* pixels;

	// 画像読み込み
	pixels = stbi_load_from_memory(Data,
		len,
		&m_width,
		&m_height,
		&m_bpp,
		STBI_rgb_alpha);



	// ピクセルイメージ解放
	stbi_image_free(pixels);

	return true;
}