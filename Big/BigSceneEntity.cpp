#include "BigSceneEntity.h"

#include "BigSceneNode.h"
#include "BigTexture.h"

//bool SceneEntity::createTexture(SceneManager *pSceneManager)
//{
//	/*if(D3DXCreateTextureFromFileEx(Device, filename,
//																D3DX_DEFAULT_NONPOW2, D3DX_DEFAULT_NONPOW2,D3DX_DEFAULT,
//																D3DUSAGE_RENDERTARGET, D3DFMT_FROM_FILE,
//																D3DPOOL_DEFAULT, D3DX_DEFAULT,
//																D3DX_DEFAULT, 0xFF000000,
//																NULL, NULL,
//																&pBackgroundTexture) == D3D_OK)
//		return true;
//	else*/
//		return false;
//}

SceneEntity::SceneEntity(float _mAngle, const D3DXVECTOR2 &_mPosition)
: mAngle(_mAngle), mPosition(_mPosition), pAttachedTexture(NULL), pAttachedSceneNode(NULL)
{
}

SceneEntity::~SceneEntity()
{
}

bool SceneEntity::AttachTexture(Texture *pTexture)
{
	if(this->pAttachedTexture == NULL)
	{
		this->pAttachedTexture = pTexture;
		return true;
	}
	else
		return false;
}

bool SceneEntity::DetachTexture()
{
	if(this->pAttachedTexture != NULL)
	{
		this->pAttachedTexture = NULL;
		return true;
	}
	else
		return false;
}

const D3DXVECTOR2& SceneEntity::GetPosition()
{
	return mPosition;
}

const float& SceneEntity::GetAngle()
{
	return mAngle;
}

PDIRECT3DTEXTURE9 SceneEntity::GetTexture()
{
	if(pAttachedTexture == NULL)
		return NULL;
	else
		return pAttachedTexture->Get();
}

unsigned int SceneEntity::GetTextureWidth()
{
	if(pAttachedTexture == NULL)
		return 0;
	else
		return pAttachedTexture->GetWidth();
}

unsigned int SceneEntity::GetTextureHeight()
{
	if(pAttachedTexture == NULL)
		return 0;
	else
		return pAttachedTexture->GetHeight();
}

void SceneEntity::SetPosition(const D3DXVECTOR2 &Position)
{
	mPosition = Position;
}

void SceneEntity::SetAngle(const float &angle)
{
	mAngle = angle;
}

bool SceneEntity::SetAttachedSceneNode(SceneNode *pSceneNode)
{
	if(this->pAttachedSceneNode == NULL)
	{
		this->pAttachedSceneNode = pSceneNode;
		return true;
	}
	else
		return false;
}
