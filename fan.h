// Emma Elliott
// With code from Will Foley
// Fall 2015
// This file is for the class Fan

#pragma once
#include <irrlicht.h>
#include <string>
#include <vector>
#include "scenery.h"
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

class Fan : public Scenery
{
public:
	// The default constructors inherits from Scenery
	Fan() : animated_(false), Scenery() {};
	Fan(const Fan& other) : animated_(other.animated_), Scenery(other) {};
	Fan(const Scenery& other) : animated_(false), Scenery(other) {};

	bool correctMeshTextureSound()
	{
		// call the three access functions
		// check to see if the mesh, the sound, and the texture are correct for class
	}

	bool isAnimated()
	{
		// checks to see if the fan is on or off
	}


	LEVEL_OF_INTERACTIVITY level_ = NONE;
	virtual void onCollision(Object* object)
	{
		//nothing should happen to the fan
	}

private:

	bool animated_;
};
