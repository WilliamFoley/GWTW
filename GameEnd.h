//Cory Budka
//This is the GameEnd class which will determine if the user has won or lost

#pragma once 
#include <irrlicht.h> 
#include "Object.h"
#include "LandingPad.h"

Class GameEnd
{
public:
   GameEnd();
   GameEnd(const GameEnd& other);
   void didYouWin (Object whatYouCollidedWith);

void didYouWin (Object whatYouCollidedWith)
{
  // if the collision is with the final pad, they WIN
  // else the collision is with any other object, they LOSE
}

};
