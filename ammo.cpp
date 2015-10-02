// Emma Elliott
// With code from Will Foley
// Fall 2015
// This file is for the class Ammo

#pragma once
#include <irrlicht.h>
#include <string>
#include <vector>
#include "powerup.h"
#include "ammo.h"
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

Ammo::Ammo(IVideoDriver* driver, ISceneManager* smgr, const char* meshName, const char* textureName,
	const char* soundName, vector3d<f32> position, vector3d<f32> rotation, vector3d<f32> scale) :
	PowerUp(driver, smgr, meshName, textureName, soundName, position, rotation, scale)
{
	if (correctMeshTextureSound() == false)
	{
		setRightMesh(correctMesh_);
		setRightSound(correctSound_);
		changeTexture(correctTexture_);
	}
}


bool Ammo::correctMeshTextureSound()
{
	// call the three access functions
	// check to see if the mesh, the sound, and the texture are correct for class
	return correctMesh_ == getMeshName() && correctSound_ == getSoundName() && correctTexture_ == getTextureName();
}

Ammo::~Ammo()
{
	delete[] correctMesh_;
	delete[] correctSound_;
	delete[] correctTexture_;
}