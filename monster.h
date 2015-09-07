// Emma Elliott
// With code from Will Foley, Cory Budka
// Fall 2015
// This file is for the class Monster

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

class Monster : public Scenery
{
	// The default constructors inherits from Scenery
	Monster() : animated_(true), Scenery() {};
	Monster(const Monster& other) : animated_(other.animated_), Scenery(other) {};
	Monster(const Scenery& other) : animated_(true), Scenery(other) {};

	bool correctMeshTextureSound()
	{
		// call the three access functions
		// check to see if the mesh, the sound, and the texture are correct for class
	}

	bool isAnimated()
	{
		// checks to see if the fan is on or off
	}

	void animate()
	{
		// Call Object's createNode()
		// get the node

		// If (node)
		// add the animation
	}

	void physics()
	{
		// Functions to create the physics for the objects
	}


	LEVEL_OF_INTERACTIVITY level_ = ACTIVATABLE;
	void onCollision(Object* object)
	{
		//if(object.getInteractivity == ID_NONINTERACTABLE)
		//play sound
		//either stun/kill/or do nothing
	}

private:
	
	bool animated_;
};
