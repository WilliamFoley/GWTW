//
//CS-365
//Fall2015
// Gone With The Wind

#ifdef _MSC_VER
// We'll also define this to stop MSVC complaining about sprintf().
#define _CRT_SECURE_NO_WARNINGS
#define _IRR_COMPILE_WITH_JOYSTICK_EVENTS_
#define _IRR_COMPILE_WITH_DIRECTINPUT_JOYSTICK_
#pragma comment(lib, "Irrlicht.lib")
//#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif

#include <cstdlib>
#include <iostream>
#include <irrlicht.h>
#include "driverChoice.h"
#include "input.h"
#include "movement.h"

using namespace irr;

using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

int main()
{
	// ask user for driver
	video::E_DRIVER_TYPE driverType = driverChoiceConsole();
	if (driverType == video::EDT_COUNT)
		return 1;

	// create device
	Myinput receiver;

	//create a joystickInfo array to store joy buttons
	array<SJoystickInfo> joystickInfo;

	//Create an Irrlicht device to run our program with
	IrrlichtDevice* device = createDevice(driverType, core::dimension2d<u32>(800, 720), 32, false, false, false, &receiver);

	//If device failed.
	if (device == 0)
		return EXIT_FAILURE; // could not create selected driver.

	//Create movement, **this would be changed to the world class later 
	movement movement(receiver, joystickInfo, device);

	//Create a video display Driver
	video::IVideoDriver* driver = device->getVideoDriver();
	
	//Create a scene manager for the objects and camera
	scene::ISceneManager* smgr = device->getSceneManager();

	//adds a camera to the scene
	smgr->addCameraSceneNode(0, vector3df(0, 30, -40), vector3df(0, 5, 0));

	//Detects plugged in joysticks.
	movement.detectJoy();

	//Main Game Loop
	while (device->run())
	{
		//Detect movement and inputs
		movement.detectInput();

		driver->beginScene(true, true, SColor(100, 70, 70, 70));

		smgr->drawAll();
		device->getGUIEnvironment()->drawAll();
		driver->endScene();
	}
	device->drop();
	return EXIT_SUCCESS;
}