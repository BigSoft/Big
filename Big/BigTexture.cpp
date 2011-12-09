#include "BigTexture.h"

//#include "BigSceneManager.h"

Texture::Texture() { }

Texture::~Texture()
{
	this->pD3DTexture->Release();
}

const unsigned int& Texture::GetWidth()
{
	return this->Width;
}

const unsigned int& Texture::GetHeight()
{
	return this->Height;
}

const PDIRECT3DTEXTURE9& Texture::Get()
{
	return this->pD3DTexture;
}