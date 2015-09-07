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
	Object() : meshName_(""), textureName_(""), soundName_("") 
	{
	// The vectors are given default positions
	}

	// Asks for a meshName, a textureName, a soundName, position, rotation, scale
	Object(IVideoDriver* driver, ISceneManager* smgr, const std::string meshName, const std::string textureName, 
		const std::string soundName, vector3d<f32> position (float pX, float pY, float pZ), 
		vector3d<f32> rotation (float rX, float rY, float rZ), 
		vector3d<f32> scale (float sX, float sY, float sZ)) : driver_(driver), smgr_(smgr), meshName_(meshName), 
		textureName_(textureName), soundName_(soundName)
	{
	// The float numbers then get added into their respective vectors
	}

	// Copy constructor
	Object(const Object& other) : driver_(other.driver_), smgr_(other.smgr_), meshName_(other.meshName_), 
		textureName_(other.textureName_), soundName_(other.soundName_)
	{
		// The vectors from other will get copied over to new vectors
	}

	// Deconstructor
	~Object();

	void createNode()
	{
		// The smgr uses the meshName to create the mesh
		// Then it adds it to the scene

		// If (node)
		// set texture, sound, position, rotation & scale
	}

	// Items which deal with collisions
	enum LEVEL_OF_INTERACTIVITY{ ID_AQUIRABLE = 1, ID_INTERACTABLE, ID_NONINTERACTABLE, ACTIVATABLE, NONE };
	LEVEL_OF_INTERACTIVITY getInteractivity(); //returns the level of interactivity

	void physics()
	{
		// Functions to create the physics for the objects
	}

	// Functions to change
	//		texture
	void changeTexture(std::string newTexture)
	{
		// Replaces the data in the private variable with the new information
	}
	//		position
	void changePosition(float newPX, float newPY, float newPZ)
	{
		// Replaces the floats in the related vector with the new numbers
	}
	//		rotation
	void changeRotation(float newRX, float newRY, float newRZ)
	{
		// Replaces the floats in the related vector with the new numbers
	}

	// Functions to access and return the
	//		Mesh
	IMeshSceneNode* getNode();
	//		Mesh Name
	std::string getMeshName();
	//		Texture Name
	std::string getTextureName();
	//		Sound Name
	std::string getSoundName();
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
	//		Driver
	IVideoDriver* driver_;
	//		Scene Manger
	ISceneManager* smgr_;
	//		Mesh
	std::string meshName_;
	IMesh* mesh_;
	//		Texture
	std::string textureName_;
	IMeshSceneNode* node_;
	//		Sound
	std::string soundName_;
	ISound*	sound_; // Has to include the IrrSound.h or whatever
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
