#include	<iostream>
#include	"Texture.h"
#include	"stb_image.h"


// �e�N�X�`�������[�h
bool Texture::Load(const std::string& filename)
{
	bool sts = true;
	unsigned char* pixels;

	// �摜�ǂݍ���
	pixels = stbi_load(filename.c_str(), &m_width, &m_height, &m_bpp, 4);
	if (pixels == nullptr) {
		std::cout << filename.c_str() << " Load error " << std::endl;
		return false;
	}

	// �s�N�Z���C���[�W���
	stbi_image_free(pixels);

	return true;
}
// �e�N�X�`�������������烍�[�h
bool Texture::LoadFromFemory(const unsigned char* Data, int len) {

	bool sts = true;
	unsigned char* pixels;

	// �摜�ǂݍ���
	pixels = stbi_load_from_memory(Data,
		len,
		&m_width,
		&m_height,
		&m_bpp,
		STBI_rgb_alpha);



	// �s�N�Z���C���[�W���
	stbi_image_free(pixels);

	return true;
}