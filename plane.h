// Emma Elliott
// With code from Will Foley, Cory Budka
// Fall 2015
// This file is for the class Plane

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

class Plane : public Object
{
public:
	// The default constructors inherits from Object
	Plane() : Object() {}
	// A plane takes in a velocity & acceleration
	Plane(IVideoDriver* driver, ISceneManager* smgr, const char* meshName, const char* textureName,
		const char* soundName, vector3d<f32> position, vector3d<f32> rotation, vector3d<f32> scale,
		vector3d<f32> velocity, vector3d<f32> acceleration, vector2d<f32> pitch);

	Plane(const Plane& other) : Object(other) {}
	Plane(const Object& other) : Object(other) {}

	bool correctMeshTextureSound();

	void physics();


	LEVEL_OF_INTERACTIVITY level_ = ID_INTERACTABLE;
	void onCollision(Object* object)
	{
		//if object.getInteractivity == ID_INTERACTABLE
		//plane location and rotation is reset
		//this means the plane hit a landing pad
		//else if object.getIteractivity != ID_AQUIRABLE (if plane did not hit a powerup)
		//plane is destroyed
	}

	~Plane();

private:
	vector2d<f32> pitch_;

	// These will eventually need to change to the correct path
	const char* correctMesh_ = "C:/Users/Emma/Documents/Visual Studio 2013/Projects/irrlichtTest/irrlichtTest/media/testairplane.obj";
	const char* correctSound_ = "None";
	const char* correctTexture_ = "C:/Users/Emma/Documents/Visual Studio 2013/Projects/irrlichtTest/irrlichtTest/media/paper3.png";
};