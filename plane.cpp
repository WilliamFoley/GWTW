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
		vector3d<f32> velocity, vector3d<f32> acceleration, vector3d<f32> pitch) : pitch_(pitch),
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

	vector3d<f32> Plane::getPitch()
	{
		return pitch_;
	}


	void Plane::updatePosition(float time)
	{
		//position_ += velocity_ * time;
		vector3d<f32> temp = getPosition();
		temp += getVelocity() * time;
		changePosition(temp);
	}

	void Plane::updateVelocity(float time)
	{
		//velocity_ = velocity_ + (acceleration_ * time);
		vector3d<f32> temp = getVelocity();
		temp = temp + (getAcceleration() * time);
		changeVelocity(temp);
	}

	float forceOfGravity = 0.0f;

	void Plane::updateAccelceration()
	{
		//acceleration_ = acceleration_ * (((forceOfGravity) ^ 2) * pitch_);
		vector3d<f32> temp = getAcceleration();
		temp = temp * ((forceOfGravity * forceOfGravity) * pitch_);
		changeAcceleration(temp);
	}

	void Plane::updatePitch()
	{
		int angle = 0;
		//angle needs to change based on user input
	}

	void Plane::physics(float time)
	{
		// Functions to create the physics for the objects
		updatePitch();
		updateAccelceration();
		updateVelocity(time);
		updatePosition(time);
	}

	Plane::~Plane()
	{
		delete[] correctMesh_;
		delete[] correctSound_;
		delete[] correctTexture_;
	}
