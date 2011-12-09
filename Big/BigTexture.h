#ifndef __BIGTEXTURE_H_
#define __BIGTEXTURE_H_

#include "d3dx9.h"
#include <string>

class Texture
{
private:
	PDIRECT3DTEXTURE9 pD3DTexture;		//DirectX3D����
	unsigned int Width, Height;							//���ʳߴ�

public:

private:

public:
	//
	Texture();

	//
	~Texture();

	//��ò��ʿ��
	const unsigned int& GetWidth();

	//��ò��ʸ߶�
	const unsigned int& GetHeight();

	//���DirectX3D����
	const PDIRECT3DTEXTURE9& Get();

friend class SceneManager;
};

#endif