#ifndef __BIGSCENEENTITY_H_
#define __BIGSCENEENTITY_H_

#include "d3dx9.h"
#include <string>

class SceneNode;
class Texture;

class SceneEntity
{
private:
	Texture* pAttachedTexture;					//ʵ��Ĳ���

public:
	SceneNode* pAttachedSceneNode;			//ʵ�屻���صĽڵ�

protected:
	float mAngle;											//ʵ��˳ʱ����б��
	D3DXVECTOR2 mPosition;					//ʵ��2Dƽ������

private:

public:
	//
	SceneEntity(float _mAngle = 0, const D3DXVECTOR2& _mPosition = D3DXVECTOR2(0.0, 0.0) );

	//
	~SceneEntity();

	//��Ӳ��ʣ��ǿ�ʵ�巵��false
	bool AttachTexture(Texture* pTexture);

	//ж�ز��ʣ���ʵ�巵��false
	bool DetachTexture();

	//����ʵ��2Dƽ������
	const D3DXVECTOR2& GetPosition();

	//����ʵ��˳ʱ����б��
	const float& GetAngle();

	//���ʵ��Ĳ��ʣ���ʵ�巵��NULL
	PDIRECT3DTEXTURE9 GetTexture();

	//��ò��ʿ��
	unsigned int GetTextureWidth();

	//��ò��ʸ߶�
	unsigned int GetTextureHeight();

	//����ʵ��2Dƽ������
	void SetPosition(const D3DXVECTOR2& Position);

	//����ʵ��˳ʱ����б��
	void SetAngle(const float& angle);

	//����ʵ�屻���صĽڵ�,������ʱ�����ҽڵ�ʹ��(��Ϸ������Ա����ʹ�ã��������Ը�)
	bool SetAttachedSceneNode(SceneNode* pSceneNode);

	//����ʱ����������ǰʵ��
	virtual void Update(const float& deltaTime) {}

};

#endif