//Sound.h
//Joseph Davis
//Irrklang 3d / 2d sound library
//•	IrrKlang is a 2d / 3d sound library that has a large range of compatibilities that allows it to be easily implemented into a graphic engine such as irrKlang
//•	The function engine->Play2D(“musicfile.mp3”, true) will play a supported sound file in the background of the program when ran, it will also loop the sound if true is added to the parameters.
//	o	Mp3 format is only supported if you include the dll that the program natively provides
//•	Engine->Play3d(“musicfile”, position(vec3df), true) allows anyone to play a sound in a 3d space at any position that they desire and it also can be looped as well
//•	The engine also can allow for the sounds to be set to a minimal distance so that you will not hear that particular sound until you get closer to it in the 3d space
//•	Irrklang does also support the use of chorus, flanger, and etc sound effects within the engine natively.
//•	Within IrrKlang, you have the option to record your own sounds using microphone or any other input device
// Sound class may not be needed but here one just in case

#include <irrlicht.h>
#include <irrKlang.h>

#include <string>

using namespace irr;
using namespace irrklang;
using namespace scene;

// sound class 
class Sound
{
public:
	
	//plays the sound once
	void playSoundOnce(bool deleteFile = false);
	
	// sets sound to play
	void PlaySound(const char* filename);

	// gets the sound
	const char* getSound() const;


	// gets the distance in a 3d setting
	void setDistance(f32 minDistance, f32 maxDistance);

	// stops the sound from playing
	void stop();

private:
	f32 MinDistance_;
	f32 MaxDistance_;
	irrklang::ISoundEngine* engine_;
	irrklang::ISound* Sound_;




};
