// Emma Elliott
// With code from Will Foley
// Fall 2015
// This file is for the class Bullet

#pragma once
#include <irrlicht.h>
#include <string>
#include <vector>
#include "Object.h"
using namespace irr;

using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif

class Bullet : public Object
{
	// The default constructors inherits from Object
	Bullet() : Object() {};
	Bullet(const Bullet& other) : Object(other) {};
	Bullet(const Object& other) : Object(other) {};

	bool correctMeshTextureSound()
	{
		// call the three access functions
		// check to see if the mesh, the sound, and the texture are correct for class
	}

	LEVEL_OF_INTERACTIVITY level_ = ID_NONINTERACTABLE;
	void onCollision(Object* object)
	{
		//bullet is destroyed
		//play sound
	}

};
