// Emma Elliott
// With code from Will Foley, Cory Budka
// Fall 2015
// This file is for the parent class Object

#include "Object.h"
#include <irrlicht.h>
#include <string>
#include <vector>
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

Object::~Object()
{
	delete[] meshName_;
	delete[] textureName_;
	delete[] soundName_;
}

void Object::createNode()
{
	// The smgr uses the meshName to create the mesh
	// Then it adds it to the scene
	mesh_ = smgr_->getMesh(meshName_);
	/*if (!mesh_)
	{
	device_->drop();
	return 1;
	}*/
	node_ = smgr_->addAnimatedMeshSceneNode(mesh_);

	// If (node)
	// set texture, sound, position, rotation & scale
	if (node_)
	{
		node_->setMaterialFlag(EMF_LIGHTING, false);
		node_->setMaterialTexture(0, driver_->getTexture(textureName_));
		node_->setPosition(position_);
		node_->setScale(scale_);
		node_->setRotation(rotation_);
	}

}

void Object::physics()
{
	// Functions to create the physics for the objects
}

// Functions to change
//		mesh - only can be done before the node is created
void Object::setRightMesh(const char* newMesh)
{
	meshName_ = newMesh;
}
//		sound
void Object::setRightSound(const char* newSound)
{
	soundName_ = newSound;
}
//		texture
void Object::changeTexture(const char* newTexture)
{
	textureName_ = newTexture;
	if (node_)
	{
		node_->setMaterialTexture(0, driver_->getTexture(textureName_));
	}
}
//		position by just floats
void Object::changePosition(float newPX, float newPY, float newPZ)
{
	// Replaces the floats in the related vector with the new numbers
	position_ = vector3df(newPX, newPY, newPZ);
	if (node_)
	{
		node_->setPosition(position_);
	}
}
//		position by a vector
void Object::changePosition(vector3d<f32> newPosition)
{
	// Replaces the floats in the related vector with the new numbers
	position_ = newPosition;
	if (node_)
	{
		node_->setPosition(position_);
	}
}
//		rotation by just floats
void Object::changeRotation(float newRX, float newRY, float newRZ)
{
	// Replaces the floats in the related vector with the new numbers
	rotation_ = vector3df(newRX, newRY, newRZ);
	if (node_)
	{
		node_->setRotation(rotation_);
	}
}
//		rotation by a vector
void Object::changeRotation(vector3d<f32> newRotation)
{
	// Replaces the floats in the related vector with the new numbers
	rotation_ = newRotation;
	if (node_)
	{
		node_->setRotation(rotation_);
	}
}
// change velocity by just floats
void Object::changeVelocity(float newVX, float newVY, float newVZ)
{
	velocity_ = vector3df(newVX, newVY, newVZ);
}
// change velocity by a vector
void Object::changeVelocity(vector3d<f32> newVelocity)
{
	velocity_ = newVelocity;
}
// change acceleration by just floats
void Object::changeAcceleration(float newAX, float newAY, float newAZ)
{
	acceleration_ = vector3df(newAX, newAY, newAZ);
}
// change acceleration by a vector
void Object::changeAcceleration(vector3d<f32> newAcceleration)
{
	acceleration_ = newAcceleration;
}

// Functions to access and return the
//		Mesh
IAnimatedMeshSceneNode* Object::getNode()
{
	return node_;
}
//		Mesh Name
const char* Object::getMeshName()
{
	return meshName_;
}

//		Texture Name
const char* Object::getTextureName()
{
	return textureName_;
}

//		Sound Name
const char*  Object::getSoundName()
{
	return soundName_;
}

//		Position
vector3d<f32> Object::getPosition()
{
	return position_;
}

//		Rotation
vector3d<f32> Object::getRotation()
{
	return rotation_;
}

//		Scale
vector3d<f32> Object::getScale()
{
	return scale_;
}

//		Velocity
vector3d<f32> Object::getVelocity()
{
	return velocity_;
}

//		Acceleration
vector3d<f32> Object::getAcceleration()
{
	return acceleration_;
}