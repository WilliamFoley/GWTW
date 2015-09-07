// Emma Elliott
// Fall 2015
// This file is for the class Desk

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

class Desk : public Scenery
{
public:
	// The default constructors inherits from Scenery
	Desk() : Scenery() {};
	Desk(const Desk& other) : Scenery(other) {};
	Desk(const Scenery& other) : Scenery(other) {};

	bool correctMeshTextureSound()
	{
		// call the three access functions
		// check to see if the mesh, the sound, and the texture are correct for class
	}
};
