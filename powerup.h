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
	PowerUp() : animated_(true), Object() {}
	PowerUp(IVideoDriver* driver, ISceneManager* smgr, const char* meshName, const char* textureName,
		const char* soundName, vector3d<f32> position, vector3d<f32> rotation, vector3d<f32> scale) : animated_(true),
		Object(driver, smgr, meshName, textureName, soundName, position, rotation, scale)
	{
		if (correctMeshTextureSound() == false)
		{
			setRightMesh(correctMesh_);
			setRightSound(correctSound_);
			changeTexture(correctTexture_);
		}
	}
	PowerUp(const PowerUp& other) : animated_(other.animated_), Object(other) {}
	PowerUp(const Object& other) : animated_(true), Object(other) {}

	bool correctMeshTextureSound()
	{
		// call the three access functions
		// check to see if the mesh, the sound, and the texture are correct for class
		return correctMesh_ == getMeshName() && correctSound_ == getSoundName() && correctTexture_ == getTextureName();

	}

	bool isAnimated()
	{
		// checks to see if the power up is moving
		return animated_ == true;
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

	~PowerUp()
	{
		delete[] correctMesh_;
		delete[] correctSound_;
		delete[] correctTexture_;
	}

private:
	bool animated_;
	// These will eventually need to change to the correct path
	const char* correctMesh_ = "C:/Users/Emma/Documents/Visual Studio 2013/Projects/irrlichtTest/irrlichtTest/media/powerup.obj";
	const char* correctSound_ = "None";
	const char* correctTexture_ = "C:/Users/Emma/Documents/Visual Studio 2013/Projects/irrlichtTest/irrlichtTest/media/randompowerup.png";
};
