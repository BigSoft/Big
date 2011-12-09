#ifndef __BIGSCENEENTITY_H_
#define __BIGSCENEENTITY_H_

#include "d3dx9.h"
#include <string>

class SceneNode;
class Texture;

class SceneEntity
{
private:
	Texture* pAttachedTexture;					//实体的材质

public:
	SceneNode* pAttachedSceneNode;			//实体被挂载的节点

protected:
	float mAngle;											//实体顺时针倾斜角
	D3DXVECTOR2 mPosition;					//实体2D平面坐标

private:

public:
	//
	SceneEntity(float _mAngle = 0, const D3DXVECTOR2& _mPosition = D3DXVECTOR2(0.0, 0.0) );

	//
	~SceneEntity();

	//添加材质，非空实体返回false
	bool AttachTexture(Texture* pTexture);

	//卸载材质，空实体返回false
	bool DetachTexture();

	//返回实体2D平面坐标
	const D3DXVECTOR2& GetPosition();

	//返回实体顺时针倾斜角
	const float& GetAngle();

	//获得实体的材质，空实体返回NULL
	PDIRECT3DTEXTURE9 GetTexture();

	//获得材质宽度
	unsigned int GetTextureWidth();

	//获得材质高度
	unsigned int GetTextureHeight();

	//设置实体2D平面坐标
	void SetPosition(const D3DXVECTOR2& Position);

	//设置实体顺时针倾斜角
	void SetAngle(const float& angle);

	//设置实体被挂载的节点,被挂载时由所挂节点使用(游戏制作人员不可使用，否则后果自负)
	bool SetAttachedSceneNode(SceneNode* pSceneNode);

	//根据时间间隔升级当前实体
	virtual void Update(const float& deltaTime) {}

};

#endif