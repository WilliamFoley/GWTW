// Emma Elliott
// With code from Will Foley
// Fall 2015
// This file is for the class Ammo

#pragma once
#include <irrlicht.h>
#include <string>
#include <vector>
#include "powerup.h"
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

class Ammo : public PowerUp
{
public:
	// The default constructors inherits from Object
	Ammo() : PowerUp() {};
	Ammo(const Ammo& other) : PowerUp(other) {};
	Ammo(const PowerUp& other) : PowerUp(other) {};

	bool correctMeshTextureSound()
	{
		// call the three access functions
		// check to see if the mesh, the sound, and the texture are correct for class
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
};
