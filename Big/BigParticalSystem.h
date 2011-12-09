//////////////////////////////////////////////////////////////////////////////////////////////////
// 
// File: pSystem.h
// 
// Author: Frank Luna (C) All Rights Reserved
//
// System: AMD Athlon 1800+ XP, 512 DDR, Geforce 3, Windows XP, MSVC++ 7.0 
//
// Desc: Represents a general particle system.
//          
//////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __pSystemH__
#define __pSystemH__

#include "d3dx9.h"
#include <list>

#include "BigBoundingGeometry.h"

namespace psys
{
	struct Particle
	{
		D3DXVECTOR3 _position;
		D3DCOLOR    _color;
		static const DWORD FVF;
	};
	
	struct Attribute
	{
		Attribute()
		{
			_lifeTime = 0.0f;
			_age      = 0.0f;
			_isAlive  = true;
		}

		D3DXVECTOR2 _position;     
		D3DXVECTOR2 _velocity;     
		D3DXVECTOR2 _acceleration; 
		float       _lifeTime;     // how long the particle lives for before dying  
		float       _age;          // current age of the particle  
		D3DXCOLOR   _color;        // current color of the particle   
		D3DXCOLOR   _colorFade;    // how the color fades with respect to time
		bool        _isAlive;    
	};


	class PSystem
	{
	public:
		PSystem();
		~PSystem();

		virtual bool init(IDirect3DDevice9* device, char* texFileName);
		virtual void reset(const D3DXVECTOR2& origin);
		
		// sometimes we don't want to free the memory of a dead particle,
		// but rather respawn it instead.
		virtual void resetParticle(Attribute* attribute) { }
		virtual void addParticle();

		virtual void update(float timeDelta) { }

		virtual void preRender();
		virtual void render();
		virtual void postRender();

		bool isEmpty();
		bool isDead();

	protected:
		virtual void removeDeadParticles();

	protected:
		IDirect3DDevice9*       _device;
		D3DXVECTOR2             _origin;
		//BoundingBox        _boundingBox;
		float                   _emitRate;   // rate new particles are added to system
		float                   _size;       // size of particles
		IDirect3DTexture9*      _tex;
		IDirect3DVertexBuffer9* _vb;
		std::list<Attribute>    _particles;
		int                     _maxParticles; // max allowed particles system can have

		//
		// Following three data elements used for rendering the p-system efficiently
		//

		DWORD _vbSize;      // size of vb
		DWORD _vbOffset;    // offset in vb to lock   
		DWORD _vbBatchSize; // number of vertices to lock starting at _vbOffset
	};

	class Firework : public PSystem
	{
	public:
		Firework(D3DXVECTOR2* origin, int numParticles);
		void resetParticle(Attribute* attribute);
		void update(float timeDelta);
		void preRender();
		void postRender();
	};
}

#endif // __pSystemH__