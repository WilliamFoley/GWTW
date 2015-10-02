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
	Ammo() : PowerUp() {}

	Ammo(IVideoDriver* driver, ISceneManager* smgr, const char* meshName, const char* textureName,
		const char* soundName, vector3d<f32> position, vector3d<f32> rotation, vector3d<f32> scale);

	Ammo(const Ammo& other) : PowerUp(other) {}
	Ammo(const PowerUp& other) : PowerUp(other) {}

	bool correctMeshTextureSound();

	LEVEL_OF_INTERACTIVITY level_ = ID_AQUIRABLE;
	virtual void onCollision(Object* object)
	{
		//if (object.getInteractivity == interactable)
		//play sound
		//Powerup disappears from level
		//an image is attached to the hud to show that the player has a powerup for use
		//that powerup is readied for use
	}

	~Ammo();

private:
	// These will eventually need to change to the correct path
	const char* correctMesh_ = "C:/Users/Emma/Documents/Visual Studio 2013/Projects/irrlichtTest/irrlichtTest/media/powerup.obj";
	const char* correctSound_ = "None";
	const char* correctTexture_ = "C:/Users/Emma/Documents/Visual Studio 2013/Projects/irrlichtTest/irrlichtTest/media/ammo.png";
};
