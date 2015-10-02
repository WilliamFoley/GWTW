//Shawn Cherry
//CS 365
//Fall 2015
//This is the movement class

#include <cstdlib>
#include <irrlicht.h>
#include "input.h"

#pragma once
using namespace irr;
using namespace std;
using namespace core;
class movement : public Myinput
{

public:
	movement(Myinput& receiver, array<SJoystickInfo>& joystickInfo, IrrlichtDevice* device) { input_ = &receiver; joystickInfo_ = &joystickInfo; device_ = device; }
	void detectInput();
	void detectJoy();
	virtual ~movement(){}
	
private:
	Myinput* input_;
	array<SJoystickInfo>*  joystickInfo_;
	IrrlichtDevice* device_;
	bool joyConnected_;
	pair<int, bool> JoysConnected_;
};

void movement::detectJoy()
{
	if (device_->activateJoysticks(*joystickInfo_))
	{
		if ((*joystickInfo_).size() == 0)
			joyConnected_ = false;
		else
			joyConnected_ = true;

		std::cout << "Joystick support is enabled and " << (*joystickInfo_).size() << " joystick(s) are present." << std::endl;
		
		for (u32 joystick = 0; joystick < (*joystickInfo_).size(); ++joystick)
			{

			std::cout << "Joystick " << joystick << ":" << std::endl;
			std::cout << "\tName: '" << (*joystickInfo_)[joystick].Name.c_str() << "'" << std::endl;
			std::cout << "\tAxes: " << (*joystickInfo_)[joystick].Axes << std::endl;
			std::cout << "\tButtons: " << (*joystickInfo_)[joystick].Buttons << std::endl;

			std::cout << "\tHat is: ";

			switch ((*joystickInfo_)[joystick].PovHat)
			{
			case SJoystickInfo::POV_HAT_PRESENT:
				std::cout << "present" << std::endl;
				break;

			case SJoystickInfo::POV_HAT_ABSENT:
				std::cout << "absent" << std::endl;
				break;

			case SJoystickInfo::POV_HAT_UNKNOWN:
			default:
				std::cout << "unknown" << std::endl;
				break;
			}
		}
	}
	else
	{
		joyConnected_ = false;
		std::cout << "Joystick support is not enabled." << std::endl;
	}
}

void movement::detectInput()
{
	if ((*input_).IsKeyDown(KEY_SPACE))
		std::cout << " key space is pressed down";
	else if ((*input_).IsKeyDown(KEY_KEY_1))
		std::cout << " key 1 is pressed down";
	else if ((*input_).IsKeyDown(KEY_KEY_2))
		std::cout << " key 2 is pressed down";
	else if ((*input_).IsKeyDown(KEY_KEY_3))
		std::cout << " key 3 is pressed down";
	else if ((*input_).IsKeyDown(KEY_KEY_4))
		std::cout << " key 4 is pressed down";
	else if ((*input_).IsKeyDown(KEY_KEY_5))
		std::cout << " key 5 is pressed down";
	else if ((*input_).IsKeyDown(KEY_KEY_6))
		std::cout << " key 6 is pressed down";
	else if ((*input_).IsKeyDown(KEY_KEY_7))
		std::cout << " key 7 is pressed down";
	else if ((*input_).IsKeyDown(KEY_KEY_8))
		std::cout << " key 8 is pressed down";
	else if ((*input_).IsKeyDown(KEY_KEY_9))
		std::cout << " key 9 is pressed down";
	else if ((*input_).IsKeyDown(KEY_KEY_0))
		std::cout << " key 0 is pressed down";


	if ((*input_).GetMouseState().LeftButtonDown)
		std::cout << " Mouse Left button down!  ";

	if ((*input_).GetMouseState().RightButtonDown)
		std::cout << " Mouse right button down!  ";

	if ((*input_).GetMouseState().MiddleMouseButtonDown)
		std::cout << " Mouse Middle button down!  ";

	if ((*input_).MouseState.mouseWheelUp)
	{
		std::cout << " Mouse wheel UP!  ";
	}
	else if ((*input_).MouseState.mouseWheelDown)
	{
		std::cout << " Mouse wheel down!  ";
	}

	const SEvent::SJoystickEvent & joystickData1 = (*input_).GetJoystickState1();
	const SEvent::SJoystickEvent & joystickData2 = (*input_).GetJoystickState2();
	const SEvent::SJoystickEvent & joystickData3 = (*input_).GetJoystickState3();
	const SEvent::SJoystickEvent & joystickData4 = (*input_).GetJoystickState4();
	
	if (joyConnected_)
		if ((f32)joystickData1.Axis[SEvent::SJoystickEvent::AXIS_X] != -1)
			std::cout << "Stick's X axis is moving.";
		if ((f32)joystickData1.Axis[SEvent::SJoystickEvent::AXIS_Y] != -1)
			std::cout << "Stick's Y axis is moving.";
		for (f32 i = (f32)joystickData1.NUMBER_OF_BUTTONS; i >= 0; --i)
			if ((f32)joystickData1.IsButtonPressed(i))
				std::cout << "button " << i << " is pressed. " << endl;
	(*input_).resetMouse();
}

