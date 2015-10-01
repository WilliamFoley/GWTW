//Shawn Cherry
//CS 365
//Fall 2015
//This is the movement class


#include <irrlicht.h>
#include "driverChoice.h"
#pragma once

using namespace irr;

class Myinput : public IEventReceiver
{
public:
	// We'll create a struct to record info on the mouse state
	struct SMouseState
	{
		//Saves the state of all of the mouse functions.
		core::position2di Position;  	//Mouse Position
		bool LeftButtonDown;			//Mouse Left button state
		bool RightButtonDown;			//Mouse Right button state
		bool MiddleMouseButtonDown;		//Mouse Middle button state
		float MouseWheel;				//Mouse wheel state
		bool mouseWheelUp;				//Mouse wheel going up state
		bool mouseWheelDown;			//Mouse wheel going down state

		//SETS THE DEFAULTS FOR THE STRUCT
		SMouseState() : LeftButtonDown(false), RightButtonDown(false), 
		MiddleMouseButtonDown(false), MouseWheel(0), mouseWheelUp(false), 
		mouseWheelDown(false){};
		
	} MouseState;
	
	//tells us which keys are being pressed down
	Myinput();
	
	//When an event happens DO THIS!
	virtual bool OnEvent(const SEvent& event);
	
	//Resets the mouse states back to a default to reduce redundant input
	bool resetMouse();

	//Is the keyboard key down?
	bool IsKeyDown(EKEY_CODE keyCode) const { return KeyIsDown[keyCode]; }

	//Gets the joystick state
	const SEvent::SJoystickEvent & GetJoystickState1(void) const { return JoystickState1; }
	const SEvent::SJoystickEvent & GetJoystickState2(void) const { return JoystickState2; }	
	const SEvent::SJoystickEvent & GetJoystickState3(void) const { return JoystickState3; }	
	const SEvent::SJoystickEvent & GetJoystickState4(void) const { return JoystickState4; }
	
	//Gets the mouse state
	const SMouseState & GetMouseState(void) const {return MouseState;}

private:
	SEvent::SJoystickEvent JoystickState1;
	SEvent::SJoystickEvent JoystickState2;
	SEvent::SJoystickEvent JoystickState3;
	SEvent::SJoystickEvent JoystickState4;
	bool KeyIsDown[KEY_KEY_CODES_COUNT];
};

Myinput::Myinput()
{
	for (u32 i = 0; i<KEY_KEY_CODES_COUNT; ++i)
		KeyIsDown[i] = false;
}

bool Myinput::OnEvent(const SEvent& event)
{
	// Remember whether each key is down or up
	if (event.EventType == irr::EET_KEY_INPUT_EVENT)
		KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;

	// check if a mouse event happened
	if (event.EventType == irr::EET_MOUSE_INPUT_EVENT)
	{
		//Determine which event happened for the mouse
		switch (event.MouseInput.Event)
		{

			//Left mouse press
		case EMIE_LMOUSE_PRESSED_DOWN:
			MouseState.LeftButtonDown = true;
			break;

			//Right mouse press
		case EMIE_RMOUSE_PRESSED_DOWN:
			MouseState.RightButtonDown = true;
			break;

			//middle mouse pressed
		case  EMIE_MMOUSE_PRESSED_DOWN:
			MouseState.MiddleMouseButtonDown = true;
			break;

			//Mouse wheel movement
		case EMIE_MOUSE_WHEEL:
			MouseState.MouseWheel = event.MouseInput.Wheel;

			//if the mouse is wheeled up
			if (MouseState.MouseWheel > 0)
			{
				MouseState.mouseWheelUp = true;
				MouseState.mouseWheelDown = false;
			}

			//If the mouse is wheeled down
			else if (MouseState.MouseWheel < 0)
			{
				MouseState.mouseWheelUp = false;
				MouseState.mouseWheelDown = true;
			}
			break;

			//Left mouse button is let go
		case EMIE_LMOUSE_LEFT_UP:
			MouseState.LeftButtonDown = false;
			break;

			//Right mouse button is let go
		case EMIE_RMOUSE_LEFT_UP:
			MouseState.RightButtonDown = false;
			break;

			//Middle mouse button is let go
		case  EMIE_MMOUSE_LEFT_UP:
			MouseState.MiddleMouseButtonDown = false;
			break;

			//the mouse is moved
		case EMIE_MOUSE_MOVED:
			MouseState.Position.X = event.MouseInput.X;
			MouseState.Position.Y = event.MouseInput.Y;
			break;

		default:

			break;
		}
	}

		// The state of each connected joystick is sent to us
		// once every run() of the Irrlicht device.  Store the
		// state of the first joystick, ignoring other joysticks.
		// This is currently only supported on Windows and Linux.
		if (event.EventType == irr::EET_JOYSTICK_INPUT_EVENT && event.JoystickEvent.Joystick == 0)
			JoystickState1 = event.JoystickEvent;

		else if (event.EventType == irr::EET_JOYSTICK_INPUT_EVENT && event.JoystickEvent.Joystick == 1)
			JoystickState2 = event.JoystickEvent;

		else if (event.EventType == irr::EET_JOYSTICK_INPUT_EVENT && event.JoystickEvent.Joystick == 2)
			JoystickState3 = event.JoystickEvent;

		else if (event.EventType == irr::EET_JOYSTICK_INPUT_EVENT && event.JoystickEvent.Joystick == 3)
			JoystickState4 = event.JoystickEvent;

		return false;
}

bool Myinput::resetMouse()
{
	MouseState.MouseWheel = 0;
	MouseState.mouseWheelUp = false;
	MouseState.mouseWheelDown = false;
	return false;
}

