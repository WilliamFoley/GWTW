// Emma Elliott
// With code from Will Foley, Cory Budka
// Fall 2015
// This file is for the parent class Object

#pragma once
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

class Object //This is the main class that all will inherit from in some way
{
public:
	// Default constructor - sets the variables to either "" or an empty vector
	Object() {}

	// Asks for a meshName, a textureName, a soundName, position, rotation, scale
	Object(IVideoDriver* driver, ISceneManager* smgr, const char* meshName, const char* textureName, 
		const char* soundName, vector3d<f32> position, 
		vector3d<f32> rotation, 
		vector3d<f32> scale) : driver_(driver), smgr_(smgr), meshName_(meshName), 
		textureName_(textureName), soundName_(soundName), position_(position), rotation_(rotation), scale_(scale) {}

	// Copy constructor
	Object(const Object& other) : driver_(other.driver_), smgr_(other.smgr_), meshName_(other.meshName_),
		textureName_(other.textureName_), soundName_(other.soundName_), position_(other.position_),
		rotation_(other.rotation_), scale_(other.scale_) {}

	// Deconstructor
	~Object();

	void createNode();

	// Items which deal with collisions
	enum LEVEL_OF_INTERACTIVITY{ ID_AQUIRABLE = 1, ID_INTERACTABLE, ID_NONINTERACTABLE, ACTIVATABLE, NONE };
	LEVEL_OF_INTERACTIVITY getInteractivity()
	{
		//returns the level of interactivity
		return level_;
	}
	

	void physics();

	// Functions to change
	//		mesh - only can be done before the node is created
	void setRightMesh(const char* newMesh);

	//		sound
	void setRightSound(const char* newSound);

	//		texture
	void changeTexture(const char* newTexture);

	//		position by just floats
	void changePosition(float newPX, float newPY, float newPZ);

	//		position by a vector
	void changePosition(vector3d<f32> newPosition);

	//		rotation by just floats
	void changeRotation(float newRX, float newRY, float newRZ);

	//		rotation by a vector
	void changeRotation(vector3d<f32> newRotation);

	// change velocity by just floats
	void changeVelocity(float newVX, float newVY, float newVZ);

	// change velocity by a vector
	void changeVelocity(vector3d<f32> newVelocity);

	// change acceleration by just floats
	void changeAcceleration(float newAX, float newAY, float newAZ);

	// change acceleration by a vector
	void changeAcceleration(vector3d<f32> newAcceleration);

	// Functions to access and return the
	//		Mesh
	IAnimatedMeshSceneNode* getNode();

	//		Mesh Name
	const char* getMeshName();


	//		Texture Name
	const char*  getTextureName();

	//		Sound Name
	const char*  getSoundName();

	//		Position
	vector3d<f32> getPosition();

	//		Rotation
	vector3d<f32> getRotation();

	//		Scale
	vector3d<f32> getScale();

	//		Velocity
	vector3d<f32> getVelocity();

	//		Acceleration
	vector3d<f32> getAcceleration();

private:
	// Variables for
	//		Device
	IrrlichtDevice* device_;
	//		Driver
	IVideoDriver* driver_;
	//		Scene Manger
	ISceneManager* smgr_;
	//		Mesh
	//std::string meshName_;
	const char* meshName_;
	IAnimatedMesh* mesh_;
	//		Texture
	//std::string textureName_;
	const char* textureName_;
	IAnimatedMeshSceneNode* node_;
	//		Sound
	//std::string soundName_;
	const char* soundName_;
	//ISound*	sound_; // Has to include the IrrSound.h or whatever
	//		Position
	vector3d<f32> position_;
	//		Rotation
	vector3d<f32> rotation_;
	//		Scale
	vector3d<f32> scale_;
	//		Velocity
	vector3d<f32> velocity_;
	//		Acceleration
	vector3d<f32> acceleration_;
	//		Collisions
	LEVEL_OF_INTERACTIVITY level_;
		//each class will inherit an addional data member called LEVEL_OF_INTERACTIVITY
		//this will determine what happens to both objects if they collide
};

