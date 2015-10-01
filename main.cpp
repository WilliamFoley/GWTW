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
#include "object.h"

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
	array<SJoystickInfo> joystickInfo;
	IrrlichtDevice* device = createDevice(driverType, core::dimension2d<u32>(800, 720), 32, false, false, false, &receiver);

	if (device == 0)
		return 1; // could not create selected driver.

	movement movement(receiver, joystickInfo, device);
	video::IVideoDriver* driver = device->getVideoDriver();
	scene::ISceneManager* smgr = device->getSceneManager();


	smgr->addCameraSceneNode(0, vector3df(0, 30, -40), vector3df(0, 5, 0));

	movement.detectJoy();
	//Main Game Loop
	while (device->run())
	{
		movement.detectInput();

		driver->beginScene(true, true, SColor(100, 70, 70, 70));

		smgr->drawAll();
		device->getGUIEnvironment()->drawAll();
		driver->endScene();
	}
	device->drop();
	return EXIT_SUCCESS;
}