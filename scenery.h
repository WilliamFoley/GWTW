// Emma Elliott
// With code from Will Foley
// Fall 2015
// This file is for the class Scenery

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

class Scenery : public Object
{
public:
	// The default constructors inherits from Object
	Scenery() : Object() {};
	Scenery(const Scenery& other) : Object(other) {};
	Scenery(const Object& other) : Object(other) {};

	bool correctMeshTextureSound()
	{
		// call the three access functions
		// check to see if the mesh, the sound, and the texture are correct for class
	}

	LEVEL_OF_INTERACTIVITY level_ = NONE;
	virtual void onCollision(Object* object)
	{
		//nothing should happen to the scene
	}
};
