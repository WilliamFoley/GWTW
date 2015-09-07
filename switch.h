// Emma Elliott
// Fall 2015
// This file is for the class Switches

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

class Switch : public Scenery
{
	// The default constructors inherits from Scenery
	Switch() : animated_(false), Scenery() {};
	Switch(const Switch& other) : animated_(other.animated_), Scenery(other) {};
	Switch(const Scenery& other) : animated_(false), Scenery(other) {};

	bool correctMeshTextureSound()
	{
		// call the three access functions
		// check to see if the mesh, the sound, and the texture are correct for class
	}

	bool isAnimated()
	{
		// checks to see if the fan is on or off
	}

	LEVEL_OF_INTERACTIVITY level_ = ACTIVATABLE;
	void onCollision(Object* object)
	{
		//if(object.getInteractivity == ID_NONINTERACTABLE) this means if a bullet hit the switch
		//play sound
		//the animation occurs for the switch
		//the object the switch is connected to is activated
	}

private:
	bool animated_;
};
