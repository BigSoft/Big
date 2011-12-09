#ifndef __BIGTEXTURE_H_
#define __BIGTEXTURE_H_

#include "d3dx9.h"
#include <string>

class Texture
{
private:
	PDIRECT3DTEXTURE9 pD3DTexture;		//DirectX3D材质
	unsigned int Width, Height;							//材质尺寸

public:

private:

public:
	//
	Texture();

	//
	~Texture();

	//获得材质宽度
	const unsigned int& GetWidth();

	//获得材质高度
	const unsigned int& GetHeight();

	//获得DirectX3D材质
	const PDIRECT3DTEXTURE9& Get();

friend class SceneManager;
};

#endif