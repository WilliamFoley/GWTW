//HUD.h
//Joseph Davis
//• Hud.h will draw the hud elements include health, ammo, powerup notifier, compass/objective marker.
//•Hud.h also has a update function that will update if the plane is less than a certain health percent
//• update will also do the same for ammo and the objective location



#include <irrlicht.h>
#include <string>
//#include ammo.h
//#include plane.h
using namespace irr;


using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class HUD
{
public:

	// default constructor
	HUD();

	// gets the driver for video, gets the gui, gets the font for the text
	// may include more for health/ammo 	
	HUD(irr::IrrlichtDevice* device, video::IVideoDriver* driver, gui::IGUIEnvironment* guienv, IGUIFont* font);

	void Draw(video::IVideoDriver* driver, gui::IGUIEnvironment* guienv, IGUIFont* font);

	//updates the current interface with changes made to plane/ammo
	void update();

	
	
	~HUD();

private:
	// stores the driver 
	video::IVideoDriver* driver_;
	// stores the gui elements
	gui::IGUIEnvironment* guienv_;
	// stores the text font/size
	IGUIFont* font_;
};

// make a draw class for this 
HUD::HUD(irr::IrrlichtDevice* device, video::IVideoDriver* driver, gui::IGUIEnvironment* guienv, IGUIFont* font)
{

	driver->draw2DRectangle(video::SColor(150, 0, 0, 0), rect<s32>(40, 418, 600, 600));
	driver->draw2DRectangle(video::SColor(150, 0, 0, 0), rect<s32>(0, 430, 40, 40));
	driver->draw2DRectangle(video::SColor(150, 0, 0, 0), rect<s32>(0, 0, 40, 40));
	
	u32 theTime = device->getTimer()->getTime();
	//device->getTimer()->getTime();
	//if font is true 
	if (font)
	//draw the hp and the ammo text
	font->draw("Lives", core::rect<s32>(90, 425, 200, 100), video::SColor(255, 255, 255, 255));
	font->draw("PowerUp", core::rect<s32>(301, 425, 200,200), video::SColor(255, 255, 255, 255));
	font->draw("Ammo",core::rect<s32>(508, 425, 200, 300), video::SColor(255, 255, 255, 255));

	//driver->draw2DLine(position2d<s32>(0, 420), position2d<s32>(700, 420),
		//SColor(255, 0, 0, 0));
	//driver->draw2DLine(position2d<s32>(2, 415), position2d<s32>(700, 415),
		//SColor(255, 0, 0, 0));

	// draws the images of the hearts 
	guienv->addImage(driver->getTexture("./media/heart_full_16x16.png"), position2d<int>(70, 450));
	guienv->addImage(driver->getTexture("./media/heart_full_16x16.png"), position2d<int>(90, 450));
	guienv->addImage(driver->getTexture("./media/heart_full_16x16.png"), position2d<int>(110, 450));
	// Draws the Rocket image
	guienv->addImage(driver->getTexture("./media/missile_51216x16.png"), position2d<int>(510, 450));
	guienv->addImage(driver->getTexture("./media/missile_51216x16.png"), position2d<int>(525, 450));
	guienv->addImage(driver->getTexture("./media/missile_51216x16.png"), position2d<int>(495, 450));

	

	//Draw polygon
	driver->draw2DPolygon(position2d<s32>(570, 70), 50, video::SColor(255, 0, 0, 0), 12);
	//driver->draw2DPolygon(position2d<s32>(200, 70), 500, video::SColor(255, 0, 0, 0), 4);
	

	// Powerup notification to determine what power up you have aquired
	//Compass to show the direction of the objective
}



void HUD::update()
{
	//if health of character is < a certain percent
	//update to image with empty hearth container
	
}

HUD::~HUD()
{
}