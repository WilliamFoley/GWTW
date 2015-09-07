// Emma Elliott
// With code from Will Foley
// Fall 2015
// This file is for the class LandingPad

#pragma once
#include <irrlicht.h>
#include <string>
#include <vector>
#include "scenery.h"
#include "plane.h"
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

class LandingPad : public Scenery
{
public: 
	// The default constructors inherits from Scenery
	LandingPad() : landedOn_(false), Scenery() {};
	LandingPad(const LandingPad& other) : landedOn_(other.landedOn_), Scenery(other) {};
	LandingPad(const Scenery& other) : landedOn_(false), Scenery(other) {};

	bool correctMeshTextureSound()
	{
		// call the three access functions
		// check to see if the mesh, the sound, and the texture are correct for class
	}
	
	bool hasItBeenLandedOn()
	{
		// checks to see if plane has been here before
		// Use this to send plane back to last check point
	}

	LEVEL_OF_INTERACTIVITY level_ = ID_INTERACTABLE;
		void onCollision(Object* object)
		{
			//if (object.getInteractivity == interactable)
			//landing pad is activated
			//play landing sound
			//a turbo powerup is added to the hud (any other powerup is deleted from the hud)
			//await for launch key input
		}

private:

	bool landedOn_;
};
