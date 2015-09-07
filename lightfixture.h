// Emma Elliott
// Fall 2015
// This file is for the class LightFixture

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

class LightFixture : public Scenery
{
	// The default constructors inherits from Scenery
	LightFixture() : Scenery() {};
	LightFixture(const LightFixture& other) : Scenery(other) {};
	LightFixture(const Scenery& other) : Scenery(other) {};

	void createLight()
	{
		// When the lightscene node is created, it can call 
		// the position of the lightfixture and use that vector of numbers
	}

	bool correctMeshTextureSound()
	{
		// call the three access functions
		// check to see if the mesh, the sound, and the texture are correct for class
	}
};
