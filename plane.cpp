// Emma Elliott
// With code from Will Foley, Cory Budka
// Fall 2015
// This file is for the class Plane

#pragma once
#include <irrlicht.h>
#include <string>
#include <vector>
#include "Object.h"
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

	// A plane takes in a velocity & acceleration
	Plane::Plane(IVideoDriver* driver, ISceneManager* smgr, const char* meshName, const char* textureName,
		const char* soundName, vector3d<f32> position, vector3d<f32> rotation, vector3d<f32> scale,
		vector3d<f32> velocity, vector3d<f32> acceleration, vector2d<f32> pitch) : pitch_(pitch),
		Object(driver, smgr, meshName, textureName, soundName, position, rotation, scale)
	{
		changeAcceleration(acceleration);
		changeVelocity(velocity);
		if (correctMeshTextureSound() == false)
		{
			setRightMesh(correctMesh_);
			setRightSound(correctSound_);
			changeTexture(correctTexture_);
		}
	}

	bool Plane::correctMeshTextureSound()
	{
		// call the three access functions
		// check to see if the mesh, the sound, and the texture are correct for class
		return correctMesh_ == getMeshName() && correctSound_ == getSoundName() && correctTexture_ == getTextureName();
	}

	void Plane::physics()
	{
		// Functions to create the physics for the objects
	}

	Plane::~Plane()
	{
		delete[] correctMesh_;
		delete[] correctSound_;
		delete[] correctTexture_;
	}