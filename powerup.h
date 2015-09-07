// Emma Elliott
// With code from Will Foley
// Fall 2015
// This file is for the class PowerUp

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

class PowerUp : public Object
{
public:
	// The default constructors inherits from Object
	PowerUp() : animated_(true), Object() {};
	PowerUp(const PowerUp& other) : animated_(other.animated_), Object(other) {};
	PowerUp(const Object& other) : animated_(true), Object(other) {};

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

	LEVEL_OF_INTERACTIVITY level_ = ID_AQUIRABLE;
	virtual void onCollision(Object* object)
	{
		//if (object.getInteractivity == interactable)
		//play sound
		//Powerup disappears from level
		//an image is attached to the hud to show that the player has a powerup for use
		//that powerup is readied for use
	}

private:

	bool animated_;
};
